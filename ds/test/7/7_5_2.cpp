#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
///���ڵ�ṹ
typedef struct node{
  char data;
  struct node *lchild,*rchild;
}bt;
//����
typedef struct q{
  bt *data[maxsize];
  int front,rear;
}queue;

///���������
void createbt(bt **T)
{
	char ch;
    scanf("%c",&ch);
   if(ch=='#')*T=NULL;
   else{
	   *T=(bt *)malloc(sizeof(bt));
       (*T)->data=ch;
       createbt(&((*T)->lchild));
       createbt(&((*T)->rchild));
   }
 }

//�������
void leveltrav(bt *t)
{
    queue qu; 
	bt *temp;
	int i;
    qu.front=0;
    qu.rear=0;
    qu.rear++;
    if(!t)return;
    qu.data[qu.rear]=t;
    while(qu.front!=qu.rear){
        qu.front=(qu.front+1)%maxsize;
        temp=qu.data[qu.front];
        printf("%c ",temp->data);
        if(temp->lchild){
             qu.rear=(qu.rear+1)%maxsize;
             qu.data[qu.rear]=temp->lchild;
		}
        if(temp->rchild){
             qu.rear=(qu.rear+1)%maxsize;
             qu.data[qu.rear]=temp->rchild;
		}  
	} 
    for(i=qu.front;i<qu.rear;i++)
	   printf("%c ",qu.data[i]);
}
////////����
void main()
{
    bt *h;

    createbt(&h);
 
	leveltrav(h);
}