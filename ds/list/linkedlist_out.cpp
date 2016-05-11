#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct linkednode {
	element data;
	element password;
	struct linkednode *next;
} linkednode;

typedef linkednode *linkedlist;

int create_list(int );
int enter_password(int );
int out_list(int , int );

linkedlist head, p, pre;

int main()
{
	int num_of_people, num_to_out;


	printf("please enter the num of people: ");
	scanf("%d", &num_of_people);
	printf("please enter a num to out: ");
	scanf("%d", &num_to_out);

	create_list(num_of_people);
	enter_password(num_of_people);
	out_list(num_to_out, num_of_people);

	return 0;
}


int create_list(int num) {

	head = (linkedlist)malloc(sizeof(struct linkednode));
	if (head == NULL)
		return 1;
	head->next = NULL;

	p = head;
	for (int i = 0; i < num; ++i) {
		linkedlist tmp = (linkedlist)malloc(sizeof(struct linkednode));
		tmp->next = p->next;
		p->next = tmp;
		p = tmp;
	}
	p->next = head->next;
	pre = head;

	return 0;
}

int enter_password(int num) {

	int pwd;

	printf("enter the password: ");
	for (int i = 0; i < num; ++i) {
		scanf("%d", &pwd);
		pre->data = i+1;
		pre->password = pwd;
		pre = pre->next;
	}
	pre = p;

	return 0;
}


int out_list(int out_num, int num_of_people) {

	printf("now in the out_list\n");
	int i, m;
	for (i = 0; i < num_of_people; ++i) {
		for (m = 0; m < out_num; ++m)
			pre = pre->next;
		p = pre->next;
		pre->next = p->next;
		printf("%d(%d) ", p->data, p->password);
		free(p);
	}

	return 0;
}
