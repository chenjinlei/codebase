#include "stdio.h"
#include "string.h"

#define MAXSIZE 100				//定义栈的存储容量
typedef int DataType;				//DataType数据类型预定义
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
//【示例4-1】：从键盘上输入一批正整数，然后按照相反的次序打印出来。
void Reverse()
{
	Stack a;
	int x;
	Init_Stack(a);
	printf("输入一批整数，直到输入终止标志-1为止!\n");
	scanf("%d",&x);
	while(x!=-1) {
		Push(a,x);
		scanf("%d",&x);
	}
	while(!Stack_Empty(a))									//栈不为空时依次退栈并输出
		printf("%d ",Pop(a));
	printf("\n");
}
//【示例4-2】：栈的简单应用：数制转换问题。
void Conversion(int N,int r)
{
	Stack  s;												//定义一个顺序栈
	DataType   x;
	Init_Stack(s);											//栈S初始化
	while ( N )
	{
		Push( s,N % r );									//由低位到高位求出入栈元素
		N=N / r ;
	}
	while( !Stack_Empty( s ) )								//由高位到低位输出d进制数的每一位
	{
		x=Pop(s) ;
		printf ( "%d",x) ;
	}
}
//【示例4-3】：采用递归算法求解正整数n的阶乘（n!）。
int fun(int n)
{
	if(n==0)
		return 1;
	else
		return n*fun(n-1);
}
//【示例4-4】：回文数字字符串。
int IsHuiwen( char *t)
{														//判断t字符是否为回文
	Stack s;
	int i , len;
	int temp;
	Init_Stack(s);
	len=strlen(t);	
	printf("\n%d\n",len);//求向量长度
	for ( i=0; i<len/2; i++)										//将一半字符入栈
		Push( s, (int)(t[i]));
	while( !Stack_Empty( s))
	{										//每弹出一个字符与相应字符比较
		temp=Pop (s);
		if( temp!=(int)(t[len-i]))
			return 0 ;											//不等则返回0
		else i--;
	} 
}
void main()
{
    int flag=1;
	char j;
	//---------------------------程序解说--------------------------
	printf("本程序用来实现栈和队列的应用。\n");
	//-------------------------------------------------------------
    while(flag)
	{ 
		printf("请选择:\n");
        printf("1.【示例4-1】：从键盘上输入一批正整数，然后按照相反的次序打印出来。\n");
        printf("2.【示例4-2】：栈的简单应用：数制转换问题。\n");
        printf("3.【示例4-3】：采用递归算法求解正整数n的阶乘（n!）。\n");
        printf("4.【示例4-4】：回文数字字符串。\n");
        printf("5.退出程序    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			Reverse();
			break; 
		case '2':
			int N,r;
			getchar();
			printf("请输入整数和数制，用逗号隔开，如3467,8\n");
			scanf("%d,%d",&N,&r);
			Conversion(N,r);
			printf("\n");
            break;
		case '3':
			int n;
			getchar();
			printf("请输入一个整数\n");
			scanf("%d",&n);
			printf("%d 的阶乘是 %d \n",n,fun(n));
            break;
		case '4':
			char c[2];
			char *t;
			t=c;
			printf("请输入一个数字字符串\n");
			scanf("%s",t);
			if(IsHuiwen(t))
				printf("字符串 %s 是回文\n",t);
			else
				printf("字符串 %s 不是回文\n",t);
			break;
		default:
			flag=0;
			printf("程序结束，按任意键退出!\n");
		}
	}
}


