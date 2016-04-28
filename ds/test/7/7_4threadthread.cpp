#include <stdio.h>   
#include <stdlib.h>   
  
#define MAX 1500   
  
//����������   
typedef struct BiTreeNode{   
  char data;   
  BiTreeNode *lChild;   
  BiTreeNode *rChild;   
  int lTag,rTag;   
}BiTreeNode;   
  
//ȫ�ֱ���   
BiTreeNode *pre =NULL;   
BiTreeNode *point[MAX+1]; //����������ʱ���������ڶ�λ�ӽڵ�   
  
//����������   
BiTreeNode *CreateBiTree()   
{   
  BiTreeNode *root=(BiTreeNode *)malloc(sizeof(BiTreeNode));   
  int i,j;char data;   
  printf("input i,data: i mod 2==0Ϊ���ӽ��\n");
  scanf("%d,%c",&i,&data);   
  while(i!=0&&data!='#')   
  {   
    BiTreeNode *newNode=(BiTreeNode *)malloc(sizeof(BiTreeNode));   
    newNode->data=data;   
    newNode->lTag=0;newNode->rTag=0;   
    newNode->lChild=NULL;newNode->rChild=NULL;   
    point[i]=newNode;    
    if(i==1)    //Ϊ���������ڵ�   
    {   
      root=point[1];   
    }   
    else  
    {   
      j=i/2;   
     if(i%2==0)   //Ϊ���ӽ��   
     {   
        point[j]->lChild=newNode;   
      }   
      else  
     {   
        point[j]->rChild=newNode;   
      }   
     }   
     scanf("%d,%c",&i,&data);   
  }   
  return root;   
}   
  
//����������������,pre��ʼ��ΪNULL   
void Inthread(BiTreeNode *root)   
{   
  if(root!=NULL)   
  {     
     Inthread(root->lChild);   
     if(root->lChild==NULL)   
     {   
      root->lTag=1;root->lChild=pre;   
     }   
     if(pre!=NULL&&pre->rChild==NULL)   
     {   
      pre->rTag=1;pre->rChild=root;   
     }   
     pre=root;   
     Inthread(root->rChild);   
  }   
}   
  
  
//���ҽ��p��ǰ�����   
BiTreeNode *InPre(BiTreeNode *p)   
{   
  if(p->lTag==1)return p->lChild;   
  BiTreeNode *q=p->lChild;   
  if(q==NULL){   
     printf("��ǰ�����\n");   
     return NULL;   
  }   
  while(q->rTag!=1)   
  {   
    q=q->rChild;   
  }   
  return q;   
}   
  
//���ҽ��p�ĺ�̽��   
BiTreeNode *InSub(BiTreeNode *p)   
{   
  if(p->rTag==1)return p->rChild;   
  BiTreeNode *q=p->rChild;   
  if(q==NULL){   
     printf("�޺�̽��\n");   
     return NULL;   
  }   
  while(q->lTag!=1)   
  {   
    q=q->lChild;   
  }   
  return q;   
}   
  
  
int main()   
{   
  char cmd;int index;   
  do{   
     BiTreeNode *root=CreateBiTree();   
     Inthread(root);   
     printf("������Ҫ���ҵĽ��,���index\n");   
     scanf("%d",&index);   
     BiTreeNode *nodePre=InPre(point[index]);   
     BiTreeNode *nodeSub=InSub(point[index]);   
     if(nodePre!=NULL)   
        printf("���%d��ǰ������ֵΪ:%c\n",index,nodePre->data);   
     if(nodeSub!=NULL)  
		 printf("���%d�ĺ�̽���ֵΪ:%c\n",index,nodeSub->data); 
         
     printf("������Y/y?\n");   
     scanf("%c",&cmd);   
  }while(cmd=='Y'||cmd=='y');   
  return 0;   
}  