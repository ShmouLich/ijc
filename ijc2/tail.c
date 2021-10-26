/*
 * IJC-DU2 A)
 * tail.c
 *
 * Datum vytvoření: 9.4.2020
 * Autor: Ondřej Kříž
 * Překladač: GCC
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LIMIT 512

typedef struct line_struct {
    char * content;
    int length;
} t_line;

typedef struct line_buffer_struct {
    t_line * line;
    int card;
} t_buffer;


void buffer_init(t_buffer * buffer) {
    buffer->card = 0;
    buffer->line = NULL;
}

void line_init(t_line * line) {
    line->length = 0;
    line->content = malloc(LIMIT);
}

void line_cpy(t_line * dst, t_line * src) {
    int i = 0;
    dst->length = src->length;
    while (src->content[i] != '\0') {
        dst->content[i] = src->content[i];
        i++;
    }
    dst->content[i] = '\0';
}

void buffer_add_line(t_buffer * buffer, t_line * line, int n) {
    if (line->content == NULL) {
        return;
    }

    if (buffer->card < n) {
        
        line_init(&buffer->line[buffer->card]);
        line_cpy(&buffer->line[buffer->card], line);
        
        buffer->card++;

    } else {
        for (int i = 0; i < n; i++) {
            line_init(&buffer->line[buffer->card]);
            line_cpy(&buffer->line[i], &buffer->line[i + 1]);
        }
        line_cpy(&buffer->line[n - 1], line);
    }
}

void read_file(t_buffer * buffer, int n, FILE *fp) {
    t_line line;
    line_init(&line);
    bool printed = false;

    char z;

    while ((z = fgetc(fp)) != EOF) {
        line.content[line.length++] = z;
        
        if (line.length == LIMIT - 1) {
            if (!printed) {
                fprintf(stderr, "error: one or more lines too long\n");
                printed = true;
            }
            line.content[LIMIT - 2] = '\n';
            line.content[LIMIT - 1] = '\0';
            buffer_add_line(buffer, &line, n);

            free(line.content);
            line_init(&line);
            line.content = calloc(LIMIT, 1);
            continue;
        }

        if (z == '\n') {
            line.content[line.length] = '\0';
            buffer_add_line(buffer, &line, n);

            free(line.content);
            line_init(&line);
            line.content = calloc(LIMIT, 1);
        }
    } //z != EOF
    if (line.content != NULL)
        free(line.content);
}


int main(int argc, char ** argv) {
    int n = 10; // implicitni delka
    int argcounter = 0;

    if (argc > 2 && !strcmp(argv[1], "-n")) {
        n = atoi(argv[2]);
        argcounter += 2;
    }

    if (n < 1) {
        fprintf(stderr, "argument: -n number < 1\n");
        return 1;
    }

    if (1 + argcounter >= argc) {
        fprintf(stderr, "missing: no file on input\n");
        return 1;
    }

    FILE *fp;
    fp = fopen(argv[argcounter + 1], "r");
    if (fp == NULL) {
        fprintf(stderr, "error: file could not be laoded\n");
        return 1;
    }

    t_buffer buffer;
    buffer_init(&buffer);
    buffer.line = malloc(LIMIT * n);

    read_file(&buffer, n, fp);


    //konec mainu

    for (int i = 0; i < n; i++) {
        if (buffer.line[i].content != NULL)
            printf("%s", buffer.line[i].content);
    }

    free(buffer.line);
    fclose(fp);

    return 0;
}
