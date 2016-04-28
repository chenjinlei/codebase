#include <stdio.h>
#include <stdlib.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//实现双向链表的链式存储结构的类型定义
typedef char DataType;
typedef struct dlistnode
{
	DataType data;				 //结点的数据域*/
	struct dlistnode *prior,*next;		 //结点的指针域
}DListNode;
typedef DListNode *DLinkList;



int  ListInsert_Dul(DLinkList &L, int i, DataType x)					//在双向链表中第i个位置前插入元素x
{
	int j=0;
	DLinkList p,s;
	p=L->next;
	while (p!=NULL&&j<i) 									//查找第i个结点
	{ 
		p=p->next;
		j++; 
	}
	if(j!=i||i<1) 												//没有找到第i个结点
	{ 
		printf("错误，没有找到r!");    
		return 0;
	}
	if(!(s=(DLinkList)malloc(sizeof(DListNode))))					//申请一个新的结点
		return 0;
	s->data=x;
	s->prior=p->prior;										
	p->prior->next=s;										
	s->next=p;											
	p->prior=s;											
	return 1;
}

int ListInsert_Dul(DLinkList &L, int i)//双向链表的删除操作
{
	int j=0; 
	DLinkList p,s;
	p=L->next;
	while (p!=NULL&&j<i) 									//查找第i个结点
	{
		p=p->next;   
		j++; 
	}
	if(j!=i||i<1) 											//没有找到第i个结点
	{ 
		printf("没有找到!");
		return 0;
	}
	s=p;
	p->prior->next=p->next ;									
	p->next->prior=p->prior ;									
	free(s); 												//释放结点存储空间
	return 1;
}


int main()
{
	char c;
	int i;
	//给链表一个初始节点，方便下面调用
	DLinkList L,L1,L2;
	L=(DLinkList)malloc(sizeof(DListNode));
	L->next=NULL;
	L->prior=NULL;
	L1=(DLinkList)malloc(sizeof(DListNode));
	L1->data='1';
	L1->prior=L;
	L1->next=NULL;
	L->next=L1;
	L2=(DLinkList)malloc(sizeof(DListNode));
	L2->data='2';
	L2->prior=L1;
	L2->next=NULL;
	L1->next=L2;

	char x;
	do
	{
		printf("\n                3.4：双向链表的基本操作                  \n");
		printf("**********************************************************\n");
		printf("    1:  插入操作\n");
		printf("    2:  删除操作\n");
		printf("    3:  退出\n");
		printf("\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		do
		{c=getchar();
		}while(c<'1'||c>'3');
		getchar();
		switch(c)
		{
		case'1':
			printf("请输入要插入的位置：");
			scanf("%d",&i);
			printf("请输入要插入的值：");
			getchar();
			scanf("%c",&x);
			ListInsert_Dul(L,i,x);
			break;
		case'2':			
			printf("请输入要删除的位置：");
			scanf("%d",&i);
			if(ListInsert_Dul(L,i))
				printf("删除成功！");
			break;
		case'3':
			break;
		}
	}while(c!='3');
	return 0;
}
