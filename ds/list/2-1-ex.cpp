#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char element;

typedef struct {
	element data[MAXSIZE];
	int length;
} sq_list;

void sqlist_intersect(sq_list , sq_list , sq_list &);

int main()
{
	sq_list list1, list2, list3;
	char ch = 'a';

	list1.length = 0;
	list2.length = 0;
	list3.length = 0;

	for (int i = 0; i < 5; i++) {
		list1.data[i] = ch++;
		list2.data[i] = ch;
		list1.length++;
		list2.length++;
	}

	sqlist_intersect(list1, list2, list3);

	list1.data[list1.length] = '\0';
	list2.data[list2.length] = '\0';
	list3.data[list3.length] = '\0';

	printf("list1: %s\n", list1.data);
	printf("list2: %s\n", list2.data);
	printf("list3: %s\n", list3.data);

	return 0;
}


void sqlist_intersect(sq_list list1, sq_list list2, sq_list &list3) {

	/*
	for (int i = 0; i < list1.length; i++) {
		for (int j = 0; j < list2.length; j++) {
			if (list1.data[i] == list2.data[j]) {
				list3.data[list3.length++] = list1.data[i];
			}
		}
	}
	*/

	// as to the list is in order...
	int i = 0;
	int j = 0;
	while (i < list1.length && j < list2.length) {
		if (list1.data[i] < list2.data[j])
			i++;
		else if (list1.data[i] > list2.data[j])
			j++;
		else {
			list3.data[list3.length++] = list1.data[i++];
		}
	}
}
