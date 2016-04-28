#include "stack.h" 
#include "stack.c" 
int *indegree; 
void FindInDegree(ALGraph G,int *indegree) 
{
	int i; 
	
	DFSTraverse(G);  
} 

int topological_sort(ALGraph G) 
{
	SqStack S; 
    int i,count,k; 

    ArcNode* p; 
	indegree = (int *)malloc(max_num_v*sizeof(int)); 
	for(i=0;i<max_num_v;i++) 
	{ 
		indegree[i]=0; 
	} 
    
	//FindInDegree(G,indegree); /* 对各顶点求入度indegree[0..vernum-1] */ 
    for(i = 0;i<max_num_v;i++) 
		printf("the indegree of the vex(%d):%d\n",i,indegree[i]); 
    InitStack(&S); 
 
	for(i=0;i<max_num_v;++i) /* 建零入度顶点栈 */ 
    if(!indegree[i]) /* 入度为0者进栈 */ 
    Push(&S,i); 
    count = 0; 
    while(!StackEmpty(S)) 
	{ 
		Pop(&S,&i); 
        printf("vex(%d)->",(G.vertices[i].data)++); 
        ++count; /* 输出i号顶点并计数 */ 
        for(p=G.vertices[i].firstarc;p; p=p->nextarc) 
		{ 
			k = p->adjvex; /* 对i号顶点的每个邻接点的入度减1 */ 
            if(!(--indegree[k]))Push(&S,k); /* 若入度减为0，则入栈 */ 
		} /* end of for */ 
	} /* end of while */ 

    if (count<max_num_v) 
         return ERROR; /* 该有向图有回路 */ 
    else 
         return OK; 
} 





















