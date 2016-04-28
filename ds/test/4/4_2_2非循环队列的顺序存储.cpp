#include "stdio.h"

#define MAXSIZE 100
typedef char DataType;				//DataType数据类型预定义
typedef struct
{
	DataType elem[MAXSIZE];								//队列中元素
	int front;												//队头
	int rear;												//队尾
}Queue;

void Init_Queue(Queue &Q)
{
	Q.rear=0;
	Q.front=0;
}

bool Queue_Empty(Queue Q)
{
	if(Q.front==Q.rear)										//front=rear时，队列为空
		return true;
	else
		return false;
}

bool Queue_Full(Queue Q)
{
	if(Q.rear+1==MAXSIZE)									//rear+1等于MAXSIZE，队列为满
		return true;
	else
		return false;
}

void In_Queue(Queue &Q,DataType elem)
{
	if(!Queue_Full(Q))
	{
        Q.elem[Q.rear]=elem;
		Q.rear=Q.rear+1;									//向队尾插入元素，先将rear前移一位
	}
	else
		printf("队列已满！");
}

DataType GetTop(Queue Q)
{
	if(!Queue_Empty(Q))										//如果队列不为空，返回队头元素
	{
		return Q.elem[Q.front];
	}
	else
		printf("队列中已经没有元素！");
	 
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
		printf("队列已空！");
}


void main()
{
	Queue Q;         //Q为一顺序存储的非循环队列
    int flag=1;
    char j,ch;
	//---------------------------程序解说--------------------------
	printf("本程序用来实现顺序存储的非循环队列。\n");
	printf("可以实现入队列、出队列、获取队头元素等操作。\n");
	//-------------------------------------------------------------
    Init_Queue(Q);         //初始化队列
    while(flag)
	{ 
		printf("请选择:\n");
        printf("1.显示从队头到队尾所有元素\n");
        printf("2.入队一个元素\n");
        printf("3.出队一个元素\n");
        printf("4.判队空\n");
		printf("5.判队满\n");
		printf("6.取队头元素\n");
        printf("7.退出程序    \n");
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
				printf("队列空");
			printf("\n");
			break; //显示从队头到队尾的所有元素
		case '2':
			getchar();                 //输入的回车
			printf("请输入要入队的元素(一个字符):\n");
            scanf("%c",&ch);  //输入要入队的元素
			In_Queue(Q,ch);//入队
            break;
		case '3':
			Out_Queue(Q);//出队
            break;
		case '4':
			if(Queue_Empty(Q))
				printf("队列空");
			else 
				printf("队列非空");
			break;
		case '5':
			if(Queue_Full(Q))
				printf("队列满");
			else 
				printf("队列非满");
			break;
		case '6':
			if(!Queue_Empty(Q))
				printf("队头元素 %c",GetTop(Q));
			else
				printf("队列空!");
			printf("\n");
			break;
		default:
			flag=0;
			printf("程序结束，按任意键退出!\n");
		}
	}
}
