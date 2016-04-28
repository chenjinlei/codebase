/*                 
1����һ������L������һ�ö���������T��
2�Զ���������T�������������������
3�������������T��ƽ�����ҳ���, ��������
4�ж϶���������T�Ƿ�Ϊƽ��������������Ϣ��OK����/��NO������
5��ʹ����������L������ƽ��Ķ���������BT��ÿ��������Ԫ�أ����ֵ�ǰ�Ķ���������BT����ƽ��Ķ���������������������ת�����µ�ƽ��Ķ���������BT��
6����ƽ��Ķ���������BT��ƽ�����ҳ��ȣ���������
6�����Ա�δƽ�⻯�Ķ�����������ƽ��Ķ����������Ĳ���Ч��(��á��ƽ���ȽϹؼ�����)
*/

#include<stdio.h>             
#include <stdlib.h>
struct bnode                                /* BnodeΪ���������(�ṹ)���� */
{int data;                                  /* dataΪ�������� */
 int bf;                                   /* �ڵ��ƽ������ */
 struct bnode *lchild,*rchild;              /* ��С������С��Ϊָ������  */
};
struct qnode                                /* qnodeΪ���н������ */
{struct bnode *data;                        /* dataΪ���������ָ�� */
 struct qnode *next;                        /* nextָ����һ���н�� */
};
struct linkqueue
{struct qnode *front;                       /* ��ͷ���ָ�� */
 struct qnode *rear;                        /* ��β���ָ�� */
};
#define N    50                             /* �����ʼ��С */
#define LENG1 sizeof(struct bnode)          /* �ڵ���ռ�ռ� */   
#define LENG2 sizeof(struct qnode)
#define LENG3 sizeof(struct linkqueue)

#define LH +1
#define EH 0
#define RH -1

struct bnode *creat_tree(struct bnode *t,int x)  /* ����һ�ö��������� */
{if(t==NULL)                                     /* ���ɿն��������� */
  { t=(struct bnode *)malloc(LENG1);             /* ����ռ� */
	t->data=x;
	t->lchild=t->rchild=NULL;                /* ����С����Ϊ�� */
 } 
 else
  { if(x<t->data)                                /* x���ڽ�� */
	  t->lchild=creat_tree(t->lchild,x);     /* ���������� */
   else
	  t->rchild=creat_tree(t->rchild,x);     /* ���������� */
  }
return t;                                        /* ���ظ��ڵ� */
}

struct bnode *inorder(struct bnode *root)        /* ������� */
{if(root)
 {root->lchild=inorder(root->lchild);            /* ������С�� */
 printf("%d  ",root->data);                       /* ��ӡ��� */
 root->rchild=inorder(root->rchild);             /* ������С��  */
 }
 return root;
}

struct bnode *preorder1(struct bnode *root,int *nu)  /* ������������� */
{
 if(root)                                            
 {
  (*nu)++;                                           /* ����ǿս����� */
 root->lchild=preorder1(root->lchild,nu);            /* ������С�� */    
  root->rchild=preorder1(root->rchild,nu);           /* ������С�� */
 }
 return root;
}

struct bnode *preorder2(struct bnode *root)          /* ������������� */
{
 if(root)
 {printf("%d  ",root->data);
  root->lchild=preorder2(root->lchild);              /* ������С�� */
  root->rchild=preorder2(root->rchild);              /* ������С�� */
 }
 return root;
}

struct linkqueue *enqueue(struct linkqueue *q,struct bnode *e)   /* �����в����� */
{struct qnode *p;
 p=(struct qnode *)malloc(LENG2);                   /* ��������ռ� */
 p->data=e;
 p->next=NULL;
 q->rear->next=p;
 q->rear=p;
 return q;
}



void compare(struct bnode *t,int x,int *Q)     
{if(t) 
  {
    if(x<t->data)                                    /* x���ڽ�� */
	{ (*Q)++;
           compare(t->lchild,x,Q);                   /* ���������� */
          return;  
        }  
   else
    { if(x>t->data)                                  /* xС�ڽ�� */
	 { (*Q)++;
           compare(t->rchild,x,Q);                   /* ���������� */
           return;
         }     
      else return;
    }
  }
 else return;
}

float ASL(struct bnode *root,int s[N],int i)      /* �����������T��ƽ�����ҳ��� */
{ int j,L=0,*Q,A;
  float  ASL=0;
  for(j=0;j<=i;j++)
 {A=1;
  Q=&A;                                         /* Q��ʼֵΪ1 */
  compare(root,s[j],Q);                         /* ��������ҳ��� */
  L+=(*Q);                                      /* LΪ���н����ҳ���֮�� */
 } 
  ASL=((float)L)/(i+1);                         /* ASLΪ����������T��ƽ�����ҳ��� */
  printf("ASL=%.2f\n",ASL);                     /* ��ӡASL */      
  return ASL;
}   

