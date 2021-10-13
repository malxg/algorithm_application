#include<stdio.h>
#include<stdlib.h>
typedef  int ElemType;
typedef struct Linknode{
	ElemType data;
	struct Linknode *next; 
}*LiStack;
void InitStack(LiStack &lst) {//lst��Ҫ�ı�ֵ�������� 
	lst=(LiStack)malloc(sizeof(Linknode));
	lst->next=NULL;
	
}
int isEmpty(LiStack lst){//�ж�ջ�Ƿ�Ϊ�� 
	if(lst->next=NULL)
		return 1;
	else
		return 0;
} 
void Push(LiStack lst,ElemType x){
	Linknode *p;
	p=(Linknode *)malloc(sizeof(Linknode));//Ϊ��ջ��Ԫ�������� 
	p->next=NULL;//��дҲ���ԣ��������ĺ�ϰ��
	//ͷ�巨��������
	p->data=x;
	p->next=lst->next;
	lst->next=p; 
	
} 
int Pop(LiStack lst,ElemType &x){//������ջ������Ԫ�ص� 
	Linknode *p;
	if(lst->next==NULL)
		return 0;
	//���¾��ǵ������ɾ������
	p=lst->next;
	x=p->data;
	lst->next=p->next;
	free(p);
	return 1; 
}
bool GetTop(LiStack lst,ElemType &x){//��ȡջ��Ԫ�ص�ֵ����x���� 
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
		printf("ջ�ĵ�%d��ֵΪ%d\n",(i+1),temp);
	}
	printf("��ջ\n");
	Pop(lst,temp);
	printf("%d\n",temp);
	Pop(lst,temp);
	printf("%d\n",temp);
	Pop(lst,temp);
	printf("%d\n",temp);
	return 0;
}
