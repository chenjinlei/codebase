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

void StrConcat(SString &S1,SString S2)
{
	int len1=GetLength(S1);
	int len2=GetLength(S2);
	if((len1+len2+1)>MAXSIZE)								//留一个空间来存放'\0'所以要+1	[后面加了一个换行符]
		printf("%s","长度超过最大长度将会截取部分字符串！");
	for(int i=len1;i<len1+len2&&i<MAXSIZE;i++)					//判断是否需要截取串
		S1.S[i]=S2.S[i-len1];
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


void StrCopy(SString &S1,SString S2)
{
	if(GetLength(S1))										//如果S1的长度为0，那么就不初始化
		InitStr(S1);
	for(int i=0;i<=GetLength(S2);i++)							//从第一个元素起将S2的字符赋给S1
		S1.S[i]=S2.S[i];
}

int Replace(SString &S,SString T,SString V)//将T替换为V
{
	int n,i;
	SString head,tail;
	InitStr(head);
	InitStr(tail);
	for(n=0,i=1;i<=GetLength(S)- GetLength (T)+1;i++)
		if(!StrComp (SubStr(S,i, GetLength (T)),T))				//找到了与T匹配的子串
		{												//把T的前面和后面存到head和tail	
			StrCopy(head,SubStr (S,1,i-1));
			StrCopy(tail,SubStr (S,i+ GetLength (T), GetLength (S)-i- GetLength (T)+1));
			StrConcat(head,V);								//把head,V,tail连接为新串
			StrCopy(S,head);
			StrConcat(S,tail);
			i+= GetLength (V);								//当前位置跳到插入串以后	
			n++;											//次数加1	
		}
		return n;
}

void main()
{
	SString s,s1,s2;//s,s1是串
	InitStr(s);//初始化串
	InitStr(s1);
	InitStr(s2);
	StrEvaluate(s,"abcdefg");		//执行对串赋值操作
	StrEvaluate(s1,"abc");				//执行对串赋值操作
	StrEvaluate(s2,"d");
	printf("原来的字符串为%s，用字符串%s替换子串%s后结果为：",s.S,s1.S,s2.S);
	int times=Replace(s,s2,s1);
	printf("%s,替换的次数为:%d\n",s.S,times);

}