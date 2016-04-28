
#include <stdio.h>

#define MAXVEX 30
#define MAXCOST 1000

void prim(int c[MAXVEX][MAXVEX],int n)
     /*己知图的顶点为{1,2,...,n},c[i][j]和c[j][i]为边(i,j)的权，打印最小生成树
       的每条边*/
{
     int i,j,k,min,lowcost[MAXVEX],closest[MAXVEX];
     for (i=2;i<=n;i++) /*从顶点1开始*/
     {
	     lowcost[i]=c[1][i];
         closest[i]=1;
     }
     closest[1]=0;
     
	 for (i=2;i<=n;i++)  /*从U之外求离U中某一顶点最近的顶点*/
     {
	    min=MAXCOST;
	    j=1;
		k=i;
	    while (j<=n)
		{
	       if (lowcost[j]<min && closest[j]!=0)
           {
	          min=lowcost[j];
              k=j;
		   }
	      j++;
		}
	   printf("(%d,%d) ",closest[k],k); /*打印边*/
	   closest[k]=0;      /*k加入到U中*/
       
	   for (j=2;j<=n;j++)
	      if (closest[j]!=0 && c[k][j]<lowcost[j])
		  {
	         lowcost[j]=c[k][j];
	         closest[j]=k;
		  }
    }
}


void main(void)
{
    int n=7,i,j,mx[MAXVEX][MAXVEX];
    for (i=0;i<=n;i++)
		for (j=0;j<=n;j++)
			mx[i][j]=MAXCOST;
		
		mx[1][2]=50;
		mx[1][3]=60;
		
		mx[2][4]=65;
		mx[2][5]=40;
		
		mx[3][4]=52;
		mx[3][7]=45;
		
		mx[4][5]=50;
		
		mx[5][6]=70;
		mx[4][6]=30;
		mx[4][7]=42;
		printf("最小生成树边集:\n  ");
		prim(mx,n);
}