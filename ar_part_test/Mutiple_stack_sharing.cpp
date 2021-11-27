#include<stdio.h>
#include<stdlib.h>
typedef  int ElemType;
typedef struct Linknode{
	ElemType data;
	struct Linknode *next; 
}*LiStack;
void InitStack(LiStack &lst) {//lst需要改变值，用引用 
	lst=(LiStack)malloc(sizeof(Linknode));
	lst->next=NULL;
	
}
int isEmpty(LiStack lst){//判断栈是否为空 
	if(lst->next=NULL)
		return 1;
	else
		return 0;
} 
void Push(LiStack lst,ElemType x){
	Linknode *p;
	p=(Linknode *)malloc(sizeof(Linknode));//为进栈的元素申请结点 
	p->next=NULL;//不写也可以，避免错误的好习惯
	//头插法建立链表
	p->data=x;
	p->next=lst->next;
	lst->next=p; 
	
} 
int Pop(LiStack lst,ElemType &x){//都是在栈顶操作元素的 
	Linknode *p;
	if(lst->next==NULL)
		return 0;
	//以下就是单链表的删除操作
	p=lst->next;
	x=p->data;
	lst->next=p->next;
	free(p);
	return 1; 
}
bool GetTop(LiStack lst,ElemType &x){//读取栈顶元素的值，用x返回 
	if(lst->next==NULL)
	 	return false;
	x=lst->next->data;
	return true;
} 
int main(){
	LiStack lst;
	ElemType a[5]={1,2,3,4,5},temp;
	InitStack(lst);
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++){
		Push(lst,a[i]);
		GetTop(lst,temp);
		printf("栈的第%d个值为%d\n",(i+1),temp);
	}
	printf("出栈\n");
	Pop(lst,temp);
	printf("%d\n",temp);
	Pop(lst,temp);
	printf("%d\n",temp);
	Pop(lst,temp);
	printf("%d\n",temp);
	return 0;
}
