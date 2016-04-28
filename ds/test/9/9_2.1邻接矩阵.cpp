#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define n 5                  //定义矩阵的阶数n                   
typedef int ver;
typedef int edg;             //定义有向图的顶点和边值为整形
typedef struct {
	ver v[n];                //顶点
	edg e[n][n];             //边权
} graph;                      //定义邻接矩阵的数据结构

void printgraph(graph G)            //打印输出邻接矩阵
{
	int i, j;
	printf("顶点");
	for (i = 0; i < n; i++)
		printf("%3d", i);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("%4d", i);
		for (j = 0; j < n; j++)
			printf("%3d", G.e[i][j]);
		printf("\n");
	}
}

void countD(graph G)                         //判断有向图的顶点的度，并判断Euler回路
{
	int i, j, l;
	int e = 0, count = 0; 
	int k;                                          //计数器赋0
	int c[n], d[n];
	for (i = 0; i < n; i++) {
		c[i] = 0;
		for (j = 0; j < n; j++) {
			if (G.e[i][j] != 0)
				c[i] = c[i]+1;
		}
		printf("顶点 %d 的出度为: %d \n", i, c[i]);              //有向图的任意顶点i的出度为邻接矩阵中第i行不为0的数的个数
	}
	printf("\n");

	for (j = 0; j < n; j++) {
		d[j] = 0;
		for (i = 0; i < n; i++) {
			if (G.e[i][j] != 0)
				d[j] = d[j]+1;
		}
		printf("顶点 %d 的入度为: %d \n", j, d[j]);             //有向图的任意顶点j的入度为邻接矩阵中第j列不为0的数的个数
	}

	for (l = 0; l < n; l++) {
		if (c[l] == d[l])
			count++;
		else {
			if (c[l]-d[l] == 1)
				e++;
			else {
				if (d[l]-c[l] == 1)
					e++;
			}
		}
	}
	k = 0;
	if (count == n)
		//判断Euler回路： 1：所有顶点的出度等于入度；
		//2：有且仅有两个点度数为奇数，且一个出度比入度大一        
		k = 1;
	//另一个入度比出度大一，其他的顶点出度等于入度
	else {
		if (e==2 && count==n-2)
			k=1;
	}

	if (k == 1)
		printf("有向图中存在Euler回路\n");
	else
		printf("有向图中不存在Euler回路\n");

}


int main()                                         //主函数
{
	int i, j, temp;

	graph G;

	srand(time(NULL));                              //随机种子

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			G.e[i][j] = 0;
	}

	for (i = 0; i < n; i++)
		G.v[i] = 0;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			do
			{
				temp = rand()%n;                    //随机建造邻接矩阵
				if (G.v[i] < n)
				{
					G.e[i][j] = temp;
					G.v[i]++;
					break;
				}
			}
			while (1);
		}
	}
	printf("生成的有向图邻接矩阵为: \n");
	printgraph(G);
	countD (G);                                       //调用子函数
	printf("有向图的边数为：%d\n", n*(n-1)/2);

}
