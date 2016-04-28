#include "stdio.h"
#include <stdlib.h> 

#define   MAX   100 
typedef  struct SqQueue
{
	int queue[MAX];
	int front, rear;
}SqQueue;

void InitQueue_Sq(SqQueue *Q)								//����һ���ն���Q
{ 
	Q->front=0; 
	Q->rear=0;
}

void EnQueue(SqQueue *Q,  int x)							//���
{    
	if((Q->rear+1)%MAX== Q->front)
     {
		printf("�����������������");
        exit(1);
	}
	Q->queue[Q->rear]=x;
    Q->rear=(Q->rear+1)%MAX;								//ָ����һ��Ԫ��
}

int DeQueue(SqQueue* Q,  int x)								//������
{ 
	if(Q->rear==Q->front)
 	{
		printf("���ѿգ���Ԫ�ؿ��Գ���");
    	return 0;
 	}
	x=Q->queue[Q->front];
	Q->front=(Q->front+1)%MAX;								//ѭ�������ϵļ�1
	return x;
}

void main()
{
	SqQueue *Q;         //QΪһѭ������
	Q=(SqQueue *)malloc(sizeof(SqQueue));
    int flag=1;
    char j;
	int ch;
	//---------------------------�����˵--------------------------
	printf("����������ʵ��ѭ�����С�\n");
	printf("����ʵ������С������С���ȡ��ͷԪ�صȲ�����\n");
	//-------------------------------------------------------------
    InitQueue_Sq(Q);         //��ʼ������
    while(flag)
	{ 
		printf("��ѡ��:\n");
        printf("1.��ʾ�Ӷ�ͷ����β����Ԫ��\n");
        printf("2.���һ��Ԫ��\n");
        printf("3.����һ��Ԫ��\n");
		printf("4.ȡ��ͷԪ��\n");
        printf("5.�˳�����    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			int i;
			if(Q->rear!=Q->front)
			{
				printf("���зǿ�");
				for(i=Q->front;i!=Q->rear;)
				{
					printf("%d  ",Q->queue[i]);
					i=(i+1)%MAX;
				}
			}
			else
				printf("���п�");
			printf("\n");
			break; //��ʾ�Ӷ�ͷ����β������Ԫ��
		case '2':
			getchar();                 //����Ļس�
			printf("������Ҫ��ӵ�Ԫ��(һ������):\n");
            scanf("%d",&ch);  //����Ҫ��ӵ�Ԫ��
			EnQueue(Q,ch);//���
            break;
		case '3':
			int x;
			DeQueue(Q,x);//����
            break;
		case '4':
			if(Q->rear!=Q->front)
				printf("��ͷԪ�� %d",Q->queue[Q->front]);
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