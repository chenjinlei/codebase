/*                 
1输入一个数列L，生成一棵二叉排序树T；
2对二叉排序树T作中序遍历，输出结果；
3计算二叉排序树T的平均查找长度, 输出结果；
4判断二叉排序树T是否为平衡二叉树，输出信息“OK！”/“NO！”；
5再使用上述数列L，生成平衡的二叉排序树BT，每当插入新元素，发现当前的二叉排序树BT不是平衡的二叉排序树，则立即将它转换成新的平衡的二叉排序树BT；
6计算平衡的二叉排序树BT的平均查找长度，输出结果。
6分析对比未平衡化的二叉排序树和平衡的二叉排序树的查找效率(最好、最坏平均比较关键字数)
*/

#include<stdio.h>             
#include <stdlib.h>
struct bnode                                /* Bnode为二叉树结点(结构)类型 */
{int data;                                  /* data为整形类型 */
 int bf;                                   /* 节点的平衡因子 */
 struct bnode *lchild,*rchild;              /* 左小孩，右小孩为指针类型  */
};
struct qnode                                /* qnode为队列结点类型 */
{struct bnode *data;                        /* data为二叉树结点指针 */
 struct qnode *next;                        /* next指向下一队列结点 */
};
struct linkqueue
{struct qnode *front;                       /* 队头结点指针 */
 struct qnode *rear;                        /* 队尾结点指针 */
};
#define N    50                             /* 数组初始大小 */
#define LENG1 sizeof(struct bnode)          /* 节点所占空间 */   
#define LENG2 sizeof(struct qnode)
#define LENG3 sizeof(struct linkqueue)

#define LH +1
#define EH 0
#define RH -1

struct bnode *creat_tree(struct bnode *t,int x)  /* 生成一棵二叉排序树 */
{if(t==NULL)                                     /* 生成空二叉排序树 */
  { t=(struct bnode *)malloc(LENG1);             /* 分配空间 */
	t->data=x;
	t->lchild=t->rchild=NULL;                /* 左右小孩置为空 */
 } 
 else
  { if(x<t->data)                                /* x大于结点 */
	  t->lchild=creat_tree(t->lchild,x);     /* 访问左子树 */
   else
	  t->rchild=creat_tree(t->rchild,x);     /* 访问右子树 */
  }
return t;                                        /* 返回根节点 */
}

struct bnode *inorder(struct bnode *root)        /* 中序遍历 */
{if(root)
 {root->lchild=inorder(root->lchild);            /* 访问左小孩 */
 printf("%d  ",root->data);                       /* 打印结点 */
 root->rchild=inorder(root->rchild);             /* 访问右小孩  */
 }
 return root;
}

struct bnode *preorder1(struct bnode *root,int *nu)  /* 先序遍历二叉树 */
{
 if(root)                                            
 {
  (*nu)++;                                           /* 计算非空结点个数 */
 root->lchild=preorder1(root->lchild,nu);            /* 访问左小孩 */    
  root->rchild=preorder1(root->rchild,nu);           /* 访问右小孩 */
 }
 return root;
}

struct bnode *preorder2(struct bnode *root)          /* 先序遍历二叉树 */
{
 if(root)
 {printf("%d  ",root->data);
  root->lchild=preorder2(root->lchild);              /* 访问左小孩 */
  root->rchild=preorder2(root->rchild);              /* 访问右小孩 */
 }
 return root;
}

struct linkqueue *enqueue(struct linkqueue *q,struct bnode *e)   /* 队列中插入结点 */
{struct qnode *p;
 p=(struct qnode *)malloc(LENG2);                   /* 给结点分配空间 */
 p->data=e;
 p->next=NULL;
 q->rear->next=p;
 q->rear=p;
 return q;
}



void compare(struct bnode *t,int x,int *Q)     
{if(t) 
  {
    if(x<t->data)                                    /* x大于结点 */
	{ (*Q)++;
           compare(t->lchild,x,Q);                   /* 访问左子树 */
          return;  
        }  
   else
    { if(x>t->data)                                  /* x小于结点 */
	 { (*Q)++;
           compare(t->rchild,x,Q);                   /* 访问右子树 */
           return;
         }     
      else return;
    }
  }
 else return;
}

float ASL(struct bnode *root,int s[N],int i)      /* 求二叉排序树T的平均查找长度 */
{ int j,L=0,*Q,A;
  float  ASL=0;
  for(j=0;j<=i;j++)
 {A=1;
  Q=&A;                                         /* Q初始值为1 */
  compare(root,s[j],Q);                         /* 求各结点查找长度 */
  L+=(*Q);                                      /* L为所有结点查找长度之和 */
 } 
  ASL=((float)L)/(i+1);                         /* ASL为二叉排序树T的平均查找长度 */
  printf("ASL=%.2f\n",ASL);                     /* 打印ASL */      
  return ASL;
}   

