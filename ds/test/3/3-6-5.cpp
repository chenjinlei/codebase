#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char

//ʵ�ֵ��������ʽ�洢�ṹ�����Ͷ���
typedef struct node			//������Ͷ���*/
{	DataType data;			//����������*/
	struct node *next;		//����ָ����
}ListNode;
typedef ListNode *LinkList;

void DeleteList ( LinkList L, DataType min , DataType max )
{
	ListNode *p , *q , *s;
	p=L;
	while( p->next && p->next->data <=min )
		p=p->next; 
	q=p->next;												//qָ���һ������min�Ľ��
	while(q&&q->data<max)
	{
		s=q;q=q->next;
		free(s);													//ɾ����㣬�ͷſռ�
	}
	p->next=q;												//��*p����ֱ�Ӻ��ָ��ָ��*q���
}

int main()
{
	LinkList L,L2;//L1,L3ΪҪ���ӵ�������
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

	printf("����LΪ��");
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	printf("\ɾ��b��d֮�����Ϊ��");
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
