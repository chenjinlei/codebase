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
	while(s.S[length]!='\0')							//ֻҪ�ַ���ֵ���ǡ�\0����length��ֵ��1
		length++;
	return length;
}

void InitStr(SString &str)
{
	for(int i=0;i<MAXSIZE;i++)				//�ӵ�һ��Ԫ�ص����Ԫ�س�ʼ��Ϊ'\0'
	{
		str.S[i]='\0';
	}
}

void StrEvaluate(SString &S1,char S2[])	//char S2[]���ַ�����һ���ַ�������
{
	if(GetLength(S1))
		InitStr(S1);										//��S1��ʼ��
	for(int i=0;S2[i]!='\0';i++)									//�ӵ�һ��Ԫ�ؿ�ʼ��S1���и�ֵ
		S1.S[i]=S2[i];
}


SString SubStr(SString S,int i,int length)
{
	SString S1;
	InitStr(S1);											//��ʼ��Ҫ���ص��Ӵ�
	if(i+length>GetLength(S)+1||i<=0)							//�ж��Ӵ������Ƿ�Ϸ�
	{
		printf("%s","��ȡ�Ӵ��ѳ��������ĳ���!�Ӵ���ȡʧ��!");
	}
	else
	{
		for(int j=i-1;j<i+length-1;j++)							//ִ��ȡ�ִ�����
			S1.S[j+1-i]=S.S[j];
	}
	return S1;
}

void StrConcat(SString &S1,SString S2)
{
	int len1=GetLength(S1);
	int len2=GetLength(S2);
	if((len1+len2+1)>MAXSIZE)								//��һ���ռ������'\0'����Ҫ+1	[�������һ�����з�]
		printf("%s","���ȳ�����󳤶Ƚ����ȡ�����ַ�����");
	for(int i=len1;i<len1+len2&&i<MAXSIZE;i++)					//�ж��Ƿ���Ҫ��ȡ��
		S1.S[i]=S2.S[i-len1];
}

void String_Reverse(SString s,SString &r)						//��s���洮r
{	InitStr(r);													//��ʼ��rΪ�մ�
	for(int i=GetLength(s);i;i--)	
	{
			StrConcat(r,SubStr (s,i,1));						//��s���ַ��Ӻ���ǰ��ӵ�r��	
	}
}

void main()
{
	SString s,s1;//s,s1�Ǵ�
	InitStr(s);//��ʼ����
	InitStr(s1);
	StrEvaluate(s,"abcdefg");		//ִ�жԴ���ֵ����
	//StrEvaluate(s1,"abc");				//ִ�жԴ���ֵ����
	//int times=StrTimes(s,s1);//�����Ӵ�s1��s�г��ֵĴ���
	String_Reverse(s,s1);//s�����÷ŵ�s1��
	printf("%s����Ϊ��%s\n",s.S,s1.S);

}