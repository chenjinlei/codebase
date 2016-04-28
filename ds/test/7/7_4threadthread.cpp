#include <stdio.h>   
#include <stdlib.h>   
  
#define MAX 1500   
  
//二叉树定义   
typedef struct BiTreeNode{   
  char data;   
  BiTreeNode *lChild;   
  BiTreeNode *rChild;   
  int lTag,rTag;   
}BiTreeNode;   
  
//全局变量   
BiTreeNode *pre =NULL;   
BiTreeNode *point[MAX+1]; //构建二叉树时辅助，用于定位子节点   
  
//构建二叉树   
BiTreeNode *CreateBiTree()   
{   
  BiTreeNode *root=(BiTreeNode *)malloc(sizeof(BiTreeNode));   
  int i,j;char data;   
  printf("input i,data: i mod 2==0为左孩子结点\n");
  scanf("%d,%c",&i,&data);   
  while(i!=0&&data!='#')   
  {   
    BiTreeNode *newNode=(BiTreeNode *)malloc(sizeof(BiTreeNode));   
    newNode->data=data;   
    newNode->lTag=0;newNode->rTag=0;   
    newNode->lChild=NULL;newNode->rChild=NULL;   
    point[i]=newNode;    
    if(i==1)    //为二叉树根节点   
    {   
      root=point[1];   
    }   
    else  
    {   
      j=i/2;   
     if(i%2==0)   //为左孩子结点   
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
  
//中序线索化二叉树,pre初始化为NULL   
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
  
  
//查找结点p的前驱结点   
BiTreeNode *InPre(BiTreeNode *p)   
{   
  if(p->lTag==1)return p->lChild;   
  BiTreeNode *q=p->lChild;   
  if(q==NULL){   
     printf("无前驱结点\n");   
     return NULL;   
  }   
  while(q->rTag!=1)   
  {   
    q=q->rChild;   
  }   
  return q;   
}   
  
//查找结点p的后继结点   
BiTreeNode *InSub(BiTreeNode *p)   
{   
  if(p->rTag==1)return p->rChild;   
  BiTreeNode *q=p->rChild;   
  if(q==NULL){   
     printf("无后继结点\n");   
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
     printf("输入您要查找的结点,序号index\n");   
     scanf("%d",&index);   
     BiTreeNode *nodePre=InPre(point[index]);   
     BiTreeNode *nodeSub=InSub(point[index]);   
     if(nodePre!=NULL)   
        printf("结点%d的前驱结点的值为:%c\n",index,nodePre->data);   
     if(nodeSub!=NULL)  
		 printf("结点%d的后继结点的值为:%c\n",index,nodeSub->data); 
         
     printf("继续吗Y/y?\n");   
     scanf("%c",&cmd);   
  }while(cmd=='Y'||cmd=='y');   
  return 0;   
}  