#include "stdio.h"
#include "malloc.h"

#define MAXSIZE 100				//����ջ�Ĵ洢����
typedef char DataType;				//DataType��������Ԥ����
//��ʽջ

typedef struct Node
{
	DataType elem;										//ջ��Ԫ��
	struct Node *top;										//ջ��ָ��
}StackNode;
typedef StackNode* Stack;									//����StackΪStackNode*����

void Init_Stack(Stack &S)								
{
	S=(Stack)malloc(sizeof(StackNode)); 						//����ռ�
	S->top=NULL; 											//ָ���ʼ��
}

bool Stack_Empty(Stack S)
{
	if(S->top==NULL)										//ջ��ָ��Ϊ��
		return true;
	else
		return false;
}

void Push(Stack &S,DataType elem)  
{
	Stack NewNode=(Stack)malloc(sizeof(StackNode));				//Ϊ�½ڵ����ռ�
	NewNode->elem=elem;									//Ϊ�½ڵ㸳ֵ
	NewNode->top=S->top;									//���½ڵ������ͷ
	S->top=NewNode;										//ջ��ָ��ָ���½ڵ�
}

DataType GetTop(Stack S)
{
	if(!Stack_Empty(S))										//���ջ��Ϊ�գ�����ջ��Ԫ��
	{
		return (S->top)->elem;
	}
	else
		printf("ջ���Ѿ�û��Ԫ�أ�");
	 
}

DataType Pop(Stack  &S)									//����ջ��Ԫ�ز���ջ��Ԫ��ɾ��
{
	if(!Stack_Empty(S))										//��ջ�վͲ���ִ�г�ջ����
	{		
		DataType ch=GetTop(S);
		Stack S1=(S->top)->top;								//����ջ��Ԫ����һ��Ԫ�صĵ�ַ
		delete(S->top);										//ɾ��ջ��Ԫ�ز��ͷſռ�
		S->top=S1;										//ջ��ָ��ָ���µ�ջ��Ԫ��
		return ch;											//����ջ��Ԫ��
	}
	else
		printf("ջ�ѿգ�����ִ�д˲�����");
}


void main()
{
	Stack S;         //SΪһ��ʽջ
    int flag=1;
    char j,ch;

	//---------------------------�����˵--------------------------
	printf("����������ʵ����ʽ�ṹ��ջ��\n");
	printf("����ʵ����ջ����ջ����ջ��Ԫ�صȲ�����\n");
	//-------------------------------------------------------------
    Init_Stack(S);         //��ʼ��ջ
    while(flag)
	{ 
		printf("��ѡ��:\n");
        printf("1.��ʾ��ջ����ջ������Ԫ��\n");
        printf("2.��ջһ��Ԫ��\n");
        printf("3.��ջһ��Ԫ��\n");
        printf("4.��ջ��\n");
		printf("5.��ջ��Ԫ��\n");
        printf("6.�˳�����    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			StackNode *node;
			if(!Stack_Empty(S))
			{
				node=S;
				while(node->top!=NULL)
				{
					printf("%c  ",node->top->elem);
					node=node->top;
				}
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
			printf("ջ��Ԫ�� %c",GetTop(S));
			break;
		default:
			flag=0;
			printf("�����������������˳�!\n");
		}
	}
}
