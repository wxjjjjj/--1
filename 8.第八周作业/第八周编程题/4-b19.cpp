/*��𪾧 2353761 �ƿ�*/
#include<iostream>
using namespace std;

int min(int a, int b,int c=2147483647,int d=2147483647) {//���õ�д����INT_MAXҪ��#include<limitis.h>ͷ�ļ��궨��or��ʮ�����Ʊ�ʾ0x7FFFFFFF��Ȼ��ʮ���ƣ�Ĭ�������ʾ��������� 
	int x = a < b ? a : b;
	int y = x < c ? x : c;
	return y < d ? y : d;
}



int main() {

	int n, a, b, c, d, x;
	while (1) {
		cout << "���������num��num����������" << endl;
		cin >> n;
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
							x = min(a, b);
							cout << "min=" << x << endl;
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
						if (a > 0 && b > 0 && c > 0) {
							x = min(a, b, c);
							cout << "min=" << x << endl;
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
						if (a > 0 && b > 0 && c > 0 && d > 0) {
							x = min(a, b, c, d);
							cout << "min=" << x << endl;
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
