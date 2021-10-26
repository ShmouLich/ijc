/* 
 * IJC-DU1
 * error.c
 * 
 * Datum vytvoření: 14.3.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void warning_msg(const char *fmt, ...) {

    va_list errors;
    va_start(errors, fmt);
	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, errors);
	va_end(errors);
}

void error_exit(const char *fmt, ...) {

    va_list errors;
    va_start(errors, fmt);
	fprintf(stderr, "CHYBA: ");
	vfprintf(stderr, fmt, errors);
	va_end(errors);
    exit(1);
}
