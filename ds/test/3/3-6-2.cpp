#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//实现单链表的链式存储结构的类型定义
typedef struct node			//结点类型定义*/
{	DataType data;			//结点的数据域*/
	struct node *next;		//结点的指针域
}ListNode;
typedef ListNode *LinkList;

//删除单链表值重复的结点算法实现如下：
void Delete_LinkList(LinkList L)
{
	ListNode  *p,*q,*s;
	p=L->next;											//p指向第一个结点
	if(p==NULL)
		return;
	while (p->next&&p->next->next)
	{
		q=p;  
		while (q->next)										// 从*p的后继开始找重复结点
		{
			if (q->next->data==p->data)
			{
				s=q->next;								//找到重复结点，用r指向，删除*r 
				q->next=s->next; 
				free(s);
			}
			else
				q=q->next;								//结点后移，移动快
		}
		if(p->next)
		p=p->next;										//p指向下一个
	}
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
	}
	printf("原来链表为：");
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	Delete_LinkList(L);
	printf("\n删除单链表值重复的结点的链表为：");
	L=L->next;
	while(L!=NULL)
	{
		printf("%c",L->data);
		L=L->next;
	}
	printf("\n");
	return 0;
}