int depth(struct bnode *root,int *nu)           /* ����rootΪ�����Ķ����������*/
{int c=0,n=0,u,v=0; 
 struct bnode *no;                              /* ����ս��no */              
  struct qnode *s;                              /* ������s */
  struct linkqueue *q;                          /* ������q */
  if(root)
  { no=(struct bnode *)malloc(LENG1);           /* Ϊno����ռ� */      
    s=(struct qnode *)malloc(LENG2);            /* Ϊs����ռ� */
    q=(struct linkqueue *)malloc(LENG3);        /* Ϊq����ռ� */
    no->lchild=NULL;                            /* no��С��Ϊ�� */
     no->data=0;                                /* no->dataΪ�� */
     no->rchild=NULL;                           /* no��С��Ϊ�� */
    q->front=q->rear=(struct qnode *)malloc(LENG2);
    q->front->next=NULL;
    enqueue(q,root);                            /* ����enqueue���� */
    s=q->front->next;
  while(c<*nu)                                  /* *nu��������������� */                                 
   { n++;                                       /* nΪ���н����� */
     if(s->data->data!=0)  c++; 
     if(s->data->lchild)
     enqueue(q,s->data->lchild);                /* ��С��������� */                               
     else enqueue(q,no);                        /* �ս�������� */
     if(s->data->rchild)
     enqueue(q,s->data->rchild);                /* ��С��������� */
     else enqueue(q,no);                        /* �ս�������� */
     s=s->next;
   }
   u=n;
   while(u)
   {  u=u/2;
      v++;                                      /* vΪ��� */                                         
   } 
  }
 return v;                                      /* ����v */
}
/* **************** ��1��2��3��4 ************************ */

struct bnode *R_Rotate(struct bnode *p)             /* ����*pΪ���Ķ������������������� */
{ struct bnode *lc;
  lc=(struct bnode *)malloc(LENG1);
  lc=p->lchild;                                     /* lcָ��p����������� */
  p->lchild=lc->rchild;                             /* lc���������ҽ�ΪP�������� */
  lc->rchild=p;
  p=lc;                                             /* pָ���µĸ���� */
  return p;
}

struct bnode *L_Rotate(struct bnode *p)             /* ����*pΪ���Ķ������������������� */
{ struct bnode *rc;
  rc=(struct bnode *)malloc(LENG1);
  rc=p->rchild;                                     /* lcָ��p����������� */
  p->rchild=rc->lchild;                             /* lc���������ҽ�ΪP��������*/
  rc->lchild=p;
  p=rc;                                             /* pָ���µĸ���� */
  return p; 
}

struct bnode *LeftBalance(struct bnode *T)                 /* ����*TΪ���Ķ���������ƽ����ת���� */
{ struct bnode *lc,*rd; 
  lc=(struct bnode *)malloc(LENG1);
  lc=T->lchild;
  switch(lc->bf)                                          /* ���*T����������ƽ��ȣ�������Ӧ���� */
  { case LH:(T->bf)=EH;(lc->bf)=EH;T=R_Rotate(T);break;  /* �½�����*T�����ӵ��������ϣ����������� */
    case RH:                                               /* �½�����*T�����ӵ��������ϣ���˫������ */
         rd=lc->rchild;
         switch(rd->bf)                                   /* �޸�*T������С����ƽ������ */
         { case LH:(T->bf)=RH;(lc->bf)=EH; break;
           case EH:(T->bf)=EH;(lc->bf)=EH; break; 
           case RH:(T->bf)=EH;(lc->bf)=LH; break;
         }
        (rd->bf)=EH;
        T->lchild=L_Rotate(T->lchild);                     /* ��*T��������������ƽ�⴦�� */
        T=R_Rotate(T);                                     /* ��*T���������� */
  }
 return T;
}

struct bnode *RightBalance(struct bnode *T)                /* ����*TΪ���Ķ���������ƽ����ת���� */
{ struct bnode *lc,*rd;
  lc=(struct bnode *)malloc(LENG1);
  rd=(struct bnode *)malloc(LENG1);
  rd=T->rchild;
  switch(rd->bf)                                          /* ���*T����������ƽ��ȣ�������Ӧ���� */
 {  case RH:(T->bf)=EH;(rd->bf)=EH;T=L_Rotate(T);break;  /* �½�����*T���Һ��ӵ��������ϣ����������� */
    case LH:                                               /* �½�����*T���Һ��ӵ��������ϣ����������� */
         lc=rd->lchild;
         switch(lc->bf)
         { case LH:(T->bf)=EH;(rd->bf)=RH; break;
           case EH:(T->bf)=EH;(rd->bf)=EH; break;         
           case RH:(T->bf)=LH;(rd->bf)=EH; break;
         }
         (lc->bf)=EH;
         T->rchild=R_Rotate(T->rchild);                    /* ��*T��������������ƽ�⴦�� */
         T=L_Rotate(T);                                    /* ��*T���������� */
 }
 return T;
}

