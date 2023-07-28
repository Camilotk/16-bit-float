#include <stdio.h>
#include <criterion/criterion.h>

#include "../src/float.h"

Test(decimal, create) {
    double value = 12.52571;
    unsigned int encoded = encode(value);
    
    cr_assert(encoded == 19011, "12.52571 should be encoded as 19011!");
}

Test(binary, create) {
    double value = 12.52571;
    char* encoded = encodeToBits(value);

    cr_assert_str_eq(encoded, "0100101001000011", "12.52571 should be encoded as 0100101001000011!");
}
