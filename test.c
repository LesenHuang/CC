#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>.\n", argv[0]);
	}
	FILE *file_pointer = fopen(argv[1], "r");
	assert(file_pointer != NULL);
	
	char *line;
	char *result = fgets(line, 11, file_pointer);
	printf("%s \n", line);
	result = fgets(line, 10, file_pointer);
	printf("%s \n", line);



	return 0;
}
