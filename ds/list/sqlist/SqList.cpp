#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef int element;
typedef struct {
	element data[MAXSIZE];
	int length;
} sqlist;


void create_list(sqlist *);
int length_list(sqlist );
void delete_list(sqlist );
void print_list(sqlist );
int is_empty(sqlist );
int is_full(sqlist );
void reverse_list(sqlist *);
sqlist insert_list(sqlist , int , element );

element get_element(sqlist , int );
sqlist delete_elememt(sqlist , int);
int locate_element(sqlist , element );

int main()
{
	sqlist list1;
	element sample;
	int index;
	int num;

	printf("This program implements sequence list, \n");
	printf("with operation `locate`, `insert`, `delete`, etc.\n");

	create_list(&list1);

	int flag = 1;
	while (flag) {
		printf("\n1. Print all the elements.\n");
		printf("2. Insert an element.\n");
		printf("3. Delete an element.\n");
		printf("4. Locate an element.\n");
		printf("5. Reverse the entire list.\n");
		printf("6. Exit.\n");
		printf("Please choose: ");

		scanf("%d", &num);
		if (num == 1) {
			print_list(list1);
		} else if (num == 2) {
			printf("Please enter index: ");
			scanf("%d", &index);
			printf("Please enter the element: ");
			scanf("%d", &sample);
			list1 = insert_list(list1, index, sample);
			printf("After insert: ");
			print_list(list1);
		} else if (num == 3) {
			printf("Please enter index to delete: ");
			scanf("%d", &index);
			list1 = delete_elememt(list1, index);
			printf("After delete: ");
			print_list(list1);
		} else if (num == 4) {
			printf("Please enter element to locate: ");
			scanf("%d", &sample);
			index = locate_element(list1, sample);
			if (-1 == index)
				printf("Element %c not found.\n", sample);
			else
				printf("Found at %d\n", index+1);
		} else if (num == 5) {
			printf("After reverse: ");
			reverse_list(&list1);
			print_list(list1);
		} else if (num == 6) {
			flag = 0;
			printf("Program finished. Press any key to continue...");
			getchar();
		} else {
			printf("Wrong selection.\n");
		}
	}

	return 0;

}


void create_list(sqlist *list) {

	printf("please enter length of the list to be created: ");
	scanf("%d", &list->length);

	printf("Now, please enter %d elements separated by space!\n", list->length);
	for (int i = 0; i < list->length; i++) {
		scanf("%d", &list->data[i]);
	}

	printf("\nList created! Press any key to continue...");
	getchar();

}

int length_list(sqlist list) {

	return list.length;

}

void delete_list(sqlist list) {

	list.length = 0;

}

void print_list(sqlist list) {

	if (is_empty(list) == 1) {
		printf("empty list.\n");
		return;
	}

	for (int i = 0; i < list.length; i++) {
		printf("%d ", list.data[i]);
	}

}

int is_empty(sqlist list) {

	if (list.length == 0)
		return 1;
	else
		return 0;

}

int is_full(sqlist list) {

	if (list.length == MAXSIZE)
		return 1;
	else
		return 0;

}

void reverse_list(sqlist *list) {

	for (int i = 0; i < list->length/2; i++) {
		element tmp = list->data[i];
		list->data[i] = list->data[list->length-i-1];
		list->data[list->length-i-1] = tmp;
	}

}

sqlist insert_list(sqlist list, int i, element tmp) {

	if (is_full(list) == 1) {
		printf("full list.\n");
		return list;
	}

	if (i < 1 || i > list.length) {
		printf("wrong position to insert.\n");
		return list;
	}

	for (int j = list.length-1; j >= i-1; j--) {
		list.data[j+1] = list.data[j];
	}
	list.data[i-1] = tmp;
	list.length++;

	return list;
}


element get_element(sqlist list, int i) {

	if (is_empty(list)) {
		printf("empty list.\n");
		exit(1);
	}

	if (i < 1 || i > length_list(list)) {
		printf("wrong index.\n");
		exit(1);
	}

	return list.data[i-1];
}

sqlist delete_elememt(sqlist list, int i) {

	if (i < 1 || i > list.length) {
		printf("wrong index.\n");
	} else {
		element deleted = list.data[i-1];
		for (int j = i-1; j < length_list(list); j++) {
			list.data[j] = list.data[j+1];
		}
		list.length--;
		printf("%c is deleted.\n", deleted);
	}
	return list;
}

int locate_element(sqlist list, element ele) {

	for (int i = 0; i < length_list(list); i++) {
		if (list.data[i] == ele)
			return i;
	}

	return -1;
}
