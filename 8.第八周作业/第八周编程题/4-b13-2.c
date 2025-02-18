/* 2353761 ��𪾧 �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */

int count = 0;
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
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		++count;
		printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	++count;
	printf("%5d:%3d# %c-->%c\n", count, n, src, dst);
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
	int layers,ret,ret1,ret2;
	char src, dst, tmp;//layers�ǲ㣬src����ʼ��,dst��Ŀ����,tmp�Ǹ�����

	while (1) {
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
		ret=scanf("%d", &layers);
		if (ret == 0) {
			int c;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
			while ((c = getchar()) != '\n' && c != EOF) {
				if (c == '\n' && (c = getchar()) != EOF) {
					ungetc(c, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
				}                                                                  // ������뻺�����еĴ����ַ�  
			}
		}
		else {
			int d;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
			while ((d = getchar()) != '\n' && d != EOF) {
				if (d == '\n' && (d = getchar()) != EOF) {
					ungetc(d, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
				}                                                                  // ������뻺�����еĴ����ַ�  
			}
			if (layers >= 1 && layers <= 16) {
				while (1) {
					printf("��������ʼ��(A-C)\n");
					ret1=scanf("%c",&src);
					if (ret1 == 0) {
						int e;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
						while ((e = getchar()) != '\n' && e != EOF) {
							if (e == '\n' && (e = getchar()) != EOF) {
								ungetc(e, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
							}                                                                  // ������뻺�����еĴ����ַ�  
						}
					}
					else {
						int f;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
						while ((f = getchar()) != '\n' && f != EOF) {
							if (f == '\n' && (f = getchar()) != EOF) {
								ungetc(f, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
							}                                                                  // ������뻺�����еĴ����ַ�  
						}
						if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) {
							while (1) {
								printf("������Ŀ����(A-C)\n");
								ret2=scanf("%c",&dst);
								if (ret2 == 0) {
									int g;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
									while ((g = getchar()) != '\n' && g != EOF) {
										if (g == '\n' && (g = getchar()) != EOF) {
											ungetc(g, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
										}                                                                  // ������뻺�����еĴ����ַ�  
									}
								}
								else {
									int h;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
									while ((h = getchar()) != '\n' && h != EOF) {
										if (h == '\n' && (h = getchar()) != EOF) {
											ungetc(h, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
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
											printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
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

	printf("�ƶ�����Ϊ:\n");
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
