#ifndef S21_STRING_H
#define S21_STRING_H
#include <stdio.h>
#include <stdlib.h>

size_t s21_strlen(char *str);
int s21_strcmp(char *str1, char *str2);
void s21_strcpy(char *source, char *destination);
char *s21_strcat(char *dest, const char *src);
char *s21_strchr(char *str, int c);

#endif