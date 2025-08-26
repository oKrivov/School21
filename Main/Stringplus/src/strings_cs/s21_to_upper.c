#include "s21_string_cs.h"

void *s21_to_upper(const char *str) {
  if (str == S21_NULL) {
    return S21_NULL;
  }

  int len = s21_strlen(str);
  char *new_str = malloc(sizeof(char) * (len + 1));

  if (new_str) {
    s21_memcpy(new_str, str, len + 1);

    for (int i = 0; i < len; i++) {
      if (new_str[i] >= 'a' && new_str[i] <= 'z') {
        new_str[i] -= 'a' - 'A';
      }
    }
  }

  return new_str;
}