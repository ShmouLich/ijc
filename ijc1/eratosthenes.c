/* 
 * IJC-DU1
 * eratosthenes.c
 * 
 * Datum vytvoření: 12.3.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "eratosthenes.h"

void eratosthenes(bitset_t pole) {

    bitset_index_t i;

    //0 a 1 nejsou prvocisla
    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);

    //druha odmocnina nejvyssiho cisla je posledni prvek, ktery ma smysl kontrolovat
    unsigned int limit = sqrt(bitset_size(pole));


    //od 2 projdeme cele pole
    for (i = 2; i <= limit; i++) {

        //pokud narazime na prvocislo, vynulujeme jeho 2. az n. mocninu
        if (!bitset_getbit(pole, i)) {
            
            for (unsigned int j = i*i; j < bitset_size(pole); j += i) {
                bitset_setbit(pole, j, 1);
            }
        }
    }
}
