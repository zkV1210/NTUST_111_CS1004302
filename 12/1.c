#include <stdio.h>
#include <string.h>
void stringReverse(char *str,int now);
int main(){
    char str[200];
    int len = 0;
    for (int i = 0;i<200;i++){
        str[i]='\0';
    }
    scanf("%s",str);
    len = strlen(str);
    stringReverse(str,len-1);
}

void stringReverse(char *str,int now){
    printf("%c",str[now]);
    if (now >0){
        now--;
        stringReverse(str,now);
    }
}