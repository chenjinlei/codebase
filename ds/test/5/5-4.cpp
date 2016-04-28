#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
	char ch;
	struct Node * next;
}SString;
typedef SString * pstring;

void InitStr(pstring &S)
{
	S=(pstring)malloc(sizeof(pstring)); 							//给S分配空间
	S->next=NULL;
}


void StrEvaluate(pstring &S,char ch[])
{
	if(S->next!=NULL)										//S中若只有一个节点就不用清空
		S->next=NULL;	
	S->ch=ch[0];
	pstring s2=S;
	for(int i=1;ch[i]!='\0';i++)
	{
		pstring s1;
		InitStr(s1); 										//赋值前执行初始化操作
		s1->ch=ch[i];										//执行赋值操作
		s2->next=s1;										//链接上S1
		s2=s1;											//改变S2指针，指向S1
	}
}


void StrConcat(pstring &s,pstring t)
{
	pstring s1=s;
	while(s1->next!=NULL) 									//判断是否到串的尾部
		s1=s1->next;										//指针后移
	s1->next=t;
}

void ReadStr(pstring s)
{
	pstring s1=s;
	while(s1!=NULL) 										//当前串非空
	{
		printf("%c",s1->ch) ; 								//显示输出S1
		s1=s1->next; 										//指针后移
	}
	printf("\n");
}


int StrComp(pstring s1,pstring s2)
{
	pstring t1=s1;
	pstring t2=s2;
	while(t1!=NULL&&t2!=NULL)								//有个字符不相同或者到了链表尾部
	{
		if(t1->ch!=t2->ch)
			break;
		else 
		{
			t1=t1->next;
			t2=t2->next;
		}
	}
	if(t1==NULL&&t2!=NULL)
	return -1;												//t1先到末尾，t1<t2
	else if(t1!=NULL&&t2==NULL) 
	return 1;												//t2先到末尾，t1>t2
	else if(t1==NULL&&t2==NULL)	
	return 0;												//两个同时到达末尾
	else if(t1->ch<t2->ch)
	return -1;
	else if(t1->ch>t2->ch)
	return 1;
}


int GetLength(pstring s)
{
	pstring s1=s;
	int i=0;
	while(s1) 												//没有到串的尾部
	{
		s1=s1->next; 										//指针后移
		i++;												//保持长度的变量自增
	}
	return i; 												//返回表的长度
}

void SubStr(pstring s,int i,int length,pstring &substring)
{
	pstring s1;
	InitStr(s1);
	if(GetLength(s)<i+length-1)
	{
		printf("取子串越界!");		
	}
	else
	{
		pstring s2=s;
		int j=0;
		while(j<i)											//移到i位置处
		{
			s2=s2->next;
			j++;
		}
		s1->ch=s2->ch;
		pstring s3=s1;
		for(j=1;j<length;j++)									//从i位置处依次读取长为length的字符
		{
			s2=s2->next;
			pstring s4;
			InitStr(s4);
			s4->ch=s2->ch;	   
			s3->next=s4;
			s3=s4;
		}
	}
	substring=s1;
}

int StrIndex(pstring s,pstring t)
{
	char ch=t->ch;											//获取子串的首字符
	pstring s1=s;
	if(GetLength(s1)<GetLength(t))
	return -1;												//如果要查询的子串长度大于主串长度
	int i=0 ;												//说明在这个字符串s中不存在该子串t
	for(i=0;i<=GetLength(s1)-GetLength(t);i++,s1=s1->next)
	{	
		if(s1->ch==ch)										//找到S1首字符在字符串s中的位置
		{
			pstring strTemp;
			SubStr(s,i,GetLength(t),strTemp);
			if(StrComp(strTemp,t)==0)			//如果相等就返回当前位置
			{
				return i+1;
			}
		}
	}
	if(i>GetLength(s1)-GetLength(t))
	return -1;
}

void StrInsert(pstring &s,int i,pstring t)
{
	pstring s1=s;
	if(i>GetLength(s))
	{
		printf("插入位置超出字符串的长度!");
		return;
	}
	if(i==1)												//插入到第一个位置就是将t插入															//到s的前面
	{
		pstring t1=t;
		while(t1->next)
			t1=t1->next;
		t1->next=s;
		s=t;
	}
	else
	{
		for(int j=1;j<i-1;j++)									//插入的不是第一个位置
		{
			s1=s1->next; 
		}
		pstring s2=s1->next;
		pstring s3=t;
		while(s3->next)
			s3=s3->next;
		s3->next=s2;
		s1->next=t;
	}
}

void StrDelete(pstring &s,int i,int length)
	{														//从第一个位置删除就把链表的第一个
		if(i==1)												//结点指针往后移动
		{
			while(length--&&s)
				s=s->next;
		}
		else
		{
			pstring s1=s;
			i=i-1;
			while((--i)>0&&s1)
				s1=s1->next;
			pstring s2=s1;
			while((length--)>0&&s1)
				s1=s1->next;
			s2->next=s1->next;
		}
	}

void main()
{
	int loc,length;
	int flag=1;
	char j;
	char s2[100];
	pstring s,s1,substring;//s，s1是两个串
	InitStr(s);//初始化串
	InitStr(s1);
	InitStr(substring);
	StrEvaluate(s,"abc");									//执行对串赋值操作
	StrEvaluate(s1,"abc");//执行对串赋值操作
//---------------------------程序解说--------------------------
 printf("本程序用来实现链表存储结构的串。\n");
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
	  printf("7.字符串的长度  \n");
	  printf("8.取子串 \n");
	  printf("9.退出 \n");
      scanf(" %c",&j);
      switch(j)
   {
   case '1':ReadStr(s); break; //显示所有元素
   case '2':{printf("串s为：");
			 ReadStr(s);
			 printf("串s1为：");
			 ReadStr(s1);
			 StrConcat(s,s1);
             printf("连接后的字符串为：");//输出连接后的字符串
			 ReadStr(s);
             break;
			}
   case '3':{printf("串s为：");
			 ReadStr(s);
			 printf("串s1为：");
			 ReadStr(s1);
			 if(StrComp(s,s1)>0)
				printf("s>s1\n");//s>s1
			 else if(StrComp(s,s1)<0)
				printf("s<s1\n");//s<s1
			 else if(StrComp(s,s1)==0)
				 printf("s=s1\n");//s=s1
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
			printf("原来字符串为:");
			ReadStr(s);
			StrInsert(s,loc,s1);
			printf("插入后的字符串为:");
			ReadStr(s);
			break;
			}
	case '6':{printf("请输入要删除的串的开始位置,长度如2,3:");
			scanf("%d,%d",&loc,&length);  //输入子串的开始位置,长度
			printf("原来字符串为:");
			ReadStr(s);
			StrDelete(s,loc,length);
			printf("删除后字符串为:");
			ReadStr(s);
			break;
			}

	case '7':printf("串的长度为：%d\n",GetLength(s));
			break;
	case '8':printf("请输入子串的开始位置,长度如2,3:");
			scanf("%d,%d",&loc,&length);  //输入子串的开始位置,长度
			SubStr(s,loc,length,substring);
			printf("子串为：");
			ReadStr(substring);
			break;
   default:flag=0;printf("程序结束，按任意键退出!\n");
   }
 }
}