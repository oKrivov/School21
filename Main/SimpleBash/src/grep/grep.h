#ifndef GREP_H
#define GREP_H

typedef struct arguments {
  int e, i, v, c, l, n, h, s, f, o;
  char pattern[1024];
  int len_pattern;
} arguments;
#endif

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pattern_add(arguments *arg, char *pattern);
arguments argumets_parrser(int argc, char *argv[]);
void output_line(char *line, int n);
void process_file(arguments arg, char *path, regex_t *reg);
void output(arguments arg, int argc, char *argv[]);