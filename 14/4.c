#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
    int tnow=0,hnow=0,twin=0,hwin=0,t,h;
    printf("BANG !!!!!\n");
    printf("AND THEY'RE OFF !!!!!\n");
    while (twin==0&&hwin==0){
        t = rand()%10+1;
        printf("%d",t);
        if (t>=1&&t<=5){
            tnow+=3;
            printf("T Fast plod\n");
        }else if(t==6||t==7){
            hnow-=6;
            printf("T Slip\n");
            if (tnow<0){
                tnow=0;
            }
        }else if(t>=8||t<=10){
            printf("T plod\n");
            tnow++;
        }
        h = rand()%10+1;
        printf("%d",h);
        if (h==1||h==2){
            printf("H Sleep\n");
        }else if(h==3||h==4){
            hnow+=9;
            printf("H Big hop\n");
        }else if(h==5){
            hnow-=12;
            printf("H Big slip\n");
            if (hnow<0){
                hnow=0;
            }
        }else if(h>=6&&h<=8){
            hnow++;
            printf("H Small hop\n");
        }else if(h==9||h==10){
            hnow-=2;
            if (hnow<0){
                hnow=0;
            }
            printf("H Small slip\n");
        }
        for (int i = 0;i<70;i++){
            if (i==tnow&&i==hnow){
                printf("OUCH!!!");
            }else if (i==tnow){
                printf("T");
            }else if(i==hnow){
                printf("H");
            }else {
                printf(" ");
            }
        }
        printf("\n");
        if(tnow>=69&&hnow>=69){
            printf("It's a tie\n");
            twin++;
            hwin++;
        }else if(tnow>=69){
            printf("TORTOISE WINS!!! YAY!!!\n");
            twin++;
        }else if(hnow>=69){
            printf("Hare wins. Yuch\n");
            hwin++;
        }
    }
}
