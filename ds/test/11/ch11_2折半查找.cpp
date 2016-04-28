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

int  Binary_Search(SSTBL  tbl, KeyType kx)                            // tbl顺序表， kx查找关键字
{
	int   low ,high,mid,flag=0;
	low=1;
	high=tbl.length;											//设置初始区间
	while(low<=high)										//表空测试
	{													//非空，进行比较测试
		mid=(low+high)/2;									//得到中点
		if(kx<tbl.elem[mid].key)								//调整到左半区
			high=mid-1;
		else if(kx>tbl.elem[mid].key)							//调整到右半区
			low=mid+1;
		else												//查找成功，元素位置设置到flag中
		{
			flag=mid;
			break;
		}
	}
	return  flag;
}

void main()
{
	srand(time(NULL));
	KeyType fkey;int m;
	SSTBL tbl;
	tbl.length=10;
	for(int k=1;k<tbl.length;k++)  
	{
		tbl.elem[k].key=10*k;
		printf("%d, ",tbl.elem[k].key);
	}

	printf("\nplease input find key:\n");
	scanf("%d",&fkey);
	m=Binary_Search(tbl,fkey);
	if(m==0)printf("%d is not in table\n",fkey);
	else printf("%d is in table pos %d.\n",fkey,m);
	

}