#include "s21_string_cs.h"

void *s21_trim(const char *src, const char *trim_chars) {
  if (!(src && trim_chars)) {
    return S21_NULL;
  }

  int src_len = s21_strlen(src);
  int start_index = 0;
  int end_index = src_len - 1;

  // первые вхождения
  while (start_index < src_len && s21_strchr(trim_chars, src[start_index])) {
    start_index++;
  }

  // последние вхождения
  while (end_index > start_index && s21_strchr(trim_chars, src[end_index])) {
    end_index--;
  }

  int new_str_len =
      (end_index >= start_index) ? (end_index - start_index + 1) : 0;
  char *new_str = malloc(sizeof(char) * new_str_len + 1);
  if (new_str) {
    s21_memcpy(new_str, src + start_index, new_str_len);
    new_str[new_str_len] = '\0';
  }

  return new_str;
}