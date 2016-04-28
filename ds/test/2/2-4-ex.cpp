#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char element;
typedef struct {
	element data[MAXSIZE];
	int length;
} sqlist;


int sqlist_compare(sqlist , sqlist );

int main(int argc, char *argv[])
{
	sqlist list1, list2;
	char ch = 'a';

	list1.length = 0;
	list2.length = 0;

	for (int i = 0; i < 5; i++) {
		list1.data[i] = ch++;
		list2.data[i] = ch;
		list1.length++;
		list2.length++;
	}
	list1.data[list1.length] = '\0';
	list2.data[list2.length] = '\0';

	printf("list1: %s\n", list1.data);
	printf("list2: %s\n", list2.data);

	int result = sqlist_compare(list1, list2);
	if (result == 0)
		printf("list1 = list2\n");
	else if (result == -1)
		printf("list1 < list2\n");
	else if (result == 1)
		printf("list1 > list2\n");

	return 0;

}

int sqlist_compare(sqlist list1, sqlist list2) {

	int i = 0;
	while (i < list1.length && i < list2.length) {
		if (list1.data[i] > list2.data[i])
			return 1;
		else if (list1.data[i] < list2.data[i])
			return -1;
		else
			i++;
	}

	if (list1.length == list2.length)
		return 0;
	else if (list1.length > list2.length)
		return 1;
	else
		return -1;

}
