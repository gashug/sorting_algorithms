#include "sort.h"

/**
* counting_sort - counting sort method
* @array: the array
* @size: size of array
* Return: Void
*/

void counting_sort(int *array, size_t size)
{
	int i;
	int j;
	int k;
	int y;
	int *hal;

	if (!array || size < 2)
		return;
	k = 0;
	for (i = 0; i < (int)size; i++)
		if (array[i] > k)
			k = array[i];

	hal = malloc(sizeof(int) * ++k);
	if (!hal)
		return;
	for (i = 0; i < k; i++)
		hal[i] = 0;
	for (i = 0; i < (int)size; i++)
		hal[array[i]] += 1;

	for (i = j = 0; i < k && j < (int)size; i++)
	{
		y = hal[i];
		while (y > 0)
		{
			array[j] = i;
			y--;
			j++;
		}
	}

	y = 0;
	for (i = 0; i < k; i++)
	{
		y += hal[i];
		hal[i] = y;
	}

	print_array(hal, k);
	free(hal);
}
