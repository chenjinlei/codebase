#include <stdio.h>
#include <malloc.h>
typedef int * pint;

void Store_Matrix(pint &A,int n,int *b)							//AΪ����Ĵ洢���飬nΪ����Ľ�����														//b�������ݾ���Ԫ��
{
	int size=(n*n+n)/2;										//�����������洢�ռ�����
	A=(int *)malloc(size*sizeof(int));						//Ϊ�洢�������ռ�
	int k=0;
	for(int i=1;i<=n;i++)									//��������Ϊ����Ĵ洢�������д洢
		for(int j=1;j<=i;j++)
		{
			A[k]=*(b+(i-1)*n+j-1);							//*( b+(i-1)*n+j-1)��i��j�е�ֵ
			k++;
		}		
}

int * Add_Matrix(int A[],int B[],int n)						//A��B�Ǵ洢�����һά���飬n�Ǿ�														//��Ľ���
{
	int *C;
	int size=(n*n+n)/2;										//�����������洢�ռ�����
	C=(int *)malloc(size*sizeof(int));						//Ϊ�洢�������ռ�
	for(int i=0;i<size;i++)
	{
		C[i]=A[i]+B[i];
	}
	return C;
}


int * Mul_Matrix(int A[],int data,int n)					//A�Ǵ洢��������飬n�Ǿ���Ľ���
{
	int *C;
	int size=(n*n+n)/2;										//�����������洢�ռ�����
	C=(int *)malloc(size*sizeof(int));						//Ϊ�洢�������ռ�
	for(int i=0;i<size;i++)
	{
		C[i]=A[i]*data;
	}
	return C;												//��������֮�������
}

void Print_Matrix(int A[],int n)							// A�Ǵ洢��������飬n�Ǿ���Ľ���
{
    for(int i=1;i<=n;i++)									//����ӵ�һ��Ԫ�ؿ�ʼ�������
	{
		for(int j=1;j<=n;j++)
		{
			if(i>=j)
				printf("   %d",A[i*(i-1)/2+j-1]);			//���þ���Ԫ���±��ҵ��洢λ�����
			else
				printf("   %d",A[j*(j-1)/2+i-1]);
		}
		printf("\n");										//����
	}
}

int main()
{
	int a[2][2]={1,2,2,3};	
	int *A;													//�洢�ĶԽǾ���
	Store_Matrix(A,2,*a);
	printf("�Գƾ���AΪ��\n");
	Print_Matrix(A,2);
	printf("2*A=\n");
	int *b;
	b=Mul_Matrix(A,2,2);									//������Ҫʹ�öԽǾ���A������a
	Print_Matrix(b,2);
	printf("A+A=\n");
	int *add;
	add=Add_Matrix(A,A,2);
	Print_Matrix(add,2);
	return 0;
}