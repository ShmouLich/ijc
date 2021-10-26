/*
 * IJC-DU2 B)
 * htab_bucket_count.c
 *
 * Datum vytvoření: 12.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "htab_struct.h"

size_t htab_bucket_count(const htab_t * t) {
    return t->arr_size;
}
