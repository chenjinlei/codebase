#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
typedef struct
{
	char S[MAXSIZE];
}SString;

int GetLength(SString s)
{
	int length=0;
	while(s.S[length]!='\0')							//只要字符的值不是’\0’，length的值加1
		length++;
	return length;
}

void InitStr(SString &str)
{
	for(int i=0;i<MAXSIZE;i++)				//从第一个元素到最后元素初始化为'\0'
	{
		str.S[i]='\0';
	}
}

void StrEvaluate(SString &S1,char S2[])	//char S2[]是字符数组一个字符串常量
{
	if(GetLength(S1))
		InitStr(S1);										//对S1初始化
	for(int i=0;S2[i]!='\0';i++)									//从第一个元素开始对S1进行赋值
		S1.S[i]=S2[i];
}

int StrComp(SString S1,SString S2)
{
	int i=0;
	while(S1.S[i]==S2.S[i]&&S1.S[i]!='\0')						//字符不同或出现‘\0’停止比较
	{
		i++;
	}
	if(S1.S[i]<S2.S[i])
	return -1;
	else if(S1.S[i]>S2.S[i])
	return 1;
	return 0;
}

SString SubStr(SString S,int i,int length)
{
	SString S1;
	InitStr(S1);											//初始化要返回的子串
	if(i+length>GetLength(S)+1||i<=0)							//判断子串长度是否合法
	{
		printf("%s","所取子串已超出主串的长度!子串获取失败!");
	}
	else
	{
		for(int j=i-1;j<i+length-1;j++)							//执行取字串操作
			S1.S[j+1-i]=S.S[j];
	}
	return S1;
}

int StrTimes(SString S,SString S1)//求一个子串在主串中出现的次数
{
	if(GetLength(S1)>GetLength(S))
	return -1;												//如果要查询的子串长度大于主串长度
	int i=0 ;												//说明在字符串S中不存在该子串S1
	char ch=S1.S[0];										//获取子串的首字符
	int j=0;
	for(i=0;i<=GetLength(S)-GetLength(S1);i++)
	{
		if(S.S[i]==ch)										//找到S1首字符在字符串S中的位置
			if(StrComp(SubStr(S,i+1,GetLength(S1)),S1)==0)		//如果相等j增1
				j++;
	}
	return j;
}

void main()
{
	SString s,s1;//s，s1是两个串
	InitStr(s);//初始化串
	InitStr(s1);
	StrEvaluate(s,"abcabcabcaa");		//执行对串赋值操作
	StrEvaluate(s1,"abc");				//执行对串赋值操作
	int times=StrTimes(s,s1);//返回子串s1在s中出现的次数
	printf("%s在%s中出现的次数为：%d次\n",s1.S,s.S,times);

}