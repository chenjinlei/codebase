#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//实现单链表的链式存储结构的类型定义
typedef struct node			//结点类型定义*/
{	DataType data;			//结点的数据域*/
	struct node *next;		//结点的指针域
}ListNode;
typedef ListNode *LinkList;

LinkList Connect(LinkList A,LinkList B)					//假设A，B为非空循环链表的尾指针
{
	LinkList p=A->next;										//保存A表的头结点位置
	A->next=B->next->next;									//B表的开始结点链接到A表尾
	free(B->next);											//释放B表的头结点
	B->next=p;											//对应第四步操作
	return B;												//返回新循环链表的尾指针
}

int main()
{
	LinkList L,L2,L3;//L1,L3为要连接的两个表
	char x;
	x='a';
	//创建L1
	L=(LinkList)malloc(sizeof(ListNode));//循环链表的头结点
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
	L2->next=L->next;
	L->next=L2;

	//创建L3
	L3=(LinkList)malloc(sizeof(ListNode));//循环链表的头结点
	L3->next=NULL;
	L2=L3;
	for(i=0;i<5;i++)
	{
		LinkList L1;
		L1=(LinkList)malloc(sizeof(ListNode));
		L1->data=x;
		L1->next=L2->next;
		L2->next=L1;
		L2=L1;
		x++;
	}
	L2->next=L3->next;
	L3->next=L2;
	LinkList L21=Connect(L,L3);
	if(L21!=NULL)
		printf("循环链表连接成功！\n");

	return 0;
}
