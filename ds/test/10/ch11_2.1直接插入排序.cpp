#include <stdio.h>
#include <stdlib.h>

void InsertSort(int p[],int length)							
{//�����p����������
	int i,j;
	for(i=2;i<=length;i++)
		if(p[i]<p[i-1]) 		 			//С��ʱ���轫elem[i]���������
		{
			p[0]=p[i];					//Ϊͳһ�㷨�����ü����
			for(j=i-1;p[0]<p[j];j--)
				p[j+1]=p[j];			//��¼����
			p[j+1]=p[0];				//���뵽��ȷλ��
		}
	for(i=1;i<length;i++)
		printf("%d  ",p[i]);
}

void main()
{
	int a[]={0,20,18,30,10,5,1,40,25,50};
  
	InsertSort(a,10);
}