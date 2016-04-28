#include <stdio.h>
#include <malloc.h>

typedef  struct  Polyn										//项的表示
{
	int   coef;												//系数
	int   expn;											//指数
	struct  Polyn  *next;
}  Polyn;
Polyn   *pf,  *pg;											//定义两个头结点

//多项式生成算法
Polyn  *CreatPolyn(int n)
{
	Polyn *L, *p,*q;
	int  i, s;
	L=new Polyn;											//先建立一个带头结点的单链表
	L->next=NULL; 
	L->coef=0;
	L->expn=-1;
	q=L;													//工作指针
	for(i=n; i>0; i--)
	{  
		p=new Polyn;										//生成新结点
		scanf("%d,%d",&p->coef,&p->expn);
		p->next=q->next;										//插入到表尾
		q->next=p;
		q=p;												//工作指针指向表尾结点
	}
	return(L);												//返回头指针
}

//多项式相加的算法
void  AddPolyn(Polyn *pf, Polyn *pg)
{   
	Polyn  *p, *q, *pre, *u; 									//定义指针
	int   sum;
	p=pf->next;											//保存当前两链表开始结点指针
	q=pg->next;
	pre=pf;
	while(p&&q)											//遍历两链表
	{
		if(p->expn<q->expn) 								//判断两多项式指数大小
		{
			pre=p;
			p=p->next;
		}
		else if (p->expn==q->expn) 							//判断两多项式指数是否相等
		{
			sum=p->coef+q->coef; 							//两多项式系数相加
			if(sum!=0)
			{ 
				p->coef=sum;
				pre=p;
			}
			else
			{
				pre->next=p->next;
				delete p;
			}
			p=pre->next;
			u=q;
			q=q->next;
			delete  u;
		}
		else 
		{
			u=q->next;
			q->next=p;
			pre->next=q;
			pre=q;
			q=u;
		}
	}
	if(q)													//q指针未到g链表末尾
		pre->next=q;										//将其链接到f链表后面
	delete pg;
} 

int main()
{
	Polyn *pf,*pg;
	printf("输入第一个多项式三项的系数和指数如1,2");
	pf=CreatPolyn(3);
	printf("输入第一个多项式三项的系数和指数如1,2");
	pg=CreatPolyn(3);
	AddPolyn(pf,pg);


	return 0;
}
