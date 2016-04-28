ALGraph * CreatGraph_A() 
{ 
int i; 
ArcNode temp; 
ArcNode *tp; 
ALGraph *graph; 
graph = (ALGraph *)malloc(sizeof(ALGraph)); 

printf("in put vexnum:\n"); 
scanf("%d",&max_num_v); 

printf("the max num of vex :%d\n",max_num_v); 
graph->vertices = (VNode *)malloc(max_num_v * sizeof(VNode)); 
for(i=0;i<max_num_v;i++) 
{ 
graph->vertices[i].data = i+1; 
graph->vertices[i].firstarc = NULL; 
printf("in put info of number V(%d) \n",(i+1));/*输入第i个结点相连的结点的信息*/ 
/*********************************************** 
输入第i+1既实际的第(i)个顶点的相关信息 
**********************************************/ 
while(1) 
{ 
printf("in put the assign numbers to ArcNode\n"); 
scanf("%d",&temp.adjvex); 
if(99 == temp.adjvex) /* 结点编号为99表示结束 */ 
{ 
break; 
} /* end of if */ 
printf("in put the weight of ArcNode"); 
scanf("%d",&temp.info); 
tp = (ArcNode *)malloc(sizeof(ArcNode)); 
*tp = temp; 
tp->nextarc = graph->vertices[i].firstarc; 
graph->vertices[i].firstarc = tp; 

} /* end of while */ 
} /*end of for */ 
printf("yeah!\n"); 
return graph; 
} 

/*void SaveGraph_A(ALGraph * graph) 
{ 
FILE * fp; 
ArcNode * tp; 
char g_name[50]; 
int i; 
printf("in put file name:\n"); 
scanf("%s",g_name); 
fp = fopen(g_name,"w") ; 
fwrite(&(graph->vexnum),sizeof(int),1,fp); 
fputc('\n',fp);/*存入顶点个数 
/*存入邻接表各顶点信息 
for(i=0;i<max_num_v;i++) 
{ 
fwrite(&graph->vertices[i].data,sizeof(VertexType),1,fp); 
fputc('\n',fp); 


tp = graph->vertices[i].firstarc; 
while(tp) 
{ 
fwrite(tp,sizeof(ArcNode),1,fp); 
fputc('c',fp); 
tp = tp->nextarc; 
}/* end of while 
/*将第i个顶点的最后一个结点存为空结点 
tp = (ArcNode *)malloc(sizeof(ArcNode)); 
tp->adjvex = 0; 
tp->nextarc = NULL; 
tp->info = 0; 
fwrite(tp,sizeof(ArcNode),1,fp); 
fputc('\n',fp); 





} 

fclose(fp); 

} 
*/ 



/*visited = (int *)malloc(max_num_v * sizeof(int));*/ 
/********************************************************* 
函数功能:深度优先遍历邻接链表表示的图 
输入参数:Graph_A G 邻接链表表示的图 
int i 出发结点 
输出参数 : void 
*********************************************************/ 


/*********************************************************** 

Status ( * VisitFunc)(int v);/*函数变量 
void DFS(ALGraph G,Status v) 
{ 
/*从第v个顶点出发递归地深度优先遍历图 G 
int t,j; 
visited[v] = TRUE; 
VisitFunc(v); /*访问第V个顶点 
/*for(w = G.vertices.firstarc;w > 0;w = G.vertices.firstarc.nextarc) 
t = G.vertices[i].firstarc;/*取顶点i的第一个邻接的顶点 

printf("the ip of the firstarc : %d\n",t); 
printf("the value of the firstarc : %d \n",t->adjvex); 
while(t) 
{ 

j = t->adjvex; 

printf("the num(%d) has't visited\n",visited[j]); 
if(!visited[j])/*若j从未被访问过 
Dfs(G,j);/*从顶点j出发进行深度优先遍历 

t = t->nextarc;/*取顶点i的下一个邻接顶点 
} 

} 

void DFSTraverse(ALGraph G,Status( * Visit)(int v)) 
{ 

VisitFunc = Visit; /*使用全局变量VisitFunc，使DFS不必设函数指针参数 
for(v = 0; v<G.vexnum;++v) 
visited[v] = FALSE; /*访问标志数组初始化 
for(v = 0; v<G.vexnum;++v) 
if(!visited[v]) DFS(G,v); 


} 

***************************************************************/ 
void DFSTraverse(ALGraph G) 
{ 
	int i; 

    visited = (int *)malloc(max_num_v * sizeof(int)); 

	for(i = 0;i<max_num_v;i++)/*给visited赋初值*/ 
		visited[i] = FALSE; 
    for(i = 0;i < max_num_v;i++) 
		if(!visited[i]) Dfs(G, i); 
} 
/*为拓扑排序而安排的visit,打印已访问的结点的同时，根据结点指针求各点的入度*/ 
void visit_func(ALGraph G,int i) 
{ 
ArcNode* t; 
printf("*****************************************\n"); 
printf("%d has visted\n",i+1); /*访问序号为i的顶点*/ 

visited[i] = TRUE;/*序号为i的结点已经访问过*/ 

t = G.vertices[i].firstarc;/*取顶点i的第一个邻接的顶点*/ 
while(t) 
{ 

indegree[t->adjvex]++; 
t = t->nextarc; 
} 

printf("the ip of the next firstarc : %d\n",G.vertices[i].firstarc); 
printf("the value of the next firstarc : %d \n",G.vertices[i].firstarc->adjvex); 
printf("******************************************\n"); 
} 

void Dfs(ALGraph G,int i) 
{ 
ArcNode * t; 
int j; 
t = G.vertices[i].firstarc;/*取顶点i的第一个邻接的顶点*/ 
visit_func(G,i); 



/************************************ 
检查所有与顶点i 邻接的顶点 
************************************/ 
while(t) 
{ 

j = t->adjvex; 



if(!visited[j])/*若j从未被访问过*/ 
Dfs(G,j);/*从顶点j出发进行深度优先遍历*/ 

t = t->nextarc;/*取顶点i的下一个邻接顶点*/ 
} 
} 