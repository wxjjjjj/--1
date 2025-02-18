/* 2353761 ��𪾧 �ƿ� */
#include <iostream>
#include <iomanip>
using namespace std;

//char-65����A��=0����B��=1����C��=2

int yuanpanshu[3];     //�洢Բ����������--[0]a��[1]--b��[2]--c
int panhao[3][10];     //[0][0]-[0][9]��a�ģ�[1]b;[2]c
int bushu = 1;         //�����õ�

void print(int n, char src, char dst, int yuanpanshu[3], int panhao[3][10]) {
	int i, j, k,m;
	i = yuanpanshu[int(src)-65];
	j= yuanpanshu[int(dst) - 65];
	panhao[int(src)-65][i - 1] = 0;
	--yuanpanshu[int(src) - 65];
	panhao[int(dst) - 65][j] = n;
	++yuanpanshu[int(dst) - 65];
	for (k = 0; k < 3; ++k) {
		cout << char(k + 65)<<':';
		for (m = 0; m < 10; ++m) {
			if (panhao[k][m] > 0) {
				cout <<setw(2)<<panhao[k][m];
			}
			else {
				cout <<setw(2)<<' ';
			}
		}
		cout << ' ';
	}
	cout << endl;
	return;
}

void hanoi(int n, char src, char tmp, char dst)  //n���̺�(Ҳ�ǲ���) ���ϵ���Ϊ1��2��3...
{
	if (n == 1) {
		cout <<"��"<<setw(4)<<bushu<<" ��(" <<setw(2)<< n <<"): "<< src << '-' << '-' << '>' << dst<<' ';
		print(n, src, dst, yuanpanshu, panhao);
		++bushu;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	cout << "��" << setw(4) << bushu << " ��(" << setw(2) << n << "): " << src << '-' << '-' << '>' << dst << ' ';
	print(n, src, dst, yuanpanshu, panhao);
	++bushu;
	hanoi(n - 1, tmp, src, dst);
	return;
}

void chushihua(char src,int yuanpanshu[3],int panhao[3][10], int n) {
	if (src == 'A') {
		yuanpanshu[0] = n;
		for (int i = 0; i < n; ++i) {
			panhao[0][i] = n - i;
		}
	}
	else if (src == 'B') {
		yuanpanshu[1] = n;
		for (int i = 0; i < n; ++i) {
			panhao[1][i] = n - i;
		}
	}
	else {
		yuanpanshu[2] = n;
		for (int i = 0; i < n; ++i) {
			panhao[2][i] = n - i;
		}
	}
}

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
			if (layers >= 1 && layers <= 10) {
				while (1) {
					cout << "��������ʼ��(A-C)" << endl;
					cin >> src;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
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
	}
	if ((src == 'A' || src == 'B') && (dst == 'A' || dst == 'B')) {
		tmp = 'C';
	}
	else if ((src == 'A' || src == 'C') && (dst == 'A' || dst == 'C')) {
		tmp = 'B';
	}
	else {
		tmp = 'A';
	}             //��src��dst��tmpȫ����Ϊ��д

	chushihua(src, yuanpanshu, panhao, layers);

	cout << "��ʼ:" << "                ";
	for (int k = 0; k < 3; ++k) {
		cout << char(k + 65) << ':';
		for (int m = 0; m < 10; ++m) {
			if (panhao[k][m] > 0) {
				cout << setw(2) << panhao[k][m];
			}
			else {
				cout << setw(2) << ' ';
			}
		}
		cout << ' ';
	}
	cout << endl;

	hanoi(layers,src,tmp,dst);
		
	return 0;


}