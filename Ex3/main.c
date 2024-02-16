#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

enum StatusCode {
    INCORRECTED_READ_FILE
};

enum StatusCode find_substring_in_files(const char* substring, int num_files, ...);

int main()
{
    enum StatusCode Status = find_substring_in_files("aaaaaa", 1, "file1.txt");
    if (Status == INCORRECTED_READ_FILE) {
        printf("Incorrected Error: invalid read file");
        return 1;
    }
    return 0;
}

enum StatusCode find_substring_in_files(const char* substring, int num_files, ...)
{
    va_list files;
    va_start(files, num_files);

    for (int i = 0; i < num_files; i++) {
        const char* file_path = va_arg(files, const char*);

        FILE* file;
        if ((file = fopen(file_path, "r")) == NULL) {
            return INCORRECTED_READ_FILE;
        }

        printf("Searching for \"%s\" in file: %s\n", substring, file_path);

        char line[256];
        int line_number = 1;

        while (fgets(line, sizeof(line), file)) {
            int line_length = strlen(line);
            int column_number = 1;
            int substring_length = strlen(substring);

            for (int j = 0; j <= line_length - substring_length; j++) {

                int match = 1;


                for (int k = 0; k < substring_length; k++) {

                    if (line[j + k] != substring[k]) {
                        match = 0;
                        break;
                    }
                }



                if (match) {
                   printf("Found at line: %d, column: %d\n", line_number, column_number);
                }



                column_number++;
            }

            line_number++;
        }

        fclose(file);
    }

    va_end(files);
}