#include <stdio.h>
#include <malloc.h>
typedef int * pint;
void Store_Matrix(pint &A,int n,int *b,int choice)			//A为矩阵的存储数组，n为矩阵的阶数，														//b传递矩阵元素，0是上三角
{
	int size=(n*n+n)/2+1;									//计算矩阵所需存储空间数量
	A=(int *)malloc(size*sizeof(int));						//为存储矩阵分配空间
	int k=1;
	if(choice==0)											//上三角
		A[0]=*(b+1*n);										//矩阵第2行第1列元素为常数
	else													//下三角
		A[0]=*(b+1);										//矩阵第1行第2列元素为常数	 
	for(int i=1;i<=n;i++)									//按照行序为主序的存储方法进行存储
		for(int j=1;j<=i;j++)
		{
			if(choice==0)
				A[k]=*(b+(j-1)*n+i-1);						//*(b+(j-1)*n+i-1)是i列j行的值
			else
				A[k]=*(b+(i-1)*n+j-1);						//*(b+(i-1)*n+j-1)是i行j列的值
			k++;
		}		
}
int * Trans_Matrix(int A[],int n)
{
	int *C;
    int size=(n*n+n)/2+1;									//计算矩阵所需存储空间数量
	C=(int *)malloc(size*sizeof(int));						//为存储矩阵分配空间
	C[0]=A[0];
	for(int j=1;j<=n;j++)
		for(int i=1;i<=j;i++)
		{						
			C[j*(j-1)/2+i]=A[j*(j-1)/2+i];					//为转置数组赋值
		}
		return C;
}

void Print_Matrix(int A[],int n,int choice)					//A为矩阵的存储数组，n为矩阵的阶数
{
    for(int i=1;i<=n;i++)									//矩阵从第一个元素开始依次输出
	{
		for(int j=1;j<=n;j++)
		{
			if(choice!=0)									//下三角
			{
				if(i>=j)
					printf("   %d",A[i*(i-1)/2+j]);			//利用矩阵元素下标找到存储位置输出
				else
					printf("   %d",A[0]);  					//输出常数部分
			}
			else											//上三角
			{
				if(i<=j)
					printf("   %d",A[j*(j-1)/2+i]);			//利用矩阵元素下标找到存储位置输出
				else
					printf("   %d",A[0]); 					//输出常数部分
			}
		}
		printf("\n");
	}
}

int main()
{
	int a[3][3]={1,2,2,3,4,5,3,3,6};	
	int *A;													//存储的对角矩阵
	Store_Matrix(A,3,*a,0);
	printf("三角矩阵A为：\n");
	Print_Matrix(A,3,0);
	printf("A的转置为：\n");
	int *b;
	b=Trans_Matrix(A,3);									//这里面要使用对角矩阵A而不是a
	Print_Matrix(b,3,1);									//因为转置后就变为上三角矩阵了，所以应该采用1方式输出
	return 0;
}