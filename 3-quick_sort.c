#include "sort.h"
/**
 * recursive_quicksort - resursion quick sorting
 * @array: array of int.
 * @lo: start point.
 * @hi: end point.
 * @size: size array.
 *
 * Return: nothing.
 */
void recursive_quicksort(int *array, int lo, int hi, size_t size)
{
	int j, aux;
	int i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < array[hi])
		{
			i++;
			aux = array[j];
			array[j] = array[i];
			array[i] = aux;
			if (i != j)
				print_array(array, size);
		}
	}
	i++;
	if (array[hi] != array[i])
	{
		aux = array[hi];
		array[hi] = array[i];
		array[i] = aux;
		if (i != hi)
			print_array(array, size);
	}
	if (lo < i - 1)
		recursive_quicksort(array, lo, i - 1, size);
	if (i + 1 < hi)
		recursive_quicksort(array, i + 1, hi, size);

}


/**
 * quick_sort - quick sorting
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;

	recursive_quicksort(array, 0, size - 1, size);
}
