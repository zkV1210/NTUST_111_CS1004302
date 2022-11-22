#include <stdio.h>
#include <string.h>
void sort_string(char word[][100],int nums );
int main(){
    char sentence[200],*token,delim[2]=" ",word[100][100];
    int now;
    //initialize sentence and word.
    for (int i =0;i<100;i++){
        for (int n =0;n<100;n++){
            word[i][n]='\0';
        }
    }
    for (int n = 0;n<200;n++){
        sentence[n]='\0';
    }
    //using "%[^\n]" would read until '\n'.
    scanf("%[^\n]",sentence);
    //put words into word[]
    token = strtok(sentence,delim);
    while(token != NULL){
        strcpy(word[now],token);
        token = strtok(NULL, delim);
        now++;
    }
    //clear the " in the last word.
    for (int i =0;i<100;i++){
        if(word[now-1][i]=='"'){
            word[now-1][i]='\0';
        }
    }
    //using ascii code to bubble sort the words.
    sort_string(word,now);
    //print
    for (int i = 0;i<now;i++){
        printf("%c",'"');
        //using for to print out the words in case print out '\0'.
        for (int n=0;n<strlen(word[i]);n++){
            printf("%c",word[i][n]);
        }
        printf("%c",'"');
        if(i!=now-1){
            printf(",");
        }
    } 
    printf("\n");
}
void sort_string(char word[][100],int nums){
    void swap_string(char a[100],char b[100]);
    int dealer = 0;
    for (int i =0;i<nums-1;i++){
        for (int n=0;n<nums-i-1;n++){
            if (strcmp(word[n],word[n+1])>0){
                swap_string(word[n],word[n+1]);
            }
        }
    }
}
void swap_string(char a[100],char b[100]){
    char temp[100] = {'\0'};
    strcpy(temp,a);
    for (int i = 0;i<100;i++){
        a[i]='\0';
    }
    strcpy(a,b);
    for (int i = 0;i<100;i++){
        b[i]='\0';
    }
    strcpy(b,temp);
}