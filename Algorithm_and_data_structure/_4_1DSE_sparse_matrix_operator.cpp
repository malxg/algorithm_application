/*
稀疏矩阵运算器，以“带行逻辑链接信息”的三元组
顺序表表示稀疏矩阵，

~实现两个矩阵相加，相减或者相乘的运算。

~稀疏矩阵的输入形式  采用三元组表示，运算结果矩阵 以通常阵列形式列出 
*/
#include <stdio.h>
#include <string.h>//包含 memset() 置 数函数 (这里 初始化二维数组(也可以直接赋值0来代替))
int main()
{
	int rows = 0,columns = 0;
	printf("最大的矩阵 行数 和 列数"); 
	scanf("%d%d",&rows,&columns);//输入矩阵 行，列大小 和 值的个数
	int a[rows][columns],b[rows][columns];
	int c[rows][columns] = {0};//存储 乘的结果
	int d[rows][columns] = {0};//存储 乘的结果
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));memset(d,0,sizeof(d));
	/*memset支持 以下 
	memset(a, 0, sizeof(arr3); 正常，arr3中的每个元素都为0 	
	memset(a, -1, sizeof(arr3);  正常，arr3中的每个元素都为-1 
	*/
	printf("三元组1 ：\n");
	/*test_
			[0,0,0,
			1,0,1,
			0,1,1]
	*/
	printf("行,列,值\n");
	int  x = 0, y = 0,v = 0;
	while(1)
	{
		scanf("%d",&x);//范围 1~rows 
		if(x == 0)
		{
			break;
		}
		scanf("%d%d",&y,&v);//y范围 1~columns
		
		a[x - 1][y - 1] = v;//修改 对应 位置的值 
	}
	
	printf("\n");
	
	printf("三元组2 ：\n");
	/*test_
			[0,0,0,9
			5,0,0,7,
			0,6,0,0]
	*/
	printf("行,列,值\n");
	int  x1 = 0, y1 = 0,v1 = 0;
	while(1)
	{
		scanf("%d",&x1);//范围 1~rows 
		if(x1 == 0)
		{
			break;
		}
		scanf("%d%d",&y1,&v1);//y范围 1~columns
		
		b[x1 - 1][y1 - 1] = v1;//修改 对应 位置的值 
	}
	printf("\n");
	
	//矩阵 相加 
	for(int i = 0;i < rows;i ++)
	{
		for(int j = 0;j < columns;j ++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	
	//矩阵 相乘 
	for(int i = 0;i < rows;i ++)
	{
		for(int j = 0;j < columns;j ++)
		{
			d[i][j] = a[i][j] * b[i][j];
		}
	}
	
	/////////////////////////////////////////
	printf("加的结果:\n");
	//输出运算结果 
	for(int i = 0;i < rows;i ++)
	{
		for(int j = 0;j < columns;j ++)
		{
			printf("%d\t",c[i][j]);
		}
		
		printf("\n");
	}
	
	//////////////////////////////////////////
	printf("\n乘的结果:\n");
	//输出运算结果 
	for(int i = 0;i < rows;i ++)
	{
		for(int j = 0;j < columns;j ++)
		{
			printf("%d\t",d[i][j]);
		}
		
		printf("\n");
	} 
	
	return 0;
}
