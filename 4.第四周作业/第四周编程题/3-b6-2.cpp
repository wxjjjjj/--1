#include<iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "������[0-100��)֮�������:" << endl;
	double a, d, x;
	int e, f, g, h, i, j, k, l, m, n, p, q;
	cin >> a;
	a = a + 0.005;                              //�ֲ�ʵ�����������λС����Ҫ��С-0.0005���Դ�����
	long c;                                     //��Ϊlong long��dev�б��벻ͨ����������long��
	x = a / 100;								    //��������������ݱ�ò���������11��9λ����������� ����ʱ��λС������λС����
	c = long(x);									//�����������������ִ���c��
	d = x - c;								    //��С�����ִ���d��

	g = c % 10;									//��λ����
	c = c / 10;
	h = c % 10;									//ǧλ����
	c = c / 10;
	i = c % 10;									//��λ����
	c = c / 10;
	j = c % 10;									//ʮ��λ����
	c = c / 10;
	k = c % 10;									//����λ����
	c = c / 10;
	l = c % 10;									//ǧ��λ����
	c = c / 10;
	m = c % 10;									//��λ����
	c = c / 10;
	n = c % 10;									//ʮ��λ����

	p = int(d * 10);                            //ʮλ����
	q = int((d - p * 0.1) / 0.01);              //Բλ����
	e = int((d - 0.1 * p - 0.01 * q) / 0.001);									//��λ����
	f = int((d - 0.1 * p - 0.01 * q - 0.001 * e) / 0.0001);									//��λ����

	cout << "��д�����:" << endl;

	switch (n) {
		case 0:
			break;
		case 1:
			if (m == 0) {
				cout << "Ҽʰ��";
			}
			else {
				cout << "Ҽʰ";
			}
			break;
		case 2:
			if (m == 0) {
				cout << "��ʰ��";
			}
			else {
				cout << "��ʰ";
			}
			break;
		case 3:
			if (m == 0) {
				cout << "��ʰ��";
			}
			else {
				cout << "��ʰ";
			}
			break;
		case 4:
			if (m == 0) {
				cout << "��ʰ��";
			}
			else {
				cout << "��ʰ";
			}
			break;
		case 5:
			if (m == 0) {
				cout << "��ʰ��";
			}
			else {
				cout << "��ʰ";
			}
			break;
		case 6:
			if (m == 0) {
				cout << "½ʰ��";
			}
			else {
				cout << "½ʰ";
			}
			break;
		case 7:
			if (m == 0) {
				cout << "��ʰ��";
			}
			else {
				cout << "��ʰ";
			}
			break;
		case 8:
			if (m == 0) {
				cout << "��ʰ��";
			}
			else {
				cout << "��ʰ";
			}
			break;
		case 9:
			if (m == 0) {
				cout << "��ʰ��";
			}
			else {
				cout << "��ʰ";
			}
			break;
	}
	switch (m) {
		case 0:
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
	}                                                     //�ں�ʮ��λ�������

	switch (l) {
		case 0:
			if(l==0&&k==0&&j==0&&i==0){
				break;
			}
			else if (m == 0 && n == 0) {
				break;
			}
			else {
				cout << "��";
				break;
			}
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
	}
	switch (k) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && i == 0) {
				break;
			}
			else if (m == 0 && n == 0 && l == 0) {
				break;
			}
			else{
				if (l == 0) {
					break;
				}
				else if(l!=0&&j!=0&&i!=0){
					cout << "��";
					break;
				}
				else {
					break;
				}
			}
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
	}
	switch (j) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && i == 0) {
				break;
			}
			else if (l == 0 && k == 0 && m == 0 && n == 0) {
				break;
			}
			else{
				if ( k != 0&&i!=0){
					cout << "��";
					break;
				}
				else {
					break;
				}
			}
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
	}
	switch (i) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && i == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0) {
				break;
			}
			else{
				cout << "��";
				break;
			}
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
	}                        //ǧ�򡢰���ʮ���������

	switch (h) {
		case 0:
			if (h == 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0&&i==0) {
				break;
			}
			else if (g == 0 && p == 0) {
				break;
			}
			else  {
				cout << "��";
				break;
			}
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
	}
	switch (g) {
		case 0:
			if (h== 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0&&h==0) {
				break;
			}
			else {
				if (h == 0) {
					break;
				}
				else if(h!=0&&p!=0){
					cout << "��";
					break;
				}
				else {
					break;
				}
			}
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
	}
	switch (p) {
		case 0:
			if (h == 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0&&g==0) {
				break;
			}
			else {
				if (q!= 0 &&g!=0){
					cout << "��";
					break;
				}
				else if (g ==0 && q != 0) {
					cout << "��";
					break;
				}
				else {
					break;
				}
			}
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
	}
	switch (q) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && e != 0 ) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && f != 0) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && e != 0 && f != 0) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0&&p==0){
				cout << "��Բ";
				break;
			}
			
			else {
				cout << "Բ";
				break;
			}
		case 1:
			cout << "ҼԲ";
			break;
		case 2:
			cout << "��Բ";
			break;
		case 3:
			cout << "��Բ";
			break;
		case 4:
			cout << "��Բ";
			break;
		case 5:
			cout << "��Բ";
			break;
		case 6:
			cout << "½Բ";
			break;
		case 7:
			cout << "��Բ";
			break;
		case 8:
			cout << "��Բ";
			break;
		case 9:
			cout << "��Բ";
			break;
	}                        //ǧ���١�ʮ��Բ�������

	if (e == 0 && f == 0) {
		cout << "��" << endl;
	}
	else if (e == 0 && f != 0) {
		if (q != 0||p!=0||g!=0||h!=0||i!=0||j!=0||k!=0||l!=0||m!=0||n!=0){
			cout << "��";
		}
		switch (f) {
			case 1:
				cout << "Ҽ��" << endl;
				break;
			case 2:
				cout << "����" << endl;
				break;
			case 3:
				cout << "����" << endl;
				break;
			case 4:
				cout << "����" << endl;
				break;
			case 5:
				cout << "���" << endl;
				break;
			case 6:
				cout << "½��" << endl;
				break;
			case 7:
				cout << "���" << endl;
				break;
			case 8:
				cout << "�Ʒ�" << endl;
				break;
			case 9:
				cout << "����" << endl;
				break;
		}
	}
	else if (e != 0 && f == 0) {
		switch (e) {
			case 1:
				cout << "Ҽ����" << endl;
				break;
			case 2:
				cout << "������" << endl;
				break;
			case 3:
				cout << "������" << endl;
				break;
			case 4:
				cout << "������" << endl;
				break;
			case 5:
				cout << "�����" << endl;
				break;
			case 6:
				cout << "½����" << endl;
				break;
			case 7:
				cout << "�����" << endl;
				break;
			case 8:
				cout << "�ƽ���" << endl;
				break;
			case 9:
				cout << "������" << endl;
				break;
		}
	}
	else {
		switch (e) {
			case 1:
				cout << "Ҽ��";
				break;
			case 2:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 5:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 7:
				cout << "���";
				break;
			case 8:
				cout << "�ƽ�";
				break;
			case 9:
				cout << "����";
				break;
		}
		switch (f) {
			case 1:
				cout << "Ҽ��" << endl;
				break;
			case 2:
				cout << "����" << endl;
				break;
			case 3:
				cout << "����" << endl;
				break;
			case 4:
				cout << "����" << endl;
				break;
			case 5:
				cout << "���" << endl;
				break;
			case 6:
				cout << "½��" << endl;
				break;
			case 7:
				cout << "���" << endl;
				break;
			case 8:
				cout << "�Ʒ�" << endl;
				break;
			case 9:
				cout << "����"<<endl;
				break;
		}
	}
	return 0;
}