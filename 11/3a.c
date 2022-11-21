#include <stdio.h>

void decide(int card[][2]);
void sort(int card[][2]);

int main(){
	char now[4];
	int card[5][2];
	for (int i=0;i<5;i++){
		scanf("%s",now);
		switch(now[0]){
			case 'S':
				card[i][0]=0;
				break;
			case 'H':
				card[i][0]=1;
				break;
			case 'D':
				card[i][0]=2;
				break;
			case 'C':
				card[i][0]=3;
				break;
		}
		switch(now[1]){
			case 'A':
				card[i][1]=1;
				break;
			case '1':
				card[i][1]=10;
				break;
			case 'J':
				card[i][1]=11;
				break;
			case 'Q':
				card[i][1]=12;
				break;
			case 'K':
				card[i][1]=13;
				break;
			default:
				card[i][1]=(int)now[1]-48;
				break;
		}
	}
	sort(card);
	for (int i =0;i<5;i++){
		printf("%d %d\n",card[i][0],card[i][1]);
	}
	decide(card);
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
		}else if (count==3&&card[0][1]==1&&card[4][1]==13){
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
	}else if(isprinted==0&&count==3&&card[0][1]==1&&card[4][1]==13){
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