#include "stdio.h"
#include "malloc.h"
typedef char DataType;
typedef struct Node									//������
{
	DataType elem;
	Node * next;
}ListNode;
typedef ListNode *QNode;

typedef struct										//�����ͷ�Ͷ�βָ��
{
	ListNode *front;
	ListNode *rear;
}QueueNode;
typedef QueueNode *Queue;

void Init_Queue(Queue &Q)
{
	Q=(Queue)malloc(sizeof(QueueNode));						//ΪQueue����ռ�
	Q->rear=(QNode)malloc(sizeof(QNode));						//Ϊrear����ռ� 
	Q->front=(QNode)malloc(sizeof(QNode));						//Ϊfront����ռ�
	Q->rear->next=Q->front;									//rear��ָ��ֵΪNULL
	Q->front->next=NULL;									//front��ָ����ָ��rear
}

bool Queue_Empty(Queue Q)
{
	if(Q->front->next==NULL)									//front��ָ����Ϊ�գ�����Ϊ��
		return true;
	else
		return false;
}

void In_Queue(Queue &Q,DataType value)
{
     QNode NewNode=(QNode)malloc(sizeof(QNode));				//Ϊ�½�����ռ�
	 NewNode->elem=value;									//Ϊ�½�㸳ֵ
     NewNode->next=NULL;									//�½ڵ�Ҫ�����β����ָ����Ϊ��
	 (Q->rear->next)->next=NewNode;							//�ı�βָ��ָ��ĵ�ָ����
	 Q->rear->next=NewNode;                         			//����rear��㣬ָ���½ڵ�
}

DataType Get_Top(Queue Q)
{
	if(!Queue_Empty(Q))
	{
		return Q->front->next->elem;
	}
	else
		printf("�����ѿ�");
}

DataType Out_Queue(Queue &Q)
{
	if(!Queue_Empty(Q))
	{
		DataType ch=Get_Top(Q);
		QNode Q1=Q->front->next;							//��ȡ��ǰ��ͷ���
		Q->front->next=Q1->next;								//�޸Ķ�ͷ����ָ����
		if(Q->front->next==NULL)
		Q->rear->next=Q->front->next;							//��rearָ��front���ָ���ʼ��״̬
		return ch;
	}
	else
		printf("�����ѿ�!");
}

void main()
{
	Queue Q;         //QΪһ��ʽ�洢�ķ�ѭ������
    int flag=1;
    char j,ch;
	//---------------------------�����˵--------------------------
	printf("����������ʵ����ʽ�洢�ķ�ѭ�����С�\n");
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
		printf("5.ȡ��ͷԪ��\n");
        printf("6.�˳�����    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			ListNode *LN;
			if(!Queue_Empty(Q))
			{
				for(LN=Q->front->next;LN!=NULL;LN=LN->next)
					printf("%c  ",LN->elem);
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
			if(!Queue_Empty(Q))
				printf("��ͷԪ�� %c",Get_Top(Q));
			else
				printf("���п�");
			printf("\n");
			break;
		default:
			flag=0;
			printf("�����������������˳�!\n");
		}
	}
}
