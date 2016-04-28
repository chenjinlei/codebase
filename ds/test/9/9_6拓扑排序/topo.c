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
    
	//FindInDegree(G,indegree); /* �Ը����������indegree[0..vernum-1] */ 
    for(i = 0;i<max_num_v;i++) 
		printf("the indegree of the vex(%d):%d\n",i,indegree[i]); 
    InitStack(&S); 
 
	for(i=0;i<max_num_v;++i) /* ������ȶ���ջ */ 
    if(!indegree[i]) /* ���Ϊ0�߽�ջ */ 
    Push(&S,i); 
    count = 0; 
    while(!StackEmpty(S)) 
	{ 
		Pop(&S,&i); 
        printf("vex(%d)->",(G.vertices[i].data)++); 
        ++count; /* ���i�Ŷ��㲢���� */ 
        for(p=G.vertices[i].firstarc;p; p=p->nextarc) 
		{ 
			k = p->adjvex; /* ��i�Ŷ����ÿ���ڽӵ����ȼ�1 */ 
            if(!(--indegree[k]))Push(&S,k); /* ����ȼ�Ϊ0������ջ */ 
		} /* end of for */ 
	} /* end of while */ 

    if (count<max_num_v) 
         return ERROR; /* ������ͼ�л�· */ 
    else 
         return OK; 
} 





















