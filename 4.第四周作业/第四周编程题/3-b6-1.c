#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	printf("������[0-100��)֮�������:\n");
	double a, d, x;
	int e, f, g, h, i, j, k, l, m, n, p, q;
	scanf("%lf", &a);
	a = a + 0.005;                              //�ֲ�ʵ�����������λС����Ҫ��С-0.0005���Դ�����
	long c;                                     //��Ϊlong long��dev�б��벻ͨ����������long��
	x = a / 100;								    //��������������ݱ�ò���������11��9λ����������� ����ʱ��λС������λС����
	c = (long)x;									//�����������������ִ���c��
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

	p = (int)(d * 10);                            //ʮλ����
	q = (int)((d - p * 0.1) / 0.01);              //Բλ����
	e = (int)((d - 0.1 * p - 0.01 * q) / 0.001);									//��λ����
	f = (int)((d - 0.1 * p - 0.01 * q - 0.001 * e) / 0.0001);									//��λ����

	printf("��д�����:\n");

	switch (n) {
		case 0:
			break;
		case 1:
			if (m == 0) {
				printf("Ҽʰ��");
			}
			else {
				printf("Ҽʰ");
			}
			break;
		case 2:
			if (m == 0) {
				printf("��ʰ��");
			}
			else {
				printf("��ʰ");
			}
			break;
		case 3:
			if (m == 0) {
				printf("��ʰ��");
			}
			else {
				printf("��ʰ");
			}
			break;
		case 4:
			if (m == 0) {
				printf("��ʰ��");
			}
			else {
				printf("��ʰ");
			}
			break;
		case 5:
			if (m == 0) {
				printf("��ʰ��");
			}
			else {
				printf("��ʰ");
			}
			break;
		case 6:
			if (m == 0) {
				printf("½ʰ��");
			}
			else {
				printf("½ʰ");
			}
			break;
		case 7:
			if (m == 0) {
				printf("��ʰ��");
			}
			else {
				printf("��ʰ");
			}
			break;
		case 8:
			if (m == 0) {
				printf("��ʰ��");
			}
			else {
				printf("��ʰ");
			}
			break;
		case 9:
			if (m == 0) {
				printf("��ʰ��");
			}
			else {
				printf("��ʰ");
			}
			break;
	}
	switch (m) {
		case 0:
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
	}                                                     //�ں�ʮ��λ�������

	switch (l) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && i == 0) {
				break;
			}
			else if (m == 0 && n == 0) {
				break;
			}
			else {
				printf("��");
				break;
			}
		case 1:
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
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
			else {
				if (l == 0) {
					break;
				}
				else if (l != 0 && j != 0 && i != 0) {
					printf("��");
					break;
				}
				else {
					break;
				}
			}
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
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
			else {
				if (k != 0 && i != 0) {
					printf("��");
					break;
				}
				else {
					break;
				}
			}
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
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
			else {
				printf("��");
				break;
			}
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
	}                        //ǧ�򡢰���ʮ���������

	switch (h) {
		case 0:
			if (h == 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0) {
				break;
			}
			else if (g == 0 && p == 0) {
				break;
			}
			else {
				printf("��");
				break;
			}
		case 1:
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
	}
	switch (g) {
		case 0:
			if (h == 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0) {
				break;
			}
			else {
				if (h == 0) {
					break;
				}
				else if (h != 0 && p != 0) {
					printf("��");
					break;
				}
				else {
					break;
				}
			}
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;

	}
	switch (p) {
		case 0:
			if (h == 0 && g == 0 && p == 0 && q == 0) {
				break;
			}
			else if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0) {
				break;
			}
			else {
				if (q != 0 && g != 0) {
					printf("��");
					break;
				}
				else if (g == 0 && q != 0) {
					printf("��");
					break;
				}
				else {
					break;
				}
			}
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
	}
	switch (q) {
		case 0:
			if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && e != 0) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && f != 0) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0 && e != 0 && f != 0) {
				break;
			}
			else	if (l == 0 && k == 0 && j == 0 && m == 0 && n == 0 && i == 0 && h == 0 && g == 0 && p == 0) {
				printf("��Բ");
				break;
			}

			else {
				printf("Բ");
				break;
			}
		case 1:
			printf("ҼԲ");
			break;
		case 2:
			printf("��Բ");
			break;
		case 3:
			printf("��Բ");
			break;
		case 4:
			printf("��Բ");
			break;
		case 5:
			printf("��Բ");
			break;
		case 6:
			printf("½Բ");
			break;
		case 7:
			printf("��Բ");
			break;
		case 8:
			printf("��Բ");
			break;
		case 9:
			printf("��Բ");
			break;
	}                        //ǧ���١�ʮ��Բ�������

	if (e == 0 && f == 0) {
		printf("��\n");
	}
	else if (e == 0 && f != 0) {
		if (q != 0 || p != 0 || g != 0 || h != 0 || i != 0 || j != 0 || k != 0 || l != 0 || m != 0 || n != 0) {
			printf("��");
		}
		switch (f) {
			case 1:
				printf("Ҽ��\n");
				break;
			case 2:
				printf("����\n");
				break;
			case 3:
				printf("����\n");
				break;
			case 4:
				printf("����\n");
				break;
			case 5:
				printf("���\n");
				break;
			case 6:
				printf("½��\n");
				break;
			case 7:
				printf("���\n");
				break;
			case 8:
				printf("�Ʒ�\n");
				break;
			case 9:
				printf("����\n");
				break;
		}
	}
	else if (e != 0 && f == 0) {
		switch (e) {
			case 1:
				printf("Ҽ����\n");
				break;
			case 2:
				printf("������\n");
				break;
			case 3:
				printf("������\n");
				break;
			case 4:
				printf("������\n");
				break;
			case 5:
				printf("�����\n");
				break;
			case 6:
				printf("½����\n");
				break;
			case 7:
				printf("�����\n");
				break;
			case 8:
				printf("�ƽ���\n");
				break;
			case 9:
				printf("������\n");
				break;
		}
	}
	else {
		switch (e) {
			case 1:
				printf("Ҽ��");
				break;
			case 2:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 5:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 7:
				printf("���");
				break;
			case 8:
				printf("�ƽ�");
				break;
			case 9:
				printf("����");
				break;
		}
		switch (f) {
			case 1:
				printf("Ҽ��\n");
				break;
			case 2:
				printf("����\n");
				break;
			case 3:
				printf("����\n");
				break;
			case 4:
				printf("����\n");
				break;
			case 5:
				printf("���\n");
				break;
			case 6:
				printf("½��\n");
				break;
			case 7:
				printf("���\n");
				break;
			case 8:
				printf("�Ʒ�\n");
				break;
			case 9:
				printf("����\n");
				break;
		}
	}
	return 0;
}
