#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	printf("����������ֵ��\n");
	double a, d;
	int p, q;
	scanf("%lf", &a);
	a = a + 0.005;                              //�ֲ�ʵ�����������λС����Ҫ��С-0.0005���Դ�����
	int c;
	c = (int)a;									//�����������������ִ���c��
	d = a - c;								    //��С�����ִ���d��

	p = (int)(d * 10);                            //��λ����p
	q = (int)((d - p * 0.1) / 0.01);              //��λ����q

	int b, e, f, g, h, i, j, k;
	b = c / 50;                 //bΪ50���������
	e = c % 50;             //cΪ��50��ʣ�µ�Ǯ
	f = e / 20;				//fΪ20���������
	g = e % 20;
	h = g / 10;				//hΪ10���������
	i = g % 10;
	j = i / 5;				//jΪ5���������
	k = i % 5;              //k������5ʣ�µ�Ǯ��Ҳ����1Ԫ������

	int l, m, n, r, s, t;
	l = p / 5;
	m = p % 5;				//m������5ʣ�µ�Ǯ��Ҳ����1������

	n = q / 5;
	r = q % 5;
	s = r / 2;
	t = r % 2;				//t������2ʣ�µ�Ǯ��Ҳ����1������

	int sum;
	sum = b + f + h + j + k + l + m + n + s + t;

	printf("��%d�����㣬�������£�\n",sum);
	if (b != 0) {
		printf("50Ԫ : %d��\n", b);
	}
	if (f != 0) {
		printf("20Ԫ : %d��\n", f);
	}
	if (h != 0) {
		printf("10Ԫ : %d��\n", h);
	}
	if (j != 0) {
		printf("5Ԫ  : %d��\n", j);
	}
	if (k != 0) {
		printf("1Ԫ  : %d��\n", k);
	}
	if (l != 0) {
		printf("5��  : %d��\n", l);
	} 
	if (m != 0) {
		printf("1��  : %d��\n", m);
	}
	if (n != 0) {
		printf("5��  : %d��\n", n);
	}
	if (s != 0) {
		printf("2��  : %d��\n", s);
	}
	if (t != 0) {
		printf("1��  : %d��\n", t);
	}
	return 0;
}