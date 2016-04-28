#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//实现单链表的链式存储结构的类型定义
typedef struct node			//结点类型定义*/
{	DataType data;			//结点的数据域*/
	struct node *next;		//结点的指针域
}ListNode;
typedef ListNode *LinkList;

LinkList  Merge_LinkList(LinkList A,LinkList B)						//设A、B均为带头结点的单链表
{
	LinkList C;
	ListNode  *p,*q,*s;
    	p=A->next;
	q=B->next;
    	C=A;													//C表的头结点
	C->next=NULL;
	free(B);
	while (p&&q)
	{
		if (p->data<q->data)
		{
			s=p;
			p=p->next;
		}
		else 
		{
			s=q;
			q=q->next;
		}												//从原AB表上摘下较小者
		s->next=C->next;									//插入到C表的头部
		C->next=s;
	}
	if (p==NULL)
		p=q;
	while (p)												//将剩余的结点个摘下，插入到C表头部
	{
		s=p;
		p=p->next;
		s->next=C->next;
		C->next=s;
	}
	return C;
}


int main()
{
	LinkList L,L2,L3;//L1,L3为要连接的两个表
	char x;
	x='a';
	//创建L1
	L=(LinkList)malloc(sizeof(ListNode));//单链表的头结点
	L->next=NULL;
	L2=L;
	for(int i=0;i<5;i++)
	{
		LinkList L1;
		L1=(LinkList)malloc(sizeof(ListNode));
		L1->data=x;
		L1->next=L2->next;
		L2->next=L1;
		L2=L1;
		x++;
	}
	x=x-2;
	//创建L3
	L3=(LinkList)malloc(sizeof(ListNode));//单链表的头结点
	L3->next=NULL;
	L2=L3;
	for(i=0;i<6;i++)
	{
		LinkList L1;
		L1=(LinkList)malloc(sizeof(ListNode));
		L1->data=x;
		L1->next=L2->next;
		L2->next=L1;
		L2=L1;
		x++;
	}
	printf("链表L为：");
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	printf("\n链表L3为：");
	L2=L3;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	LinkList s=Merge_LinkList(L,L3);
	printf("\n连接后的表为：");
	L2=s;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	printf("\n");
	return 0;
}