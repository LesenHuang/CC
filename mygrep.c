#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

#define INIT_CAPACITY 10

char *read_line(FILE *);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "This program will search for a 'pattern' in a given file.\n\n");
		fprintf(stderr, "\tUsage: %s <pattern> <file>\n", argv[0]);
		exit(0);
	}

	FILE *file_pointer = fopen(argv[2], "r");
	if (file_pointer == NULL) {
		fprintf(stderr, "Cannot open file %s.\n", argv[2]);
		exit(1);
	}

	char *line;
	while((line = read_line(file_pointer)) != NULL)
		if (strstr(line, argv[1]))
			printf("%s\n", line);

	return 0;
}

char *read_line(FILE *file_pointer)
{
	size_t capacity = INIT_CAPACITY;
	char *line = malloc(capacity);

	assert(line != NULL);

	char *result = fgets(line, capacity, file_pointer);
	if (result == NULL) {
		free(line);
		return NULL;
	}

	size_t bytes_read = capacity;
	char *newline;

	while(true) {
		
		if((newline = strchr(line, '\n'))) break;
		capacity <<= 1;
		line = realloc(line, capacity);
		assert(line != NULL);

		result = fgets(line + bytes_read - 1, capacity - bytes_read + 1, file_pointer);
		if (result == NULL) break;
		bytes_read = capacity;

	}

	*newline = '\0';

	return line;
}
