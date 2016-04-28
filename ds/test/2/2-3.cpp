#include <stdio.h>
#include <stdlib.h>

typedef char DataType;				//DataType可以是任何相应的数据类型如int, float或char

#define  MaxSize 100				//线性表最大长度，大小可根据需要而定
typedef  struct {
	DataType  data[MaxSize];		//存放数据元素
	int	 length;			//线性表的当前长度
}SqList;

void Insert_IncreaseList(SqList*L,DataType x)
{
	int i;
	if(L->length == MaxSize)		//判断表是否为满
		printf("表满,不能插入\n");
	for(i=L->length-1;i>=0&&L->data[i]>x;i--)
		L->data[i+1]=L->data[i];
	L->data[i+1]=x;				//比较并移动元素
	L->length++;
}

int main()
{
	SqList *L1;
	L1=(SqList *)malloc(sizeof(SqList));	//为指针分配存储空间
	char x='a';
	L1->length=0;
	for(int i=0;i<5;i++)
	{
		L1->data[i]=x++;
		L1->length++;

	}
	Insert_IncreaseList(L1,'d');
	L1->data[L1->length]='\0';		//把最后赋值为'\0'是为了下面输出方便
	printf("插入d结果为：%s\n",L1->data);

	return 0;
}
