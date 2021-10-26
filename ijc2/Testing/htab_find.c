/*
 * IJC-DU2 B)
 * htab_find.c
 *
 * Datum vytvoření: 13.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "htab_struct.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key) {
    int hash = htab_hash_function(key) % t->arr_size;
    struct htab_item * tmp = t->arr[hash];

    while (tmp != NULL) {
        
        if (!strcmp(key, tmp->pair.key)) {
            return &tmp->pair;
        }
        
        if (tmp->next != NULL)
            tmp = tmp->next;
        else
            break;
    }

    return NULL;
}
