#include "str_work.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define ZERO 48
#define NINE 57

// struct Circle
// {
//     double x;
//     double y;
//     double radius;
// };

void strToLower(char* str)
{
    for (long unsigned int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}
int isObject(char* str)
{
    int ret = 1;
    char rec[100];
    for (long unsigned int i = 0; i < strlen(str); i++) {
        if (str[i] != '(')
            rec[i] = str[i];
        else
            break;
    }
    char figure[] = "circle";
    if (strcmp(rec, figure) == 0)
        ret = 0;
    return ret;
}
int isArguments(char* str)
{
    int countArgs = 0;
    for (long unsigned int i = 7; str[i] != ',' && i < strlen(str); i++) {
        if ((str[i] != '.' && str[i] != ' ')
            && !(str[i] >= ZERO && str[i] <= NINE)) {
            printf("Неправильно введены координаты объекта\n");
            return 1;
        }
        if (str[i] >= ZERO && str[i] <= NINE && str[i + 1] == ' ')
            countArgs++;
        if (str[i] == '.' && (str[i + 1] == ' ' || str[i + 1] == '.')) {
            printf("Неправильно введены координаты объекта\n");
            return 1;
        }
    }
    if (countArgs != 1) {
        printf("Неправильно введены координаты объекта\n");
        return 1;
    }
    long unsigned int index = 0;
    countArgs = 0;
    for (long unsigned int i = 0; i != strlen(str); i++) {
        if (str[i] == ',') {
            index = i + 1;
            i = strlen(str) - 1;
        }
    }
    for (; str[index] != ')' && index < strlen(str); index++) {
        if ((str[index] != '.' && str[index] != ' ')
            && !(str[index] >= ZERO && str[index] <= NINE)) {
            printf("Неправильно введён радиус объекта\n");
            return 1;
        }
        if (str[index] >= ZERO && str[index] <= NINE && str[index + 1] == ' ')
            countArgs++;
        if (str[index] == '.'
            && (str[index + 1] == ' ' || str[index + 1] == '.')) {
            printf("Неправильно введены координаты объекта\n");
            return 1;
        }
    }
    if (countArgs != 0) {
        printf("Неправильно введён радиус объекта\n");
        return 0;
    }
    return 0;
}
int isLastBracket(char* str)
{
    int ret = 1;
    long unsigned int firstBracket = 0;
    size_t endingSymbol;
    if (str[strlen(str) - 1] == '\n')
        endingSymbol = strlen(str) - 2;
    else
        endingSymbol = strlen(str) - 1;
    for (long unsigned int i = 0; i < strlen(str); i++) {
        if (str[i] == ')') {
            firstBracket = i;
            break;
        }
    }
    if (firstBracket == endingSymbol)
        ret = 0;
    return ret;
}