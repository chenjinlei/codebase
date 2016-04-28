#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;				//������ݱ���
	struct BiTNode *Lchild;			//����ָ��
	struct BiTNode *Rchild;			//�Һ���ָ�� 
} BiTNode, *BiTree;

//ͳ�ƶ�������Ҷ�ӽ��ĸ��� 
void CountLeaf(BiTree T, int& count)
{
	//����Ҷ�ӽ�����Ŀ
	if (T)
	{
		if ((!T->Lchild) && (!T->Rchild))
			count++;		//��Ҷ�ӽ����� 
		CountLeaf( T->Lchild, count);
		CountLeaf( T->Rchild, count);
	}
}

//���������
void createbt(BiTree& T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#') {
		T = NULL;
	} else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		createbt(T->Lchild);
		createbt(T->Rchild);
	}
}


int main()
{
	int counter = 0;
	BiTree T;
	printf("create a tree such as ABC##DE#G##F### \n");
	createbt(T);

	printf("ͳ�ƶ�������Ҷ�ӽ��ĸ���\n");
	CountLeaf(T, counter);
	printf("%d\n", counter);

	return 0;
}



