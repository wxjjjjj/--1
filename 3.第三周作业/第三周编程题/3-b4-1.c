#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>


int main()
{
	int a, b, c;
	double d;
	float s;
	const double pi = 3.14159;
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	scanf("%d %d %d", &a, &b, &c);
	d = c * pi/180;
	s = a * b * (float)sin(d) / 2;
	printf("���������Ϊ : %.3f\n", s);
	return 0;

}