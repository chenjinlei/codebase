#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;			//������ݱ���
	struct BiTNode *Lchild;		//����ָ��
	struct BiTNode *Rchild;		//�Һ���ָ�� 
} BiTNode, *BiTree;

//�������
void Preorder (BiTree T)
{
	//���������TΪ��ָ��Ķ�����
	if (T)
	{					//������Ϊ�գ������κβ���
		printf("%c  ", T->data);	// ͨ������ָ�� *visit ���ʸ���� 
		Preorder(T->Lchild);		//�������������
		Preorder(T->Rchild);		//�������������
	}
}

//�������
void Inorder (BiTree T)
{
	//���������TΪ��ָ��Ķ�����
	if (T)
	{					//������Ϊ�����������κβ���
		Inorder(T->Lchild);		//�������������
		printf("%c  ", T->data);	//ͨ������ָ�� *visit ���ʸ����
		Inorder(T->Rchild);		//�������������
	}
}

//�������
void Postorder (BiTree T)
{
	//���������TΪ��ָ��Ķ�����
	if (T)
	{					//������Ϊ�����������κβ���
		Postorder(T->Lchild);		//�������������
		Postorder(T->Rchild);		//�������������
		printf("%c  ", T->data);	//ͨ������ָ�� *visit ���ʸ����
	}
}

///���������
void createbt(BiTree& T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#') {
		T=NULL;
	} else {
		T = (BiTree )malloc(sizeof(BiTNode));
		T->data = ch;
		createbt(T->Lchild);
		createbt(T->Rchild);
	}
}


int main()
{
	BiTree T;
	printf("create a tree such as ABC##DE#G##F### \n");
	createbt(T);

	printf("�������\n");
	Preorder(T);
	printf("�������\n");
	Inorder(T);
	printf("�������\n");
	Postorder(T);
	printf("\n");

	return 0;
}
