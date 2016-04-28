#include "stdio.h"

#define  MaxSize 100				//线性表最大长度，大小可根据需要而定
typedef  int  DataType;			        //类型可根据实际情况而定
typedef  struct {
	char  data[MaxSize];		        //存放数据元素
	int	 length;			//线性表的当前长度
} SqList;

void Create_List(SqList *L)
{
	int i;
	printf("请输入待建立的表长：");
	scanf("%d", &L->length);			//读取键盘输入的表长
	getchar();
	printf("请输入%d个元素用空格分开,", L->length);
	for (i = 0; i < L->length; i++) {
		scanf("%c", &L->data[i]);	//读取键盘输入数据元素
	}
	getchar();
	printf("\n成功建立表!按任意键继续!\n");
	//	getchar();
}


int Length_List(SqList L)
{
	return L.length;			//返回表的长度
}

int Empty_List (SqList L)
{
	if (L.length == 0)			//判断顺序表的长度
		return 1;
	else
		return 0;
}

int Full_List(SqList L)
{
	if (L.length == MaxSize)			//判断顺序表是否为满
		return 1;
	else
		return 0;
}

void Clear_List(SqList L)
{
	L.length = 0;				//删除所有数据元素
}

int Get_List(SqList L, int i)
{
	//判断表是否为空或输入位置是否合法
	if (Empty_List(L) || i < 1 || i > Length_List(L)) {
		printf("表空或者输入的位置不对!");
		return -1;
	}
	return L.data[i-1];			//返回对应位置数据元素
}

void Print_List(SqList L)
{
	//判断表是否为空表
	int i;
	if (Empty_List(L) == 1) {
		printf("空表\n");
		return;
	} else {
		for (i = 0; i < Length_List(L); i++) {
			printf("%c  ", L.data[i]);//输出数据元素
		}
		printf("\n按任意键继续!\n");
	}
	getchar();
}

int Locate_List(SqList L, char x)
{
	int i = 0;
	while (i < L.length && L.data[i] != x)		//在顺序表中查找值为x元素
		i++;

	if (i < L.length)
		return i+1;			//返回数据元素的序号
	else
		return 0;			//查找失败
}


SqList Insert_List(SqList L, int i, char x)
{
	int j;
	if (L.length == MaxSize)			//判断表是否为满
		printf("表满,不能插入\n");
	else if (i < 1 || i > L.length+1)		//判断插入位置是否正确
		printf("插入位置不正确\n");
	else
	{
		for (j = L.length-1; j >= i-1; j--)	//元素依次向后移动
			L.data[j+1] = L.data[j];
		L.data[i-1] = x;			//插入x
		L.length++;			//表长增1
	}
	return L;
}



SqList Delete_List(SqList L,int i)
{
	int j;
	char x;
	if (i < 1 || i > L.length)
		printf("删除位置不正确\n");
	else
	{
		x = L.data[i-1];
		for (j = i; j <= L.length-1; j++)	//元素依次向前移动
			L.data[j-1] = L.data[j];
		L.length--;			//表长减1
		printf("%c已被删除\n", x);
	}
	return L;
}
void Reverse_List(SqList*L)
{
	DataType temp ;				 //设置临时空间用于存放data
	int i;
	for (i = 0; i < L->length/2; i++)		 //只要判断一半就可以了
	{
		temp = L->data[i];		 //交换数据
		L->data[i] = L->data[L->length-1-i];
		L->data[L->length-1-i] = temp;
	}
}

int main()
{
	SqList S;      //S为一线性表
	int loc,flag = 1;
	char j,ch;
	//---------------------------程序解说--------------------------
	printf("本程序用来实现顺序结构的线性表。\n");
	printf("可以实现查找、插入、删除等操作。\n");
	//-------------------------------------------------------------
	Create_List(&S);         //初始化线性表
	while (flag) {
		printf("请选择:\n");
		printf("1.显示所有元素\n");
		printf("2.插入一个元素\n");
		printf("3.删除一个元素\n");
		printf("4.查找一个元素\n");
		printf("5.逆置操作\n");
		printf("6.退出程序    \n");
		scanf("%c", &j);
		switch(j) {
		case '1':
			Print_List(S); break; //显示所有元素
		case '2':
			printf("请输入要插入的元素(一个字符)和插入位置:\n");
			printf("格式：字符，位置；例如:a,2\n");
			scanf(" %c,%d",&ch,&loc);  //输入要插入的元素和插入的位置
			S=Insert_List(S,loc,ch);     //插入
			Print_List(S);//插入成功
			break;
		case '3':
			printf("请输入要删除元素的位置:");
			scanf("%d",&loc);    //输入要删除的元素的位置
			S=Delete_List(S,loc);  //删除
			Print_List(S);
			break;
		case '4':
			printf("请输入要查找的元素:");
			scanf(" %c",&ch);      //输入要查找的元素
			loc=Locate_List(S,ch);      //定位
			if(loc!=0) printf("该元素所在位置:%d\n",loc); //显示该元素位置
			else    printf("%c 不存在!\n",ch);//当前元素不存在
			break;
		case '5':
			Reverse_List(&S);Print_List(S);break;
		default:
			flag=0;
			printf("程序结束，按任意键退出!\n");
		}
	}

	return 0;
}
