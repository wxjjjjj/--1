#include <iostream>
#include <limits> //dev�б���� vs�ɲ���
using namespace std;



int zeller(int y, int m, int d) //�Ѿ�������y��m��d�����ڲ����ٶ���
{
	int c,w,q;
	q = y;    //��ݴ���q�ڲ���
	c = y / 100;
	y = y - c * 100;
	if (m == 1) {
		q = q - 1;
		c = q / 100;
		y = q - c * 100;
		m = 13;
	}
	else if (m == 2) {
		q = q - 1;
		c = q / 100;
		y = q - c * 100;
		m = 14;
	}
	else {
		m = m;
	}
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w = w + 7;
	}
	w = w % 7;
	return w;
}

int main()
{
	int a, b, c,l;//a���꣬b����,c������

	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> a >> b>>c;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е��ַ���ֱ�����з�!!��<windows.h>��ͷ�ļ��Ͳ�����
			cout << "�����������������" << endl;
		}
		else {
			if (a<1900||a>2100) {
				cout << "��ݲ���ȷ������������" << endl;
			}
			else {
				if (b > 12 || b < 1) {
					cout << "�·ݲ���ȷ������������" << endl;
				}
				else {  //���յ���ȷ��
					if (b == 2) {
						if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {  //�������
							if (c >= 0 && c <= 29) {
								break;
							}
							else {
								cout << "�ղ���ȷ������������" << endl;
							}
						}
						else {
							if (c >= 0 && c <= 28) {
								break;
							}
							else {
								cout << "�ղ���ȷ������������" << endl;
							}
						}
					}
					else if (b==1||b==3||b==5||b==7||b==8||b==10||b==12) {
						if (c >= 0 && c <= 31) {
							break;
						}
						else {
							cout << "�ղ���ȷ������������" << endl;
						}

					}
					else {
						if (c >= 0 && c <= 30) {
							break;
						}
						else {
							cout << "�ղ���ȷ������������" << endl;
						}
					}
				}
			}
		}
	}
	l = zeller(a, b, c);
	switch (l) {
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
		case 0:
			cout << "������" << endl;
			break;
		default:
			break;
	}
	return 0;
}
