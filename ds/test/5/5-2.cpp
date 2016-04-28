#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
typedef struct
{
	char S[MAXSIZE];
}SString;

void InitStr(SString &str)
{
	for(int i=0;i<MAXSIZE;i++)				//从第一个元素到最后元素初始化为'\0'
	{
		str.S[i]='\0';
	}
}

int GetLength(SString s)
{
	int length=0;
	while(s.S[length]!='\0')							//只要字符的值不是’\0’，length的值加1
		length++;
	return length;
}

void StrEvaluate(SString &S1,char S2[])	//char S2[]是字符数组一个字符串常量
{
	if(GetLength(S1))
		InitStr(S1);										//对S1初始化
	for(int i=0;S2[i]!='\0';i++)									//从第一个元素开始对S1进行赋值
		S1.S[i]=S2[i];
}

/*void StrEvaluate(SString &S1,char S2[])
  {
  for(int i=0;S2[i]!='\0';i++)									//从第一个元素开始对S1进行赋值			S1.S[i]=S2[i];
  }*/

void StrCopy(SString &S1,SString S2)
{
	if(GetLength(S1))										//如果S1的长度为0，那么就不初始化
		InitStr(S1);
	for(int i=0;i<=GetLength(S2);i++)							//从第一个元素起将S2的字符赋给S1
		S1.S[i]=S2.S[i];
}

void StrConcat(SString &S1,SString S2)
{
	int len1=GetLength(S1);
	int len2=GetLength(S2);
	if((len1+len2+1)>MAXSIZE)								//留一个空间来存放'\0'所以要+1				
		printf("%s","长度超过最大长度将会截取部分字符串！");
	for(int i=len1;i<len1+len2&&i<MAXSIZE;i++)					//判断是否需要截取串
		S1.S[i]=S2.S[i-len1];
}

SString SubStr(SString S,int i,int length)
{
	SString S1;
	InitStr(S1);											//初始化要返回的子串
	if(i+length>GetLength(S)+1||i<=0)							//判断子串长度是否合法
	{
		printf("%s","所取子串已超出主串的长度!子串获取失败!");
	}
	else
	{
		for(int j=i-1;j<i+length-1;j++)							//执行取字串操作
			S1.S[j+1-i]=S.S[j];
	}
	return S1;
}

int StrComp(SString S1,SString S2)
{
	int i=0;
	while(S1.S[i]==S2.S[i]&&S1.S[i]!='\0')						//字符不同或出现‘\0’停止比较
	{
		i++;
	}
	if(S1.S[i]<S2.S[i])
		return -1;
	else if(S1.S[i]>S2.S[i])
		return 1;
	return 0;
}


int StrIndex(SString S,SString S1)
{
	if(GetLength(S1)>GetLength(S)) 
		return -1;												//判断子串长度是否合法
	int i=0 ;												//定义返回位置变量
	char ch=S1.S[0];										//获取子串的首字符
	for(i=0;i<=GetLength(S)-GetLength(S1);i++)
	{
		if(S.S[i]==ch)										//找到S1首字符在字符串S中的位置
			if(StrComp(SubStr(S,i+1,GetLength(S1)),S1)==0)		//如果相等就返回当前位置
				return i+1;
	}
	if(i>GetLength(S)-GetLength(S1))
		return -1;
}

void StrInsert(SString &S,int i,SString t)
{
	if(GetLength(S)+GetLength(t)>=MAXSIZE)					//判断长度是否合法
	{
		printf("%s","超出数组的最大容量!");
		return;
	}
	if(i>GetLength(S)+1)										//判断插入位置是否合法
	{
		printf("%s","插入位置超出数组的长度!"); 
		return;
	}
	SString S1;
	InitStr(S1);
	StrCopy(S1,t);											//将t复制给一个变量S1
	StrConcat(S1,SubStr(S,2,GetLength(S)-i+1));					//将S从i后面的子串连接到S1尾部
	SString S2;
	InitStr(S2);	
	S2=SubStr(S,1,i-1);										//将s的前半部分子串复制到S2中
	StrConcat(S2,S1);										//将S1连接到S2的尾部
	StrCopy(S,S2);											//将S2复制到S中完成插入
}

