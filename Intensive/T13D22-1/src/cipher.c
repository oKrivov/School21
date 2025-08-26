#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    nofile,
    empty,
    not_empty

} f_flag;

int select_file(char *fname, f_flag *file_flag);

void print_file(char *fname);
void write_file(char *fname, f_flag file_flag);
int cipher_dir();
int caesar_files(const char *fname, int shift);
int clear_files(const char *fname);

int main() {
    f_flag file_flag = nofile;
    int choice;
    char fname[256];

    while (1) {
        choice = 0;
        scanf("%d", &choice);
        while (getchar() != '\n') {
        }

        if (choice == -1) {
            break;
        } else if (choice == 1) {
            select_file(fname, &file_flag) ? print_file(fname) : printf("n/a\n");
        } else if (choice == 2) {
            write_file(fname, file_flag);
            if (file_flag != nofile) print_file(fname);
        } else if (choice == 3) {
            cipher_dir();
        } else {
            printf("n/a\n");
        }
    }

    return 0;
}

int select_file(char *fname, f_flag *file_flag) {
    FILE *file = NULL;
    fgets(fname, 256, stdin);
    fname[strcspn(fname, "\n")] = 0;
    file = fopen(fname, "r");

    if (file != NULL) {
        int count = 0;
        while (fgetc(file) != EOF) count++;
        fclose(file);
        *file_flag = (count != 0) ? not_empty : empty;
    }
    return (*file_flag == not_empty) ? 1 : 0;
}

void print_file(char *fname) {
    FILE *file = fopen(fname, "r");
    char ch;
    while ((ch = fgetc(file)) != EOF) putchar(ch);
    fclose(file);
    printf("\n");
}

void write_file(char *fname, f_flag file_flag) {
    char buffer[4000];
    fgets(buffer, 4000, stdin);

    if (file_flag == nofile) {
        printf("n/a\n");
    } else {
        buffer[strcspn(buffer, "\n")] = 0;
        FILE *file = fopen(fname, "a");
        fprintf(file, "%s", buffer);
        fclose(file);
    }
}

int cipher_dir() {
    char dir_path[256];
    fgets(dir_path, 256, stdin);
    dir_path[strcspn(dir_path, "\n")] = 0;

    int shift;
    int i = scanf("%d", &shift);
    while (getchar() != '\n') {
    }
    shift = (i != 1) ? 0 : (shift % 26);

    DIR *dir = opendir(dir_path);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".c") != NULL) {
            char fname[2000];
            snprintf(fname, sizeof(fname), "%s/%s", dir_path, entry->d_name);
            caesar_files(fname, shift);
        } else if (strstr(entry->d_name, ".h") != NULL) {
            char fname[2000];
            snprintf(fname, sizeof(fname), "%s/%s", dir_path, entry->d_name);
            clear_files(fname);
        }
    }
    closedir(dir);
    return 0;
}

int caesar_files(const char *fname, int shift) {
    FILE *file = fopen(fname, "r");
    char *buffer = NULL;
    size_t size = 0;

    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = malloc(size + 1);
    fread(buffer, 1, size, file);
    buffer[size] = '\0';
    fclose(file);

    for (size_t i = 0; i < size; i++) {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
            buffer[i] = ((buffer[i] - 'a' + shift) % 26) + 'a';
        else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
            buffer[i] = ((buffer[i] - 'A' + shift) % 26) + 'A';
    }

    file = fopen(fname, "w");
    fwrite(buffer, 1, size, file);

    free(buffer);
    fclose(file);
    return 0;
}

int clear_files(const char *fname) {
    FILE *file = fopen(fname, "w");
    fclose(file);
    return 0;
}
