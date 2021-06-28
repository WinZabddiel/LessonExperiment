/***********************************************
3.���������ķ�������һ�ö�������
2���Էǵݹ������������������˶�������
***********************************************/
#include <stdio.h>
#include <stdlib.h> 
//�������������� 
typedef char TElemType;
//��������������ṹ 
typedef struct BiTNode{
	TElemType data;	//������� 
	struct BiTNode *lchild, *rchild;	//���Һ���ָ�� 
}BiTNode, *BiTree; 

//����ջ
typedef struct{
	BiTNode *stack;
	int base;
	int top;
	int stacksize;
}Stack;
//��ʼ��ջ
void InitStack(Stack* &s){
	s=(Stack*)malloc(sizeof(Stack));
	s->top = s->base = 0;
	s->stacksize = 20;
}
int StackEmpty(Stack* &s){
	if(s->top == s->base){
		return 1;
	}else{
		return 0;	
	}
}
int StackFull(Stack* &s){
	if(s->top - s->base == s->stacksize){
		return 1;
	}else{
		return 0;
	}
}
void StackPush(Stack* &s, BiTNode* &T){
	if(StackFull(s) == 1){
		return ;
	}
	s->stack[s->top].data = T->data;
	s->stack[s->top].lchild = T->lchild;
	s->stack[s->top].rchild = T->rchild;
	s->top++;
}

BiTNode* StackPop(Stack* &s){
	if(StackEmpty(s) == 1){
		return NULL;
	}
	s->top--;
	return &(s->stack[s->top]);
}
void CreateBiTree(BiTNode* &T){
	char ch;
	scanf("%c",&ch);
	if(ch != '.'){
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild); 
	}else{
		T = NULL;
	} 	
}
void InOrderTraverse(Stack* &s, BiTNode* &T){
	InitStack(s);
	BiTNode* p = T;
	BiTNode* q;
	while(p || !StackEmpty(s)){
		if(p){
			StackPush(s, p);
			p = p->lchild;
		}else{
			q = StackPop(s);
			putchar(q->data);
			p = q->rchild;
		}
	}	
}
int main(){
	Stack* s;
	BiTNode* T;
	printf("�밴������ʽ�����������ֵ(�ս��Ϊ'.'):\n");
	CreateBiTree(T);
	printf("�ǵݹ�����������Ϊ��");
	InOrderTraverse(s, T);
	return 0;
	
}


