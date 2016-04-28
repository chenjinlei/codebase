#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
typedef struct
{
	char S[MAXSIZE];
}SString;

void InitStr(SString &str)
{
	for(int i=0;i<MAXSIZE;i++)				//�ӵ�һ��Ԫ�ص����Ԫ�س�ʼ��Ϊ'\0'
	{
		str.S[i]='\0';
	}
}

int GetLength(SString s)
{
	int length=0;
	while(s.S[length]!='\0')							//ֻҪ�ַ���ֵ���ǡ�\0����length��ֵ��1
		length++;
	return length;
}

void StrEvaluate(SString &S1,char S2[])	//char S2[]���ַ�����һ���ַ�������
{
	if(GetLength(S1))
		InitStr(S1);										//��S1��ʼ��
	for(int i=0;S2[i]!='\0';i++)									//�ӵ�һ��Ԫ�ؿ�ʼ��S1���и�ֵ
		S1.S[i]=S2[i];
}

/*void StrEvaluate(SString &S1,char S2[])
  {
  for(int i=0;S2[i]!='\0';i++)									//�ӵ�һ��Ԫ�ؿ�ʼ��S1���и�ֵ			S1.S[i]=S2[i];
  }*/

void StrCopy(SString &S1,SString S2)
{
	if(GetLength(S1))										//���S1�ĳ���Ϊ0����ô�Ͳ���ʼ��
		InitStr(S1);
	for(int i=0;i<=GetLength(S2);i++)							//�ӵ�һ��Ԫ����S2���ַ�����S1
		S1.S[i]=S2.S[i];
}

void StrConcat(SString &S1,SString S2)
{
	int len1=GetLength(S1);
	int len2=GetLength(S2);
	if((len1+len2+1)>MAXSIZE)								//��һ���ռ������'\0'����Ҫ+1				
		printf("%s","���ȳ�����󳤶Ƚ����ȡ�����ַ�����");
	for(int i=len1;i<len1+len2&&i<MAXSIZE;i++)					//�ж��Ƿ���Ҫ��ȡ��
		S1.S[i]=S2.S[i-len1];
}

SString SubStr(SString S,int i,int length)
{
	SString S1;
	InitStr(S1);											//��ʼ��Ҫ���ص��Ӵ�
	if(i+length>GetLength(S)+1||i<=0)							//�ж��Ӵ������Ƿ�Ϸ�
	{
		printf("%s","��ȡ�Ӵ��ѳ��������ĳ���!�Ӵ���ȡʧ��!");
	}
	else
	{
		for(int j=i-1;j<i+length-1;j++)							//ִ��ȡ�ִ�����
			S1.S[j+1-i]=S.S[j];
	}
	return S1;
}

int StrComp(SString S1,SString S2)
{
	int i=0;
	while(S1.S[i]==S2.S[i]&&S1.S[i]!='\0')						//�ַ���ͬ����֡�\0��ֹͣ�Ƚ�
	{
		i++;
	}
	if(S1.S[i]<S2.S[i])
		return -1;
	else if(S1.S[i]>S2.S[i])
		return 1;
	return 0;
}


int StrIndex(SString S,SString S1)
{
	if(GetLength(S1)>GetLength(S)) 
		return -1;												//�ж��Ӵ������Ƿ�Ϸ�
	int i=0 ;												//���巵��λ�ñ���
	char ch=S1.S[0];										//��ȡ�Ӵ������ַ�
	for(i=0;i<=GetLength(S)-GetLength(S1);i++)
	{
		if(S.S[i]==ch)										//�ҵ�S1���ַ����ַ���S�е�λ��
			if(StrComp(SubStr(S,i+1,GetLength(S1)),S1)==0)		//�����Ⱦͷ��ص�ǰλ��
				return i+1;
	}
	if(i>GetLength(S)-GetLength(S1))
		return -1;
}

void StrInsert(SString &S,int i,SString t)
{
	if(GetLength(S)+GetLength(t)>=MAXSIZE)					//�жϳ����Ƿ�Ϸ�
	{
		printf("%s","����������������!");
		return;
	}
	if(i>GetLength(S)+1)										//�жϲ���λ���Ƿ�Ϸ�
	{
		printf("%s","����λ�ó�������ĳ���!"); 
		return;
	}
	SString S1;
	InitStr(S1);
	StrCopy(S1,t);											//��t���Ƹ�һ������S1
	StrConcat(S1,SubStr(S,2,GetLength(S)-i+1));					//��S��i������Ӵ����ӵ�S1β��
	SString S2;
	InitStr(S2);	
	S2=SubStr(S,1,i-1);										//��s��ǰ�벿���Ӵ����Ƶ�S2��
	StrConcat(S2,S1);										//��S1���ӵ�S2��β��
	StrCopy(S,S2);											//��S2���Ƶ�S����ɲ���
}

