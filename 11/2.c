#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void shuffle(unsigned int deck[][13]){
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

int main(){
	srand(time(NULL));
	unsigned int deck[4][13],times=1;
	for (int i =0;i<4;i++){
		for (int n = 0;n<13;n++){
			deck[i][n]=times;
			times++;
		}
	}
	shuffle(deck);	
	for (int i =0;i<4;i++){
		for (int n = 0;n<13;n++){
			printf("%u ",deck[i][n]);
		}
		printf("\n");
	}
	return 0;
}