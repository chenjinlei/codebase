#include <stdio.h>
#include <stdlib.h>

typedef char DataType;				//DataType可以是任何相应的数据类型如int, float或char

#define  MaxSize 100				//线性表最大长度，大小可根据需要而定
typedef  struct {
	DataType  data[MaxSize];		//存放数据元素
	int	 length;			//线性表的当前长度
}SqList;

void SqList_Intersect(SqList A,SqList B,SqList &C)
{
	int i=1,j=1,k=0;			//下标初始化，下标都从1开始
	while(i<=A.length&&j<=B.length)		//A,B表均未到表尾
	{
		if(A.data[i]<B.data[j])		//A表元素比B表元素小，A表下标后移
			i++;
		else if(A.data[i]>B.data[j])
			j++;
		else				//在A，B中都存在的元素
		{
			C.data[k++]=A.data[i];	//将其添加到C中
			i++;
			j++;
		}
	}
	C.length=k;				//C表长度位置
}

int main()
{
	SqList L1,L2,L3;
	char x='a';
	L1.length=0;
	L2.length=0;
	L3.length=0;
	for(int i=0;i<5;i++) {
		L1.data[i]=x++;
		L2.data[i]=x;
		L1.length++;
		L2.length++;

	}
	SqList_Intersect(L1,L2,L3);
	L1.data[L1.length]='\0';//把最后赋值为'\0'是为了下面输出方便
	L2.data[L2.length]='\0';
	L3.data[L3.length]='\0';
	printf("L1为：%s\nL2为：%s\n按升序取顺序表L1和L2交集为：%s\n",L1.data,L2.data,L3.data);

	return 0;
}
