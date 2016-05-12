#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char element;
typedef struct {
	element data[MAXSIZE];
	int length;
} sq_list;

void sqlist_insert(sq_list *, element );

int main(int argc, char *argv[])
{
	sq_list *list1;
	char ch = 'a';

	if (argc < 2) {
		printf("Usage: two parameters required!\n");
		return 1;
	}

	list1 = (sq_list *)malloc(sizeof(sq_list));
	list1->length = 0;

	for (int i = 0; i < 5; i++) {
		list1->data[i] = ch++;
		list1->length++;
	}

	printf("before insert op.: %s\n", list1->data);
	// we only use the first character of argv[1]
	sqlist_insert(list1, (element)*argv[1]);
	list1->data[list1->length] = '\0';
	printf("after insert op.: %s\n", list1->data);

	return 0;
}

void sqlist_insert(sq_list *list, element ch) {

	if (list->length == MAXSIZE) {
		printf("no enough space for this list!\n");
		return;
	}

	int i;
	for (i = list->length-1; i >= 0; i--) {
		if (list->data[i] > ch)
			list->data[i+1] = list->data[i];
		else
			break;
	}
	list->data[i+1] = ch;
	list->length++;

}
