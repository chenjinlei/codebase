#include <stdio.h>
#include <malloc.h>
typedef int * pint;
void Store_Matrix(pint &A,int n,int *b,int choice)			//AΪ����Ĵ洢���飬nΪ����Ľ�����														//b���ݾ���Ԫ�أ�0��������
{
	int size=(n*n+n)/2+1;									//�����������洢�ռ�����
	A=(int *)malloc(size*sizeof(int));						//Ϊ�洢�������ռ�
	int k=1;
	if(choice==0)											//������
		A[0]=*(b+1*n);										//�����2�е�1��Ԫ��Ϊ����
	else													//������
		A[0]=*(b+1);										//�����1�е�2��Ԫ��Ϊ����	 
	for(int i=1;i<=n;i++)									//��������Ϊ����Ĵ洢�������д洢
		for(int j=1;j<=i;j++)
		{
			if(choice==0)
				A[k]=*(b+(j-1)*n+i-1);						//*(b+(j-1)*n+i-1)��i��j�е�ֵ
			else
				A[k]=*(b+(i-1)*n+j-1);						//*(b+(i-1)*n+j-1)��i��j�е�ֵ
			k++;
		}		
}
int * Trans_Matrix(int A[],int n)
{
	int *C;
    int size=(n*n+n)/2+1;									//�����������洢�ռ�����
	C=(int *)malloc(size*sizeof(int));						//Ϊ�洢�������ռ�
	C[0]=A[0];
	for(int j=1;j<=n;j++)
		for(int i=1;i<=j;i++)
		{						
			C[j*(j-1)/2+i]=A[j*(j-1)/2+i];					//Ϊת�����鸳ֵ
		}
		return C;
}

void Print_Matrix(int A[],int n,int choice)					//AΪ����Ĵ洢���飬nΪ����Ľ���
{
    for(int i=1;i<=n;i++)									//����ӵ�һ��Ԫ�ؿ�ʼ�������
	{
		for(int j=1;j<=n;j++)
		{
			if(choice!=0)									//������
			{
				if(i>=j)
					printf("   %d",A[i*(i-1)/2+j]);			//���þ���Ԫ���±��ҵ��洢λ�����
				else
					printf("   %d",A[0]);  					//�����������
			}
			else											//������
			{
				if(i<=j)
					printf("   %d",A[j*(j-1)/2+i]);			//���þ���Ԫ���±��ҵ��洢λ�����
				else
					printf("   %d",A[0]); 					//�����������
			}
		}
		printf("\n");
	}
}

int main()
{
	int a[3][3]={1,2,2,3,4,5,3,3,6};	
	int *A;													//�洢�ĶԽǾ���
	Store_Matrix(A,3,*a,0);
	printf("���Ǿ���AΪ��\n");
	Print_Matrix(A,3,0);
	printf("A��ת��Ϊ��\n");
	int *b;
	b=Trans_Matrix(A,3);									//������Ҫʹ�öԽǾ���A������a
	Print_Matrix(b,3,1);									//��Ϊת�ú�ͱ�Ϊ�����Ǿ����ˣ�����Ӧ�ò���1��ʽ���
	return 0;
}