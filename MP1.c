#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct coursearray {
	char data[100];
	struct course *next;
}coursearray;

int in_array(int x);
int color[25][25];	
int main() {
	FILE *fp;
	FILE *fc;
	int arr[25][25];
	coursearray holder[25];
	int coursenum[25];
	
	int i = 0, j = 0, k=1, m = 1, a = 0, c=0, b =0, d = 0;

	fc= fopen("201001634.txt", "w");
	fp= fopen("test.txt", "r");
	rewind (fp);
	
	
	
fgets(holder[i].data, 100, fp);
rewind(fp);
while(strcmp(holder[i].data, "END") != 0 && !feof(fp)) {
	for(i=0;i<=20; i++){
		 strcpy(holder[i].data, "");
	}
	i = 0, j = 0, k=1, m = 1, a = 0, c=0, b =0, d = 0;
	for(i=0; i<=20; i++){
		coursenum[i] = 0;
	}
	while(j<=20){
		i =0;
		while(i<=20){
			arr[j][i] = 0;
			color[j][i] = 0;
			i++;
		}
	j++;
	}
	i=0;
		fgets(holder[i].data, 100, fp);
		 while(strcmp(holder[i].data, "\n") != 0 && strcmp(holder[i].data, "END") != 0 && !feof(fp)){
			strcpy(holder[i + 1].data, holder[i].data);
			i++;
			fgets(holder[i].data, 100, fp);
			if(strcmp(holder[i].data, "\n") == 0 || strcmp(holder[i].data, "END") == 0 || feof(fp)) break;
			}
			
	d = i;
	j = 0;
	
	
	j=0;
	
	while(j<d){
		k=0;
		while(holder[j].data[k] != ' ' && holder[j].data[k] != '\n') {
			if(holder[j].data[k+1] == ' ' || holder[j].data[k+1] == '\n')
			coursenum[j] = coursenum[j] + holder[j].data[k];
			else coursenum[j] = holder[j].data[k] * 10;
			k++;
		}
		coursenum[j] = coursenum[j] - 48*(k-1)*10 - 48;
		j++;
		
	}
	


	
	j = 0;
	i = 0;
	
while(j<=d) {
	i = 0;
	while(i<d) {
		c=0;
		a=0;
		k = 1;
		m = 1;
		while(holder[j].data[k] != ' ' && holder[j].data[k] != '\n') {
			k++;
		}
		
		while(holder[i].data[m] != ' ' && holder[i].data[m] != '\n' ) {
			m++;	
		}
		m++;
		b=m;
		
		
		while(holder[j].data[k] != '\0' && holder[j].data[k] != '\n') {
			k++;
			while(holder[i].data[m] != '\0'){
				while(holder[j].data[k] == holder[i].data[m] && holder[i].data[m] != ' ' && holder[i].data[m] != '\n'){
					c++;
					k++; m++;
				}
				
				if(c == 3 && i != j) {
					a = 1;
					arr[j][i] = 1;
					break;
				}
				else {
					k = k-c; m = m + (4 - c);
   				c=0;	
 		  		}
			}
		if(a!=1) {
		m = b;
		k = k+3;
		c=0;
		}
		else break;
	}
	i++;
	}
	j++;
	}
	
	
	i=0; j=0;
	a=-1; c=0; b=0;
	for(j=0; j<d; j++) {
		
		if(in_array(j) == 0){
		a++; b=0;c=0;	
		for(i = j; i<d;i++ ){
			if(arr[j][i] == 0){
				for(c=b; c>0;){
					if(arr[color[a][c -1]][i] == 0 && in_array(i) == 0){
					c--;}
					else break;	
				}
				if(c==0) {
					color[a][b] = i;
					b++;
					
				}
				}
			
			}
		}
			
	}

		for(k=0; k<d; k++){
			for(j=0;j<d; j++){
				for(i=0;i<d;i++){
				if(k==color[j][i]) break;
				}
				if(k==color[j][i]) break;	
				}
				if(j==0)fprintf(fc,"%d MON 8:00-10:00 AM\n", coursenum[k]);
				else if(j==1)fprintf(fc,"%d MON 10:00-12:00 NN\n", coursenum[k]);
				else if(j==2)fprintf(fc,"%d MON 12:00-2:00 PM\n", coursenum[k]);
				else if(j==3)fprintf(fc,"%d MON 2:00-4:00 PM\n", coursenum[k]);
				else if(j==4)fprintf(fc,"%d MON 4:00-6:00 PM\n", coursenum[k]);
				else if(j==5)fprintf(fc,"%d TUE 8:00-10:00 AM\n", coursenum[k]);
				else if(j==6)fprintf(fc,"%d TUE 10:00-12:00 NN\n", coursenum[k]);
				else if(j==7)fprintf(fc,"%d TUE 12:00-2:00 PM\n", coursenum[k]);
				else if(j==8)fprintf(fc,"%d TUE 2:00-4:00 PM\n", coursenum[k]);
				else if(j==9)fprintf(fc,"%d TUE 4:00-6:00 PM\n", coursenum[k]);
				else if(j==10)fprintf(fc,"%d WED 8:00-10:00 AM\n", coursenum[k]);
				else if(j==11)fprintf(fc,"%d WED 10:00-12:00 NN\n", coursenum[k]);
				else if(j==12)fprintf(fc,"%d WED 12:00-2:00 PM\n", coursenum[k]);
				else if(j==13)fprintf(fc,"%d WED 2:00-4:00 PM\n", coursenum[k]);
				else if(j==14)fprintf(fc,"%d WED 4:00-6:00 PM\n", coursenum[k]);
				else if(j==15)fprintf(fc,"%d THURS 8:00-10:00 AM\n", coursenum[k]);
				else if(j==16)fprintf(fc,"%d THURS 10:00-12:00 NN\n", coursenum[k]);
				else if(j==17)fprintf(fc,"%d THURS 12:00-2:00 PM\n", coursenum[k]);
				else if(j==18)fprintf(fc,"%d THURS 2:00-4:00 PM\n", coursenum[k]);
				else if(j==19)fprintf(fc,"%d THURS 4:00-6:00 PM\n", coursenum[k]);
		}
	fprintf(fc,"\n");
	}
	fclose(fp);
	fclose(fc);
	return 0;
}
int in_array(int x){
	int n=0; int k, m;
		for(k=0; k<20; k++){
			for(m=0; m<20; m++) {
				if(x!= 0 && x == color[k][m]){
					n = 1; break;
				}
			}	
		}
	return n;	
}	