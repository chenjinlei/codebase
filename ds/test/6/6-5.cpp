#include <stdio.h>
#include <malloc.h>
//typedef int * pint;
typedef struct Node//定义结点
{
	int row;//行
	int col;//列
	int value;//值
	Node *right;//向右指针
	Node *down;//向下指针
}MNode;

typedef struct List//定义十字链表
{
	MNode *RowList;//行指针数组,这样定义空间可以动态分配
	MNode *ColList;//行指针数组
	int m;//矩阵的行数
	int n;//矩阵的列数
	int t;//矩阵的非零元素个数
}CList;
typedef struct
{
	int row;//行
	int col;//列
	int value;//值
}Matrix;

typedef Matrix * pMatrix;

void Store_Matrix(pMatrix &A,int m,int n,int t,int *b)//A为矩阵存储数组，m、n为矩阵行数和列数，t非零元素个数，b用来传递矩阵元素								
{
	int size=t;//计算矩阵所需存储空间数量
	A=(Matrix *)malloc(size*sizeof(Matrix));//为存储矩阵分配空间
    int k=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(*(b+(i-1)*n+(j-1))!=0)//依次存入矩阵非零元素
			{
				A[k].row=i-1;//存入非零元素行
				A[k].col=j-1;//存入非零元素列
				A[k].value=*(b+(i-1)*n+(j-1));//存入非零元素的值
				k++;
			}
}

pMatrix Trans_Matrix(pMatrix A,int m,int n,int t)
{
	pMatrix B;
    int size=t;//计算矩阵所需存储空间数量
	B=(pMatrix)malloc(size*sizeof(pMatrix));//为存储矩阵分配空间
	for(int i=0;i<t;i++)
	{
		B[i].col=A[i].row;//原矩阵的行存入转置后的列
		B[i].row=A[i].col;
		B[i].value=A[i].value;
	}
	return B;//返回转置后的矩阵数组
}

int Read_Matrix(pMatrix A,int m,int n,int t,int row,int col)
{

	if(row<=0||col<=0||row>m||col>n)//判断下标是否越界
		printf("下标越界！");
	else
	{
		for(int i=0;i<t;i++)//数组中共有t个元素，依次查找
			if(A[i].row==row&&A[i].col==col)//找到返回
				return A[i].value;
			return 0;//不在一维数组中为0元素。
	}
}

int main()
{
	int a[7][6]={0};
	a[1][5]=7;
	a[3][3]=8;
	pMatrix A,B;
	Store_Matrix(A,7,6,2,*a);	
	int row,col;
	printf("稀疏矩阵A为：\n");
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<6;j++)
			printf("  %d",a[i][j]);
		printf("\n");
	}
	B=Trans_Matrix(A,7,6,2);
	printf("\n");
	printf("输入要读取的数据的行，列如：0,4:");
	scanf("%d,%d",&row,&col);
	printf("\n第%d行第%d列的数据为%d\n",row,col,Read_Matrix(A,7,6,2,row,col));
	printf("\n转置后的第%d行第%d列的数据为%d\n",row,col,Read_Matrix(B,7,6,2,row,col));
	return 0;
}