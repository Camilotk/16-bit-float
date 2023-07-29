#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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

// Helper function to check if a character is an ANSI escape code delimiter
bool isEscapeDelimiter(char c) {
    return c == '\x1b' || c == '[' || c == 'm';
}

// Helper function to strip ANSI escape codes from a string
char* stripAnsiEscapeCodes(const char* str) {
    static char result[4096]; // Use a static buffer with a fixed size
    int i = 0, j = 0;
    while (str[i]) {
        // Check for ANSI escape code delimiter
        if (str[i] == '\x1b' && str[i + 1] == '[') {
            // Skip the ANSI escape code and the following character '['
            while (str[i] && str[i] != 'm') {
                i++;
            }
            if (str[i]) {
                i++; // Skip the 'm' delimiter
            }
        } else {
            result[j++] = str[i++];
        }
    }
    result[j] = '\0';
    return result;
}

Test(inspect, positive_value) {
    double value = 12.52571;
    char* expected = "The 12.52571 value is encoded in the value 19011 that is represented in memory as \x1b[32m0100101001000011\x1b[0m.\n\n"
                     "0                      = \x1b[34msign\x1b[0m, this is a \x1b[34mpositive\x1b[0m number.\n"
                     "1-5                    = \x1b[34mpower\x1b[0m, in this case is the value \x1b[34m00018\x1b[0m in decimal.\n"
                     "6-15                   = \x1b[34mmantissa\x1b[0m, in this case is the value \x1b[32m00579\x1b[0m in decimal.\n";

    char* inspection = inspect(value);
    cr_assert_str_eq(stripAnsiEscapeCodes(inspection), stripAnsiEscapeCodes(expected));

    free(inspection);
}

Test(inspect, negative_value) {
    double value = -12.52571;
    char* expected = "The -12.52571 value is encoded in the value 51779 that is represented in memory as \x1b[32m1100101001000011\x1b[0m.\n\n"
                     "0                      = \x1b[34msign\x1b[0m, this is a \x1b[34mnegative\x1b[0m number.\n"
                     "1-5                    = \x1b[34mpower\x1b[0m, in this case is the value \x1b[34m00018\x1b[0m in decimal.\n"
                     "6-15                   = \x1b[34mmantissa\x1b[0m, in this case is the value \x1b[32m00579\x1b[0m in decimal.\n";

    char* inspection = inspect(value);
    cr_assert_str_eq(stripAnsiEscapeCodes(inspection), stripAnsiEscapeCodes(expected));

    free(inspection);
}

