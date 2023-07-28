#include <stdio.h>
#include <criterion/criterion.h>

#include "../src/problem.h"

Test(main, create) {
    bool isTrue = isMultipleOf(9,3);
    cr_assert(isTrue == true, "9 is a multiple of 3!");
}
