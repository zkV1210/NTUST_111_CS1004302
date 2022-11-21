#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(int deck[][13]);
void swap_own(int *x,int *y);
void decide(int card[][2]);
void sort(int card[][2]);

int main(){
	srand(time(NULL));
	int deck[4][13],times=1;
	for (int i =0;i<4;i++){
		for (int n = 0;n<13;n++){
			deck[i][n]=times;
			times++;
		}
	}
	shuffle(deck);
	int cards[52][2],card[5][2];
	for (int i =0;i<4;i++){
		for (int n = 0;n<13;n++){
			cards[deck[i][n]-1][0]=i;
			cards[deck[i][n]-1][1]=n+1;
		}
	}
	for (int i =0;i<5;i++){
		for (int n = 0; n<2;n++){
			card[i][n]=cards[i][n];
		}
	}
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
		printf(" \n");
	}
	sort(card);
	decide(card);
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
void decide(int card[][2]){
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
			isprinted++;
		}else if (count==3&&card[0][1]==1&& card[1][1]==10){
			printf("Straght flush\n");
			isprinted++;
		}else {
			printf("Flush\n");
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
		isprinted++;
	}else if(isprinted==0&&count==3&&card[0][1]==1&&card[1][1]==10){
		printf("Straight\n");
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
		isprinted++;
	}else if(countL==3||countR==3){
		if(card[0][1]==card[1][1]&&card[3][1]==card[4][1]){
			printf("Full house\n");
			isprinted++;
		}else {
			printf("Three of a kind\n");
			isprinted++;
		}
	}else if(countR==2||countL==2){
		if(card[1][1]==card[2][1]||card[2][1]==card[3][1]&&isprinted==0){
			printf("Two pair\n");
			isprinted++;
		}else if(card[0][1]==card[1][1]&&card[3][1]==card[4][1]&&isprinted==0){
			printf("Two pair\n");
			isprinted++;
		}else if(card[1][1]==card[2][1]&&card[3][1]==card[4][1]&&isprinted==0){
			printf("Two pair\n");
			isprinted++;
		}else{
			printf("One pair\n");
			isprinted++;
		}
	}
	if (card[1][1]==card[2][1]||card[2][1]==card[2][3]&&isprinted==0){
		if (isprinted==0){
			printf("One pair\n");
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
		isprinted++;
	}
 	if (isprinted==0){
		printf("High card\n");
	}
}