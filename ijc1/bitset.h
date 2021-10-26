/* 
 * IJC-DU1
 * bitset.h
 * 
 * Datum vytvoření: 9.3.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#pragma once

#include <malloc.h>
#include <assert.h>
#include <limits.h>
#include "error.h"

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define MAX_LENGTH 200000000 //maximalni velikost pole 200 milionu

#define LENGTH_BITS (sizeof(unsigned long) * CHAR_BIT)

//definuje a _nuluje_ proměnnou jmeno_pole

#define bitset_create(bitset_name, bitset_size) \
    static_assert(bitset_size > 0, "bitset_create: Chyba při vytváření pole\n"); \
    unsigned long bitset_name[(bitset_size / LENGTH_BITS) + 2] = {(bitset_size), 0}
    //+2 kvuli prvnimu indexu = velikost pole, poslednimu indexu = \0

//definuje proměnnou jmeno_pole tak, aby byla kompatibilní s polem vytvořeným pomocí bitset_create,
//ale pole bude alokováno dynamicky.
   
#define bitset_alloc(bitset_name, bitset_size) \
    bitset_t bitset_name; \
    assert((bitset_size < MAX_LENGTH && "bitset_alloc: Chyba alokace paměti\n")); \
    bitset_name = calloc(((bitset_size / LENGTH_BITS) + 2), sizeof(bitset_index_t)); \
    assert((bitset_name != NULL && "bitset_alloc: Chyba alokace paměti\n")); \
    bitset_name[0] = bitset_size
    

#ifndef USE_INLINE
    
//uvolní paměť dynamicky (bitset_alloc) alokovaného pole

#define bitset_free(bitset_name) \
    free(bitset_name)


//vrátí deklarovanou velikost pole v bitech (uloženou v poli)

#define bitset_size(bitset_name) \
    bitset_name[0]
       

//nastaví zadaný bit v poli na hodnotu zadanou výrazem
 
#define bitset_setbit(bitset_name, index, term) \
    if ((index) >= bitset_name[0]) {error_exit("bitset_setbit: index %lu mimo rozsah pole (%lu)\n", (unsigned long)index, bitset_name[0]);} \
    (term) \
        ? (bitset_name[(index/LENGTH_BITS) + 1] |= 1UL << index % LENGTH_BITS) \
        : (bitset_name[(index/LENGTH_BITS) + 1] &= ~(1UL << index % LENGTH_BITS))


//získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1


#define bitset_getbit(array_name, index) \
	((index) > array_name[0] \
	    ? error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)(index), bitset_size(array_name)) , 2 \
	    : (array_name[(index) / LENGTH_BITS + 1] & (1UL << (index) % LENGTH_BITS)) ? 1 : 0)


#else

inline void bitset_free(bitset_t bitset_name) {
    free(bitset_name);
}


//vrátí deklarovanou velikost pole v bitech (uloženou v poli)

inline int bitset_size(bitset_t bitset_name) {
    return bitset_name[0];
}
       

//nastaví zadaný bit v poli na hodnotu zadanou výrazem

inline void bitset_setbit(bitset_t bitset_name, int index, unsigned char term) {
    
    if (index/sizeof(unsigned long) > bitset_name[0]) {
        error_exit("bitset_setbit: index %lu mimo rozsah pole (%lu)\n", (unsigned long)index, bitset_name[0]);
    }

    if (term)
        bitset_name[(index/LENGTH_BITS) + 1] |= 1UL << index % LENGTH_BITS;
    
    else
        bitset_name[(index/LENGTH_BITS) + 1] &= ~(1UL << index % LENGTH_BITS);
    
}


//získá hodnotu zadaného bitu, vrací hodnotu 0 nebo 1

inline unsigned char bitset_getbit(bitset_t bitset_name, bitset_index_t index) {

    if (index) > bitset_name[0]) {
        error_exit("bitset_getbit: index %lu mimo rozsah pole (%lu)\n", (unsigned long)index, bitset_name[0]);
    }

    return (bitset_name[(index/LENGTH_BITS) + 1] >> (index % LENGTH_BITS)) & ~(~0 << 1UL);

}

#endif
