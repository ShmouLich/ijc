/*
 * IJC-DU2 B)
 * htab_lookup_add.c
 *
 * Datum vytvoření: 14.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdio.h>
#include <stdlib.h>
#include "htab_struct.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key) {

    htab_pair_t * tmp = htab_find(t, key);
    
    if (tmp != NULL)
        return tmp;


    htab_item_t * new;
    new = malloc(sizeof(struct htab_item));

    if (new == NULL) {
        fprintf(stderr, "Chyba pri alokaci pameti\n");
        return NULL;
    }
    
    new->pair.key = malloc(sizeof(char) * (strlen(key) + 1));

    if (new->pair.key == NULL) {
        free(new);
        return NULL;
    }

    strcpy((char *)new->pair.key, key);
    new->next = NULL;
    unsigned int hash = (htab_hash_function(key) % t->arr_size);

    if (t->arr[hash] == NULL) {
        t->arr[hash] = new;
    }
    else {
        struct htab_item * ptr;
        ptr = t->arr[hash];
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }
    
    t->size++;
    return &new->pair;
}
