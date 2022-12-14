#include <stdio.h>
#include <stdlib.h>
struct linklist{
    int number;
    struct linklist *nPtr;
};
typedef struct linklist Linklist; 
void displayList(Linklist *data);
void insert(Linklist **data,int input);
void printListBackward(Linklist *data);
int main(){
    Linklist *start = NULL;
    int input = 0;
    for (int i = 0;i<10;i++){
        scanf("%d",&input);
        insert(&start,input);
    }
    displayList(start);
    printf("\n");
    printListBackward(start);
}
void insert(Linklist **data,int input){
    Linklist *newPtr = malloc(sizeof(Linklist));
    int i =0;
    if (newPtr!=NULL){
        newPtr->number = input;
        Linklist *nextPtr = *data;
        Linklist *forPtr = NULL;
        if (*data!=NULL){
            while(input>=nextPtr->number&&(nextPtr->nPtr)!=NULL){
                if((nextPtr->nPtr)->number>input){
                    forPtr = nextPtr;
                    nextPtr = nextPtr->nPtr;
                    forPtr->nPtr = newPtr;
                    newPtr->nPtr = nextPtr;
                    i=1;
                }else{
                    forPtr = nextPtr;
                    nextPtr = nextPtr->nPtr;
                }
            }
            if(i==0&&input<nextPtr->number){
                newPtr->nPtr=*data;
                *data = newPtr;
            }else if(i==0&&input>nextPtr->number){
                newPtr->nPtr = nextPtr->nPtr;
                nextPtr->nPtr = newPtr;
            }
        }else{
            newPtr->nPtr = *data;
            *data = newPtr;
        }
    }
}
void displayList(Linklist *data){
    printf("%4d",data->number);
    if (data->nPtr!=NULL){
        displayList(data->nPtr);
    }
}
void printListBackward(Linklist *data){
    if (data->nPtr!=NULL){
        printListBackward(data->nPtr);
    }
    printf("%4d",data->number);
}