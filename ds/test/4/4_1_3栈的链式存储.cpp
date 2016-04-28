#include "stdio.h"
#include "malloc.h"

#define MAXSIZE 100				//定义栈的存储容量
typedef char DataType;				//DataType数据类型预定义
//链式栈

typedef struct Node
{
	DataType elem;										//栈中元素
	struct Node *top;										//栈顶指针
}StackNode;
typedef StackNode* Stack;									//定义Stack为StackNode*类型

void Init_Stack(Stack &S)								
{
	S=(Stack)malloc(sizeof(StackNode)); 						//分配空间
	S->top=NULL; 											//指针初始化
}

bool Stack_Empty(Stack S)
{
	if(S->top==NULL)										//栈顶指针为空
		return true;
	else
		return false;
}

void Push(Stack &S,DataType elem)  
{
	Stack NewNode=(Stack)malloc(sizeof(StackNode));				//为新节点分配空间
	NewNode->elem=elem;									//为新节点赋值
	NewNode->top=S->top;									//将新节点插入链头
	S->top=NewNode;										//栈顶指针指向新节点
}

DataType GetTop(Stack S)
{
	if(!Stack_Empty(S))										//如果栈不为空，返回栈顶元素
	{
		return (S->top)->elem;
	}
	else
		printf("栈中已经没有元素！");
	 
}

DataType Pop(Stack  &S)									//返回栈顶元素并将栈顶元素删除
{
	if(!Stack_Empty(S))										//若栈空就不许执行出栈操作
	{		
		DataType ch=GetTop(S);
		Stack S1=(S->top)->top;								//保存栈顶元素下一个元素的地址
		delete(S->top);										//删除栈顶元素并释放空间
		S->top=S1;										//栈顶指针指向新的栈顶元素
		return ch;											//返回栈顶元素
	}
	else
		printf("栈已空，不可执行此操作！");
}


void main()
{
	Stack S;         //S为一链式栈
    int flag=1;
    char j,ch;

	//---------------------------程序解说--------------------------
	printf("本程序用来实现链式结构的栈。\n");
	printf("可以实现入栈、出栈、读栈顶元素等操作。\n");
	//-------------------------------------------------------------
    Init_Stack(S);         //初始化栈
    while(flag)
	{ 
		printf("请选择:\n");
        printf("1.显示从栈顶到栈底所有元素\n");
        printf("2.入栈一个元素\n");
        printf("3.出栈一个元素\n");
        printf("4.判栈空\n");
		printf("5.读栈顶元素\n");
        printf("6.退出程序    \n");
        scanf(" %c",&j);
        switch(j)
		{
		case '1':
			StackNode *node;
			if(!Stack_Empty(S))
			{
				node=S;
				while(node->top!=NULL)
				{
					printf("%c  ",node->top->elem);
					node=node->top;
				}
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
			printf("栈顶元素 %c",GetTop(S));
			break;
		default:
			flag=0;
			printf("程序结束，按任意键退出!\n");
		}
	}
}
