#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sqlist.h"

int main()
{
	sqlist_t *list = sqlist_create(0);

	srand(time(0));
	//sqlist_create(&list);

	if ( list == NULL ) {

		fprintf(stderr, "sqlist_create() failed!\n");
		exit(1);

	}
	
	for (int i = 0; i < DATASIZE + 1; i++)
		sqlist_insert(list, list->last + 1, rand() % DATASIZE);

	sqlist_display(list);

	printf("last: %d\n", list->last);

	sqlist_delete(list, 3);

	sqlist_display(list);

	sqlist_insert(list, list->last + 1, rand() % DATASIZE);

	sqlist_display(list);

	printf("index: %d\n", sqlist_find(list, 3));
	
	sqlist_display(list);

	sqlist_t *src = sqlist_create(0);
	sqlist_t *dst = sqlist_create(0);

	for (int i = 0; i < DATASIZE / 2  + 1; i++) {
		sqlist_insert(src, sqlist_length(src), rand() % DATASIZE);
		sqlist_insert(dst, sqlist_length(dst), rand() % DATASIZE);
	}

	sqlist_display(src);
	sqlist_display(dst);

	sqlist_union(src, dst);

	sqlist_display(src);


	sqlist_destroy(list);

	return 0;
}
