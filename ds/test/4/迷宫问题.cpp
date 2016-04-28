#include "stdio.h"
//迷宫问题
//1．迷宫的数据结构
#define ROW 8					                            //ROW表示迷宫的行数
#define COLUMN 8				                            //COLUMN表示迷宫的列数
#define STEP ROW*COLUMN		                                //STEP表示队列的容量	
//2．移动方向
struct MoveD							                    //定义结构体用来表示迷宫中的移动方向
{
	int x, y;							                    //x,y坐标增量，取值-1，0，1
}move[8]; //一共有8种方向
//3．防止重复到达某区域，设立标志给出记录迷宫路径队的定义如下：
struct StepQueue											//定义用来记录迷宫探路的队列
{
	int x,y;    
	int PreStep;
}StepQ[STEP],tmpStepQ[STEP];


//实现寻找迷宫可走路径的函数：
int PathMaze(int maze[ROW][COLUMN])							//迷宫探路函数
{
	int i,j,k,v,front,rear,x,y,l;
	int mark[ROW][COLUMN];								    //声明标记数组记录是否到达过某个点
	for(i=0;i<ROW;i++)
		for(j=0;j<COLUMN;j++)
			mark[i][j]=0;									//并进行初始化
	StepQ[1].x=1;											//初始化入口点	
	StepQ[1].y=1;
	StepQ[1].PreStep=0;
	front=1;
	rear=1;
	mark[1][1]=1;   
	while(front<=rear)
	{
		
		x=StepQ[front].x;									//以(x,y)为出发点进行搜索
		y=StepQ[front].y;
		  
		for(v=0;v<8;v++)									//搜索(x,y)的8个相邻(i,j)是否可以到达
		{
			i=x+move[v].x;
			j=y+move[v].y;
			if((maze[i][j]==0)&&(mark[i][j]==0))			//(i,j)为可以到达点，将起入队
			{
				rear++;
				StepQ[rear].PreStep=front;
				StepQ[rear].x=i;
				StepQ[rear].y=j;
				mark[i][j]=1; 
			}
			if((i==ROW-2)&&(j==COLUMN-2))					//如果到达出口，则输出路径
			{
				printf("\n迷宫路径: \n\n");
				k=rear;
				l=0;
				while(k!=0)								    //k==0说明已经到达
				{
					tmpStepQ[l++].x=StepQ[k].x;
					tmpStepQ[l++].y=StepQ[k].y;
					k=StepQ[k].PreStep;						//找前一点
				}
				while(l>0)									//输出路径
					printf("(%d,%d)>",tmpStepQ[--l].x,tmpStepQ[--l].y);
				//printf("(%d,%d)",tmpStepQ[0].x,tmpStepQ[0].y);
				return(1);      
			}
		}
		front++;											//从队列中出队，front指向新的出发点

	} 													//队空说明没有路径
	printf("没用路可走! \n");
	return(0); 
}
void main()
{
	int maze[ROW][COLUMN];
	int i,j,index_x,index_y;
	for(i=0;i<ROW;i++)//第一行和最后一行为1,第一列和最后一列为1
	{
		for(j=0;j<COLUMN;j++)
			if(i==0||i==ROW-1)
				maze[i][j]=j;
			else if(j==0||j==COLUMN-1)
				maze[i][j]=i;
			else
				maze[i][j]=0;
	}
	//初始化方向
	move[0].x=1;
	move[0].y=0;
	move[1].x=1;
	move[1].y=1;
	move[2].x=0;
	move[2].y=1;
	move[3].x=-1;
	move[3].y=1;
	move[4].x=-1;
	move[4].y=0;
	move[5].x=-1;
	move[5].y=-1;
	move[6].x=0;
	move[6].y=-1;
	move[7].x=1;
	move[7].y=-1;
	int flag=1;
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COLUMN;j++)
			printf("%d\t",maze[i][j]);
		printf("\n");
	}
	while(flag)
	{
		printf("迷宫入口(1,1),出口(6,6),请输入1-8障碍坐标,输入0结束,如2,3\n");
		scanf("%d,%d",&index_x,&index_y);
		if(index_x==0||index_y==0)
			flag=0;
		else
			maze[index_x][index_y]=1;
	    for(i=0;i<ROW;i++)
		{
			for(j=0;j<COLUMN;j++)
				printf("%d\t",maze[i][j]);
			printf("\n");
		}
	}
	PathMaze(maze);
}