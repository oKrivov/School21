#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct arguments {
  int b, n, s, E, T, v;
} arguments;

arguments argument_parser(int argc, char* argv[]) {
  arguments arg = {0};
  struct option long_options[] = {{"number", 0, 0, 'n'},
                                  {"number-nonblank", 0, 0, 'b'},
                                  {"squeeze-blank", 0, 0, 's'},
                                  {0, 0, 0, 0}};
  int opt;
  while ((opt = getopt_long(argc, argv, "bnseEtTv", long_options, 0)) != -1) {
    switch (opt) {
      case 'b':
        arg.b = 1;
        break;
      case 'n':
        arg.n = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 'e':
        arg.E = 1;
        arg.v = 1;
        break;
      case 'E':
        arg.E = 1;
        break;
      case 't':
        arg.T = 1;
        arg.v = 1;
        break;
      case 'T':
        arg.T = 1;
        break;
      case 'v':
        arg.v = 1;
        break;
      case '?':
        perror("Error");
        exit(1);
        break;
      default:
        break;
    }
  }
  return arg;
}

char v_output(char ch) {
  if (ch == '\n' || ch == '\t') return ch;

  if (ch <= 31) {
    putchar('^');
    ch += 64;
  } else if (ch == 127) {
    putchar('^');
    ch = '?';
  }
  return ch;
}

void outline(arguments* arg, char* line, int n) {
  for (int i = 0; i < n; i++) {
    if (arg->T && line[i] == '\t')
      printf("^I");
    else {
      if (arg->E && line[i] == '\n') putchar('$');
      if (arg->v) line[i] = v_output(line[i]);
      putchar(line[i]);
    }
  }
}

void output(arguments* arg, char* argv[]) {
  FILE* f = fopen(argv[optind], "r");
  if (!f) {
    perror("Error opening file");
    exit(1);
  }

  char* line = NULL;
  size_t memline = 0;
  int read = 0;
  int line_count = 1;
  int empty_count = 0;

  while ((read = getline(&line, &memline, f)) != -1) {
    if (line[0] == '\n')
      empty_count++;
    else
      empty_count = 0;
    if (arg->s && empty_count > 1) {
      continue;
    } else {
      if (arg->n || arg->b) {
        if (arg->b && line[0] != '\n') printf("%6d\t", line_count++);
        if (arg->b && arg->E && line[0] == '\n') printf("      \t");
        if (arg->n && !arg->b) printf("%6d\t", line_count++);
      }
      outline(arg, line, read);
    }
  }
  free(line);
  fclose(f);
}

int main(int argc, char* argv[]) {
  arguments arg = argument_parser(argc, argv);

  if (optind >= argc) {
    fprintf(stderr, "Expected argument after options\n");
    return EXIT_FAILURE;
  }

  output(&arg, argv);

  return 0;
}