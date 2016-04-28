#include <stdio.h>
#include <malloc.h>
typedef char datatype;
typedef struct
{
	datatype **data;//指向二维数组的指针
	int row;//行数
	int col;//列数
}Array;

void Init_Array(Array &A,int row,int col,datatype data)							//为A分配空间并对数组A赋初值data
{
    
	A.data=new datatype*[row];							//创建一个大小为row类型为datatype* 的指针即创建行
	for(int   i=0;i<row;i++)							//为每一行中的列分配空间  
		A.data[i]=new  datatype[col];
	A.col=col;
	A.row=row;
	for(i=0;i<A.row;i++)								//依次对数组中的元素赋值
	{
		for(int j=0;j<A.col;j++)
			A.data[i][j]=data;
	}	
	
}

void Write_Array(Array &A,int row,int col,datatype data)//将data存入数组A的第row行col列
{
	if(row>A.row||col>A.col||row<1||col<1)				//判断row和col是否越界
	{
		printf("数组下标越界!");
		return;
	}
	else
	{
		A.data[row-1][col-1]=data;						//注意这里的row和col的值都要减一
	}
}

datatype Read_Array(Array A,int row,int col)			//读取数组A的第row行col列的值
{
	if(row>A.row||col>A.col||row<1||col<1)				//判断row和col是否越界
	{
		printf("数组下标越界!");
	}
	else
	{
		return A.data[row-1][col-1];					//注意这里的row和col的值都要减一
	}
}
datatype Change_Array(Array &A,int row,int col,datatype data)	//将数组A的第row行col列值变为data
{
	if(row>A.row||col>A.col||row<1||col<1)				//判断row和col是否越界
	{
		printf("数组下标越界!");
	}
	else
	{
		datatype data1=A.data[row-1][col-1];			//保存原来的值
		A.data[row-1][col-1]=data;						//修改相应位置的值
		return 	data1;									//返回原来的值					
	}
}

void Del_Array(Array &A)
{
	for(int i=0;i<A.row;i++)							//先回收行所占据的存储空间
		delete   [] A.data[i];   
	delete   [] A.data;									//销毁整个数组
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