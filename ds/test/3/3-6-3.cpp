#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char

//ʵ�ֵ��������ʽ�洢�ṹ�����Ͷ���
typedef struct node			//������Ͷ���*/
{	DataType data;			//����������*/
	struct node *next;		//����ָ����
}ListNode;
typedef ListNode *LinkList;

//����������������һ��
LinkList Link( LinkList L1 , LinkList L2, int m,int n )
{
	ListNode *p , *q, *s ;										//sָ��̱�ͷ��㣬qָ�򳤱�ʼ���
	if (m<=n)
	{
		s=L1;
		q=L2->next;
		free(L2);
	}
	else
	{
		s=L2;
		q=L1->next;
		free(L1);
	}
	p=s;
	while( p->next ) 
		p=p->next;										//���Ҷ̱��ն˽��
	p->next = q;											//������ʼ��������ڶ̱��
	return s;
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
	}
	x=x+1;
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
	LinkList s=Link(L,L3,5,6);
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