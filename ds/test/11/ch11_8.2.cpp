#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define NULL 0 
unsigned int key; 
unsigned int key2; 
int *p; 
struct node //���ڵ� 
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

//�绰�����ϣ����
void hash(char num[11])  
{ 
	//printf("��hash�����ڲ�ִ��");
    int i = 2; 
    key=(int)num[1];
 
    while(num[i]!=NULL) 
	{ 
		key+=(int)num[i]; 
        i++; 
	} 
    key=key%20;
}
//�ٹ�ϣ����
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
 //�绰�����ͻ����
 node *q=phone[key]->next;
 while((q->name)!=NULL)
 {
  key=key+1;
  q=phone[key]->next;
 }
}

//������ͻ����
void clash2()
{
 node *q=nam[key2]->next;
 while((q->name)!=NULL)
 {
  key2=key2+1;
  q=nam[key2]->next;
 }
}

//������ϣ���� 
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

node* input() //����ڵ� 
{ 
 //printf("�ɹ�ִ��");
 node *temp; 
 temp = new node; 
 temp->next=NULL; 
 printf("����������\n");
 
 scanf("%s",&(temp->name));
 printf("�����ַ��\n");
 
 scanf("%s",&(temp->address));
 printf("����绰��\n");
 
 scanf("%s",&(temp->num)); 
 return temp; 
} 

int apend() //��ӽڵ� 
{ 
 node *newphone; 
 node *newname; 
 newphone=input(); 
 newname=newphone; 
 newphone->next=NULL; 
 newname->next=NULL; 
 hash(newphone->num);
 //�绰�����ͻ����
 clash();
 hash2(newname->name);
 printf("�绰�����ͻ�����key��ֵ��%d\n",key);
 //������ͻ����
 clash2();
 printf("������ͻ�����key��ֵ��%d\n",key2);
 newphone->next = phone[key]->next; 
 phone[key]->next=newphone; 
 newname->next = nam[key2]->next; 
 nam[key2]->next=newname; 
 return 0; 
} 

void create() //�½��ڵ� 
{ 
 int i; 
 phone=new pnode[20]; 
 for(i=0;i<20;i++) 
 { 
  phone[i]=new node; 
  phone[i]->next=NULL; 
 } 
} 
void create2() //�½��ڵ� 
{ 
 int i; 
 nam=new mingzi[20]; 
 for(i=0;i<20;i++) 
 { 
  nam[i]=new node; 
  nam[i]->next=NULL; 
 } 
} 
void list() //��ʾ�б� 
{ 
 int i; 
 node *p; 
 for(i=0;i<20;i++) 
 { 
  p=phone[i]->next; 
  while(p) 
  { 
   
   printf("\n\n|----------------------------|\n");
   printf("������%s\n",p->name); 
   printf("��ַ��%s\n",p->address);
   printf("�绰��%s\n",p->num);
   printf("|----------------------------|\n\n\n");
   p=p->next; 
  } 
 } 
} 
void list2() //��ʾ�б� 
{ 
 int i; 
 node *p; 
 for(i=0;i<20;i++) 
 { 
  p=nam[i]->next; 
  while(p) 
  { 
   
   printf("\n\n|----------------------------|\n");
   printf("������%s\n",p->name); 
   printf("��ַ��%s\n",p->address);
   printf("�绰��%s\n",p->num);
   printf("|----------------------------|\n\n\n");
   p=p->next; 
  } 
 } 
} 

void find(char num[11]) //�����û���Ϣ 
{ 
 hash(num);
 //printf("key��ֵ��%d",key);
 //printf("����ִ��hash����");
 node *q=phone[key]->next; 
 while(q!= NULL) 
 { 
  if(strcmp(num,q->num)==0) 
   break; 
  q=q->next; 
 } 
 //printf("�Ƿ�����жϣ�\n");
 if(q) 
 
 {
  //printf("�ǣ��жϳɹ�");
  printf("\n\n|----------------------------|\n");
  printf("������%s\n",q->name);
  printf("��ַ��%s\n",q->address);
  printf("�绰��%s\n",q->num);
  printf("|----------------------------|\n\n\n"); 
 }
 else 
  
  printf("\n�޴˼�¼\n\n");
} 

//�绰�����ͻ�����Ĳ���

void find01(char num[11])
{
 hash(num);
 node *p=phone[key]->next;
 if(p==NULL)
 {
  printf("\n�޴˼�¼\n\n");
 }
 else
 {
  while(p!=NULL)
  {
  if(strcmp(num,p->num)==0)
   {
    printf("\n\n|----------------------------|\n");
    printf("������%s\n",p->name); 
    printf("��ַ��%s\n",p->address);
    printf("�绰��%s\n",p->num);
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
void find2(char name[20]) //�����û���Ϣ 
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
  printf("������%s\n",q->name); 
  printf("��ַ��%s\n",q->address);
  printf("�绰��%s\n",q->num);
  printf("|----------------------------|\n\n\n");
 } 
 else 
  
  printf("\n�޴˼�¼\n\n");
} 

//������ͻ�����Ĳ���
void find02(char name[20])
{
 hash(name);
 node *q=nam[key2]->next;
 if(q== NULL)
 {
  printf("\n�޴˼�¼\n\n");
 }
 else
 {
  while(q!= NULL)
  {
  if(strcmp(name,q->name)==0)
   {
    printf("\n\n|----------------------------|\n");
    printf("������%s\n",q->name); 
    printf("��ַ��%s\n",q->address);
    printf("�绰��%s\n",q->num);
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


//�˵� 
void menu() 
{ 
 printf("\n|----------------------------|\n");
 printf("|----1.��Ӽ�¼--------------|\n");
 printf("|----2.���Ҽ�¼--------------|\n");
 printf("|----3.����ɢ��--------------|\n");
 printf("|----4.����ɢ��--------------|\n");
 printf("|----5.��ռ�¼--------------|\n");
 printf("|----6.�˳�ϵͳ--------------|\n"); 
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
   printf("9�����ѯ\n8������ѯ\n");
   int b; 
   
   scanf("%d",&b);
   if(b==9) 
   { 
    printf("������绰����:\n");
    
    scanf("%s",&num);
    
    printf("\n������ҵ���Ϣ:\n\n");
    find01(num); 
   } 
   else 
   { 
    printf("����������:\n");
    
    scanf("%s",&name);
    
    printf("\n������ҵ���Ϣ:\n\n"); 
    find02(name);
   } 
  } 
  if(sel==3) 
  { 
   printf("����ɢ�н��:\n");
   list2(); 
  } 
  if(sel==1) 
  { 
   printf("������Ҫ��ӵ�����:\n");
   apend(); 
  } 
  if(sel==4) 
  { 
   printf("����ɢ�н��:\n");
   list(); 
  } 
  if(sel==5) 
  { 
   printf("�б������:\n");
   create(); 
   create2(); 
  } 
  if(sel==6) return 0; 
 } 
 return 0; 
 
}
