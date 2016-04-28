/**��ϣ����ۺϲ��� **/
/**CONTENT :Insert,Search,Deltet **/
/* * * * * * * * * * * * * * * * * * * * * * * **/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 30 /*��ϣ�������������������õĹ�ϣ�����й�*/
typedef enum{False,True}  BOOL;
typedef enum{NULLKEY,HAVEKEY,DELKEY} HAVEORNOT;
/*��ϣ��Ԫ�ص�����״̬��û�м�¼���м�¼���й���¼���ѱ�ɾ��*/
typedef struct /*�����ϣ��Ľṹ*/
{
int elem[MAXSIZE]; /* ����Ԫ���� */
HAVEORNOT elemflag[MAXSIZE]; /*Ԫ��״̬��־��û�м�¼���м�¼���й���¼���ѱ�ɾ��*/
int count; /*��ϣ���е�ǰԪ�صĸ��� */
}HashTable;
typedef struct
{int keynum; /*��¼��������ֻ�йؼ���һ��*/
}Record;
void InitialHash(HashTable*); /*��ʼ����ϣ��*/
void CreateHash(HashTable*);/* ���ݴӼ����������һϵ������������ϣ�� */
void PrintHash(HashTable); /*��ʾ��ϣ���е�����Ԫ��*/
BOOL SearchHash(HashTable,int,int*); /*�ڹ�ϣ���в���Ԫ��*/
BOOL InsertHash(HashTable*,Record); /*�ڹ�ϣ���в���Ԫ��*/
BOOL DeleteHash(HashTable*,Record); /*�ڹ�ϣ����ɾ��Ԫ��*/
int Hash(int); /*��ϣ����*/
void main()
{HashTable H; /*������ϣ��H*/
char ch,j='y';
int position;
Record R;
BOOL temp;

InitialHash(&H);
CreateHash(&H);
/*-------------------------����˵��-------------------------------*/
printf("This program will show how to operate to a HashTable.\n");
printf("You can display all elems,search a elem,\ninsert a elem,delete a elem.\n");
/*----------------------------------------------------------------*/

while(j!='n')
{printf("1.display\n");
printf("2.search\n");
printf("3.insert\n");
printf("4.delete\n");
printf("5.exit\n");
scanf(" %c",&ch);
switch(ch)
{case '1':if(H.count) PrintHash(H); /*��ϣ����*/
else printf("The HashTable has no elem!\n");
break;
case '2':if(!H.count) printf("The HashTable has no elem!\n"); /*��ϣ���*/
else
{printf("Please input the keynum(int) of the elem to search:");
scanf("%d",&R.keynum); /*��������¼�Ĺؼ���*/
temp=SearchHash(H,R.keynum,&position);
/*temp=True:��¼���ҳɹ���temp=False:û���ҵ������¼*/
if(temp) printf("The position of the elem is %d\n",position);
else printf("The elem isn't exist!\n");
}
break;
case '3':if(H.count==MAXSIZE) /*��ϣ������*/
{printf("The HashTable is full!\n");
break;
}
printf("Please input the elem(int) to insert:");
scanf("%d",&R.keynum); /*����Ҫ����ļ�¼*/
temp=InsertHash(&H,R);
/*temp=True:��¼����ɹ���temp=False:�Ѵ��ڹؼ�����ͬ�ļ�¼*/
if(temp) printf("Sucess to insert the elem!\n");
else printf("Fail to insert the elem.The same elem has been exist!\n");
break;
case '4':printf("Please input the keynum of the elem(int) to delet:");
scanf("%d",&R.keynum); /*����Ҫɾ����¼�Ĺؼ���*/
temp=DeleteHash(&H,R);
/*temp=True:��¼ɾ���ɹ���temp=False:��ɾ��¼������ */
if(temp) printf("Sucess to delete the elem!\n");
else printf("The elem isn't exist in the HashTable!\n");
break;
default: j='n';
}
}
printf("The program is over!\nPress any key to shut off the window!\n");
getchar();
}
void InitialHash(HashTable *H)
{/*��ϣ���ʼ��*/
int i;
(*H).count=0;
for(i=0;i<MAXSIZE;i++) (*H).elemflag[i]=NULLKEY;
}
void CreateHash(HashTable *H)
{/* ���ݴӼ����������һϵ��������������12������-1������������ϣ�� */
 Record e;
 printf("�������һϵ������(������12������-1����)�Խ�����ϣ��:\n");
 scanf("%d",&e.keynum);
 while(e.keynum!=-1)
    if(InsertHash(H,e))  scanf("%d",&e.keynum);
    else 
      {printf("�����벻�ظ������ݣ�");
       return;
       }     
}

