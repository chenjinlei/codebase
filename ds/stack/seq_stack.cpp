#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int element;

typedef struct {
	int top;
	element data[MAXSIZE];
} stack;

void init_stack(stack &);
bool is_empty(stack );
bool is_full(stack );
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
		printf("5. show whether the stack is full or not.\n");
		printf("6. get the top element.\n");
		printf("7. exit.\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			if (!is_empty(s)) {
				for (int i = 0; i <= s.top; ++i) {
					printf("%d ", s.data[i]);
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
			if (is_full(s))
				printf("full stack!\n");
			else
				printf("not full stack!\n");
			break;
		case 6:
			if (!is_empty(s))
				printf("the top element: %d\n", get_top(s));
			else
				printf("empty stack!\n");
			break;
		case 7:
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
	s.top = -1;
}

bool is_empty(stack s) {

	return s.top == -1? true:false;
}

bool is_full(stack s) {
	return s.top == MAXSIZE-1? true:false;
}

void push(stack &s, element e) {
	if (!is_full(s))
		s.data[++s.top] = e;
	else
		printf("stack is full!\n");
}

element pop(stack &s) {
	return s.data[s.top--];
}

element get_top(stack s) {
	return s.data[s.top];
}
