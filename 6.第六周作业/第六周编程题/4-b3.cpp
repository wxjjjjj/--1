#include <iostream>
#include <limits> //dev�б���� vs�ɲ��� ��Ϊcin.ignore(numeric_limits<streamsize>::max(), '\n');
#include<iomanip>
using namespace std;



int zeller(int y, int m, int d) //�Ѿ�������y��m��d�����ڲ����ٶ���
{
	int c, w, q;
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
	return w;    //wΪ���������ն�Ӧ������0��������
}

void calendar(int year, int month)
{

	cout << year << "��" << month << "��" << endl;
	/* ͷ���ָ��ߣ������� */
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

	/* ������Ӵ��� */
	int l;
	l = zeller(year, month, 1);  //a��b�µ�һ�������;

	int d = 1;
	
	switch (l) {
		case 0:
			cout << setw(4) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 0) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
						if (month == 2 && d == 29) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//��������
						if (month == 2 && d == 28) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}


				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
					if (month == 2 && d == 29) {//2��
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//��������
					if (month == 2 && d == 28) {//2��
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;
		
		case 1:
			cout << setw(12) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 6) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
						if (month == 2 && d == 29) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//��������
						if (month == 2 && d == 28) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}

				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
					if (month == 2 && d == 29) {//2��
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//��������
					if (month == 2 && d == 28) {//2��
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;
		
		case 2:
			cout << setw(20) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;


				if (d % 7 == 5) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
						if (month == 2 && d == 29) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//��������
						if (month == 2 && d == 28) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}


				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
					if (month == 2 && d == 29) {//2��
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//��������
					if (month == 2 && d == 28) {//2��
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;
		
		case 3:
			cout << setw(28) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 4) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
						if (month == 2 && d == 29) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//��������
						if (month == 2 && d == 28) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}

				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
					if (month == 2 && d == 29) {//2��
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//��������
					if (month == 2 && d == 28) {//2��
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
			break;
		case 4:
			cout << setw(36) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 3) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
						if (month == 2 && d == 29) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//��������
						if (month == 2 && d == 28) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}
				
			    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
					if (month == 2 && d == 29) {//2��
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//��������
					if (month == 2 && d == 28) {//2��
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;
		
		case 5:
			cout << setw(44) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;

				if (d % 7 == 2) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
						if (month == 2 && d == 29) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//��������
						if (month == 2 && d == 28) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}

				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
					if (month == 2 && d == 29) {//2��
					    cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//��������
					if (month == 2 && d == 28) {//2��
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}

			}
		break;
		
		case 6:
			cout << setw(52) << d << endl;
			for (d = 2; d <= 31; d++) { //ÿһ�μ�֮ǰ�������ж��Ƿ�������µ����һ�죡�������������� 

				if (d == 2) {
					cout << setw(4) << d;
					d++;
				}
				cout << setw(8) << d;

				if (d % 7 == 1) {
					cout << endl;
					if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
						if (month == 2 && d == 29) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					else {//��������
						if (month == 2 && d == 28) {//2��
							break;
						}
						else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
							break;
						}
						else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
							break;
						}
					}
					d++;
					cout << setw(4) << d;
				}

				if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����
					if (month == 2 && d == 29) {//2��
						cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
				else {//��������
					if (month == 2 && d == 28) {//2��
				    	cout<<endl;
						break;
					}
					else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d == 31) {
						cout<<endl;
						break;
					}
					else if ((month == 4 || month == 6 || month == 9 || month == 11) && d == 30) {
						cout<<endl;
						break;
					}
				}
			}
		break;

	}
	      //cout<<endl; �߼��е����⣬��Ϊ���е������ �������µ����һ��or��7����x (�Ѿ��ĺ� 
	cout << "======================================================" << endl;
}

int main()
{
	int a, b;//a���꣬b����

	while (1) {
		cout << "��������[1900-2100]����" << endl;
		cin >> a >> b;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е��ַ���ֱ�����з�!!��<windows.h>��ͷ�ļ��Ͳ�����--<limits>
			cout << "�����������������" << endl;
		}
		else {
			if (a < 1900 || a>2100) {
				cout << "��ݲ���ȷ������������" << endl;
			}
			else {
				if (b > 12 || b < 1) {
					cout << "�·ݲ���ȷ������������" << endl;
				}
				else {
					break;
				}

			}
		}
	}
	cout << endl;
	calendar(a, b);

	return 0;
}
