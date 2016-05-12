#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
	element data;
	struct node *next;
} linkedlistnode;

typedef linkedlistnode *linkedlist;

linkedlist merge(linkedlist , linkedlist );

int main()
{
	linkedlist list1, list2, list3;
	element sample = 456;

	list1 = (linkedlist)malloc(sizeof(linkedlistnode));
	list1->next = NULL;

	list2 = list1;
	for (int i = 0; i < 5; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(linkedlistnode));
		tmp->data = sample;
		tmp->next = list2->next;
		list2->next = tmp;
		list2 = tmp;
		sample++;
	}

	sample = sample - 2;
	list3 = (linkedlist)malloc(sizeof(linkedlistnode));
	list3->next = NULL;

	list2 = list3;
	for (int i = 0; i < 6; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(linkedlistnode));
		tmp->data = sample;
		tmp->next = list2->next;
		list2->next = tmp;
		list2 = tmp;
		sample++;
	}

	printf("list1: ");
	list2 = list1->next;
	while (list2) {
		printf("%d ", list2->data);
		list2 = list2->next;
	}
	printf("\n");

	printf("list3: ");
	list2 = list3->next;
	while (list2) {
		printf("%d ", list2->data);
		list2 = list2->next;
	}
	printf("\n");

	linkedlist result = merge(list1, list3);
	printf("After merge: ");
	list2 = result->next;
	while (list2) {
		printf("%d ", list2->data);
		list2 = list2->next;
	}
	printf("\n");

	return 0;

}


linkedlist merge(linkedlist list1, linkedlist list2) {

	linkedlist result;
	linkedlistnode *p, *q, *s;

	result = list1;
	result->next = NULL;
	free(list2);

	p = list1->next;
	q = list2->next;

	while (p && q) {
		if (p->data < q->data) {
			s = p;
			p = p->next;
		} else {
			s = q;
			q = q->next;
		}
		s->next = result->next;
		result->next = s;
	}

	if (p == NULL)
		p = q;

	while (p) {
		s = p;
		p = p->next;
		s->next = result->next;
		result->next = s;
	}

	return result;

}