void StrDelete(SString &S,int i,int length)
{
	if((i+length)>GetLength(S)+1)								//ɾ���±곬���ַ�����Χ����ɾ��
	{
		printf("%s","ɾ���±곬���ַ�����Χ!");
		return;
	}
	SString S1,S2;
	InitStr(S1);
	InitStr(S2);
	StrCopy(S1,SubStr(S,1,i-1)); 								//ȡ��Ҫɾ���ط���ǰ���Ӵ�
	StrCopy(S2,SubStr(S,i+length,GetLength(S)-i-length+1));			//��ȡҪɾ���Ӵ��ĺ�벿���Ӵ�
	StrConcat(S1,S2);										//����ȡ���������Ӵ���������
	StrCopy(S,S1);											//ɾ�����ǲ����Ӵ�
}

void StrReplace(SString &S,int I,int length,SString t)
{
	StrDelete(S,I,length);
	StrInsert(S,I,t);
}

void main()
{
	int loc,length;
	int flag=1;
	char j,ch;
	SString s,s1;//s��s1��������
	InitStr(s);//��ʼ����
	InitStr(s1);
	StrEvaluate(s,"abc");									//ִ�жԴ���ֵ����
	StrEvaluate(s1,"abc");//ִ�жԴ���ֵ����
	//---------------------------�����˵--------------------------
	printf("����������ʵ��˳��ṹ�Ĵ���\n");
	printf("����ʵ�ֲ��ҡ����롢ɾ���Ȳ�����\n");
	//-------------------------------------------------------------
	while(flag)
	{ printf("��ѡ��:\n");
		printf("1.��ʾ����Ԫ��\n");
		printf("2.���ַ����ĳ���\n");
		printf("3.���ַ������Ӵ�\n");
		printf("4.��������\n");
		printf("5.�ַ����ıȽ�  \n");
		printf("6.���Ӵ���λ��  \n");
		printf("7.�ַ����Ĳ���\n");
		printf("8.�ַ�����ɾ��  \n");
		printf("9.�ַ������滻  \n");
		printf("10.�˳� \n");
		scanf(" %c",&j);
		switch(j)
		{
		case '1':printf("%s\n",s.S); break; //��ʾ����Ԫ��
		case '2':printf("����Ϊ��%d\n",GetLength(s)); break;//�󴮳�     
		case '3':{printf("�������Ӵ��Ŀ�ʼλ��,������2,3:");
			scanf("%d,%d",&loc,&length);  //�����Ӵ��Ŀ�ʼλ��,����
			printf("�����Ӵ�Ϊ��%s\n",SubStr(s,loc,length).S);//���Ӵ�SubStr(s,loc,length)
			break;
		}
		case '4':{printf("��sΪ��%s\n��s1Ϊ��%s\n",s.S,s1.S);
			StrConcat(s,s1);
			printf("���Ӻ���ַ���Ϊ��%s\n",s.S);//������Ӻ���ַ���
			break;
		}
		case '5':{printf("��sΪ��%s\n��s1Ϊ��%s\n",s.S,s1.S);
			if(StrComp(s,s1))
				printf("s>s1\n");//s>s1
			else
				printf("s<s1\n");//s<s1
			break;
		}
		case '6':{printf("������Ҫ����Ӵ���");
			scanf("%s",s1.S);//�����Ӵ�
			printf("�����Ӵ���һ�γ��ֵ�λ�ã�%d\n",StrIndex(s,s1));//����Ӵ���λ��StrIndex(s,s1)
			break;
		}
		case '7':{printf("������Ҫ����λ��:");
			scanf("%d",&loc);  //�����Ӵ��Ŀ�ʼλ��,����
			printf("������Ҫ������Ӵ���");
			scanf("%s",s1.S);//����Ҫ������ַ���
			printf("ԭ���ַ���Ϊ:%s\n",s.S);
			StrInsert(s,loc,s1);
			printf("�������ַ���Ϊ:%s\n",s.S);
			break;
		}
		case '8':{printf("������Ҫɾ���Ĵ��Ŀ�ʼλ��,������2,3:");
			scanf("%d,%d",&loc,&length);  //�����Ӵ��Ŀ�ʼλ��,����
			printf("ԭ���ַ���Ϊ:%s\n",s.S);
			StrDelete(s,loc,length);
			printf("ɾ������ַ���Ϊ:%s\n",s.S);
			break;
		}
		case '9':printf("��sΪ��%s\n��s1Ϊ��%s\n",s.S,s1.S);
			 StrReplace(s,2,1,s1);//ִ�д��滻����
			 printf("��s�ӵ�2��λ�ÿ�ʼ����Ϊ1�Ĳ����滻Ϊs1�����Ϊ��%s\n",s.S);
			 break;
		default:flag=0;printf("�����������������˳�!\n");
		}
	}
}
