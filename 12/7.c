#include <stdio.h>
#include <string.h>
int main(){
    char sentence[200],target[200],*searchPtr;
    int now;
    //initialize sentence and word.
    for (int n = 0;n<200;n++){
        sentence[n]='\0';
        target[n]='\0';
    }
    //using "%[^\n]" would read until '\n'.
    scanf("%[^\n]",sentence);
    scanf("%s",target);
    searchPtr = strstr(sentence,target);
    while (searchPtr!=NULL){
        printf("%s\n",searchPtr);
        searchPtr = strstr(searchPtr+1,target);
    }

}