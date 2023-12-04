#include <stdio.h>
#include <string.h>

char* numbers[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    FILE* f = fopen("./d1.in", "r");
    int total = 0;

    unsigned char c;

    // these must be reset on every endline
    char first = -1;
    char last = -1;
    char cur_l[100];
    unsigned char index; // index of cur_l position

    while(!feof(f)) {
        c = fgetc(f);

        if(c >= 49 && c <= 57) { // if number
            if(first == -1) first = c - 48; // just minus ascii offset to get real number
            last = c - 48;

        } else if(c == 10) { // if character endline, reset states and add to total
            total += ((first) * 10) + (last);
            first = -1;
            last = -1;
            memset(cur_l, 0, 100);
            index = 0;

        } else { // if character is not number or endline
            cur_l[index] = c; // continue our list of the current line
            
            for(int i = 0; i < 9; i++) { // for every number 1-9
                size_t n_len = strlen(numbers[i]); // get the length
                char match = 1; // start valid
                for(int k = 0; k < n_len; k++) { // for evry char in that number
                    if(cur_l[index - k] != numbers[i][n_len - k - 1]) { match = 0; } // compare it to the end of the cur_l array, if invalid set invalid
                }
                if(match == 1) { // if it matches
                    if(first == -1) first = i + 1;
                    last = i + 1;
                }
            }

            index++;
        }

    }
 
    printf("Total: %d\n", total);

    return 0;
}
