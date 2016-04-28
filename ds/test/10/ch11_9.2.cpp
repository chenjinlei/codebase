#include <stdio.h>
#include <stdlib.h>

void Carve_up(int array[],int number,int*m)
{
	int i,j,k,middle,temp;
	i=0;
	j=number-1;
	k=(i+j)/2;
	if(array[i]>=array[j]&&array[j]>=array[k])				//在下标i,j,k的数组元素中选取中项
		middle=j;											//Array[j]是中项
	else if(array[i]>=array[k]&&array[k]>=array[j])
		middle=k;												//array[k]是中项
	else
		middle=i;											//Array[i]是中项
	temp=array[middle];
	array[middle]=array[i];
	while(i!=j)
	{
		while(i<j&&array[j]>=temp)
			j--;											//逐步减小，直到array[j]<temp为止
		if(i<j)
		{
			array[i]=array[j];
			i++;
			while(i<j&&array[i]<=temp)
				i++;										//i逐步减小，直到array[i]>temp为止
			if(i<j)
			{
				array[j]=array[i];
				j--;
			}
		}
	}
	array[i]=temp;
	*m=i;
	return;
}
void Quick_Sort(int array[],int number)							//递归实现快速排序
{
	int i;
	if(number>1)
	{
		Carve_up(array,number,&i);
		Quick_Sort(array,i);
		Quick_Sort(&array[i+1],number-i-1);
	}
	return;
}

void main()
{
	int i;
	int  array[10]={10,8,20,40,2,90,70,100,15,78};
    Quick_Sort(array,10);
	for(i=0;i<10;i++)
		printf("%d  ",array[i]);
}