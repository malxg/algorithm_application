/*
ɾ����s1������s2�ִ� 
*/

#include <stdio.h>
#include <string.h>

//��ӡ 
void prin_array(char a[])
{
	for(int i = 0;a[i] != '\0';i ++)
	{
		printf("%c",a[i]);
	}
	printf("\n"); 
	return;
}

//�ҵ����Ӵ���������λ�ã����� ���� ���� ������ ���� �����ȶ� 
int index(char a[],char b[])
{
	//��� ����� ���� ������ Ҫ��ֱ�� ���� 
	if( *a == '\0' && b[0] == '\0' )
	{
		return -1;
	}
	
	
	//j ���� ���� �ִ� 
	int j = 0;
	for(int i = 0;a[i] != '\0';i ++)
	{
		if(a[i] == b[0])
		{
			for(j = 0;b[j] != '\0' && a[i + j] != '\0';j ++)
			{
				if(b[j] != a[i + j])//�ִ� �� ���� �Ա� 
				{
					break;
				}
			}
			//˵�� �ִ� �Ѿ����� ��β�ˣ���Գɹ� 
			if(b[j] == '\0')
			{
				return i;
			}
		}
	}
	
	return -1;
}

void delete_Son(char a[],char b[])
{
	int len_b = strlen(b);//��ȡ �Ӵ� ���� 
	int flag = 0;
	
	int len_a = strlen(a);//��ȡ ���� ���� 
	char c[len_a] = {0};//���� ���� ���� ��ֵ 
	
	strcpy(c,a);//��aֵ ��ֵ��c�У��� c �����޸� 
	prin_array(a);
	prin_array(b);
	
	while(1)
	{
		flag = index(c,b);
		if(flag == -1)
		{
			break;
		}
		
		int i = flag;
		//��Ȼ ���� �� ������ Ҳ���� ��֤ û�� �Ӵ� 
		for(i = flag;i < len_a - len_b;i ++)//��ǰ ���ǣ�����ɾ�����磺abcdfg -> dfgdfg
		{
			c[i] = c[i + len_b];//i + len_b + 1 = len_a -> i < len_a -lenb
		}
		
		for(int j = i;c[j] != '\0';j ++)//��ǰ�ƶ��ɹ�,Ȼ���ٰ�ĩβ��ո��� Ϊ�Ӵ����� ��Ԫ�أ�dfgdfg -> dfg'\0''\0''\0'
		{
			c[j] = '\0';
		}
		
		
	}

	//��ӡ ����ַ�����
	prin_array(c);
	
	return;
}


int main()
{
	//���� ���� �� �ִ� 
	char *a = "caabcbcfabccabcccxdsa";//���� 
	char *b = "abc";//�ȼ��� b[3] = {'a','b','c'},��ǰ�� �����޸�����ĳ��Ԫ��,ֻ�������޸�,�鿴�����߷����޸� 
	
	delete_Son(a,b);
	
	return 0;
}
