#include <stdio.h>
#include <stdlib.h>
# define vtxnum 5
# define null 0

struct arcnode
{
	int adjvex;
	struct arcnode *next;
};

struct vexnode
{
	int data;
	struct arcnode *firstarc;
};

int main()
{
	int i, j, flag;
	int ch;
	struct arcnode *p, *s, *z;

	struct vexnode a[6];

	for (i = 1; i <= vtxnum; i++)
	{
		flag = 0;

		a[i].firstarc = null;

		a[i].data = i;

		do{
			printf("ͼ��%d����н�������������?[�й���������0,�޹���������1]:", i);

			scanf("%d", &ch);

			if (ch == 0)
			{
				printf("������%d���������Ľ��,���������", i);

				scanf("%d", &j);
				p = (struct arcnode *)malloc(sizeof(struct arcnode));
				a[i].firstarc = p;

				s = p;
				z = s;

				while (j != 0)
				{
					flag = flag+1;

					while ((j<0) || (j>vtxnum))
					{
						printf("��������Ľ��ų����涨��Χ,����������%d�����صĽ��", i);
						scanf("%d", &j);
					}

					if (j != 0) {
						z = s;
						s->adjvex = j;

						p = (struct arcnode *)malloc(sizeof(struct arcnode));

						s->next = p;
						s = p;
					} else {
						if (flag == 1)
							a[i].firstarc = null;
						else
							z->next = null;
					}

					printf("������%d���������Ľ��,���������", i);
					scanf("%d", &j);
				}
				z->next = null;
			}
			else
			{
				if (ch == 1)
					a[i].firstarc = null;
				else
					printf("��������");
			}
		} while((ch != 1) && (ch != 0));
	}

	for (i = 1; i <= vtxnum; i++)
	{
		p = a[i].firstarc;
		if (p == null)
			printf("%d�����һ���������", i);
		else {
			printf("%d", i);
			while (p)
			{
				printf("----->");
				printf("%d", p->adjvex);
				p = p->next;
			}
		}

		printf("\n");
	}
}
