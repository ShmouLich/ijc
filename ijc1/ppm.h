/* 
 * IJC-DU1
 * eratosthenes.c
 * 
 * Datum vytvoření: 15.3.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#pragma once

#define PPM_LIMIT 8000*8000*3 //8000x8000 (rozmery) x3 (3 bajty pro barvu)
    

// RGB bajty, celkem 3*xsize*ysize
struct ppm {
   int xsize;
   int ysize;
   char data[];
};


//načte obsah PPM souboru do touto funkcí dynamicky alokované struktury.
struct ppm * ppm_read(const char * filename);


//uvolní paměť dynamicky alokovanou v ppm_read
void ppm_free(struct ppm *p);
