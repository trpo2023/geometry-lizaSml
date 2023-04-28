#include "print_err.h"
#include "str_work.h"

#include <stdio.h>

// struct point
// {
//     double x;
//     double y;
// };
// typedef struct point point;
// struct circle
// {
//     point center;
//     double radius;
// };
// typedef struct circle circle;

int main()
{
    FILE* file;
    file = fopen("input.txt", "r");

    if (!file) {
        printf("Не найден файл\n");
        return 1;
    }
    char str1[100];
    while (fgets(str1, 99, file)) {
        strToLower(str1);
        printErrors(str1);
        printf("%s\n", str1);
    }
    fclose(file);
    return 0;
}
