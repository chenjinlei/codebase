#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define NULL 0 
unsigned int key; 
unsigned int key2; 
int *p; 
struct node //建节点 
{ 
 char name[20],address[50]; 
 char num[11]; 
 node * next; 
}; 

typedef node* pnode; 
typedef node* mingzi; 
node **phone; 
node **nam; 
node *a; 

//电话号码哈希函数
void hash(char num[11])  
{ 
	//printf("在hash函数内部执行");
    int i = 2; 
    key=(int)num[1];
 
    while(num[i]!=NULL) 
	{ 
		key+=(int)num[i]; 
        i++; 
	} 
    key=key%20;
}
//再哈希函数
void rehash(char num[11])
{
	int i=1;
    key=(int)num[0];
    while(num[i]!=NULL)
	{
		key+=(int)num[i];
		i++;
	}
    key=(key+i)%20;
}

bool reclash()
{
	node *q=phone[key]->next;
    if((q->name)!=NULL)return true;
    else return false;
}

void clash()
{
 //电话号码冲突处理
 node *q=phone[key]->next;
 while((q->name)!=NULL)
 {
  key=key+1;
  q=phone[key]->next;
 }
}

//姓名冲突处理
void clash2()
{
 node *q=nam[key2]->next;
 while((q->name)!=NULL)
 {
  key2=key2+1;
  q=nam[key2]->next;
 }
}

//姓名哈希函数 
void hash2(char name[20]) 
{ 
 int i=1; 
 key2=(int)name[0]; 
 while(name[i]!=NULL) 
 { 
  key2+=(int)name[i]; 
  i++; 
 } 
 key2=key2%20; 
} 

node* input() //输入节点 
{ 
 //printf("成功执行");
 node *temp; 
 temp = new node; 
 temp->next=NULL; 
 printf("输入姓名：\n");
 
 scanf("%s",&(temp->name));
 printf("输入地址：\n");
 
 scanf("%s",&(temp->address));
 printf("输入电话：\n");
 
 scanf("%s",&(temp->num)); 
 return temp; 
} 

int apend() //添加节点 
{ 
 node *newphone; 
 node *newname; 
 newphone=input(); 
 newname=newphone; 
 newphone->next=NULL; 
 newname->next=NULL; 
 hash(newphone->num);
 //电话号码冲突处理
 clash();
 hash2(newname->name);
 printf("电话号码冲突处理后key的值：%d\n",key);
 //姓名冲突处理
 clash2();
 printf("姓名冲突处理后key的值：%d\n",key2);
 newphone->next = phone[key]->next; 
 phone[key]->next=newphone; 
 newname->next = nam[key2]->next; 
 nam[key2]->next=newname; 
 return 0; 
} 

void create() //新建节点 
{ 
 int i; 
 phone=new pnode[20]; 
 for(i=0;i<20;i++) 
 { 
  phone[i]=new node; 
  phone[i]->next=NULL; 
 } 
} 
void create2() //新建节点 
{ 
 int i; 
 nam=new mingzi[20]; 
 for(i=0;i<20;i++) 
 { 
  nam[i]=new node; 
  nam[i]->next=NULL; 
 } 
} 
void list() //显示列表 
{ 
 int i; 
 node *p; 
 for(i=0;i<20;i++) 
 { 
  p=phone[i]->next; 
  while(p) 
  { 
   
   printf("\n\n|----------------------------|\n");
   printf("姓名：%s\n",p->name); 
   printf("地址：%s\n",p->address);
   printf("电话：%s\n",p->num);
   printf("|----------------------------|\n\n\n");
   p=p->next; 
  } 
 } 
} 
void list2() //显示列表 
{ 
 int i; 
 node *p; 
 for(i=0;i<20;i++) 
 { 
  p=nam[i]->next; 
  while(p) 
  { 
   
   printf("\n\n|----------------------------|\n");
   printf("姓名：%s\n",p->name); 
   printf("地址：%s\n",p->address);
   printf("电话：%s\n",p->num);
   printf("|----------------------------|\n\n\n");
   p=p->next; 
  } 
 } 
} 

