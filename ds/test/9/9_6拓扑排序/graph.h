#define MAX_VERTEX_NUM 20 
#define FALSE 0 
#define TRUE 1 
typedef int InfoType; 
typedef int VertexType; 
/*typedef int Status;*/ 
typedef struct ArcNode /* �ڽӱ�ı�ڵ� */ 
{ 
int adjvex; /* ������� */ 
struct ArcNode *nextarc; /* ָ����һ������ָ�� */ 
InfoType info; /* �û������Ϣ����������ΪȨֵ�� */ 
}ArcNode; 
typedef struct VNode /* ��ͷ�ڵ� */ 
{ 
VertexType data; /* ������Ϣ */ 
ArcNode *firstarc; /* ָ���һ���·��ö���Ļ���ָ�� */ 
}VNode; 
typedef struct /* �ڽ������ʾ��ͼ���������� */ 
{ 
VNode *vertices; 
int vexnum,arcnum; /* ͼ�ĵ�ǰ�������ͺ��� */ 
int kind; /* ͼ�������־ */ 
}ALGraph; 
int max_num_v; /* ������*/ 
int * visited;/*�ж��Ƿ��ѷ���*/ 

ALGraph * CreatGraph_A(); 
void SaveGraph_A(ALGraph * graph); 
void Dfs(ALGraph G,int i); 