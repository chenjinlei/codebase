#include "stdio.h"
#include "string.h"

#define MAXSIZE 100				//����ջ�Ĵ洢����
typedef char DataType;				//DataType��������Ԥ����
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

// ����ƥ������
int MatchBracket( char *st)									//�����ʽST�������Ƿ����
{    
	int i;
	Stack S;												//����һ��ջ
	Init_Stack (S);											//��ʼ��ջ
	for (i=0; i<strlen(st) ; i++)
	{
		if ( st[i]=='(' )
			Push(S, st[i]);									//��'('ʱ��ջ
		if ( st[i]==')' )										//��')'
			if (!Stack_Empty(S))								//ջ��Ϊ��ʱ����ջ��Ԫ�س�ջ
				Pop(S);
			else
				return 0;										//��ƥ�䣬����0
	}
	if (Stack_Empty(S))
		return 1;											// ƥ�䣬����1
	else
		return 0;											//��ƥ�䣬����0
}
void main()
{
    int flag=1;
	char j;
	char c[2];
	char *t=c;
	//---------------------------�����˵--------------------------
	printf("����������ʵ��ջ�Ͷ��е�Ӧ�á�\n");
	//-------------------------------------------------------------
    while(flag)
	{ 
		printf("��ѡ��:\n");
		printf("1������ƥ������\n");	
        printf("2���˳�����    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			printf("������һ���ַ���\n");
			scanf("%s",t);
			if(MatchBracket(t))
				printf("�ַ��� %s ����ƥ��\n",t);
			else
				printf("�ַ��� %s ���Ų�ƥ��\n",t);
            break;
		default:
			flag=0;
			printf("�����������������˳�!\n");
			break;
		}
	}
}