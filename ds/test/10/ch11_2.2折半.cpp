#include <stdio.h>
#include <stdlib.h>

void InsertSort(int s[],int length)
{//��˳���s�����۰�������򣬽����s����������
	int i,j,low,high,mid;
	for(i=1;i<length;i++)
	{
		s[0]=s[i];								//���������Ԫ��
		low=1;high=i-1;										//���ó�ʼ����
		while(low<=high)									//��ѭ��������ȷ������λ��
		{
			mid=(low+high)/2;
			if(s[0]>s[mid])
				low=mid+1;								//����λ���ڸ߰�����
			else
				high=mid-1;								//����λ���ڵͰ�����
		}
		for(j=i-1;j>=high+1;j--)								//high+1Ϊ����λ��
			s[j+1]=s[j];							//����Ԫ�أ����������λ
		s[high+1]=s[0];							//��Ԫ�ز���
	}
	for(i=1;i<length;i++)
		printf("%d  ",s[i]);
}

void main()
{
	int a[]={0,9,8,1,2,5,3,7,6,4,12};//0Ϊ�յ�Ԫ
    InsertSort(a,11);
}
