#include<stdio.h>
#include<malloc.h>
typedef struct binode
{
 char data;
 struct binode *lchild,*rchild;
}binode,*bitree;                        //定义树结点结构
typedef struct queuenode
{
 bitree ch;
 struct queuenode *next;
}queuenode,*queueptr;                   //定义队列结点结构
typedef struct
{
 queueptr front;
 queueptr rear;
}linkqueue;                             //定义队列指针

//建树
int createbitree(bitree &T,int &sum)
{
 char ch;
 scanf("%c",&ch);
 if(ch=='#')
  T=NULL;
 else
 {
  if(!(T=(bitree)malloc(sizeof(binode))))
   return 0;
  T->data=ch;
  sum++;
  createbitree(T->lchild,sum);
  createbitree(T->rchild,sum);
 }
 return 1;
}

//初始化一个带头结点的队列
void initqueue(linkqueue &q)
{
 q.front=q.rear=(queueptr)malloc(sizeof(queuenode));
 q.front->next=NULL;
}

//入队列
void enqueue(linkqueue &q,bitree p)
{
 queueptr s;
 int first=1;
 s=(queueptr)malloc(sizeof(queuenode));
 s->ch=p;
 s->next=NULL;
 q.rear->next=s;
 q.rear=s;
}

//出队列
void dequeue(linkqueue &q,bitree &p)
{
 char data;
 queueptr s;
 s=q.front->next;
 p=s->ch;
    data=p->data;
 q.front->next=s->next;
 if(q.rear==s)
  q.rear=q.front;
 free(s);
 printf("%c ",data);
}

//判断队列是否为空
int queueempty(linkqueue q)
{
 if(q.front->next==NULL)
  return 1;
 return 0;
}

//按层次遍历树中结点
void traverse(bitree bt)
{
 linkqueue q;
 bitree p;
 initqueue(q);
 p=bt;
 enqueue(q,p);
 while(queueempty(q)!=1)
 {
  dequeue(q,p);
   if(p->lchild!=NULL)
   enqueue(q,p->lchild);
  if(p->rchild!=NULL)
   enqueue(q,p->rchild);
 }
 printf("\n");
}

//主函数
void main()
{
 int n=0;
 bitree bt;
 createbitree(bt,n);
 printf("该二叉树共有%d个结点.\n",n);
 printf("按层次遍历树中结点其输出顺序为: \n");
 traverse(bt);
}
