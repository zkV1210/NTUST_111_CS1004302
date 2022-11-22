#include <stdio.h>
#include <string.h>
void reverseword(char sentence[200],char *token,char delim[2],int start);
int main(){
    char sentence[200],*token,delim[2]=" ",word[100][100];
    for (int i =0;i<100;i++){
        for (int n =0;n<100;n++){
            word[i][n]='\0';
        }
    }
    int now=0;
    for (int n = 0;n<200;n++){
        sentence[n]='\0';
    }
    scanf("%[^\n]",sentence);
    token = strtok(sentence,delim);\
    
    while(token != NULL){
        strcpy(word[now],token);
        token = strtok(NULL, delim);
        now++;
    }
    for (int i =now-1;i>=0;i--){
        if (word[i][0]!='\0'){
            printf("%s ",word[i]);
        }
    }

}