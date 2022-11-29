#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct fraction{
    int numerator;
    int denominator; 
};
void reduce(struct fraction f, struct fraction * reduced_f);
int main(){
    char number[10];
    struct fraction org={0,0};
    struct fraction reduced={0,0};
    scanf("%s",number);
    sscanf(strtok(number,"/"), "%d", &org.numerator);
    sscanf(strtok(NULL,"/"), "%d", &org.denominator);
    reduce(org,&reduced);
    printf("%d/%d\n",reduced.numerator,reduced.denominator);
}
void reduce(struct fraction f, struct fraction * reduced_f){
    int GCD = 0,smaller=0;
    if (f.numerator>f.denominator){
        smaller=f.denominator;
    }else {
        smaller=f.numerator;
    }
    for (int i =1;i<=smaller;i++){
        if (f.denominator%i==0&&f.numerator%i==0){
            GCD=i;
        }
    }
    reduced_f->numerator=f.numerator/GCD;
    reduced_f->denominator=f.denominator/GCD;
}