#ifndef __SQLIST_H__
#define __SQLIST_H__

#define DATATYPE int
#define DATASIZE 8

typedef struct sqlist_t {

	DATATYPE data[DATASIZE];
	int last;

} sqlist_t ;

sqlist_t *sqlist_create(sqlist_t **);

int sqlist_insert(sqlist_t *, int, DATATYPE);

int sqlist_delete(sqlist_t *, int);

int sqlist_find(sqlist_t *, DATATYPE);

void sqlist_setempty(sqlist_t *);

int sqlist_isempty(sqlist_t *);

int sqlist_getnum(sqlist_t *);

void sqlist_display(sqlist_t *);

void sqlist_destroy(sqlist_t *);

int sqlist_union(sqlist_t *, sqlist_t *);


#endif
