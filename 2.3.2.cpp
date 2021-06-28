/***********************************************
3.用先序次序的方法构造一棵二叉树：
2）以非递归的中序遍历方法遍历此二叉树。
***********************************************/
#include <stdio.h>
#include <stdlib.h> 
//树结点的数据类型 
typedef char TElemType;
//创建二叉链表结点结构 
typedef struct BiTNode{
	TElemType data;	//结点数据 
	struct BiTNode *lchild, *rchild;	//左右孩子指针 
}BiTNode, *BiTree; 

//定义栈
typedef struct{
	BiTNode *stack;
	int base;
	int top;
	int stacksize;
}Stack;
//初始化栈
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
	printf("请按照先序方式依次输入结点的值(空结点为'.'):\n");
	CreateBiTree(T);
	printf("非递归中序遍历结果为：");
	InOrderTraverse(s, T);
	return 0;
	
}


