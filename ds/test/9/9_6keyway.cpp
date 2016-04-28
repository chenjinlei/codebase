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

void AOE(int m)  /*��ʼ��һ��AOE�����Ծ��󴢴棬xΪͼ��*/
{
    int i,j;
    if(m==1)
	{ NUM=6;
     for(i=1;i<=NUM;i++)   
     for(j=0;j<=NUM;j++)
        net[i][j]=-999; /*���㲻������ͨȨֵ�ã�999����*/
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
          net[i][j]=-999; /*���㲻������ͨȨֵ�ã�999����*/
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

int indegree(int m) /*���x�����*/
{
	int i,degree=0;
      if(x==1)NUM=6;
      if(x==2)NUM=9;
     for(i=1;i<=NUM;i++)
        {if(net[i][m]>0)
            degree++;  /*����*/
        }
     return(degree);   /*���ض���*/
    
}


void toporder(struct stack *T)  /*����������*/
{int i,k,count=0,j,net1[max][max];
 struct stack S;
 Initstack(&S);
 if(x==1)NUM=6;
 if(x==2)NUM=9;
 AOE(x);
 
 Initstack(&S);
 for(i=1;i<=NUM;i++)
    { 
       if(indegree(i)==0) /*�����Ϊ0�ĵ�ջS*/
        Push(&S,i);
     }
 Initstack(T);
 while(S.top!=-1)
     { Pop(&S,&j);
       Push(T,j);
       printf(" V%d,",j);
       count++;       /*�������ж��Ƿ��л�·*/
       for(i=1;i<=NUM;i++)
          {if(net[j][i]>0)   /*��j���ڵĵ������1��*/
             { net[j][i]=-999; 
               if(indegree(i)==0) /*Ϊ0�Ľ�ջ*/
                 Push(&S,i);
             }
          }
      }
    if(count<NUM)  /*countС��NUM֤���л�·���������*/
    { 
      printf("\n\n\t\tERROR,there is circle int the grath");
    }
    AOE(x);/**/
}



void keypath(struct stack T)   /*��ؼ�·��*/
  {int e[max]={0},l[max]={0},i,j,k,z;
   struct stack M;
   Initstack(&M);
   if(x==1)NUM=6;
   if(x==1)NUM=9;
   AOE(x);
   for(k=0,i=T.e[0];k<=T.top;k++,i=T.e[k]) /*���¼����緢��ʱ��V[]*/
      {for(j=1;j<=NUM;j++)
          { if(net[i][j]+e[i]>e[j])   
            e[j]=net[i][j]+e[i];
           }
       }
 for(i=1;i<=NUM;i++)       /*��ʼ���¼����緢��ʱ��*/
     l[i]=e[NUM];
  while(T.top!=-1)         /*���¼���ٷ���ʱ��l[]*/
       {Pop(&T,&z);
        Push(&M,z);        /*תΪ���������У����ڶ�ջM*/
        for(j=1;j<=NUM;j++)
           {if(l[z]-net[j][z]<l[j])
               l[j]=l[z]-net[j][z];
           }
       }
   
  while(M.top!=-1)    /*������������ؼ�·��*/
       {Pop(&M,&z);
        if(l[z]==e[z])
           printf(" V%d",z);  /*����ؼ�·��*/

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
	     case 1:         /*��AOE��*/
               printf("\n\nThe topo logical order is: "); 
               toporder(&T);  /*�����������зŽ���ջT*/
               printf("\n\nThe key path is: "); 
               keypath(T);    /*��ؼ�·��*/  
               break;
	      case 2:
			  printf("\n\nThe topo logical order is: "); 
               toporder(&T);  /*�����������зŽ���ջT*/
               printf("\n\nThe key path is: "); 
               keypath(T);    /*��ؼ�·��*/  
               break;
                
         
        }
         if(m==0)
         {m=1;
           break;
         } 
   
         printf("\n\n\t\tPress anykey to contiue !");
   }


}