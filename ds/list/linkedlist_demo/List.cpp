#include <stdio.h>
#include <stdlib.h>

typedef char DataType;		//DataType�������κ���Ӧ������������int, float��char

//ʵ�ֵ��������ʽ�洢�ṹ�����Ͷ���
typedef struct node			//������Ͷ���*/
{	DataType data;			//����������*/
	struct node *next;		//����ָ����
}ListNode;
typedef ListNode *LinkList;


LinkList CreateListTou()//ͷ�巨����������
{
	LinkList L;					//����������
	DataType ch;					//������ʱ����
	ListNode *p;					//������ʱ���ָ��
	L=(LinkList)malloc(sizeof(ListNode));		//����һ��ͷ���
	L->next=NULL;					//��ͷ���
	getchar();
	printf("������Ҫ�����ĵ������ַ�����abcdefg.\n");
	ch=getchar();
	while(ch!='\n')
	{
		p=(LinkList)malloc(sizeof(ListNode));	//�������
		p->data=ch;				//����㸳ֵ
		p->next=L->next;			//���½��������
		L->next=p;				//�ı�ͷָ��
		ch=getchar();
	}
	printf("�����ɹ����������������\n");
	getchar();
	return L;
}

LinkList CreateListWei()//β�巨����������
{
	LinkList L;
	DataType ch;
	ListNode *p,*r;
	L=(LinkList)malloc(sizeof(ListNode));		//����һ�ռ�
	L->next=NULL;					//ͷ��㸳ֵ
	r=L->next;					//βָ��ָ��ͷ���
	getchar();
	printf("�����������������Ԫ�� ���� abcdefg.\n");
	ch=getchar();
	while(ch!='\n')
	{
		p=(LinkList)malloc(sizeof(ListNode));	//�����½��ռ�
		p->data=ch;				//���½�㸳ֵ
		if(L->next==NULL)			//��������ǿձ�
		{
			L->next=p;
		}
		else
		{
			r->next=p;
		}
		r=p;					//�ı�βָ��ָ��
		ch=getchar();
	}
	r->next=NULL;					//���һ����㸳ֵΪ��
	printf("�ɹ���.\n");
	getchar();
	return L;
}

bool InsertNode(LinkList &L,int i,DataType x)//�������ǰ�����
{
	int j;						//�����������ǰλ��
	LinkList p,s;					//��������ָ��
	p=L;
	j=0;
	while(p&&j<i-1)					//���ҵ�i-1�����
	{
		p=p->next;				//�Ƶ���һ�����
		++j;
	}
	if(!p||j>i-1)					//��i-1�������ڲ��ܲ���
	{
		getchar();
		printf("Insert error!Any key to contnue.\n");
		getchar();
		return false;
	}
	s=(LinkList)malloc(sizeof(ListNode));		//���롢��װ���
	s->data=x;
	s->next=p->next;				//�½������ڵ�i-1�����ĺ���
	p->next=s;
	getchar();
	printf("Success!Any key to contnue.\n");
	getchar();
	return true;
}

int Init_List(LinkList &L)//��ʼ��������
{
	L=(ListNode*)malloc(sizeof(ListNode));		//������ռ�
	if(L)
	{
		L->next=NULL;				//��Ϊ�ձ�
		return 1;
	}
	else
		return 0;
}

int Clear_List(LinkList &L)//��ձ�
{
	while(L!=NULL)					//�ж������Ƿ�Ϊ��
	{
		LinkList p;
		p=L;
		L=L->next;
		free(p);				//�ͷŽ��洢�ռ�
	}
	return 1;
}

int IsEmpty(LinkList L) //�жϱ��Ƿ�Ϊ��
{
	if (L->next==NULL)				//�ж������Ƿ�Ϊ��
		return 1;
	else
		return 0;
}

int  Length_LinkList (LinkList L)//���
{
	ListNode  * p=L;				//pָ��ͷ���
	int  k=0;					//�������kͳ�ƽ�����
	while (p->next)
	{
		p=p->next;				//ָ�����
		k++;
	}						//p��ָ���ǵ�k�����
	return  k;
}

