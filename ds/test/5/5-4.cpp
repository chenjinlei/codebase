#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
	char ch;
	struct Node * next;
}SString;
typedef SString * pstring;

void InitStr(pstring &S)
{
	S=(pstring)malloc(sizeof(pstring)); 							//��S����ռ�
	S->next=NULL;
}


void StrEvaluate(pstring &S,char ch[])
{
	if(S->next!=NULL)										//S����ֻ��һ���ڵ�Ͳ������
		S->next=NULL;	
	S->ch=ch[0];
	pstring s2=S;
	for(int i=1;ch[i]!='\0';i++)
	{
		pstring s1;
		InitStr(s1); 										//��ֵǰִ�г�ʼ������
		s1->ch=ch[i];										//ִ�и�ֵ����
		s2->next=s1;										//������S1
		s2=s1;											//�ı�S2ָ�룬ָ��S1
	}
}


void StrConcat(pstring &s,pstring t)
{
	pstring s1=s;
	while(s1->next!=NULL) 									//�ж��Ƿ񵽴���β��
		s1=s1->next;										//ָ�����
	s1->next=t;
}

void ReadStr(pstring s)
{
	pstring s1=s;
	while(s1!=NULL) 										//��ǰ���ǿ�
	{
		printf("%c",s1->ch) ; 								//��ʾ���S1
		s1=s1->next; 										//ָ�����
	}
	printf("\n");
}


int StrComp(pstring s1,pstring s2)
{
	pstring t1=s1;
	pstring t2=s2;
	while(t1!=NULL&&t2!=NULL)								//�и��ַ�����ͬ���ߵ�������β��
	{
		if(t1->ch!=t2->ch)
			break;
		else 
		{
			t1=t1->next;
			t2=t2->next;
		}
	}
	if(t1==NULL&&t2!=NULL)
	return -1;												//t1�ȵ�ĩβ��t1<t2
	else if(t1!=NULL&&t2==NULL) 
	return 1;												//t2�ȵ�ĩβ��t1>t2
	else if(t1==NULL&&t2==NULL)	
	return 0;												//����ͬʱ����ĩβ
	else if(t1->ch<t2->ch)
	return -1;
	else if(t1->ch>t2->ch)
	return 1;
}


int GetLength(pstring s)
{
	pstring s1=s;
	int i=0;
	while(s1) 												//û�е�����β��
	{
		s1=s1->next; 										//ָ�����
		i++;												//���ֳ��ȵı�������
	}
	return i; 												//���ر�ĳ���
}

void SubStr(pstring s,int i,int length,pstring &substring)
{
	pstring s1;
	InitStr(s1);
	if(GetLength(s)<i+length-1)
	{
		printf("ȡ�Ӵ�Խ��!");		
	}
	else
	{
		pstring s2=s;
		int j=0;
		while(j<i)											//�Ƶ�iλ�ô�
		{
			s2=s2->next;
			j++;
		}
		s1->ch=s2->ch;
		pstring s3=s1;
		for(j=1;j<length;j++)									//��iλ�ô����ζ�ȡ��Ϊlength���ַ�
		{
			s2=s2->next;
			pstring s4;
			InitStr(s4);
			s4->ch=s2->ch;	   
			s3->next=s4;
			s3=s4;
		}
	}
	substring=s1;
}

int StrIndex(pstring s,pstring t)
{
	char ch=t->ch;											//��ȡ�Ӵ������ַ�
	pstring s1=s;
	if(GetLength(s1)<GetLength(t))
	return -1;												//���Ҫ��ѯ���Ӵ����ȴ�����������
	int i=0 ;												//˵��������ַ���s�в����ڸ��Ӵ�t
	for(i=0;i<=GetLength(s1)-GetLength(t);i++,s1=s1->next)
	{	
		if(s1->ch==ch)										//�ҵ�S1���ַ����ַ���s�е�λ��
		{
			pstring strTemp;
			SubStr(s,i,GetLength(t),strTemp);
			if(StrComp(strTemp,t)==0)			//�����Ⱦͷ��ص�ǰλ��
			{
				return i+1;
			}
		}
	}
	if(i>GetLength(s1)-GetLength(t))
	return -1;
}

void StrInsert(pstring &s,int i,pstring t)
{
	pstring s1=s;
	if(i>GetLength(s))
	{
		printf("����λ�ó����ַ����ĳ���!");
		return;
	}
	if(i==1)												//���뵽��һ��λ�þ��ǽ�t����															//��s��ǰ��
	{
		pstring t1=t;
		while(t1->next)
			t1=t1->next;
		t1->next=s;
		s=t;
	}
	else
	{
		for(int j=1;j<i-1;j++)									//����Ĳ��ǵ�һ��λ��
		{
			s1=s1->next; 
		}
		pstring s2=s1->next;
		pstring s3=t;
		while(s3->next)
			s3=s3->next;
		s3->next=s2;
		s1->next=t;
	}
}

