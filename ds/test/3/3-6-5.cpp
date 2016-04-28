#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//实现单链表的链式存储结构的类型定义
typedef struct node			//结点类型定义*/
{	DataType data;			//结点的数据域*/
	struct node *next;		//结点的指针域
}ListNode;
typedef ListNode *LinkList;

void DeleteList ( LinkList L, DataType min , DataType max )
{
	ListNode *p , *q , *s;
	p=L;
	while( p->next && p->next->data <=min )
		p=p->next; 
	q=p->next;												//q指向第一个大于min的结点
	while(q&&q->data<max)
	{
		s=q;q=q->next;
		free(s);													//删除结点，释放空间
	}
	p->next=q;												//将*p结点的直接后继指针指向*q结点
}

int main()
{
	LinkList L,L2;//L1,L3为要连接的两个表
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

	printf("链表L为：");
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	printf("\删除b和d之间的数为：");
	DeleteList(L,'b','d');
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	printf("\n");
	return 0;
}
