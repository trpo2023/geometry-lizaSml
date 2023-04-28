#include <ctest.h>
#include <stdio.h>

#include "str_work.h"

/*
test_isObject -- тест на определение ошибок в части "circle(
test_isLastBracket -- тест на определение наличия закрывающего символа в данных
строки"
*/

CTEST(test_isObject, inp_error)
{
    char* st = "circlee(";

    int i = isObject(st);

    ASSERT_EQUAL(1, i);
}

CTEST(test_isObject, inp_no_errors)
{
    char* st = "circle(";

    int i = isObject(st);

    ASSERT_EQUAL(0, i);
}

CTEST(test_isLastBracket, inp_error)
{
    char* st = "circle(";

    int i = isLastBracket(st);

    ASSERT_EQUAL(1, i);
}

CTEST(test_isLastBracket, inp_no_errors)
{
    char* st = "circle()";

    int i = isLastBracket(st);

    ASSERT_EQUAL(0, i);
}