#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>


int main()
{
	int a, b, c, d, e, f;
	printf("������һ��[1..30000]������:\n");
	scanf("%d", &a);
	b = a % 10;                     //��λ����
	a = a / 10;
	c = a % 10;					    //ʮλ����
	a = a / 10;
	d = a % 10;						//��λ����
	a = a / 10;
	e = a % 10;						//ǧλ����
	a = a / 10;
	f = a % 10;						//��λ����

	printf("��λ : %d\n", f);
	printf("ǧλ : %d\n", e);
	printf("��λ : %d\n", d);
	printf("ʮλ : %d\n", c);
	printf("��λ : %d\n", b);
	
	return 0;
}
