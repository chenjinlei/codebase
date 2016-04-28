//* * * * * * * * * * * * * * * * * * * * * * * *
//最短路径 :弗洛依德算法               *
//* * * * * * * * * * * * * * * * * * * * * * * *

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY 10000    //定义权值的最大值 
#define MAX_NUM 20 //图的最大顶点数
enum BOOL {False,True};
typedef struct
{
	int arcs[MAX_NUM][MAX_NUM]; //邻接矩阵
    int vexnum,arcnum;                //图的当前顶点和边数
}Graph;
void CreateGraph(Graph &);    //生成图的邻接矩阵
void ShortestPath_Floyd(Graph,BOOL[][MAX_NUM][MAX_NUM],int[][MAX_NUM]);
    //用弗洛依德算法求每对顶点之间的最短路径
void Print_ShortestPath(Graph,BOOL[][MAX_NUM][MAX_NUM],int[][MAX_NUM]);
    //显示用弗洛依德算法所求得的最短路径
void Print_OnePath(int,int,int,BOOL[][MAX_NUM][MAX_NUM]);
    //显示一对顶点之间的最短路径
void main()
{
	Graph G;  //采用邻接矩阵结构的图
 char j='y';
 int u;
 BOOL P[MAX_NUM][MAX_NUM][MAX_NUM]; //存放每对顶点的最短路径
 int D[MAX_NUM][MAX_NUM];                 //存放每对顶点的最短路径的距离

 //------------------程序解说----------------------------
 printf("本程序将演示利用弗洛依德算法求图的每一对顶点之间的最短路径。\n");
 printf("首先输入图的顶点和弧的数目。\n例如：3,5\n");
 printf("接着输入弧(i,j)和其权值。\n例如：\n1,2,4\n2,1,6\n1,3,11\n3,1,3\n2,3,2\n");
 printf("程序将会显示出每对顶点之间的最短路径值和所经过的路径：\n");
 printf("4  1->2\n6  1->2->3\n5  2->3->1\n2  2->3\n3  3->1\n7  3->1->2\n");
 //------------------------------------------------------
 while(j!='N'&&j!='n')
      {CreateGraph(G);       //生成邻接矩阵结构的图
       ShortestPath_Floyd(G,P,D); //利用弗洛依德算法求最短路径
       Print_ShortestPath(G,P,D); //显示每对顶点之间的最短路径
       printf("继续执行吗?(Y/N)");
       scanf(" %c",&j);
     }
 printf("程序运行结束，按任意键退出窗口!");

}

void CreateGraph(Graph &G)
{//构造邻接矩阵结构的图G
 int i,j;
 int start,end,weight;
 printf("请输入顶点和弧的数目，格式：顶点数，弧数\n");
 scanf("%d,%d",&G.vexnum,&G.arcnum); //输入图的顶点数和边数
 for(i=1;i<=G.vexnum;i++)
    for(j=1;j<=G.vexnum;j++)
      G.arcs[i][j]=INFINITY; //初始化邻接矩阵
 printf("请输入各条弧和其权值，格式：弧尾，弧头，权值：\n");
 for(i=1;i<=G.arcnum;i++)
   {scanf("%d,%d,%d",&start,&end,&weight); //输入边的起点和终点及权值
    G.arcs[start][end]=weight;
   }
}
void ShortestPath_Floyd(Graph G,BOOL P[][MAX_NUM][MAX_NUM],int D[][MAX_NUM])
{//用弗洛依德算法求有向网G的每对顶点v和w之间的最短路径P[v][w]
 //及其带权路径长度D[v][w],
 //若P[v][w][u]为True,表明u是从v到w当前求得最短路径上的顶点
 int u,v,w,i;
 for(v=1;v<=G.vexnum;v++) //各对顶点之间的初始已知路径及距离
   for(w=1;w<=G.vexnum;w++)
    {D[v][w]=G.arcs[v][w];
     for(u=1;u<=G.vexnum;u++) P[v][w][u]=False;
     if(D[v][w]<INFINITY)     //从v到w有直接路径
	{P[v][w][v]=True;P[v][w][w]=True;}
    }
 for(u=1;u<=G.vexnum;u++)
    for(v=1;v<=G.vexnum;v++)
      for(w=1;w<=G.vexnum;w++)
	if(D[v][u]+D[u][w]<D[v][w]&&v!=w) //从v经u到w的一条路径更短
	   {D[v][w]=D[v][u]+D[u][w];
	    for(i=1;i<=G.vexnum;i++)
	       if(P[v][u][i]||P[u][w][i]) P[v][w][i]=True;
	   }
}

void Print_ShortestPath(Graph G,BOOL P[][MAX_NUM][MAX_NUM],int D[][MAX_NUM])
{//显示每对顶点之间的最短路径及距离
 int v,w,j;
 printf("最短路径：\n");
 for(v=1;v<=G.vexnum;v++)
   for(w=1;w<=G.vexnum;w++)
     if(D[v][w]<INFINITY)  //顶点v和w之间有通路
	{printf("%-5d",D[v][w]); //从v到w的最短距离
	 Print_OnePath(v,w,G.vexnum,P); //显示从v到w的最短路径
	 printf("\n");
	}
}
void Print_OnePath(int v,int w,int num,BOOL P[][MAX_NUM][MAX_NUM])
{//显示从v到w的最短路径
 int i;
 for(i=1;i<=num;i++)
    if(i!=v&&i!=w&&P[v][w][i]==True) break;
 if(i>num) printf("%d->%d",v,w); //说明从v到w不需经过其它的顶点
 else {Print_OnePath(v,i,num,P); //否则从v到w需经过顶点i，先显示从v到i的最短路径
       if(i<10) printf("\b");  //控制显示格式，消除多余的"->"
       else printf("\b\b");
       Print_OnePath(i,w,num,P); //显示从i到w的最短路径
      }
}
