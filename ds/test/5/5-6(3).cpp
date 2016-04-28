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


void StrCopy(SString &S1,SString S2)
{
	if(GetLength(S1))										//���S1�ĳ���Ϊ0����ô�Ͳ���ʼ��
		InitStr(S1);
	for(int i=0;i<=GetLength(S2);i++)							//�ӵ�һ��Ԫ����S2���ַ�����S1
		S1.S[i]=S2.S[i];
}

int Replace(SString &S,SString T,SString V)//��T�滻ΪV
{
	int n,i;
	SString head,tail;
	InitStr(head);
	InitStr(tail);
	for(n=0,i=1;i<=GetLength(S)- GetLength (T)+1;i++)
		if(!StrComp (SubStr(S,i, GetLength (T)),T))				//�ҵ�����Tƥ����Ӵ�
		{												//��T��ǰ��ͺ���浽head��tail	
			StrCopy(head,SubStr (S,1,i-1));
			StrCopy(tail,SubStr (S,i+ GetLength (T), GetLength (S)-i- GetLength (T)+1));
			StrConcat(head,V);								//��head,V,tail����Ϊ�´�
			StrCopy(S,head);
			StrConcat(S,tail);
			i+= GetLength (V);								//��ǰλ���������봮�Ժ�	
			n++;											//������1	
		}
		return n;
}

void main()
{
	SString s,s1,s2;//s,s1�Ǵ�
	InitStr(s);//��ʼ����
	InitStr(s1);
	InitStr(s2);
	StrEvaluate(s,"abcdefg");		//ִ�жԴ���ֵ����
	StrEvaluate(s1,"abc");				//ִ�жԴ���ֵ����
	StrEvaluate(s2,"d");
	printf("ԭ�����ַ���Ϊ%s�����ַ���%s�滻�Ӵ�%s����Ϊ��",s.S,s1.S,s2.S);
	int times=Replace(s,s2,s1);
	printf("%s,�滻�Ĵ���Ϊ:%d\n",s.S,times);

}