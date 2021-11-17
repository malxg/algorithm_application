/*
使用栈(非调用)判断该字符串是否中心对称，
如 abccba 即为 中心对称 字符串
*/

#include <stdio.h>
#include <malloc.h>//include malloc()
#define Maxlen 100

typedef struct node{
	char data;
	struct node *next;
}cnode;

cnode *create(char s[])
{
	int i = 0;
	cnode *h,*p,*r;
	
	while(s[i] != '\0')
	{
		p = (cnode *)malloc(sizeof(cnode));
		p->data = s[i];p->next = NULL;//init node p
		
		if(i == 0)
		{
			h = p;
			r = p;//r 始终指向 最后一个结点 
		}
		
		else
		{
			r->next = p;r = p;
		}
		i ++;
		
	}
	
	return h;
}

int judge(cnode *h)
{
	if(h == NULL)
	{
		printf("h is NULL");
		return 0;
	}
	
	char st[Maxlen];
	int top = 0;
	cnode *p = h;   //操作 指针 指向 头结点 
	
	while(p != NULL)//放入 模拟 栈 中 
	{
		st[top ++] = p->data;//从头开始 放 
		p = p->next;         //后移 
	}
	p = h;          //归位，从指向NULL，又 指回 头结点 
	
	while(p != NULL)//与st 刚才存的元素 进行配对 
	{
		top --;     //top 目前指向st数组的末尾，由于上了循环赋值的(top ++) 
		if(p->data == st[top])//起始 头结点 与 st数组 最后一个 元素 比较 
			p = p->next;      //配对 成功 就继续配对，找下一个 结点，然后 回到top -- 与 倒数第二个 元素配对...类推  
			
		else       //有元素配对 失败，直接退出循环 
			break;
	}
	
	if(p ==NULL)//如果 是 配对 成功 才结束（非break，p == NULL,或者 top == 0） 
	{
		return 1;
	}
	else       //如果 是break 中断，说明 配对失败 
	{
		return 0;
	}
}

int main()
{
	char str[Maxlen] = {'\0'};
	cnode *h;
	
	printf("please,enter a string: ");
	scanf("%c",str);
	h = create(str);
	if(judge(h) == 1)
		printf("str 是中心对称字符串\n");
	else
		printf("str 不是中心堆成字符串\n");
		
	return 0;
}
