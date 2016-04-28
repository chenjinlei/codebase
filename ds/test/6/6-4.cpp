#include <stdio.h>
#include <malloc.h>
typedef int * pint;

void Store_Matrix(pint &A,int n,int m,int *b)//n为矩阵的阶数，m为对角矩阵的半宽带
{
	int size=m*(2*n-m-1)+n;//计算矩阵所需存储空间数量
	A=(int *)malloc(size*sizeof(int));//为存储矩阵分配空间
	int k=0;
	for(int i=1;i<n;i++)
	{
		int j,col;
		if(i<=m+1)//要存储的数据是从第一列开始的,到m+i结束
		{
			j=1;
			col=m+i;
		}
		if(i>m+1)//要存储的数据是从第i-m列开始的,到n结束
		{
			j=i-m;
			col=n;
		}
		for(j;j<=col;j++)//每行要存储的列下标从j开始到col结束
		{
			if(i<=j)
				A[(m-j+i)*(2*(n-m)+m-(j-i+1))/2+i-1]=*(b+(i-1)*n+j-1);
			else
				A[m*(2*n-m-1)/2+(2*n-i+j-1)*(i-j)/2+(j-1)]=*(b+(i-1)*n+j-1);
		}
	}
}


int Read_Matrix(int A[],int row,int col,int n,int m)
{
	if(row<=0||col<=0||row>n||col>n)//判断下标是否越界
		printf("下标越界！");
	else
	{
		int k;//k为映射到一维数组的下标
		if(row<=col)//对角线上方元素
			k=(m-col+row)*(2*(n-m)+m-(col-row+1))/2+row-1;
		else//对角线下方元素
			k=col*(col-1)/2+row-1;
		if(k<0||k>m*(2*n-m-1)+n-1)//0元素
			return 0;
		else
			return A[k];
	}
}


int main()
{
	int a[4][4]={1,2,3,0,4,6,7,14,5,8,9,13,0,11,12,10};	
	int *A;
	Store_Matrix(A,4,3,*a);
	printf("输入要读取的数据的行，列如：2,4:");
	int row,col;
	scanf("%d,%d",&row,&col);
	printf("\n第%d行第%d列的数据为%d\n",row,col,Read_Matrix(A,row,col,4,3));
	return 0;
}