#include <stdio.h>
#include <malloc.h>

typedef struct
{
	char *S;
	int length;
}SString;
typedef SString * pstring;

void InitStr(pstring &str,int size)
{
	str=(pstring)malloc(size*sizeof(pstring));						//Ϊstr����ռ�
	str->length=0;											//��ʼ���ַ�������Ϊ0
	str->S=(char*)malloc(size*sizeof(char));						//Ϊ�ṹ���е�S����ռ�
	for(int i=0;i<size;i++)										//���ַ����е�ÿһ���ַ�����ֵ'\0'
	{
		str->S[i]='\0';
	}
}


void StrEvaluate(pstring &S1,char S2[])
{	
	int size=0;
	S1->length=0;
	while(S2[size]!='\0')
	{
		size++;
	}
	size=size+1;
	if(size-1>S1->length)										//�������ֵ���ַ����������ȴ���
	{													//����ֵ�ַ������·���ռ�
		delete(S1->S);
		delete(S1);
		InitStr(S1,size);		
	}	
	for(int i=0;i<size-1;i++)									//�ӵ�һ��Ԫ�ؿ�ʼ��S1���и�ֵ
	{
		S1->S[i]=S2[i];
		S1->length++;										//�ַ����ĳ���ҲҪ�ı�
	}
	S1->S[S1->length]='\0';
}

void StrCopy(pstring &S1,pstring S2)
{
	if(S1->length<S2->length)	//Ϊ��ֵ�ַ������·���ռ�
	{
		delete(S1->S);
		delete(S1);
		InitStr(S1,S2->length+1);	
	}
	S1->length=0;
	for(int i=0;i<S2->length;i++)								//�ӵ�һ��Ԫ�ؿ�ʼ��S1���и�ֵ
	{
		S1->S[i]=S2->S[i];
		S1->length++;										//�ַ����ĳ���ҲҪ�ı�
		S1->S[S1->length]='\0';
	}
	S1->S[S1->length]='\0';
	
}

void StrConcat(pstring &S1,pstring S2)
{
	int len1=S1->length-1;
	int len2=S2->length-1;
	pstring s;
	if((len1+len2+1)>=S1->length)								//�жϳ����ǳ�����Χ
	{
		InitStr(s,len1+len2+1);								//��ʼ����
		for(int i=0;i<len1+1;i++)								//��S1���ƹ���
		{
			s->S[i]=S1->S[i];
			s->length++;
			s->S[s->length]='\0';		
		}
		for(int j=0;j<len2+1;j++)								//��S2���ƹ���
		{
			s->S[j+len1+1]=S2->S[j];
			s->length++;
			s->S[s->length]='\0';
		}
		StrCopy(S1,s);
		return;
	}
}

pstring SubStr(pstring S,int i,int length)
{
	pstring S1;
	InitStr(S1,length);										//��ʼ��Ҫ���ص��Ӵ�
	S1->length=0;
	if(i+length>S->length+1||i<=0)								//�ж��Ӵ��ĳ����Ƿ�Ϸ�
	{
		printf("%s","��ȡ�Ӵ��ѳ��������ĳ���!�Ӵ���ȡʧ��!");
	}
	else
	{
		for(int j=i-1;j<i+length-1;j++) 							//ȡ�Ӵ�
		{
			S1->S[j+1-i]=S->S[j];
			S1->length++;
			S1->S[S1->length]='\0';
		}
	}
	return S1;	
}

int StrComp(pstring S1,pstring S2)
{
	int i=0;
	while(S1->S[i]==S2->S[i]&&S1->S[i]!='\0')						//���ַ���ͬ���߳��֡�\0��ֹͣ�Ƚ�
	{
		i++;
	}
	if(S1->S[i]<S2->S[i])
	return -1;
	else if(S1->S[i]>S2->S[i])
	return 1;
	return 0;
}


int StrIndex(pstring S,pstring S1)
{
	if(S1->length>S->length) 
	return -1;												//�ж��Ӵ������Ƿ������������
	int i=0 ;												//���巵��ֵ
	char ch=S1->S[0];										//��ȡ�Ӵ������ַ�
	for(i=0;i<=S->length-S1->length;i++)
	{
		if(S->S[i]==ch)										//�ҵ�S1���ַ����ַ���S�е�λ��
			if(StrComp(SubStr(S,i+1,S1->length),S1)==0)			//�����Ⱦͷ��ص�ǰλ��
						return i+1;
	}
	if(i>S->length-S1->length)
	return -1;
}

