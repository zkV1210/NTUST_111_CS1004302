#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
int main(){
    srand(time(NULL));
    char article[5][5] = {"the", "a", "one", "some" , "any"};
    char noun[5][5] = {"boy", "girl", "dog", "town","car"};
    char verb[5][8] = {"drove", "jumped", "ran", "walked" , "skipped"};
    char prepositions[5][6]={"to", "from", "over", "under" , "on"};
    char sentence[32] = {'\0'};
    for (int i = 0;i<20;i++){
        strcat(sentence,article[rand()%5]);
        strcat(sentence," ");
        strcat(sentence,noun[rand()%5]);
        strcat(sentence," ");
        strcat(sentence,verb[rand()%5]);
        strcat(sentence," ");
        strcat(sentence,prepositions[rand()%5]);
        strcat(sentence," ");
        strcat(sentence,article[rand()%5]);
        strcat(sentence," ");
        strcat(sentence,noun[rand()%5]);
        strcat(sentence,".");
        sentence[0]=sentence[0]-32;
        printf("%s\n",sentence);
        for (int n =0;n<32;n++){
            sentence[n]='\0';
        }
    }
}