int depth(struct bnode *root,int *nu)           /* 求以root为根结点的二叉树的深度*/
{int c=0,n=0,u,v=0; 
 struct bnode *no;                              /* 定义空结点no */              
  struct qnode *s;                              /* 定义结点s */
  struct linkqueue *q;                          /* 定义结点q */
  if(root)
  { no=(struct bnode *)malloc(LENG1);           /* 为no分配空间 */      
    s=(struct qnode *)malloc(LENG2);            /* 为s分配空间 */
    q=(struct linkqueue *)malloc(LENG3);        /* 为q分配空间 */
    no->lchild=NULL;                            /* no左小孩为空 */
     no->data=0;                                /* no->data为零 */
     no->rchild=NULL;                           /* no右小孩为空 */
    q->front=q->rear=(struct qnode *)malloc(LENG2);
    q->front->next=NULL;
    enqueue(q,root);                            /* 调用enqueue函数 */
    s=q->front->next;
  while(c<*nu)                                  /* *nu二叉树非零结点个数 */                                 
   { n++;                                       /* n为队列结点个数 */
     if(s->data->data!=0)  c++; 
     if(s->data->lchild)
     enqueue(q,s->data->lchild);                /* 左小孩插入队列 */                               
     else enqueue(q,no);                        /* 空结点插入队列 */
     if(s->data->rchild)
     enqueue(q,s->data->rchild);                /* 右小孩插入队列 */
     else enqueue(q,no);                        /* 空结点插入队列 */
     s=s->next;
   }
   u=n;
   while(u)
   {  u=u/2;
      v++;                                      /* v为深度 */                                         
   } 
  }
 return v;                                      /* 返回v */
}
/* **************** 第1，2，3，4 ************************ */

struct bnode *R_Rotate(struct bnode *p)             /* 对以*p为根的二叉排序树作右旋处理 */
{ struct bnode *lc;
  lc=(struct bnode *)malloc(LENG1);
  lc=p->lchild;                                     /* lc指向p左子树根结点 */
  p->lchild=lc->rchild;                             /* lc的右子树挂接为P的左子树 */
  lc->rchild=p;
  p=lc;                                             /* p指向新的根结点 */
  return p;
}

struct bnode *L_Rotate(struct bnode *p)             /* 对以*p为根的二叉排序树作左旋处理 */
{ struct bnode *rc;
  rc=(struct bnode *)malloc(LENG1);
  rc=p->rchild;                                     /* lc指向p右子树根结点 */
  p->rchild=rc->lchild;                             /* lc的左子树挂接为P的右子树*/
  rc->lchild=p;
  p=rc;                                             /* p指向新的根结点 */
  return p; 
}

struct bnode *LeftBalance(struct bnode *T)                 /* 对以*T为根的二叉树作左平衡旋转处理 */
{ struct bnode *lc,*rd; 
  lc=(struct bnode *)malloc(LENG1);
  lc=T->lchild;
  switch(lc->bf)                                          /* 检查*T的左子树的平衡度，再作相应处理 */
  { case LH:(T->bf)=EH;(lc->bf)=EH;T=R_Rotate(T);break;  /* 新结点插入*T的左孩子的左子树上，做右旋处理 */
    case RH:                                               /* 新结点插入*T的左孩子的右子树上，做双旋处理 */
         rd=lc->rchild;
         switch(rd->bf)                                   /* 修改*T及其左小孩的平衡因子 */
         { case LH:(T->bf)=RH;(lc->bf)=EH; break;
           case EH:(T->bf)=EH;(lc->bf)=EH; break; 
           case RH:(T->bf)=EH;(lc->bf)=LH; break;
         }
        (rd->bf)=EH;
        T->lchild=L_Rotate(T->lchild);                     /* 对*T的左子树作左旋平衡处理 */
        T=R_Rotate(T);                                     /* 对*T作右旋处理 */
  }
 return T;
}

struct bnode *RightBalance(struct bnode *T)                /* 对以*T为根的二叉树作右平衡旋转处理 */
{ struct bnode *lc,*rd;
  lc=(struct bnode *)malloc(LENG1);
  rd=(struct bnode *)malloc(LENG1);
  rd=T->rchild;
  switch(rd->bf)                                          /* 检查*T的右子树的平衡度，再作相应处理 */
 {  case RH:(T->bf)=EH;(rd->bf)=EH;T=L_Rotate(T);break;  /* 新结点插入*T的右孩子的右子树上，做左旋处理 */
    case LH:                                               /* 新结点插入*T的右孩子的左子树上，做右旋处理 */
         lc=rd->lchild;
         switch(lc->bf)
         { case LH:(T->bf)=EH;(rd->bf)=RH; break;
           case EH:(T->bf)=EH;(rd->bf)=EH; break;         
           case RH:(T->bf)=LH;(rd->bf)=EH; break;
         }
         (lc->bf)=EH;
         T->rchild=R_Rotate(T->rchild);                    /* 对*T的右子树作右旋平衡处理 */
         T=L_Rotate(T);                                    /* 对*T作左旋处理 */
 }
 return T;
}

