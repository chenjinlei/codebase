#include <stdio.h>
#include <stdlib.h>

void bubblesort(int r[], int n)
{                                                               //˳���r���䳤��n
	int i,j;
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-1;j++)
			if(r[j+1]<r[j])                               //����λ��
			{
				r[0]=r[j];    							  //r[0]������ʱ���Ԫ��
				r[j]=r[j+1];
				r[j+1]=r[0];
			}
			
    }
    for(i=1;i<=n-1;i++)
       printf("%d  ",r[i]);
}

void main()
{
	int a[]={0,5,12,34,10,56,80,50,2,4,100};
	bubblesort(a,11);
	
}