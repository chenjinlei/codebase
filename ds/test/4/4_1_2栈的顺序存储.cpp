#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100				//定义栈的存储容量
typedef char DataType;				//DataType数据类型预定义
//顺序栈
typedef struct
{
	int top;						//栈顶元素下标也就是栈顶的值
	DataType elem[MAXSIZE];		//存储栈元素的数组
}Stack;

void Init_Stack(Stack &S)       //初始栈
{
	S.top=-1;
}

bool Stack_Empty(Stack S)        //判栈空
{
	if(S.top==-1)		// top=-1时栈空
		return true;
	else
		return false;
}

bool Stack_Full(Stack  S)       //判栈满
{
	if(S.top==MAXSIZE-1)	//下标最大值为MAXSIZE-1
		return true;
	else
		return false;
}

void Push(Stack &S,DataType elem)
{
	if(!Stack_Full(S))	//若栈满就不允许入栈
	{
		S.top++;
		S.elem[S.top]=elem;
	}
	else
		printf("栈已满！不可执行此操作！");
}

DataType Pop(Stack  &S)		//将top-1并返回栈顶元素
{
	if(!Stack_Empty(S))	//若栈空，不许执行出栈操作
	{
		return S.elem[S.top--];
	}
	else
		printf ("栈已空，不可执行此操作！");
}

DataType GetTop(Stack S)
{
	if(!Stack_Empty(S))	//若栈空，不能获取栈顶元素
	{
		return S.elem[S.top];
	}
	else
		printf("栈中已经没有元素！");
}

int main()
{
	Stack S;         //S为一顺序存储的栈
	int flag=1;
	char j,ch;

	//---------------------------程序解说--------------------------
	printf("本程序用来实现顺序结构的栈。\n");
	printf("可以实现入栈、出栈、读栈顶元素等操作。\n");
	//-------------------------------------------------------------
	Init_Stack(S);         //初始化栈
	while(flag)
	{
		printf("请选择:\n");
		printf("1.显示从栈底到栈顶所有元素\n");
		printf("2.入栈一个元素\n");
		printf("3.出栈一个元素\n");
		printf("4.判栈空\n");
		printf("5.判栈满\n");
		printf("6.读栈顶元素\n");
		printf("7.退出程序    \n");
		scanf(" %c",&j);
		switch(j)
		{
		case '1':
			int i;
			if(!Stack_Empty(S))
			{
				for(i=0;i<=S.top;i++)
					printf("%c  ",S.elem[i]);
			}
			else
				printf("栈空");
			printf("\n");
			break; //显示从栈底到栈顶所有元素
		case '2':
			getchar();//输入的回车
			printf("请输入要入栈的元素(一个字符):\n");
			scanf("%c",&ch);  //输入要入栈的元素
			Push(S,ch);//入栈
			break;
		case '3':
			Pop(S);//出栈
			break;
		case '4':
			if(Stack_Empty(S))
				printf("栈空");
			else
				printf("栈非空");
			break;
		case '5':
			if(Stack_Full(S))
				printf("栈满");
			else
				printf("栈非满");
			break;
		case '6':
			printf("栈顶元素 %c",GetTop(S));
			break;
		default:
			flag=0;
			printf("程序结束，按任意键退出!\n");
		}
	}
	return 0;
}
