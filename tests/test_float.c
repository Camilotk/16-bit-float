#include <stdio.h>
#include <criterion/criterion.h>

#include "../src/float.h"

Test(main, create) {
    double value = 12.52571;
    unsigned int encoded = encode(value);
    
    cr_assert(encoded == 19011, "12.52571 should be encoded as 19011!");
}
