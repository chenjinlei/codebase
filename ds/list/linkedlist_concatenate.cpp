#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
	element data;
	struct node *next;
} linkedlistnode;

typedef linkedlistnode *linkedlist;

linkedlist concatenate(linkedlist , linkedlist , int , int );

int main()
{
	linkedlist list1, list2, list3;
	element sample = 567;

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

	sample = sample + 1;
	list3 = (linkedlist)malloc(sizeof(linkedlistnode));
	list3->next = NULL;

	list2 = list3;
	for (int i = 0; i < 6; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(linkedlistnode));
		tmp->data = sample;
		tmp->next = list2->next;
		list2->next = tmp;
		list2 = tmp;
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

	linkedlist result = concatenate(list1, list3, 5, 6);

	printf("After concatenate: ");
	list2 = result->next;
	while (list2) {
		printf("%d ", list2->data);
		list2 = list2->next;
	}
	printf("\n");

	return 0;
}


linkedlist concatenate(linkedlist list1, linkedlist list2,
		       int m, int n) {

	linkedlistnode *p, *q, *s;

	if (m <= n) {
		s = list1;
		q = list2->next;
		free(list2);
	} else {
		s = list2;
		q = list1->next;
		free(list1);
	}
	p = s;
	while (p->next) {
		p = p->next;
	}
	p->next = q;

	return s;
}
