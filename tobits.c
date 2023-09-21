#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

char *toBits(void *value, char bytes)
{
    char *ch; 
    char bit;
    switch(bytes) {
 
        case 1: 
            bit = bytes * 8;
            ch = malloc(bit + 1);
            for (size_t tib = bit - 1, i = 0; i < bit; i++)
                ch[i] = 1 << (tib - i) & *(char *) value ? '1' : '0';
            break;
        case 2: 
            bit = bytes * 8;
            ch = malloc(bit + 1);
            for (size_t tib = bit - 1, i = 0; i < bit; i++)
                ch[i] = 1 << (tib - i) & *(short *) value ? '1' : '0';
            break;
        case 4: 
            bit = bytes * 8;
            ch = malloc(bit + 1);
            for (size_t tib = bit - 1, i = 0; i < bit; i++)
                ch[i] = 1 << (tib - i) & *(int *) value ? '1' : '0';
            break;
        case 8: 
            bit = bytes * 8;
            ch = malloc(bit + 1);
            for (size_t tib = bit - 1, i = 0; i < bit; i++)
                ch[i] = 1 << (tib - i) & *(long *) value ? '1' : '0';
            break;
        default:
            ch = "The bit variables are numbers 1, 2, 4, and 8\n";
            return ch;

    }

    while(*ch++==48);
    
    return --ch;

}

int main(int argc, char *argv[])
{
	char *ch;


	if (! --argc) {
	
		puts("Usage:\n");
		printf("\t %s 2 or more int number .eg 09\n", *argv);
		printf("\t %s only 1 char symbol .eg 'c'\n", *argv);
		printf("\t %s Need to be spaced by dots. float number .eg 3.14\n", *argv);
		exit(1);
	}

	if (strchr(argv[1], '.') != NULL)

		ch = toBits(&(float){atoi(argv[1])}, sizeof(float));

	else if(strlen(argv[1]) == 1)

		ch = toBits(&(char){*argv[1]}, sizeof(char));

	else

		ch = toBits(&(int){atoi(argv[1])}, sizeof(int));

    printf("%s %s\n", ch, argv[1]);

    return 0;
}
