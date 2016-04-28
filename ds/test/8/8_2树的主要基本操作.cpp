#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define FALSE  0
#define OK     1
#define TRUE   1
#define ERROR  0
#define OVERFLOW    -2
typedef char TElemType; /* Ԫ������Ϊ�ַ�����*/
typedef int Status;


//--------------���Ķ�����������-�ֵܣ��洢��ʾ------//

typedef struct CBNode {
	TElemType data;
	struct CBNode *firstchild, *brother;
} CBNode, *CBTree;

//--------------���õ��Ķ��еĴ洢�ṹ----------------//

typedef struct QBNode {
	CBTree base;
	QBNode *next;
} QBNode, *QCB;

typedef struct {
	QCB front;   //��ͷָ��
	QCB rear;    //��βָ��
} Queue;


//��Ҫ����ԭ��
void InitTree();//��ʼ����
void DestroyTree();//������
Status LevelCreateTree();//��η�ʽ������
void PreCreateTree();//�ȸ�����������
void ClearTree();//�����
Status TreeEmpty();//�ж����շ�
Status TreeDepth();//���������
TElemType Root();//����������
Status Point();//�жϽ���Ƿ����
Status Assign();//�޸Ľ��ֵ
TElemType Parent();//����˫�׵�ֵ
TElemType LeftChild();//����ĳ���
TElemType RightBrother();//��������ֵ�
Status InsertChild();//��������
Status DeleteChild();//ɾ������
Status LevelOrderTraverse();//���������
Status PreOrderTraverse();//�ȸ�������
Status PostOrderTraverse();//���������


//�㷨ʵ��
Status InitQueue(Queue &Q)
{
	//����ն���Q
	Q.rear = (QCB)malloc(sizeof(QBNode));
	Q.front = Q.rear;
	if (!Q.front)
		return OVERFLOW;
	Q.rear->next = NULL;
	return OK;
}

Status EnQueue(Queue &Q, CBTree &e)
{
	//����Ԫ��eΪQ���µĶ�βԪ��
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
	//�����зǿգ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK,���򷵻�ERROR
	QCB p;
	if (Q.front == Q.rear)
		return ERROR;//�ն���
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
	//�ж�Q�Ƿ�Ϊ�ն��У��Ƿ���TRUE,�񷵻�FALSE
	if (Q.front->next == NULL)
		return TRUE;
	return FALSE;
}

//Status(*Visit)(TElemType)

void InitTree(CBTree &T)
{
	//�������T
	T = NULL;
}

void DestroyTree(CBTree &T)
{
	//��ʼ��������T���ڡ����������������T
	if (T)
	{
		if (T->firstchild)//T�г���
			DestroyTree(T->firstchild);//������T����Ϊ��������
		if (T->brother)//T����һ���ֵ�
			DestroyTree(T->brother);//������T����һ���ֵ�Ϊ��������
		free(T);//�ͷ�����T
		T = NULL;
	}
}

