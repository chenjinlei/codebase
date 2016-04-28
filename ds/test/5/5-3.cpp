#include <stdio.h>
#include <malloc.h>

typedef struct
{
	char *S;
	int length;
}SString;
typedef SString * pstring;

void InitStr(pstring &str,int size)
{
	str=(pstring)malloc(size*sizeof(pstring));						//为str分配空间
	str->length=0;											//初始化字符串长度为0
	str->S=(char*)malloc(size*sizeof(char));						//为结构体中的S分配空间
	for(int i=0;i<size;i++)										//对字符串中的每一个字符赋初值'\0'
	{
		str->S[i]='\0';
	}
}


void StrEvaluate(pstring &S1,char S2[])
{	
	int size=0;
	S1->length=0;
	while(S2[size]!='\0')
	{
		size++;
	}
	size=size+1;
	if(size-1>S1->length)										//如果所赋值的字符串常量长度大于
	{													//被赋值字符串重新分配空间
		delete(S1->S);
		delete(S1);
		InitStr(S1,size);		
	}	
	for(int i=0;i<size-1;i++)									//从第一个元素开始对S1进行赋值
	{
		S1->S[i]=S2[i];
		S1->length++;										//字符串的长度也要改变
	}
	S1->S[S1->length]='\0';
}

void StrCopy(pstring &S1,pstring S2)
{
	if(S1->length<S2->length)	//为赋值字符串重新分配空间
	{
		delete(S1->S);
		delete(S1);
		InitStr(S1,S2->length+1);	
	}
	S1->length=0;
	for(int i=0;i<S2->length;i++)								//从第一个元素开始对S1进行赋值
	{
		S1->S[i]=S2->S[i];
		S1->length++;										//字符串的长度也要改变
		S1->S[S1->length]='\0';
	}
	S1->S[S1->length]='\0';
	
}

void StrConcat(pstring &S1,pstring S2)
{
	int len1=S1->length-1;
	int len2=S2->length-1;
	pstring s;
	if((len1+len2+1)>=S1->length)								//判断长度是超出范围
	{
		InitStr(s,len1+len2+1);								//初始化串
		for(int i=0;i<len1+1;i++)								//把S1复制过来
		{
			s->S[i]=S1->S[i];
			s->length++;
			s->S[s->length]='\0';		
		}
		for(int j=0;j<len2+1;j++)								//把S2复制过来
		{
			s->S[j+len1+1]=S2->S[j];
			s->length++;
			s->S[s->length]='\0';
		}
		StrCopy(S1,s);
		return;
	}
}

pstring SubStr(pstring S,int i,int length)
{
	pstring S1;
	InitStr(S1,length);										//初始化要返回的子串
	S1->length=0;
	if(i+length>S->length+1||i<=0)								//判断子串的长度是否合法
	{
		printf("%s","所取子串已超出主串的长度!子串获取失败!");
	}
	else
	{
		for(int j=i-1;j<i+length-1;j++) 							//取子串
		{
			S1->S[j+1-i]=S->S[j];
			S1->length++;
			S1->S[S1->length]='\0';
		}
	}
	return S1;	
}

int StrComp(pstring S1,pstring S2)
{
	int i=0;
	while(S1->S[i]==S2->S[i]&&S1->S[i]!='\0')						//有字符不同或者出现‘\0’停止比较
	{
		i++;
	}
	if(S1->S[i]<S2->S[i])
	return -1;
	else if(S1->S[i]>S2->S[i])
	return 1;
	return 0;
}


int StrIndex(pstring S,pstring S1)
{
	if(S1->length>S->length) 
	return -1;												//判断子串长度是否大于主串长度
	int i=0 ;												//定义返回值
	char ch=S1->S[0];										//获取子串的首字符
	for(i=0;i<=S->length-S1->length;i++)
	{
		if(S->S[i]==ch)										//找到S1首字符在字符串S中的位置
			if(StrComp(SubStr(S,i+1,S1->length),S1)==0)			//如果相等就返回当前位置
						return i+1;
	}
	if(i>S->length-S1->length)
	return -1;
}

