#include "stdio.h"
#include <stdlib.h>
#define MAXSIZE 100
typedef int DataType;				//DataType数据类型预定义
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

DataType Get_Top(Queue Q)
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
		DataType ch=Get_Top(Q);
        Q.front=Q.front+1;
		return ch;
	}
	else
		printf("队列已空！");
}


//农夫过河问题
		
int farmer(int location)										//判断农夫的位置
{
    return (0 != (location &0x08));
}
int wolf(int location)											//判断狼的位置
{
    return (0 != (location &0x04));
}
int cabbage(int location) 										//判断白菜的位置
{
    return (0 != (location &0x02));
}
int goat(int location)											 //判断羊的位置
{
    return (0 != (location &0x01));
}
int safe(int location)											//若状态安全则返回true
{	
	if ((goat(location) == cabbage(location)) && (goat(location) != farmer	//羊吃白菜
        (location)))
        return (0);
    if ((goat(location) == wolf(location)) && (goat(location) != farmer		//狼吃羊
        (location)))
        return (0);
    return (1); 												//其他状态是安全的
}
void farmerproblem()
{
    int i, movers, location, newlocation;
    int route[16];											//用于记录已考虑的状态路径
	Queue moveTo;											//用于记录可以安全到达的中间状态
	Init_Queue(moveTo);
    In_Queue (moveTo, 0x00);								//初始状态进队列
    for (i = 0; i < 16; i++)
        route[i] =  - 1;	
    route[0] = 0;											//准备数组route初值
    while (!Queue_Empty(moveTo) && (route[15] ==  - 1))
    {
        location =Get_Top(moveTo);							//取队头状态为当前状态
        Out_Queue (moveTo);
        for (movers = 1; movers <= 8; movers <<= 1)				//考虑各种物品移动
            if ((0 != (location &0x08)) == (0 != (location &movers)))		//农夫与移动的物品在同一侧
			{
				newlocation = location ^ (0x08 | movers);			//计算新状态
				if (safe(newlocation) && (route[newlocation] == - 1))	//新状态安全且未处理
				{
					route[newlocation] = location;				//记录新状态的前驱
					In_Queue (moveTo, newlocation);			//新状态入队
				}
			}
    }
    														//打印出路径
    if (route[15] !=  - 1)										//到达最终状态
    {
        printf("逆序的路径为: \n");
        for (location = 15; location >= 0; location = route[location])
        {
            printf("当前位置 : %d\n", location);
            if (location == 0)
                exit(0);
        }
    }
    else
        printf("问题无解.\n");									//问题无解
}
void main()
{
	farmerproblem();
}