struct bnode *InsertAVL(struct bnode *T,int e,int *taller,int *G)   /* 生成平衡二叉排序树 */
{ if(!T)                                                            /* 插入新结点，树“长高”，taller置为1 */
    { T=(struct bnode *)malloc(LENG1);
      T->data=e;
      T->lchild=NULL;T->rchild=NULL;(T->bf)=EH;(*taller)=1;
    }
  else
   {  if(e==T->data)                                      /* 树中存在和e有相同关键字的结点 */
      { (*taller)=0;(*G)=0;return T;                      /* 则不插入 */
      }
     if(e<T->data)                                        /* 在左子树搜索 */
       { T->lchild=InsertAVL(T->lchild,e,taller,G);
        if(!(*G)) return T;                               /* 未插入 */
        if(*taller)
         { 
           switch(T->bf)                                 /* 检查*T的平衡度 */
           { case LH:T=LeftBalance(T);(*taller)=0;break;  /* 原来左子树比右子树高，作左平衡处理 */
             case EH:(T->bf)=LH;(*taller)=1;break;       /* 原来左，右子树等高，树增高 */
             case RH:(T->bf)=EH;(*taller)=0;break;       /* 原来右子树比左子树高，现左，右子树等高 */
           }
         }
      }
    else                                                  /* 在右子树搜索 */
     {T->rchild=InsertAVL(T->rchild,e,taller,G);
      if(!(*G)) return T;                                 /* 未插入 */
       if((*taller))
       switch(T->bf)                                     /* 检查*T的平衡度 */
       {  case LH:(T->bf)=EH;(*taller)=0;break;          /* 原来左子树比右子树高，现左，右子树等高 */
          case EH:(T->bf)=RH;(*taller)=1;break;          /* 原来左，右子树等高，树增高 */
          case RH:T=RightBalance(T);(*taller)=0;break;    /* 原来右子树比左子树高，作右平衡处理 */
       }
     }
  }
  (*G)=1;
  return T;
}
/* *******************  第5问  **************************** */


void main()
{ struct bnode *root,*t,*root_AVL;
  int flag=0,d,S[N],i=-1,j,*nu,*taller,B=0,C=0,D=0,E,*G;
  t=(struct bnode *)malloc(LENG1);
  G=&E;
  (*G)=0;
  nu=&B;                                             
  taller=&B;
  root=NULL;
  t=NULL;
  root_AVL=NULL;
 printf("input an array of int end of ENTER:");        /* 输入一列数 */
do
 { scanf("%d",&d);                                     /* 逐一读入数 */
  flag=0;
  if(i>0)                                        
  {for(j=0;j<=i;j++)                                   /* 判断结点是否相同，相同则不输入 */
    { if(d==S[j])
      {flag=1;break;} 
    }
  } 
    if(!flag)
    {i++;                                              /* i标记节点数 */
    S[i]=d;                                            /* 将结点存入数组 */  
    root=creat_tree(root,d);                           /* 生成一棵二叉排序树 */
   }
 }
while(getchar()!='\n');                                /* 结束标志 */
    printf("Inorder of the Binary Sort Tree:");
    inorder(root);                                     /* 中序遍历二叉树 */                          
    printf("\n");
    ASL(root,S,i);                                      /* 求二叉排序树的平均查找长度*/
    printf("Press any key to continue\n");

/* *************      第4问         ***************** */
 printf("Make sure whether the BSTree is a BBTree:");
 for(j=0;j<=i;j++)                                     /* 判断二叉排序树T是否为平衡二叉树 */                
 { t=root;
   { while(S[j]!=t->data)                              /* 找到各结点 */
      {  if(S[j]<t->data)                             
         t=t->lchild;
        else t=t->rchild;
      }
     B=0;
     preorder1(t->lchild,nu);                          /* 求出以t->lchild为根二叉树结点个数 */
     C=depth(t->lchild,nu);                            /* 求出以t->lchild为根二叉树深度 */                        
     B=0;
     preorder1(t->rchild,nu);                          /* 求出以t->rchild为根二叉树结点个数 */
     D=depth(t->rchild,nu);                            /* 求出以t->rchild为根二叉树深度 */ 
     if((C-D)>1||(C-D)<-1)                             /* 左，右子树深度相差大于1，则为非平衡二叉树，输出NO!*/
      { printf("NO!\n");
        break;
      }
   }
  if(j==i) printf("OK!\n");                            /* 否则为平衡二叉树，输出OK!*/                             
 }
 printf("Press any key to continue\n");  

/* **************     第4问        ****************** */


/* *********************第5,6问****************************** */
  B=0;
  for(j=0;j<=i;j++)                                    /* 生成平衡的二叉排序树 */   
  {root_AVL=InsertAVL(root_AVL,S[j],taller,G);      
  }
  printf("Preorder The Balanced Binary Tree:");
  preorder2(root_AVL);                                 /* 先序遍历二叉树 */ 
  printf("\nInorder The Balanced  Binary Tree:");        
  inorder(root_AVL);                                   /* 中序遍历二叉树 */ 
  printf("\n");
  ASL(root_AVL,S,i);                                   /* 求二叉排序树root_AVL的平均查找长度 */                                
  printf("Press any key to return\n");
}

/* *********************第5,6问****************************** */