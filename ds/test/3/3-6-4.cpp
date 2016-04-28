#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char

//ʵ�ֵ��������ʽ�洢�ṹ�����Ͷ���
typedef struct node			//������Ͷ���*/
{	DataType data;			//����������*/
	struct node *next;		//����ָ����
}ListNode;
typedef ListNode *LinkList;

LinkList  Merge_LinkList(LinkList A,LinkList B)						//��A��B��Ϊ��ͷ���ĵ�����
{
	LinkList C;
	ListNode  *p,*q,*s;
    	p=A->next;
	q=B->next;
    	C=A;													//C���ͷ���
	C->next=NULL;
	free(B);
	while (p&&q)
	{
		if (p->data<q->data)
		{
			s=p;
			p=p->next;
		}
		else 
		{
			s=q;
			q=q->next;
		}												//��ԭAB����ժ�½�С��
		s->next=C->next;									//���뵽C���ͷ��
		C->next=s;
	}
	if (p==NULL)
		p=q;
	while (p)												//��ʣ��Ľ���ժ�£����뵽C��ͷ��
	{
		s=p;
		p=p->next;
		s->next=C->next;
		C->next=s;
	}
	return C;
}


int main()
{
	LinkList L,L2,L3;//L1,L3ΪҪ���ӵ�������
	char x;
	x='a';
	//����L1
	L=(LinkList)malloc(sizeof(ListNode));//�������ͷ���
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
	x=x-2;
	//����L3
	L3=(LinkList)malloc(sizeof(ListNode));//�������ͷ���
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
		x++;
	}
	printf("����LΪ��");
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	printf("\n����L3Ϊ��");
	L2=L3;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	LinkList s=Merge_LinkList(L,L3);
	printf("\n���Ӻ�ı�Ϊ��");
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