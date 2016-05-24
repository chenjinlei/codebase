#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

linkedlist create_list_head() {

	int num;
	linkedlist list = (linkedlist) malloc(sizeof(struct node));
	list->next = NULL;

	printf("Please enter the size of the list: ");
	scanf("%d", &num);

	listnode *p = list;
	for (int i = 0; i < num; ++i) {
		listnode *tmp = (listnode *) malloc(sizeof(struct node));
		scanf("%d", &tmp->data);
		tmp->next = p->next;
		p->next = tmp;
	}

	return list;
}

linkedlist create_list_tail() {

	int num;
	linkedlist list = (linkedlist) malloc(sizeof(struct node));
	list->next = NULL;

	printf("Please enter the size of the list: ");
	scanf("%d", &num);

	listnode *p = list;
	for (int i = 0; i < num; ++i) {
		listnode *tmp = (listnode *) malloc(sizeof(struct node));
		scanf("%d", &tmp->data);
		tmp->next = p->next;
		p->next = tmp;
		p = tmp;
	}

	return list;
}

int insert_node(linkedlist &list, int index, element ele) {

	if (list == NULL) {
		printf("Empty list.\n");
		return -1;
	}

	linkedlist p = list;
	for (int i = 0; i < index; ++i) {
		p = p->next;
	}
	linkedlist tmp = (linkedlist) malloc(sizeof(struct node));
	tmp->data = ele;
	tmp->next = p->next;
	p->next = tmp;

	printf("Insert succeed!\n");

	return 0;
}

int init_list(linkedlist &list) {

	list = (linkedlist) malloc(sizeof(struct node));
	if (list) {
		list->next = NULL;
		return 1;
	}

	return 0;
}

int clear_list(linkedlist &list) {

	linkedlist p = list->next;
	linkedlist tmp;

	while (p != NULL) {
		tmp = p;
		p = p->next;
		free(tmp);
	}

	list->next = NULL;

	return 0;
}

int is_empty(linkedlist list) {

	if (list->next == NULL)
		return 1;
	else
		return 0;
}

int length_of_list(linkedlist list) {

	linkedlist p = list;
	int counter = 0;

	while (p->next != NULL) {
		counter++;
		p = p->next;
	}
	return counter;
}

bool delete_node(linkedlist &list, int index) {

	linkedlist p = list;
	int counter = 0;
	for (int i = 0; i < index && p->next != NULL; ++i) {
		p = p->next;
	}

	if (p->next == NULL || counter > index-1) {
		printf("Delete Error!\n");
		return false;
	}

	linkedlist s = p->next;
	p->next = s->next;
	free(s);

	printf("Delete Succeed!\n");

	return true;
}

listnode *locate_element(linkedlist list, element ele) {

	listnode *p = list;
	int counter = 0;

	while (p->next && p->next->data != ele) {
		p = p->next;
		counter++;
	}

	if (p) {
		printf("Locate Succeed! %d is the number %d element.\n",
		       ele, counter+1);
	}

	return p;

}

void print_list(linkedlist list) {

	linkedlist p = list;

	while (p->next != NULL) {

		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
}

