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
printf("in put info of number V(%d) \n",(i+1));/*�����i����������Ľ�����Ϣ*/ 
/*********************************************** 
�����i+1��ʵ�ʵĵ�(i)������������Ϣ 
**********************************************/ 
while(1) 
{ 
printf("in put the assign numbers to ArcNode\n"); 
scanf("%d",&temp.adjvex); 
if(99 == temp.adjvex) /* �����Ϊ99��ʾ���� */ 
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
fputc('\n',fp);/*���붥����� 
/*�����ڽӱ��������Ϣ 
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
/*����i����������һ������Ϊ�ս�� 
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
��������:������ȱ����ڽ������ʾ��ͼ 
�������:Graph_A G �ڽ������ʾ��ͼ 
int i ������� 
������� : void 
*********************************************************/ 


/*********************************************************** 

Status ( * VisitFunc)(int v);/*�������� 
void DFS(ALGraph G,Status v) 
{ 
/*�ӵ�v����������ݹ��������ȱ���ͼ G 
int t,j; 
visited[v] = TRUE; 
VisitFunc(v); /*���ʵ�V������ 
/*for(w = G.vertices.firstarc;w > 0;w = G.vertices.firstarc.nextarc) 
t = G.vertices[i].firstarc;/*ȡ����i�ĵ�һ���ڽӵĶ��� 

printf("the ip of the firstarc : %d\n",t); 
printf("the value of the firstarc : %d \n",t->adjvex); 
while(t) 
{ 

j = t->adjvex; 

printf("the num(%d) has't visited\n",visited[j]); 
if(!visited[j])/*��j��δ�����ʹ� 
Dfs(G,j);/*�Ӷ���j��������������ȱ��� 

t = t->nextarc;/*ȡ����i����һ���ڽӶ��� 
} 

} 

void DFSTraverse(ALGraph G,Status( * Visit)(int v)) 
{ 

VisitFunc = Visit; /*ʹ��ȫ�ֱ���VisitFunc��ʹDFS�����躯��ָ����� 
for(v = 0; v<G.vexnum;++v) 
visited[v] = FALSE; /*���ʱ�־�����ʼ�� 
for(v = 0; v<G.vexnum;++v) 
if(!visited[v]) DFS(G,v); 


} 

***************************************************************/ 
void DFSTraverse(ALGraph G) 
{ 
	int i; 

    visited = (int *)malloc(max_num_v * sizeof(int)); 

	for(i = 0;i<max_num_v;i++)/*��visited����ֵ*/ 
		visited[i] = FALSE; 
    for(i = 0;i < max_num_v;i++) 
		if(!visited[i]) Dfs(G, i); 
} 
/*Ϊ������������ŵ�visit,��ӡ�ѷ��ʵĽ���ͬʱ�����ݽ��ָ�����������*/ 
void visit_func(ALGraph G,int i) 
{ 
ArcNode* t; 
printf("*****************************************\n"); 
printf("%d has visted\n",i+1); /*�������Ϊi�Ķ���*/ 

visited[i] = TRUE;/*���Ϊi�Ľ���Ѿ����ʹ�*/ 

t = G.vertices[i].firstarc;/*ȡ����i�ĵ�һ���ڽӵĶ���*/ 
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
t = G.vertices[i].firstarc;/*ȡ����i�ĵ�һ���ڽӵĶ���*/ 
visit_func(G,i); 



/************************************ 
��������붥��i �ڽӵĶ��� 
************************************/ 
while(t) 
{ 

j = t->adjvex; 



if(!visited[j])/*��j��δ�����ʹ�*/ 
Dfs(G,j);/*�Ӷ���j��������������ȱ���*/ 

t = t->nextarc;/*ȡ����i����һ���ڽӶ���*/ 
} 
} 