CC= gcc
CFLAGS= -Wall -Werror -Wextra -std=c11
BUILD_DIR=../build/

all: cipher

rebuild: clean all

cipher: cipher.c
	$(CC) $(CFLAGS) cipher.c -o $(BUILD_DIR)cipher

clean:
	rm -rf ${BUILD_DIR}cipher