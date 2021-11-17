/*
删除串s1中所有s2字串 
*/

#include <stdio.h>
#include <string.h>

//打印 
void prin_array(char a[])
{
	for(int i = 0;a[i] != '\0';i ++)
	{
		printf("%c",a[i]);
	}
	printf("\n"); 
	return;
}

//找到在子串在主串的位置，传入 两个 数组 变量， 进行 遍历比对 
int index(char a[],char b[])
{
	//如果 传入的 数组 不符合 要求，直接 返回 
	if( *a == '\0' && b[0] == '\0' )
	{
		return -1;
	}
	
	
	//j 用来 保存 字串 
	int j = 0;
	for(int i = 0;a[i] != '\0';i ++)
	{
		if(a[i] == b[0])
		{
			for(j = 0;b[j] != '\0' && a[i + j] != '\0';j ++)
			{
				if(b[j] != a[i + j])//字串 和 主串 对比 
				{
					break;
				}
			}
			//说明 字串 已经遍历 到尾了，配对成功 
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
	int len_b = strlen(b);//获取 子串 长度 
	int flag = 0;
	
	int len_a = strlen(a);//获取 主串 长度 
	char c[len_a] = {0};//用来 保存 主串 的值 
	
	strcpy(c,a);//把a值 赋值在c中，给 c 便于修改 
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
		//当然 覆盖 后 的数组 也必须 保证 没有 子串 
		for(i = flag;i < len_a - len_b;i ++)//往前 覆盖（代替删除）如：abcdfg -> dfgdfg
		{
			c[i] = c[i + len_b];//i + len_b + 1 = len_a -> i < len_a -lenb
		}
		
		for(int j = i;c[j] != '\0';j ++)//向前移动成功,然后再把末尾清空个数 为子串长度 的元素：dfgdfg -> dfg'\0''\0''\0'
		{
			c[j] = '\0';
		}
		
		
	}

	//打印 结果字符数组
	prin_array(c);
	
	return;
}


int main()
{
	//测试 主串 和 字串 
	char *a = "caabcbcfabccabcccxdsa";//主串 
	char *b = "abc";//等价于 b[3] = {'a','b','c'},但前者 不能修改其中某个元素,只能整体修改,查看，后者方便修改 
	
	delete_Son(a,b);
	
	return 0;
}
