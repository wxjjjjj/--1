#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>


int main()
{
	printf("������һ��[1-100��)֮�������:\n");
	double a, d, x;
	int e, f, g, h, i, j, k, l, m, n, p, q;
	scanf("%lf", &a);
	a = a + 0.005;                              //�ֲ�ʵ�����������λС����Ҫ��С-0.0005���Դ�����
	long c;                                     //��Ϊlong long��dev�б��벻ͨ����������long��
	x = a / 100;								    //��������������ݱ�ò���������11��9λ����������� ����ʱ��λС������λС����
	c = (long)x;									//�����������������ִ���c��
	d = x - c;								    //��С�����ִ���d��

	g = c % 10;									//��λ����
	c = c / 10;
	h = c % 10;									//ǧλ����
	c = c / 10;
	i = c % 10;									//��λ����
	c = c / 10;
	j = c % 10;									//ʮ��λ����
	c = c / 10;
	k = c % 10;									//����λ����
	c = c / 10;
	l = c % 10;									//ǧ��λ����
	c = c / 10;
	m = c % 10;									//��λ����
	c = c / 10;
	n = c % 10;									//ʮ��λ����

	p = (int)(d * 10);                            //ʮλ����
	q = (int)((d - p * 0.1) / 0.01);			 //Բλ����
	e = (int)((d - 0.1 * p - 0.01 * q) / 0.001);	//��λ����
	f = (int)((d - 0.1 * p - 0.01 * q - 0.001 * e) / 0.0001);	//��λ����

	printf( "ʮ��λ : %d\n", n);
	printf("��λ   : %d\n", m);
	printf("ǧ��λ : %d\n", l);
	printf("����λ : %d\n", k);
	printf("ʮ��λ : %d\n", j);
	printf("��λ   : %d\n", i);
	printf("ǧλ   : %d\n", h);
	printf("��λ   : %d\n", g);
	printf("ʮλ   : %d\n", p);
	printf("Բ     : %d\n", q);
	printf("��     : %d\n", e);
	printf("��     : %d\n", f);

	return 0;
}