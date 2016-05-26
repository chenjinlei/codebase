#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node {
	element data;
	struct node *next;
} linked_node;

typedef struct {
	linked_node *front;
	linked_node *rear;
} queue_node;

typedef queue_node *queue;


void init_queue(queue );
void enqueue(queue , element );
element dequeue(queue );
void print(queue );
bool is_empty(queue );
bool is_full(queue );


int main()
{
	queue q;// = (queue) malloc(sizeof(queue_node));
	element e;
	int flag = 1;
	int select;

	init_queue(q);

	while (flag) {
		printf("*******************************************\n");
		printf("*            queue basic operations       *\n");
		printf("*******************************************\n");
		printf("1. print all elements of the queue.\n");
		printf("2. enqueue.\n");
		printf("3. dequeue.\n");
		printf("4. show whether the queue is empty or not.\n");
		printf("5. show whether the queue is full or not.\n");
		printf("6. exit.\n");
		scanf("%d", &select);
		switch (select) {
		case 1:
			if (!is_empty(q)) {
				print(q);
			} else {
				printf("Empty Queue!\n");
			}
			break;
		case 2:
			if (is_full(q)) {
				printf("Full Queue!\n");
			} else {
				printf("Please enter en element to enqueue: ");
				scanf("%d", &e);
				enqueue(q, e);
				printf("Enqueued: %d\n", e);
			}
			break;
		case 3:
			if (is_empty(q)) {
				printf("Empty Queue!\n");
			} else {
				e = dequeue(q);
				printf("Dequeued: %d\n", e);
			}
			break;
		case 4:
			if (!is_empty(q)) {
				printf("Not empty Queue.\n");
			} else {
				printf("Empty Queue!\n");
			}
			break;
		case 5:
			if (!is_full(q)) {
				printf("Not full Queue.\n");
			} else {
				printf("Full Queue!\n");
			}
			break;
		case 6:
			flag = 0;
			break;
		default:
			break;
		}
	}

	return 0;
}

void init_queue(queue q) {
	q = (queue) malloc(sizeof(queue_node));
	q->front = NULL;
	q->rear = NULL;
}

void enqueue(queue q, element e) {

}
element dequeue(queue );
void print(queue );
bool is_empty(queue );
bool is_full(queue );

