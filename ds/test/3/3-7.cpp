#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType可以是任何相应的数据类型如int, float或char

//约瑟夫问题链式存储结构的类型定义
typedef struct LNode  /*定义链表的存储结构*/                                
{
	int num;													//编号
	int password;												//所持密码
	struct LNode *next;											//指针域
}LNode,*Linklist;
Linklist L, pt,p ;												//定义头指针、当前指针及其前一指针


//首先创建一个不带头结点的单链表进而构造成循环链表，存储每个人的编号。
int CreatLinkList(int n)
{
	int i;
	L=(Linklist)malloc(sizeof(LNode));							/*带头结点的链表*/
	if(!L)
		return 0;
	p=L;
	for(i=1;i<n;i++)
	{
		pt=(Linklist)malloc(sizeof(LNode));							/*生成新结点*/
		if(!pt)
			return 0;
		p->next=pt;
		p=pt;
	}
	p->next=L;												/*重新指向头结点，构成循环链表*/
	pt=L;
	return 0;
}

//把密码的输入单独封装为函数，实现密码输入的算法如下：
int EnterPwd(int n)
{
	int i,j;
	printf("\nplease enter the password:(example:4 7 11)\n");
	for( i=1;i<=n;i++)
	{
		scanf("%d",&j); 										/*输入密码*/
		pt->num=i;
		pt->password=j; 										/*密码赋值*/
		pt=pt->next; 										/*指针下移*/
	}
	pt=p; /*改变当前指针*/
	return 0;
}

//实现从编号为i的人开始报数，报m的人出列，直到所有人出列，输出出列顺序，实现的算法如下：
int OutList(int m,int n)
{
	int i,a;
	for(i=1;i<=n;i++)
	{
		for(a=1;a<m;a++)										/*遍历整个链表*/
			pt=pt->next;
		p=pt->next;
		m=p->password;
		printf("%d ",p->num);
		pt->next=p->next;										/*删除链表*/
		free(p);												/*释放动态分配的结点指针*/
	}
	return 0;
}

int main()
{
	int n,m;
	printf("输入人数：");
	scanf("%d",&n);
	printf("输入报的数：");
	scanf("%d",&m);
	CreatLinkList(n);
	EnterPwd(n);
	OutList(m,n);
	return 0;
}
