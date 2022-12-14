#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct link{
    char number;
    struct link *nPtr;
};
typedef struct link Link; 
void  push(Link **data,char input);
void add(Link **data,char input);
int check(Link *a,Link *b);
int main(){
    char words[200]={0};
    Link *start1=NULL;
    Link *start2=NULL;
    fgets(words,200,stdin);
    for(int i = 0;i<200;i++){
        if(words[i]!=0&&words[i]!='\n'&&words[i]!=' '){
            push(&start1,words[i]);
            add(&start2,words[i]);
        }
    }
    if(check(start1,start2)){
        printf("True\n");
    }else{
        printf("False\n");
    }

}
void push(Link **data,char input){
    Link *newPtr =  malloc(sizeof(Link));
    if (input<97){
        input = input+32;
    }
    newPtr->nPtr=*data;
    *data = newPtr;
    newPtr->number = input;
}
void add(Link **data,char input){
    if ((*data)!=NULL){
        add(&((*data)->nPtr),input);
    }else{
        if (input<97){
            input = input+32;
        }
        Link *newPtr = malloc(sizeof(Link));
        newPtr->number = input;
        newPtr->nPtr = *data;
        *data = newPtr;
    }
}
int check(Link *a,Link *b){
    if (a->nPtr!=NULL&&b->nPtr!=NULL){
        if (a->number==b->number){
            return check(a->nPtr,b->nPtr);
        }else{
            return 0;
        }
    }else{
        if (a->number==b->number){
            return 1;
        }else{
            return 0;
        }
    }
}