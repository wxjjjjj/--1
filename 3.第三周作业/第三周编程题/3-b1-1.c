#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
	const double pi = 3.14159;
	double r, h, c, s, S, v, V;
	printf("������뾶�͸߶�\n");
	scanf("%lf %lf", &r, &h);
	c = 2 * pi * r;
	s = pi * r * r;
	S = 4 * pi * r * r;
	v = 4 * pi * r * r * r / 3;
	V = pi * r * r * h;

	printf("Բ�ܳ�     : %.2lf\n", c);
	printf("Բ���     : %.2lf\n", s);
	printf("Բ������ : %.2lf\n", S);
	printf("Բ�����   : %.2lf\n", v);
	printf("Բ�����   : %.2lf\n", V);


	return 0;

}



















































