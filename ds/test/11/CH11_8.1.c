#include   <stdlib.h> 
#include   <stdio.h> 

#define   NULL   0 

typedef   int   KeyType; 

typedef   struct   { 	
	KeyType   key;   	
}ElemType;       //元素类型（其他数据项略，读者可根据实际情况加入）

typedef   struct   BiTNode{ 	
	ElemType   data; 	
	struct   BiTNode   *lchild,*rchild; 	
}BiTNode,*BiTree; 

BiTree   searchBST(BiTree   bt,KeyType   key){ 	
	//在二叉排序树   bt   中查找其关键字等于给定值的结点是否存在，并输出相应信息	
	if   (bt==NULL)   return   NULL; 	
	else   if   (bt-> data.key==key)   return   bt; 
	else   if   (key <bt-> data.key)   return   searchBST(bt-> lchild,key); 	
	else   return   searchBST(bt-> rchild,key); 	
} 

void   insertBST(BiTree  *bt,BiTree  s){ 	
	//在二叉排序树中插入一个新结点	
	if   (*bt==NULL)   *bt=s; 	
	else   if   (s-> data.key <(*bt)-> data.key)   insertBST(&((*bt)-> lchild),s); 	
	else   if   (s-> data.key> (*bt)-> data.key)   insertBST(&((*bt)-> rchild),s); 	
} 

void   inorder(BiTree   bt){ 	
	//对已经建立好的二叉排序树进行中序遍历，将得到一个按关键字有序的元素序列	
	if   (bt!=NULL){ 		
		inorder(bt-> lchild); 		
		printf( "%5d ",(bt->data).key); 		
		inorder(bt-> rchild); 		
	} 	
} 

void main(){ 
	char ch;
    KeyType   key; 	
    BiTree   bt,s; 	
    int   i=0; 	
	//建立一棵二叉排序树，元素值从键盘输入，直到输入关键字等于-1为止	
    printf( "\nPlease   input   data(-1:end)\n "); 	
    scanf( "%d ",&key); 	
    bt=NULL; 	
	while   (key!=-1){         		
		s=(BiTree)malloc(sizeof(BiTNode)); 		
		(s-> data).key=key;s-> lchild=s-> rchild=NULL; 		
		insertBST(&bt,s); 		
		scanf( "%d ",&key); 		
	} 	
    printf( "\nCreate   is   complete\n "); 
	inorder(bt);											//中序遍历已建立的二叉排序树
	do {
		printf("\nInput the key you want to search:");
		scanf("%d",&key);
		s=searchBST(bt,key);								//二叉排序树的查找
		if (s!=NULL)
			printf("\nsuccess,the value is %d ",s->data.key);
		else printf("\nunsuccess");
		printf("\ncontinue(y/n):\n");
		ch=getch();
	}while (ch=='y' || ch=='Y');
}
	
