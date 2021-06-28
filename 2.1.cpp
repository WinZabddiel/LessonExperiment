/*******************************************
2.1 编写一个程序实现两个有序（从小到大）顺序
表合并成为一个顺序表， 合并后的结果放在第一
个顺序表中。
*******************************************/

#include <stdio.h>
#define M 100
typedef int datatype;

//制表 
typedef struct{
	datatype a[M];
	int size;
}sequenceList; 

//空表 
void InitList(sequenceList *L){
	L->size = 0;
}

 
void Func(sequenceList *L1, sequenceList *L2){
	int i,j;
	for(i = 0; i < L2->size; i++ ){
		for(j = L1->size - 1; j >= 0; j--){
			if(L2->a[i] >= L1->a[j]){
				L1->a[j+1] = L2->a[i];
				break;
			}else{
				L1->a[j+1] = L1->a[j];
				if(j == 0)
					L1->a[0] = L2->a[i]; 
			}
		}
		++L1->size;
	}
}
void List(datatype a, sequenceList &L){
	scanf("%d",&a);
	while(a){
		L.a[L.size] = a;
		L.size++;
		scanf("%d",&a);
	}
}
int main(){
	sequenceList L1,L2;
	datatype a;
	int i;
	InitList(&L1);
	InitList(&L2);
	printf("请从小到大输入顺序表L1(以0结束)：");
	List(a, L1);
//	scanf("%d",&a);
//	while(a){
//		L1.a[L1.size] = a;
//		L1.size++;
//		scanf("%d",&a);
//	} 
	printf("请从小到大输入顺序表L2(以0结束)：");
	List(a, L2);
//	scanf("%d",&a);
//	while(a){
//		L2.a[L2.size] = a;
//		L2.size++;
//		scanf("%d",&a);
//	}
	Func(&L1, &L2);
	printf("合并处理后，顺序表L1为："); 
	for(i = 0; i < L1.size ; i++){
		printf("%d ",L1.a[i]);
	}
	return 0; 
}

