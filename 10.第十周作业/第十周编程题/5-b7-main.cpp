/*��𪾧 2353761 �ƿ�*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include"5-b7.h"

using namespace std;
int bushu = 1;
int a[10], b[10], c[10];  //�洢�̺�
int d, e, f;            //�洢a��b��c��������
static int sudushijian;//�ƶ���ʱ��ʱ��

void sudushijianshezhi(int sudu,int xianshi)
{  //��ʱ����sudu����ʾ�ڲ�����xianshi;sudushijianshezhi(�ٶ�ʱ�����ã�
	if (sudu == 1) {
		sudushijian = 1000;
	}
	else if (sudu == 2) {
		sudushijian = 500;
	}
	else if (sudu == 3) {
		sudushijian = 200;
	}
	else if (sudu == 4) {
		sudushijian = 50;
	}
	else {
		sudushijian = 0;
	}
	return;
}

void chushihua(char src, int n)
{
	if (src == 'A') {
		d = n;
		for (int i = 0; i < n; ++i) {
			a[i] = n - i;
		}
	}
	else if (src == 'B') {
		e = n;
		for (int i = 0; i < n; ++i) {
			b[i] = n - i;
		}
	}
	else {
		f = n;
		for (int i = 0; i < n; ++i) {
			c[i] = n - i;
		}
	}
	return;
}

void print(int n, char src, char dst,int xianshi)
{
	int i, j, m;
	
	if (src == 'A') {
		i = d;
		a[i - 1] = 0;
		--d;
	}
	else if (src == 'B') {
		i = e;
		b[i - 1] = 0;
		--e;
	}
	else {
		i = f;
		c[i - 1] = 0;
		--f;
	}

	if (dst == 'A') {
		j = d;
		a[j] = n;
		++d;
	}
	else if (dst == 'B') {
		j = e;
		b[j] = n;
		++e;
	}
	else {
		j = f;
		c[j] = n;
		++f;
	}


	if (xianshi) {
		cout << "A:";
	for (m = 0; m < 10; ++m) {
		if (a[m] > 0) {
			cout << setw(2) << a[m];
		}
		else {
			cout << "  ";
		}
	}
	cout << " ";

	cout << "B:";
	for (m = 0; m < 10; ++m) {
		if (b[m] > 0) {
			cout << setw(2) << b[m];
		}
		else {
			cout << "  ";
		}
	}
	cout << " ";

	cout << "C:";
	for (m = 0; m < 10; ++m) {
		if (c[m] > 0) {
			cout << setw(2) << c[m];
		}
		else {
			cout << "  ";
		}
	}
	cout << " ";

	cout << endl;
	}
	
	int x = 11, y = 26;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (a[m] > 0) {
			cout << a[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	x = x + 10;
	y = 26;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (b[m] > 0) {
			cout << b[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	x = x + 10;
	y = 26;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (c[m] > 0) {
			cout << c[m];
			--y;
		}
		else {
			cout << " ";
		}
	}

	return;
}


void hanoi(int n, char src, char tmp, char dst,int xianshi)  //n���̺�(Ҳ�ǲ���) ���ϵ���Ϊ1��2��3...
{
	if (n == 1) {
		cct_gotoxy(20, 32);
		cout << "��" << setw(4) << bushu << "��(" <<  n << "#: " << src << "-->" << dst<<") ";
		
		print(n, src, dst, xianshi);
		if(sudushijian)
			Sleep(sudushijian);
		else {
			int huiche;
			while(1){
				huiche = _getch();
				if (huiche == 13) {
					break;
				}
			}
		}
		++bushu;
		return;
	}
	hanoi(n - 1, src, dst, tmp,xianshi);
	cct_gotoxy(20, 32);
	cout << "��" << setw(4) << bushu << "��(" << n << "#: " << src << "-->" << dst << ") ";
	
	print(n, src, dst, xianshi);
	if (sudushijian)
		Sleep(sudushijian);
	else {
		int huiche;
		while (1) {
			huiche = _getch();
			if (huiche == 13) {
				break;
			}
		}
	}
	++bushu;
	hanoi(n - 1, tmp, src, dst,xianshi);
	return;

}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	int layers;
	char src, dst, tmp;//layers�ǲ㣬src����ʼ��,dst��Ŀ����,tmp�Ǹ�����

	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
		cin >> layers;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
		}
		else {
			cin.ignore(65536, '\n');//������ȷҲҪ���Ժ�����ַ�
			if (layers >= 1 && layers <= 16) {
				while (1) {
					cout << "��������ʼ��(A-C)" << endl;
					cin >> src;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�//�Ӹ�continue������������ٳ����� ����65536����ɺ���� 
					}
					else {
						cin.ignore(65536, '\n');//������ȷҲҪ���Ժ�����ַ�
						if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) {
							while (1) {
								cout << "������Ŀ����(A-C)" << endl;
								cin >> dst;
								if (cin.good() == 0) {
									cin.clear();
									cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
								}
								else {
									cin.ignore(65536, '\n');
									if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c')) {
										if (src == dst || src == dst + 32 || src == dst - 32) {
											if (src >= 'a' && src <= 'c') {
												src = src - 32;
											}
											if (dst >= 'a' && dst <= 'c') {
												dst = dst - 32;
											}
											cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
										}
										else {
											break;
										}
									}

								}
							}
							break;
						}
					}
				}
				break;
			}
		}
	}                //���벿�ִ������

	if (src >= 'a' && src <= 'c') {
		src = src - 32;
	}
	if (dst >= 'a' && dst <= 'c') {
		dst = dst - 32;
	}//src,dstת��д

	tmp = 'A' + 'B' + 'C' - src - dst;  //����

	int sudu,xianshi;//��ʾ
	
	while (1) {
		cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
		cin >> sudu;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
		}
		else {
			if (sudu >= 0 && sudu <= 5)
				break;
		}
	}
	while (1) {
		cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
		cin >> xianshi;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
		}
		else {
			if (xianshi==0 || xianshi == 1)
				break;
		}
	}
	
	cct_cls();//����
	cout << "�� " << src << " �ƶ��� " << dst << " ,�� " << layers << " �㣬��ʱ����Ϊ " << sudu << ", ";
	if (xianshi == 0) {
		cout << "����ʾ�ڲ�����ֵ" << endl;
	}
	else {
		cout<< "��ʾ�ڲ�����ֵ" << endl;
	}
	
	chushihua(src, layers);
	sudushijianshezhi(sudu, xianshi);
	if (xianshi) {
		cct_gotoxy(20, 32);
		cout << "��ʼ:                ";

		cout << "A:";
		for (int m = 0; m < 10; ++m) {
			if (a[m] > 0) {
				cout << setw(2) << a[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "B:";
		for (int m = 0; m < 10; ++m) {
			if (b[m] > 0) {
				cout << setw(2) << b[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "C:";
		for (int m = 0; m < 10; ++m) {
			if (c[m] > 0) {
				cout << setw(2) << c[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << endl;
		if (sudushijian)
			Sleep(sudushijian);
		else {
			int huiche;
			while (1) {
				huiche = _getch();
				if (huiche == 13) {
					break;
				}
			}
		}
	}
	cct_gotoxy(9, 27);
	cout << "=========================" << endl;
	cct_gotoxy(9, 28);
	cout << "  A         B         C" << endl;
	int x = 11, y = 26;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (a[m] > 0) {
			cout << a[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	x = x + 10;
	y = 26;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (b[m] > 0) {
			cout << b[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	x = x + 10;
	y = 26;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (c[m] > 0) {
			cout << c[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	if (sudushijian)
		Sleep(sudushijian);
	else {
		int huiche;
		while (1) {
			huiche = _getch();
			if (huiche == 13) {
				break;
			}
		}
	}
	hanoi(layers, src, tmp, dst,xianshi);
	

	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}
