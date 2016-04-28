#include "stdio.h"
#include "malloc.h"
typedef char DataType;
typedef struct Node									//定义结点
{
	DataType elem;
	Node * next;
}ListNode;
typedef ListNode *QNode;

typedef struct										//定义队头和队尾指针
{
	ListNode *front;
	ListNode *rear;
}QueueNode;
typedef QueueNode *Queue;

void Init_Queue(Queue &Q)
{
	Q=(Queue)malloc(sizeof(QueueNode));						//为Queue分配空间
	Q->rear=(QNode)malloc(sizeof(QNode));						//为rear分配空间 
	Q->front=(QNode)malloc(sizeof(QNode));						//为front分配空间
	Q->rear->next=Q->front;									//rear的指针值为NULL
	Q->front->next=NULL;									//front的指针域指向rear
}

bool Queue_Empty(Queue Q)
{
	if(Q->front->next==NULL)									//front的指针域为空，队列为空
		return true;
	else
		return false;
}

void In_Queue(Queue &Q,DataType value)
{
     QNode NewNode=(QNode)malloc(sizeof(QNode));				//为新结点分配空间
	 NewNode->elem=value;									//为新结点赋值
     NewNode->next=NULL;									//新节点要插入队尾所以指针域为空
	 (Q->rear->next)->next=NewNode;							//改变尾指针指向的的指针域。
	 Q->rear->next=NewNode;                         			//更新rear结点，指向新节点
}

DataType Get_Top(Queue Q)
{
	if(!Queue_Empty(Q))
	{
		return Q->front->next->elem;
	}
	else
		printf("队列已空");
}

DataType Out_Queue(Queue &Q)
{
	if(!Queue_Empty(Q))
	{
		DataType ch=Get_Top(Q);
		QNode Q1=Q->front->next;							//获取当前队头结点
		Q->front->next=Q1->next;								//修改队头结点的指针域
		if(Q->front->next==NULL)
		Q->rear->next=Q->front->next;							//将rear指向front，恢复初始化状态
		return ch;
	}
	else
		printf("队列已空!");
}

void main()
{
	Queue Q;         //Q为一链式存储的非循环队列
    int flag=1;
    char j,ch;
	//---------------------------程序解说--------------------------
	printf("本程序用来实现链式存储的非循环队列。\n");
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
		printf("5.取队头元素\n");
        printf("6.退出程序    \n");
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
			if(!Queue_Empty(Q))
				printf("队头元素 %c",Get_Top(Q));
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
