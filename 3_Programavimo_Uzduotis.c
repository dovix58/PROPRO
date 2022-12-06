// LSP == 2213741 kavoliunudovyda@gmail.com(dovydas.kavoliunas@mif.stud.vu.lt) 3 užduotis 8 variantas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define name_length 100
typedef struct word
{
    char *array;
    int size;
}word;
void clear(word *word) {

    (*word).size = 0;
    (*word).array = realloc((*word).array, 0);
}
void push(word *word, char value) {
    ++(*word).size;
    (*word).array = realloc((*word).array, (*word).size * sizeof(char));
    (*word).array[(*word).size - 1] = value;

}
char *getFileName(char *str, char *string) {
    char name[name_length];
    int isCorrect = 0;
    while (!isCorrect) {
        printf("%s\n", string);
        scanf("%s", name);
        int len = strlen(name);
        if (name[len - 1] == 't' && name[len - 2] == 'x' && name[len - 3] == 't' && name[len - 4] == '.') {
            isCorrect = 1;
        }
        else {
            printf("inputed file is in the wrong format. Try again.\n");
        }
    }

    strcpy(str, name);
    return str;
}
FILE *readOpen(char name[]) {

    FILE *str = NULL;
    str = fopen(name, "r");
    if (str == NULL) {
        printf("file can't be opened to read \nStopping program");
        exit(0);
    }
    return str;
}
FILE *writeOpen(char name[]) {

    FILE *str = NULL;
    str = fopen(name, "w+");
    if (NULL == str) {
        printf("file can't be opened to write \n Stopping program");
        exit(0);
    }
    return str;

}
bool read(FILE *str, word *w) {
    clear(w);
    fseek(str, ftell(str), SEEK_SET);
    char symbol;
    do
    {
        symbol = fgetc(str);
        if (symbol != EOF) {
            push(w, symbol);
        }
        else {
            push(w, ' ');
        }
    } while (symbol != ' ' && symbol != '\n' && symbol != EOF);
    if (symbol == EOF) {
        return false;
    }
    return true;
}
void write(FILE *str, word *w) {                         //atspausdinama i faila is kito array galo
    for (int i = w->size - 2; i >= 0; --i) {
        fprintf(str, "%c", w->array[i]);
    }
    fprintf(str, "%c", w->array[w->size - 1]);
}


int main() {

    char *name = malloc(sizeof(char) * name_length);
    char file_name[name_length];
    strcpy(file_name, getFileName(name, "Input the file name with the date to be read."));
    FILE *readNamePtr = readOpen(file_name);
    strcpy(file_name, getFileName(name, "Input the file name where the reversed words will be written"));
    FILE *writeNamePtr = writeOpen(file_name);
    word a1;
    while (read(readNamePtr, &a1)) {
        write(writeNamePtr, &a1);
    }
    write(writeNamePtr, &a1);
    free(name);
    free(a1.array);
    fclose(readNamePtr);
    fclose(writeNamePtr);
    return 0;
}
