#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
	linkedlist list;
	int select;
	int method;
	int index;
	int flag = 1;
	int length;
	element data;

	init_list(list);

	do {
		printf("*****************************************\n");
		printf("         single linkedlist op.           \n");
		printf("*****************************************\n");
		printf("    1:  create a single linkedlist\n");
		printf("    2:  insert op.\n");
		printf("    3:  clear op.\n");
		printf("    4:  length of list\n");
		printf("    5:  delete op.\n");
		printf("    6:  locate op\n");
		printf("    7:	print op.\n");
		printf("    8:  exit\n");
		printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			printf("    1:  head way creation.\n");
			printf("    2:  tail way creation.\n");
			printf("    Press any key to back.\n");
			scanf("%d", &method);
			switch (method) {
			case 1:
				list = create_list_head();
				break;
			case 2:
				list = create_list_tail();
				break;
			default:
				break;
			}
			break;
		case 2:
			if (list->next == NULL) {
				printf("single linkedlist not created, \
				       please create it first!\n");
				break;
			}
			printf("Please enter the index: ");
			scanf("%d", &index);
			printf("Please enter the element: ");
			scanf("%d", &data);
			insert_node(list, index, data);
			break;
		case 3:
			clear_list(list);
			break;
		case 4:
			length = length_of_list(list);
			printf("length of list: %d\n", length);
			break;
		case 5:
			printf("Please enter the index: ");
			scanf("%d", &index);
			delete_node(list, index);
			break;
		case 6:
			printf("Please enter the element to locate: ");
			scanf("%d", &data);
			locate_element(list, data);
			break;
		case 7:
			if (is_empty(list) == 1) {
				printf("Linkedlist is empty.\n");
			} else {
				print_list(list);
			}
			break;
		case 8:
			flag = 0;
			break;
		default:
			break;
		}
	} while (flag != 0);

	return 0;
}
