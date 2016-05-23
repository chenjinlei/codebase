#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef int element;
typedef struct node {
	element data;
	struct node *next;
} listnode;

typedef listnode *linkedlist;

linkedlist create_list_head();
linkedlist create_list_tail();
int insert_node(linkedlist &list, int index, element ele);
int init_list(linkedlist &list);
int clear_list(linkedlist &list);
int is_empty(linkedlist list);
int length_of_list(linkedlist list);
bool delete_node(linkedlist &list, int index);
listnode *locate_element(linkedlist list, element ele);
void print_list(linkedlist list);

#endif
