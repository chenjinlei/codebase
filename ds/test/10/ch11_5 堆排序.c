#include <stdio.h>
#include <stdlib.h>
#define N 6
int k,j;
/* ���Ѻ��� */
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
/* ��ӡ���麯�� */
void prnt(int *a,int n){
    int i;
    printf("\n");
    for(i=0;i<n;i++){
        printf("%3d",a[i]);
    }
    printf("\n");
}
/* ��ӡ�Ѻ��� */
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
    printf("  �ѣ�\n");
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
/* ��ӡ���������麯�� */
void prntar(int *a,int b2,int len){
  int i; 
  printf("  ������\n");
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
    printf("              ������\n");
    printf("\n============================================\n");    
    printf("\n  ���������������Ԫ�ظ���,�Իس�������\n");
    scanf("%3d",&len);    
    printf("\n  ���������������Ԫ��,�Իس�������\n");
    for(i=0;i<len;i++)
        scanf("%3d",&a[i]);        
    tmp=1;sum=0;
    while(sum+tmp<=len){
        sum+=tmp;    
        tmp*=2;
    }
    printf("\n============================================\n");    
    printf("\n  ��ʼ���飺            \n");    
    prnt(a,len);    
    /* ����ʼ�� */
    for(i=sum-1;i>=0;i--)
        build(a,i,len-1);       
    prnthp(a,0,len-1);      
    /* �Ľ��� */
    for(i=0;i<len-1;i++){
        tmp=a[0];
        a[0]=a[len-1-i];
        a[len-1-i]=tmp;
        build(a,0,len-2-i);
        prnthp(a,0,len-2-i);
        prntar(a,len-1-i,len-1);        
    }
    printf("\n--------------------------------------------\n");
    printf("\n  ��������\n");        
    prnt(a,len);
    printf("\n============================================\n\n");    
    getch();
}
