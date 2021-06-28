/**************************************************
2.2����ջ�ṹ�����Ƚ���������ԣ����ʵ�֣�����һ��
����ʮ��������ת��Ϊ�˽������Ͷ����������������
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
		printf("ת�����%d������Ϊ��0", cet);
		return ;
	}
	printf("ת�����%d������Ϊ��", cet);
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
	printf("������Ҫת����ʮ��������");
	scanf("%d",&number);
	printf("������Ҫת�������ƣ�");
	scanf("%d",&cet);
	Func_10_8_2(number,cet);
	return 0; 
}
