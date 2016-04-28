#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
typedef struct Node
{
	struct Node * next;										//��һ�е���ʼλ��
	char S[MAXSIZE];										//һ��ֻ����100���ַ�
}HNode;
typedef HNode * pHNode;

void Insert(pHNode &p,int row,char *s)						 //rowҪ�����λ�ã�sҪ���������
{
	if(row<1)												//����ʱ���Ҫ�ӵ�һ�п�ʼ����
	{
		printf("�����кŲ���С��1��");
		return;
	}
	else if(p==NULL&&row!=1)								//���pΪNULLֻ�ܴӵ�һ�в���
	{
		printf("Ŀǰû���κ��У�ֻ�ܲ��뵽��һ�У�"); 
		return;
	}
	else if(p==NULL&&row==1)								//���pΪNULL�����뵽��һ�еĲ���
	{
		p=(pHNode)malloc(sizeof(pHNode));
		p->next=NULL;
		int i=0;
		while(s[i]!='\0')									 //Ϊ��㸳ֵ
		{
			p->S[i]=s[i]; 
			i++;
		}
		p->S[i]='\0';
		return; 
	}
	pHNode p3=(pHNode)malloc(sizeof(pHNode)); 				//Ϊ�½�����ռ�
	int i=0;
	while(s[i]!='\0')										//Ϊ��㸳ֵ
	{
		p3->S[i]=s[i]; 
		i++;
	}
	p3->S[i]='\0';
	if(p!=NULL&&row==1)									    //p��ΪNULL�����뵽��һ��
	{
		p3->next=p;
		p=p3;
		return;
	}
														     //�������
	pHNode p1=p;
	i=1;
	while(i<row-1&&p1->next)								 //��������������������嵽���һ��
	{
		i++;
		p1=p1->next;
	}	
	p3->next=p1->next;
	p1->next=p3;
}

void del(pHNode &p,int row)									//ɾ���У�rowΪҪɾ�����к�
{
	if(row<1)												//����ʱ���Ҫ�ӵ�һ�п�ʼ����
	{
		printf("�����кŲ���С��1!");
		return;
	}
	if(row==1&&p)											//���ɾ�����ǵ�һ��
	{
		p=p->next;
		return;
	}
	pHNode p1=p;
	int i=1;
	while(i<row-1&&p1)										//���������������
	{
		i++;
		p1=p1->next;
	}
	if(p1==NULL)
	{
		printf("ɾ�����к�Խ��!");
		return;
	}
	p1->next=p1->next->next;
}


void row_insert(char *s,int i,char *s1)							//sҪ�༭���ַ�����i�����λ�ã�s1														//������ַ���
{
	char s2[MAXSIZE];
	int j=0;
	while(s[j]!='\0'&&j+1<i)									//��ȡǰ�벿���ַ�
	{
		s2[j]=s[j];
		j++;
	}
	if(s[j]=='\0')
	{
		printf("����λ�ó��������ַ���!");
		return;
	}
	int k=0,n=j;
	while(s1[k]!='\0')										//��Ҫ������ַ�����ָ����λ��
	{
		s2[n]=s1[k];
		k++;
		n++;
	}
	while(s[j]!='\0')											//���Ӻ�����ַ��� 
	{
		s2[n]=s[j];
		n++;
		j++;
	}
	s2[n]='\0';
  	j=0;
	while(s2[j]!='\0')
	{
		s[j]=s2[j];											//����ȡ���ַ�������s
		j++;
	}
	s[j]='\0'; 
}

void row_del(char *s,int i,int length) //sҪ�༭���ַ�����iɾ������ʼλ�ã�lengthɾ���ĳ���
{

	char s1[MAXSIZE];
	int j=0;
	while(s[j]!='\0'&&j+1<i)									//��ȡǰ�벿���ַ�
	{
		s1[j]=s[j];
		j++;
	}
	if(s[j]=='\0')
	{
		printf("ɾ����ʼλ�ó��������ַ���!");
		return;
	}
	int k=j+1;
	while(k<i+length-1&&s[k]!='\0')								//����Ҫɾ�����ǲ����ַ�
		k++;
	if(s[k]=='\0')
	{
		printf("ɾ������λ�ó��������ַ���!");
		return;
	}
	
	while(s[k]!='\0')											//��ȡ��벿���ַ�
	{
		s1[j]=s[k];
		j++;
		k++;
	}
	s1[j]='\0';												//���'\0'
	j=0;
	while(s1[j]!='\0')
	{
		s[j]=s1[j];											//����ȡ���ַ�������s
		j++;
	}
	s[j]='\0'; 
}

void row_edit(pHNode &p,int row,int choose)						//chooseΪ0ʱִ��ɾ��������choose														//Ϊ1ʱִ�в������
{
	int r=1;
	while(r<row&&p)										//�ƶ���Ҫ�༭����
	{
		p=p->next;
		r++;
	}
	if(choose==0)											//ɾ������
	{
		printf("����Ҫɾ������ʼ�ַ���λ��\n");
		int i,length;
		scanf("%d",&i);
		if(i<1)
		{
			printf("\nɾ���Ŀ�ʼ�ַ�λ�ò���С��1!");
			return;
		}
		
		printf("����Ҫɾ���ĳ���\n");
		scanf("%d",&length);
		row_del(p->S,i,length);								//��Ҫ�༭�е��ַ����Լ���Ҫ��Ϣ��														//��row_del
	}
	if(choose==1)											//�������
	{
		printf("����Ҫ�����λ��\n");
		int i;
		scanf("%d",&i);
		if(i<1)
		{
			printf("\n����Ŀ�ʼ�ַ�λ�ò���С��1!");
			return;
		}
		char *s="wer";										//Ҫ������ַ���
		row_insert(p->S,i,s);									//�����༭���ַ�������Ϣ����
	}
}


void main()
{
	pHNode text=NULL,text1;
	int row;
	//Insert(text,1,"fyfyugtu");
	//Insert(text,1,"fyfyugtu");
	int flag=1,select;
	char j;
	char s[MAXSIZE];
//---------------------------�����˵--------------------------
  printf("�б༭����\n");
 //-------------------------------------------------------------
  while(flag)
    { printf("\n��ѡ��:\n");
      printf("1.��ʾ�����ı�\n");
      printf("2.����һ���ı�\n");
      printf("3.�ı��༭\n");
      printf("4.ɾ���ı�\n");
      printf("5.�˳�  \n");
	  scanf(" %c",&j);
      switch(j)
   {
   case '1':
			printf("\n");
			text1=text;
			while(text1!=NULL)
			{
				printf("%s\n",text1->S);
				text1=text1->next;
			}
			break; //��ʾ����Ԫ��
   case '2':
			printf("������Ҫ�����е�λ�ã�"); 
			scanf("%d",&row);
			printf("������Ҫ���������:");
			scanf("%s",s);
			Insert(text,row,s);
			break;     
   case '3':
			printf("������Ҫ�༭���У�"); 
			scanf("%d",&row);
			printf("��ѡ��:\n0.ɾ��\n1.����\n�������ѡ��");
			scanf("%d",&select);
			row_edit(text,row,select);
			break;    
   case '4':
			printf("������Ҫɾ�����У�"); 
			scanf("%d",&row);
			del(text,row);
			break;
   default:flag=0;printf("�����������������˳�!\n");
   }
 }

}