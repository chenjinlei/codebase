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
		p = tmp;
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

	return 0;
}

int init_list(linkedlist &list) {

	return 0;
}

int clear_list(linkedlist &list) {

	return 0;
}

int is_empty(linkedlist list) {

	return 0;
}

int length_of_list(linkedlist list) {

	return 0;
}

int delete_node(linkedlist &list, int index) {

	return 0;
}

listnode *locate_element(linkedlist list, element ele) {

	listnode *p;

	return p;
}

void print_list(linkedlist list) {

}

