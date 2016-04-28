#include <stdio.h>
#include <malloc.h>
typedef char datatype;
typedef struct
{
	datatype **data;//ָ���ά�����ָ��
	int row;//����
	int col;//����
}Array;

void Init_Array(Array &A,int row,int col,datatype data)							//ΪA����ռ䲢������A����ֵdata
{
    
	A.data=new datatype*[row];							//����һ����СΪrow����Ϊdatatype* ��ָ�뼴������
	for(int   i=0;i<row;i++)							//Ϊÿһ���е��з���ռ�  
		A.data[i]=new  datatype[col];
	A.col=col;
	A.row=row;
	for(i=0;i<A.row;i++)								//���ζ������е�Ԫ�ظ�ֵ
	{
		for(int j=0;j<A.col;j++)
			A.data[i][j]=data;
	}	
	
}

void Write_Array(Array &A,int row,int col,datatype data)//��data��������A�ĵ�row��col��
{
	if(row>A.row||col>A.col||row<1||col<1)				//�ж�row��col�Ƿ�Խ��
	{
		printf("�����±�Խ��!");
		return;
	}
	else
	{
		A.data[row-1][col-1]=data;						//ע�������row��col��ֵ��Ҫ��һ
	}
}

datatype Read_Array(Array A,int row,int col)			//��ȡ����A�ĵ�row��col�е�ֵ
{
	if(row>A.row||col>A.col||row<1||col<1)				//�ж�row��col�Ƿ�Խ��
	{
		printf("�����±�Խ��!");
	}
	else
	{
		return A.data[row-1][col-1];					//ע�������row��col��ֵ��Ҫ��һ
	}
}
datatype Change_Array(Array &A,int row,int col,datatype data)	//������A�ĵ�row��col��ֵ��Ϊdata
{
	if(row>A.row||col>A.col||row<1||col<1)				//�ж�row��col�Ƿ�Խ��
	{
		printf("�����±�Խ��!");
	}
	else
	{
		datatype data1=A.data[row-1][col-1];			//����ԭ����ֵ
		A.data[row-1][col-1]=data;						//�޸���Ӧλ�õ�ֵ
		return 	data1;									//����ԭ����ֵ					
	}
}

void Del_Array(Array &A)
{
	for(int i=0;i<A.row;i++)							//�Ȼ�������ռ�ݵĴ洢�ռ�
		delete   [] A.data[i];   
	delete   [] A.data;									//������������
}
int main()
{
	Array a;
	Init_Array(a,3,4,'\0');
	Write_Array(a,1,1,'a');
	printf("%c\n",Read_Array(a,1,1));
	Change_Array(a,1,1,'b');
	printf("%c\n",Read_Array(a,1,1));
    Del_Array(a);
	return 0;
}