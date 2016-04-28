#include<stdio.h>
#include<malloc.h>
typedef struct binode
{
 char data;
 struct binode *lchild,*rchild;
}binode,*bitree;                        //���������ṹ
typedef struct queuenode
{
 bitree ch;
 struct queuenode *next;
}queuenode,*queueptr;                   //������н��ṹ
typedef struct
{
 queueptr front;
 queueptr rear;
}linkqueue;                             //�������ָ��

//����
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

//��ʼ��һ����ͷ���Ķ���
void initqueue(linkqueue &q)
{
 q.front=q.rear=(queueptr)malloc(sizeof(queuenode));
 q.front->next=NULL;
}

//�����
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

//������
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

//�ж϶����Ƿ�Ϊ��
int queueempty(linkqueue q)
{
 if(q.front->next==NULL)
  return 1;
 return 0;
}

//����α������н��
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

//������
void main()
{
 int n=0;
 bitree bt;
 createbitree(bt,n);
 printf("�ö���������%d�����.\n",n);
 printf("����α������н�������˳��Ϊ: \n");
 traverse(bt);
}
