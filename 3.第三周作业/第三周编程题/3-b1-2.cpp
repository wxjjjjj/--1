#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	const double pi = 3.14159;
	double r, h,c,s,S,v,V;
	cout << "������뾶�͸߶�" << endl;
	cin >> r >> h;
	c = 2 * pi * r;
	s = pi * r * r;
	S = 4 * pi * r * r;
	v = 4 * pi * r * r * r / 3;
	V = pi * r * r * h;
	
	cout << std::fixed << std::setprecision(2) << "Բ�ܳ�     : " << c << endl;
	cout << std::fixed << std::setprecision(2) << "Բ���     : " << s << endl;
	cout << std::fixed << std::setprecision(2) << "Բ������ : " << S << endl;
	cout << std::fixed << std::setprecision(2) << "Բ�����   : " << v << endl;
	cout << std::fixed << std::setprecision(2) << "Բ�����   : " << V << endl;

	return 0;

}
