#include "s21_string.h"

size_t s21_strlen(char *str) {
    size_t length = 0;
    if (str != NULL) {
        for (; *(str + length); length++) {
        }
    }
    return length;
}

int s21_strcmp(char *str1, char *str2) {
    int cmp;
    if (str1 != NULL && str2 != NULL) {
        for (; *str1 && (*str1 == *str2); str1++, str2++) {
        }
        cmp = *str1 - *str2;
    } else if (str1 == str2) {
        cmp = 0;
    } else if (str1 == NULL) {
        cmp = -1;
    } else {
        cmp = 1;
    }
    return cmp;
}

void s21_strcpy(char *source, char *destination) {
    if (source != NULL && destination != NULL)
        for (; *source != '\0' && *destination; source++, destination++) *destination = *source;
}

char *s21_strcat(char *dest, const char *src) {
    char *ptr = NULL;
    if (dest != NULL) {
        ptr = dest;
        while (*dest != '\0') {
            dest++;
        }
        while (*src) {
            *dest = *src;
            dest++;
            src++;
        }
        *dest = '\0';
    }
    return ptr;
}

char *s21_strchr(char *str, int c) {
    char *ptr = NULL;
    if (str != NULL) {
        while (*str) {
            if ((int)*str == c) {
                ptr = str;
                return ptr;
            }
            str++;
        }
    }
    return ptr;
}