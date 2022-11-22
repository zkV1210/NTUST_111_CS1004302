#include <stdio.h>
#include <string.h>

int main(){
    char number[20],*token;
    //phone_number length need to be 9 
    //avoiding lost the '\n' at the end when appending token to phone_number[] may lost the '\n' at the end.
    char area_code[4]={'\0'},phone_number[9];
    int area = 0;
    long nums=0;
    scanf("%s",number);
    token = strtok(number,")");
    strcpy(area_code,token+1);
    token = strtok(NULL,"-");
    strcpy(phone_number,token);
    token = strtok(NULL,"-");
    strcat(phone_number,token);
    for (int i =0;i<8;i++){
        nums = nums*10+(phone_number[i]-48);
    }
    for (int i = 0;i<4;i++){
        if (area_code[i]!='\0'){
            area = area*10+(area_code[i]-48);
        }
    }
    printf("%02d\n%ld\n",area,nums);
}