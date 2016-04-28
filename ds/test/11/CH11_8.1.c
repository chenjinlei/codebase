#include   <stdlib.h> 
#include   <stdio.h> 

#define   NULL   0 

typedef   int   KeyType; 

typedef   struct   { 	
	KeyType   key;   	
}ElemType;       //Ԫ�����ͣ������������ԣ����߿ɸ���ʵ��������룩

typedef   struct   BiTNode{ 	
	ElemType   data; 	
	struct   BiTNode   *lchild,*rchild; 	
}BiTNode,*BiTree; 

BiTree   searchBST(BiTree   bt,KeyType   key){ 	
	//�ڶ���������   bt   �в�����ؼ��ֵ��ڸ���ֵ�Ľ���Ƿ���ڣ��������Ӧ��Ϣ	
	if   (bt==NULL)   return   NULL; 	
	else   if   (bt-> data.key==key)   return   bt; 
	else   if   (key <bt-> data.key)   return   searchBST(bt-> lchild,key); 	
	else   return   searchBST(bt-> rchild,key); 	
} 

void   insertBST(BiTree  *bt,BiTree  s){ 	
	//�ڶ����������в���һ���½��	
	if   (*bt==NULL)   *bt=s; 	
	else   if   (s-> data.key <(*bt)-> data.key)   insertBST(&((*bt)-> lchild),s); 	
	else   if   (s-> data.key> (*bt)-> data.key)   insertBST(&((*bt)-> rchild),s); 	
} 

void   inorder(BiTree   bt){ 	
	//���Ѿ������õĶ�������������������������õ�һ�����ؼ��������Ԫ������	
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
	//����һ�ö�����������Ԫ��ֵ�Ӽ������룬ֱ������ؼ��ֵ���-1Ϊֹ	
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
	inorder(bt);											//��������ѽ����Ķ���������
	do {
		printf("\nInput the key you want to search:");
		scanf("%d",&key);
		s=searchBST(bt,key);								//�����������Ĳ���
		if (s!=NULL)
			printf("\nsuccess,the value is %d ",s->data.key);
		else printf("\nunsuccess");
		printf("\ncontinue(y/n):\n");
		ch=getch();
	}while (ch=='y' || ch=='Y');
}
	
