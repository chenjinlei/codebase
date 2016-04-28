#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char

//ʵ�ֵ��������ʽ�洢�ṹ�����Ͷ���
typedef struct node			//������Ͷ���*/
{	DataType data;			//����������*/
	struct node *next;		//����ָ����
}ListNode;
typedef ListNode *LinkList;

LinkList Connect(LinkList A,LinkList B)					//����A��BΪ�ǿ�ѭ�������βָ��
{
	LinkList p=A->next;										//����A���ͷ���λ��
	A->next=B->next->next;									//B��Ŀ�ʼ������ӵ�A��β
	free(B->next);											//�ͷ�B���ͷ���
	B->next=p;											//��Ӧ���Ĳ�����
	return B;												//������ѭ�������βָ��
}

int main()
{
	LinkList L,L2,L3;//L1,L3ΪҪ���ӵ�������
	char x;
	x='a';
	//����L1
	L=(LinkList)malloc(sizeof(ListNode));//ѭ�������ͷ���
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
	L2->next=L->next;
	L->next=L2;

	//����L3
	L3=(LinkList)malloc(sizeof(ListNode));//ѭ�������ͷ���
	L3->next=NULL;
	L2=L3;
	for(i=0;i<5;i++)
	{
		LinkList L1;
		L1=(LinkList)malloc(sizeof(ListNode));
		L1->data=x;
		L1->next=L2->next;
		L2->next=L1;
		L2=L1;
		x++;
	}
	L2->next=L3->next;
	L3->next=L2;
	LinkList L21=Connect(L,L3);
	if(L21!=NULL)
		printf("ѭ���������ӳɹ���\n");

	return 0;
}
