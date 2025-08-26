CC =gcc
CFLAGS =-Wall -Werror -Wextra -std=c11
GCOV_FLAG =--coverage 

SOURCE_DIR =strings sprintf sscanf strings_cs
SOURCE =$(foreach dir, $(SOURCE_DIR), $(wildcard $(dir)/s21_*.c))
OBJECTS =$(SOURCE:.c=.o)

ifeq ($(shell uname -s), Linux)
	LDLIBS =-lrt -pthread -lsubunit 
else
	LDLIBS =
endif

TESTS_DIR = tests tests/*
TESTS_SOURCE =$(foreach dir, $(TESTS_DIR), $(wildcard $(dir)/s21_*.c))
TESTS_OBJECTS=$(TESTS_SOURCE:.c=.o)
TEST_NAME =s21_tests
TESTS_LIBS =-lcheck -lm -lgcov

GCOV_REPORT_NAME =$(TEST_NAME)_gcov_report
REPORT_LIB =gcov_report


all: clean test


s21_string.a: clean_s21_string_a clean_objects $(OBJECTS)
	ar rc s21_string.a $(OBJECTS)
	ranlib s21_string.a

	make clean_gcov_test clean_objects

test: clean_testing_files s21_string.a $(TESTS_OBJECTS)
	$(CC) $(CFLAGS) $(TESTS_OBJECTS) s21_string.a -o $(TEST_NAME) $(TESTS_LIBS) $(LDLIBS)
	./$(TEST_NAME)
	
	make clean_gcov_test clean_objects

gcov_report:clean_testing_files clean_gcov_lib $(TESTS_OBJECTS)
	$(CC) $(CFLAGS) $(GCOV_FLAG) $(SOURCE) $(TESTS_OBJECTS) -o $(GCOV_REPORT_NAME) $(TESTS_LIBS) $(LDLIBS)
	./$(GCOV_REPORT_NAME)
	lcov -c  -t "$(GCOV_REPORT_NAME)" -o $(GCOV_REPORT_NAME).info -d .
	genhtml -o $(REPORT_LIB)/html_info $(GCOV_REPORT_NAME).info
	open ./$(REPORT_LIB)/html_info/index.html

	make clean_gcov_test clean_objects


$(OBJECTS): clean_objects
	$(CC) $(CFLAGS) -c $(patsubst %.o,%.c, $@) -o $@ $(LDLIBS)

$(TESTS_OBJECTS):  clean_objects
	$(CC) $(CFLAGS) -c $(patsubst %.o,%.c, $@) -o $@ $(LDLIBS)


clean_objects:
	rm -f */*.o */*/*.o

clean_gcov_test:
	rm -f *.gcno */*.gcno */*/*.gcno
	rm -f *.gcov */*.gcov */*/*.gcov
	rm -f *.info */*.info */*/*.info
	rm -f *.gcda */*.gcda */*/*.gcda

clean_s21_string_a:
	rm -f s21_string.a

clean_testing_files:
	rm -f $(TEST_NAME)
	rm -f $(GCOV_REPORT_NAME)

clean_gcov_lib:
	rm -rf $(REPORT_LIB)

clean: clean_objects clean_gcov_test clean_s21_string_a clean_testing_files clean_gcov_lib clean_gcov_test