struct bnode *InsertAVL(struct bnode *T,int e,int *taller,int *G)   /* ����ƽ����������� */
{ if(!T)                                                            /* �����½�㣬�������ߡ���taller��Ϊ1 */
    { T=(struct bnode *)malloc(LENG1);
      T->data=e;
      T->lchild=NULL;T->rchild=NULL;(T->bf)=EH;(*taller)=1;
    }
  else
   {  if(e==T->data)                                      /* ���д��ں�e����ͬ�ؼ��ֵĽ�� */
      { (*taller)=0;(*G)=0;return T;                      /* �򲻲��� */
      }
     if(e<T->data)                                        /* ������������ */
       { T->lchild=InsertAVL(T->lchild,e,taller,G);
        if(!(*G)) return T;                               /* δ���� */
        if(*taller)
         { 
           switch(T->bf)                                 /* ���*T��ƽ��� */
           { case LH:T=LeftBalance(T);(*taller)=0;break;  /* ԭ�����������������ߣ�����ƽ�⴦�� */
             case EH:(T->bf)=LH;(*taller)=1;break;       /* ԭ�����������ȸߣ������� */
             case RH:(T->bf)=EH;(*taller)=0;break;       /* ԭ�����������������ߣ������������ȸ� */
           }
         }
      }
    else                                                  /* ������������ */
     {T->rchild=InsertAVL(T->rchild,e,taller,G);
      if(!(*G)) return T;                                 /* δ���� */
       if((*taller))
       switch(T->bf)                                     /* ���*T��ƽ��� */
       {  case LH:(T->bf)=EH;(*taller)=0;break;          /* ԭ�����������������ߣ������������ȸ� */
          case EH:(T->bf)=RH;(*taller)=1;break;          /* ԭ�����������ȸߣ������� */
          case RH:T=RightBalance(T);(*taller)=0;break;    /* ԭ�����������������ߣ�����ƽ�⴦�� */
       }
     }
  }
  (*G)=1;
  return T;
}
/* *******************  ��5��  **************************** */


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
 printf("input an array of int end of ENTER:");        /* ����һ���� */
do
 { scanf("%d",&d);                                     /* ��һ������ */
  flag=0;
  if(i>0)                                        
  {for(j=0;j<=i;j++)                                   /* �жϽ���Ƿ���ͬ����ͬ������ */
    { if(d==S[j])
      {flag=1;break;} 
    }
  } 
    if(!flag)
    {i++;                                              /* i��ǽڵ��� */
    S[i]=d;                                            /* ������������ */  
    root=creat_tree(root,d);                           /* ����һ�ö��������� */
   }
 }
while(getchar()!='\n');                                /* ������־ */
    printf("Inorder of the Binary Sort Tree:");
    inorder(root);                                     /* ������������� */                          
    printf("\n");
    ASL(root,S,i);                                      /* �������������ƽ�����ҳ���*/
    printf("Press any key to continue\n");

/* *************      ��4��         ***************** */
 printf("Make sure whether the BSTree is a BBTree:");
 for(j=0;j<=i;j++)                                     /* �ж϶���������T�Ƿ�Ϊƽ������� */                
 { t=root;
   { while(S[j]!=t->data)                              /* �ҵ������ */
      {  if(S[j]<t->data)                             
         t=t->lchild;
        else t=t->rchild;
      }
     B=0;
     preorder1(t->lchild,nu);                          /* �����t->lchildΪ�������������� */
     C=depth(t->lchild,nu);                            /* �����t->lchildΪ����������� */                        
     B=0;
     preorder1(t->rchild,nu);                          /* �����t->rchildΪ�������������� */
     D=depth(t->rchild,nu);                            /* �����t->rchildΪ����������� */ 
     if((C-D)>1||(C-D)<-1)                             /* �����������������1����Ϊ��ƽ������������NO!*/
      { printf("NO!\n");
        break;
      }
   }
  if(j==i) printf("OK!\n");                            /* ����Ϊƽ������������OK!*/                             
 }
 printf("Press any key to continue\n");  

/* **************     ��4��        ****************** */


/* *********************��5,6��****************************** */
  B=0;
  for(j=0;j<=i;j++)                                    /* ����ƽ��Ķ��������� */   
  {root_AVL=InsertAVL(root_AVL,S[j],taller,G);      
  }
  printf("Preorder The Balanced Binary Tree:");
  preorder2(root_AVL);                                 /* ������������� */ 
  printf("\nInorder The Balanced  Binary Tree:");        
  inorder(root_AVL);                                   /* ������������� */ 
  printf("\n");
  ASL(root_AVL,S,i);                                   /* �����������root_AVL��ƽ�����ҳ��� */                                
  printf("Press any key to return\n");
}

/* *********************��5,6��****************************** */