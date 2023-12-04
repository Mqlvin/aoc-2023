#include <stdio.h>
#include <string.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int main() {
    FILE* f;
    f = fopen("./d2.in", "r");
    
    char nbui[2] = {-1, -1}; // number, -1 null
    unsigned char c;
    char gamestarted = 0; 
  
    unsigned char blue = 0; // totals for each round
    unsigned char green = 0;
    unsigned char red = 0;

    int totalproduct = 0; // total game id

    while(!feof(f)) {
        c = fgetc(f);

        if(gamestarted == 0 && c == ':') { // if game isnt started but we get a colon, mark it as started
            gamestarted = 1;
        } else

        if(c >= '0' && c <= '9' && gamestarted == 1) { // if number and game is started
            if(nbui[0] == -1) nbui[0] = c - 48;
            else nbui[1] = c - 48;
        } else
        
        if(c >= 'a' && gamestarted && !(nbui[0] == -1 && nbui[1] == -1)) { // if lowercase character and last few chars were number
            unsigned char num;
            if(nbui[1] != -1) num = nbui[0] * 10 + nbui[1];
            else num = nbui[0];

            if(c == 'r') red = MAX(red, num);
            else if(c == 'g') green = MAX(green, num); 
            else if(c == 'b') blue = MAX(blue, num);
      
            memset(nbui, -1, 2);
        } else

        if(c == '\n') { // if one "grab" of cubes ended, check if its possible
            totalproduct += red * green * blue;
      
            blue = 0;
            green = 0;
            red = 0;
        }



        if(c == '\n') { // if newline, reset states
            gamestarted = 0; 
        }
    }

    printf("Total product: %d\n", totalproduct);

    return 0;
}
