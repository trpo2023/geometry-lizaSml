#include "print_err.h"
#include "str_work.h"

#include <stdio.h>

int printErrors(char* str)
{
    if (isObject(str))
        printf("Неправильно введено название объекта\n");
    else if (isArguments(str))
        return 0;
    else if (isLastBracket(str))
        printf("Неправильный завершающий символ\n");
    else
        printf("Работает\n");
    return 0;
}