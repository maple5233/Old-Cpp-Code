#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
int main()
{
	double income;//����;
	printf("�����빤��(5000-8000Ԫ):\n");
	scanf("%lf", &income);
	printf("%lf\n", income);
	income -= (income - 3500) / 10 - 105;
	printf("����ʵ������Ϊ:%lfԪ", income);
	return 0;
}