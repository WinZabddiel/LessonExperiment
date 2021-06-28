/***********************************************
3.���������ķ�������һ�ö�������
1�����ֵݹ���������򡢺���������ʽ�����˶�������
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
//�ṹ���ʼ�� 
void Init(BiTree *T){
	*T = (BiTree)malloc(sizeof(BiTNode));
	(*T)->lchild = NULL;
	(*T)->rchild = NULL;
}
//���������� 
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
//���������ǰ�������
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
	printf("�밴������ʽ�����������ֵ(�ս��Ϊ'.'):\n");
	CreateBiTree(&T);
	printf("����������Ϊ��"); 
	PreOrderTraverse(T);
	printf("\n����������Ϊ��"); 
	InOrderTraverse(T);
	printf("\n����������Ϊ��"); 
	PostOrderTraverse(T);
	return 0;
	
}

