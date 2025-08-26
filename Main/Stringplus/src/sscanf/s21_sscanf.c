#include "s21_sscanf.h"

const char *SkipWhitespace(const char *str) {
  while (isspace((unsigned char)*str)) {
    str++;
  }
  return str;
}

void ProccessLengthAndWidth(const char **p_format, const char **p_input,
                            int *width, char *length) {
  (*p_format)++;
  *p_input = SkipWhitespace(*p_input);

  while (isdigit((unsigned char)*(*p_format))) {
    *width = *width * 10 + (*(*p_format) - '0');
    (*p_format)++;
  }

  switch (*(*p_format)) {
    case ('h'): {
      *length = 'h';
      (*p_format)++;
      break;
    }
    case ('l'): {
      *length = 'l';
      (*p_format)++;
      break;
    }
    case ('L'): {
      *length = 'L';
      (*p_format)++;
      break;
    }
  }
}

int GetStrtolBase(const char p_format) {
  int base = 0;
  switch (p_format) {
    case 'd':
      base = 10;
      break;
    case 'i':
      base = 0;
      break;
    case 'o':
      base = 8;
      break;
    case 'x':
    case 'X':
      base = 16;
      break;
    default:
      base = 0;
      break;
  }
  return base;
}

int ProccessSignedIntNumbers(va_list args, const char *p_format,
                             const char **p_input, int width, char length) {
  int error = 0;
  char *endptr;
  int base = GetStrtolBase(*p_format);

  char temp_input[100] = {0};
  if (width > 0) {
    s21_strncpy(temp_input, *p_input, width);
    temp_input[width] = '\0';
  } else {
    s21_strncpy(temp_input, *p_input, sizeof(temp_input) - 1);
  }

  if (length == 'h') {
    short *short_ptr = va_arg(args, short *);
    *short_ptr = (short)strtol(temp_input, &endptr, base);
  } else if (length == 'l') {
    long *long_ptr = va_arg(args, long *);
    *long_ptr = strtol(temp_input, &endptr, base);
  } else {
    int *int_ptr = va_arg(args, int *);
    *int_ptr = (int)strtol(temp_input, &endptr, base);
  }
  if (endptr == temp_input) {
    va_end(args);
    error = 1;
  }

  *p_input += (endptr - temp_input);

  return error;
}

int ProccessUnsignedIntNumbers(va_list args, const char *p_format,
                               const char **p_input, int width, char length) {
  int error = 0;
  char *endptr;
  int base = GetStrtolBase(*p_format);

  char temp_input[100] = {0};
  if (width > 0) {
    s21_strncpy(temp_input, *p_input, width);
    temp_input[width] = '\0';
  } else {
    s21_strncpy(temp_input, *p_input, sizeof(temp_input) - 1);
  }

  if (length == 'h') {
    unsigned short *short_ptr = va_arg(args, unsigned short *);
    *short_ptr = (unsigned short)strtol(temp_input, &endptr, base);
  } else if (length == 'l') {
    unsigned long *long_ptr = va_arg(args, unsigned long *);
    *long_ptr = (unsigned long)strtol(temp_input, &endptr, base);
  } else {
    unsigned int *int_ptr = va_arg(args, unsigned int *);
    *int_ptr = (unsigned int)strtol(temp_input, &endptr, base);
  }

  if (endptr == *p_input) {
    va_end(args);
    error = 1;
  }

  *p_input += (endptr - temp_input);

  return error;
}

int ProccessFloatNumbers(va_list args, const char **p_input, int width,
                         char length) {
  int error = 0;
  char *endptr;

  char temp_input[100] = {0};
  if (width > 0) {
    s21_strncpy(temp_input, *p_input, width);
    temp_input[width] = '\0';
  } else {
    s21_strncpy(temp_input, *p_input, sizeof(temp_input) - 1);
  }

  if (length == 'L') {
    long double *double_ptr = va_arg(args, long double *);
    *double_ptr = strtod(temp_input, &endptr);
  } else {
    float *float_ptr = va_arg(args, float *);
    *float_ptr = (float)strtod(temp_input, &endptr);
  }

  if (endptr == *p_input) {
    va_end(args);
    error = 1;
  }

  *p_input += (endptr - temp_input);

  return error;
}

void ProccessChar(va_list args, const char **p_input) {
  char *char_ptr = va_arg(args, char *);
  *char_ptr = **p_input;
  (*p_input)++;
}

void ProccessString(va_list args, const char **p_input, int width) {
  if (isspace((unsigned char)*(*p_input))) {
    *p_input = SkipWhitespace(*p_input);
  }
  char *str_ptr = va_arg(args, char *);
  int i = 0;
  while (**p_input && !isspace((unsigned char)*(*p_input)) &&
         (width == 0 || i < width)) {
    str_ptr[i++] = **p_input;
    (*p_input)++;
  }
  str_ptr[i] = '\0';
}

void ProccessN(va_list args, const char *p_input, const char *input) {
  int *int_ptr = va_arg(args, int *);
  *int_ptr = (int)(p_input - input);
}

void ProccessPointer(va_list args, const char **p_input) {
  void **ptr_ptr = va_arg(args, void **);
  *ptr_ptr = (void *)strtoull(*p_input, (char **)p_input, 16);
}

int ProccessPercent(va_list args, const char **p_input) {
  int error = 0;
  if (**p_input != '%') {
    va_end(args);
    error = 1;
  } else {
    (*p_input)++;
  }
  return error;
}

int ScanText(va_list args, const char *input, const char *format) {
  int error = 0, count = 0;
  const char *p_format = format, *p_input = input;
  int width = 0;
  char length = 0;
  while (*p_format && !error) {
    if (*p_format == '%') {
      ProccessLengthAndWidth(&p_format, &p_input, &width, &length);
      if (*p_format == 'd' || *p_format == 'i') {
        error =
            ProccessSignedIntNumbers(args, p_format, &p_input, width, length);
      } else if (*p_format == 'u' || *p_format == 'o' || *p_format == 'x' ||
                 *p_format == 'X') {
        error =
            ProccessUnsignedIntNumbers(args, p_format, &p_input, width, length);
      } else if (*p_format == 'f' || *p_format == 'g' || *p_format == 'G' ||
                 *p_format == 'e' || *p_format == 'E') {
        error = ProccessFloatNumbers(args, &p_input, width, length);
      } else if (*p_format == 'c') {
        ProccessChar(args, &p_input);
      } else if (*p_format == 's') {
        ProccessString(args, &p_input, width);
      } else if (*p_format == 'n') {
        ProccessN(args, p_input, input);
        count--;
      } else if (*p_format == 'p') {
        ProccessPointer(args, &p_input);
      } else if (*p_format == '%') {
        ProccessPercent(args, &p_input);
        count--;
      } else {
        if (*p_input != *p_format) {
          va_end(args);
          error = 1;
        }
      }
      if (!error) {
        count++;
      }
    }
    if (!error) {
      do {
        p_format++;
      } while (isspace((unsigned char)*p_format));
      if (isspace((unsigned char)*(p_format - 1))) {
        p_input = SkipWhitespace(p_input);
      }
    }
  }
  return count;
}

int s21_sscanf(const char *input, const char *format, ...) {
  if (input == S21_NULL || *input == '\0') {
    return -1;
  }
  va_list args;
  va_start(args, format);

  int count = ScanText(args, input, format);

  va_end(args);
  return count;
}