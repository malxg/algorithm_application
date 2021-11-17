#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//预处理指令
int main(void)
{
        double bNumber, Number, Result;                //给加减乘除定义的变量
        int No;                //选项的定义变量
        double a, b, c, x1, x2, Rad;                //给一元一次方程定义的变量
        int Ary_10;                                        //定义进制的变量
        char string[32];                //二进制变量定义
 
        system ("title 简单计算器 —— By:HaGit");                //程序窗口上的标题
 
        while(1)
        {
                //界面
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");
                printf ("┇请选择你要计算的方法:                         ┇\n");
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
                printf ("┇  加法请按_1    进制转换_5                    ┇\n");
                printf ("┇  减法请按_2    求一元二次方程_6              ┇\n");
                printf ("┇  乘法请按_3                                  ┇\n");
                printf ("┇  除法请按_4               退出_0             ┇\n");
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");
                printf ("Please write down the number:");
                scanf ("%d",&No);
 
                if (No == 1)
                {
                        //        加法
                        printf ("        请输入被加数:");
                        scanf ("%lf",&bNumber);
                        printf ("        请输入加数:");
                        scanf ("%lf",&Number);
                        Result = bNumber + Number;
                        printf (" 结果是: %lf\n\n",Result);
                }
                else if (No == 2)
                {
                        //        减法
                        printf ("        请输入被减数:");
                        scanf ("%lf",&bNumber);
                        printf ("        请输入减数:");
                        scanf ("%lf",&Number);
                        Result = bNumber - Number;
                        printf (" 结果是: %lf\n\n",Result);
                }
                else if (No == 3)
                {
                        //        乘法
                        printf ("        请输入被乘数:");
                        scanf ("%lf",&bNumber);
                        printf ("        请输入乘数:");
                        scanf ("%lf",&Number);
                        Result = bNumber * Number;
                        printf (" 结果是: %lf\n\n",Result);
                }
                else if (No == 4)
                {
                        //        除法
                        printf ("        请输入被除数:");
                        scanf ("%lf",&bNumber);
                        printf ("        请输入除数:");
                        scanf ("%lf",&Number);
                        Result = bNumber / Number;
                        printf (" 结果是: %lf\n\n",Result);
                }
                else if (No == 5)
                {
                        //进制转换的代码
                        printf("请输入需要转换的十进制数:");
                        scanf("%d", &Ary_10);
                        itoa (Ary_10, string ,2);
                        printf("二进制: %s\n", &string);
                        printf("八进制: %o\n", &Ary_10);
                        printf("十六进制: %x\n", &Ary_10);
                }
                else if (No == 6)
                {
                        //求一元二次方程的解的代码
                        printf("请输入一元一次方程的a,b,c三个数:");
                        scanf("%lf%lf%lf",&a,&b,&c);
                        Rad = b*b - 4*a*c;
                        if (Rad > 0)
                        {
                                x1 = -b + sqrt(Rad) / (2*a);
                                x2 = -b - sqrt(Rad) / (2*a);
                                printf("有两个解 x1 = %lf, x2 = %lf\n", &x1, &x2);
                        }
                        else if (Rad == 0)
                        {
                                x1 = -b / (2*a);
                                printf("只有一个解 x1 = %lf\n", &x1);
                        }
                        else
                        {
                                printf("无解\n");
                        }
                }
                else if (No == 0)
                {
                        //        退出程序
                        break;
                }
                else
                {
                        //        输入的选项不对
                        printf("  请输入正确的数字。\n\n");
                }
                system ("pause");        //按任意键继续
                system ("cls");                //清屏
        }
        return 0;
        getchar();
}
