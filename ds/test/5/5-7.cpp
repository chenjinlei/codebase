#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
typedef struct Node
{
	struct Node * next;										//下一行的起始位置
	char S[MAXSIZE];										//一行只允许100个字符
}HNode;
typedef HNode * pHNode;

void Insert(pHNode &p,int row,char *s)						 //row要插入的位置，s要插入的内容
{
	if(row<1)												//插入时最低要从第一行开始插入
	{
		printf("输入行号不可小于1！");
		return;
	}
	else if(p==NULL&&row!=1)								//如果p为NULL只能从第一行插入
	{
		printf("目前没有任何行，只能插入到第一行！"); 
		return;
	}
	else if(p==NULL&&row==1)								//如果p为NULL，插入到第一行的操作
	{
		p=(pHNode)malloc(sizeof(pHNode));
		p->next=NULL;
		int i=0;
		while(s[i]!='\0')									 //为结点赋值
		{
			p->S[i]=s[i]; 
			i++;
		}
		p->S[i]='\0';
		return; 
	}
	pHNode p3=(pHNode)malloc(sizeof(pHNode)); 				//为新结点分配空间
	int i=0;
	while(s[i]!='\0')										//为结点赋值
	{
		p3->S[i]=s[i]; 
		i++;
	}
	p3->S[i]='\0';
	if(p!=NULL&&row==1)									    //p不为NULL，插入到第一行
	{
		p3->next=p;
		p=p3;
		return;
	}
														     //其他情况
	pHNode p1=p;
	i=1;
	while(i<row-1&&p1->next)								 //若行数超过所最大行数插到最后一行
	{
		i++;
		p1=p1->next;
	}	
	p3->next=p1->next;
	p1->next=p3;
}

void del(pHNode &p,int row)									//删除行，row为要删除的行号
{
	if(row<1)												//插入时最低要从第一行开始插入
	{
		printf("输入行号不可小于1!");
		return;
	}
	if(row==1&&p)											//如果删除的是第一行
	{
		p=p->next;
		return;
	}
	pHNode p1=p;
	int i=1;
	while(i<row-1&&p1)										//行数超过最大行数
	{
		i++;
		p1=p1->next;
	}
	if(p1==NULL)
	{
		printf("删除的行号越界!");
		return;
	}
	p1->next=p1->next->next;
}


void row_insert(char *s,int i,char *s1)							//s要编辑的字符串，i插入的位置，s1														//插入的字符串
{
	char s2[MAXSIZE];
	int j=0;
	while(s[j]!='\0'&&j+1<i)									//截取前半部分字符
	{
		s2[j]=s[j];
		j++;
	}
	if(s[j]=='\0')
	{
		printf("插入位置超过本行字符数!");
		return;
	}
	int k=0,n=j;
	while(s1[k]!='\0')										//将要插入的字符赋给指定的位置
	{
		s2[n]=s1[k];
		k++;
		n++;
	}
	while(s[j]!='\0')											//连接后面的字符串 
	{
		s2[n]=s[j];
		n++;
		j++;
	}
	s2[n]='\0';
  	j=0;
	while(s2[j]!='\0')
	{
		s[j]=s2[j];											//将截取的字符串赋给s
		j++;
	}
	s[j]='\0'; 
}

void row_del(char *s,int i,int length) //s要编辑的字符串，i删除的起始位置，length删除的长度
{

	char s1[MAXSIZE];
	int j=0;
	while(s[j]!='\0'&&j+1<i)									//截取前半部分字符
	{
		s1[j]=s[j];
		j++;
	}
	if(s[j]=='\0')
	{
		printf("删除起始位置超过本行字符数!");
		return;
	}
	int k=j+1;
	while(k<i+length-1&&s[k]!='\0')								//跳过要删除的那部分字符
		k++;
	if(s[k]=='\0')
	{
		printf("删除结束位置超过本行字符数!");
		return;
	}
	
	while(s[k]!='\0')											//截取后半部分字符
	{
		s1[j]=s[k];
		j++;
		k++;
	}
	s1[j]='\0';												//最后赋'\0'
	j=0;
	while(s1[j]!='\0')
	{
		s[j]=s1[j];											//将截取的字符串赋给s
		j++;
	}
	s[j]='\0'; 
}

void row_edit(pHNode &p,int row,int choose)						//choose为0时执行删除操作，choose														//为1时执行插入操作
{
	int r=1;
	while(r<row&&p)										//移动到要编辑的行
	{
		p=p->next;
		r++;
	}
	if(choose==0)											//删除操作
	{
		printf("输入要删除的起始字符的位置\n");
		int i,length;
		scanf("%d",&i);
		if(i<1)
		{
			printf("\n删除的开始字符位置不能小于1!");
			return;
		}
		
		printf("输入要删除的长度\n");
		scanf("%d",&length);
		row_del(p->S,i,length);								//将要编辑行的字符串以及必要信息传														//入row_del
	}
	if(choose==1)											//插入操作
	{
		printf("输入要插入的位置\n");
		int i;
		scanf("%d",&i);
		if(i<1)
		{
			printf("\n插入的开始字符位置不能小于1!");
			return;
		}
		char *s="wer";										//要插入的字符串
		row_insert(p->S,i,s);									//将待编辑行字符串等信息插入
	}
}


void main()
{
	pHNode text=NULL,text1;
	int row;
	//Insert(text,1,"fyfyugtu");
	//Insert(text,1,"fyfyugtu");
	int flag=1,select;
	char j;
	char s[MAXSIZE];
//---------------------------程序解说--------------------------
  printf("行编辑操作\n");
 //-------------------------------------------------------------
  while(flag)
    { printf("\n请选择:\n");
      printf("1.显示所有文本\n");
      printf("2.插入一行文本\n");
      printf("3.文本编辑\n");
      printf("4.删除文本\n");
      printf("5.退出  \n");
	  scanf(" %c",&j);
      switch(j)
   {
   case '1':
			printf("\n");
			text1=text;
			while(text1!=NULL)
			{
				printf("%s\n",text1->S);
				text1=text1->next;
			}
			break; //显示所有元素
   case '2':
			printf("请输入要插入行的位置："); 
			scanf("%d",&row);
			printf("请输入要插入的内容:");
			scanf("%s",s);
			Insert(text,row,s);
			break;     
   case '3':
			printf("请输入要编辑的行："); 
			scanf("%d",&row);
			printf("请选择:\n0.删除\n1.插入\n输入你的选择");
			scanf("%d",&select);
			row_edit(text,row,select);
			break;    
   case '4':
			printf("请输入要删除的行："); 
			scanf("%d",&row);
			del(text,row);
			break;
   default:flag=0;printf("程序结束，按任意键退出!\n");
   }
 }

}