void StrInsert(pstring &S,int i,pstring t)
{
	pstring S1;
	InitStr(S1,t->length+1);
	StrCopy(S1,t);										//��֤t��ֵ���䣬��t��������S1
	StrConcat(S1,SubStr(S,i,S->length-i+1));			//��S��i��ʼ�Ӵ����ӵ�S1��β����
	pstring S2;
	InitStr(S2,t->length+S->length+1);
	StrCopy(S2,SubStr(S,1,i-1));							//��s��ǰ�벿���Ӵ����Ƶ�S2��
	StrConcat(S2,S1);										//��S1���ӵ�S2��β��
	StrCopy(S,S2);										//��S2���Ƶ�S����ɲ���
}

void StrDelete(pstring &S,int i,int length)
{
	if((i+length)>S->length+1)									//�жϴ�ɾ�����±��Ƿ�Ϸ�
	{
		printf("%s","ɾ���±곬���ַ�����Χ!");
		return;
	}
	pstring S1,S2;
	InitStr(S1,length+1);
	InitStr(S2,length+1);
	StrCopy(S1,SubStr(S,1,i-1));								//ȡ��Ҫɾ���ط���ǰ���Ӵ�
	StrCopy(S2,SubStr(S,i+length,S->length-i-length+1));			//��ȡҪɾ���Ӵ��ĺ�벿���Ӵ�
	StrConcat(S1,S2);										//����ȡ���������Ӵ���������
	StrCopy(S,S1);											//ɾ�����ǲ����Ӵ�	
}

void StrReplace(pstring &S,int I,int length,pstring t)
{
	StrDelete(S,I,length);
	StrInsert(S,I,t);
}

void main()
{
	int loc,length;
	int flag=1;
	char j;
	char s2[100];
	pstring s,s1;//s��s1��������
	InitStr(s,100);//��ʼ����
	InitStr(s1,100);
	StrEvaluate(s,"abc");									//ִ�жԴ���ֵ����
	StrEvaluate(s1,"abc");//ִ�жԴ���ֵ����
//---------------------------�����˵--------------------------
 printf("����������ʵ�ֶѴ洢�ṹ�Ĵ���\n");
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
	  printf("7.�ַ������滻  \n");
	  printf("8.�˳� \n");
      scanf(" %c",&j);
      switch(j)
   {
   case '1':printf("%s\n",s->S); break; //��ʾ����Ԫ��
   case '2':{printf("��sΪ��%s\n��s1Ϊ��%s\n",s->S,s1->S);
			 StrConcat(s,s1);
             printf("���Ӻ���ַ���Ϊ��%s\n",s->S);//������Ӻ���ַ���
             break;
			}
   case '3':{printf("��sΪ��%s\n��s1Ϊ��%s\n",s->S,s1->S);
			 if(StrComp(s,s1))
				printf("s>s1\n");//s>s1
			 else
				printf("s<s1\n");//s<s1
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
			printf("ԭ���ַ���Ϊ:%s\n",s->S);
			StrInsert(s,loc,s1);
			printf("�������ַ���Ϊ:%s\n",s->S);
			break;
			}
	case '6':{printf("������Ҫɾ���Ĵ��Ŀ�ʼλ��,������2,3:");
			scanf("%d,%d",&loc,&length);  //�����Ӵ��Ŀ�ʼλ��,����
			printf("ԭ���ַ���Ϊ:%s\n",s->S);
			StrDelete(s,loc,length);
			printf("ɾ������ַ���Ϊ:%s\n",s->S);
			break;
			}
	case '7':printf("��sΪ��%s\n��s1Ϊ��%s\n",s->S,s1->S);
		StrReplace(s,2,1,s1);//ִ�д��滻����
		printf("��s�ӵ�2��λ�ÿ�ʼ����Ϊ1�Ĳ����滻Ϊs1�����Ϊ��%s\n",s->S);
		break;
   default:flag=0;printf("�����������������˳�!\n");
   }
 }
}