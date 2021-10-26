/*
 * IJC-DU2 B)
 * htab_for_each.c
 *
 * Datum vytvoření: 13.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "htab_struct.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    for (unsigned int i = 0; i < t->arr_size; i++) {

        struct htab_item * tmp = t->arr[i];
        while (tmp != NULL) {
            (* f)(&tmp->pair);
            tmp = tmp->next;
        }
    }
}
