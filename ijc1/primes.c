/* 
 * IJC-DU1
 * primes.c
 * 
 * Datum vytvoření: 16.3.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdio.h>
#include <time.h>
#include "eratosthenes.h"

#define NUM_OF_PRIMES 200000000

int main() {

    clock_t start_t;
    start_t = clock();

    bitset_create(array, NUM_OF_PRIMES);
    eratosthenes(array);

    bitset_index_t toPrint[10]; //pole prvocisel, ktera budou vypsana
    int counter = 0; //pocitadlo prvocisel, ktera budou vypsana

    for (bitset_index_t i = bitset_size(array); counter <= 10 && i >= 2; i--) {

        if (!bitset_getbit(array, i))
            toPrint[counter++] = i;
    }

    for (int i = 10; i > 0; i--)
        printf("%lu\n", toPrint[i]);

    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start_t)/CLOCKS_PER_SEC);
    return 0;
}
