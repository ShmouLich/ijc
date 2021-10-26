/*
 * IJC-DU2 B)
 * htab_size.c
 *
 * Datum vytvoření: 12.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "htab_struct.h"

size_t htab_size (const htab_t *t) {
    return t->size;
}
