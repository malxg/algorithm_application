#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//Ԥ����ָ��
int main(void)
{
        double bNumber, Number, Result;                //���Ӽ��˳�����ı���
        int No;                //ѡ��Ķ������
        double a, b, c, x1, x2, Rad;                //��һԪһ�η��̶���ı���
        int Ary_10;                                        //������Ƶı���
        char string[32];                //�����Ʊ�������
 
        system ("title �򵥼����� ���� By:HaGit");                //���򴰿��ϵı���
 
        while(1)
        {
                //����
                printf ("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
                printf ("����ѡ����Ҫ����ķ���:                         ��\n");
                printf ("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
                printf ("��  �ӷ��밴_1    ����ת��_5                    ��\n");
                printf ("��  �����밴_2    ��һԪ���η���_6              ��\n");
                printf ("��  �˷��밴_3                                  ��\n");
                printf ("��  �����밴_4               �˳�_0             ��\n");
                printf ("�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��\n");
                printf ("Please write down the number:");
                scanf ("%d",&No);
 
                if (No == 1)
                {
                        //        �ӷ�
                        printf ("        �����뱻����:");
                        scanf ("%lf",&bNumber);
                        printf ("        ���������:");
                        scanf ("%lf",&Number);
                        Result = bNumber + Number;
                        printf (" �����: %lf\n\n",Result);
                }
                else if (No == 2)
                {
                        //        ����
                        printf ("        �����뱻����:");
                        scanf ("%lf",&bNumber);
                        printf ("        ���������:");
                        scanf ("%lf",&Number);
                        Result = bNumber - Number;
                        printf (" �����: %lf\n\n",Result);
                }
                else if (No == 3)
                {
                        //        �˷�
                        printf ("        �����뱻����:");
                        scanf ("%lf",&bNumber);
                        printf ("        ���������:");
                        scanf ("%lf",&Number);
                        Result = bNumber * Number;
                        printf (" �����: %lf\n\n",Result);
                }
                else if (No == 4)
                {
                        //        ����
                        printf ("        �����뱻����:");
                        scanf ("%lf",&bNumber);
                        printf ("        ���������:");
                        scanf ("%lf",&Number);
                        Result = bNumber / Number;
                        printf (" �����: %lf\n\n",Result);
                }
                else if (No == 5)
                {
                        //����ת���Ĵ���
                        printf("��������Ҫת����ʮ������:");
                        scanf("%d", &Ary_10);
                        itoa (Ary_10, string ,2);
                        printf("������: %s\n", &string);
                        printf("�˽���: %o\n", &Ary_10);
                        printf("ʮ������: %x\n", &Ary_10);
                }
                else if (No == 6)
                {
                        //��һԪ���η��̵Ľ�Ĵ���
                        printf("������һԪһ�η��̵�a,b,c������:");
                        scanf("%lf%lf%lf",&a,&b,&c);
                        Rad = b*b - 4*a*c;
                        if (Rad > 0)
                        {
                                x1 = -b + sqrt(Rad) / (2*a);
                                x2 = -b - sqrt(Rad) / (2*a);
                                printf("�������� x1 = %lf, x2 = %lf\n", &x1, &x2);
                        }
                        else if (Rad == 0)
                        {
                                x1 = -b / (2*a);
                                printf("ֻ��һ���� x1 = %lf\n", &x1);
                        }
                        else
                        {
                                printf("�޽�\n");
                        }
                }
                else if (No == 0)
                {
                        //        �˳�����
                        break;
                }
                else
                {
                        //        �����ѡ���
                        printf("  ��������ȷ�����֡�\n\n");
                }
                system ("pause");        //�����������
                system ("cls");                //����
        }
        return 0;
        getchar();
}
