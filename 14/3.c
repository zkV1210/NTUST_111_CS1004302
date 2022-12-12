#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct client {
	double account;
	char name[20];
	double payment;
};
int main(){
	FILE *tran,*oldmast,*newmast;
	
	tran = fopen("trans.txt","r");
	oldmast = fopen("oldmast.txt","r");
	newmast = fopen("newmast.txt","w+");
	
	char tranarray[100][100],temp[100],*ptr,old[100][100],t1[100];
	struct client clients[100];
	int i = 0,times1=0,times2=0,n;
	double trand[100][2];
	for (i=0;i<100;i++){
		for (n = 0;n<100;n++){
			tranarray[i][n]=0;
		}
	}
	for (i=0;i<100;i++){
		fgets(tranarray[i],100,tran);
		if (tranarray[i][0]!=0){
			times1++;
		}
	}
	for (i=0;i<times1;i++){
		strcpy(temp,strtok(tranarray[i]," "));
		trand[i][0]=strtod(temp, &ptr);
		strcpy(temp,strtok(NULL," "));
		trand[i][1]=strtod(temp, &ptr);
	}
	for (i=0;i<100;i++){
		fgets(old[i],100,oldmast);
		if (old[i][0]>=48&&old[i][0]<=57){
			times2++;
		}
	}
	for (i=0;i<times2;i++){
		strcpy(temp,strtok(old[i]," "));
		clients[i].account=strtod(temp, &ptr);
		strcpy(temp,strtok(NULL," "));
		strcpy(clients[i].name,temp);
		strcpy(temp,strtok(NULL," "));
		strcat(clients[i].name," ");
		strcat(clients[i].name,temp);
		strcpy(temp,strtok(NULL," "));
		clients[i].payment=strtod(temp, &ptr);
	}
	int t;
	for (i = 0;i<times1;i++){
		t = 0;
		for (n = 0;n<times2;n++){
			if (clients[n].account==trand[i][0]){
				clients[n].payment = clients[n].payment+trand[i][1];
				t++;
				printf("%.0lf %s %.2lf\n",clients[n].account,clients[n].name,clients[n].payment);
			}
		}
		if (t==0){
			printf("Unmatched transaction record for account number %.0lf\n",trand[i][0]);
		}
	}
    for (n = 0;n<times2;n++){
		sprintf(t1,"%.0lf %s %.2lf\n",clients[n].account,clients[n].name,clients[n].payment);
		fputs(t1, newmast);
	}
	fclose(tran);
	fclose(oldmast);
	fclose(newmast);
}