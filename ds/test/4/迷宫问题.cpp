#include "stdio.h"
//�Թ�����
//1���Թ������ݽṹ
#define ROW 8					                            //ROW��ʾ�Թ�������
#define COLUMN 8				                            //COLUMN��ʾ�Թ�������
#define STEP ROW*COLUMN		                                //STEP��ʾ���е�����	
//2���ƶ�����
struct MoveD							                    //����ṹ��������ʾ�Թ��е��ƶ�����
{
	int x, y;							                    //x,y����������ȡֵ-1��0��1
}move[8]; //һ����8�ַ���
//3����ֹ�ظ�����ĳ����������־������¼�Թ�·���ӵĶ������£�
struct StepQueue											//����������¼�Թ�̽·�Ķ���
{
	int x,y;    
	int PreStep;
}StepQ[STEP],tmpStepQ[STEP];


//ʵ��Ѱ���Թ�����·���ĺ�����
int PathMaze(int maze[ROW][COLUMN])							//�Թ�̽·����
{
	int i,j,k,v,front,rear,x,y,l;
	int mark[ROW][COLUMN];								    //������������¼�Ƿ񵽴��ĳ����
	for(i=0;i<ROW;i++)
		for(j=0;j<COLUMN;j++)
			mark[i][j]=0;									//�����г�ʼ��
	StepQ[1].x=1;											//��ʼ����ڵ�	
	StepQ[1].y=1;
	StepQ[1].PreStep=0;
	front=1;
	rear=1;
	mark[1][1]=1;   
	while(front<=rear)
	{
		
		x=StepQ[front].x;									//��(x,y)Ϊ�������������
		y=StepQ[front].y;
		  
		for(v=0;v<8;v++)									//����(x,y)��8������(i,j)�Ƿ���Ե���
		{
			i=x+move[v].x;
			j=y+move[v].y;
			if((maze[i][j]==0)&&(mark[i][j]==0))			//(i,j)Ϊ���Ե���㣬�������
			{
				rear++;
				StepQ[rear].PreStep=front;
				StepQ[rear].x=i;
				StepQ[rear].y=j;
				mark[i][j]=1; 
			}
			if((i==ROW-2)&&(j==COLUMN-2))					//���������ڣ������·��
			{
				printf("\n�Թ�·��: \n\n");
				k=rear;
				l=0;
				while(k!=0)								    //k==0˵���Ѿ�����
				{
					tmpStepQ[l++].x=StepQ[k].x;
					tmpStepQ[l++].y=StepQ[k].y;
					k=StepQ[k].PreStep;						//��ǰһ��
				}
				while(l>0)									//���·��
					printf("(%d,%d)>",tmpStepQ[--l].x,tmpStepQ[--l].y);
				//printf("(%d,%d)",tmpStepQ[0].x,tmpStepQ[0].y);
				return(1);      
			}
		}
		front++;											//�Ӷ����г��ӣ�frontָ���µĳ�����

	} 													//�ӿ�˵��û��·��
	printf("û��·����! \n");
	return(0); 
}
void main()
{
	int maze[ROW][COLUMN];
	int i,j,index_x,index_y;
	for(i=0;i<ROW;i++)//��һ�к����һ��Ϊ1,��һ�к����һ��Ϊ1
	{
		for(j=0;j<COLUMN;j++)
			if(i==0||i==ROW-1)
				maze[i][j]=j;
			else if(j==0||j==COLUMN-1)
				maze[i][j]=i;
			else
				maze[i][j]=0;
	}
	//��ʼ������
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
		printf("�Թ����(1,1),����(6,6),������1-8�ϰ�����,����0����,��2,3\n");
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