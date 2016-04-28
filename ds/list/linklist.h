#ifndef _LINKLIST_H
#define _LINKLIST_H

typedef struct linklist {
	int num;
	struct linklist* next;
} list;

void init(list* linklist, int len);
void input(list* linklist);
int find(int num);
void print(list* );

#endif
