#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;				//������ݱ���
	struct BiTNode *Lchild;			//����ָ��
	struct BiTNode *Rchild;			//�Һ���ָ�� 
} BiTNode, *BiTree;

//������������  
void BiTreeDepth(BiTree T, int level, int &depth)
{
	//Tָ��������ĸ���level Ϊ T ��ָ������ڲ�Σ� ���ֵΪ1��depth��ǰ��õ������,��ֵΪ0
	if (T)
	{
		if (level > depth)
			depth = level;
		BiTreeDepth(T->Lchild, level+1, depth);
		BiTreeDepth(T->Rchild, level+1, depth);
	}
}

//���������
void createbt(BiTree& T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#') {
		T=NULL;
	} else {
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = ch;
		createbt(T->Lchild);
		createbt(T->Rchild);
	}
}


int main()
{
	int depth = 0;
	BiTree T;
	printf("create a tree such as ABC##DE#G##F### \n");
	createbt(T);

	printf("�����������\n");
	BiTreeDepth(T, 1, depth);
	printf("%d\n", depth);

	return 0;
}



