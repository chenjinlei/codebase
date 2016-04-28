#include <stdio.h>
#include <stdlib.h>
#define N 6
int k,j;
/* 建堆函数 */
void build(int *a,int i,int n){
    int tmp;
    k=i;
    j=2*k+1;
    while(j<=n){
        if(j<n && a[j]<a[j+1])
            j++;
        if(a[k]>=a[j])break;
        tmp=a[k];
        a[k]=a[j];
        a[j]=tmp;        
        k=j;
        j=2*j+1;
    }
}
/* 打印数组函数 */
void prnt(int *a,int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf("%3d",a[i]);
    }
    printf("\n");
}
/* 打印堆函数 */
void prnthp(int *a,int b1,int b2){
    int size;
    int h=0,sum=0,item=1;
    int i,j,cnt,start,tmp;
    size=b2-b1+1;
    while(sum<=size){
        sum+=item;
        h++;
        item*=2;
    }
    item=1;
    cnt=0;
    start=b1;
    tmp=1;
    printf("\n--------------------------------------------\n");    
    printf("  堆：\n");
    while(1){
        for(i=0;i<h;i++){
                for(j=0;j<h-i;j++)
                                printf("    ");
                 for(j=0;j<i+1;j++)printf(" "); 
                for(j=0;j<tmp;j++){
                                if(cnt>size-1)goto end;
                                printf("%4d",a[cnt++]);
                }
                printf("\n");
                tmp*=2;
        }       
     }
     end:
          printf("\n");         
          return;                  
}
/* 打印已排序数组函数 */
void prntar(int *a,int b2,int len){
  int i; 
  printf("  已排序：\n");
  for(i=0;i<b2;i++){
    printf("   ");
  }          
  for(i=b2;i<=len;i++){
    printf("%3d",a[i]);
  }          
  printf("\n");
} 
main(){
    /* int a[]={-1,2,5,1,0,-3,-2,8,6}; */
    int a[50];
    int i;
    int tmp;
    int sum;
    int num;
    int len;
    printf("              堆排序\n");
    printf("\n============================================\n");    
    printf("\n  请输入待排序数组元素个数,以回车结束：\n");
    scanf("%3d",&len);    
    printf("\n  请输入待排序数组元素,以回车结束：\n");
    for(i=0;i<len;i++)
        scanf("%3d",&a[i]);        
    tmp=1;sum=0;
    while(sum+tmp<=len){
        sum+=tmp;    
        tmp*=2;
    }
    printf("\n============================================\n");    
    printf("\n  初始数组：            \n");    
    prnt(a,len);    
    /* 建初始堆 */
    for(i=sum-1;i>=0;i--)
        build(a,i,len-1);       
    prnthp(a,0,len-1);      
    /* 改建堆 */
    for(i=0;i<len-1;i++){
        tmp=a[0];
        a[0]=a[len-1-i];
        a[len-1-i]=tmp;
        build(a,0,len-2-i);
        prnthp(a,0,len-2-i);
        prntar(a,len-1-i,len-1);        
    }
    printf("\n--------------------------------------------\n");
    printf("\n  排序结果：\n");        
    prnt(a,len);
    printf("\n============================================\n\n");    
    getch();
}
