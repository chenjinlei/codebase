#include <stdio.h>
#include <stdlib.h>

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
	if(S.top==-1)		// top=-1ʱջ��
		return true;
	else
		return false;
}

bool Stack_Full(Stack  S)       //��ջ��
{
	if(S.top==MAXSIZE-1)	//�±����ֵΪMAXSIZE-1
		return true;
	else
		return false;
}

void Push(Stack &S,DataType elem)
{
	if(!Stack_Full(S))	//��ջ���Ͳ�������ջ
	{
		S.top++;
		S.elem[S.top]=elem;
	}
	else
		printf("ջ����������ִ�д˲�����");
}

DataType Pop(Stack  &S)		//��top-1������ջ��Ԫ��
{
	if(!Stack_Empty(S))	//��ջ�գ�����ִ�г�ջ����
	{
		return S.elem[S.top--];
	}
	else
		printf ("ջ�ѿգ�����ִ�д˲�����");
}

DataType GetTop(Stack S)
{
	if(!Stack_Empty(S))	//��ջ�գ����ܻ�ȡջ��Ԫ��
	{
		return S.elem[S.top];
	}
	else
		printf("ջ���Ѿ�û��Ԫ�أ�");
}

int main()
{
	Stack S;         //SΪһ˳��洢��ջ
	int flag=1;
	char j,ch;

	//---------------------------�����˵--------------------------
	printf("����������ʵ��˳��ṹ��ջ��\n");
	printf("����ʵ����ջ����ջ����ջ��Ԫ�صȲ�����\n");
	//-------------------------------------------------------------
	Init_Stack(S);         //��ʼ��ջ
	while(flag)
	{
		printf("��ѡ��:\n");
		printf("1.��ʾ��ջ�׵�ջ������Ԫ��\n");
		printf("2.��ջһ��Ԫ��\n");
		printf("3.��ջһ��Ԫ��\n");
		printf("4.��ջ��\n");
		printf("5.��ջ��\n");
		printf("6.��ջ��Ԫ��\n");
		printf("7.�˳�����    \n");
		scanf(" %c",&j);
		switch(j)
		{
		case '1':
			int i;
			if(!Stack_Empty(S))
			{
				for(i=0;i<=S.top;i++)
					printf("%c  ",S.elem[i]);
			}
			else
				printf("ջ��");
			printf("\n");
			break; //��ʾ��ջ�׵�ջ������Ԫ��
		case '2':
			getchar();//����Ļس�
			printf("������Ҫ��ջ��Ԫ��(һ���ַ�):\n");
			scanf("%c",&ch);  //����Ҫ��ջ��Ԫ��
			Push(S,ch);//��ջ
			break;
		case '3':
			Pop(S);//��ջ
			break;
		case '4':
			if(Stack_Empty(S))
				printf("ջ��");
			else
				printf("ջ�ǿ�");
			break;
		case '5':
			if(Stack_Full(S))
				printf("ջ��");
			else
				printf("ջ����");
			break;
		case '6':
			printf("ջ��Ԫ�� %c",GetTop(S));
			break;
		default:
			flag=0;
			printf("�����������������˳�!\n");
		}
	}
	return 0;
}
