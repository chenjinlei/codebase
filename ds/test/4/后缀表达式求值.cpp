#include "stdio.h"

#define MAXSIZE 100				//����ջ�Ĵ洢����
typedef double DataType;				//DataType��������Ԥ����
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

//���ʽ��ֵ����---��׺���ʽ��ֵ
double  Cal_exp(char *T)										//�����ɺ�׺���ʽT������
{    
	Stack  s ;
	char ch;
	double a,b,c,result;
	ch=*T++ ;
	Init_Stack(s) ; 
	while ( ch != '#' )
	{
		if (ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='('&&ch!=')'&&ch!='#')//���������
			Push(s,(double)ch-48) ;
		else
		{ 
			b=Pop(s) ; 
			a=Pop(s) ;	
			printf("a=%f,b=%f\n",a,b);//ȡ������������
			switch(ch) 									//����������
			{
			case '+':c=a+b ; break ;
			case '-':c=a-b ; break ;
			case '*':c=a*b ; break ;
			case '/':c=a/b ; break ; 
			//case '%':c=a%b ; break ;
			}
			Push(s, c);
		}
		ch=*T++ ;
	}
	result=Pop( s) ;
	return result ;
}
void main()
{
	char c[2];
	char *t=c;
	printf("������һ��10���ں�׺���ʽ����#����\n");
	scanf("%s",t);
	printf("��� %f \n",Cal_exp(t));
}