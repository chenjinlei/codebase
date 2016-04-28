#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct BiTNode
{
	ElemType data;			//结点数据变量
	struct BiTNode *Lchild;		//左孩子指针
	struct BiTNode *Rchild;		//右孩子指针 
} BiTNode, *BiTree;

//构造一棵空二叉树
int Init(BiTree &T)
{
	if ((T = (BiTNode* )malloc(sizeof(BiTNode))))		//构造一个空结点
	{
		T->Lchild = NULL;				//左孩子指针为空	    
		T->Rchild = NULL;				//右孩子指针为空
		return 1;					//成功
	}
	else
		return 0;					//失败
}

//销毁一棵二叉树
void Destroy(BiTree &T)
{
	if (T)				//树T非空
	{
		Destroy(T->Lchild);     //销毁左子树
		Destroy(T->Rchild);	//销毁右子树
		free(T);		//销毁根结点
		T = NULL;
	}
	return;
}

//删除二叉树某结点的子树（左子树）
void DeleteL(BiTree &T, BiTree pt)
{
	if (pt == NULL || pt->Lchild == NULL)	//pt及其左子树为空
		return;				//退出
	Destroy(pt->Lchild);			//销毁pt左子树
	pt->Lchild = NULL;			//pt左孩子指针赋空
}

//在二叉树中插入结点
void InsertL(BiTree &T, ElemType e, BiTree pt)
{
	BiTree p;
	if (pt)
	{
		if ((p = (BiTNode*)malloc(sizeof(BiTNode))))	//分配结点空间
		{
			p->data = e;				//赋值
			//插入新结点
			p->Lchild = pt->Lchild;
			p->Rchild = pt->Rchild;
			pt->Lchild = p;
		}
	}
}

void InsertR(BiTree &T, ElemType e, BiTree pt)
{
	BiTree p;
	if (pt)
	{
		if ((p = (BiTNode*)malloc(sizeof(BiTNode))))	//分配结点空间
		{
			p->data = e;				//赋值
			//插入新结点
			p->Lchild = pt->Lchild;
			p->Rchild = pt->Rchild;
			pt->Rchild = p;
		}
	}
}

int main()
{
	BiTree T;
	printf("create a null tree\n");
	Init(T);
	printf("success a null tree\n");

	printf("插入Left结点\n");
	InsertL(T, 'A', T);
	printf("%c\n", T->Lchild->data);
	printf("插入Right结点\n");
	InsertR(T, 'B', T);
	printf("%c\n", T->Rchild->data);


	printf("删除根左子树\n");
	DeleteL(T, T);

	return 0;
}
