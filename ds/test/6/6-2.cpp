#include <stdio.h>
#include <malloc.h>
typedef int * pint;

void Store_Matrix(pint &A,int n,int *b)							//A为矩阵的存储数组，n为矩阵的阶数，														//b用来传递矩阵元素
{
	int size=(n*n+n)/2;										//计算矩阵所需存储空间数量
	A=(int *)malloc(size*sizeof(int));						//为存储矩阵分配空间
	int k=0;
	for(int i=1;i<=n;i++)									//按照行序为主序的存储方法进行存储
		for(int j=1;j<=i;j++)
		{
			A[k]=*(b+(i-1)*n+j-1);							//*( b+(i-1)*n+j-1)是i行j列的值
			k++;
		}		
}

int * Add_Matrix(int A[],int B[],int n)						//A、B是存储矩阵的一维数组，n是矩														//阵的阶数
{
	int *C;
	int size=(n*n+n)/2;										//计算矩阵所需存储空间数量
	C=(int *)malloc(size*sizeof(int));						//为存储矩阵分配空间
	for(int i=0;i<size;i++)
	{
		C[i]=A[i]+B[i];
	}
	return C;
}


int * Mul_Matrix(int A[],int data,int n)					//A是存储矩阵的数组，n是矩阵的阶数
{
	int *C;
	int size=(n*n+n)/2;										//计算矩阵所需存储空间数量
	C=(int *)malloc(size*sizeof(int));						//为存储矩阵分配空间
	for(int i=0;i<size;i++)
	{
		C[i]=A[i]*data;
	}
	return C;												//返回数乘之后的数组
}

void Print_Matrix(int A[],int n)							// A是存储矩阵的数组，n是矩阵的阶数
{
    for(int i=1;i<=n;i++)									//矩阵从第一个元素开始依次输出
	{
		for(int j=1;j<=n;j++)
		{
			if(i>=j)
				printf("   %d",A[i*(i-1)/2+j-1]);			//利用矩阵元素下标找到存储位置输出
			else
				printf("   %d",A[j*(j-1)/2+i-1]);
		}
		printf("\n");										//换行
	}
}

int main()
{
	int a[2][2]={1,2,2,3};	
	int *A;													//存储的对角矩阵
	Store_Matrix(A,2,*a);
	printf("对称矩阵A为：\n");
	Print_Matrix(A,2);
	printf("2*A=\n");
	int *b;
	b=Mul_Matrix(A,2,2);									//这里面要使用对角矩阵A而不是a
	Print_Matrix(b,2);
	printf("A+A=\n");
	int *add;
	add=Add_Matrix(A,A,2);
	Print_Matrix(add,2);
	return 0;
}