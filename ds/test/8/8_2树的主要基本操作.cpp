#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define FALSE  0
#define OK     1
#define TRUE   1
#define ERROR  0
#define OVERFLOW    -2
typedef char TElemType; /* 元素类型为字符类型*/
typedef int Status;


//--------------树的二叉链表（孩子-兄弟）存储表示------//

typedef struct CBNode {
	TElemType data;
	struct CBNode *firstchild, *brother;
} CBNode, *CBTree;

//--------------所用到的队列的存储结构----------------//

typedef struct QBNode {
	CBTree base;
	QBNode *next;
} QBNode, *QCB;

typedef struct {
	QCB front;   //对头指针
	QCB rear;    //队尾指针
} Queue;


//主要函数原型
void InitTree();//初始化树
void DestroyTree();//销毁树
Status LevelCreateTree();//层次方式构造树
void PreCreateTree();//先根历遍生成树
void ClearTree();//清空树
Status TreeEmpty();//判断树空否
Status TreeDepth();//求树的深度
TElemType Root();//求树的树根
Status Point();//判断结点是否存在
Status Assign();//修改结点值
TElemType Parent();//求结点双亲的值
TElemType LeftChild();//求结点的长子
TElemType RightBrother();//求结点的右兄弟
Status InsertChild();//插入子树
Status DeleteChild();//删除子树
Status LevelOrderTraverse();//层次历遍树
Status PreOrderTraverse();//先根历遍树
Status PostOrderTraverse();//后根历遍树


//算法实现
Status InitQueue(Queue &Q)
{
	//构造空队列Q
	Q.rear = (QCB)malloc(sizeof(QBNode));
	Q.front = Q.rear;
	if (!Q.front)
		return OVERFLOW;
	Q.rear->next = NULL;
	return OK;
}

