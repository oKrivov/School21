#include "grep.h"

int main(int argc, char *argv[]) {
  arguments arg = argumets_parrser(argc, argv);
  output(arg, argc, argv);
  return 0;
}

void pattern_add(arguments *arg, char *pattern) {
  if (arg->len_pattern != 0) {
    strcat(arg->pattern + arg->len_pattern, "|");
    arg->len_pattern++;
  }
  arg->len_pattern += sprintf(arg->pattern + arg->len_pattern, "(%s)", pattern);
}

arguments argumets_parrser(int argc, char *argv[]) {
  arguments arg = {0};
  int opt;
  while ((opt = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt) {
      case 'e':
        arg.e = 1;
        pattern_add(&arg, optarg);
        break;
      case 'i':
        arg.i = REG_ICASE;
        break;
      case 'v':
        arg.v = 1;
        break;
      case 'c':
        arg.c = 1;
        break;
      case 'l':
        arg.l = 1;
        break;
      case 'n':
        arg.n = 1;
        break;
      case 'h':
        arg.h = 1;
        break;
      case 's':
        arg.s = 1;
        break;
      case 'f':
        arg.f = 1;
        break;
      case 'o':
        arg.o = 1;
        break;
    }
  }
  if (arg.len_pattern == 0) {
    pattern_add(&arg, argv[optind]);
    optind++;
  }
  if (argc - optind == 1) arg.h = 1;

  return arg;
}

void output_line(char *line, int n) {
  for (int i = 0; i < n; i++) {
    putchar(line[i]);
  }
  if (line[n - 1] != '\n') putchar('\n');
}

void process_file(arguments arg, char *path, regex_t *reg) {
  FILE *f = fopen(path, "r");
  if (f == NULL) {
    if (!arg.s) perror(path);
    exit(1);
  }
  char *line = NULL;
  size_t linecap = 0;
  int read = 0;
  int line_count = 1;
  int c = 0;
  read = getline(&line, &linecap, f);

  while (read != -1) {
    int result = regexec(reg, line, 0, NULL, 0);

    if ((result == 0 && !arg.v) || (result != 0 && arg.v)) {
      if (!arg.c && !arg.l) {
        if (arg.n) printf("%d:", line_count);
        output_line(line, read);
      }
      c++;
    }
    read = getline(&line, &linecap, f);
    line_count++;
  }
  free(line);
  if (arg.c && !arg.l) {
    if (!arg.h) printf("%s:", path);
    printf("%d\n", c);
  }
  if (arg.l && c > 0) printf("%s\n", path);
  fclose(f);
}

void output(arguments arg, int argc, char *argv[]) {
  regex_t reg;
  int error = regcomp(&reg, arg.pattern, REG_EXTENDED | arg.i);
  if (error) perror("ERROR");

  for (int i = optind; i < argc; i++) {
    process_file(arg, argv[i], &reg);
  }
  regfree(&reg);
}
