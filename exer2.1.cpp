#include <stdio.h>
#include <string.h>
int count(char a[]){
	int letterCount = 0,numberCount = 0,emptyCounter = 0,otherCount = 0;
	int length = strlen(a);
	for(int i = 0; i < length; i++){
		if(a[i] >= 'A' && a[i] <= 'Z' || a[i] >= 'a' && a[i] <= 'z'){
			letterCount++;
		}
		else if(a[i] >= '0' && a[i] <= '9'){
			numberCount++;
		}
		else if(a[i] == ' '){
			emptyCounter++;	
		}
		else{
			otherCount++;
		}
	}
	printf("letter:%d, digit:%d, space:%d, others:%d",letterCount,numberCount,emptyCounter,otherCount);
}

int main(){
	char str[100];
	printf("Please input string:\n");
	gets(str);
	printf("The string is inputed is:\n");
	puts(str);
	count(str);
	return 0;
}

