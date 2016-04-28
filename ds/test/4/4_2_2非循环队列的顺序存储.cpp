#include "stdio.h"

#define MAXSIZE 100
typedef char DataType;				//DataType��������Ԥ����
typedef struct
{
	DataType elem[MAXSIZE];								//������Ԫ��
	int front;												//��ͷ
	int rear;												//��β
}Queue;

void Init_Queue(Queue &Q)
{
	Q.rear=0;
	Q.front=0;
}

bool Queue_Empty(Queue Q)
{
	if(Q.front==Q.rear)										//front=rearʱ������Ϊ��
		return true;
	else
		return false;
}

bool Queue_Full(Queue Q)
{
	if(Q.rear+1==MAXSIZE)									//rear+1����MAXSIZE������Ϊ��
		return true;
	else
		return false;
}

void In_Queue(Queue &Q,DataType elem)
{
	if(!Queue_Full(Q))
	{
        Q.elem[Q.rear]=elem;
		Q.rear=Q.rear+1;									//���β����Ԫ�أ��Ƚ�rearǰ��һλ
	}
	else
		printf("����������");
}

DataType GetTop(Queue Q)
{
	if(!Queue_Empty(Q))										//������в�Ϊ�գ����ض�ͷԪ��
	{
		return Q.elem[Q.front];
	}
	else
		printf("�������Ѿ�û��Ԫ�أ�");
	 
}

DataType Out_Queue(Queue &Q)
{
	if(!Queue_Empty(Q))
	{
		DataType ch=GetTop(Q);
        Q.front=Q.front+1;
		return ch;
	}
	else
		printf("�����ѿգ�");
}


void main()
{
	Queue Q;         //QΪһ˳��洢�ķ�ѭ������
    int flag=1;
    char j,ch;
	//---------------------------�����˵--------------------------
	printf("����������ʵ��˳��洢�ķ�ѭ�����С�\n");
	printf("����ʵ������С������С���ȡ��ͷԪ�صȲ�����\n");
	//-------------------------------------------------------------
    Init_Queue(Q);         //��ʼ������
    while(flag)
	{ 
		printf("��ѡ��:\n");
        printf("1.��ʾ�Ӷ�ͷ����β����Ԫ��\n");
        printf("2.���һ��Ԫ��\n");
        printf("3.����һ��Ԫ��\n");
        printf("4.�жӿ�\n");
		printf("5.�ж���\n");
		printf("6.ȡ��ͷԪ��\n");
        printf("7.�˳�����    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			int i;
			if(!Queue_Empty(Q))
			{
				for(i=Q.front;i<Q.rear;i++)
					printf("%c  ",Q.elem[i]);
			}
			else
				printf("���п�");
			printf("\n");
			break; //��ʾ�Ӷ�ͷ����β������Ԫ��
		case '2':
			getchar();                 //����Ļس�
			printf("������Ҫ��ӵ�Ԫ��(һ���ַ�):\n");
            scanf("%c",&ch);  //����Ҫ��ӵ�Ԫ��
			In_Queue(Q,ch);//���
            break;
		case '3':
			Out_Queue(Q);//����
            break;
		case '4':
			if(Queue_Empty(Q))
				printf("���п�");
			else 
				printf("���зǿ�");
			break;
		case '5':
			if(Queue_Full(Q))
				printf("������");
			else 
				printf("���з���");
			break;
		case '6':
			if(!Queue_Empty(Q))
				printf("��ͷԪ�� %c",GetTop(Q));
			else
				printf("���п�!");
			printf("\n");
			break;
		default:
			flag=0;
			printf("�����������������˳�!\n");
		}
	}
}
