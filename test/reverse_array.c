#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int solution1()
{
	char* src = "hello, world";
	char* des = NULL;

	int len = strlen(src);
	des = (char* ) malloc(len + 1);

	char* tmp = des;
	char* s = &src[len-1];
	while (len-- != 0) {
		*tmp++ = *s--;
	}
	*tmp = '\0';

	printf("%s\n", des);

	free(des);
	return 0;
}

void solution2()
{
	char src[] = "hello, world";
	int i;
	char t;
	int len = strlen(src);

	for (i = 0; i < len/2; i++) {
		t = src[i];
		src[i] = src[len-i-1];
		src[len-i-1] = t;
	}
	printf("%s\n", src);
}

int main()
{
	solution2();
	return 0;
}
