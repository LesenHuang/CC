#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "sqlist.h"

sqlist_t *sqlist_create(sqlist_t **this_address)
{

	if (!this_address) {

		sqlist_t *list;

		do
			list = malloc(sizeof(sqlist_t));
		while (!list);

		list->last = -1;

		return list;
	}

	do
		*this_address = malloc(sizeof(**this_address));
	while (!*this_address);

	(*this_address)->last = -1;

	return 0;

}

int sqlist_insert(sqlist_t *this, int index, DATATYPE data)
{
	if (this->last == DATASIZE - 1)
		return -1;

	if (index < 0 || this->last + 1 < index)
		return -2;
	
	for (int j = this->last; index <= j; j--)
		this->data[j+1] = this->data[j];

	this->data[index] = data;
	this->last++;

	return 0;

}

int sqlist_delete(sqlist_t *this, int index)
{

	if ( -1 < index && index < this->last + 1 ) {
		for (int i = index; i < this->last; i++)
			this->data[i] = this->data[i+1];
		
		this->last--;
		return 0;
	}

	fprintf(stderr, "error: 'sqlist_delete()' index invalid range.\n");
	return -1;
}

int sqlist_find(sqlist_t *this, DATATYPE data)
{
	for (int i = 0 ; i < this->last + 1; i++)
		if (this->data[i] == data)
			return i;

	return -1;
}

void sqlist_setempty(sqlist_t *this)
{
	this->last = -1;
	puts("sqlist is empty now!");
}

int sqlist_isempty(sqlist_t *this)
{
	return this->last == -1 ? 0 : -1;
}

size_t sqlist_length(sqlist_t *this)
{
	return this->last + 1;
}

void sqlist_display(sqlist_t *this)
{
	printf("sqlist : { ");

	for (int i = 0; i < this->last + 1; i++)
		if ( i == this->last )
			printf("%d ", this->data[i]);
		else
			printf("%d, ", this->data[i]);

	puts("}");
}

void sqlist_destroy(sqlist_t *this)
{
	free(this);
}

int sqlist_union(sqlist_t *src, sqlist_t *dst)
{
	if (dst->last == -1)
		return -1;

	for (int i = 0; i < dst->last + 1; i++)
		if (sqlist_find(src, dst->data[i]) == -1)
			sqlist_insert(src, src->last+1, dst->data[i]);	

	return 0;
}
