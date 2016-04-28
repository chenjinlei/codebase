#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char

//ʵ�ֵ��������ʽ�洢�ṹ�����Ͷ���
typedef struct node			//������Ͷ���*/
{	DataType data;			//����������*/
	struct node *next;		//����ָ����
}ListNode;
typedef ListNode *LinkList;

//ɾ��������ֵ�ظ��Ľ���㷨ʵ�����£�
void Delete_LinkList(LinkList L)
{
	ListNode  *p,*q,*s;
	p=L->next;											//pָ���һ�����
	if(p==NULL)
		return;
	while (p->next&&p->next->next)
	{
		q=p;  
		while (q->next)										// ��*p�ĺ�̿�ʼ���ظ����
		{
			if (q->next->data==p->data)
			{
				s=q->next;								//�ҵ��ظ���㣬��rָ��ɾ��*r 
				q->next=s->next; 
				free(s);
			}
			else
				q=q->next;								//�����ƣ��ƶ���
		}
		if(p->next)
		p=p->next;										//pָ����һ��
	}
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
	}
	printf("ԭ������Ϊ��");
	L2=L;
	L2=L2->next;
	while(L2!=NULL)
	{
		printf("%c",L2->data);
		L2=L2->next;
	}
	Delete_LinkList(L);
	printf("\nɾ��������ֵ�ظ��Ľ�������Ϊ��");
	L=L->next;
	while(L!=NULL)
	{
		printf("%c",L->data);
		L=L->next;
	}
	printf("\n");
	return 0;
}