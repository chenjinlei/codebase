#include "stdio.h"
#include "string.h"

#define MAXSIZE 100				//����ջ�Ĵ洢����
typedef int DataType;				//DataType��������Ԥ����
//˳��ջ
typedef struct
{
	int top;						//ջ��Ԫ���±�Ҳ����ջ����ֵ
	DataType elem[MAXSIZE];		//�洢ջԪ�ص�����
 }Stack;

void Init_Stack(Stack &S)       //��ʼջ
{
	S.top=-1;
}

bool Stack_Empty(Stack S)        //��ջ��
{
	if(S.top==-1)											// top=-1ʱջ��
		return true;
	else
		return false;
}

bool Stack_Full(Stack  S)         //��ջ��
{
	if(S.top==MAXSIZE-1)									//�±����ֵΪMAXSIZE-1
		return true;
	else
		return false;
}

void Push(Stack &S,DataType elem)
{
	if(!Stack_Full(S))										//��ջ���Ͳ�������ջ
	{
		S.top++;
		S.elem[S.top]=elem;
	}
	else
		printf("ջ����������ִ�д˲�����");
}

DataType Pop(Stack  &S)									//��top-1������ջ��Ԫ��
{
	if(!Stack_Empty(S))										//��ջ�գ�����ִ�г�ջ����
	{		
		return S.elem[S.top--];
	}
	else
		printf ("ջ�ѿգ�����ִ�д˲�����");
}

DataType GetTop(Stack S)
{
	if(!Stack_Empty(S))										//��ջ�գ����ܻ�ȡջ��Ԫ��
	{		
		return S.elem[S.top];
	}
	else
		printf("ջ���Ѿ�û��Ԫ�أ�");
}
//��ʾ��4-1�����Ӽ���������һ����������Ȼ�����෴�Ĵ����ӡ������
void Reverse()
{
	Stack a;
	int x;
	Init_Stack(a);
	printf("����һ��������ֱ��������ֹ��־-1Ϊֹ!\n");
	scanf("%d",&x);
	while(x!=-1) {
		Push(a,x);
		scanf("%d",&x);
	}
	while(!Stack_Empty(a))									//ջ��Ϊ��ʱ������ջ�����
		printf("%d ",Pop(a));
	printf("\n");
}
//��ʾ��4-2����ջ�ļ�Ӧ�ã�����ת�����⡣
void Conversion(int N,int r)
{
	Stack  s;												//����һ��˳��ջ
	DataType   x;
	Init_Stack(s);											//ջS��ʼ��
	while ( N )
	{
		Push( s,N % r );									//�ɵ�λ����λ�����ջԪ��
		N=N / r ;
	}
	while( !Stack_Empty( s ) )								//�ɸ�λ����λ���d��������ÿһλ
	{
		x=Pop(s) ;
		printf ( "%d",x) ;
	}
}
//��ʾ��4-3�������õݹ��㷨���������n�Ľ׳ˣ�n!����
int fun(int n)
{
	if(n==0)
		return 1;
	else
		return n*fun(n-1);
}
//��ʾ��4-4�������������ַ�����
int IsHuiwen( char *t)
{														//�ж�t�ַ��Ƿ�Ϊ����
	Stack s;
	int i , len;
	int temp;
	Init_Stack(s);
	len=strlen(t);	
	printf("\n%d\n",len);//����������
	for ( i=0; i<len/2; i++)										//��һ���ַ���ջ
		Push( s, (int)(t[i]));
	while( !Stack_Empty( s))
	{										//ÿ����һ���ַ�����Ӧ�ַ��Ƚ�
		temp=Pop (s);
		if( temp!=(int)(t[len-i]))
			return 0 ;											//�����򷵻�0
		else i--;
	} 
}
void main()
{
    int flag=1;
	char j;
	//---------------------------�����˵--------------------------
	printf("����������ʵ��ջ�Ͷ��е�Ӧ�á�\n");
	//-------------------------------------------------------------
    while(flag)
	{ 
		printf("��ѡ��:\n");
        printf("1.��ʾ��4-1�����Ӽ���������һ����������Ȼ�����෴�Ĵ����ӡ������\n");
        printf("2.��ʾ��4-2����ջ�ļ�Ӧ�ã�����ת�����⡣\n");
        printf("3.��ʾ��4-3�������õݹ��㷨���������n�Ľ׳ˣ�n!����\n");
        printf("4.��ʾ��4-4�������������ַ�����\n");
        printf("5.�˳�����    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			Reverse();
			break; 
		case '2':
			int N,r;
			getchar();
			printf("���������������ƣ��ö��Ÿ�������3467,8\n");
			scanf("%d,%d",&N,&r);
			Conversion(N,r);
			printf("\n");
            break;
		case '3':
			int n;
			getchar();
			printf("������һ������\n");
			scanf("%d",&n);
			printf("%d �Ľ׳��� %d \n",n,fun(n));
            break;
		case '4':
			char c[2];
			char *t;
			t=c;
			printf("������һ�������ַ���\n");
			scanf("%s",t);
			if(IsHuiwen(t))
				printf("�ַ��� %s �ǻ���\n",t);
			else
				printf("�ַ��� %s ���ǻ���\n",t);
			break;
		default:
			flag=0;
			printf("�����������������˳�!\n");
		}
	}
}


