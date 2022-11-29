#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct sci_not_t{
    double mantissa;
    double exponent;
}scitype;
void scan_sci(char number[10],scitype *sci);
void compute(scitype sci1,scitype sci2,double *sum,double *difference,double *product,double *quotient);
void print_sci(double number);
int main(){
    char number1[10],number2[10];
    scitype org1,org2;
    double sum,difference,product,quotient;
    scanf("%s %s",number1,number2);
    scan_sci(number1,&org1);
    scan_sci(number2,&org2);
    compute(org1,org2,&sum,&difference,&product,&quotient);
    print_sci(sum);
    print_sci(difference);
    print_sci(product);
    print_sci(quotient);
}
void scan_sci(char number[10],scitype *sci){
    sscanf(strtok(number,"e"), "%lf", &(sci->mantissa));
    sscanf(strtok(NULL,"e"), "%lf", &(sci->exponent));
}
void compute(scitype sci1,scitype sci2,double *sum,double *difference,double *product,double *quotient){
    double num1=sci1.mantissa*pow(10,sci1.exponent),num2=sci2.mantissa*pow(10,sci2.exponent);
    *sum = num1+num2;
    *difference = num1-num2;
    *product = num1*num2;
    *quotient = num1/num2;
}
void print_sci(double number){
    double mantissa;
    int exponent=0;
    while (number>=1.0){
        number = number/10;
        exponent++;
    }
    mantissa=number;
    printf("%.5lfe%d\n",mantissa,exponent);
}