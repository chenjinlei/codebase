#include <stdio.h>
#include <stdlib.h>

typedef char DataType;				//DataType可以是任何相应的数据类型如int, float或char

#define  MaxSize 100				//线性表最大长度，大小可根据需要而定
typedef  struct {
	DataType  data[MaxSize];		//存放数据元素
	int	 length;			//线性表的当前长度
}SqList;

int  Comp_List(SqList A,SqList B)
{
	for (int i=0;(i<A.length)&&(i<B.length);i++)
	{
		if(A.data[i]<B.data[i])
			return(-1);
		if(A.data[i]>B.data[i])
			return(1);
	}
	if(A.length==B.length)
		return(0);
	else if(A.length>B.length)
		return(1);
	else return(-1);
}

int main()
{
	SqList L1,L2;
	char x='a';
	L1.length=0;
	L2.length=0;
	for(int i=0;i<5;i++)
	{
		L1.data[i]=x++;
		L2.data[i]=x;
		L1.length++;
		L2.length++;

	}
	L1.data[L1.length]='\0';		//把最后赋值为'\0'是为了下面输出方便
	L2.data[L2.length]='\0';
	printf("L1为：%s\nL2为：%s\n",L1.data,L2.data);
	int cmp=Comp_List(L1,L2);
	if(cmp==0)
		printf("L1=L2\n");
	else if(cmp==-1)
		printf("L1<L2\n");
	else if(cmp==1)
		printf("L1>L2\n");
	return 0;
}