void StrInsert(pstring &S,int i,pstring t)
{
	pstring S1;
	InitStr(S1,t->length+1);
	StrCopy(S1,t);										//保证t的值不变，将t复给变量S1
	StrConcat(S1,SubStr(S,i,S->length-i+1));			//将S从i开始子串连接到S1的尾部。
	pstring S2;
	InitStr(S2,t->length+S->length+1);
	StrCopy(S2,SubStr(S,1,i-1));							//将s的前半部分子串复制到S2中
	StrConcat(S2,S1);										//将S1连接到S2的尾部
	StrCopy(S,S2);										//将S2复制到S中完成插入
}

void StrDelete(pstring &S,int i,int length)
{
	if((i+length)>S->length+1)									//判断待删除的下标是否合法
	{
		printf("%s","删除下标超出字符串范围!");
		return;
	}
	pstring S1,S2;
	InitStr(S1,length+1);
	InitStr(S2,length+1);
	StrCopy(S1,SubStr(S,1,i-1));								//取出要删除地方的前面子串
	StrCopy(S2,SubStr(S,i+length,S->length-i-length+1));			//获取要删除子串的后半部分子串
	StrConcat(S1,S2);										//将获取的两部分子串连接起来
	StrCopy(S,S1);											//删除掉那部分子串	
}

void StrReplace(pstring &S,int I,int length,pstring t)
{
	StrDelete(S,I,length);
	StrInsert(S,I,t);
}

void main()
{
	int loc,length;
	int flag=1;
	char j;
	char s2[100];
	pstring s,s1;//s，s1是两个串
	InitStr(s,100);//初始化串
	InitStr(s1,100);
	StrEvaluate(s,"abc");									//执行对串赋值操作
	StrEvaluate(s1,"abc");//执行对串赋值操作
//---------------------------程序解说--------------------------
 printf("本程序用来实现堆存储结构的串。\n");
 printf("可以实现查找、插入、删除等操作。\n");
 //-------------------------------------------------------------
  while(flag)
    { printf("请选择:\n");
      printf("1.显示所有元素\n");
      printf("2.串的连接\n");
      printf("3.字符串的比较  \n");
	  printf("4.求子串的位置  \n");
	  printf("5.字符串的插入\n");
      printf("6.字符串的删除  \n");
	  printf("7.字符串的替换  \n");
	  printf("8.退出 \n");
      scanf(" %c",&j);
      switch(j)
   {
   case '1':printf("%s\n",s->S); break; //显示所有元素
   case '2':{printf("串s为：%s\n串s1为：%s\n",s->S,s1->S);
			 StrConcat(s,s1);
             printf("连接后的字符串为：%s\n",s->S);//输出连接后的字符串
             break;
			}
   case '3':{printf("串s为：%s\n串s1为：%s\n",s->S,s1->S);
			 if(StrComp(s,s1))
				printf("s>s1\n");//s>s1
			 else
				printf("s<s1\n");//s<s1
             break;
			}
	case '4':{printf("请输入要求的子串：");
			 scanf("%s",s2);//输入子串
			 StrEvaluate(s1,s2);
			 printf("所求子串第一次出现的位置：%d\n",StrIndex(s,s1));//输出子串的位置StrIndex(s,s1)
             break;
			}
	case '5':{printf("请输入要插入位置:");
			scanf("%d",&loc);  //输入子串的开始位置,长度
			printf("请输入要插入的子串：");
			 scanf("%s",s2);//输入子串
			 StrEvaluate(s1,s2);
			printf("原来字符串为:%s\n",s->S);
			StrInsert(s,loc,s1);
			printf("插入后的字符串为:%s\n",s->S);
			break;
			}
	case '6':{printf("请输入要删除的串的开始位置,长度如2,3:");
			scanf("%d,%d",&loc,&length);  //输入子串的开始位置,长度
			printf("原来字符串为:%s\n",s->S);
			StrDelete(s,loc,length);
			printf("删除后的字符串为:%s\n",s->S);
			break;
			}
	case '7':printf("串s为：%s\n串s1为：%s\n",s->S,s1->S);
		StrReplace(s,2,1,s1);//执行串替换操作
		printf("将s从第2个位置开始长度为1的部分替换为s1，结果为：%s\n",s->S);
		break;
   default:flag=0;printf("程序结束，按任意键退出!\n");
   }
 }
}