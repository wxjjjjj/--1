/*��𪾧 2353761 �ƿ�*/
#include<iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int max(int a, int b, int c) {
	int x = a > b ? a : b;
	return x > c ? x : c;
}

int max(int a, int b, int c, int d) {
	int x = a > b ? a : b;
	int y = x > c ? x : c;
	return y > d ? y : d;
}

int main() {
	
	int n, a, b, c, d,x;
	while (1) {
		cout << "���������num��num����������" << endl;
		cin >> n;/*�������鷳�� ��case��ѡ��
		switch��num��
		case 1��
		cin��a��
		case 2��
		cin��a��b��
		������*/
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else {
			if (n >= 2 && n <= 4) {
				if (n == 2) {
					cin >> a >> b;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n');
					}
					else {
						if (a > 0 && b > 0) {
							x=max(a, b);
							cout << "max=" << x << endl;
							break;
						}
					}
				}
				else if (n == 3) {
					cin >> a >> b >> c;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n');
					}
					else {
						if (a > 0 && b > 0&&c>0) {
							x=max(a, b,c);
							cout << "max=" << x << endl;
							break;
						}
					}
				}
				else {
					cin >> a >> b >> c >> d;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n');
					}
					else {
						if (a > 0 && b > 0 && c > 0&&d>0) {
							x=max(a, b, c,d);
							cout << "max=" << x << endl;
							break;
						}
					}
				}
			}
			else {
				cout << "�����������" << endl;
				break;
			}
		}
	}
	
	return 0;
}
