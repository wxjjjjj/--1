#include<iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "����������ֵ��" << endl;
	double a,d;
	int p,q;
	cin >> a;
	a = a + 0.005;                              //�ֲ�ʵ�����������λС����Ҫ��С-0.0005���Դ�����
	int c;                                     
	c = int(a);									//�����������������ִ���c��
	d = a - c;								    //��С�����ִ���d��

	p = int(d * 10);                            //��λ����p
	q = int((d - p * 0.1) / 0.01);              //��λ����q

	int b, e, f, g, h, i, j, k;
	b=c/50;                 //bΪ50���������
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

	cout << "��" << sum << "�����㣬�������£�" << endl;
	if(b!=0){
		cout << "50Ԫ : " << b <<"��" << endl;
	}
	if (f != 0) {
		cout << "20Ԫ : " << f << "��" << endl;
	}
	if (h != 0) {
		cout << "10Ԫ : " << h << "��" << endl;
	}
	if (j != 0) {
		cout << "5Ԫ  : " << j << "��" << endl;
	}
	if (k != 0) {
		cout << "1Ԫ  : " << k << "��" << endl;
	}
	if (l != 0) {
		cout << "5��  : " << l << "��" << endl;
	}
	if (m != 0) {
		cout << "1��  : " << m << "��" << endl;
	}
	if (n != 0) {
		cout << "5��  : " << n << "��" << endl;
	}
	if (s != 0) {
		cout << "2��  : " << s << "��" << endl;
	}
	if (t != 0) {
		cout << "1��  : " << t << "��" << endl;
	}
	return 0;
}
