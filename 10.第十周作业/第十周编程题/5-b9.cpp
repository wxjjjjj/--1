/*��𪾧 2353761 �ƿ�*/
#include<iostream>

using namespace std;
#define num 9     //!!!!!�궨�����û�зֺţ�����const����
#define MAX 65536

void examine_xiaojiugongge(int array[9][9],int array2[9], int row,int column) 
{//column�У�row��
	int k;
	for (int i = row; i < row+3; ++i) {
		for (int j = column; j < column+3; ++j) {
			k = array[i][j];
			++array2[k - 1];
		}
	}//һ��С�Ź��������
	for (int l = 0; l < num; ++l) {
		if (array2[l] != 1) {
			cout << "���������Ľ�" << endl;
			return;
		}
	}//һ��С�Ź����ж���
	for (int d = 0; d < num; ++d) {
		array2[d] = 0;
	}//�����������
	return;
}

int main()
{
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	int a[num][num] = { 0 };
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			while (1){
				cin >> a[i][j];           //ע�⣡����cinϣ����ֵ���ǵ�������������cin>>a[i]һ�����Ǵ��
				if (cin.good() == 0) {
					cin.clear();
					cin.ignore(MAX, '\n');
					cout << "�����������" << i+1 << "��" << j+1 << "��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}
				else {
					if (a[i][j] >= 1 && a[i][j] <= 9) {
						break;
					}
					else {
						cout << "�����������" << i+1 << "��" << j+1 << "��(���о���1��ʼ����)��ֵ" << endl;
						continue;
					}
				}
			}
		}	
	}                  //���봦�����

	int k = 0, b[9] = { 0 };//b[j]��ֵ��������j+1���ֵĴ���
	//ÿһ�м��
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			k = a[i][j];
			++b[k - 1];
		} //һ��ͳ����
		for (int l = 0; l < num; ++l) {
			if (b[l] != 1) {
				cout << "���������Ľ�" << endl;
				return 0;
			}
		}//һ���ж���
		for (int d = 0; d < num; ++d) {
			b[d] = 0;
		}//����������㣬��һ��ͳ��
	}
	//ÿһ�м��
	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			k = a[j][i];
			++b[k - 1];
		} //һ��ͳ����
		for (int l = 0; l < num; ++l) {
			if (b[l] != 1) {
				cout << "���������Ľ�" << endl;
				return 0;
			}
		}//һ���ж���
		for (int d = 0; d < num; ++d) {
			b[d] = 0;
		}//����������㣬��һ��ͳ��
	}
	//ÿ��С�Ź�����
	examine_xiaojiugongge(a, b, 0, 0);//column�У�row��	
	examine_xiaojiugongge(a, b, 0, 3);
	examine_xiaojiugongge(a, b, 0, 6);
	examine_xiaojiugongge(a, b, 3, 0);
	examine_xiaojiugongge(a, b, 3, 3);
	examine_xiaojiugongge(a, b, 3, 6);
	examine_xiaojiugongge(a, b, 6, 0);
	examine_xiaojiugongge(a, b, 6, 3);
	examine_xiaojiugongge(a, b, 6, 6);

	cout << "�������Ľ�" << endl;
	
	return 0;
}
