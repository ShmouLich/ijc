/*
 * IJC-DU2 B)
 * htab_init.c
 *
 * Datum vytvoření: 12.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdlib.h>
#include "htab_struct.h"

htab_t * htab_init(size_t n) {
    htab_t *t = (htab_t *) malloc(sizeof(htab_t) + sizeof(struct htab_listitem *) * n);

	if (t == NULL)
		return NULL;

	t->size = 0;
	t->arr_size = n;
	for (unsigned i = 0; i < n; i++)
		t->arr[i] = NULL;
	return t;
}
