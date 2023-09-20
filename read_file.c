#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *file_pointer = fopen("mygrep.c", "r");

	if (file_pointer == NULL) {
		fprintf(stderr, "Cannot open 'mygrep.c'.\n");
		return 1;
	}

	char buffer[20];

	fgets(buffer, sizeof(buffer), file_pointer);

	printf("%s\n", buffer);

	return 0;
}
