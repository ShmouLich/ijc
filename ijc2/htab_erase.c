/*
 * IJC-DU2 B)
 * htab_erase.c
 *
 * Datum vytvoření: 14.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdlib.h>
#include "htab_struct.h"

bool htab_erase(htab_t * t, htab_key_t key) {
    int hash = htab_hash_function(key);
    struct htab_item * tmp = t->arr[hash];

    while (tmp != NULL) {
        if (!strcmp(key, tmp->pair.key)) {
            t->arr[hash] = tmp->next;
            free(tmp);
            t->size--;
        }

        if (tmp->next == NULL)
            break;
        
        if (!strcmp(key, tmp->next->pair.key)) {
            struct htab_item * tmp_holder = tmp->next->next;
			free(tmp->next);
			tmp->next = tmp_holder;
			t->size--;
			return true;
        }

        tmp = tmp->next;
    }

    return false;
}
