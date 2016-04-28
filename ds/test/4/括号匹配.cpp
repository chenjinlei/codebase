#include "stdio.h"
#include "string.h"

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
	if(S.top==-1)											// top=-1时栈空
		return true;
	else
		return false;
}

bool Stack_Full(Stack  S)         //判栈满
{
	if(S.top==MAXSIZE-1)									//下标最大值为MAXSIZE-1
		return true;
	else
		return false;
}

void Push(Stack &S,DataType elem)
{
	if(!Stack_Full(S))										//若栈满就不允许入栈
	{
		S.top++;
		S.elem[S.top]=elem;
	}
	else
		printf("栈已满！不可执行此操作！");
}

DataType Pop(Stack  &S)									//将top-1并返回栈顶元素
{
	if(!Stack_Empty(S))										//若栈空，不许执行出栈操作
	{		
		return S.elem[S.top--];
	}
	else
		printf ("栈已空，不可执行此操作！");
}

DataType GetTop(Stack S)
{
	if(!Stack_Empty(S))										//若栈空，不能获取栈顶元素
	{		
		return S.elem[S.top];
	}
	else
		printf("栈中已经没有元素！");
}

// 括号匹配问题
int MatchBracket( char *st)									//检查表达式ST中括号是否配对
{    
	int i;
	Stack S;												//定义一个栈
	Init_Stack (S);											//初始化栈
	for (i=0; i<strlen(st) ; i++)
	{
		if ( st[i]=='(' )
			Push(S, st[i]);									//遇'('时进栈
		if ( st[i]==')' )										//遇')'
			if (!Stack_Empty(S))								//栈不为空时，将栈顶元素出栈
				Pop(S);
			else
				return 0;										//不匹配，返回0
	}
	if (Stack_Empty(S))
		return 1;											// 匹配，返回1
	else
		return 0;											//不匹配，返回0
}
void main()
{
    int flag=1;
	char j;
	char c[2];
	char *t=c;
	//---------------------------程序解说--------------------------
	printf("本程序用来实现栈和队列的应用。\n");
	//-------------------------------------------------------------
    while(flag)
	{ 
		printf("请选择:\n");
		printf("1、括号匹配问题\n");	
        printf("2、退出程序    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			printf("请输入一个字符串\n");
			scanf("%s",t);
			if(MatchBracket(t))
				printf("字符串 %s 括号匹配\n",t);
			else
				printf("字符串 %s 括号不匹配\n",t);
            break;
		default:
			flag=0;
			printf("程序结束，按任意键退出!\n");
			break;
		}
	}
}