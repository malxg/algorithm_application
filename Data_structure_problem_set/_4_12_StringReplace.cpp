/*
��дһ��ʵ�ִ����û�����Replace(&S,T,V).
*/

#include <stdio.h>
//��ȡ������ 
int get_stringSize(char *p);
//��ӡ 
void print_string(char *p);
// �����û����� �ô�v�û��� ��s����t��ͬ�����зǿմ� 
void replace(char s[],char t[],char v[])
{
	int len_v = get_stringSize(v);
	int len_t = get_stringSize(t);
	int len_s = get_stringSize(s);
	
	if(len_s < len_t || len_v == 0 || len_t == 0 || len_s == 0)//������Ϊ��,���Ӵ� ���ܱ������� 
	{
		printf("�滻ʧ��,�������Ϲ涨!!!\n");
		return;
	}
	
	int i = 0,j = 0;
	for(i = 0;s[i] != '\0';i ++)
	{
		for(j = 0;t[j] != '\0';j ++)
		{
			if(s[i + j] == t[j])
			{
				continue;
			}
			break;
		}
		
		//�ȶ��ҵ���һ�� 
		if(t[j] == '\0')
		{
			//���Ҫ�滻�Ĵ�t ���ȴ��� �滻��v 
			if(len_t >= len_v)
			{
				//���滻 ����λ�� 
				//�滻 
				for(int k = 0;k < len_v;k ++)
				{
					s[i + k] = v[k];
				}
				//��Ϊ �滻������ ��Ч���ݣ�����������ǰ��£
				int sub = len_t - len_v;//��ǰ��£�ռ�Ϊ sub
				for(int k = i + len_v;k < len_s;k ++)
				{
					s[k] = s[k + sub];
				}//���subλ Ԫ�� �ᱻ�Լ���ֵΪ�գ�ʡ�˸��ղ��� 
			}
			else//len_t < len_vҪ�滻�Ĵ�t ����С�� �滻��v
			{
				//����λ�� ���滻
				//��� ��λ�� 
				int sub = len_v - len_t;
				for(int k = len_s - 1;k >= i + len_t;k --)
				{
					s[k + sub] = s[k];
				}
				//λ���ڳ�����ʼ�滻
				for(int k = 0;k < len_v;k ++)
				{
					s[i + k] = v[k];
				}
			}
			
			//ԭs �� �ĳ��� ������ �仯������s������ 
			len_s = get_stringSize(s);
		}
		else;//û���ҵ� break���� 
	}
	return;
}

int main()
{
	char s[50] = {'a','b','c','d','a','b','c','a','b'};//��ʼ��һ����,��Ҫ�޸Ķ�����ַ����� 
	char *t = "bcd";//ֻ��Ҫ���ң����޸Ķ�����ַ���ָ�� 
	char *v = "BCD";//ֻ��Ҫ���ң����޸Ķ�����ַ���ָ�� 
	//����ת�� 
	replace(s,t,v);
	print_string(s);
	return 0;
}

//��ȡ������ 
int get_stringSize(char *p)
{
	int i = 0;
	while(*(p + i) != '\0'){i ++;}
	return i;
}

void print_string(char *p)
{
	for(int i = 0;*(p + i) != '\0';i ++)
	{
		printf("%c ",*(p + i));
	}
	printf("\n");
	return;
}
