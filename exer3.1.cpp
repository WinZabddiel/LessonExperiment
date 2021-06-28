#include <stdio.h>
#include <string.h>

#define N 10

int main(){
	
	void sortString(char (*p)[N]);
	void scanfString(char str[N][N]);
	void printString(char str[N][N]);
	
	char str[N][N];
	char (*p)[N];
	
	scanfString(str);
	p = str;
	
	sortString(p);
	
	printf("The squence is:\n");
	printString(p);
	
}

void sortString(char (*p)[N]){
	char temp[N];
	
	for(int i = 0; i < N - 1; i++){
		for(int j = 0; j < N - 1 - i; j++){
			if(strcmp(*(p + j), *(p + j +1)) > 0){
				strcpy(temp, *(p + j));
				strcpy(*(p + j), *(p + j + 1));
				strcpy(*(p + j + 1), temp);
			}
		}
	}
}

void scanfString(char str[N][N]){
	printf("Please input %d strings:\n",N);
	for(int i = 0; i < N; i++){
		scanf("%s",&str[i]);
	}
}

void printString(char str[N][N]){
	for(int i = 0; i < N; i++){
		printf("%s\n",str[i]);
	}
}
