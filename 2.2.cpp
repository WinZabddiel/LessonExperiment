/**************************************************
2.2利用栈结构具有先进后出的特性，编程实现：输入一个
任意十进制数，转换为八进制数和二进制数进行输出。
*************************************************/ 

#include <stdio.h> 
#include <stdlib.h>

#define INITSIZE 10
#define ERROR 0
#define OK 1
#define INCREMENT 2
typedef int Elemtype;
typedef int Status;
typedef struct{
	Elemtype *base;
	Elemtype *top;
	int StackSize; 
}SqStack;

Status InitStack(SqStack *S){
	S->base = (Elemtype*)malloc(sizeof(Elemtype)*INITSIZE);
	if(!S->base){
		return ERROR;
	}
	S->top = S->base;
	S->StackSize = INITSIZE;
	return OK;
}

Status PushStack(SqStack *S, Elemtype e){
	if(S->top - S->base >= S->StackSize){
		S->base = (Elemtype*)realloc(S->base,(S->StackSize + INCREMENT)*sizeof(Elemtype));
		if(!S->base){
			return ERROR;
		}
		S->top = S->base + S->StackSize;
		S->StackSize += INCREMENT;
	}
	*S->top = e;
	S->top++;
	return OK;
}

Status StackEmpty(SqStack *S){
	if(S->top == S->base){
		return OK;
	}
	return ERROR;
}

Status PopStack(SqStack *S, Elemtype *e){
	if (S->top == S->base){
		return ERROR;
	}
	*e = *--S->top;
	return OK;	
}

void Func_10_8_2(int number, int cet){
	SqStack S;
	Elemtype e;
	InitStack(&S);
	if(number == 0){
		printf("转换后的%d进制数为：0", cet);
		return ;
	}
	printf("转换后的%d进制数为：", cet);
	while(number){
	PushStack(&S, number%cet);
	number = number/cet;
	}
	while(!StackEmpty(&S)){
		PopStack(&S, &e);
		printf("%d", e);
	}
}
int main(){
	int number,cet;
	printf("请输入要转换的十进制数：");
	scanf("%d",&number);
	printf("请输入要转换的数制：");
	scanf("%d",&cet);
	Func_10_8_2(number,cet);
	return 0; 
}
