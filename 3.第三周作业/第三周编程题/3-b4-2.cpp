#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;


int main()
{
	int a, b, c;
	double d;
	float s;
	const double pi = 3.14159;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a>> b>>c;
	d = c * pi/180;
	s = a * b * float(sin(d)) / 2;
	cout << std::fixed << std::setprecision(3) << "���������Ϊ : " << s<< endl;
	return 0;

}
