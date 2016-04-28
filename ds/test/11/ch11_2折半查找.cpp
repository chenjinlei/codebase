#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
typedef int KeyType;
typedef struct {
	KeyType key;
}ElemType;
typedef  struct												//˳��洢�ṹ
{
	ElemType  elem[MAX];										//�洢����Ԫ�ص�����
	int       length;										//����
}SSTBL;
typedef  struct  NODE										//��ʽ�洢�ṹ
{
	ElemType  elem;										//����ֵ��
	struct  NODE  *next;									//��һ�����ָ����
}NodeType;

int  Binary_Search(SSTBL  tbl, KeyType kx)                            // tbl˳��� kx���ҹؼ���
{
	int   low ,high,mid,flag=0;
	low=1;
	high=tbl.length;											//���ó�ʼ����
	while(low<=high)										//��ղ���
	{													//�ǿգ����бȽϲ���
		mid=(low+high)/2;									//�õ��е�
		if(kx<tbl.elem[mid].key)								//�����������
			high=mid-1;
		else if(kx>tbl.elem[mid].key)							//�������Ұ���
			low=mid+1;
		else												//���ҳɹ���Ԫ��λ�����õ�flag��
		{
			flag=mid;
			break;
		}
	}
	return  flag;
}

void main()
{
	srand(time(NULL));
	KeyType fkey;int m;
	SSTBL tbl;
	tbl.length=10;
	for(int k=1;k<tbl.length;k++)  
	{
		tbl.elem[k].key=10*k;
		printf("%d, ",tbl.elem[k].key);
	}

	printf("\nplease input find key:\n");
	scanf("%d",&fkey);
	m=Binary_Search(tbl,fkey);
	if(m==0)printf("%d is not in table\n",fkey);
	else printf("%d is in table pos %d.\n",fkey,m);
	

}