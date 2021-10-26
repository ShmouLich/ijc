//13.4

#ifndef __HTAB_STRUCT_H__
#define __HTAB_STRUCT_H__

#include "htab.h"

typedef struct htab_item {
    htab_pair_t pair;
    struct htab_item *next;
} htab_item_t;

struct htab {
    size_t size; //pocet prvku tabulky - celkove
    size_t arr_size; //pocet prvku v retezci - velikost pole
    htab_item_t *arr[];
};

#endif
