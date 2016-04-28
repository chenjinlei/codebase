#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define n 5                  //�������Ľ���n                   
typedef int ver;
typedef int edg;             //��������ͼ�Ķ���ͱ�ֵΪ����
typedef struct {
	ver v[n];                //����
	edg e[n][n];             //��Ȩ
} graph;                      //�����ڽӾ�������ݽṹ

void printgraph(graph G)            //��ӡ����ڽӾ���
{
	int i, j;
	printf("����");
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

void countD(graph G)                         //�ж�����ͼ�Ķ���Ķȣ����ж�Euler��·
{
	int i, j, l;
	int e = 0, count = 0; 
	int k;                                          //��������0
	int c[n], d[n];
	for (i = 0; i < n; i++) {
		c[i] = 0;
		for (j = 0; j < n; j++) {
			if (G.e[i][j] != 0)
				c[i] = c[i]+1;
		}
		printf("���� %d �ĳ���Ϊ: %d \n", i, c[i]);              //����ͼ�����ⶥ��i�ĳ���Ϊ�ڽӾ����е�i�в�Ϊ0�����ĸ���
	}
	printf("\n");

	for (j = 0; j < n; j++) {
		d[j] = 0;
		for (i = 0; i < n; i++) {
			if (G.e[i][j] != 0)
				d[j] = d[j]+1;
		}
		printf("���� %d �����Ϊ: %d \n", j, d[j]);             //����ͼ�����ⶥ��j�����Ϊ�ڽӾ����е�j�в�Ϊ0�����ĸ���
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
		//�ж�Euler��·�� 1�����ж���ĳ��ȵ�����ȣ�
		//2�����ҽ������������Ϊ��������һ�����ȱ���ȴ�һ        
		k = 1;
	//��һ����ȱȳ��ȴ�һ�������Ķ�����ȵ������
	else {
		if (e==2 && count==n-2)
			k=1;
	}

	if (k == 1)
		printf("����ͼ�д���Euler��·\n");
	else
		printf("����ͼ�в�����Euler��·\n");

}


int main()                                         //������
{
	int i, j, temp;

	graph G;

	srand(time(NULL));                              //�������

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
				temp = rand()%n;                    //��������ڽӾ���
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
	printf("���ɵ�����ͼ�ڽӾ���Ϊ: \n");
	printgraph(G);
	countD (G);                                       //�����Ӻ���
	printf("����ͼ�ı���Ϊ��%d\n", n*(n-1)/2);

}
