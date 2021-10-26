/*
 * IJC-DU2 B)
 * htab_move.c
 *
 * Datum vytvoření: 14.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "htab_struct.h"

htab_t * htab_move(size_t n, htab_t *from) {
    struct htab * new = htab_init(n);

    for (unsigned int i = 0; i < from->arr_size; i++) {
        struct htab_item * tmp = from->arr[i];
        while (tmp != NULL) {
            htab_lookup_add(new, tmp->pair.key);
            tmp = tmp->next;
        }
    }

    htab_clear(from);
    return new;
}
