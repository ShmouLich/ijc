/* 
 * IJC-DU1
 * steg-decode.c
 * 
 * Datum vytvoření: 18.3.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdio.h>
#include "ppm.h"
#include "eratosthenes.h"
#include "error.h"

int main(int argc, char *argv[]) {


    if (argc != 2)
        error_exit("steg-decode: spustte s argumentem formatu .ppm\n");

    struct ppm *img = ppm_read(argv[1]);

    if (img == NULL)
        error_exit("steg-decode: nepovedlo se nacist soubor\n");

    bitset_alloc(primes, img->xsize * img->ysize * 3);

    if (primes == NULL) {
        ppm_free(img);
        return 1;
    }

    eratosthenes(primes);

    unsigned char c[2]= {8, 0};
    int c_length = 0;

    for (bitset_index_t i = 23; i < bitset_size(primes); i++) {

        if (!bitset_getbit(primes, i)) {

            //zjistime jestli je bit 0/1, postveme na nej masku a posuneme na spravnou pozici
            //binarni or nastavi bit na pozici c_length v promenne c
            bitset_setbit(c, c_length, (img->data[i] & 1));
            c_length++;
        }
        
        if (c_length == CHAR_BIT) {

            if (c[1] == '\0')
                break;
            
            putchar(c[1]);
            c_length = 0;
        }
    }

    putchar('\n');
    ppm_free(img);
    bitset_free(primes);

    if (c[1] != '\0')
        printf("Zprava je ve spatnem formatu\n");

    return 0;
}
