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
int insert_node(linkedlist &, int , element ele);
int init_list(linkedlist &);
int clear_list(linkedlist &);
int is_empty(linkedlist );
int length_of_list(linkedlist );
bool delete_node(linkedlist &, int );
listnode *locate_element(linkedlist , element );
void print_list(linkedlist );

#endif
