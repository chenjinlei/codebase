#include <stdio.h>
#include <malloc.h>
typedef char DataType;
typedef struct GLNode
{
	int tag;												//标志位tag用来区别原子结点和表结点
	union													//结点的指针域的联合体域
	{
		DataType data;										//原子结点的值域data
		struct GLNode * head;								//表结点的指针域包括表头指针域head
	};
	struct GLNode *next;									//下一个元素的指针
}GList;
typedef GList* pGList;

void CreateGList(pGList &gl,char str[])
{
    char ch;												
    if(*str!='\0')
	{
		ch=*str;
		str++;
	}
    if(ch == '#')											//若输入为＃，则置表头指针为空
	{
        gl = NULL;
    }
	else if(ch == '(')										//若输入左括号则建立子表结点
	{
        gl =(pGList)malloc(sizeof(struct GLNode));
        gl->tag = 1;
		gl->next=NULL;
		CreateGList((gl->head),str); 						//递归构造子表
    }
    else													//建立单元素结点
	{
        gl =(pGList)malloc(sizeof(struct GLNode));
        gl->tag = 0;
        gl->data = ch;
	}
	if(*str!='\0')
	{
		ch=*str;
		str++;
	}
    if(gl == NULL)											//若gl为空，则什么都不做
	{
		;
    }
    else if(ch == ',')										//若输入为逗号则递归构造后继表
	{
        CreateGList((gl->next),str);
    }
    else if((ch == ')') || (ch == ';'))						//后继指针域为空
	{
        gl->next = NULL;
    }
    return;
}

int DepthGList(struct GLNode *gl)
{
    int max = 0;
    while(gl != NULL)										//遍历结点，求出子表的最大深度
	{
        if(gl->tag == 1)
		{
            int dep = DepthGList(gl->head);						//递归求出一个子表的深度
            if(dep > max)									//max为同一个子表中深度最大值
			{
				max = dep;
            }
        }
        gl = gl->next;										//让gl指向下一个结点
    }
    return max+1;											//返回表的深度
}


void PrintGList(struct GLNode *gl)
{
    if(gl->tag == 1)										//对于表结点的处理
	{
        printf("(");										//存在子表，先输出左括号 
        if(gl->head == NULL)								//若子表为空，则输出'#'字符 
		{
            printf("#");
        }
        else												//若子表非表，则递归输出子表 
		{
            PrintGList(gl->head);
        }
        printf(")");										//输出结束后，再输出右括号 
    }
    else													//对单个结点，直接输出其结点的值 
	{
        printf("%c", gl->data);
    }
    if(gl->next != NULL)									//输出该结点的后继表 
	{
        printf(", ");										//先输出逗号分隔 
        PrintGList(gl->next);								//再递归输出后继表 
    }
    return;
}

int main()
{
	GList *gl;
	gl=NULL;
	printf("请输入一广义表：");
	char str[200];
	scanf("%s",str);
	CreateGList(gl,str);
	if(gl!=NULL)
	{
	printf("\n所建的广义表为：");
	PrintGList(gl);
	printf("\n广义表的深度为：%d\n",DepthGList(gl)-2);
	}
	return 0;
}