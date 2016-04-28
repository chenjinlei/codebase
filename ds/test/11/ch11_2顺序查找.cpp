#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
typedef int KeyType;
typedef struct {
	KeyType key;
}ElemType;
typedef  struct												//顺序存储结构
{
	ElemType  elem[MAX];										//存储数据元素的数组
	int       length;										//表长度
}SSTBL;
typedef  struct  NODE										//链式存储结构
{
	ElemType  elem;										//结点的值域
	struct  NODE  *next;									//下一个结点指针域
}NodeType;

int  s_search(SSTBL tbl,KeyType kx)                     	//在表tbl中查找关键字为kx的数据元素，
								//若找到返回该元素在数组中的下标，否则返回0
{
	tbl.elem[0].key = kx;							     //在从后向前查找失败时，不必判表是
	//否检测完从而达到算法统一
	for( int i = tbl.length ; tbl.elem[i].key != kx ;i--); 			//从表尾端向前找 
	return  i;
}

void main()
{
	srand(time(NULL));
	KeyType fkey;int m;
	SSTBL tbl;
	tbl.length=10;
	for(int k=1;k<tbl.length;k++)  
	{
		tbl.elem[k].key=10*rand()/10;
		printf("%d, ",tbl.elem[k].key);
	}

	printf("\nplease input find key:\n");
	scanf("%d",&fkey);
	m=s_search(tbl,fkey);
	if(m==0)printf("%d is not in table\n",fkey);
	else printf("%d is in table pos %d.\n",fkey,m);
	

}