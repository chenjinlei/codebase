#include <stdio.h>
#include <malloc.h>

typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char

//Լɪ��������ʽ�洢�ṹ�����Ͷ���
typedef struct LNode  /*��������Ĵ洢�ṹ*/                                
{
	int num;													//���
	int password;												//��������
	struct LNode *next;											//ָ����
}LNode,*Linklist;
Linklist L, pt,p ;												//����ͷָ�롢��ǰָ�뼰��ǰһָ��


//���ȴ���һ������ͷ���ĵ�������������ѭ�������洢ÿ���˵ı�š�
int CreatLinkList(int n)
{
	int i;
	L=(Linklist)malloc(sizeof(LNode));							/*��ͷ��������*/
	if(!L)
		return 0;
	p=L;
	for(i=1;i<n;i++)
	{
		pt=(Linklist)malloc(sizeof(LNode));							/*�����½��*/
		if(!pt)
			return 0;
		p->next=pt;
		p=pt;
	}
	p->next=L;												/*����ָ��ͷ��㣬����ѭ������*/
	pt=L;
	return 0;
}

//����������뵥����װΪ������ʵ������������㷨���£�
int EnterPwd(int n)
{
	int i,j;
	printf("\nplease enter the password:(example:4 7 11)\n");
	for( i=1;i<=n;i++)
	{
		scanf("%d",&j); 										/*��������*/
		pt->num=i;
		pt->password=j; 										/*���븳ֵ*/
		pt=pt->next; 										/*ָ������*/
	}
	pt=p; /*�ı䵱ǰָ��*/
	return 0;
}

//ʵ�ִӱ��Ϊi���˿�ʼ��������m���˳��У�ֱ�������˳��У��������˳��ʵ�ֵ��㷨���£�
int OutList(int m,int n)
{
	int i,a;
	for(i=1;i<=n;i++)
	{
		for(a=1;a<m;a++)										/*������������*/
			pt=pt->next;
		p=pt->next;
		m=p->password;
		printf("%d ",p->num);
		pt->next=p->next;										/*ɾ������*/
		free(p);												/*�ͷŶ�̬����Ľ��ָ��*/
	}
	return 0;
}

int main()
{
	int n,m;
	printf("����������");
	scanf("%d",&n);
	printf("���뱨������");
	scanf("%d",&m);
	CreatLinkList(n);
	EnterPwd(n);
	OutList(m,n);
	return 0;
}