#define ClearTree DestroyTree // ���߲�����ͬ
Status LevelCreateTree(CBTree &T)
{
	//���ڿ���T���Բ�η�ʽ������T
	TElemType te[30];//��ʱ�������ĺ��ӽ��
	CBTree p, e;
	TElemType root;
	int i, length;
	Queue Q;
	InitQueue(Q);
	printf("�Բ�η�ʽ�����������������㣬�ַ��͵ģ�����0��ʾΪ�գ�");
	scanf("%c%*c", &root);
	if (root != '0')
	{
		p = (CBTree)malloc(sizeof(CBNode));
		T = (CBTree)malloc(sizeof(CBNode));
		if (!T || !p)
			return ERROR;
		T->data = root;        //T������ֵ
		T->brother = NULL;     //�������ֵܽ��
		EnQueue(Q, T);        //���������
		while (!EmptyQueue(Q))
		{
			DeQueue(Q, p);
			printf("��˳������ %c �������к��ӽ��:", p->data);
			gets(te);
			length = strlen(te);
			if (length > 0)
			{
				e = (CBTree)malloc(sizeof(CBNode));
				if(!e)
					return ERROR;
				e->data = te[0];//���p�ĳ���
				p->firstchild = e;
				for (i = 1; i < length; ++i)
				{
					e->brother = (CBTree)malloc(sizeof(CBNode));
					EnQueue(Q, e);
					e = e->brother;
					e->data = te[i];
				}
				e->brother = NULL;
				EnQueue(Q, e);//���һ����������
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
	//�ȸ��������ɶ���������(����-�ֵ�)
	TElemType t;
	printf("�ȸ��������������ȸ���ʽ�����������н�㣬�ڿս����Ӧλ������Esc����ʾ��\n");
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
	//��ʼ��������T���ڡ�
	//�����������TΪ�������򷵻�TRUE�����򷵻�FALSE
	if (!T)
		return TRUE;
	return FALSE;
}

Status TreeDepth(CBTree T)
{
	//��ʼ��������T���ڡ�������������أԵ����
	CBTree p;
	InitTree(p);
	int dep, m = 0;
	if (!T)
		return 0;//����
	else if (!T->firstchild)
		return 1;//ֻ������
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
	// ����p��ָ����ֵ
	if (p)
		return p->data;
	return NULL;
}

TElemType Root(CBTree T)
{
	//��ʼ��������T���ڡ��������������T�ĸ�
	if (T)
		return T->data;
	return NULL;
}

CBTree GetPointer(CBTree &T, TElemType e)
{
	// ���ض�������(����-�ֵ�)��T��ָ��Ԫ��ֵΪe�Ľ���ָ��
	Queue Q;
	CBTree p;
	InitTree(p);
	if (T) // �ǿ���
	{
		p = (CBTree)malloc(sizeof(CBNode));  //����ռ�
		InitQueue(Q); // ��ʼ������
		EnQueue(Q, T); // ��������
		while (!EmptyQueue(Q)) // �Ӳ���
		{
			DeQueue(Q, p); // ����,����Ԫ�ظ���p
			if (p->data == e)
				return p;
			if (p->firstchild) // �г���
				EnQueue(Q, p->firstchild); // ��ӳ���
			if (p->brother) // ����һ���ֵ�
				EnQueue(Q, p->brother); // �����һ���ֵ�
		}
	}
	return NULL;
}

Status Point(CBTree &T, TElemType cur_e)
{
	//��T���ڣ��ж���T���Ƿ������cur_eֵ��ȵĽ���ֵ�������ڷ���FALSE�����򷵻�TRUE
	CBTree p;
	p = GetPointer(T, cur_e);
	if (p)
		return TRUE;
	else
		return FALSE;
}

Status Assign(CBTree T,TElemType cur_e,TElemType value)
{
	//��ʼ��������T���ڣ�cur_e��T��ĳ����㡣
	//������������cur_e��ֵΪvalue��
	CBTree p;
	p = GetPointer(T, cur_e);
	if (!p)
		return ERROR;//ָ���ȡʧ��
	p->data = value;
	return OK;
}

TElemType Parent(CBTree T, TElemType cur_e)
{
	//��ʼ��������T���ڣ�cur_e��T��ĳ����㡣
	//�����������cur_e��T�ķǸ���㣬�򷵻�����˫�ף�������ֵΪ"��"
	CBTree p, t;
	Queue Q;
	InitQueue(Q);
	if (T) // ���ǿ�
	{
		if (Value(T) == cur_e)     // �����ֵΪcur_e
			return NULL;
		EnQueue(Q, T);           // ��������
		while (!EmptyQueue(Q))
		{
			DeQueue(Q,p);
			if (p->firstchild)       // p�г���
			{
				if (p->firstchild->data == cur_e)  // ����Ϊcur_e
					return Value(p);              // ����˫��
				t = p;                            // ˫��ָ�븳��t
				p = p->firstchild;                // pָ����
				EnQueue(Q, p);                   // ��ӳ���
				while (p->brother)           // ����һ���ֵ�
				{
					p = p->brother;             // pָ����һ���ֵ�
					if (Value(p) == cur_e)                // ��һ���ֵ�Ϊcur_e
						return Value(t);             // ����˫��
					EnQueue(Q, p);            // �����һ���ֵ�
				}
			}
		}
	}
	return NULL; // ���ջ�û�ҵ�cur_e

}

TElemType LeftChild(CBTree T, TElemType cur_e)
{
	//��ʼ��������T���ڣ�cur_e��T��ĳ����㡣
	//�����������cur_e��T�ķ�Ҷ�ӽ�㣬�򷵻����������ӣ����򷵻�"��"
	CBTree p;
	p = GetPointer(T,cur_e);
	if (p && p->firstchild)
		return Value(p->firstchild);
	else
		return NULL;
}

TElemType RightBrother(CBTree T, TElemType cur_e)
{
	//��ʼ��������T���ڣ�cur_e��T��ĳ����㡣
	//�����������cur_e�����ֵܣ��򷵻��������ֵܣ����򷵻�"��"
	CBTree p;
	p = GetPointer(T, cur_e);
	if (!p || !p->brother)
		return NULL;
	return Value(p->brother);
}

Status InsertChild(CBTree &T, CBTree &p, int i, CBTree c)
{
	//��ʼ���������Դ��ڣ���ָ�����ĳ����㣬1��i��pָ���Ķȣ������ǿ�������Բ��ཻ
	//�������������cΪ���У�ָ���ĵڣ������
	int j;

	if (T && p) // T����
	{
		if (i == 1) // ����cΪp�ĳ���
		{
			c->brother = p->firstchild; // p��ԭ��������c����һ���ֵ�(c�����ֵ�)

			p->firstchild = c;
		}
		else // �Ҳ����
		{
			p = p->firstchild; // ָ��p�ĳ���
			j = 2;
			while (p && j < i)
			{
				p = p->brother;
				j++;
			}
			if (j == i&&p) // �ҵ�����λ��
			{
				c->brother = p->brother;

				p->brother = c;
			}
			else // pԭ�к�����С��i-1
				return ERROR;
		}
		return OK;
	}
	else // T��
		return ERROR;
}

Status DeleteChild(CBTree &T, CBTree &p, int i)
{
	//��ʼ��������T���ڣ�pָ��T��ĳ����㣬1��i��pָ���Ķ�
	//���������ɾ�����У���ָ���ĵڣ������
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
			p = p->firstchild; // pָ����
			j = 2;
			while (p && j<i)
			{
				p = p->brother;
				j++;
			}
			if (j == i) // �ҵ���i������
			{
				t = p->brother;
				p->brother = t->brother;
				t->brother = NULL;
				DestroyTree(t);
			}
			else // pԭ�к�����С��i
				return ERROR;
		}
		return OK;
	}
	else
		return ERROR;//��TΪ��
}

Status PreOrderTraverse(CBTree T)
{
	//�ȸ�������T����ÿ��������Visit������һ������ʧ�ܣ������ʧ��
	if (T)
	{
		printf("%c", T->data);//���ȷ��ʸ����
		PreOrderTraverse(T->firstchild);// Ȼ���ȸ�������������
		PreOrderTraverse(T->brother);//// ����ȸ�������һ���ֵ�����
		return OK;
	}
	return ERROR;
}

Status PostOrderTraverse(CBTree T)
{
	//���������T����ÿ��������Visit������һ������ʧ�ܣ������ʧ��
	CBTree p;
	if (T)
	{
		if (T->firstchild != NULL)       //�г���
		{
			PostOrderTraverse(T->firstchild); // ���������������
			p = T->firstchild->brother; // pָ���ӵ���һ���ֵ�
			while (p)
			{
				PostOrderTraverse(p); // ���������һ���ֵ�����
				p = p->brother; // pָ������һ���ֵ�����
			}
		}
		printf("%c", T->data);//�����ʸ����T
		return OK;
	}
	return ERROR;
}

Status LevelOrderTraverse(CBTree T)
{
	//���������T����ÿ��������Visit������һ������ʧ�ܣ������ʧ��
	Queue Q;
	CBTree p;
	InitTree(p);
	if (T)
	{
		p = (CBTree)malloc(sizeof(CBNode));
		InitQueue(Q);
		printf("%c", T->data);   //���ʸ����
		EnQueue(Q, T);
		while (!EmptyQueue(Q))
		{
			DeQueue(Q, p);
			if (p->firstchild) // �г���
			{
				p = p->firstchild;
				printf("%c", p->data); // ���ʳ��ӽ��
				EnQueue(Q, p); // ��ӳ��ӽ���ָ��
				while (p->brother) // ����һ���ֵ�
				{
					p = p->brother;
					printf("%c", p->data); // ������һ���ֵ�
					EnQueue(Q, p); // ����ֵܽ���ָ��
				}
			}
		}
		return OK;
	}
	return ERROR;
}

//����
int main()
{

	system("cls");   //����
	int i;
	CBTree T, tree, p, q;
	InitTree(T);
	InitTree(tree);
	TElemType t1, t2;
	printf("�ѳ�ʼ������T,�빹����T.\n");
	LevelCreateTree(T);
	printf("��T������ϣ�����ʾ��T�������Ϣ��\n");
	printf("��T�ĸ���㣺 %c ", Root(T));
	printf("��T����ȣ� %d \n", TreeDepth(T));

	printf("�ȸ�������T:");
	PreOrderTraverse(T);
	printf("\n���������T:");
	PostOrderTraverse(T);
	printf("\n��α�����T:");
	LevelOrderTraverse(T);

	printf("\n����һ���ַ�ֵt1: ");
	scanf("%c%*c", &t1);
	p = GetPointer(T, t1);
	if (Point(T, t1))
	{
		printf("\n����T�д���ֵΪ %c �Ľ��", t1);
		printf("\nt1����˫����: %c ������: %c ���ֵ���: %c",
		       Parent(T, t1), LeftChild(T, t1), RightBrother(T, t1));
	}
	else
	{
		printf("\n��T�в�δ���� %c ֵ�Ľ��.", t1);
		goto loop;
	}
	printf("\n��t1ΪҪ���޸ĵĽ��ֵ�������޸�ֵt2:");
	scanf("%c%*c", &t2);
	if (Assign(T, t1, t2))
		printf("\n�޸ĳɹ���");
	else
		printf("\n�޸�ʧ�ܣ���T�ջ���T�����ڽ��t1");
	printf("\n��t1�����в�������tree,����������λ����Ϊt1�ĵڼ�������:");

	scanf("%d%*c", &i);
	printf("\n��������tree.\n");
	PreCreateTree(tree);
	printf("\n��α�������tree:");
	LevelOrderTraverse(tree);
	printf("\n������tree");
	if (!InsertChild(T, p, i, tree))
		printf("\n����ʧ�ܣ���T�ջ���T�����ڽ��t1��t1ԭ�к�����С�� %d", --i);
	else
	{
		printf("\n����T����Ϣ");
		printf("\n��T�ĸ���㣺 %c ", Root(T));
		printf("��T����ȣ� %d \n", TreeDepth(T));

		printf("�ȸ�������T:");
		PreOrderTraverse(T);
		printf("\n���������T:");
		PostOrderTraverse(T);
		printf("\n��α�����T:");
		LevelOrderTraverse(T);
	}

	printf("\n��t1����������Ҫɾ����T��t1����������λ��:");
	scanf("%d%*c", &i);

	if (DeleteChild(T, p, i) == ERROR)
		printf("\nɾ��ʧ�ܣ�������T�ջ���T�����ڽ��t1��t1ԭ�к�����С�� %d", i);
	else
	{
		printf("\n����T����Ϣ");
		printf("\n��T�ĸ���㣺 %c ", Root(T));
		printf("��T����ȣ� %d \n", TreeDepth(T));

		printf("�ȸ�������T:");
		PreOrderTraverse(T);
		printf("\n���������T:");
		PostOrderTraverse(T);
		printf("\n��α�����T:");
		LevelOrderTraverse(T);
	}
	printf("\n��T�Ƿ�Ϊ�գ�");
	if (TreeEmpty(T))
		printf("��T�ѿ�!!!");
	else
	{
		printf("��Tδ�գ���������T!");
		DestroyTree(T);
	}
loop:
	printf("��лʹ�ã��ټ���");
	system("PAUSE");
}
