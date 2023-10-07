#include "fileprocessor.h"
#include <dirent.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define CODE_TEXT 0
#define CODE_INC 1
#define CODE_NAME 2
#define CODE_EXT 3

extern char buffer[200][MAX_FILELENGTH];

int main(int argc, char* argv[])
{
    setlocale(0, "");
    char* directory = "./";
    char* patternPath = 0;
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-d") == 0) {
            if (i + 1 >= argc) {
                perror("no argument for -d");
                exit(1);
            }
            directory = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "-p") == 0) {
            if (i + 1 >= argc) {
                perror("no argument for -p");
                exit(1);
            }
            patternPath = argv[i + 1];
            i++;
        }
    }

    if (directory[strlen(directory) - 1] != '/') {
        perror("directory should end with '/' char");
        exit(1);
    }

    if (patternPath == 0) {
        perror("no pattern file selected");
        exit(1);
    }

    FILE* patternFile;
    if ((patternFile = fopen(patternPath, "r")) == NULL) {
        perror("Error opening patternFile");
        exit(1);
    }
    char pattern[500];
    size_t len = 0;
    if ((len = fread(pattern, sizeof(char), sizeof(pattern), patternFile))
        <= 0) {
        perror("Error reading patternFile");
        exit(1);
    }
    pattern[len] = 0;
    fclose(patternFile);
    printf("Pattern: %s\n", pattern);

    scandirMy(directory);

    printf("\nStart Renaming:\n");
    massRename(pattern);
    return 0;
}
