#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//实现单链表的链式存储结构的类型定义
typedef struct node			//结点类型定义*/
{	DataType data;			//结点的数据域*/
	struct node *next;		//结点的指针域
}ListNode;
typedef ListNode *LinkList;

//将两个链表连接在一起：
LinkList Link( LinkList L1 , LinkList L2, int m,int n )
{
	ListNode *p , *q, *s ;										//s指向短表头结点，q指向长表开始结点
	if (m<=n)
	{
		s=L1;
		q=L2->next;
		free(L2);
	}
	else
	{
		s=L2;
		q=L1->next;
		free(L1);
	}
	p=s;
	while( p->next ) 
		p=p->next;										//查找短表终端结点
	p->next = q;											//将长表开始结点链接在短表后
	return s;
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
	}
	x=x+1;
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
	LinkList s=Link(L,L3,5,6);
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