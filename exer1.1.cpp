#include <stdio.h> 
#define N 3
int main(){
	void printArray(int a[N][N]);
	void conver(int a[N][N]);
	void scanfArray(int a[N][N]);
	
	int a[N][N];
	
	scanfArray(a); 
	
	printf("The matrix is defined£º\n"); 
	printArray(a);
	
	conver(a);
	
    printf("The matrix is transposed£º\n");
    printArray(a);
	return 0;
}

void conver(int a[N][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int temp;
			a[i][i] = a[i][i];
			if(j > i){
				temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
	}
	
}

void printArray(int a[N][N]){
	for(int i = 0; i < N; i++){
    	for(int j = 0; j < N; j++){
    		printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void scanfArray(int a[N][N]){
	printf("Please define the matrix£º\n");
	for(int i = 0; i < N; i++){
    	for(int j = 0; j < N; j++){
    		scanf("%d",&a[i][j]);
		}
	}
} 
