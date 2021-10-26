/*
 * IJC-DU2 B)
 * htab_clear.c
 *
 * Datum vytvoření: 14.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdlib.h>
#include "htab_struct.h"

void htab_clear(htab_t * t) {
    for (unsigned int i = 0; i < t->arr_size; i++) {
        while (t->arr[i] != NULL) {

            struct htab_item * tmp = t->arr[i];

            while (tmp != NULL) {

                if (tmp->next == NULL) {
                    t->size--;
					tmp->pair.key = NULL;
					free(tmp);
					t->arr[i] = NULL;
					break;
                }

                if (tmp->next->next == NULL) {
                    t->size--;
					tmp->next->pair.key = NULL;
					free(tmp->next);
					tmp->next = NULL;
					break;
                }

                tmp = tmp->next;

            } //while tmp != NULL
        } //while t->arr[i] != NULL
    } //for i < t->arr_size
}