void find(char num[11]) //查找用户信息 
{ 
 hash(num);
 //printf("key的值是%d",key);
 //printf("可以执行hash函数");
 node *q=phone[key]->next; 
 while(q!= NULL) 
 { 
  if(strcmp(num,q->num)==0) 
   break; 
  q=q->next; 
 } 
 //printf("是否进行判断？\n");
 if(q) 
 
 {
  //printf("是，判断成功");
  printf("\n\n|----------------------------|\n");
  printf("姓名：%s\n",q->name);
  printf("地址：%s\n",q->address);
  printf("电话：%s\n",q->num);
  printf("|----------------------------|\n\n\n"); 
 }
 else 
  
  printf("\n无此记录\n\n");
} 

//电话号码冲突处理后的查找

void find01(char num[11])
{
 hash(num);
 node *p=phone[key]->next;
 if(p==NULL)
 {
  printf("\n无此记录\n\n");
 }
 else
 {
  while(p!=NULL)
  {
  if(strcmp(num,p->num)==0)
   {
    printf("\n\n|----------------------------|\n");
    printf("姓名：%s\n",p->name); 
    printf("地址：%s\n",p->address);
    printf("电话：%s\n",p->num);
    printf("|----------------------------|\n\n\n");
    
  
   }
  if(key<20)
   {
    key=key+1;
   }
  p=phone[key]->next;
  }
 }

}
void find2(char name[20]) //查找用户信息 
{ 
 hash2(name); 
 node *q=nam[key2]->next;
 while(q!= NULL) 
 { 
  if(strcmp(name,q->name)==0) 
   break; 
  q=q->next; 
 } 
 if(q) 
  
 {
  printf("\n\n|----------------------------|\n");
  printf("姓名：%s\n",q->name); 
  printf("地址：%s\n",q->address);
  printf("电话：%s\n",q->num);
  printf("|----------------------------|\n\n\n");
 } 
 else 
  
  printf("\n无此记录\n\n");
} 

//姓名冲突处理后的查找
void find02(char name[20])
{
 hash(name);
 node *q=nam[key2]->next;
 if(q== NULL)
 {
  printf("\n无此记录\n\n");
 }
 else
 {
  while(q!= NULL)
  {
  if(strcmp(name,q->name)==0)
   {
    printf("\n\n|----------------------------|\n");
    printf("姓名：%s\n",q->name); 
    printf("地址：%s\n",q->address);
    printf("电话：%s\n",q->num);
    printf("|----------------------------|\n\n\n");
   }
  if(key2>0)
   {
    key2=key2-1;
   }
  q=nam[key2]->next;
  }
 }

}


//菜单 
void menu() 
{ 
 printf("\n|----------------------------|\n");
 printf("|----1.添加记录--------------|\n");
 printf("|----2.查找记录--------------|\n");
 printf("|----3.姓名散列--------------|\n");
 printf("|----4.号码散列--------------|\n");
 printf("|----5.清空记录--------------|\n");
 printf("|----6.退出系统--------------|\n"); 
 printf("|----------------------------|\n");
} 

int main() 
{ 
 char num[11]; 
 char name[20]; 
 
 create(); 
 create2() ; 
 
 int sel; 
 while(1) 
 { 
  menu();
  
  
  scanf("%d",&sel);
  if(sel==2) 
  { 
   printf("9号码查询\n8姓名查询\n");
   int b; 
   
   scanf("%d",&b);
   if(b==9) 
   { 
    printf("请输入电话号码:\n");
    
    scanf("%s",&num);
    
    printf("\n输出查找的信息:\n\n");
    find01(num); 
   } 
   else 
   { 
    printf("请输入姓名:\n");
    
    scanf("%s",&name);
    
    printf("\n输出查找的信息:\n\n"); 
    find02(name);
   } 
  } 
  if(sel==3) 
  { 
   printf("姓名散列结果:\n");
   list2(); 
  } 
  if(sel==1) 
  { 
   printf("请输入要添加的内容:\n");
   apend(); 
  } 
  if(sel==4) 
  { 
   printf("号码散列结果:\n");
   list(); 
  } 
  if(sel==5) 
  { 
   printf("列表已清空:\n");
   create(); 
   create2(); 
  } 
  if(sel==6) return 0; 
 } 
 return 0; 
 
}
