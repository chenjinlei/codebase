#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;			//结点数据变量
	struct BiTNode *Lchild;		//左孩子指针
	struct BiTNode *Rchild;		//右孩子指针 
} BiTNode, *BiTree;


///构造二叉树
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



