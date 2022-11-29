#include <stdio.h>
#include <string.h>
void fact_calc(char *str,int in);
int main(){
    int in = 1,sum=1;
    char str[100];
    scanf("%d",&in);
    while(in!=-1){
        fact_calc(str,in);
        if (in>=0&&in<=9){
            for (int i =0;i<strlen(str)+2;i++){
                printf("*");
            }
            printf("\n*");
            for (int i =0;i<strlen(str);i++){
                printf("%c",str[i]);
            }
            printf("*\n");
            for (int i =0;i<strlen(str)+2;i++){
                printf("*");
            }
            printf("\n");
        }else{
            printf("%s\n",str);
        }
        for (int n = 0;n<100;n++){
            str[n]='\0';
        }
        scanf(" %d",&in);
    }
}
void fact_calc(char *str,int in){
    int sum=1;
    char tstr[10]={0};
    if (in<0||in>9){
        sprintf(str, "%s","Invalid entry");
    }else {
        if (in!=0){
            sprintf(str,"%d!=",in);
            for (int i =in;i>=1;i--){
                sum = sum*i;
                if (i!=1){
                    sprintf(tstr,"%dx",i);
                    strcat(str,tstr);
                    for (int n = 0;n<5;n++){
                        tstr[n]='\0';
                    }
                }else {
                    sprintf(tstr,"%d=%d",i,sum);
                    strcat(str,tstr);
                    for (int n = 0;n<5;n++){
                        tstr[n]='\0';
                    }
                }
            }
        }else{
            sprintf(str,"%d!=1",in);
        }
    }
}