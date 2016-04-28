#define MAX_VERTEX_NUM 20 
#define FALSE 0 
#define TRUE 1 
typedef int InfoType; 
typedef int VertexType; 
/*typedef int Status;*/ 
typedef struct ArcNode /* 邻接表的表节点 */ 
{ 
int adjvex; /* 顶点序号 */ 
struct ArcNode *nextarc; /* 指向下一条弧的指针 */ 
InfoType info; /* 该弧相关信息（可以视作为权值） */ 
}ArcNode; 
typedef struct VNode /* 表头节点 */ 
{ 
VertexType data; /* 顶点信息 */ 
ArcNode *firstarc; /* 指向第一条衣服该顶点的弧的指针 */ 
}VNode; 
typedef struct /* 邻接链表表示的图的数据类型 */ 
{ 
VNode *vertices; 
int vexnum,arcnum; /* 图的当前顶点数和狐数 */ 
int kind; /* 图的种类标志 */ 
}ALGraph; 
int max_num_v; /* 顶点数*/ 
int * visited;/*判断是否已访问*/ 

ALGraph * CreatGraph_A(); 
void SaveGraph_A(ALGraph * graph); 
void Dfs(ALGraph G,int i); 