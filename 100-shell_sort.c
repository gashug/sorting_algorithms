#include "sort.h"

/**
* shell_sort - shell sort method
* @array: array
* @size: size of array
* Return: Void
*/

void shell_sort(int *array, size_t size)
{
	size_t i;
	size_t fin;

	fin = 1;
	if (array == NULL || size < 2)
		return;

	while (fin < size)
		fin = (fin * 3) + 1;
	fin = (fin - 1) / 3;
	while (fin > 0)
	{
		for (i = 0; i < size; i++)
			shell_sort_main(array, size, fin, i);
		fin = (fin - 1) / 3;
		print_array(array, size);
	}
}

/**
* shell_sort_main - shell sort method
* @array: array
* @size: size of array
* @fin: interval that subdivides array
* @index: initial position to sort
* Return: Void
*/

void shell_sort_main(int *array, size_t size, size_t fin, size_t index)
{
	size_t i, j, min;
	int is_swapped, temp;

	is_swapped = 0;
	for (i = index; i < size; i = i + fin)
	{
		is_swapped = 0;
		min = i;
		for (j = i + fin; j < size; j = j + fin)
		{
			if (array[j] < array[min])
			{
				min = j;
				is_swapped = 1;
			}
		}
		if (is_swapped)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}
