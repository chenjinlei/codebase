#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;				//������ݱ���
	struct BiTNode* Lchild;			//����ָ��
	struct BiTNode* Rchild;			//�Һ���ָ�� 
} BiTNode, *BiTree;

BiTNode *GetTreeNode(ElemType item, BiTNode *lptr, BiTNode *rptr)
{
	//����һ����Ԫ��ֵΪ item����ָ��Ϊlptr����ָ��Ϊ rptr �Ľ��
	BiTNode* T;
	T = (BiTree )malloc(sizeof(BiTNode));	//����һ�����
	T-> data = item;
	T-> Lchild = lptr;
	T-> Rchild = rptr;
	return T;
}
BiTNode *CopyTree(BiTNode *T)
{
	//��֪�������ĸ�ָ��Ϊ T,���㷨�������ĸ���Ʒ�ĸ�ָ��
	struct BiTNode *newlptr, *newrptr;
	BiTNode *newnode;
	if (!T)
		return NULL;				//����һ�ÿ���
	if (T->Lchild)
		newlptr = CopyTree(T->Lchild);		//����(����)������
	else
		newlptr = NULL;
	if (T->Rchild)
		newrptr = CopyTree(T->Rchild);		//����(����)������
	else
		newrptr = NULL;
	newnode = GetTreeNode(T->data, newlptr, newrptr);	//���ɸ����
	return newnode;
}

//���������
void createbt(BiTree& T)
{
	char ch;
	scanf ("%c", &ch);
	if (ch == '#') {
		T = NULL;
	} else{
		T = (BiTree )malloc(sizeof(BiTNode));
		T->data = ch;
		createbt(T->Lchild);
		createbt(T->Rchild);
	}
}

//�������
void Inorder (BiTree T)
{
	//���������TΪ��ָ��Ķ�����
	if (T)
	{						//������Ϊ�����������κβ���
		Inorder(T->Lchild);			//�������������
		printf("%c  ", T->data);		//ͨ������ָ�� *visit ���ʸ����
		Inorder(T->Rchild);			//�������������
	}
}

int main()
{
	int depth = 0;
	BiTree T, T0;
	printf("create a tree such as ABC##DE#G##F### \n");
	createbt(T);
	printf("print T\n");
	Inorder(T);
	printf("copytree:\n");
	T0 = CopyTree(T);
	printf("print T0\n");
	Inorder(T0);

	return 0;
}
