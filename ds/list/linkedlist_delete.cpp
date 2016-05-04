#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node {
	element data;
	struct node *next;
} linkedlistnode;

typedef linkedlistnode *linkedlist;

void delete_duplicate_node(linkedlist );

int main()
{
	linkedlist list1, list2;
	element sample = 866;

	list1 = (linkedlist)malloc(sizeof(linkedlistnode));
	list1->next = NULL;

	list2 = list1;
	for (int i = 0; i < 5; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(linkedlistnode));
		tmp->data = sample;
		tmp->next = list2->next;
		list2->next = tmp;
		list2 = tmp;
	}

	printf("Before delete: ");
	list2 = list1;
	list2 = list2->next;
	while (list2 != NULL) {
		printf("%d ", list2->data);
		list2 = list2->next;
	}
	printf("\n");

	delete_duplicate_node(list1);

	printf("After delete: ");
	list1 = list1->next;
	while (list1 != NULL) {
		printf("%d ", list1->data);
		list1 = list1->next;
	}
	printf("\n");

	return 0;
}


void delete_duplicate_node(linkedlist list) {

	linkedlistnode *p, *q, *s;

	p = list->next;

	if (p == NULL)
		return ;

	while (p->next && p->next->next) {
		q = p;
		while (q->next) {
			if (q->next->data == p->data) {
				s = q->next;
				q->next = s->next;
				free(s);
			} else {
				q = q->next;
			}
		}

		if (p->next)
			p = p->next;
	}

}
