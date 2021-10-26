/* 
 * IJC-DU1
 * ppm.c
 * 
 * Datum vytvoření: 15.3.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdio.h>
#include <malloc.h>
#include "ppm.h"
#include "error.h"

struct ppm * ppm_read(const char * filename) {

    FILE *fp = fopen(filename, "rb");

    if (fp == NULL)
        return NULL;

    char ppm_header[2];
    int max_color;
    int x_size;
    int y_size;

    //program nacte hlavicku ppm souboru
    //P6\n
    //xsize ysize\n
    //255
    if (!fscanf(fp, "%c%c\n%d %d\n%d", &ppm_header[0], &ppm_header[1], &x_size, &y_size, &max_color)) {
        fclose(fp);
        return NULL;
    }
    fgetc(fp);
    
    if (ppm_header[0] != 'P' || ppm_header[1] != '6' || max_color != 255) {
        //hlavicka je spatne / obsahuje necekane hodnoty
        fclose(fp);
        return NULL;
    }

    unsigned int image_size = x_size * y_size * 3; //velikost obrazku v bajtech

    struct ppm *image_p = malloc(2 * sizeof(int) + image_size);
    image_p->xsize = x_size;
    image_p->ysize = y_size;

    if (image_p == NULL|| image_size > PPM_LIMIT){
        free(image_p);
        fclose(fp);
        return NULL;
    }

    char c = 0;
    
    for (unsigned long i = 0; i < image_size; i++) {

        c = fgetc(fp);
        image_p->data[i] = c;

        if (c == EOF) {
            free(image_p);
            fclose(fp);
            return NULL;
        }
    }

    fclose(fp);
    return image_p;   
}


//uvolní paměť dynamicky alokovanou v ppm_read
void ppm_free(struct ppm *p) {

    if (p != NULL)
        free(p);
}
