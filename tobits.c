#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

int main()
{

    char *ch = toBits(&(char){4}, sizeof(char));

    printf("%s %u\n", ch, 4);

    return 0;
}
