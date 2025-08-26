CC= gcc -std=c11 -D_GNU_SOURCE
CFLAGS= -Wall -Werror -Wextra
GREP= grep.c
SHELL := /bin/bash
FILE=test.txt

all: s21_grep

s21_grep:
	$(CC) $(CFLAGS) $(GREP) -o s21_grep

clean:
	rm -rf s21_grep

tests:
	-diff <(./s21_grep empt $(FILE)) <(grep empt $(FILE))
	-diff <(./s21_grep -v empt $(FILE)) <(grep -v empt $(FILE))
	-diff <(./s21_grep -i Empt $(FILE)) <(grep -i Empt $(FILE))
	-diff <(./s21_grep -iv Empt $(FILE)) <(grep -iv Empt $(FILE))
	-diff <(./s21_grep -in Empt $(FILE)) <(grep -in Empt $(FILE))
	-diff <(./s21_grep -ie "^yes" $(FILE)) <(grep -ie "^yes" $(FILE))
	-diff <(./s21_grep -ince "^yes" $(FILE)) <(grep -ince "^yes" $(FILE))
	-diff <(./s21_grep -lh se $(FILE)) <(grep -lh se $(FILE))
	-diff <(./s21_grep -c Yes $(FILE)) <(grep -c Yes $(FILE))
	-diff <(./s21_grep -e Yes -e again $(FILE)) <(grep -e Yes -e again $(FILE))
	-diff <(./s21_grep -s Yes $(FILE)) <(grep -s Yes $(FILE))

rebuild:
	make clean
	make all
	rm -rf *.a *.o