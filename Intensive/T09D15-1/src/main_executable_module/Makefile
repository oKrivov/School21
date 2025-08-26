CC=gcc
CFLAGS= -Wall -Werror -Wextra -std=c11
BUILD_DIR= ../../build/

all: build build_with_static build_with_dynamic

rebuild: clean build 

build: main_executable_module.o decision.o data_io.o data_process.o data_stat.o
	$(CC) $(CFLAGS) $(BUILD_DIR)main_executable_module.o $(BUILD_DIR)decision.o $(BUILD_DIR)data_io.o $(BUILD_DIR)data_process.o $(BUILD_DIR)data_stat.o -o $(BUILD_DIR)Quest_3

build_with_static: main_executable_module.o decision.o data_io.o data_process.o data_stat.a
	$(CC) $(CFLAGS) $(BUILD_DIR)main_executable_module.o $(BUILD_DIR)decision.o $(BUILD_DIR)data_io.o $(BUILD_DIR)data_process.o  $(BUILD_DIR)data_stat.a -o  $(BUILD_DIR)Quest_5

build_with_dynamic: main_executable_module.o decision.o data_io.o data_process.so data_stat.a
	$(CC) $(CFLAGS) $(BUILD_DIR)main_executable_module.o $(BUILD_DIR)decision.o $(BUILD_DIR)data_io.o $(BUILD_DIR)data_process.o  -L$(BUILD_DIR) -ldata_process_dyn  -o $(BUILD_DIR)Quest_6  

main_executable_module.o: main_executable_module.c
	$(CC) $(CFLAGS) -c main_executable_module.c -o $(BUILD_DIR)main_executable_module.o

decision.o: ../yet_another_decision_module/decision.c
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c -o $(BUILD_DIR)decision.o

data_process.o: ../data_module/data_process.c
	$(CC) $(CFLAGS) -fPIC -c ../data_module/data_process.c -o $(BUILD_DIR)data_process.o

data_process.so: data_process.o  data_stat.o 
	$(CC) $(CFLAGS)  -shared -o $(BUILD_DIR)libdata_process_dyn.so $(BUILD_DIR)data_stat.o $(BUILD_DIR)data_process.o

data_io.o : ../data_libs/data_io.c 
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c -o $(BUILD_DIR)data_io.o 

data_stat.o: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c -o $(BUILD_DIR)data_stat.o

data_stat.a: data_stat.o 
	 ar rc $(BUILD_DIR)data_stat.a $(BUILD_DIR)data_stat.o


clean:
	rm -rf  $(BUILD_DIR)*.so  $(BUILD_DIR)*.o  $(BUILD_DIR)*.a $(BUILD_DIR)Quest_*