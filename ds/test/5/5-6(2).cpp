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

void String_Reverse(SString s,SString &r)						//求s的逆串r
{	InitStr(r);													//初始化r为空串
	for(int i=GetLength(s);i;i--)	
	{
			StrConcat(r,SubStr (s,i,1));						//把s的字符从后往前添加到r中	
	}
}

void main()
{
	SString s,s1;//s,s1是串
	InitStr(s);//初始化串
	InitStr(s1);
	StrEvaluate(s,"abcdefg");		//执行对串赋值操作
	//StrEvaluate(s1,"abc");				//执行对串赋值操作
	//int times=StrTimes(s,s1);//返回子串s1在s中出现的次数
	String_Reverse(s,s1);//s的逆置放到s1中
	printf("%s逆置为：%s\n",s.S,s1.S);

}