#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node {
	element data;
	struct node *next;
} node;

typedef node *linkedlist;


linkedlist reverse(linkedlist );


int main()
{
	linkedlist list1, list2;
	int sample = 998;

	list1 = (linkedlist)malloc(sizeof(node));
	if (list1 == NULL) {
		printf("malloc error!\n");
		return 1;
	}

	list1->data = sample;
	list1->next = NULL;

	list2 = list1;

	for (int i = 0; i < 5; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(node));
		tmp->data = sample;
		tmp->next = list2->next;
		list2->next = tmp;
		list2 = tmp;
		++sample;
	}

	printf("Before reverse: ");
	list2 = list1;
	list2 = list1->next;
	while (list2 != NULL) {
		printf("%d ", list2->data);
		list2 = list2->next;
	}
	printf("\n");

	reverse(list1);

	printf("After reverse: ");
	list1 = list1->next;
	while(list1 != NULL) {
		printf("%d ", list1->data);
		list1 = list1->next;
	}
	printf("\n");

	return 0;
}

linkedlist reverse(linkedlist list) {

	node *p, *q;

	if (list->next && list->next->next) {
		p = list->next;
		q = p->next;
		p->next = NULL;
		while (q) {
			p  = q;
			q = q->next;
			p->next = list->next;
			list->next = p;
		}
		return list;
	}
	return list;

}
