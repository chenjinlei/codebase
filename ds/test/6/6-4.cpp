#include <stdio.h>
#include <malloc.h>
typedef int * pint;

void Store_Matrix(pint &A,int n,int m,int *b)//nΪ����Ľ�����mΪ�ԽǾ���İ���
{
	int size=m*(2*n-m-1)+n;//�����������洢�ռ�����
	A=(int *)malloc(size*sizeof(int));//Ϊ�洢�������ռ�
	int k=0;
	for(int i=1;i<n;i++)
	{
		int j,col;
		if(i<=m+1)//Ҫ�洢�������Ǵӵ�һ�п�ʼ��,��m+i����
		{
			j=1;
			col=m+i;
		}
		if(i>m+1)//Ҫ�洢�������Ǵӵ�i-m�п�ʼ��,��n����
		{
			j=i-m;
			col=n;
		}
		for(j;j<=col;j++)//ÿ��Ҫ�洢�����±��j��ʼ��col����
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
	if(row<=0||col<=0||row>n||col>n)//�ж��±��Ƿ�Խ��
		printf("�±�Խ�磡");
	else
	{
		int k;//kΪӳ�䵽һά������±�
		if(row<=col)//�Խ����Ϸ�Ԫ��
			k=(m-col+row)*(2*(n-m)+m-(col-row+1))/2+row-1;
		else//�Խ����·�Ԫ��
			k=col*(col-1)/2+row-1;
		if(k<0||k>m*(2*n-m-1)+n-1)//0Ԫ��
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
	printf("����Ҫ��ȡ�����ݵ��У����磺2,4:");
	int row,col;
	scanf("%d,%d",&row,&col);
	printf("\n��%d�е�%d�е�����Ϊ%d\n",row,col,Read_Matrix(A,row,col,4,3));
	return 0;
}