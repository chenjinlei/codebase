#include <stdio.h> 
#include <stdlib.h>
int *indegree; 
#include "Graph.H" 
#include "Graph.c" 

#include "topo.c" 

main() 
{
	ALGraph G; 

	int flag; 
	
	G = * CreatGraph_A(); 
    DFSTraverse(G);

    flag = topological_sort(G); 
	if(ERROR == flag) 
	    printf("erro!have circle\n"); 

}