void StrDelete(pstring &s,int i,int length)
	{														//�ӵ�һ��λ��ɾ���Ͱ�����ĵ�һ��
		if(i==1)												//���ָ�������ƶ�
		{
			while(length--&&s)
				s=s->next;
		}
		else
		{
			pstring s1=s;
			i=i-1;
			while((--i)>0&&s1)
				s1=s1->next;
			pstring s2=s1;
			while((length--)>0&&s1)
				s1=s1->next;
			s2->next=s1->next;
		}
	}

void main()
{
	int loc,length;
	int flag=1;
	char j;
	char s2[100];
	pstring s,s1,substring;//s��s1��������
	InitStr(s);//��ʼ����
	InitStr(s1);
	InitStr(substring);
	StrEvaluate(s,"abc");									//ִ�жԴ���ֵ����
	StrEvaluate(s1,"abc");//ִ�жԴ���ֵ����
//---------------------------�����˵--------------------------
 printf("����������ʵ������洢�ṹ�Ĵ���\n");
 printf("����ʵ�ֲ��ҡ����롢ɾ���Ȳ�����\n");
 //-------------------------------------------------------------
  while(flag)
    { printf("��ѡ��:\n");
      printf("1.��ʾ����Ԫ��\n");
      printf("2.��������\n");
      printf("3.�ַ����ıȽ�  \n");
	  printf("4.���Ӵ���λ��  \n");
	  printf("5.�ַ����Ĳ���\n");
      printf("6.�ַ�����ɾ��  \n");
	  printf("7.�ַ����ĳ���  \n");
	  printf("8.ȡ�Ӵ� \n");
	  printf("9.�˳� \n");
      scanf(" %c",&j);
      switch(j)
   {
   case '1':ReadStr(s); break; //��ʾ����Ԫ��
   case '2':{printf("��sΪ��");
			 ReadStr(s);
			 printf("��s1Ϊ��");
			 ReadStr(s1);
			 StrConcat(s,s1);
             printf("���Ӻ���ַ���Ϊ��");//������Ӻ���ַ���
			 ReadStr(s);
             break;
			}
   case '3':{printf("��sΪ��");
			 ReadStr(s);
			 printf("��s1Ϊ��");
			 ReadStr(s1);
			 if(StrComp(s,s1)>0)
				printf("s>s1\n");//s>s1
			 else if(StrComp(s,s1)<0)
				printf("s<s1\n");//s<s1
			 else if(StrComp(s,s1)==0)
				 printf("s=s1\n");//s=s1
             break;
			}
	case '4':{printf("������Ҫ����Ӵ���");
			 scanf("%s",s2);//�����Ӵ�
			 StrEvaluate(s1,s2);
			 printf("�����Ӵ���һ�γ��ֵ�λ�ã�%d\n",StrIndex(s,s1));//����Ӵ���λ��StrIndex(s,s1)
             break;
			}
	case '5':{printf("������Ҫ����λ��:");
			scanf("%d",&loc);  //�����Ӵ��Ŀ�ʼλ��,����
			printf("������Ҫ������Ӵ���");
			 scanf("%s",s2);//�����Ӵ�
			 StrEvaluate(s1,s2);
			printf("ԭ���ַ���Ϊ:");
			ReadStr(s);
			StrInsert(s,loc,s1);
			printf("�������ַ���Ϊ:");
			ReadStr(s);
			break;
			}
	case '6':{printf("������Ҫɾ���Ĵ��Ŀ�ʼλ��,������2,3:");
			scanf("%d,%d",&loc,&length);  //�����Ӵ��Ŀ�ʼλ��,����
			printf("ԭ���ַ���Ϊ:");
			ReadStr(s);
			StrDelete(s,loc,length);
			printf("ɾ�����ַ���Ϊ:");
			ReadStr(s);
			break;
			}

	case '7':printf("���ĳ���Ϊ��%d\n",GetLength(s));
			break;
	case '8':printf("�������Ӵ��Ŀ�ʼλ��,������2,3:");
			scanf("%d,%d",&loc,&length);  //�����Ӵ��Ŀ�ʼλ��,����
			SubStr(s,loc,length,substring);
			printf("�Ӵ�Ϊ��");
			ReadStr(substring);
			break;
   default:flag=0;printf("�����������������˳�!\n");
   }
 }
}