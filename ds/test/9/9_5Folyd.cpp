//* * * * * * * * * * * * * * * * * * * * * * * *
//���·�� :���������㷨               *
//* * * * * * * * * * * * * * * * * * * * * * * *

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITY 10000    //����Ȩֵ�����ֵ 
#define MAX_NUM 20 //ͼ����󶥵���
enum BOOL {False,True};
typedef struct
{
	int arcs[MAX_NUM][MAX_NUM]; //�ڽӾ���
    int vexnum,arcnum;                //ͼ�ĵ�ǰ����ͱ���
}Graph;
void CreateGraph(Graph &);    //����ͼ���ڽӾ���
void ShortestPath_Floyd(Graph,BOOL[][MAX_NUM][MAX_NUM],int[][MAX_NUM]);
    //�ø��������㷨��ÿ�Զ���֮������·��
void Print_ShortestPath(Graph,BOOL[][MAX_NUM][MAX_NUM],int[][MAX_NUM]);
    //��ʾ�ø��������㷨����õ����·��
void Print_OnePath(int,int,int,BOOL[][MAX_NUM][MAX_NUM]);
    //��ʾһ�Զ���֮������·��
void main()
{
	Graph G;  //�����ڽӾ���ṹ��ͼ
 char j='y';
 int u;
 BOOL P[MAX_NUM][MAX_NUM][MAX_NUM]; //���ÿ�Զ�������·��
 int D[MAX_NUM][MAX_NUM];                 //���ÿ�Զ�������·���ľ���

 //------------------�����˵----------------------------
 printf("��������ʾ���ø��������㷨��ͼ��ÿһ�Զ���֮������·����\n");
 printf("��������ͼ�Ķ���ͻ�����Ŀ��\n���磺3,5\n");
 printf("�������뻡(i,j)����Ȩֵ��\n���磺\n1,2,4\n2,1,6\n1,3,11\n3,1,3\n2,3,2\n");
 printf("���򽫻���ʾ��ÿ�Զ���֮������·��ֵ����������·����\n");
 printf("4  1->2\n6  1->2->3\n5  2->3->1\n2  2->3\n3  3->1\n7  3->1->2\n");
 //------------------------------------------------------
 while(j!='N'&&j!='n')
      {CreateGraph(G);       //�����ڽӾ���ṹ��ͼ
       ShortestPath_Floyd(G,P,D); //���ø��������㷨�����·��
       Print_ShortestPath(G,P,D); //��ʾÿ�Զ���֮������·��
       printf("����ִ����?(Y/N)");
       scanf(" %c",&j);
     }
 printf("�������н�������������˳�����!");

}

void CreateGraph(Graph &G)
{//�����ڽӾ���ṹ��ͼG
 int i,j;
 int start,end,weight;
 printf("�����붥��ͻ�����Ŀ����ʽ��������������\n");
 scanf("%d,%d",&G.vexnum,&G.arcnum); //����ͼ�Ķ������ͱ���
 for(i=1;i<=G.vexnum;i++)
    for(j=1;j<=G.vexnum;j++)
      G.arcs[i][j]=INFINITY; //��ʼ���ڽӾ���
 printf("���������������Ȩֵ����ʽ����β����ͷ��Ȩֵ��\n");
 for(i=1;i<=G.arcnum;i++)
   {scanf("%d,%d,%d",&start,&end,&weight); //����ߵ������յ㼰Ȩֵ
    G.arcs[start][end]=weight;
   }
}
void ShortestPath_Floyd(Graph G,BOOL P[][MAX_NUM][MAX_NUM],int D[][MAX_NUM])
{//�ø��������㷨��������G��ÿ�Զ���v��w֮������·��P[v][w]
 //�����Ȩ·������D[v][w],
 //��P[v][w][u]ΪTrue,����u�Ǵ�v��w��ǰ������·���ϵĶ���
 int u,v,w,i;
 for(v=1;v<=G.vexnum;v++) //���Զ���֮��ĳ�ʼ��֪·��������
   for(w=1;w<=G.vexnum;w++)
    {D[v][w]=G.arcs[v][w];
     for(u=1;u<=G.vexnum;u++) P[v][w][u]=False;
     if(D[v][w]<INFINITY)     //��v��w��ֱ��·��
	{P[v][w][v]=True;P[v][w][w]=True;}
    }
 for(u=1;u<=G.vexnum;u++)
    for(v=1;v<=G.vexnum;v++)
      for(w=1;w<=G.vexnum;w++)
	if(D[v][u]+D[u][w]<D[v][w]&&v!=w) //��v��u��w��һ��·������
	   {D[v][w]=D[v][u]+D[u][w];
	    for(i=1;i<=G.vexnum;i++)
	       if(P[v][u][i]||P[u][w][i]) P[v][w][i]=True;
	   }
}

void Print_ShortestPath(Graph G,BOOL P[][MAX_NUM][MAX_NUM],int D[][MAX_NUM])
{//��ʾÿ�Զ���֮������·��������
 int v,w,j;
 printf("���·����\n");
 for(v=1;v<=G.vexnum;v++)
   for(w=1;w<=G.vexnum;w++)
     if(D[v][w]<INFINITY)  //����v��w֮����ͨ·
	{printf("%-5d",D[v][w]); //��v��w����̾���
	 Print_OnePath(v,w,G.vexnum,P); //��ʾ��v��w�����·��
	 printf("\n");
	}
}
void Print_OnePath(int v,int w,int num,BOOL P[][MAX_NUM][MAX_NUM])
{//��ʾ��v��w�����·��
 int i;
 for(i=1;i<=num;i++)
    if(i!=v&&i!=w&&P[v][w][i]==True) break;
 if(i>num) printf("%d->%d",v,w); //˵����v��w���辭�������Ķ���
 else {Print_OnePath(v,i,num,P); //�����v��w�辭������i������ʾ��v��i�����·��
       if(i<10) printf("\b");  //������ʾ��ʽ�����������"->"
       else printf("\b\b");
       Print_OnePath(i,w,num,P); //��ʾ��i��w�����·��
      }
}
