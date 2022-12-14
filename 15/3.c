#include <stdio.h>
#include <stdlib.h>
struct link{
    int number;
    struct link *nPtr;
    struct link *pPtr;
};
typedef struct link Link; 
void displayList(Link *data);
void insert1(Link **previous, Link **next,int input);
void insert2(Link **previous, Link **next,int input);
void insert3(Link **previous, Link **next,int node,int input);
void delete(Link **previous,Link **next,int input);
int main(){
    Link *start = NULL,*end = NULL;
    int method = 0,input = 0,node = 0;
    while(method!=-1){
        scanf("%d",&method);
        switch(method){
            case 1:
                scanf("%d",&input);
                insert1(&start,&end,input);
                displayList(start);
                printf("\n");
                break;
            case 2:
                scanf("%d",&input);
                insert2(&start,&end,input);
                displayList(start);
                printf("\n");
                break;
            case 3:
                scanf("%d %d",&node,&input);
                insert3(&start,&end,node,input);
                displayList(start);
                printf("\n");
                break;
            case 4:
                scanf("%d",&input);
                delete(&start,&end,input);
                displayList(start);
                printf("\n");
                break;
        }
    }
    
}
void insert1(Link **previous, Link **next,int input){
    Link *newPtr = malloc(sizeof(Link));
    newPtr->number = input;
    if (*next==NULL&&*previous==NULL){
        newPtr->nPtr = *next;
        newPtr->pPtr = *previous;
        *previous = newPtr;
    }else{
        newPtr->nPtr = *previous;
        newPtr->pPtr = (*previous)->pPtr;
        (*previous)->pPtr = newPtr;
        *next = *previous;
        *previous = newPtr;
    }
}
void insert2(Link **previous, Link **next,int input){
    if(*next==NULL&&*previous==NULL){
        Link *newPtr = malloc(sizeof(Link));
        newPtr->number = input;
        newPtr->nPtr = *next;
        newPtr->pPtr = *previous;
        *previous = newPtr;
    }else if((*previous)->nPtr!=NULL){
        insert2(&((*previous)->nPtr),next,input);
    }else {
        Link *newPtr = malloc(sizeof(Link));
        newPtr->number = input;
        newPtr->nPtr = (*previous)->nPtr;
        newPtr->pPtr = *previous;
        (*previous)->nPtr = newPtr;
    }
}
void displayList(Link *data){
    if (data!=NULL){
        printf("%4d",data->number);
        if (data->nPtr!=NULL){
            displayList(data->nPtr);
        }
    }
}
void insert3(Link **previous, Link **next,int node,int input){
    if(*next==NULL&&*previous==NULL){
        Link *newPtr = malloc(sizeof(Link));
        newPtr->number = input;
        newPtr->nPtr = *next;
        newPtr->pPtr = *previous;
        *previous = newPtr;
    }else if((*previous)->nPtr!=NULL&&(*previous)->number!=node){
        insert3(&((*previous)->nPtr),next,node,input);
    }else {
        Link *newPtr = malloc(sizeof(Link));
        newPtr->number = input;
        newPtr->nPtr = *previous;
        newPtr->pPtr = (*previous)->pPtr;
        *previous = newPtr;
    }
}
void delete(Link **previous,Link **next,int input){
    if(*previous==NULL){
    }else if((*previous)->nPtr!=NULL&&(*previous)->number!=input){
        delete(&((*previous)->nPtr),next,input);
    }else if((*previous)->nPtr!=NULL&&(*previous)->pPtr!=NULL){
        Link *former = (*previous)->pPtr;
        Link *after =  (*previous)->nPtr;
        former->nPtr = (*previous)->nPtr;
        after->pPtr = (*previous)->pPtr;
    }else if((*previous)->pPtr!=NULL){
        ((*previous)->pPtr)->nPtr = (*previous)->nPtr;
    }else if((*previous)->nPtr!=NULL){
        ((*previous)->nPtr)->pPtr = (*previous)->pPtr;
        *previous = (*previous)->nPtr;
    }else {
        Link *newPtr = *previous;
        *previous = (*previous)->pPtr;
        *next = newPtr->nPtr;
    }
}