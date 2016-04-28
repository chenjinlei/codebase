#include<stdio.h>
#include<stdlib.h>

#define MAXE 100                     /*定义最大空间100*/
struct edges                         
{int bv;
 int tv;
 int w;
};
typedef struct edges edgeset;
int seeks(int set[],int v)           /*定义一个整形变量seeks*/
{int i;
 i=v;
 while(set[i]>0) i=set[i];
 return i;
}
/*
void kruskal(edgeset ge[],int n,int e)
{
	int set[MAXE],v1,v2,i,j;
    for(i=1;i<n+1;i++) set[i]=0;
    i=1;
    j=1;
    while(j<=e&&i<=n-1)
	{
		v1=seeks(set,ge[j].bv);
        v2=seeks(set,ge[j].tv);
        if(v1!=v2)
		{
			printf("(%d,%d):%d\n",ge[j].bv,ge[j].tv,ge[j].w);
            set[v1]=v2;
            i++;
		}
        j++;
	}
}
*/
void insertsort(edgeset ge[],int e)
{
	int i,j;
	for(i=2;i<=e;i++)
    if(ge[i].w<ge[i-1].w)
	{
		ge[0]=ge[i];
        j=i-1;
        while(ge[0].w<ge[j].w)
		{
			ge[j+1]=ge[j];
            j--;
		}
        ge[j+1]=ge[0];
	}
}
/////
void dijkstra(int cost[MAXE][MAXE],int dist[MAXE],int path[MAXE],int s[MAXE],int n,int v0)             /*定义函数dijkstra*/
{
	int u,vnum,w,wm;
    for(w=1;w<=n;w++)
	{
		dist[w]=cost[v0][w];
        if(cost[v0][w]<32767)
        path[w]=v0;
	}
    vnum=1;
    while(vnum<=n-1)
	{
		wm=32767;
        u=v0;
        for(w=1;w<=n;w++)
           if(s[w]==0&&dist[w]<wm)
		   {
			   u=w;
               wm=dist[w];
		   }
        s[u]=1;
        vnum++;
        for(w=1;w<=n;w++)
        if(s[w]==0&&dist[u]+cost[u][w]<dist[w]&&cost[u][w]!=32767)
		{
			dist[w]=dist[u]+cost[u][w];
            path[w]=u;
		}
	}
}


void printpath1(int dist[],int path[],int s[],int n,int v0)
/*定义函数printpaht1*/
{int i,k;
 for(i=1;i<=n;i++)
  if(s[i]==1)
  {k=i;
   while(k!=v0)
    {printf("%d<-",k);
     k=path[k];
    }
    printf("%d:%d\n",k,dist[i]);
   }
  else
  printf("%d<-%d:32767\n",i,v0);
}
void printpath2(int dist[],int path[],int v0,int v1)/*定义函数printpath2*/
{int k;
 k=v1;
 while(k!=v0)
    {printf("%d<-",k);
     k=path[k];
    }

 printf("%d:%d\n",k,dist[v1]);
}

void main()
{edgeset ge[MAXE];
 int cost[MAXE][MAXE],dist[MAXE],path[MAXE],s[MAXE],a,n,e,i,j,k,v0,v1;
 printf("input the number of point:");
 scanf("%d",&n);
 printf("input the number of edges:");
 scanf("%d",&e);
 printf("input the edges:\n");
 for(i=1;i<=e;i++)
  scanf("%d,%d,%d",&ge[i].bv,&ge[i].tv,&ge[i].w);
 printf("please choise\n");
 printf("1.kruskal\n ");
 printf("2.shortpath\n");
 printf("3.shortpath between two point\n");
 printf("4.exit\n");
 scanf("%d",&a);
 while(a!=4)
  {switch(a)
    {case 1:insertsort(ge,e);
	    kruskal(ge,n,e);
	    break;
     case 2:printf("input the start point:");/*请输入开始位置*/
	    scanf("%d",&v0);
	    for(i=1;i<=n;i++)
	     for(j=1;j<=n;j++)
	      cost[i][j]=32767;
	    for(k=1;k<=e;k++)
	     {i=ge[k].bv;
	      j=ge[k].tv;
	      cost[i][j]=ge[k].w;
	     }
	    for(i=1;i<=n;i++)
	     s[i]=0;
	    s[v0]=1;
	    dijkstra(cost,dist,path,s,n,v0);
	    printpath1(dist,path,s,n,v0);
	    break;
     case 3:printf("input the start point:");/*请输入插入点位置*/
	    scanf("%d",&v0);
	    printf("input the end point:");
	    scanf("%d",&v1);
	    for(i=1;i<=n;i++)
	     for(j=1;j<=n;j++)
	      cost[i][j]=32767;
	    for(k=1;k<=e;k++)
	     {i=ge[k].bv;
	      j=ge[k].tv;
	      cost[i][j]=ge[k].w;
	     }
	    for(i=1;i<=n;i++)
	     s[i]=0;
	    s[v0]=1;
	    dijkstra(cost,dist,path,s,n,v0);
	    printpath2(dist,path,v0,v1);
	    break;
    }
   printf("please choise\n");
   printf("1.kruskal\n ");
   printf("2.shortpath\n");
   printf("3.shortpath between two point\n");
   printf("4.exit\n");
   scanf("%d",&a);
 }
}
