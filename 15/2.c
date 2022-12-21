#include <stdio.h>
#include <stdlib.h>
struct link{
    int number;
    struct link *nPtr;
};
typedef struct link Link; 
void displayList(Link *data);
void insert(Link **data,int input);
void printListBackward(Link *data);
void concatenate(Link *head,Link *tail);
void add(Link **data,int input);
Link *merge(Link **data,Link*data2);
Link *reverse(Link *now,Link *previous);
int main(){
    Link *start1 = NULL;
    Link *start2 = NULL;
    Link *reversestart = NULL;
    int len1 = 0,len2 = 0,input=0;
    scanf("%d %d",&len1,&len2);
    for (int i = 0;i<len1;i++){
        scanf("%d",&input);
        add(&start1,input);
    }
    for (int i = 0;i<len2;i++){
        scanf("%d",&input);
        add(&start2,input);
    }
    concatenate(start1,start2);
    displayList(start1);
    printf("\n");
    start1 = merge(&start1,start2);
    displayList(start1);
    printf("\n");
    reversestart = reverse(start1,NULL);
    displayList(reversestart);
}
void add(Link **data,int input){
    if ((*data)!=NULL){
        add(&((*data)->nPtr),input);
    }else{
        Link *newPtr = malloc(sizeof(Link));
        newPtr->number = input;
        newPtr->nPtr = *data;
        *data = newPtr;
    }
}
void displayList(Link *data){
    printf("%4d",data->number);
    if (data->nPtr!=NULL){
        displayList(data->nPtr);
    }
}
void printListBackward(Link *data){
    if (data->nPtr!=NULL){
        printListBackward(data->nPtr);
    }
    printf("%4d",data->number);
}
void concatenate(Link *head,Link *tail){
    if(head->nPtr!=NULL){
        concatenate(head->nPtr,tail);
    }else{
        head->nPtr=tail;
    }
}
Link *merge(Link **data,Link*data2){
    int count=1;
    Link *countlist = *data;
    while (countlist->nPtr!=NULL){
        count++;
        countlist = countlist->nPtr;
    }
    Link *now = *data;
    Link *next = now->nPtr;
    int temp = 0;
    for (int i = 0;i<count;i++){
        now = *data;
        next = now->nPtr;
        for (int n =1;n<count-i;n++){
            if (now->number>next->number){
                temp = now->number;
                now->number = next->number;
                next->number = temp;
                now = now->nPtr;
                next = next->nPtr;
            }else {
                now = now->nPtr;
                next = next->nPtr;
            }
        }
    }
    return *data;
}
Link *reverse(Link *now,Link *previous){
    Link *newPtr = malloc(sizeof(Link));
    newPtr->number = now->number;
    if (now->nPtr!=NULL){
        newPtr->nPtr = previous;
        previous = newPtr;
        now = now->nPtr;
        return reverse(now,previous);
    }else {
        newPtr->nPtr = previous;
        return newPtr;
    }
}