#include <stdio.h>

int main()
{
	char a;
	int i;
	a = 17;

	a = a | (1 << 3);	/* set 3rd bit */
	printf("%d\n", a);

	a = a & (~(1<<4));	/* clear 4th bit */
	printf("%d\n", a);

	for (i = 7; i >= 0; i--) {
		printf("%d", (a & (1 << i)) >> i);	/* read i'th bit */
	}
	printf("\n");

	return 0;
}
