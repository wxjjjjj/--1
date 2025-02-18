#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>



int bushu = 1;            
int a[10],b[10],c[10];  //�洢�̺�
int d, e, f;            //�洢a��b��c��������

void print(int n, char src, char dst) {
	int i, j,m;
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

	printf("A:");
	for (m = 0; m < 10; ++m) {
		if (a[m] > 0) {
			printf("%2d", a[m]);
		}
		else {
			printf("  ");
		}
	}
	printf(" ");

	printf("B:");
	for (m = 0; m < 10; ++m) {
		if (b[m] > 0) {
			printf("%2d", b[m]);
		}
		else {
			printf("  ");
		}
	}
	printf(" ");

	printf("C:");
	for (m = 0; m < 10; ++m) {
		if (c[m] > 0) {
			printf("%2d", c[m]);
		}
		else {
			printf("  ");
		}
	}
	printf(" ");

	printf("\n");

	return;
}

void hanoi(int n, char src, char tmp, char dst)  //n���̺�(Ҳ�ǲ���) ���ϵ���Ϊ1��2��3...
{
	if (n == 1) {
		printf("��%4d ��(%2d): %c-->%c ", bushu, n, src, dst);
		print(n, src, dst);
		++bushu;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	printf("��%4d ��(%2d): %c-->%c ", bushu, n, src, dst);
	print(n, src, dst);
	++bushu;
	hanoi(n - 1, tmp, src, dst);
	return;
	
}

void chushihua(char src,int n) {
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
}

int main()
{
	int layers,ret,ret1,ret2;
	char src, dst, tmp;//layers�ǲ㣬src����ʼ��,dst��Ŀ����,tmp�Ǹ�����

	while (1) {
		printf("�����뺺ŵ���Ĳ���(1-10)\n");
		ret=scanf("%d", &layers);
		if (ret == 0) {
			int cc;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
			while ((cc = getchar()) != '\n' && cc != EOF) {
				if (cc == '\n' && (cc = getchar()) != EOF) {
					ungetc(cc, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
				}                                                                  // ������뻺�����еĴ����ַ�  
			}
		}
		else {
			int ccc;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
			while ((ccc = getchar()) != '\n' && ccc != EOF) {
				if (ccc == '\n' && (ccc = getchar()) != EOF) {
					ungetc(ccc, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
				}                                                                  // ������뻺�����еĴ����ַ�  
			}
			if (layers >= 1 && layers <= 10) {
				while (1) {
					printf("��������ʼ��(A-C)\n");
					ret1 = scanf("%c", &src);
					if (ret1 == 0) {
						int cc;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
						while ((cc = getchar()) != '\n' && cc != EOF) {
							if (cc == '\n' && (cc = getchar()) != EOF) {
								ungetc(cc, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
							}                                                                  // ������뻺�����еĴ����ַ�  
						}
					}
					else {
						int dd;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
						while ((dd = getchar()) != '\n' && dd != EOF) {
							if (dd == '\n' && (dd = getchar()) != EOF) {
								ungetc(dd, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
							}                                                                  // ������뻺�����еĴ����ַ�  
						}
						if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) {
							while (1) {
								printf("������Ŀ����(A-C)\n");
								ret2 = scanf("%c", &dst);
								if (ret2 == 0) {
									int cc;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
									while ((cc = getchar()) != '\n' && cc != EOF) {
										if (cc == '\n' && (cc = getchar()) != EOF) {
											ungetc(cc, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
										}                                                                  // ������뻺�����еĴ����ַ�  
									}
								}
								else {
									int ddd;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
									while ((ddd= getchar()) != '\n' && ddd != EOF) {
										if (ddd == '\n' && (ddd = getchar()) != EOF) {
											ungetc(ddd, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
										}                                                                  // ������뻺�����еĴ����ַ�  
									}
									if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c')) {
										if (src == dst || src == dst + 32 || src == dst - 32) {
											if (src >= 'a' && src <= 'c') {
												src = src - 32;
											}
											if (dst >= 'a' && dst <= 'c') {
												dst = dst - 32;
											}
											printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", src, dst);
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

	chushihua(src,layers);

	printf("��ʼ:                ");

	printf("A:");
	for (int m = 0; m < 10; ++m) {
		if (a[m] > 0) {
			
			printf("%2d", a[m]);
		}
		else {
			printf("  ");
		}
	}
	printf(" ");
	
	printf("B:");
	for (int m = 0; m < 10; ++m) {
		if (b[m] > 0) {
			printf("%2d", b[m]);
		}
		else {
			printf("  ");
		}
	}
	printf(" ");

	printf("C:");
	for (int m = 0; m < 10; ++m) {
		if (c[m] > 0) {
			printf("%2d", c[m]);
		}
		else {
			printf("  ");
		}
	}
	printf(" ");

	printf("\n");

	hanoi(layers, src, tmp, dst);

	return 0;

}