Status EnQueue(Queue &Q, CBTree &e)
{
	//插入元素e为Q的新的队尾元素
	QCB p;
	p = (QCB)malloc(sizeof(QBNode));
	if (!p)
		return OVERFLOW;
	p->base = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

Status DeQueue(Queue &Q, CBTree &e)
{
	//若队列非空，则删除Q的队头元素，用e返回其值，并返回OK,否则返回ERROR
	QCB p;
	if (Q.front == Q.rear)
		return ERROR;//空队列
	p = Q.front->next;
	e = p->base;

	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	p->next = NULL;
	free(p);
	return OK;
}

Status EmptyQueue(Queue Q)
{
	//判断Q是否为空队列，是返回TRUE,否返回FALSE
	if (Q.front->next == NULL)
		return TRUE;
	return FALSE;
}

//Status(*Visit)(TElemType)

void InitTree(CBTree &T)
{
	//构造空树T
	T = NULL;
}

void DestroyTree(CBTree &T)
{
	//初始条件：树T存在。操作结果：销毁树T
	if (T)
	{
		if (T->firstchild)//T有长子
			DestroyTree(T->firstchild);//销毁以T长子为根的子树
		if (T->brother)//T有下一个兄弟
			DestroyTree(T->brother);//销毁以T的下一个兄弟为根的子树
		free(T);//释放树根T
		T = NULL;
	}
}

#define ClearTree DestroyTree // 二者操作相同
Status LevelCreateTree(CBTree &T)
{
	//存在空树T，以层次方式构造树T
	TElemType te[30];//临时存放输入的孩子结点
	CBTree p, e;
	TElemType root;
	int i, length;
	Queue Q;
	InitQueue(Q);
	printf("以层次方式构造树，请输入根结点，字符型的，输入0表示为空：");
	scanf("%c%*c", &root);
	if (root != '0')
	{
		p = (CBTree)malloc(sizeof(CBNode));
		T = (CBTree)malloc(sizeof(CBNode));
		if (!T || !p)
			return ERROR;
		T->data = root;        //T根结点的值
		T->brother = NULL;     //树根无兄弟结点
		EnQueue(Q, T);        //树根入队列
		while (!EmptyQueue(Q))
		{
			DeQueue(Q, p);
			printf("按顺序输入 %c 结点的所有孩子结点:", p->data);
			gets(te);
			length = strlen(te);
			if (length > 0)
			{
				e = (CBTree)malloc(sizeof(CBNode));
				if(!e)
					return ERROR;
				e->data = te[0];//结点p的长子
				p->firstchild = e;
				for (i = 1; i < length; ++i)
				{
					e->brother = (CBTree)malloc(sizeof(CBNode));
					EnQueue(Q, e);
					e = e->brother;
					e->data = te[i];
				}
				e->brother = NULL;
				EnQueue(Q, e);//最后一个结点入队列
			}
			else
				p->firstchild = NULL;
		}
		return OK;
	}
	T = NULL;
	return OK;
}

void PreCreateTree(CBTree &T)
{
	//先根历遍生成二叉链表树(孩子-兄弟)
	TElemType t;
	printf("先根历遍生成树，先根方式输入树的所有结点，在空结点相应位置输入Esc来表示：\n");
	scanf("%c", &t);
	if (t == 27)
		T = NULL;
	else
	{
		T = (CBTree)malloc(sizeof(CBNode));
		T->data = t;
		PreCreateTree(T->firstchild);
		PreCreateTree(T->brother);
	}
}

Status TreeEmpty(CBTree T)
{
	//初始条件：树T存在。
	//操作结果：若T为空树，则返回TRUE，否则返回FALSE
	if (!T)
		return TRUE;
	return FALSE;
}

Status TreeDepth(CBTree T)
{
	//初始条件：树T存在。操作结果：返回Ｔ的深度
	CBTree p;
	InitTree(p);
	int dep, m = 0;
	if (!T)
		return 0;//空树
	else if (!T->firstchild)
		return 1;//只有树根
	else
	{
		for (p = T->firstchild; p; p = p->brother)
		{
			dep = TreeDepth(p);
			if (dep > m)
				m = dep;
		}
		return m+1;
	}
}

TElemType Value(CBTree &p)
{
	// 返回p所指结点的值
	if (p)
		return p->data;
	return NULL;
}

TElemType Root(CBTree T)
{
	//初始条件：树T存在。操作结果：返回T的根
	if (T)
		return T->data;
	return NULL;
}

CBTree GetPointer(CBTree &T, TElemType e)
{
	// 返回二叉链表(孩子-兄弟)树T中指向元素值为e的结点的指针
	Queue Q;
	CBTree p;
	InitTree(p);
	if (T) // 非空树
	{
		p = (CBTree)malloc(sizeof(CBNode));  //分配空间
		InitQueue(Q); // 初始化队列
		EnQueue(Q, T); // 根结点入队
		while (!EmptyQueue(Q)) // 队不空
		{
			DeQueue(Q, p); // 出队,队列元素赋给p
			if (p->data == e)
				return p;
			if (p->firstchild) // 有长子
				EnQueue(Q, p->firstchild); // 入队长子
			if (p->brother) // 有下一个兄弟
				EnQueue(Q, p->brother); // 入队下一个兄弟
		}
	}
	return NULL;
}

Status Point(CBTree &T, TElemType cur_e)
{
	//树T存在，判断树T中是否存在与cur_e值相等的结点的值，不存在返回FALSE，否则返回TRUE
	CBTree p;
	p = GetPointer(T, cur_e);
	if (p)
		return TRUE;
	else
		return FALSE;
}

Status Assign(CBTree T,TElemType cur_e,TElemType value)
{
	//初始条件：树T存在，cur_e是T中某个结点。
	//操作结果：结点cur_e赋值为value。
	CBTree p;
	p = GetPointer(T, cur_e);
	if (!p)
		return ERROR;//指针获取失败
	p->data = value;
	return OK;
}

TElemType Parent(CBTree T, TElemType cur_e)
{
	//初始条件：树T存在，cur_e是T中某个结点。
	//操作结果：若cur_e是T的非根结点，则返回它的双亲，否则函数值为"空"
	CBTree p, t;
	Queue Q;
	InitQueue(Q);
	if (T) // 树非空
	{
		if (Value(T) == cur_e)     // 根结点值为cur_e
			return NULL;
		EnQueue(Q, T);           // 根结点入队
		while (!EmptyQueue(Q))
		{
			DeQueue(Q,p);
			if (p->firstchild)       // p有长子
			{
				if (p->firstchild->data == cur_e)  // 长子为cur_e
					return Value(p);              // 返回双亲
				t = p;                            // 双亲指针赋给t
				p = p->firstchild;                // p指向长子
				EnQueue(Q, p);                   // 入队长子
				while (p->brother)           // 有下一个兄弟
				{
					p = p->brother;             // p指向下一个兄弟
					if (Value(p) == cur_e)                // 下一个兄弟为cur_e
						return Value(t);             // 返回双亲
					EnQueue(Q, p);            // 入队下一个兄弟
				}
			}
		}
	}
	return NULL; // 树空或没找到cur_e

}

TElemType LeftChild(CBTree T, TElemType cur_e)
{
	//初始条件：树T存在，cur_e是T中某个结点。
	//操作结果：若cur_e是T的非叶子结点，则返回它的最左孩子，否则返回"空"
	CBTree p;
	p = GetPointer(T,cur_e);
	if (p && p->firstchild)
		return Value(p->firstchild);
	else
		return NULL;
}

TElemType RightBrother(CBTree T, TElemType cur_e)
{
	//初始条件：树T存在，cur_e是T中某个结点。
	//操作结果：若cur_e有右兄弟，则返回它的右兄弟，否则返回"空"
	CBTree p;
	p = GetPointer(T, cur_e);
	if (!p || !p->brother)
		return NULL;
	return Value(p->brother);
}

Status InsertChild(CBTree &T, CBTree &p, int i, CBTree c)
{
	//初始条件：树Ｔ存在，ｐ指向Ｔ中某个结点，1≤i≤p指结点的度＋１，非空树ｃ与Ｔ不相交
	//操作结果：插入c为Ｔ中ｐ指结点的第ｉ棵子树
	int j;

	if (T && p) // T不空
	{
		if (i == 1) // 插入c为p的长子
		{
			c->brother = p->firstchild; // p的原长子现是c的下一个兄弟(c本无兄弟)

			p->firstchild = c;
		}
		else // 找插入点
		{
			p = p->firstchild; // 指向p的长子
			j = 2;
			while (p && j < i)
			{
				p = p->brother;
				j++;
			}
			if (j == i&&p) // 找到插入位置
			{
				c->brother = p->brother;

				p->brother = c;
			}
			else // p原有孩子数小于i-1
				return ERROR;
		}
		return OK;
	}
	else // T空
		return ERROR;
}

Status DeleteChild(CBTree &T, CBTree &p, int i)
{
	//初始条件：树T存在，p指向T中某个结点，1≤i≤p指结点的度
	//操作结果：删除Ｔ中ｐ所指结点的第ｉ棵子树
	int j;
	CBTree t;
	if (T && p)
	{
		if (i == 1)
		{
			t = p->firstchild;
			p->firstchild = NULL;
			DestroyTree(t);
		}
		else
		{
			p = p->firstchild; // p指向长子
			j = 2;
			while (p && j<i)
			{
				p = p->brother;
				j++;
			}
			if (j == i) // 找到第i棵子树
			{
				t = p->brother;
				p->brother = t->brother;
				t->brother = NULL;
				DestroyTree(t);
			}
			else // p原有孩子数小于i
				return ERROR;
		}
		return OK;
	}
	else
		return ERROR;//树T为空
}

Status PreOrderTraverse(CBTree T)
{
	//先根历遍树T，对每个结点调用Visit函数，一旦调用失败，则操作失败
	if (T)
	{
		printf("%c", T->data);//首先访问根结点
		PreOrderTraverse(T->firstchild);// 然后先根遍历长子子树
		PreOrderTraverse(T->brother);//// 最后先根遍历下一个兄弟子树
		return OK;
	}
	return ERROR;
}

Status PostOrderTraverse(CBTree T)
{
	//后根历遍树T，对每个结点调用Visit函数，一旦调用失败，则操作失败
	CBTree p;
	if (T)
	{
		if (T->firstchild != NULL)       //有长子
		{
			PostOrderTraverse(T->firstchild); // 后根遍历长子子树
			p = T->firstchild->brother; // p指向长子的下一个兄弟
			while (p)
			{
				PostOrderTraverse(p); // 后根遍历下一个兄弟子树
				p = p->brother; // p指向再下一个兄弟子树
			}
		}
		printf("%c", T->data);//最后访问根结点T
		return OK;
	}
	return ERROR;
}

Status LevelOrderTraverse(CBTree T)
{
	//层次历遍树T，对每个结点调用Visit函数，一旦调用失败，则操作失败
	Queue Q;
	CBTree p;
	InitTree(p);
	if (T)
	{
		p = (CBTree)malloc(sizeof(CBNode));
		InitQueue(Q);
		printf("%c", T->data);   //访问根结点
		EnQueue(Q, T);
		while (!EmptyQueue(Q))
		{
			DeQueue(Q, p);
			if (p->firstchild) // 有长子
			{
				p = p->firstchild;
				printf("%c", p->data); // 访问长子结点
				EnQueue(Q, p); // 入队长子结点的指针
				while (p->brother) // 有下一个兄弟
				{
					p = p->brother;
					printf("%c", p->data); // 访问下一个兄弟
					EnQueue(Q, p); // 入队兄弟结点的指针
				}
			}
		}
		return OK;
	}
	return ERROR;
}

//测试
int main()
{

	system("cls");   //清屏
	int i;
	CBTree T, tree, p, q;
	InitTree(T);
	InitTree(tree);
	TElemType t1, t2;
	printf("已初始化空树T,请构造树T.\n");
	LevelCreateTree(T);
	printf("树T构造完毕，将显示树T的相关信息。\n");
	printf("树T的根结点： %c ", Root(T));
	printf("树T的深度： %d \n", TreeDepth(T));

	printf("先根遍历树T:");
	PreOrderTraverse(T);
	printf("\n后根遍历树T:");
	PostOrderTraverse(T);
	printf("\n层次遍历树T:");
	LevelOrderTraverse(T);

	printf("\n输入一个字符值t1: ");
	scanf("%c%*c", &t1);
	p = GetPointer(T, t1);
	if (Point(T, t1))
	{
		printf("\n在树T中存在值为 %c 的结点", t1);
		printf("\nt1结点的双亲是: %c 长子是: %c 右兄弟是: %c",
		       Parent(T, t1), LeftChild(T, t1), RightBrother(T, t1));
	}
	else
	{
		printf("\n树T中并未存在 %c 值的结点.", t1);
		goto loop;
	}
	printf("\n以t1为要被修改的结点值，输入修改值t2:");
	scanf("%c%*c", &t2);
	if (Assign(T, t1, t2))
		printf("\n修改成功！");
	else
		printf("\n修改失败！树T空或树T不存在结点t1");
	printf("\n对t1结点进行插入子树tree,请输入插入的位置作为t1的第几课子树:");

	scanf("%d%*c", &i);
	printf("\n创建子树tree.\n");
	PreCreateTree(tree);
	printf("\n层次遍历子树tree:");
	LevelOrderTraverse(tree);
	printf("\n插入树tree");
	if (!InsertChild(T, p, i, tree))
		printf("\n插入失败，树T空或树T不存在结点t1或t1原有孩子数小于 %d", --i);
	else
	{
		printf("\n新树T的信息");
		printf("\n树T的根结点： %c ", Root(T));
		printf("树T的深度： %d \n", TreeDepth(T));

		printf("先根遍历树T:");
		PreOrderTraverse(T);
		printf("\n后根遍历树T:");
		PostOrderTraverse(T);
		printf("\n层次遍历树T:");
		LevelOrderTraverse(T);
	}

	printf("\n对t1操作，输入要删除树T中t1结点的子树的位置:");
	scanf("%d%*c", &i);

	if (DeleteChild(T, p, i) == ERROR)
		printf("\n删除失败！！！树T空或树T不存在结点t1或t1原有孩子数小于 %d", i);
	else
	{
		printf("\n新树T的信息");
		printf("\n树T的根结点： %c ", Root(T));
		printf("树T的深度： %d \n", TreeDepth(T));

		printf("先根遍历树T:");
		PreOrderTraverse(T);
		printf("\n后根遍历树T:");
		PostOrderTraverse(T);
		printf("\n层次遍历树T:");
		LevelOrderTraverse(T);
	}
	printf("\n树T是否为空？");
	if (TreeEmpty(T))
		printf("树T已空!!!");
	else
	{
		printf("树T未空，将销毁树T!");
		DestroyTree(T);
	}
loop:
	printf("感谢使用！再见！");
	system("PAUSE");
}
