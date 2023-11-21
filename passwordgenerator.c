#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    // all variables for the program
    char lowercase[26] = { "abcdefghijklmnopqrstuvwxyz" };
    char uppercase[26] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    char symbols[20] = { "!@#$^&*()_+-=`.,';[]" };
    char numbers[9] = { "123456789" };
    int randomNum = 0;
    int size;
    int clearBuffer;

    srand(time(NULL)); // this is required at beginning of main if srand is going to be used otherwise function won't function properly

    do {
        size = -1; // each loop resets size to invalid value so that character or string input must be reinputted
        do { // do while to make sure input is an integer and between 1-100
            printf("Input a password size from 1-100 (0 exits program): ");
            scanf("%d", &size);

            while ((clearBuffer = getchar()) != '\n' && clearBuffer != EOF) {} // clears input buffer so that char/string input doesn't infinitely loop the program

        } while (size < 0 || size > 100);

        char password[size]; // set passwords size to inputted length

        for (int i = 0; i < size; i++) {

            randomNum = (rand() % 4) + 1; // generates random number for 1-4

            if (randomNum == 1) {
                randomNum = rand() % 26; // generates random number for 0-25
                password[i] = lowercase[randomNum]; // stores a random character in lowercase into password
            }
            if (randomNum == 2) {
                randomNum = rand() % 26; // generates random number for 0-25
                password[i] = uppercase[randomNum]; // stores a random character in lowercase into password
            }
            if (randomNum == 3) {
                randomNum = rand() % 20; // generates random number for 0-19
                password[i] = symbols[randomNum]; // stores a random character in lowercase into password
            }
            if (randomNum == 4) {
                randomNum = (rand() % 10); // generates random number for 0-9
                password[i] = numbers[randomNum]; // stores a random number in lowercase into password
            }
        }

        if (size != 0) { // if they did not exit the program, print this before the generated password
            printf("Your new password: ");
        }

        for (int i = 0; i < size; i++) {
            printf("%c", password[i]);
        }
        printf("\n");

    } while (size != 0); // exit program if size input is 0

    return 0;
}