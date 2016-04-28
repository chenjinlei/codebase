#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;				//结点数据变量
	struct BiTNode* Lchild;			//左孩子指针
	struct BiTNode* Rchild;			//右孩子指针 
} BiTNode, *BiTree;

BiTNode *GetTreeNode(ElemType item, BiTNode *lptr, BiTNode *rptr)
{
	//生成一个其元素值为 item，左指针为lptr，右指针为 rptr 的结点
	BiTNode* T;
	T = (BiTree )malloc(sizeof(BiTNode));	//生成一个结点
	T-> data = item;
	T-> Lchild = lptr;
	T-> Rchild = rptr;
	return T;
}
BiTNode *CopyTree(BiTNode *T)
{
	//已知二叉树的根指针为 T,本算法返回它的复制品的根指针
	struct BiTNode *newlptr, *newrptr;
	BiTNode *newnode;
	if (!T)
		return NULL;				//复制一棵空树
	if (T->Lchild)
		newlptr = CopyTree(T->Lchild);		//复制(遍历)左子树
	else
		newlptr = NULL;
	if (T->Rchild)
		newrptr = CopyTree(T->Rchild);		//复制(遍历)右子树
	else
		newrptr = NULL;
	newnode = GetTreeNode(T->data, newlptr, newrptr);	//生成根结点
	return newnode;
}

//构造二叉树
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

//中序遍历
void Inorder (BiTree T)
{
	//中序遍历以T为根指针的二叉树
	if (T)
	{						//二叉树为空树，不做任何操作
		Inorder(T->Lchild);			//中序遍历左子树
		printf("%c  ", T->data);		//通过函数指针 *visit 访问根结点
		Inorder(T->Rchild);			//中序遍历右子树
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
