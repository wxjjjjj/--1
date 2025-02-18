/* 2353761 ��𪾧 �ƿ� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�����������hanoi�ж���һ����̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
  ���������int n������
            char src����ʼ��
            char tmp���м���
            char dst��Ŀ����
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
            2������������������κ���ʽ��ѭ��
            3��������һ����̬�ֲ�����
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int count = 0;
	if (n == 1) {
		++count;
		cout <<setw(5)<<count<<':'<< setw(3) << n << '#' << ' ' << src << '-' << '-' << '>' << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	++count;
	cout << setw(5) << count <<':'<< setw(3) << n << '#' << ' ' << src << '-' << '-' << '>' << dst << endl;
	hanoi(n - 1, tmp, src, dst);
	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
	int layers;
	char src, dst, tmp;//layers�ǲ㣬src����ʼ��,dst��Ŀ����,tmp�Ǹ�����

	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
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

	cout << "�ƶ�����Ϊ:" << endl;
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
	}
	hanoi(layers, src, tmp, dst);

	return 0;
}
