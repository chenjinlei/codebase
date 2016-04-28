#include "stdio.h"
#include <stdlib.h> 

#define   MAX   100 
typedef  struct SqQueue
{
	int queue[MAX];
	int front, rear;
}SqQueue;

void InitQueue_Sq(SqQueue *Q)								//构造一个空队列Q
{ 
	Q->front=0; 
	Q->rear=0;
}

void EnQueue(SqQueue *Q,  int x)							//入队
{    
	if((Q->rear+1)%MAX== Q->front)
     {
		printf("队已满，不可以入队");
        exit(1);
	}
	Q->queue[Q->rear]=x;
    Q->rear=(Q->rear+1)%MAX;								//指向下一个元素
}

int DeQueue(SqQueue* Q,  int x)								//出队列
{ 
	if(Q->rear==Q->front)
 	{
		printf("队已空，无元素可以出队");
    	return 0;
 	}
	x=Q->queue[Q->front];
	Q->front=(Q->front+1)%MAX;								//循环意义上的加1
	return x;
}

void main()
{
	SqQueue *Q;         //Q为一循环队列
	Q=(SqQueue *)malloc(sizeof(SqQueue));
    int flag=1;
    char j;
	int ch;
	//---------------------------程序解说--------------------------
	printf("本程序用来实现循环队列。\n");
	printf("可以实现入队列、出队列、获取队头元素等操作。\n");
	//-------------------------------------------------------------
    InitQueue_Sq(Q);         //初始化队列
    while(flag)
	{ 
		printf("请选择:\n");
        printf("1.显示从队头到队尾所有元素\n");
        printf("2.入队一个元素\n");
        printf("3.出队一个元素\n");
		printf("4.取队头元素\n");
        printf("5.退出程序    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			int i;
			if(Q->rear!=Q->front)
			{
				printf("队列非空");
				for(i=Q->front;i!=Q->rear;)
				{
					printf("%d  ",Q->queue[i]);
					i=(i+1)%MAX;
				}
			}
			else
				printf("队列空");
			printf("\n");
			break; //显示从队头到队尾的所有元素
		case '2':
			getchar();                 //输入的回车
			printf("请输入要入队的元素(一个整数):\n");
            scanf("%d",&ch);  //输入要入队的元素
			EnQueue(Q,ch);//入队
            break;
		case '3':
			int x;
			DeQueue(Q,x);//出队
            break;
		case '4':
			if(Q->rear!=Q->front)
				printf("队头元素 %d",Q->queue[Q->front]);
			else
				printf("队列空");
			printf("\n");
			break;
		default:
			flag=0;
			printf("程序结束，按任意键退出!\n");
		}
	}
}