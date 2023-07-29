#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "src/float.h"

int main() {
    char command;
    float value;
    unsigned int intValue;
    char input[100];

    while (true) {
        printf("Enter a command (e <float> / d <unsigned int> / i <float> / q): ");
        fgets(input, sizeof(input), stdin);
        sscanf(input, "%c", &command);

        switch (command) {
            case 'e':
                sscanf(input, "%*c %f", &value);
                unsigned int encodedValue = encode(value);
                printf("Encoded value: %u\n", encodedValue);
                break;

            case 'd':
                sscanf(input, "%*c %u", &intValue);
                float decodedValue = decode(intValue);
                printf("Decoded value: %f\n", decodedValue);
                break;

            case 'i':
                sscanf(input, "%*c %f", &value);
                char *inspection = inspect(value);
                printf("%s", inspection);
                free(inspection);
                break;

            case 'q':
                printf("Exiting. Have a nice week!\n");
                return 0;

            default:
                printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}