void PrintHash(HashTable H)
{/*��ʾ��ϣ������Ԫ�ؼ�������λ��*/
int i;
for(i=0;i<MAXSIZE;i++) /*��ʾ��ϣ���м�¼����λ��*/
if(H.elemflag[i]==HAVEKEY) /*ֻ��ʾ��־ΪHAVEKEY(����м�¼)��Ԫ��*/
printf("%-4d",i);
printf("\n");
for(i=0;i<MAXSIZE;i++) /*��ʾ��ϣ���м�¼ֵ*/
if(H.elemflag[i]==HAVEKEY)
printf("%-4d",H.elem[i]);
printf("\ncount:%d\n",H.count); /*��ʾ��ϣ��ǰ��¼��*/
}
BOOL SearchHash(HashTable H,int k,int *p)
{/*�ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���Ϊk������Ԫ�أ������ҳɹ�����pָʾ
��������Ԫ���ڱ��е�λ�ã�������True��������pָʾ����λ�ã���
����False*/
int p1;
p1=(*p)=Hash(k); /*��ù�ϣ��ַ*/
while(H.elemflag[(*p)]==HAVEKEY&&k!=H.elem[(*p)]) 
/*��λ�������м�¼���ҹؼ��ֲ����*/
{(*p)++; /*��ͻ������������̽����ɢ��*/
if((*p)>=MAXSIZE) (*p)=(*p)%MAXSIZE; /*ѭ������*/
if((*p)==p1) return False; /*�������������꣬û���ҵ�����Ԫ��*/
}
if(k==H.elem[(*p)]&&H.elemflag[(*p)]==HAVEKEY) /*���ҳɹ���pָʾ����Ԫ��λ��*/
return True; 
else return False; /*���Ҳ��ɹ�*/
}
BOOL InsertHash(HashTable *H,Record e)
{/*���Ҳ��ɹ�ʱ����Ԫ��e�����Ŷ�ַ��ϣ��H�У�������True�����򷵻�False*/
int p;
if(SearchHash((*H),e.keynum,&p)) /*����������e����ͬ�ؼ��ֵ�Ԫ��*/
return False;
else
{(*H).elemflag[p]=HAVEKEY; /*���ñ�־ΪHAVEKEY����ʾ��λ�����м�¼*/
(*H).elem[p]=e.keynum; /*�����¼*/
(*H).count++; /*��ϣ��ǰ���ȼ�һ */
return True;
}
}
BOOL DeleteHash(HashTable *H,Record e)
{/*�ڲ��ҳɹ�ʱɾ����ɾԪ��e��������True�����򷵻�False*/
int p;
if(!SearchHash((*H),e.keynum,&p)) /*���в����ڴ�ɾԪ��*/
return False;
else
{(*H).elemflag[p]=DELKEY; /*���ñ�־ΪDELKEY��������Ԫ���ѱ�ɾ��*/
(*H).count--; /*��ϣ��ǰ���ȼ�һ*/
return True;
}
}
int Hash(int kn)
{/*��ϣ������H(key)=key MOD 11*/
return (kn%11);
} 
