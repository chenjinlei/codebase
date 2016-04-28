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

int StrComp(SString S1,SString S2)
{
	int i=0;
	while(S1.S[i]==S2.S[i]&&S1.S[i]!='\0')						//�ַ���ͬ����֡�\0��ֹͣ�Ƚ�
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

int StrTimes(SString S,SString S1)//��һ���Ӵ��������г��ֵĴ���
{
	if(GetLength(S1)>GetLength(S))
	return -1;												//���Ҫ��ѯ���Ӵ����ȴ�����������
	int i=0 ;												//˵�����ַ���S�в����ڸ��Ӵ�S1
	char ch=S1.S[0];										//��ȡ�Ӵ������ַ�
	int j=0;
	for(i=0;i<=GetLength(S)-GetLength(S1);i++)
	{
		if(S.S[i]==ch)										//�ҵ�S1���ַ����ַ���S�е�λ��
			if(StrComp(SubStr(S,i+1,GetLength(S1)),S1)==0)		//������j��1
				j++;
	}
	return j;
}

void main()
{
	SString s,s1;//s��s1��������
	InitStr(s);//��ʼ����
	InitStr(s1);
	StrEvaluate(s,"abcabcabcaa");		//ִ�жԴ���ֵ����
	StrEvaluate(s1,"abc");				//ִ�жԴ���ֵ����
	int times=StrTimes(s,s1);//�����Ӵ�s1��s�г��ֵĴ���
	printf("%s��%s�г��ֵĴ���Ϊ��%d��\n",s1.S,s.S,times);

}