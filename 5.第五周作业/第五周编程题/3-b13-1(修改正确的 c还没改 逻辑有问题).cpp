#include <iostream>
#include <limits>//dev�б���� vs�ɲ���
#include<iomanip>
using namespace std;

int main()
{
	int a, b, c;//a���꣬b����,c������

	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> a >> b;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е��ַ���ֱ�����з�!!��<windows.h>��ͷ�ļ��Ͳ�����
			cout << "����Ƿ�������������" << endl;
		}
		else {
			if ((a >= 2000 && a <= 2030 && b >= 1 && b <= 12) == 0) {
				cout << "����Ƿ�������������" << endl;
			}
			else {
				while (1) {
					cout << "������" << a << "��" << b << "��1�յ�����(0-6��ʾ������-������) : ";
					cin >> c;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������뻺�����е��ַ���ֱ�����з�
						cout << "����Ƿ�������������" << endl;
					}
					else {
						if ((c >= 0 && c <= 6) == 0) {
							cout << "����Ƿ�������������" << endl;
						}
						else {
							break;
						}
					}
				}
				break;
			}
		}
	}
	

	cout << endl;
	cout << a << "��" << b << "�µ�����Ϊ:" << endl;
	cout << "������  " << "����һ  " << "���ڶ�  " << "������  " << "������  " << "������  " << "������  " << endl;
	int d = 1;
	switch (c) {
		case 0:
			cout << setw(4) << d;
			for (d = 2; d <= 31; d++) {
				cout << setw(8) << d;
				
				if (d % 7 == 0) {
					cout << endl;
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
				    	if (b == 2 && d == 29) {//2��
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//��������
					    if (b == 2 && d == 28) {//2��
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
					if (b == 2 && d == 29) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//��������
					if (b == 2 && d == 28) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
				    	if (b == 2 && d == 29) {//2��
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//��������
					    if (b == 2 && d == 28) {//2��
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
					if (b == 2 && d == 29) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//��������
					if (b == 2 && d == 28) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
				    	if (b == 2 && d == 29) {//2��
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//��������
					    if (b == 2 && d == 28) {//2��
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
					if (b == 2 && d == 29) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//��������
					if (b == 2 && d == 28) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
				    	if (b == 2 && d == 29) {//2��
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//��������
					    if (b == 2 && d == 28) {//2��
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
					if (b == 2 && d == 29) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//��������
					if (b == 2 && d == 28) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
				    	if (b == 2 && d == 29) {//2��
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//��������
					    if (b == 2 && d == 28) {//2��
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
					if (b == 2 && d == 29) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//��������
					if (b == 2 && d == 28) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
				    	if (b == 2 && d == 29) {//2��
					    	break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
				    else {//��������
					    if (b == 2 && d == 28) {//2��
						    break;
					    }
					    else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						    break;
					    }
					    else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						    break;
					    }
				    }
					d++;
					cout << setw(4) << d;
				}
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
					if (b == 2 && d == 29) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//��������
					if (b == 2 && d == 28) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
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
					cout<<endl;
				    if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
				    	if (b == 2 && d == 29) {//2��
					    	break;
				    	}
				    	else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
				    		break;
				    	}
				     	else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
					    	break;
				    	}
				    }
			    	else {//��������
				    	if (b == 2 && d == 28) {//2��
				    		break;
				    	}
				    	else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
					    	break;
				    	}
				    	else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
					    	break;
					    }
			    	}
				    d++;
					cout << setw(4) << d;	
				}
				
				if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {//����
					if (b == 2 && d == 29) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				else {//��������
					if (b == 2 && d == 28) {//2��
						break;
					}
					else if ((b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) && d == 31) {
						break;
					}
					else if ((b == 4 || b == 6 || b == 9 || b == 11) && d == 30) {
						break;
					}
				}
				
			}
			break;

	}
	cout << endl;
	return 0;
}

