#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
	int coeff;
	int exp;
	struct polynomial *next;
} polynomial;

polynomial *create_polyn(int );
void add_polyn(polynomial *, polynomial *);

int main()
{
	polynomial *pf, *pg, *tmp;
	printf("enter 3 items!!!\n");
	pf = create_polyn(3);
	printf("again enter 3 items!!!\n");
	pg = create_polyn(3);

	add_polyn(pf, pg);

	tmp = pf->next;
	while (tmp) {
		printf("%dX^%d ", tmp->coeff, tmp->exp);
		tmp = tmp->next;
	}

	return 0;
}


polynomial *create_polyn(int n) {

	polynomial *head, *p, *q;

	head = new polynomial;

	head->next = NULL;
	head->coeff = 0;
	head->exp = -1;

	q = head;
	for (int i = n; i > 0; --i) {
		p = new polynomial;
		printf("please enter coeff and exp: ");
		scanf("%d %d", &p->coeff, &p->exp);
		p->next = q->next;
		q->next = p;
		q = p;
	}

	return head;

}

void add_polyn(polynomial *pf, polynomial *pg) {

	polynomial *p, *q, *pre, *u;

	p = pf->next;
	q = pg->next;

	while (p && q) {
		if (p->exp < q->exp) {
			pre = p;
			p = p->next;
		} else if (p->exp == q->exp) {
			int addition = p->coeff + q->coeff;
			if (addition != 0) {
				p->coeff = addition;
				pre = p;
			} else {
				pre->next = p->next;
				delete p;
			}
			p = pre->next;
			u = q;
			q = q->next;
			delete u;
		} else {
			u = q->next;
			q->next = p;
			pre->next = q;
			pre = q;
			q = u;
		}
	}

	if (q)
		pre->next = q;
	delete pg;
}
