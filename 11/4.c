#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(int deck[][13]);
void swap_own(int *x,int *y);
int decide(int card[][2]);
void sort(int card[][2]);
void printcard(int card[][2]);
void reset(int deck[][13]);
int main(){
	srand(time(NULL));
	int deck[4][13];
    reset(deck);
	shuffle(deck);
	int cards[52][2],card1[5][2],card2[5][2],cardtype[2],card1org[5][2],card2org[5][2];
	for (int i =0;i<4;i++){
		for (int n = 0;n<13;n++){
			cards[deck[i][n]-1][0]=i;
			cards[deck[i][n]-1][1]=n+1;
		}
	}
	for (int i =0;i<5;i++){
		for (int n = 0; n<2;n++){
			card1[i][n]=cards[i][n];
            card1org[i][n]=cards[i][n];
		}
	}
    reset(deck);
    shuffle(deck);
    for (int i =0;i<4;i++){
		for (int n = 0;n<13;n++){
			cards[deck[i][n]-1][0]=i;
			cards[deck[i][n]-1][1]=n+1;
		}
	}
    for (int i =0;i<5;i++){
		for (int n = 0; n<2;n++){
			card2[i][n]=cards[i][n];
            card2org[i][n]=cards[i][n];
		}
	}
	printcard(card1);
	sort(card1);
	cardtype[0]=decide(card1);
    printcard(card2);
	sort(card2);
	cardtype[1]=decide(card2);
    if (cardtype[0]<cardtype[1]){
        printcard(card1org);
    }else if(cardtype[0]>cardtype[1]){
        printcard(card2org);
    }else{
        int countA1=0,countA2=0;
        for (int i =0;i<5;i++){
            if (card1[i][1]==1){
                countA1++;
            }
            if (card2[i][1]==1){
                countA2++;
            }
        }
        if (countA1>countA2){
            printcard(card1org);
        }else if(countA1<countA2){
            printcard(card2org);
        }else{
            for (int i =4;i>=0;i--){
                if (card1[i][1]>card2[i][1]){
                    printcard(card1org);
                    break;
                }else if(card1[i][1]<card2[i][1]){
                    printcard(card2org);
                    break;
                }else if(i==0){
                    printf("deuce\n");
                }
            }
        }
    }
}
void reset(int deck[][13]){
    int times=1;
    for (int i =0;i<4;i++){
		for (int n = 0;n<13;n++){
			deck[i][n]=times;
			times++;
		}
	}
}
void printcard(int card[][2]){
	for (int i=0;i<5;i++){
		switch(card[i][0]){
			case 0:
				printf("S");
				break;
			case 1:
				printf("H");
				break;
			case 2:
				printf("D");
				break;
			case 3:
				printf("C");
				break;
		}
		switch(card[i][1]){
			case 1:
				printf("A");
				break;
			case 11:
				printf("J");
				break;
			case 12:
				printf("Q");
				break;
			case 13:
				printf("K");
				break;
			default:
				printf("%d",card[i][1]);
				break;
		}
        printf(" ");
	}
    printf("\n");
}
void shuffle(int deck[][13]){
	void swap_own(int *x,int *y);
	for (int i = 0;i<4;i++){
		for (int n=0;n<13;n++){
			swap_own(&deck[i][n],&deck[rand()%4][rand()%13]);
		}
	}
}
void swap_own(int *x,int *y){
	unsigned int temper = *x;
	*x = *y;
	*y = temper;
}
void sort(int card[][2]){
	int temp0=0,temp1 = 0;
	for (int i =0;i<4;i++){
		for (int n = 0;n<4-i;n++){
			if (card[n][1]>card[n+1][1]){
				temp0=card[n+1][0];
				temp1=card[n+1][1];
				card[n+1][0]=card[n][0];
				card[n+1][1]=card[n][1];
				card[n][0]=temp0;
				card[n][1]=temp1;
			}
		}
	}
}
int decide(int card[][2]){
	int isprinted =0,count=0;
	//同花
	if (card[0][0]==card[1][0]&&card[1][0]==card[2][0]&&card[2][0]==card[3][0]&&card[3][0]==card[4][0]){
		for (int i=0;i<4;i++){
			if(card[i][1]+1==card[i+1][1]){
				count++;
			}
		}
		if (count==4&&card[5][1]!=5){
			printf("Straght flush\n");
            return 1;
			isprinted++;
		}else if (count==3&&card[0][1]==1&& card[1][1]==10){
			printf("Straght flush\n");
            return 1;
			isprinted++;
		}else {
			printf("Flush\n");
            return 4;
			isprinted++;
		}
	}
	//順子
	count=0;
	for (int i=0;i<4;i++){
		if(card[i][1]+1==card[i+1][1]){
			count++;
		}
	}
	if (count==4&&isprinted==0&&card[5][1]!=5){
		printf("Straight\n");
        return 5;
		isprinted++;
	}else if(isprinted==0&&count==3&&card[0][1]==1&&card[1][1]==10){
		printf("Straight\n");
        return 5;
		isprinted++;
	}
	//鐵支
	int countL=0,countR=0;
	for (int i =0;i<5;i++){
		if (card[0][1]==card[i][1]){
			countL++;
		}
		if (card[4][1]==card[i][1]){
			countR++;
		}
	}
	if(countL==4||countR==4){
		printf("Four of a kind\n");
        return 2;
		isprinted++;
	}else if(countL==3||countR==3){
		if(card[0][1]==card[1][1]&&card[3][1]==card[4][1]){
			printf("Full house\n");
            return 3;
			isprinted++;
		}else {
			printf("Three of a kind\n");
            return 6;
			isprinted++;
		}
	}else if(countR==2||countL==2){
		if(card[1][1]==card[2][1]||card[2][1]==card[3][1]&&isprinted==0){
			printf("Two pair\n");
            return 7;
			isprinted++;
		}else if(card[0][1]==card[1][1]&&card[3][1]==card[4][1]&&isprinted==0){
			printf("Two pair\n");
            return 7;
			isprinted++;
		}else if(card[1][1]==card[2][1]&&card[3][1]==card[4][1]&&isprinted==0){
			printf("Two pair\n");
            return 7;
			isprinted++;
		}else{
			printf("One pair\n");
            return 8;
			isprinted++;
		}
	}
	if (card[1][1]==card[2][1]||card[2][1]==card[2][3]&&isprinted==0){
		if (isprinted==0){
			printf("One pair\n");
            return 8;
			isprinted++;
		}
	}
	count=0;
	for (int i=1;i<4;i++){
		if (card[1][1]==card[i][1]){
			count++;
		}
	}
	if(count==3&&isprinted==0){
		printf("Three of a kind\n");
        return 6;
		isprinted++;
	}
 	if (isprinted==0){
		printf("High card\n");
        return 9;
	}
}