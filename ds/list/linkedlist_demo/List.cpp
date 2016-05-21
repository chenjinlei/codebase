#include <stdio.h>
#include <stdlib.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//实现单链表的链式存储结构的类型定义
typedef struct node			//结点类型定义*/
{	DataType data;			//结点的数据域*/
	struct node *next;		//结点的指针域
}ListNode;
typedef ListNode *LinkList;


LinkList CreateListTou()//头插法创建单链表
{
	LinkList L;					//派生出对象
	DataType ch;					//定义临时变量
	ListNode *p;					//定义临时结点指针
	L=(LinkList)malloc(sizeof(ListNode));		//附加一个头结点
	L->next=NULL;					//带头结点
	getchar();
	printf("请输入要创建的单链表字符，如abcdefg.\n");
	ch=getchar();
	while(ch!='\n')
	{
		p=(LinkList)malloc(sizeof(ListNode));	//创建结点
		p->data=ch;				//给结点赋值
		p->next=L->next;			//把新结点链接上
		L->next=p;				//改变头指针
		ch=getchar();
	}
	printf("创建成功，按任意键继续！\n");
	getchar();
	return L;
}

LinkList CreateListWei()//尾插法创建单链表
{
	LinkList L;
	DataType ch;
	ListNode *p,*r;
	L=(LinkList)malloc(sizeof(ListNode));		//申请一空间
	L->next=NULL;					//头结点赋值
	r=L->next;					//尾指针指向头结点
	getchar();
	printf("请输入待创建表数据元素 ，如 abcdefg.\n");
	ch=getchar();
	while(ch!='\n')
	{
		p=(LinkList)malloc(sizeof(ListNode));	//申请新结点空间
		p->data=ch;				//给新结点赋值
		if(L->next==NULL)			//如果链表是空表
		{
			L->next=p;
		}
		else
		{
			r->next=p;
		}
		r=p;					//改变尾指针指向
		ch=getchar();
	}
	r->next=NULL;					//最后一个结点赋值为空
	printf("成功！.\n");
	getchar();
	return L;
}

bool InsertNode(LinkList &L,int i,DataType x)//单链表的前插操作
{
	int j;						//定义变量，当前位置
	LinkList p,s;					//定义链表指针
	p=L;
	j=0;
	while(p&&j<i-1)					//查找第i-1个结点
	{
		p=p->next;				//移到下一个结点
		++j;
	}
	if(!p||j>i-1)					//第i-1个不存在不能插入
	{
		getchar();
		printf("Insert error!Any key to contnue.\n");
		getchar();
		return false;
	}
	s=(LinkList)malloc(sizeof(ListNode));		//申请、填装结点
	s->data=x;
	s->next=p->next;				//新结点插入在第i-1个结点的后面
	p->next=s;
	getchar();
	printf("Success!Any key to contnue.\n");
	getchar();
	return true;
}

int Init_List(LinkList &L)//初始化单链表
{
	L=(ListNode*)malloc(sizeof(ListNode));		//申请结点空间
	if(L)
	{
		L->next=NULL;				//置为空表
		return 1;
	}
	else
		return 0;
}

int Clear_List(LinkList &L)//清空表
{
	while(L!=NULL)					//判断链表是否为空
	{
		LinkList p;
		p=L;
		L=L->next;
		free(p);				//释放结点存储空间
	}
	return 1;
}

int IsEmpty(LinkList L) //判断表是否为空
{
	if (L->next==NULL)				//判断链表是否为空
		return 1;
	else
		return 0;
}

int  Length_LinkList (LinkList L)//求表长
{
	ListNode  * p=L;				//p指向头结点
	int  k=0;					//定义变量k统计结点个数
	while (p->next)
	{
		p=p->next;				//指针后移
		k++;
	}						//p所指的是第k个结点
	return  k;
}

