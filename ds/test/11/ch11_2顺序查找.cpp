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

int  s_search(SSTBL tbl,KeyType kx)                     	//�ڱ�tbl�в��ҹؼ���Ϊkx������Ԫ�أ�
								//���ҵ����ظ�Ԫ���������е��±꣬���򷵻�0
{
	tbl.elem[0].key = kx;							     //�ڴӺ���ǰ����ʧ��ʱ�������б���
	//������Ӷ��ﵽ�㷨ͳһ
	for( int i = tbl.length ; tbl.elem[i].key != kx ;i--); 			//�ӱ�β����ǰ�� 
	return  i;
}

void main()
{
	srand(time(NULL));
	KeyType fkey;int m;
	SSTBL tbl;
	tbl.length=10;
	for(int k=1;k<tbl.length;k++)  
	{
		tbl.elem[k].key=10*rand()/10;
		printf("%d, ",tbl.elem[k].key);
	}

	printf("\nplease input find key:\n");
	scanf("%d",&fkey);
	m=s_search(tbl,fkey);
	if(m==0)printf("%d is not in table\n",fkey);
	else printf("%d is in table pos %d.\n",fkey,m);
	

}