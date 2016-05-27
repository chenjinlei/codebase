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


int main()
{
	queue q = (queue) malloc(sizeof(queue_node));
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
		printf("5. exit.\n");
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
				printf("Please enter en element to enqueue: ");
				scanf("%d", &e);
				enqueue(q, e);
				printf("Enqueued: %d\n", e);
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
			flag = 0;
			break;
		default:
			break;
		}
	}

	return 0;
}

void init_queue(queue q) {
	q->front = (linked_node *) malloc(sizeof(linked_node));
	q->rear = (linked_node *) malloc(sizeof(linked_node));
	q->rear->next = q->front;
	q->front->next = NULL;
}

void enqueue(queue q, element e) {

	if (q == NULL)
		return;

	linked_node *tmp = (linked_node *) malloc(sizeof(linked_node));
	tmp->data = e;
	tmp->next = q->rear->next;
	q->rear->next = tmp;

	if (q->front->next == NULL)
		q->front->next = tmp;

}

element dequeue(queue q) {

	element e;

	linked_node *p = q->front->next;
	linked_node *s = q->rear;

	if (q->front->next == q->rear->next) {
		e = q->front->next->data;
		free(q->front->next);
		q->rear->next = q->front;
		q->front->next = NULL;
		return e;
	}

	while (s->next != p)
		s = s->next;
	e = p->data;
	q->front->next = s;
	free(p);

	return e;
}

void print(queue q) {

	linked_node *p = q->rear->next;

	while (p!=q->front) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

bool is_empty(queue q) {
	return q->rear->next == q->front;
}

