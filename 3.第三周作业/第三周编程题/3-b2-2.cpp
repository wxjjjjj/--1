#include<iostream>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cout << "������һ��[1..30000]������:" << endl;
	cin >> a;
	b = a % 10;                     //��λ����
	a = a / 10;
	c = a % 10;					    //ʮλ����
	a = a / 10;
	d = a % 10;						//��λ����
	a = a / 10;
	e = a % 10;						//ǧλ����
	a = a / 10;
	f = a % 10;						//��λ����
	cout << "��λ : " << f << endl;
	cout << "ǧλ : " << e << endl;
	cout << "��λ : " << d << endl;
	cout << "ʮλ : " << c << endl;
	cout << "��λ : " << b << endl;
	return 0;
}
