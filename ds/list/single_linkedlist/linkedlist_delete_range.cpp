#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
	element data;
	struct node *next;
} linkedlistnode;

typedef linkedlistnode *linkedlist;

void delete_range(linkedlist list, int low, int high);

int main()
{
	linkedlist list1, list2;
	element sample = 248;

	list1 = (linkedlist)malloc(sizeof(sizeof(linkedlistnode)));
	list1->next = NULL;

	list2 = list1;
	for (int i = 0; i < 5; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(linkedlistnode));
		tmp->data = sample++;
		tmp->next = list2->next;
		list2->next = tmp;
		list2 = tmp;
	}

	printf("list: ");
	list2 = list1->next;
	while (list2) {
		printf("%d ", list2->data);
		list2 = list2->next;
	}
	printf("\n");

	delete_range(list1, 249, 251);

	printf("After delete_range: ");
	list2 = list1->next;
	while (list2) {
		printf("%d ", list2->data);
		list2 = list2->next;
	}
	printf("\n");

	return 0;
}

void delete_range(linkedlist list, int low, int high) {

	linkedlist p, s;

	p = list->next;
	s = list;

	while (p) {
		if (p->data >= low && p->data <= high) {
			s->next = p->next;
			free(p);
			p = s->next;
		} else {
			p = p->next;
			s = s->next;
		}
	}
}
