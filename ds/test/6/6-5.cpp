#include <stdio.h>
#include <malloc.h>
//typedef int * pint;
typedef struct Node//������
{
	int row;//��
	int col;//��
	int value;//ֵ
	Node *right;//����ָ��
	Node *down;//����ָ��
}MNode;

typedef struct List//����ʮ������
{
	MNode *RowList;//��ָ������,��������ռ���Զ�̬����
	MNode *ColList;//��ָ������
	int m;//���������
	int n;//���������
	int t;//����ķ���Ԫ�ظ���
}CList;
typedef struct
{
	int row;//��
	int col;//��
	int value;//ֵ
}Matrix;

typedef Matrix * pMatrix;

void Store_Matrix(pMatrix &A,int m,int n,int t,int *b)//AΪ����洢���飬m��nΪ����������������t����Ԫ�ظ�����b�������ݾ���Ԫ��								
{
	int size=t;//�����������洢�ռ�����
	A=(Matrix *)malloc(size*sizeof(Matrix));//Ϊ�洢�������ռ�
    int k=0;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(*(b+(i-1)*n+(j-1))!=0)//���δ���������Ԫ��
			{
				A[k].row=i-1;//�������Ԫ����
				A[k].col=j-1;//�������Ԫ����
				A[k].value=*(b+(i-1)*n+(j-1));//�������Ԫ�ص�ֵ
				k++;
			}
}

pMatrix Trans_Matrix(pMatrix A,int m,int n,int t)
{
	pMatrix B;
    int size=t;//�����������洢�ռ�����
	B=(pMatrix)malloc(size*sizeof(pMatrix));//Ϊ�洢�������ռ�
	for(int i=0;i<t;i++)
	{
		B[i].col=A[i].row;//ԭ������д���ת�ú����
		B[i].row=A[i].col;
		B[i].value=A[i].value;
	}
	return B;//����ת�ú�ľ�������
}

int Read_Matrix(pMatrix A,int m,int n,int t,int row,int col)
{

	if(row<=0||col<=0||row>m||col>n)//�ж��±��Ƿ�Խ��
		printf("�±�Խ�磡");
	else
	{
		for(int i=0;i<t;i++)//�����й���t��Ԫ�أ����β���
			if(A[i].row==row&&A[i].col==col)//�ҵ�����
				return A[i].value;
			return 0;//����һά������Ϊ0Ԫ�ء�
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
	printf("ϡ�����AΪ��\n");
	for(int i=0;i<7;i++)
	{
		for(int j=0;j<6;j++)
			printf("  %d",a[i][j]);
		printf("\n");
	}
	B=Trans_Matrix(A,7,6,2);
	printf("\n");
	printf("����Ҫ��ȡ�����ݵ��У����磺0,4:");
	scanf("%d,%d",&row,&col);
	printf("\n��%d�е�%d�е�����Ϊ%d\n",row,col,Read_Matrix(A,7,6,2,row,col));
	printf("\nת�ú�ĵ�%d�е�%d�е�����Ϊ%d\n",row,col,Read_Matrix(B,7,6,2,row,col));
	return 0;
}