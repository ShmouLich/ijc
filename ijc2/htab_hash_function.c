/*
 * IJC-DU2 B)
 * htab_hash_function.c
 *
 * Datum vytvoření: 12.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "htab.h"
#include <inttypes.h>

size_t htab_hash_function (const char *str) {
    uint32_t h = 0;     //32bit
    const unsigned char *p;
    for (p = (const unsigned char *)str; *p != '\0'; p++)
        h = 65599 * h + *p;
    return h;
}
