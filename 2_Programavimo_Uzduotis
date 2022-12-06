// LSP == 2213741 kavoliunudovyda@gmail.com(dovydas.kavoliunas@mif.stud.vu.lt) 2 užduotis 5 variantas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int validatedInput() {
    int isCorrect = 0;
    int number;

    while (!isCorrect) {
        if (scanf("%d", &number) == 1 && getchar() == '\n') {
            isCorrect = 1;
        }
        else {
            printf("Input is not a whole number. Input again\n");
            while (getchar() != '\n');
        }
    }

    return number;

}
void input(int size, int array[][size]) {

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            array[i][j] = validatedInput();
            //(rand() % (20 - -10 + 1)) + -10;

        }
    }
}
void printAnswer(int number, char msg[]) {
    printf("%s :%d\n", msg, number);
}
void findMaxOfMinimums(int size, int array[][size]) {

    int maxOfMin;
    int collumIndex = 0;
    int row;
    int collum;
    for (int i = 0; i < size; ++i) {
        int minValue = array[i][0];
        for (int j = 0; j < size; j++) {
            if (minValue >= array[i][j]) {
                minValue = array[i][j];
                collumIndex = j;
            }
        }
        printf("\n|%d|\n", minValue);
        printf("%dx%d", i + 1, collumIndex + 1);
        if (i == 0) {
            maxOfMin = minValue;
        }
        if (maxOfMin <= minValue) {
            maxOfMin = minValue;
            row = i + 1;
            collum = collumIndex + 1;
        }
    }
    printAnswer(row, "\nrow of the number");
    printAnswer(collum, "collum of the number");
    printAnswer(maxOfMin, "biggest number out of rows");
}
int main()
{
    int N;
    printf("This program will find the smallest number in each row and then the biggest among them\n");
    printf("input a whole number N: ");
    N = validatedInput();
    int array[N][N];
    input(N, array);
    //srand(time(0));
    for (int i = 0; i < N; ++i) {
        printf("\n");
        for (int j = 0; j < N; ++j) {
            printf(" %2d", array[i][j]);
        }
    }
    printf("\n");
    findMaxOfMinimums(N, array);
    return 0;
}
