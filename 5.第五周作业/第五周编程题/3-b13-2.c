#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a, b, c,ret;//a���꣬b����,c������

	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret = scanf("%d %d", &a, &b);
		if (ret == 0||ret==1) {
			int cc;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
			while ((cc = getchar()) != '\n' && cc != EOF) {
				if (cc == '\n' && (cc = getchar()) != EOF) {
					ungetc(cc, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
				}                                                                  // ������뻺�����еĴ����ַ�  
			}
			printf("����Ƿ�������������\n");
		}
		else {
			if ((a >= 2000 && a <= 2030 && b >= 1 && b <= 12) == 0) {
				printf("����Ƿ�������������\n");
			}
			else {
				while (1) {
					printf("������%d��%d��1�յ����ڣ�0-6��ʾ������-������) : ",a,b);
					int ret2;
					ret2 = scanf("%d", &c); 
					if (ret2 == 0) {
						int ccc;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
						while ((ccc = getchar()) != '\n' && ccc != EOF) {
							if (ccc == '\n' && (ccc = getchar()) != EOF) {
								ungetc(ccc, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
							}                                                                  // ������뻺�����еĴ����ַ�  
						}
						printf("����Ƿ�������������\n");
					}
					else {
						if ((c >= 0 && c <= 6) == 0) {
							printf("����Ƿ�������������\n");
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

	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n",a,b);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������  \n");
	int d = 1;
	switch (c) {
		case 0:
			printf("%4d",d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
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
				if (d % 7 == 0) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 1:
			printf("%12d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
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
				if (d % 7 == 6) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 2:
			printf("%20d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
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
				if (d % 7 == 5) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 3:
			printf("%28d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
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
				if (d % 7 == 4) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 4:
			printf("%36d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
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
				if (d % 7 == 3) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 5:
			printf("%44d", d);
			for (d = 2; d <= 31; d++) {
				printf("%8d", d);
				
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
				if (d % 7 == 2) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;
		case 6:
			printf("%52d\n", d);
			for (d = 2; d <= 31; d++) {
				if (d == 2) {
					printf("%4d", d);
					d++;
				}
				printf("%8d", d);
				
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
				if (d % 7 == 1) {
					printf("\n");
					d++;
					printf("%4d", d);
				}
			}
			break;

	}
	printf("\n");
	return 0;
}
