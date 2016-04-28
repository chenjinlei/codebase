#include <stdio.h>
#include <stdlib.h>

void Insertion_Sort(int a[],int n) 
{
	int i,j,key;
	for(j=1;j<n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>=0&&a[i]>key)
		{
			a[i+1]=a[i]; i=i-1;
		}
		a[i+1]=key;
	}
}

void main()
{
	int i;
	int  array[10]={10,8,20,40,2,90,70,100,15,78};
    Insertion_Sort(array,10);
	for(i=0;i<10;i++)
		printf("%d  ",array[i]);
}