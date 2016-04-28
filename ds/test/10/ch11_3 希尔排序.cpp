#include<stdio.h>
#include<stdlib.h>

void hillsort(int*,int);

main()
{
	int sup=10;
	int *list=(int *)malloc(sizeof(int)*sup);
	int val,i=1,j;
	printf("输入整数，以-1结束");
	scanf("%d",&val);
	while(val!=EOF)//以-1结束 
	{
		list[i++]=val;
		scanf("%d",&val);
		if(i>=sup){
			sup=i+sup;
			realloc(list,sizeof(int)*sup);
		}
	}
	
	hillsort(list,i-1);
	for(j=1;j<i;j++){
		printf("%d ",list[j]);
		if(j%10==0)
			printf("\n");
	}
	return 0;
}

void hillsort(int *list,int n)
{
	int gap=n/2,count,j;
	while(gap>=1){
		for(count=1+gap;count<=n;count+=gap)
		{
			if(list[count]<list[count-gap])
			{
				list[0]=list[count];
				for(j=count-gap;j>0&&list[j]>list[0];j-=gap)
					list[j+gap]=list[j];
				list[j+gap]=list[0];
			}
		}
		gap=gap/2;
	}
} 