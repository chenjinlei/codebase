#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
typedef struct
{
	char S[MAXSIZE];
}SString;

int GetLength(SString s)
{
	int length=0;
	while(s.S[length]!='\0')							//只要字符的值不是’\0’，length的值加1
		length++;
	return length;
}

void InitStr(SString &str)
{
	for(int i=0;i<MAXSIZE;i++)				//从第一个元素到最后元素初始化为'\0'
	{
		str.S[i]='\0';
	}
}

void StrEvaluate(SString &S1,char S2[])	//char S2[]是字符数组一个字符串常量
{
	if(GetLength(S1))
		InitStr(S1);										//对S1初始化
	for(int i=0;S2[i]!='\0';i++)									//从第一个元素开始对S1进行赋值
		S1.S[i]=S2[i];
}

int Index(SString S,SString T, int pos)	//简单的模式匹配			
{//若主串S中存在和模式T相同的子串，则返回子串在S中第pos个字之后第一次出现的位置
	int i = pos, j = 1;
	while(i<=GetLength(S) && j <= GetLength(T))
	{
		if(S.S[i] == T.S[j-1])
		{
			++i;
			++j;
		}												//继续比较后续字符
		else
		{ 
			i = i-j+2; 
			j =1;
		}												//指针后退重新开始匹配
	}
	if(j > GetLength(T))
		return i-GetLength(T)+1;							//匹配成功
	else
		return -1;											//匹配不成功
}


void GetNext(char *T, int next[])								//求模式串T的next函数值并存入数组
{
	int j = 0,k = -1; 
	next[0] = -1; 
	while ( T[j] != '\0') 
	{ 
		if (k == -1 || T[j] == T[k]) 
		{ 
			++j; ++k; 
			if (T[j]!=T[k]) 
				next[j] = k; 
			else 
				next[j] = next[k]; 
		}
		else 
			k = next[k]; 
	}  
}

int KMP(char *s,char* t) //改进的模式匹配
{
	int len=0; 
	const char * t1=t; 
	while(t1[len]!='\0')										//求字符串t的长度
	{ 
		++len;
	} 
	int *next=(int *)malloc(sizeof(int)*(len+1));						//为next数组动态分配空间
	GetNext(t,next);										//求t的next函数值 
	int index=0,i=0,j=0;										//index当前匹配t[0]在s中的位置
	while(s[i]!='\0'&&t[j]!='\0') 
	{ 
		if(s[i]== t[j])										//如果相等的话继续往后比较
		{ 
			++i;
			++j; 
		} 
		else												//如果不相等
		{ 
			index += j-next[j];								//index的值向右移动j-next[j]
			if(next[j]!=-1) 
				j=next[j];									//如果next[j]!=-1就让s[i]与t[next[j]]比较
			else 
			{
				j=0;										//如果next[j]=-1就让s[i+1]与t[0]比较
				++i; 
			}
		}
	}
	delete []next;											//释放为next动态分配的空间
	if(t[j]=='\0')
		return index+1;										// 匹配成功
	else
		return -1; 											// 匹配失败
}

void main()
{
	int loc,length;
	int flag=1;
	char j;
	char s2[100];
	SString s,s1,substring;//s，s1是两个串
	InitStr(s);//初始化串
	InitStr(s1);
	InitStr(substring);
	StrEvaluate(s,"abc");									//执行对串赋值操作
	StrEvaluate(s1,"abc");//执行对串赋值操作
//---------------------------程序解说--------------------------
 printf("本程序用来实现串的简单模式匹配和改进的模式匹配。\n");
 printf("可以实现查找、插入、删除等操作。\n");
 //-------------------------------------------------------------
  while(flag)
    { printf("请选择:\n");
      printf("1.简单的模式匹配\n");
      printf("2.改进的模式匹配\n");
      printf("3.退出  \n");
	  scanf(" %c",&j);
   switch(j)
   {
   case '1':printf("请输入要求的子串：");
			 scanf("%s",s2);//输入子串
			 StrEvaluate(s1,s2);
			 printf("所求子串在0位置之后，第一次出现的位置：%d\n",Index(s,s1,0));//输出子串的位置Index(s,s1,0)
			 break; 
   case '2':printf("请输入要求的子串：");
			 scanf("%s",s2);//输入子串
			 StrEvaluate(s1,s2);
			 printf("所求子串在0位置之后，第一次出现的位置：%d\n",KMP(s.S,s2));//输出子串的位置Index(s,s1,0)
			 break; 
   
   default:flag=0;printf("程序结束，按任意键退出!\n");
   }
 }
}