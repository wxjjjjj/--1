#include<iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "������һ��[1-100��)֮�������:" << endl;
	double a,d,x;
	int e,f,g,h,i,j,k,l,m,n,p,q;
	cin >> a;
	a = a + 0.005;                              //�ֲ�ʵ�����������λС����Ҫ��С-0.0005���Դ�����
	long c;                                     //��Ϊlong long��dev�б��벻ͨ����������long��
	x= a/100;								    //��������������ݱ�ò���������11��9λ����������� ����ʱ��λС������λС����
	c = long(x);									//�����������������ִ���c��
	d = x - c;								    //��С�����ִ���d��

	g = c % 10;									//��λ����
	c = c / 10;
	h= c % 10;									//ǧλ����
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

	p = int(d * 10);                            //ʮλ����
	q = int((d - p * 0.1) / 0.01);              //Բλ����
	e = int((d-0.1*p-0.01*q)/0.001);									//��λ����
	f = int((d-0.1*p-0.01*q-0.001*e)/0.0001);									//��λ����

	cout << "ʮ��λ : " << n << endl;
	cout << "��λ   : " << m << endl;
	cout << "ǧ��λ : " << l << endl;
	cout << "����λ : " << k << endl;
	cout << "ʮ��λ : " << j << endl;
	cout << "��λ   : " << i << endl;
	cout << "ǧλ   : " << h << endl;
	cout << "��λ   : " << g << endl;
	cout << "ʮλ   : " << p << endl;
	cout << "Բ     : " << q << endl;
	cout << "��     : " << e<< endl;
	cout << "��     : " << f<< endl;



	return 0;
}
