#include <stdio.h>

int main() {
    FILE* f = fopen("./d1.input", "r");
    int total = 0;

    unsigned char c;

    // these must be reset to -1 on every endline
    char first = -1;
    char last = -1;

    while(!feof(f)) {
        c = fgetc(f);
        if(c >= 49 && c <= 57) { // if number
            if(first == -1) first = c;
            last = c;
        } else if(c == 10) { // if character endline, reset states and add to total
            total += ((first - 48) * 10) + (last - 48);
            first = -1;
            last = -1;
        }
    }
 
    printf("Total: %d\n", total);

    return 0;
}
