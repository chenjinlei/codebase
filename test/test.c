#include <stdio.h>

unsigned short hash(unsigned short key)
{
	return (key>>)%256;


}


int main()
{
	printf("%u", hash(16));
	printf("%u"), hash(256));
}
