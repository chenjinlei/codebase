#include <stdio.h>
#include <stdlib.h>

void InsertSort(int s[],int length)
{//对顺序表s进行折半插入排序，结果是s由无序到有序
	int i,j,low,high,mid;
	for(i=1;i<length;i++)
	{
		s[0]=s[i];								//保存待插入元素
		low=1;high=i-1;										//设置初始区间
		while(low<=high)									//该循环语句完成确定插入位置
		{
			mid=(low+high)/2;
			if(s[0]>s[mid])
				low=mid+1;								//插入位置在高半区中
			else
				high=mid-1;								//插入位置在低半区中
		}
		for(j=i-1;j>=high+1;j--)								//high+1为插入位置
			s[j+1]=s[j];							//后移元素，留出插入空位
		s[high+1]=s[0];							//将元素插入
	}
	for(i=1;i<length;i++)
		printf("%d  ",s[i]);
}

void main()
{
	int a[]={0,9,8,1,2,5,3,7,6,4,12};//0为空单元
    InsertSort(a,11);
}
