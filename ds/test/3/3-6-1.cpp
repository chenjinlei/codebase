#include <stdio.h>
#include <stdlib.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//实现单链表的链式存储结构的类型定义
typedef struct node			//结点类型定义*/
{	DataType data;			//结点的数据域*/
	struct node *next;		//结点的指针域
}ListNode;
typedef ListNode *LinkList;

//单链表逆置函数
LinkList ReverseList( LinkList  L )								//将L所指的单链表(带头结点)逆置
{

	ListNode *p ,*q ;										//设置两个临时指针变量
	if( L->next && L->next->next)								//当链表不是空表而且不是单结点时
	{
		p=L->next;
		q=p->next;
		p -> next=NULL;									//将开始结点变成终端结点
		while (q)											//每次循环将后一个结点变成开始结点
		{
			p=q;
			q=q->next ;
			p->next = L-> next ;
			L->next = p;
		}
		return   L;
	}
	return  L;												//如是空表或单结点表，直接返回L
} 


int main()
{
	LinkList L,L2;
	char x;
	x='a';
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
		x=x+1;
	}
	printf("原来链表为：");
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	ReverseList(L);
	printf("\n逆置后的链表为：");
	L=L->next;
	while(L!=NULL)
	{
		printf("%c",L->data);
		L=L->next;
	}
	printf("\n");
	return 0;
}
