#include "s21_string_cs.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!(src && str)) {
    return S21_NULL;
  }

  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_str = s21_strlen(str);

  char *new_str = S21_NULL;
  if (len_src >= start_index) {
    new_str = malloc(sizeof(char) * len_src + len_str + 1);

    if (new_str) {
      s21_memcpy(new_str, src, start_index);
      char *reserve_new_str = new_str;
      reserve_new_str += start_index;
      src += start_index;
      s21_memcpy(reserve_new_str, str, len_str);
      reserve_new_str += len_str;
      s21_memcpy(reserve_new_str, src, (len_src + 1) - start_index);
    }
  }

  return new_str;
}