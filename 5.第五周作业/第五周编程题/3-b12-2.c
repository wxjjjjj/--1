/* �ƿ� 2353761 ��𪾧 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;

	while (1) {
		printf("������x��ֵ[0-100] : ");
		ret = scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (ret == 1 && (x >= 0 && x <= 100)) {
			break;
		}
		else if (ret == 1) {
			printf("�����д�[ret=%d x=%d],����������\n", ret, x);           //ȷ��һ�£�ret��ֵ����scanf�ķ���ֵ����ʲô���壿 --����scanf�ɹ���ȡ����Чֵ����
		}
		else {
			printf("�����д�[ret=%d x=%d],����������\n", ret, x);
			int c;                                                             // ѭ����ȡ�������ַ���ֱ���������з�  
			while ((c = getchar()) != '\n' && c != EOF) {
				if (c == '\n' && (c = getchar()) != EOF) {
					ungetc(c, stdin);                                              // ����ȡ�Ķ����ַ��Ż����������������EOF��  
				}                                                                  // ������뻺�����еĴ����ַ�  
			}
		}
	}

	printf("ret=%d x=%d\n", ret, x);

	return 0;
}