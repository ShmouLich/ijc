/*
 * IJC-DU2 B)
 * wordcount.c
 *
 * Datum vytvoření: 16.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdio.h>
#include <stdbool.h>
#include "htab.h"
#include "io.h"

#define WORD_LENGTH_LIMIT 128

//limit jsem zvolil aby byl prvocislo, i kdyz odborne zdroje se neshoduji, jestli to ma vliv
//takze se jedna spis o povercivost
//limit nadale musi byt dostatecne velky, aby byly zaznamy v tabulce dostatecne rozprostreny
//pokud je zaplnenost tabulky vetsi nez 50-75%, je lepsi zvolit vyssi. Protoze neznam dopredu
//rozmanitost slov, na ktere bude program pouzivan, Rozhodl jsem se pro okoli cisla 100 000
#define HASH_MAP_SIZE 100003

void print(htab_pair_t *pair)
{
    printf("%s\t%d\n", pair->key, pair->value);
}

int main() {

    htab_t * hashmap = htab_init(HASH_MAP_SIZE);
    htab_pair_t *pair = NULL;

    void (*F)(htab_pair_t*) = print;

    FILE *fp;

    fp = stdin;

    if (fp == NULL)
        return 1;

    char word[WORD_LENGTH_LIMIT];
    int length;
    bool printed = false;

    while ((length = get_word(word, WORD_LENGTH_LIMIT, fp)) != EOF) {

        if (length > WORD_LENGTH_LIMIT && !printed) {
            fprintf(stderr, "soubor obsahuje prilis dlouhe slovo\n");
            printed = true;
        }
        if ((pair = htab_lookup_add(hashmap, word)) == NULL) {
            htab_free(hashmap);
            return 1;
        }
        else
        {
            pair->value++;
        }
    }

    htab_for_each(hashmap, (F));
    htab_free(hashmap);

    return 0;
}
