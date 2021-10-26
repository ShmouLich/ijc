/*
 * IJC-DU2 B)
 * htab_free.c
 *
 * Datum vytvoření: 12.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "htab_struct.h"
#include <stdlib.h>

void htab_free(htab_t * t) {
    htab_clear(t);
    free(t);
}
