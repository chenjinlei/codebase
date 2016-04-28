#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;				//结点数据变量
	struct BiTNode *Lchild;			//左孩子指针
	struct BiTNode *Rchild;			//右孩子指针 
} BiTNode, *BiTree;

//求二叉树的深度  
void BiTreeDepth(BiTree T, int level, int &depth)
{
	//T指向二叉树的根，level 为 T 所指结点所在层次， 其初值为1，depth当前求得的最大层次,初值为0
	if (T)
	{
		if (level > depth)
			depth = level;
		BiTreeDepth(T->Lchild, level+1, depth);
		BiTreeDepth(T->Rchild, level+1, depth);
	}
}

//构造二叉树
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

	printf("二叉树的深度\n");
	BiTreeDepth(T, 1, depth);
	printf("%d\n", depth);

	return 0;
}



