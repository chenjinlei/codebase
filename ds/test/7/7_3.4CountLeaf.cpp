#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;				//结点数据变量
	struct BiTNode *Lchild;			//左孩子指针
	struct BiTNode *Rchild;			//右孩子指针 
} BiTNode, *BiTree;

//统计二叉树中叶子结点的个数 
void CountLeaf(BiTree T, int& count)
{
	//树中叶子结点的数目
	if (T)
	{
		if ((!T->Lchild) && (!T->Rchild))
			count++;		//对叶子结点计数 
		CountLeaf( T->Lchild, count);
		CountLeaf( T->Rchild, count);
	}
}

//构造二叉树
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

	printf("统计二叉树中叶子结点的个数\n");
	CountLeaf(T, counter);
	printf("%d\n", counter);

	return 0;
}



