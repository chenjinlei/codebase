/**哈希表的综合操作 **/
/**CONTENT :Insert,Search,Deltet **/
/* * * * * * * * * * * * * * * * * * * * * * * **/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 30 /*哈希表的最大容量，与所采用的哈希函数有关*/
typedef enum{False,True}  BOOL;
typedef enum{NULLKEY,HAVEKEY,DELKEY} HAVEORNOT;
/*哈希表元素的三种状态，没有记录、有记录、有过记录但已被删除*/
typedef struct /*定义哈希表的结构*/
{
int elem[MAXSIZE]; /* 数据元素体 */
HAVEORNOT elemflag[MAXSIZE]; /*元素状态标志，没有记录、有记录、有过记录但已被删除*/
int count; /*哈希表中当前元素的个数 */
}HashTable;
typedef struct
{int keynum; /*记录的数据域，只有关键字一项*/
}Record;
void InitialHash(HashTable*); /*初始化哈希表*/
void CreateHash(HashTable*);/* 根据从键盘上输入的一系列整数建立哈希表 */
void PrintHash(HashTable); /*显示哈希表中的所有元素*/
BOOL SearchHash(HashTable,int,int*); /*在哈希表中查找元素*/
BOOL InsertHash(HashTable*,Record); /*在哈希表中插入元素*/
BOOL DeleteHash(HashTable*,Record); /*在哈希表中删除元素*/
int Hash(int); /*哈希函数*/
void main()
{HashTable H; /*声明哈希表H*/
char ch,j='y';
int position;
Record R;
BOOL temp;

InitialHash(&H);
CreateHash(&H);
/*-------------------------程序说明-------------------------------*/
printf("This program will show how to operate to a HashTable.\n");
printf("You can display all elems,search a elem,\ninsert a elem,delete a elem.\n");
/*----------------------------------------------------------------*/

while(j!='n')
{printf("1.display\n");
printf("2.search\n");
printf("3.insert\n");
printf("4.delete\n");
printf("5.exit\n");
scanf(" %c",&ch);
switch(ch)
{case '1':if(H.count) PrintHash(H); /*哈希表不空*/
else printf("The HashTable has no elem!\n");
break;
case '2':if(!H.count) printf("The HashTable has no elem!\n"); /*哈希表空*/
else
{printf("Please input the keynum(int) of the elem to search:");
scanf("%d",&R.keynum); /*输入待查记录的关键字*/
temp=SearchHash(H,R.keynum,&position);
/*temp=True:记录查找成功；temp=False:没有找到待查记录*/
if(temp) printf("The position of the elem is %d\n",position);
else printf("The elem isn't exist!\n");
}
break;
case '3':if(H.count==MAXSIZE) /*哈希表已满*/
{printf("The HashTable is full!\n");
break;
}
printf("Please input the elem(int) to insert:");
scanf("%d",&R.keynum); /*输入要插入的记录*/
temp=InsertHash(&H,R);
/*temp=True:记录插入成功；temp=False:已存在关键字相同的记录*/
if(temp) printf("Sucess to insert the elem!\n");
else printf("Fail to insert the elem.The same elem has been exist!\n");
break;
case '4':printf("Please input the keynum of the elem(int) to delet:");
scanf("%d",&R.keynum); /*输入要删除记录的关键字*/
temp=DeleteHash(&H,R);
/*temp=True:记录删除成功；temp=False:待删记录不存在 */
if(temp) printf("Sucess to delete the elem!\n");
else printf("The elem isn't exist in the HashTable!\n");
break;
default: j='n';
}
}
printf("The program is over!\nPress any key to shut off the window!\n");
getchar();
}
void InitialHash(HashTable *H)
{/*哈希表初始化*/
int i;
(*H).count=0;
for(i=0;i<MAXSIZE;i++) (*H).elemflag[i]=NULLKEY;
}
void CreateHash(HashTable *H)
{/* 根据从键盘上输入的一系列整数（不超过12个，以-1结束）建立哈希表 */
 Record e;
 printf("请输入的一系列整数(不超过12个，以-1结束)以建立哈希表:\n");
 scanf("%d",&e.keynum);
 while(e.keynum!=-1)
    if(InsertHash(H,e))  scanf("%d",&e.keynum);
    else 
      {printf("请输入不重复的数据！");
       return;
       }     
}

void PrintHash(HashTable H)
{/*显示哈希表所有元素及其所在位置*/
int i;
for(i=0;i<MAXSIZE;i++) /*显示哈希表中记录所在位置*/
if(H.elemflag[i]==HAVEKEY) /*只显示标志为HAVEKEY(存放有记录)的元素*/
printf("%-4d",i);
printf("\n");
for(i=0;i<MAXSIZE;i++) /*显示哈希表中记录值*/
if(H.elemflag[i]==HAVEKEY)
printf("%-4d",H.elem[i]);
printf("\ncount:%d\n",H.count); /*显示哈希表当前记录数*/
}
BOOL SearchHash(HashTable H,int k,int *p)
{/*在开放定址哈希表H中查找关键字为k的数据元素，若查找成功，以p指示
待查数据元素在表中的位置，并返回True；否则，以p指示插入位置，并
返回False*/
int p1;
p1=(*p)=Hash(k); /*求得哈希地址*/
while(H.elemflag[(*p)]==HAVEKEY&&k!=H.elem[(*p)]) 
/*该位置中填有记录并且关键字不相等*/
{(*p)++; /*冲突处理方法：线性探测再散列*/
if((*p)>=MAXSIZE) (*p)=(*p)%MAXSIZE; /*循环搜索*/
if((*p)==p1) return False; /*整个表已搜索完，没有找到待查元素*/
}
if(k==H.elem[(*p)]&&H.elemflag[(*p)]==HAVEKEY) /*查找成功，p指示待查元素位置*/
return True; 
else return False; /*查找不成功*/
}
BOOL InsertHash(HashTable *H,Record e)
{/*查找不成功时插入元素e到开放定址哈希表H中，并返回True，否则返回False*/
int p;
if(SearchHash((*H),e.keynum,&p)) /*表中已有与e有相同关键字的元素*/
return False;
else
{(*H).elemflag[p]=HAVEKEY; /*设置标志为HAVEKEY，表示该位置已有记录*/
(*H).elem[p]=e.keynum; /*插入记录*/
(*H).count++; /*哈希表当前长度加一 */
return True;
}
}
BOOL DeleteHash(HashTable *H,Record e)
{/*在查找成功时删除待删元素e，并返回True，否则返回False*/
int p;
if(!SearchHash((*H),e.keynum,&p)) /*表中不存在待删元素*/
return False;
else
{(*H).elemflag[p]=DELKEY; /*设置标志为DELKEY，表明该元素已被删除*/
(*H).count--; /*哈希表当前长度减一*/
return True;
}
}
int Hash(int kn)
{/*哈希函数：H(key)=key MOD 11*/
return (kn%11);
} 
