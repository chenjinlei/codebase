#include <stdio.h>
#include <malloc.h>

typedef  struct  Polyn										//��ı�ʾ
{
	int   coef;												//ϵ��
	int   expn;											//ָ��
	struct  Polyn  *next;
}  Polyn;
Polyn   *pf,  *pg;											//��������ͷ���

//����ʽ�����㷨
Polyn  *CreatPolyn(int n)
{
	Polyn *L, *p,*q;
	int  i, s;
	L=new Polyn;											//�Ƚ���һ����ͷ���ĵ�����
	L->next=NULL; 
	L->coef=0;
	L->expn=-1;
	q=L;													//����ָ��
	for(i=n; i>0; i--)
	{  
		p=new Polyn;										//�����½��
		scanf("%d,%d",&p->coef,&p->expn);
		p->next=q->next;										//���뵽��β
		q->next=p;
		q=p;												//����ָ��ָ���β���
	}
	return(L);												//����ͷָ��
}

//����ʽ��ӵ��㷨
void  AddPolyn(Polyn *pf, Polyn *pg)
{   
	Polyn  *p, *q, *pre, *u; 									//����ָ��
	int   sum;
	p=pf->next;											//���浱ǰ������ʼ���ָ��
	q=pg->next;
	pre=pf;
	while(p&&q)											//����������
	{
		if(p->expn<q->expn) 								//�ж�������ʽָ����С
		{
			pre=p;
			p=p->next;
		}
		else if (p->expn==q->expn) 							//�ж�������ʽָ���Ƿ����
		{
			sum=p->coef+q->coef; 							//������ʽϵ�����
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
	if(q)													//qָ��δ��g����ĩβ
		pre->next=q;										//�������ӵ�f�������
	delete pg;
} 

int main()
{
	Polyn *pf,*pg;
	printf("�����һ������ʽ�����ϵ����ָ����1,2");
	pf=CreatPolyn(3);
	printf("�����һ������ʽ�����ϵ����ָ����1,2");
	pg=CreatPolyn(3);
	AddPolyn(pf,pg);


	return 0;
}
