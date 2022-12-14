#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link{
    char number;
    struct link *nPtr;
};
typedef struct link Link; 
void  push(Link **data,char input);
void displayList(Link *data);
int main(){
    char words[200]={0};
    Link *start=NULL;
    fgets(words,200,stdin);
    for(int i = 0;i<200;i++){
        if(words[i]!=0&&words[i]!='\n'){
            push(&start,words[i]);
        }
    }
    displayList(start);

}
void push(Link **data,char input){
    Link *newPtr =  malloc(sizeof(Link));
    newPtr->nPtr=*data;
    *data = newPtr;
    newPtr->number = input;
}
void displayList(Link *data){
    if (data!=NULL){
        printf("%c",data->number);
        if (data->nPtr!=NULL){
            displayList(data->nPtr);
        }
    }
}