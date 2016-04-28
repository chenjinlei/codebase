#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;			//������ݱ���
	struct BiTNode *Lchild;		//����ָ��
	struct BiTNode *Rchild;		//�Һ���ָ�� 
} BiTNode, *BiTree;


///���������
void createbt(BiTree& T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#') {
		T = NULL;
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

	printf("create success!\n");

	return 0;
}



