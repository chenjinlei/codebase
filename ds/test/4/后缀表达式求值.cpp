#include "stdio.h"

#define MAXSIZE 100				//定义栈的存储容量
typedef double DataType;				//DataType数据类型预定义
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

//表达式求值问题---后缀表达式求值
double  Cal_exp(char *T)										//返回由后缀表达式T运算结果
{    
	Stack  s ;
	char ch;
	double a,b,c,result;
	ch=*T++ ;
	Init_Stack(s) ; 
	while ( ch != '#' )
	{
		if (ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='('&&ch!=')'&&ch!='#')//不是运算符
			Push(s,(double)ch-48) ;
		else
		{ 
			b=Pop(s) ; 
			a=Pop(s) ;	
			printf("a=%f,b=%f\n",a,b);//取出两个操作数
			switch(ch) 									//操作数运算
			{
			case '+':c=a+b ; break ;
			case '-':c=a-b ; break ;
			case '*':c=a*b ; break ;
			case '/':c=a/b ; break ; 
			//case '%':c=a%b ; break ;
			}
			Push(s, c);
		}
		ch=*T++ ;
	}
	result=Pop( s) ;
	return result ;
}
void main()
{
	char c[2];
	char *t=c;
	printf("请输入一个10以内后缀表达式，以#结束\n");
	scanf("%s",t);
	printf("结果 %f \n",Cal_exp(t));
}