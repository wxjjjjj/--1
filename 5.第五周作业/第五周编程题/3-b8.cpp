#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main() {
	cout << "������x��ֵ[-10 ~ +65]" << endl;
	int x;
	cin >> x;
	while (cin.good() == 1 && (x > 65 || x < -10)) {
		cout << "����Ƿ�������������" << endl;
		cout << "������x��ֵ[-10 ~ +65]" << endl;
		cin >> x;
	}
	double sum = 0;
	int i;
	double c,a,b;
	c = 1;
	a = 1;
	b = 1;
	for (i = 1; fabs(c) >= 1e-6; ++i) {
		sum = sum + c;			//e^x  ���ж��ټӣ�����ȷ���ӵ����һ����Ĵ��ڵ���1e-6 
		a = x * a/10;				//x^n
		b = b * i/10;				//n!
		c = a / b;				//x^n/n!

	}
	cout<<"e^"<<x<<"="<< setprecision(10) << sum << endl;

	return 0;
}
