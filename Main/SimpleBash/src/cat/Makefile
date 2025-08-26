CC= gcc -std=c11 -D_GNU_SOURCE
CFLAGS= -Wall -Werror -Wextra
CAT= cat.c
SHELL := /bin/bash
FILE=test1.txt

all: s21_cat

s21_cat:
	$(CC) $(CFLAGS) $(CAT) -o s21_cat

clean:
	rm -rf s21_cat
tests:
	-diff <(./s21_cat $(FILE)) <(cat $(FILE))
	-diff <(./s21_cat -e $(FILE)) <(cat -e $(FILE))
	-diff <(./s21_cat -t $(FILE)) <(cat -t $(FILE))
	-diff <(./s21_cat -s $(FILE)) <(cat -s $(FILE))
#	-diff <(./s21_cat --squeeze-blanck $(FILE)) <(cat -s $(FILE))
	-diff <(./s21_cat -n $(FILE)) <(cat -n $(FILE))
	-diff <(./s21_cat --number $(FILE)) <(cat -n $(FILE))
	-diff <(./s21_cat -b $(FILE)) <(cat -b $(FILE))
#	-diff <(./s21_cat --number-nonblanck $(FILE)) <(cat -b $(FILE))
	-diff <(./s21_cat -etsnb $(FILE)) <(cat -etsnb $(FILE))
	-diff <(./s21_cat -v $(FILE)) <(cat -v $(FILE))

rebuild:
	make clean
	make all
	rm -rf *.a *.o