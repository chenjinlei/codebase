#include <stdio.h>
#include <malloc.h>
typedef char DataType;
typedef struct GLNode
{
	int tag;												//��־λtag��������ԭ�ӽ��ͱ���
	union													//����ָ�������������
	{
		DataType data;										//ԭ�ӽ���ֵ��data
		struct GLNode * head;								//�����ָ���������ͷָ����head
	};
	struct GLNode *next;									//��һ��Ԫ�ص�ָ��
}GList;
typedef GList* pGList;

void CreateGList(pGList &gl,char str[])
{
    char ch;												
    if(*str!='\0')
	{
		ch=*str;
		str++;
	}
    if(ch == '#')											//������Ϊ�������ñ�ͷָ��Ϊ��
	{
        gl = NULL;
    }
	else if(ch == '(')										//�����������������ӱ���
	{
        gl =(pGList)malloc(sizeof(struct GLNode));
        gl->tag = 1;
		gl->next=NULL;
		CreateGList((gl->head),str); 						//�ݹ鹹���ӱ�
    }
    else													//������Ԫ�ؽ��
	{
        gl =(pGList)malloc(sizeof(struct GLNode));
        gl->tag = 0;
        gl->data = ch;
	}
	if(*str!='\0')
	{
		ch=*str;
		str++;
	}
    if(gl == NULL)											//��glΪ�գ���ʲô������
	{
		;
    }
    else if(ch == ',')										//������Ϊ������ݹ鹹���̱�
	{
        CreateGList((gl->next),str);
    }
    else if((ch == ')') || (ch == ';'))						//���ָ����Ϊ��
	{
        gl->next = NULL;
    }
    return;
}

int DepthGList(struct GLNode *gl)
{
    int max = 0;
    while(gl != NULL)										//������㣬����ӱ��������
	{
        if(gl->tag == 1)
		{
            int dep = DepthGList(gl->head);						//�ݹ����һ���ӱ�����
            if(dep > max)									//maxΪͬһ���ӱ���������ֵ
			{
				max = dep;
            }
        }
        gl = gl->next;										//��glָ����һ�����
    }
    return max+1;											//���ر�����
}


void PrintGList(struct GLNode *gl)
{
    if(gl->tag == 1)										//���ڱ���Ĵ���
	{
        printf("(");										//�����ӱ������������ 
        if(gl->head == NULL)								//���ӱ�Ϊ�գ������'#'�ַ� 
		{
            printf("#");
        }
        else												//���ӱ�Ǳ���ݹ�����ӱ� 
		{
            PrintGList(gl->head);
        }
        printf(")");										//�������������������� 
    }
    else													//�Ե�����㣬ֱ����������ֵ 
	{
        printf("%c", gl->data);
    }
    if(gl->next != NULL)									//����ý��ĺ�̱� 
	{
        printf(", ");										//��������ŷָ� 
        PrintGList(gl->next);								//�ٵݹ������̱� 
    }
    return;
}

int main()
{
	GList *gl;
	gl=NULL;
	printf("������һ�����");
	char str[200];
	scanf("%s",str);
	CreateGList(gl,str);
	if(gl!=NULL)
	{
	printf("\n�����Ĺ����Ϊ��");
	PrintGList(gl);
	printf("\n���������Ϊ��%d\n",DepthGList(gl)-2);
	}
	return 0;
}