/***********************************************
3.用先序次序的方法构造一棵二叉树：
1）三种递归的先序、中序、后续遍历方式遍历此二叉树。
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
//结构体初始化 
void Init(BiTree *T){
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
}
//建立二叉树 
void CreateBiTree(BiTree *T){
	TElemType ch;
	scanf("%c",&ch);
	if(ch == '.'){
		*T = NULL;
	}else{
		*T= (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree(&((*T)->lchild));
		CreateBiTree(&((*T)->rchild));
	} 
}
//先序遍历（前序遍历）
void PreOrderTraverse(BiTree T){
	if(T == NULL){
		return;
	}
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);

} 

void InOrderTraverse(BiTree T){
	if(T == NULL){
		return;
	}
	InOrderTraverse(T->lchild);	
	printf("%c",T->data);
	InOrderTraverse(T->rchild);
} 

void PostOrderTraverse(BiTree T){
	if(T == NULL){
		return;
	}
	PostOrderTraverse(T->lchild);	
	PostOrderTraverse(T->rchild);
	printf("%c",T->data);
} 
int main()
{
	BiTree T;
	Init(&T);
	printf("请按照先序方式依次输入结点的值(空结点为'.'):\n");
	CreateBiTree(&T);
	printf("先序遍历结果为："); 
	PreOrderTraverse(T);
	printf("\n中序遍历结果为："); 
	InOrderTraverse(T);
	printf("\n后序遍历结果为："); 
	PostOrderTraverse(T);
	return 0;
	
}

