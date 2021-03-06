#include <stdio.h>
#include <stdlib.h>


typedef int element;
typedef struct dlistnode {
	element data;
	struct dlistnode *prior, *next;
} node;

typedef node *dlinkedlist;

int dlinkedlist_insert(dlinkedlist &list, int index, element );
int dlinkedlist_delete(dlinkedlist &list, int index);
void dlinkedlist_print(dlinkedlist list);
static void flush(void);

int main()
{
	int index, sample, num;
	node *node1, *node2, *node3;
	dlinkedlist list;

	node1 = (node *)malloc(sizeof(node));
	node1->data = 1;
	node1->prior = NULL;
	node1->next = NULL;

	node2 = (node *)malloc(sizeof(node));
	node2->data = 2;
	node2->prior = node1;
	node2->next = NULL;
	node1->next = node2;

	node3 = (node *)malloc(sizeof(node));
	node3->data = 3;
	node3->prior = node2;
	node3->next = NULL;
	node2->next = node3;

	list = node1;

	do {
		printf("\n	Basic operations of doubly linked list	  \n");
		printf("*******************************************************\n");
		printf("		1:	Insert an integer\n");
		printf("		2:	Delete an integer\n");
		printf("		3:	Print whole list\n");
		printf("		4:	Exit\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		do {
			scanf("%d", &num);
		} while(num < 1 || num > 4);

		switch (num) {
		case 1:
			printf("Please enter index: ");
			scanf("%d", &index);
			printf("Please enter the integer: ");
			scanf("%d", &sample);
			dlinkedlist_insert(list, index, sample);
			dlinkedlist_print(list);
			break;
		case 2:
			printf("Please enter index: ");
			scanf("%d", &index);
			if(dlinkedlist_delete(list, index))
				printf("Delete Succeeded!");
			dlinkedlist_print(list);
			break;
		case 3:
			dlinkedlist_print(list);
			break;
		default:
			break;
		}

	} while (num != 4);

	return 0;
}

/*
 * convension: insert as the `index` of the list.
 */
int dlinkedlist_insert(dlinkedlist &list, int index, element ch) {

	dlinkedlist tmp = list;
	int counter = 0;


	while (tmp->next != NULL && counter < index-1) {
		tmp = tmp->next;
		counter++;
	}

	if (counter != index-1 || index < 1) {
		printf("WRONG index!\n");
		return -1;
	}

	dlinkedlist insert_node = (dlinkedlist)malloc(sizeof(dlistnode));
	if (NULL == insert_node) {
		printf("malloc error!!\n");
		return -1;
	}

	insert_node->data = ch;
	insert_node->prior = tmp->prior;
	tmp->prior->next = insert_node;
	insert_node->next = tmp;
	tmp->prior = insert_node;

	return 0;
}


int dlinkedlist_delete(dlinkedlist &list, int index) {

	dlinkedlist tmp = list;
	int counter = 0;

	while (counter < index && index < 0) {
		tmp = tmp->next;
		counter++;
	}

	if (counter != index || tmp == NULL) {
		printf("NODE not found!\n");
		return -1;
	}

	tmp->prior->next = tmp->next;
	tmp->next->prior = tmp->prior;

	free(tmp);

	return 0;
}

void dlinkedlist_print(dlinkedlist list) {

	dlinkedlist tmp = list;

	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