void StrDelete(SString &S,int i,int length)
{
	if((i+length)>GetLength(S)+1)								//删除下标超出字符串范围不可删除
	{
		printf("%s","删除下标超出字符串范围!");
		return;
	}
	SString S1,S2;
	InitStr(S1);
	InitStr(S2);
	StrCopy(S1,SubStr(S,1,i-1)); 								//取出要删除地方的前面子串
	StrCopy(S2,SubStr(S,i+length,GetLength(S)-i-length+1));			//获取要删除子串的后半部分子串
	StrConcat(S1,S2);										//将获取的两部分子串连接起来
	StrCopy(S,S1);											//删除掉那部分子串
}

void StrReplace(SString &S,int I,int length,SString t)
{
	StrDelete(S,I,length);
	StrInsert(S,I,t);
}

void main()
{
	int loc,length;
	int flag=1;
	char j,ch;
	SString s,s1;//s，s1是两个串
	InitStr(s);//初始化串
	InitStr(s1);
	StrEvaluate(s,"abc");									//执行对串赋值操作
	StrEvaluate(s1,"abc");//执行对串赋值操作
	//---------------------------程序解说--------------------------
	printf("本程序用来实现顺序结构的串。\n");
	printf("可以实现查找、插入、删除等操作。\n");
	//-------------------------------------------------------------
	while(flag)
	{ printf("请选择:\n");
		printf("1.显示所有元素\n");
		printf("2.求字符串的长度\n");
		printf("3.求字符串的子串\n");
		printf("4.串的连接\n");
		printf("5.字符串的比较  \n");
		printf("6.求子串的位置  \n");
		printf("7.字符串的插入\n");
		printf("8.字符串的删除  \n");
		printf("9.字符串的替换  \n");
		printf("10.退出 \n");
		scanf(" %c",&j);
		switch(j)
		{
		case '1':printf("%s\n",s.S); break; //显示所有元素
		case '2':printf("长度为：%d\n",GetLength(s)); break;//求串长     
		case '3':{printf("请输入子串的开始位置,长度如2,3:");
			scanf("%d,%d",&loc,&length);  //输入子串的开始位置,长度
			printf("所求子串为：%s\n",SubStr(s,loc,length).S);//求子串SubStr(s,loc,length)
			break;
		}
		case '4':{printf("串s为：%s\n串s1为：%s\n",s.S,s1.S);
			StrConcat(s,s1);
			printf("连接后的字符串为：%s\n",s.S);//输出连接后的字符串
			break;
		}
		case '5':{printf("串s为：%s\n串s1为：%s\n",s.S,s1.S);
			if(StrComp(s,s1))
				printf("s>s1\n");//s>s1
			else
				printf("s<s1\n");//s<s1
			break;
		}
		case '6':{printf("请输入要求的子串：");
			scanf("%s",s1.S);//输入子串
			printf("所求子串第一次出现的位置：%d\n",StrIndex(s,s1));//输出子串的位置StrIndex(s,s1)
			break;
		}
		case '7':{printf("请输入要插入位置:");
			scanf("%d",&loc);  //输入子串的开始位置,长度
			printf("请输入要插入的子串：");
			scanf("%s",s1.S);//输入要插入的字符串
			printf("原来字符串为:%s\n",s.S);
			StrInsert(s,loc,s1);
			printf("插入后的字符串为:%s\n",s.S);
			break;
		}
		case '8':{printf("请输入要删除的串的开始位置,长度如2,3:");
			scanf("%d,%d",&loc,&length);  //输入子串的开始位置,长度
			printf("原来字符串为:%s\n",s.S);
			StrDelete(s,loc,length);
			printf("删除后的字符串为:%s\n",s.S);
			break;
		}
		case '9':printf("串s为：%s\n串s1为：%s\n",s.S,s1.S);
			 StrReplace(s,2,1,s1);//执行串替换操作
			 printf("将s从第2个位置开始长度为1的部分替换为s1，结果为：%s\n",s.S);
			 break;
		default:flag=0;printf("程序结束，按任意键退出!\n");
		}
	}
}
