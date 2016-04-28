 /*  
二路归并排序
主要思想：将要排序的数分成若干个小组，可以先是若干个长度为2，
之后长度以2的倍数递增，对每二个小部分进行归并排序，之后逐渐
归并达到最大长度。
*/
#include<stdio.h>

void MergSort(int a[],int b[],int n,int k)/*归并排序*/
{
int l1,l2,j=0,u1,u2,i,m=0;

l1=0;

while(l1+k<n)
{
l2=l1+k;/*l2的下届*/
u1=l2-1;/*l1的上届*/
u2=(l2+k-1<=n-1)?l2+k-1:n-1;/*l2的下届*/

for(i=l1,j=l2;i<=u1&&j<=u2;++m)/*每次对两个小部分进行归并排序*/
{
   if(a[i]>=a[j])
    b[m]=a[j++];

   else
    b[m]=a[i++];
}


while(i<=u1)/*将l1长度下剩余的放入*/
b[m++]=a[i++];

while(j<=u2)/*将l2长度下剩余的放入*/
b[m++]=a[j++];

l1=u2+1;/*取l2的上届加1继续归并*/
}

for(i=l1;i<n;++i,++m)/*将剩余的元素放入数组中，当随着K的增大，这些剩余的元素将被归并*/
   b[m]=a[i];

}



void main()
{
int a[20],b[20],i,k=1,n;

printf("输入你要输入的元素个数\n");
scanf("%d",&n);

printf("现在开始输入数字\n");
for(i=0;i!=n;++i)
{
scanf("%d",&a[i]);
}


while(k<n)
{
   MergSort(a,b,n,k);
   for(i=0;i<n;++i)/*每次归并后的结果在放回a[i]*/
    a[i]=b[i];
   k=k*2;
}

printf("使用归并排序排好的序列是\n");
for(i=0;i<n;++i)
   printf("%d ",a[i]);
printf("\n");

}

 