bool DeleteNode(LinkList &L,int i)//�������ɾ������
{
	int j;
	LinkList p,s;
	p=L;
	j=0;
	while(p->next&&j<i-1)				//���ҵ�i-1�����
	{
		p=p->next;
		++j;
	}
	if(!(p->next)||j>i-1)
	{
		getchar();
		printf("Delete error!Any key to contnue.\n");
		getchar();
		return false;
	}
	s=p->next;
	p->next=s->next;				//��������ɾ��
	free(s);					//�ͷ�s
	getchar();
	printf("Success!Any key to contnue.\n");
	getchar();
	return true;
}

ListNode* LocateElem(LinkList L,int i)//������Ų���
{
	ListNode* p;
	p=L->next;
	int j=1;
	while(p&&j<i)					//���ҵ�i�����
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)					//û���ҵ����������Ľ��
		return NULL;
	return p;
}

ListNode *LocateElem(LinkList L,DataType e)//����ֵ����
{
	ListNode* p;
	int j=1;
	p=L->next;
	while(p&&p->data!=e)				//�жϴ����ҽ���ֵ�Ƿ����
	{
		p=p->next;
		j++;
	}
	if(p)						//���ҳɹ�
		printf("���ҳɹ�!�ǵ� %d ��Ԫ��.\n",j);
	return p;
}

void showList(LinkList L)
{
	L=L->next;
	while(L!=NULL)
	{
		printf("%c",L->data);
		L=L->next;
	}
	printf("\n���������");
	getchar();
}

int main()
{
	char c;
	int i;
	LinkList L,L1;
	Init_List(L);//��ʼ��������
	char x;
	do
	{
		printf("                ��3�£����Ա����ʽ�洢                  \n");
		printf("**********************************************************\n");
		printf("    1:  ������������\n");
		printf("    2:  ������������\n");
		printf("    3:  ��������ղ���\n");
		printf("    4:  ���������\n");
		printf("    5:  ������ɾ������\n");
		printf("    6:  ��������Ҳ���\n");
		printf("    7:  ��ʾ��������\n");
		printf("    8:  �˳�\n");
		printf("\n >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		do
		{c=getchar();
		}while(c<'1'||c>'7');
		getchar();
		switch(c)
		{
		case'1':
			printf("    1:  ͷ�巨�������������\n");
			printf("    2:  β�巨�������������\n");
			printf("    ���������\n");
			c=getchar();
			switch(c)
			{
			case '1':L=CreateListTou();break;
			case '2':L=CreateListWei();break;
			default:c=' ';break;
			}
			break;
		case'2':
			if ( L->next==NULL )
			{
				printf("������δ���������ȴ�������\n");
				break;
			}
			printf("����������λ�ã�");
			scanf("%d",&i);
			printf("�����������ַ���");
			getchar();
			x=getchar();
			InsertNode(L,i,x);
			break;
		case'3':
			Clear_List(L);
			break;
		case'4':
			if(L==NULL)
			{
				printf("�����ڣ����߱���գ�\n");
				break;
			}
			printf(" ��ĳ���Ϊ��%d\n",Length_LinkList(L));
			break;
		case'5':
			printf("������Ҫɾ����λ�ã�");
			scanf("%d",&i);
			DeleteNode(L,i);
			break;
		case'6':
			printf("    1:  ����Ų���\n");
			printf("    2:  ��ֵ����\n");
			printf("    ���������\n");
			c=getchar();
			switch(c)
			{
			case '1':
				printf("��������ţ�");
				scanf("%d",&i);
				L1=LocateElem(L,i);
				if(L1!=NULL)
					printf("\n���ҵ�ֵΪ:%c\n",L1->data);
				else
					printf("\nû����Ҫ���ҵ�ֵ\n");
				break;
			case '2':
				printf("������ֵ��");
				getchar();
				scanf("%c",&x);
				L1=LocateElem(L,x);
				break;
			default:c=' ';break;
			}
			break;
		case'7':
			if(L==NULL||L->next==NULL)
			{
				printf("�����ڣ����߱���գ�\n");
				break;
			}
			showList(L);
			break;
		case'8':
			break;
		}
	}while(c!='8');
	return 0;
}
