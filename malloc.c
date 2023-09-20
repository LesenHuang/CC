#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *create_random_array(size_t);

#define TEST_SIZE 5

int main()
{
	int *random_array = create_random_array(TEST_SIZE);

	for (int i = 0; i < TEST_SIZE; i++) {
		printf("%d ", random_array[i]);
	}

	puts("");
	free(random_array);

	return 0;
}

int *create_random_array(size_t size)
{
	int *random_array = malloc(size);
	assert(random_array != NULL);

	for (int i = 0; i < size; i++) {
		random_array[i] = rand();
	}

	return random_array;
}
