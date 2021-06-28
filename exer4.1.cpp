#include <stdio.h>
#include <string.h>

#define N 10 
#define M 15

int main(){
	void sortString(char *[]);
	void scanfString(char str[N][M]);
	void printString(char *p[N]);
	void cmpString(char *p[], char str[N][M]);
	 
	char *p[N],str[N][M];
	
	scanfString(str);
	cmpString(p, str);
	sortString(p);
	
	printf("The squence is:\n");
	printString(p);
	
}

void sortString(char *p[]){
	char *temp;
	
	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - 1 - i; j++){
			if(strcmp(*(p + j), *(p + j + 1)) > 0){
				strcpy(temp, *(p + j));
				strcpy(*(p + j), *(p + j + 1));
				strcpy(*(p + j + 1), temp);
			}
		}
	}
}

void scanfString(char str[N][M]){
	printf("Please input %d strings:\n", N);
	for(int i = 0; i < N; i++){
		scanf("%s",&str[i]);
	}
}

void printString(char *p[N]){
	for(int i = 0; i < N; i++){
		printf("%s\n",p[i]);
	}
}

void cmpString(char *p[], char str[N][M]){
	for(int i = 0; i < N; i++){
		p[i] = str[i];
	}
}
