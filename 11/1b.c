#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mazeTraverse(char map[][13],int now[2],int heading);
void findentry(char map[][13],int now[2]);
void mazeGenerator(char map[][13]);
int main(){
    srand(time(NULL));
	char map[12][13];
	int now[2],heading=1;
    for (int i =0;i<12;i++){
        for (int n =0;n<12;n++){
            map[i][n]='#';
        }
        map[i][12]='\n';
    }
    mazeGenerator(map);
    findentry(map,now);
    mazeTraverse(map,now,heading);
}
void findentry(char map[][13],int now[2]){
    for (int i =0;i<12;i++){
		if (map[i][0]=='.'){
			now[0]=i;
			now[1]=0;
		}
	}
    }
void mazeGenerator(char map[][13]){
    for (int i =0;i<12;i++){
        for (int n =0;n<12;n++){
            map[i][n]='#';
        }
        map[i][12]='\n';
    }
    int start= 0,next=0,nowinside[2],times=0;
    start = rand()%10+1;
    nowinside[0]=start;
    nowinside[1]=0;

    while(nowinside[1]!=11){
        map[nowinside[0]][nowinside[1]]='.';
        next=rand()%2;
        if (next){
            nowinside[1]++;
        }
        map[nowinside[0]][nowinside[1]]='.';
        next=rand()%2;
        times++;
        switch (next){
            case 0:
                if (nowinside[0]+1<11&&nowinside[1]!=0){
                    nowinside[0]++;
                }
            case 1:
                if (nowinside[0]-1>0&&nowinside[1]!=0){
                    nowinside[0]--;
                }
        }
    }
    for (int x = 1;x<11;x++){
        for (int y=1;y<11;y++){
            if(rand()%2){
                map[x][y]='.';
            }
        }
    }
    for (int x = 0; x<12;x++){
			for (int y = 0;y<12;y++){
				printf("%c",map[x][y]);
			}
			printf("\n");
	}
    printf("\n");
    
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