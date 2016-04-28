#include "stdio.h"
#include <stdlib.h>
#define MAXSIZE 100
typedef int DataType;				//DataType��������Ԥ����
typedef struct
{
	DataType elem[MAXSIZE];								//������Ԫ��
	int front;												//��ͷ
	int rear;												//��β
}Queue;

void Init_Queue(Queue &Q)
{
	Q.rear=0;
	Q.front=0;
}

bool Queue_Empty(Queue Q)
{
	if(Q.front==Q.rear)										//front=rearʱ������Ϊ��
		return true;
	else
		return false;
}

bool Queue_Full(Queue Q)
{
	if(Q.rear+1==MAXSIZE)									//rear+1����MAXSIZE������Ϊ��
		return true;
	else
		return false;
}

void In_Queue(Queue &Q,DataType elem)
{
	if(!Queue_Full(Q))
	{
        Q.elem[Q.rear]=elem;
		Q.rear=Q.rear+1;									//���β����Ԫ�أ��Ƚ�rearǰ��һλ
	}
	else
		printf("����������");
}

DataType Get_Top(Queue Q)
{
	if(!Queue_Empty(Q))										//������в�Ϊ�գ����ض�ͷԪ��
	{
		return Q.elem[Q.front];
	}
	else
		printf("�������Ѿ�û��Ԫ�أ�");
	 
}

DataType Out_Queue(Queue &Q)
{
	if(!Queue_Empty(Q))
	{
		DataType ch=Get_Top(Q);
        Q.front=Q.front+1;
		return ch;
	}
	else
		printf("�����ѿգ�");
}


//ũ���������
		
int farmer(int location)										//�ж�ũ���λ��
{
    return (0 != (location &0x08));
}
int wolf(int location)											//�ж��ǵ�λ��
{
    return (0 != (location &0x04));
}
int cabbage(int location) 										//�жϰײ˵�λ��
{
    return (0 != (location &0x02));
}
int goat(int location)											 //�ж����λ��
{
    return (0 != (location &0x01));
}
int safe(int location)											//��״̬��ȫ�򷵻�true
{	
	if ((goat(location) == cabbage(location)) && (goat(location) != farmer	//��԰ײ�
        (location)))
        return (0);
    if ((goat(location) == wolf(location)) && (goat(location) != farmer		//�ǳ���
        (location)))
        return (0);
    return (1); 												//����״̬�ǰ�ȫ��
}
void farmerproblem()
{
    int i, movers, location, newlocation;
    int route[16];											//���ڼ�¼�ѿ��ǵ�״̬·��
	Queue moveTo;											//���ڼ�¼���԰�ȫ������м�״̬
	Init_Queue(moveTo);
    In_Queue (moveTo, 0x00);								//��ʼ״̬������
    for (i = 0; i < 16; i++)
        route[i] =  - 1;	
    route[0] = 0;											//׼������route��ֵ
    while (!Queue_Empty(moveTo) && (route[15] ==  - 1))
    {
        location =Get_Top(moveTo);							//ȡ��ͷ״̬Ϊ��ǰ״̬
        Out_Queue (moveTo);
        for (movers = 1; movers <= 8; movers <<= 1)				//���Ǹ�����Ʒ�ƶ�
            if ((0 != (location &0x08)) == (0 != (location &movers)))		//ũ�����ƶ�����Ʒ��ͬһ��
			{
				newlocation = location ^ (0x08 | movers);			//������״̬
				if (safe(newlocation) && (route[newlocation] == - 1))	//��״̬��ȫ��δ����
				{
					route[newlocation] = location;				//��¼��״̬��ǰ��
					In_Queue (moveTo, newlocation);			//��״̬���
				}
			}
    }
    														//��ӡ��·��
    if (route[15] !=  - 1)										//��������״̬
    {
        printf("�����·��Ϊ: \n");
        for (location = 15; location >= 0; location = route[location])
        {
            printf("��ǰλ�� : %d\n", location);
            if (location == 0)
                exit(0);
        }
    }
    else
        printf("�����޽�.\n");									//�����޽�
}
void main()
{
	farmerproblem();
}