
#include <stdlib.h>
#include <stdio.h>
#define True 1
#define False 0
#define Error -1
#define Ok 1
#define INFINITY 0

#define MAX_VERTEX_NUM 10 //��󶥵���

#define MAX_EDGE_NUM 40 //������

typedef enum {DG, DN, UDG, UDN} Graphkind;


typedef char VertexType; //������������

typedef struct ArcCell
{
	int adj; //��Ȩͼ��1��0��ʾ���ڷ񣻴�Ȩͼ����Ȩֵ
	//int *info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];


typedef struct
{
	VertexType vexs[MAX_VERTEX_NUM]; //��������
	AdjMatrix arcs; //�ڽӾ���
	int vexnum, arcnum; //ͼ�ĵ�ǰ�������ͻ���
	Graphkind kind;
} MGraph;

typedef struct ArcNode
{
	int adjvex;
	int weight;
	struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode
{
	int data;
	ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
} ALGraph;

int LocateVex(MGraph G, VertexType v1)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
		if (G.vexs[i] == v1)
			return i;
	return -1;
}

typedef struct Node
{
	int data;
	struct Node *next;
} LinkQueueNode;

typedef struct
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
} LinkQueue;

int InitQueue(LinkQueue *Q)
{
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (Q->front != NULL)
	{
		Q->rear = Q->front;
		Q->front->next = NULL;
		return(True);
	}
	else
		return(False);
}

int EnterQueue(LinkQueue *Q, int x)
{
	LinkQueueNode *NewNode;
	NewNode = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if (NewNode != NULL)
	{
		NewNode->data = x;
		NewNode->next = NULL;
		Q->rear->next = NewNode;
		Q->rear = NewNode;
		return(True);
	}
	else
		return(False);
}

int DeleteQueue(LinkQueue *Q, int *x)
{
	LinkQueueNode *p;
	if (Q->front == Q->rear)
		return(False);
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	*x = p->data;
	free(p);
	return(True);
}

int IsEmpty(LinkQueue *Q)
{
	if (Q->front == Q->rear)
		return(True);
	else
		return(False);
}

int visited[MAX_VERTEX_NUM];
int CreatDN(MGraph &G1,ALGraph &G2) // ���������ʾ�������������� G
{
	int b;
	ArcNode *p;
	VertexType v1, v2;
	int w, j, i;
	printf("����ͼ�Ķ�����������\n");
	scanf("%d,%d", &G1.vexnum, &G1.arcnum);
	G2.vexnum = G1.vexnum;
	G2.arcnum = G1.arcnum;
	printf("���붥������\n");
	for (i = 0; i < G1.vexnum; i++)
	{
		scanf("%c", &G1.vexs[i]);
	}
	for (i = 0; i < G1.vexnum; i++)
		for (j = 0; j < G1.vexnum; j++)
			G1.arcs[i][j].adj = INFINITY;
	for (i = 0; i < G2.vexnum; i++)
	{
		G2.vertices[i].data = i;
		G2.vertices[i].firstarc = NULL;
	}
	printf("������������������㼰�˱ߵ�Ȩֵ\n");

	for(int k = 0; k < G1.arcnum; ++k) //�����ڽӾ���
	{
		printf("please input:");
		scanf("%c,%c,%d", &v1, &v2, &w);
		i = LocateVex(G1, v1);
		j = LocateVex(G1, v2);
		G1.arcs[i][j].adj = w;
		p = (ArcNode *)malloc(sizeof(ArcNode));
		b = w;
		p->adjvex = j;
		p->weight = b;
		p->nextarc = G2.vertices[i].firstarc;
		G2.vertices[i].firstarc = p;
	}
	return 1;
}

void dispMGraph(MGraph G)
{
	printf("ͼ���ڽӾ���ͼ�ǣ�\n");

	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			scanf("%d  ", &G.arcs[i][j].adj);
		printf("\n");
	}
}

void Depth1(MGraph g1, int vo)
{
	int vj;
	printf("%c", g1.vexs[vo]);
	visited[vo] = True;
	for (vj = 0; vj < g1.vexnum; vj++)
		if((!visited[vj]) && (!g1.arcs[vo][vj].adj == 0))
			Depth1(g1, vj);
}

void Breadth1(MGraph g1, int vo)
{
	int vi, vj;
	LinkQueue Q;
	InitQueue(&Q);
	visited[vo] = True;
	EnterQueue(&Q, vo);
	while (!IsEmpty(&Q))
	{
		DeleteQueue(&Q, &vi);
		printf("%c", g1.vexs[vi]);
		for (vj = 0; vj < g1.vexnum; vj++)
			if ((!visited[vj]) && (!g1.arcs[vi][vj].adj == 0))
			{
				visited[vj] = True;
				EnterQueue(&Q, vj);
			}
	}
}

void Traverse1(MGraph g1)
{
	int vi;
	for (vi = 0; vi < g1.vexnum; vi++)
		visited[vi] = False;
	printf("\n������ȱ����Ľ��:\n");
	for (vi = 0; vi < g1.vexnum; vi++)
	{
		if (!visited[vi])
		{
			Depth1(g1, vi);
			printf("\n");
		}
	}
	for (vi = 0; vi < g1.vexnum; vi++)
		visited[vi] = False;
	printf("\n������ȱ����Ľ��:\n");
	for(vi = 0; vi < g1.vexnum; vi++)
	{
		if (!visited[vi])
		{
			Breadth1(g1, vi);
			printf("\n");
		}
	}
}

void change1(MGraph G)
{
	printf("ͼ���ڽӾ���ת��Ϊ�ڽӱ����£�\n");

	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
			if (G.arcs[i][j].adj != 0)
				printf("(%c ,%c ,%d)", G.vexs[i], G.vexs[j], G.arcs[i][j].adj);

	}

}

void change2(ALGraph G)
{
	int a [MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int i,j,m;
	ArcNode *p;
	printf("ͼ���ڽӱ�ת��Ϊ�ڽӾ������£�\n");

	for(i=0;i<G.vexnum;i++)
	{
		p=G.vertices[i].firstarc;
		while(p!=NULL)
		{
			m=p->adjvex;
			a[i][m]=p->weight;
			p=p->nextarc;

		}
	}
	for(i=0;i<G.vexnum;i++) {
		for(j=0;j<G.vexnum;j++){
			if(a[i][j]>0);
			else a[i][j]=0;
		}
	}
	for(i=0;i<G.vexnum;i++) {
		for(j=0;j<G.vexnum;j++)
			printf("%d  ",a[i][j]);
		printf("\n");
	}
}


int main()
{
	int a;
	MGraph G1;
	ALGraph G2;
	printf("��������ͼ   ");

	CreatDN(G1, G2);

	dispMGraph(G1);

	Traverse1(G1);
}
