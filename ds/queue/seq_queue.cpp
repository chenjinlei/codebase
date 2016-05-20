#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef int element;

typedef struct {
	element data[MAXSIZE];
	int front;
	int rear;
} queue;

void init_queue(queue &);
bool is_empty(queue );
bool is_full(queue );
void in(queue &, element );
element out(queue &);
element get_top(queue );


int main()
{
	queue q;
	element e;
	int flag = 1;
	int select;
	int front;

	init_queue(q);

	while (flag) {
		printf("1. print all the element of the queue.\n");
		printf("2. `in` an element.\n");
		printf("3. `out` an element.\n");
		printf("4. show whether the queue is empty or not.\n");
		printf("5. show whether the queue is full or not.\n");
		printf("6. get the top element.\n");
		printf("7. exit.\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			if (is_empty(q)) {
				printf("Empty queue!\n");
			} else {
				front = q.front;
				while (front != q.rear) {
					printf("%d ", q.data[front++]);
				}
				printf("\n");
			}
			break;
		case 2:
			if (is_full(q)) {
				printf("Full queue!\n");
			} else {
				printf("Please enter an element: ");
				scanf("%d", &e);
				in(q, e);
			}
			break;
		case 3:
			if (is_empty(q)) {
				printf("Empty queue!\n");
			} else {
				e = out(q);
				printf("outed: %d\n", e);
			}
			break;
		case 4:
			if (is_empty(q)) {
				printf("Empty queue!\n");
			} else {
				printf("Not empty queue.\n");
			}
			break;
		case 5:
			if (is_full(q)) {
				printf("Full queue!\n");
			} else {
				printf("Not full queue.\n");
			}
			break;
		case 6:
			if (is_empty(q)) {
				printf("Empty queue!\n");
			} else {
				e = get_top(q);
				printf("top one: %d\n", e);
			}
			break;
		case 7:
			flag = 0;
			break;
		default:
			break;
		}

	}

	return 0;
}

void init_queue(queue &q) {
	q.front = 0;
	q.rear = 0;
}

bool is_empty(queue q) {
	if (q.rear == q.front) {
		return true;
	} else {
		return false;
	}
}

bool is_full(queue q) {
	if (q.rear+1 == MAXSIZE) {
		return true;
	} else {
		return false;
	}
}

void in(queue &q, element e) {
	q.data[q.rear++] = e;
}

element out(queue &q) {
	return q.data[q.front++];
}

element get_top(queue q) {
	return q.data[q.front];
}
