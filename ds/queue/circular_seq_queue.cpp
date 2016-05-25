#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int element;
typedef struct queue {
	int data[MAXSIZE];
	int front, rear;
} queue;

void init_queue(queue *);
void enqueue(queue *, element );
element dequeue(queue *);
void print(queue *);
bool is_empty(queue *);
bool is_full(queue *);


int main()
{
	queue *q  = (queue *) malloc(sizeof(struct queue));
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


void init_queue(queue *q) {
	q->front = 0;
	q->rear = 0;
}

void enqueue(queue *q, element e) {
	q->data[q->rear] = e;
	q->rear = (q->rear+1+MAXSIZE)%MAXSIZE;
}

element dequeue(queue *q) {
	element e = q->data[q->front];
	q->front = (q->front+1)%MAXSIZE;
	return e;
}

void print(queue *q) {

	int index = q->front;
	while (index != q->rear) {
		printf("%d ", q->data[index]);
		index = (index+1)%MAXSIZE;
	}
	printf("\n");

}

bool is_empty(queue *q) {
	return q->front == q->rear;
}
bool is_full(queue *q) {
	return (q->rear+1)%MAXSIZE == q->front;
}
