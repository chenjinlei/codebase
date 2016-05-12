#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
	element data;
	struct node *next;
} linkedlistnode;

typedef linkedlistnode *linkedlist;

linkedlist connect(linkedlist , linkedlist );

int main()
{
	linkedlist list1, list2, list3;
	element sample = 232;

	list1 = (linkedlist)malloc(sizeof(linkedlistnode));
	list1->next = NULL;

	list2 = list1;
	for (int i = 0; i < 5; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(linkedlistnode));
		tmp->data = sample++;
		tmp->next = list2->next;
		list2->next = tmp;
		list2 = tmp;
	}
	list2->next = list1->next;
	// point to the last element
	list1->next = list2;

	list3 = (linkedlist)malloc(sizeof(linkedlistnode));
	list3->next = NULL;

	list2 = list3;
	for (int i = 0; i < 5; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(linkedlistnode));
		tmp->data = sample++;
		tmp->next = list2->next;
		list2->next = tmp;
		list2 = tmp;
	}
	list2->next = list3->next;
	// point to the last element
	list3->next = list2;

	linkedlist result = connect(list1, list3);

	do {
		printf("%d ", result->next->data);
		result = result->next;
	} while (result->next != list1->next);

	printf("\n");

	return 0;

}

linkedlist connect(linkedlist list1, linkedlist list2) {

	linkedlist p = list1->next->next;// first node of list1
	list1->next->next = list2->next->next;
	list2->next->next = p;
	free(list2);
	list1->next = p;

	return list1;

}
