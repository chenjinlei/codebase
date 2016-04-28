#include <stdio.h>
#include <stdlib.h>

void InsertSort(int p[],int length)							
{//结果是p由无序到有序
	int i,j;
	for(i=2;i<=length;i++)
		if(p[i]<p[i-1]) 		 			//小于时，需将elem[i]插入有序表
		{
			p[0]=p[i];					//为统一算法，设置监测哨
			for(j=i-1;p[0]<p[j];j--)
				p[j+1]=p[j];			//记录后移
			p[j+1]=p[0];				//插入到正确位置
		}
	for(i=1;i<length;i++)
		printf("%d  ",p[i]);
}

void main()
{
	int a[]={0,20,18,30,10,5,1,40,25,50};
  
	InsertSort(a,10);
}