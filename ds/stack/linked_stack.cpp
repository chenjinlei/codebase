#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node {
	element data;
	struct node *top;
} node, *stack;


void init_stack(stack &);
bool is_empty(stack );
void push(stack &, element );
element pop(stack &);
element get_top(stack );

int main()
{
	stack s;
	int select;
	int flag = 1;

	init_stack(s);
	while (flag) {
		printf("1. print all the element of the stack.\n");
		printf("2. push an element.\n");
		printf("3. pop an element.\n");
		printf("4. show whether the stack is empty or not.\n");
		printf("5. get the top element.\n");
		printf("6. exit.\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			if (!is_empty(s)) {
				stack p = s;
				while (p->top) {
					printf("%d ", p->top->data);
					p = p->top;
				}
			} else {
				printf("empty stack!\n");
			}
			printf("\n");
			break;
		case 2:
			element tmp;
			printf("please enter an element: ");
			scanf("%d", &tmp);
			push(s, tmp);
			break;
		case 3:
			if (!is_empty(s)) {
				element result = pop(s);
				printf("poped: %d\n", result);
			} else {
				printf("empty stack!\n");
			}
			break;
		case 4:
			if (is_empty(s))
				printf("empty stack!\n");
			else
				printf("not empty!\n");
			break;
		case 5:
			if (!is_empty(s))
				printf("the top element: %d\n", get_top(s));
			else
				printf("empty stack!\n");
			break;
		case 6:
			flag = 0;
			break;
		default:
			printf("wrong selection!\n");
			break;
		}
	}

	return 0;
}

void init_stack(stack &s) {

	s = (stack) malloc(sizeof(struct node));
	s->top = NULL;
}

bool is_empty(stack s) {

	return (s->top == NULL)? true:false;
}

void push(stack &s, element e) {

	struct node *p = (stack) malloc(sizeof(struct node));
	p->data = e;
	p->top = s->top;
	s->top = p;
}

element pop(stack &s) {

	element e = s->top->data;
	stack tmp = s->top->top;
	free(s->top);
	s->top = tmp;

	return e;
}

element get_top(stack s) {

	return s->top->data;
}
