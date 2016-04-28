#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;			//结点数据变量
	struct BiTNode *Lchild;		//左孩子指针
	struct BiTNode *Rchild;		//右孩子指针 
} BiTNode, *BiTree;

//先序遍历
void Preorder (BiTree T)
{
	//先序遍历以T为根指针的二叉树
	if (T)
	{					//二叉树为空，不做任何操作
		printf("%c  ", T->data);	// 通过函数指针 *visit 访问根结点 
		Preorder(T->Lchild);		//先序遍历左子树
		Preorder(T->Rchild);		//先序遍历右子树
	}
}

//中序遍历
void Inorder (BiTree T)
{
	//中序遍历以T为根指针的二叉树
	if (T)
	{					//二叉树为空树，不做任何操作
		Inorder(T->Lchild);		//中序遍历左子树
		printf("%c  ", T->data);	//通过函数指针 *visit 访问根结点
		Inorder(T->Rchild);		//中序遍历右子树
	}
}

//后序遍历
void Postorder (BiTree T)
{
	//后序遍历以T为根指针的二叉树
	if (T)
	{					//二叉树为空树，不做任何操作
		Postorder(T->Lchild);		//后序遍历左子树
		Postorder(T->Rchild);		//后序遍历右子树
		printf("%c  ", T->data);	//通过函数指针 *visit 访问根结点
	}
}

///构造二叉树
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

	printf("先序遍历\n");
	Preorder(T);
	printf("中序遍历\n");
	Inorder(T);
	printf("后序遍历\n");
	Postorder(T);
	printf("\n");

	return 0;
}
