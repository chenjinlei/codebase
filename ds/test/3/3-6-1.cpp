#include <stdio.h>
#include <stdlib.h>

typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char

//ʵ�ֵ��������ʽ�洢�ṹ�����Ͷ���
typedef struct node			//������Ͷ���*/
{	DataType data;			//����������*/
	struct node *next;		//����ָ����
}ListNode;
typedef ListNode *LinkList;

//���������ú���
LinkList ReverseList( LinkList  L )								//��L��ָ�ĵ�����(��ͷ���)����
{

	ListNode *p ,*q ;										//����������ʱָ�����
	if( L->next && L->next->next)								//�������ǿձ���Ҳ��ǵ����ʱ
	{
		p=L->next;
		q=p->next;
		p -> next=NULL;									//����ʼ������ն˽��
		while (q)											//ÿ��ѭ������һ������ɿ�ʼ���
		{
			p=q;
			q=q->next ;
			p->next = L-> next ;
			L->next = p;
		}
		return   L;
	}
	return  L;												//���ǿձ�򵥽���ֱ�ӷ���L
} 


int main()
{
	LinkList L,L2;
	char x;
	x='a';
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
		x=x+1;
	}
	printf("ԭ������Ϊ��");
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	ReverseList(L);
	printf("\n���ú������Ϊ��");
	L=L->next;
	while(L!=NULL)
	{
		printf("%c",L->data);
		L=L->next;
	}
	printf("\n");
	return 0;
}
