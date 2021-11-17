/*
ʹ��ջ(�ǵ���)�жϸ��ַ����Ƿ����ĶԳƣ�
�� abccba ��Ϊ ���ĶԳ� �ַ���
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
			r = p;//r ʼ��ָ�� ���һ����� 
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
	cnode *p = h;   //���� ָ�� ָ�� ͷ��� 
	
	while(p != NULL)//���� ģ�� ջ �� 
	{
		st[top ++] = p->data;//��ͷ��ʼ �� 
		p = p->next;         //���� 
	}
	p = h;          //��λ����ָ��NULL���� ָ�� ͷ��� 
	
	while(p != NULL)//��st �ղŴ��Ԫ�� ������� 
	{
		top --;     //top Ŀǰָ��st�����ĩβ����������ѭ����ֵ��(top ++) 
		if(p->data == st[top])//��ʼ ͷ��� �� st���� ���һ�� Ԫ�� �Ƚ� 
			p = p->next;      //��� �ɹ� �ͼ�����ԣ�����һ�� ��㣬Ȼ�� �ص�top -- �� �����ڶ��� Ԫ�����...����  
			
		else       //��Ԫ����� ʧ�ܣ�ֱ���˳�ѭ�� 
			break;
	}
	
	if(p ==NULL)//��� �� ��� �ɹ� �Ž�������break��p == NULL,���� top == 0�� 
	{
		return 1;
	}
	else       //��� ��break �жϣ�˵�� ���ʧ�� 
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
		printf("str �����ĶԳ��ַ���\n");
	else
		printf("str �������Ķѳ��ַ���\n");
		
	return 0;
}
