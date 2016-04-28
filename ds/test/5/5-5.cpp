#include <stdio.h>
#include <malloc.h>

#define MAXSIZE 100
typedef struct
{
	char S[MAXSIZE];
}SString;

int GetLength(SString s)
{
	int length=0;
	while(s.S[length]!='\0')							//ֻҪ�ַ���ֵ���ǡ�\0����length��ֵ��1
		length++;
	return length;
}

void InitStr(SString &str)
{
	for(int i=0;i<MAXSIZE;i++)				//�ӵ�һ��Ԫ�ص����Ԫ�س�ʼ��Ϊ'\0'
	{
		str.S[i]='\0';
	}
}

void StrEvaluate(SString &S1,char S2[])	//char S2[]���ַ�����һ���ַ�������
{
	if(GetLength(S1))
		InitStr(S1);										//��S1��ʼ��
	for(int i=0;S2[i]!='\0';i++)									//�ӵ�һ��Ԫ�ؿ�ʼ��S1���и�ֵ
		S1.S[i]=S2[i];
}

int Index(SString S,SString T, int pos)	//�򵥵�ģʽƥ��			
{//������S�д��ں�ģʽT��ͬ���Ӵ����򷵻��Ӵ���S�е�pos����֮���һ�γ��ֵ�λ��
	int i = pos, j = 1;
	while(i<=GetLength(S) && j <= GetLength(T))
	{
		if(S.S[i] == T.S[j-1])
		{
			++i;
			++j;
		}												//�����ȽϺ����ַ�
		else
		{ 
			i = i-j+2; 
			j =1;
		}												//ָ��������¿�ʼƥ��
	}
	if(j > GetLength(T))
		return i-GetLength(T)+1;							//ƥ��ɹ�
	else
		return -1;											//ƥ�䲻�ɹ�
}


void GetNext(char *T, int next[])								//��ģʽ��T��next����ֵ����������
{
	int j = 0,k = -1; 
	next[0] = -1; 
	while ( T[j] != '\0') 
	{ 
		if (k == -1 || T[j] == T[k]) 
		{ 
			++j; ++k; 
			if (T[j]!=T[k]) 
				next[j] = k; 
			else 
				next[j] = next[k]; 
		}
		else 
			k = next[k]; 
	}  
}

int KMP(char *s,char* t) //�Ľ���ģʽƥ��
{
	int len=0; 
	const char * t1=t; 
	while(t1[len]!='\0')										//���ַ���t�ĳ���
	{ 
		++len;
	} 
	int *next=(int *)malloc(sizeof(int)*(len+1));						//Ϊnext���鶯̬����ռ�
	GetNext(t,next);										//��t��next����ֵ 
	int index=0,i=0,j=0;										//index��ǰƥ��t[0]��s�е�λ��
	while(s[i]!='\0'&&t[j]!='\0') 
	{ 
		if(s[i]== t[j])										//�����ȵĻ���������Ƚ�
		{ 
			++i;
			++j; 
		} 
		else												//��������
		{ 
			index += j-next[j];								//index��ֵ�����ƶ�j-next[j]
			if(next[j]!=-1) 
				j=next[j];									//���next[j]!=-1����s[i]��t[next[j]]�Ƚ�
			else 
			{
				j=0;										//���next[j]=-1����s[i+1]��t[0]�Ƚ�
				++i; 
			}
		}
	}
	delete []next;											//�ͷ�Ϊnext��̬����Ŀռ�
	if(t[j]=='\0')
		return index+1;										// ƥ��ɹ�
	else
		return -1; 											// ƥ��ʧ��
}

void main()
{
	int loc,length;
	int flag=1;
	char j;
	char s2[100];
	SString s,s1,substring;//s��s1��������
	InitStr(s);//��ʼ����
	InitStr(s1);
	InitStr(substring);
	StrEvaluate(s,"abc");									//ִ�жԴ���ֵ����
	StrEvaluate(s1,"abc");//ִ�жԴ���ֵ����
//---------------------------�����˵--------------------------
 printf("����������ʵ�ִ��ļ�ģʽƥ��͸Ľ���ģʽƥ�䡣\n");
 printf("����ʵ�ֲ��ҡ����롢ɾ���Ȳ�����\n");
 //-------------------------------------------------------------
  while(flag)
    { printf("��ѡ��:\n");
      printf("1.�򵥵�ģʽƥ��\n");
      printf("2.�Ľ���ģʽƥ��\n");
      printf("3.�˳�  \n");
	  scanf(" %c",&j);
   switch(j)
   {
   case '1':printf("������Ҫ����Ӵ���");
			 scanf("%s",s2);//�����Ӵ�
			 StrEvaluate(s1,s2);
			 printf("�����Ӵ���0λ��֮�󣬵�һ�γ��ֵ�λ�ã�%d\n",Index(s,s1,0));//����Ӵ���λ��Index(s,s1,0)
			 break; 
   case '2':printf("������Ҫ����Ӵ���");
			 scanf("%s",s2);//�����Ӵ�
			 StrEvaluate(s1,s2);
			 printf("�����Ӵ���0λ��֮�󣬵�һ�γ��ֵ�λ�ã�%d\n",KMP(s.S,s2));//����Ӵ���λ��Index(s,s1,0)
			 break; 
   
   default:flag=0;printf("�����������������˳�!\n");
   }
 }
}