bool DeleteNode(LinkList &L,int i)//单链表的删除操作
{
	int j;
	LinkList p,s;
	p=L;
	j=0;
	while(p->next&&j<i-1)				//查找第i-1个结点
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1)
	{
		getchar();
		printf("Delete error!Any key to contnue.\n");
		getchar();
		return false;
	}
	s=p->next;
	p->next=s->next;				//从链表中删除
	free(s);					//释放s
	getchar();
	printf("Success!Any key to contnue.\n");
	getchar();
	return true;
}

ListNode* LocateElem(LinkList L,int i)//按照序号查找
{
	ListNode* p;
	p=L->next;
	int j=1;
	while(p&&j<i)					//查找第i个结点
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)					//没有找到满足条件的结点
		return NULL;
	return p;
}

ListNode *LocateElem(LinkList L,DataType e)//按照值查找
{
	ListNode* p;
	int j=1;
	p=L->next;
	while(p&&p->data!=e)				//判断待查找结点的值是否相等
	{
		p=p->next;
		j++;
	}
	if(p)						//查找成功
		printf("查找成功!是第 %d 个元素.\n",j);
	return p;
}

void showList(LinkList L)
{
	L=L->next;
	while(L!=NULL)
	{
		printf("%c",L->data);
		L=L->next;
	}
	printf("\n任意键返回");
	getchar();
}

int main()
{
	char c;
	int i;
	LinkList L,L1;
	Init_List(L);//初始化单链表
	char x;
	do
	{
		printf("                第3章：线性表的链式存储                  \n");
		printf("**********************************************************\n");
		printf("    1:  单链表创建操作\n");
		printf("    2:  单链表插入操作\n");
		printf("    3:  单链表清空操作\n");
		printf("    4:  单链表求表长\n");
		printf("    5:  单链表删除操作\n");
		printf("    6:  单链表查找操作\n");
		printf("    7:  显示表中数据\n");
		printf("    8:  退出\n");
		printf("\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		do
		{c=getchar();
		}while(c<'1'||c>'7');
		getchar();
		switch(c)
		{
		case'1':
			printf("    1:  头插法创建单链表操作\n");
			printf("    2:  尾插法创建单链表操作\n");
			printf("    任意键返回\n");
			c=getchar();
			switch(c)
			{
			case '1':L=CreateListTou();break;
			case '2':L=CreateListWei();break;
			default:c=' ';break;
			}
			break;
		case'2':
			if ( L->next==NULL )
			{
				printf("链表尚未创建，请先创建链表！\n");
				break;
			}
			printf("请输入插入的位置：");
			scanf("%d",&i);
			printf("请输入插入的字符：");
			getchar();
			x=getchar();
			InsertNode(L,i,x);
			break;
		case'3':
			Clear_List(L);
			break;
		case'4':
			if(L==NULL)
			{
				printf("表不存在，或者被清空！\n");
				break;
			}
			printf(" 表的长度为：%d\n",Length_LinkList(L));
			break;
		case'5':
			printf("请输入要删除的位置：");
			scanf("%d",&i);
			DeleteNode(L,i);
			break;
		case'6':
			printf("    1:  按序号查找\n");
			printf("    2:  按值查找\n");
			printf("    任意键返回\n");
			c=getchar();
			switch(c)
			{
			case '1':
				printf("请输入序号：");
				scanf("%d",&i);
				L1=LocateElem(L,i);
				if(L1!=NULL)
					printf("\n查找的值为:%c\n",L1->data);
				else
					printf("\n没有您要查找的值\n");
				break;
			case '2':
				printf("请输入值：");
				getchar();
				scanf("%c",&x);
				L1=LocateElem(L,x);
				break;
			default:c=' ';break;
			}
			break;
		case'7':
			if(L==NULL||L->next==NULL)
			{
				printf("表不存在，或者被清空！\n");
				break;
			}
			showList(L);
			break;
		case'8':
			break;
		}
	}while(c!='8');
	return 0;
}
