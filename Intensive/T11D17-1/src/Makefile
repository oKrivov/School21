CC= gcc
CFLAGS= -Wall -Werror -Wextra -std=c11
BUILD_DIR= ../build/

all: door_struct
rebuild: clean all

door_struct: dmanager_module.c
	$(CC) $(CFLAGS) dmanager_module.c -o $(BUILD_DIR)Quest_1


clean:
	rm -rf ${BUILD_DIR}Quest_* 