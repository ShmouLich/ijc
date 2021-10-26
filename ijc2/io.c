/*
 * IJC-DU2 B)
 * io.c
 *
 * Datum vytvoření: 17.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "io.h"

int get_word(char *word, int limit, FILE *fp) {
    if (fp == NULL) {
        fprintf(stderr, "File could not be loaded.\n");
        return -1;
    }

    int z;

    while ((z = fgetc(fp)) != EOF && isspace(z));//skip through space chars

    if (z == EOF)
        return EOF;

    word[0] = z;
    int i = 1;

    while ((z = fgetc(fp)) != EOF && !isspace(z) && i < limit - 1) {
        word[i] = z; //add to word
        i++;
    }

    word[i] = '\0';

    if (i == limit - 1) {
        while ((z = fgetc(fp)) != EOF && !isspace(z)) {
            i++;
        } //go through rest of word
    }

    if (z == EOF)
        return EOF;

    return i;
}
