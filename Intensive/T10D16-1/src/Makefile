CC= gcc
CFLAGS=  -Wall -Werror -Wextra -std=c11
BUILD_DIR= ../build/

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests
rebuild: clean all 

strlen_tests: s21_string.c s21_string_test.c
	$(CC) $(CFLAGS) -DSTRLEN s21_string.c s21_string_test.c -o ${BUILD_DIR}Quest_1

strcmp_tests: s21_string.c s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCMP s21_string.c s21_string_test.c -o ${BUILD_DIR}Quest_2

strcpy_tests: s21_string.c s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCPY s21_string.c s21_string_test.c -o ${BUILD_DIR}Quest_3

strcat_tests: s21_string.c s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCAT s21_string.c s21_string_test.c -o ${BUILD_DIR}Quest_4

strchr_tests: s21_string.c s21_string_test.c
	$(CC) $(CFLAGS) -DSTRCHR s21_string.c s21_string_test.c -o ${BUILD_DIR}Quest_5

clean: 
	rm -rf ${BUILD_DIR}*.o ${BUILD_DIR}Quest_*

