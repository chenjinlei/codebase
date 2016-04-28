#include <stdio.h>
#include <stdlib.h>
#define max 10
#define increment 5
int net[max][max],x,NUM;
struct stack
{int e[max];
	int top;
	int stacksize;
};

void Initstack(struct stack *p)
{
	p->top=-1;
	p->stacksize=0;
}

void Push(struct stack *p,int h)
{
	int i;
     if(p->top>=p->stacksize)
       {p->stacksize=p->stacksize+increment;
	p->top++;
	p->e[p->top]=h;
       }
     else
	{p->top++;
	 p->e[p->top]=h;
	}
}
void Pop(struct stack *p,int *h)
    {if(p->top==-1)
       {printf("ERR  PoP");
	return;
       }
    else
       {*h=p->e[p->top];
	p->top--;
       }
}
void Gettop(struct stack p,int *h)
{ if(p.top==-1)
	  {printf("ERR GettoP");
	   return;
	  }
       *h=p.e[p.top];
}

void AOE(int m)  /*初始化一个AOE网，以矩阵储存，x为图号*/
{
    int i,j;
    if(m==1)
	{ NUM=6;
     for(i=1;i<=NUM;i++)   
     for(j=0;j<=NUM;j++)
        net[i][j]=-999; /*两点不存在连通权值用－999代替*/
 net[1][3]=2;net[1][2]=3;
 net[2][4]=2;net[2][5]=3;
 net[3][4]=4;net[3][6]=3;
 net[4][6]=2;
 net[5][6]=1;
   } 

if(m==2)
  {NUM=9;
   for(i=1;i<=NUM;i++)   
     for(j=0;j<=NUM;j++)
          net[i][j]=-999; /*两点不存在连通权值用－999代替*/
    net[1][3]=4;net[1][2]=6;net[1][4]=5;
   net[2][5]=1;
   net[3][5]=1;
   net[4][6]=2;
   net[5][7]=9;net[5][8]=7;
   net[6][8]=4;
   net[7][9]=2;
   net[8][9]=5;
   }
}

int indegree(int m) /*求点x的入度*/
{
	int i,degree=0;
      if(x==1)NUM=6;
      if(x==2)NUM=9;
     for(i=1;i<=NUM;i++)
        {if(net[i][m]>0)
            degree++;  /*计数*/
        }
     return(degree);   /*返回度数*/
    
}


void toporder(struct stack *T)  /*求拓扑序列*/
{int i,k,count=0,j,net1[max][max];
 struct stack S;
 Initstack(&S);
 if(x==1)NUM=6;
 if(x==2)NUM=9;
 AOE(x);
 
 Initstack(&S);
 for(i=1;i<=NUM;i++)
    { 
       if(indegree(i)==0) /*建入度为0的点栈S*/
        Push(&S,i);
     }
 Initstack(T);
 while(S.top!=-1)
     { Pop(&S,&j);
       Push(T,j);
       printf(" V%d,",j);
       count++;       /*计数，判断是否有回路*/
       for(i=1;i<=NUM;i++)
          {if(net[j][i]>0)   /*与j相邻的点度数减1，*/
             { net[j][i]=-999; 
               if(indegree(i)==0) /*为0的进栈*/
                 Push(&S,i);
             }
          }
      }
    if(count<NUM)  /*count小于NUM证明有回路，输出错误*/
    { 
      printf("\n\n\t\tERROR,there is circle int the grath");
    }
    AOE(x);/**/
}



void keypath(struct stack T)   /*求关键路径*/
  {int e[max]={0},l[max]={0},i,j,k,z;
   struct stack M;
   Initstack(&M);
   if(x==1)NUM=6;
   if(x==1)NUM=9;
   AOE(x);
   for(k=0,i=T.e[0];k<=T.top;k++,i=T.e[k]) /*求事件最早发生时间V[]*/
      {for(j=1;j<=NUM;j++)
          { if(net[i][j]+e[i]>e[j])   
            e[j]=net[i][j]+e[i];
           }
       }
 for(i=1;i<=NUM;i++)       /*初始化事件最早发生时间*/
     l[i]=e[NUM];
  while(T.top!=-1)         /*求事件最迟发生时间l[]*/
       {Pop(&T,&z);
        Push(&M,z);        /*转为正拓扑序列，放在堆栈M*/
        for(j=1;j<=NUM;j++)
           {if(l[z]-net[j][z]<l[j])
               l[j]=l[z]-net[j][z];
           }
       }
   
  while(M.top!=-1)    /*按拓扑序列求关键路径*/
       {Pop(&M,&z);
        if(l[z]==e[z])
           printf(" V%d",z);  /*输出关键路径*/

        }
}

void main()
{
	int i,j,m=1;
    struct stack T;
    while(1)
	{
        printf("\nChioce G1 or G2? \n\t1.G1 \n\t2.G2 \n\t  Exit    <0>");
        scanf("%d",&x);
        switch(x)
		{case 0:m=0;break;
	     case 1:         /*建AOE网*/
               printf("\n\nThe topo logical order is: "); 
               toporder(&T);  /*求拓扑逆序列放进堆栈T*/
               printf("\n\nThe key path is: "); 
               keypath(T);    /*求关键路径*/  
               break;
	      case 2:
			  printf("\n\nThe topo logical order is: "); 
               toporder(&T);  /*求拓扑逆序列放进堆栈T*/
               printf("\n\nThe key path is: "); 
               keypath(T);    /*求关键路径*/  
               break;
                
         
        }
         if(m==0)
         {m=1;
           break;
         } 
   
         printf("\n\n\t\tPress anykey to contiue !");
   }


}