#include <stdio.h>
#include <string.h>
int testPalindrome(char *str,int now);
int main(){
    char str[200],strnew[200];
    int len = 0,now=0;
    for (int i = 0;i<200;i++){
        str[i]='\0';
        strnew[i]='\0';
    }
    scanf("%[^\n]",str);
    len = strlen(str);
    for (int i = 0;i<len;i++){
        if (str[i]!='\0'&&str[i]!=' '&&str[i]!='.'&&str[i]!=','){
            strnew[now]=str[i];
            now++;
        }
    }
    len = strlen(strnew);
    if (testPalindrome(strnew,len-1)){
        printf("True\n");
    }else{
        printf("False\n");
    }
}

int testPalindrome(char *str,int now){
    if (str[now]==str[strlen(str)-1-now]||str[now]==str[strlen(str)-1-now]-32||str[now]==str[strlen(str)-1-now]+32){
        if (now>0){
            now--;
            testPalindrome(str,now);
        }else{
            return 1;
        }
    }else {
        return 0;
    }
}