#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
int main(){
	FILE *f1 ,*f2 ,*result;
	f1 = fopen("14_1file1.txt","r");
	f2 = fopen("14_1file2.txt","r");
	result = fopen("result.txt","w+");
	char fa1[300]={0},fa2[300]={0},fa3[600]={0};
	fgets(fa1, 300, f1 );
	fgets(fa2, 300, f2 );
	strcat(fa3,fa1);
	strcat(fa3,fa2);
	printf("%s",fa3);
	fputs(fa3,result);
	fclose(f1);
	fclose(f2);
	fclose(result);
}