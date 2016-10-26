#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int main()
{
	double income;//收入;
	printf("请输入工资(5000-8000元):\n");
	scanf("%lf", &income);
	printf("%lf\n", income);
	income -= (income - 3500) / 10 - 105;
	printf("本月实际收入为:%lf元", income);
	return 0;
}