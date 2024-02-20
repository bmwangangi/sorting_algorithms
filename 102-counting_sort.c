#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers in ascending order using Counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void counting_sort(int *array, size_t size) {
    if (size < 2)
        return;

    size_t i;
    int max = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    int j;
    for (j = 0; j <= max; j++)
        count[j] = 0;

    for (i = 0; i < size; i++)
        count[array[i]]++;

    printf("%d", count[0]);
    for (j = 1; j <= max; j++)
        printf(", %d", count[j]);
    printf("\n");

    int index = 0;
    for (j = 0; j <= max; j++) {
        while (count[j] > 0) {
            array[index++] = j;
            count[j]--;
        }
    }

    free(count);
}