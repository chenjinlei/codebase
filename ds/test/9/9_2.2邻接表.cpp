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
			printf("图中%d结点有结点与其相关连吗?[有关联请输入0,无关联请输入1]:", i);

			scanf("%d", &ch);

			if (ch == 0)
			{
				printf("输入与%d结点相关联的结点,键入零结束", i);

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
						printf("您所输入的结点号超出规定范围,重新输入与%d结点相关的结点", i);
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

					printf("输入与%d结点相关联的结点,键入零结束", i);
					scanf("%d", &j);
				}
				z->next = null;
			}
			else
			{
				if (ch == 1)
					a[i].firstarc = null;
				else
					printf("重新输入");
			}
		} while((ch != 1) && (ch != 0));
	}

	for (i = 1; i <= vtxnum; i++)
	{
		p = a[i].firstarc;
		if (p == null)
			printf("%d结点是一个孤立结点", i);
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
