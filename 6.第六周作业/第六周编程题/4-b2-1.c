#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
	return w;
}

int main()
{
	int a, b, c, ret,l;//a���꣬b����,c������

	while (1) {
		printf("��������[1900-2100]���¡��գ�\n");
		ret=scanf("%d %d %d", &a, &b, &c);
		if (ret == 0 || ret == 1||ret==2) {
			int cc;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
			while ((cc = getchar()) != '\n' && cc != EOF) {
				if (cc == '\n' && (cc = getchar()) != EOF) {
					ungetc(cc, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
				}                                                                  // ������뻺�����еĴ����ַ�  
			}
			printf("�����������������\n");
		}
		else {
			if (a < 1900 || a>2100) {
				printf("��ݲ���ȷ������������\n");
			}
			else {
				if (b > 12 || b < 1) {
					printf("�·ݲ���ȷ������������\n");
				}
				else {  //���յ���ȷ��
					if (b == 2) {
						if ((a % 4 == 0) && (a % 100 != 0) || (a % 400 == 0)) {  //�������
							if (c >= 0 && c <= 29) {
								break;
							}
							else {
								printf("�ղ���ȷ������������\n");
							}
						}
						else {
							if (c >= 0 && c <= 28) {
								break;
							}
							else {
								printf("�ղ���ȷ������������\n");
							}
						}
					}
					else if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) {
						if (c >= 0 && c <= 31) {
							break;
						}
						else {
							printf("�ղ���ȷ������������\n");
						}

					}
					else {
						if (c >= 0 && c <= 30) {
							break;
						}
						else {
							printf("�ղ���ȷ������������\n");
						}
					}
				}
			}
		}
	}
	l = zeller(a, b, c);
	switch (l) {
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		case 6:
			printf("������\n");
			break;
		case 0:
			printf("������\n");
			break;
		default:
			break;
	}
	return 0;
}
