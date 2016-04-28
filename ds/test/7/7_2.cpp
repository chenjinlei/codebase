#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;			//������ݱ���
	struct BiTNode *Lchild;		//����ָ��
	struct BiTNode *Rchild;		//�Һ���ָ�� 
} BiTNode, *BiTree;

//����һ�ÿն�����
int Init(BiTree &T)
{
	if ((T = (BiTNode* )malloc(sizeof(BiTNode))))		//����һ���ս��
	{
		T->Lchild = NULL;				//����ָ��Ϊ��	    
		T->Rchild = NULL;				//�Һ���ָ��Ϊ��
		return 1;					//�ɹ�
	}
	else
		return 0;					//ʧ��
}

//����һ�ö�����
void Destroy(BiTree &T)
{
	if (T)				//��T�ǿ�
	{
		Destroy(T->Lchild);     //����������
		Destroy(T->Rchild);	//����������
		free(T);		//���ٸ����
		T = NULL;
	}
	return;
}

//ɾ��������ĳ������������������
void DeleteL(BiTree &T, BiTree pt)
{
	if (pt == NULL || pt->Lchild == NULL)	//pt����������Ϊ��
		return;				//�˳�
	Destroy(pt->Lchild);			//����pt������
	pt->Lchild = NULL;			//pt����ָ�븳��
}

//�ڶ������в�����
void InsertL(BiTree &T, ElemType e, BiTree pt)
{
	BiTree p;
	if (pt)
	{
		if ((p = (BiTNode*)malloc(sizeof(BiTNode))))	//������ռ�
		{
			p->data = e;				//��ֵ
			//�����½��
			p->Lchild = pt->Lchild;
			p->Rchild = pt->Rchild;
			pt->Lchild = p;
		}
	}
}

void InsertR(BiTree &T, ElemType e, BiTree pt)
{
	BiTree p;
	if (pt)
	{
		if ((p = (BiTNode*)malloc(sizeof(BiTNode))))	//������ռ�
		{
			p->data = e;				//��ֵ
			//�����½��
			p->Lchild = pt->Lchild;
			p->Rchild = pt->Rchild;
			pt->Rchild = p;
		}
	}
}

int main()
{
	BiTree T;
	printf("create a null tree\n");
	Init(T);
	printf("success a null tree\n");

	printf("����Left���\n");
	InsertL(T, 'A', T);
	printf("%c\n", T->Lchild->data);
	printf("����Right���\n");
	InsertR(T, 'B', T);
	printf("%c\n", T->Rchild->data);


	printf("ɾ����������\n");
	DeleteL(T, T);

	return 0;
}
