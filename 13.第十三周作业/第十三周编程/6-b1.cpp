/* 2353761 ��𪾧 �ƿ� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], *p;
	int  a[N] = { 0 }, *pnum, *pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	cin.getline(str, 256);//�����ַ���

	pnum = a;
	pa = a;
	p = str;
	is_num = 0;
	for (; *p != 0 && pnum - pa < N; ++p) {
		if ('0' <= *p &&*p<= '9') {

			if (!is_num) {
				*pnum = int(*p - '0');
				is_num = 1;
			}
			else {
				*pnum = *pnum * 10 + int(*p - '0');
			}
		}
		else {
			if (is_num) {
				is_num = 0;
				pnum++;
			}
		}
	}

	cout << "����" << pnum - pa + is_num << "������" << endl;
	for (; pnum-pa+is_num!= 0; ++pa) {
		cout << *pa << ' ';
	}
	cout << endl;

	return 0;
}
