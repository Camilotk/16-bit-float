#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <criterion/criterion.h>

#include "../src/float.h"

// TESTS

Test(decimal_encode, create) {
    double value = 12.52571;
    unsigned int encoded = encode(value);

    cr_assert(encoded == 19011, "12.52571 should be encoded as 19011!");
}

Test(binary_encode, create) {
    double value = 12.52571;
    char* encoded = encodeToBits(value);

    cr_assert_str_eq(encoded, "0100101001000011", "12.52571 should be encoded as 0100101001000011!");
}

Test(decimal_decode, create) {
    double value = 1.0;
    unsigned int encoded = encode(value);
    double decoded = decode(encoded);

    double relative_error = fabs((decoded - value) / value);
    
    // Epsilon for adjust max error range
    double max_relative_error = 1e-4;

    cr_assert(relative_error <= max_relative_error, "Relative error should be within an acceptable range!");
}

Test(inf_and_nan, create) {
    unsigned int encoded_inf_pos = 0b0111110000000000; // 31744
    unsigned int encoded_inf_neg = 0b1111110000000000; // 64512
    unsigned int encoded_nan = 0b0111111111111111;

    double decoded_inf_pos = decode(encoded_inf_pos);
    double decoded_inf_neg = decode(encoded_inf_neg);

    cr_assert(decoded_inf_pos == INFINITY, "Positive Infinity test failed!");
    cr_assert(decoded_inf_neg == -INFINITY, "Negative Infinity test failed!");
    cr_assert(isnan(decode(encoded_nan)), "NaN test failed!");
}

