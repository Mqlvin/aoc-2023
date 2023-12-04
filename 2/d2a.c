#include <stdio.h>
#include <string.h>

#define MAX_BLUE 14
#define MAX_GREEN 13
#define MAX_RED 12

int main() {
    FILE* f;
    f = fopen("./d2.in", "r");
    
    unsigned char gamenum = 1;
    unsigned char valid = 1;
    char nbui[2] = {-1, -1}; // number, -1 null
    unsigned char c;
    char gamestarted = 0; 
  
    unsigned char blue = 0; // totals for each round
    unsigned char green = 0;
    unsigned char red = 0;

    int totalid = 0; // total game id

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

            if(c == 'r') red += num;
            else if(c == 'g') green += num;
            else if(c == 'b') blue += num;
      
            memset(nbui, -1, 2);
        } else

        if(c == '\n' || c == ';') { // if one "grab" of cubes ended, check if its possible
            if(!(blue <= MAX_BLUE && green <= MAX_GREEN && red <= MAX_RED)) valid = 0;

            blue = 0;
            green = 0;
            red = 0;
        }



        if(c == '\n') { // if newline, reset states
            if(valid == 1) totalid += gamenum;
            
            valid = 1;
            gamenum++;
            gamestarted = 0; 
      
            printf("Total: %d\n", totalid);
        }
    }

    return 0;
}
