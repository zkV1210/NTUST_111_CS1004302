#include <stdio.h>
#include <string.h>

int main(){
    char words[4][200],sentence[800],*token,delim[2]=" ";
    int count=0;
    for (int i=0;i<4;i++){
        for (int n = 0;n<200;n++){
            words[i][n]='\0';
        }
    }
    for (int i=0;i<4;i++){
        scanf(" %[^\n]",words[i]);
        strcat(sentence,words[i]);
        strcat(sentence," ");
    }
    token = strtok(sentence,delim);
    while(token != NULL){
        token = strtok(NULL, delim);
        count++;
    }
    printf("%d\n",count);
}