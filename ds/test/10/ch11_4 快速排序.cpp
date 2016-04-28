#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM_ITEMS 100

void quickSort(int numbers[], int array_size);
void q_sort(int numbers[], int left, int right);

int numbers[NUM_ITEMS];


int main()
{
	int i;
	
	//seed random number generator
	srand(time(NULL));
	
	//fill array with random integers
	for (i = 0; i < NUM_ITEMS; i++)
		numbers[i] = rand();
	
	//perform quick sort on array
	quickSort(numbers, NUM_ITEMS);
	
	printf("Done with sort.\n");
	for (i = 0; i < NUM_ITEMS; i++)
		printf("%i\n", numbers[i]);
}


void quickSort(int numbers[], int array_size)
{
	q_sort(numbers, 0, array_size - 1);
}



void q_sort(int numbers[], int left, int right)
{
	int pivot, l_hold, r_hold;
	
	l_hold = left;
	r_hold = right;
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		q_sort(numbers, left, pivot-1);
	if (right > pivot)
		q_sort(numbers, pivot+1, right);
} 