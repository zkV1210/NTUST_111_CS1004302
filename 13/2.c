#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct complex {
    double real;
    double imaginary;
};
void add_complex(struct complex complex1,struct complex complex2,struct complex *complexr);
int main(){
    char number1[10],number2[10];
    scanf("%s %s",number1,number2);
    struct complex complex1={0,0};
    struct complex complex2={0,0};
    struct complex complexr={0,0};
    sscanf(strtok(number1,"+"), "%lf", &complex1.real);
    sscanf(strtok(NULL,"i"), "%lf", &complex1.imaginary);
    sscanf(strtok(number2,"+"), "%lf", &complex2.real);
    sscanf(strtok(NULL,"i"), "%lf",&complex2.imaginary);
    add_complex(complex1,complex2,&complexr);
    printf("%.1lf+%.1lfi",complexr.real,complexr.imaginary);
}
void add_complex(struct complex complex1,struct complex complex2,struct complex *complexr){
    complexr->real = complex1.real+complex2.real;
    complexr->imaginary = complex1.imaginary+complex2.imaginary;
}
