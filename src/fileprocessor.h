#ifndef H_FILEPROC
#define H_FILEPROC

#define MAX_FILELENGTH 500

#define CODE_TEXT 0
#define CODE_INC 1
#define CODE_NAME 2
#define CODE_EXT 3

struct renameCode {
    int code;
    char* txt;
};

char buffer[200][MAX_FILELENGTH];
int isFile(const char* path);
void scandirMy(char* dirname);
int getCode(char** pattern);
void massRename(char* pattern);

#endif
