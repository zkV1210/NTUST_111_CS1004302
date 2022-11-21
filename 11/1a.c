#include <stdio.h>
void mazeTraverse(char map[][13],int now[2],int heading);
int main(){
	char map[12][13];
	int now[2],heading=1;
	for (int x = 0; x<12;x++){
		for (int y = 0;y<13;y++){
			scanf("%c",&map[x][y]);
		}
	}
	for (int i =0;i<12;i++){
		if (map[i][0]=='.'){
			now[0]=i;
			now[1]=0;
		}
	}
	mazeTraverse(map,now,heading);
}
void mazeTraverse(char map[][13],int now[2],int heading){
	if (map[now[0]][now[1]]!='X'){
		map[now[0]][now[1]]='X';
		for (int x = 0; x<12;x++){
			for (int y = 0;y<12;y++){
				printf("%c",map[x][y]);
			}
			printf("\n");
		}
		printf("\n");
	}
	if(now[1]!=11){
		if (heading == 1){
			if (map[now[0]][now[1]+1]!='#'&&map[now[0]+1][now[1]]=='#'){
				now[1]++;
				mazeTraverse(map,now,heading);
			}else if (map[now[0]+1][now[1]]!='#'){
				heading = 2;
				now[0]++;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]-1][now[1]]!='#'){
				heading = 4;
				now[0]--;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]+1][now[1]]=='#'&&map[now[0]-1][now[1]]=='#'&&map[now[0]][now[1]+1]=='#'){
				heading = 3;
				now[1]--;
				mazeTraverse(map,now,heading);
			}
		}else if (heading==2){
			if(map[now[0]+1][now[1]]!='#'&&map[now[0]][now[1]-1]=='#'){
				now[0]++;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]][now[1]-1]!='#'){
				heading = 3;
				now[1]--;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]][now[1]+1]!='#'){
				heading = 1;
				now[1]++;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]+1][now[1]]=='#'&&map[now[0]][now[1]-1]=='#'&&map[now[0]][now[1]+1]=='#'){
				heading = 4;
				now[0]--;
				mazeTraverse(map,now,heading);
			}
		}else if (heading == 3){
			if (map[now[0]][now[1]-1]!='#'&&map[now[0]-1][now[1]]=='#'){
				now[1]--;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]-1][now[1]]!='#'){
				heading = 4;
				now[0]--;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]+1][now[1]]!='#'){
				heading = 2;
				now[0]++;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]+1][now[1]]=='#'&&map[now[0]][now[1]-1]=='#'&&map[now[0]-1][now[1]]=='#'){
				heading = 1;
				now[1]++;
				mazeTraverse(map,now,heading);
			}
		}else if (heading == 4){
			if (map[now[0]-1][now[1]]!='#'&&map[now[0]][now[1]+1]=='#'){
				now[0]--;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]][now[1]+1]!='#'){
				heading = 1;
				now[1]++;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]][now[1]-1]!='#'){
				heading = 3;
				now[1]--;
				mazeTraverse(map,now,heading);
			}else if(map[now[0]-1][now[1]]=='#'&&map[now[0]][now[1]-1]=='#'&&map[now[0]][now[1]+1]=='#'){
				heading = 2;
				now[0]++;
				mazeTraverse(map,now,heading);
			}
		}
	}
}