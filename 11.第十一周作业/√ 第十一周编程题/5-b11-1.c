/* �ƿ� ��𪾧 2353761 */
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<string.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */     //chnstr��ÿ����һ������
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void danwei_function(int n)
{
	switch (n) {
		case 0:
			strcat(result, "ʰ");
			break;
		case 1:
			strcat(result, "��");
			break;
		case 2:
			strcat(result, "Ǫ");
			break;
		case 3:
			strcat(result, "��");
			break;
		case 4:
			strcat(result, "ʰ");
			break;
		case 5:
			strcat(result, "��");
			break;
		case 6:
			strcat(result, "Ǫ");
			break;
		case 7:
			strcat(result, "��");
			break;
		case 8:
			strcat(result, "ʰ");
			break;
		case 9:
			strcat(result, "Բ");
			break;
		case 10:
			strcat(result, "��");
			break;
		case 11:
			strcat(result, "��");
			break;
		case 12:
			strcat(result, "��");
			break;
	}
	return;
}
void result_function(int array[])
{
	int tmp = 0;
	for (int i = 0; i < 10; ++i) {
		//�ȴ�������
		if (array[i] != 0) {
			strncat(result, &chnstr[2 * array[i]], 2);
		}
		else {
			if (i != 0 && i != 1&&i!=5) {
				for (int j = 0; j < i; ++j) {
					tmp = tmp + array[j];
				}
				if (tmp > 0 && array[i + 1] > 0&&i!=9) {
					strncat(result, &chnstr[2 * array[i]], 2);
				}
				else if (tmp + array[10] + array[11] == 0 && i == 9) {
					strncat(result, &chnstr[2 * array[i]], 2);
				}
				tmp = 0;
			}
		}
		//����λ
		if (i != 1 && i != 5 && i != 9) {
			if (array[i] != 0) {
				danwei_function(i);
			}
		}
		else {
			if (i == 1) {
				if (array[0] + array[1]) {
					danwei_function(i);
				}
			}
			else if (i == 5) {
				if (array[2] + array[3] + array[4] + array[5]) {
					danwei_function(i);
				}
			}
			else {
				for (int j = 0; j <= i; ++j) {
					tmp = array[j] + tmp;
				}
				if (tmp==0&&(array[10]!=0||array[11]!=0)) {
					;
				}
				else {
					danwei_function(i);
				}
				
			}
		}
	}
	//�ǡ��ֵ�������
	if (array[10] == 0 && array[11] == 0) {
		danwei_function(12);
	}
	else if (array[10] != 0 && array[11] == 0) {
		if (array[10] != 0) {
			strncat(result, &chnstr[2 * array[10]], 2);
		}
		danwei_function(10);
		danwei_function(12);
	}
	else if (array[10] == 0 && array[11] != 0) {
		for (int j = 0; j < 10; ++j) {
			tmp = tmp + array[j];
		}
		if (tmp > 0) {
			strncat(result, &chnstr[2 * array[10]], 2);
		}
		if (array[11]) {
			strncat(result, &chnstr[2 * array[11]], 2);
		}
		danwei_function(11);
	}
	else {
		if (array[10] != 0) {
			strncat(result, &chnstr[2 * array[10]], 2);
		}
		if (array[10] != 0) {
			danwei_function(10);
		}
		if (array[11] != 0) {
			strncat(result, &chnstr[2 * array[11]], 2);
		}
		if (array[11] != 0) {
			danwei_function(11);
		}
	}
	return;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
	printf("������[0-100��)֮�������:\n");
	double a, d, x;
	int shuzi[12] = { 0 };
	scanf("%lf", &a);
	a = a + 0.005;                              //�ֲ�ʵ�����������λС����Ҫ��С-0.0005���Դ�����
	long c;                                     //��Ϊlong long��dev�б��벻ͨ����������long��
	x = a / 100;								    //��������������ݱ�ò���������11��9λ����������� ����ʱ��λС������λС����
	c = (long)x;									//�����������������ִ���c��
	d = x - c;								    //��С�����ִ���d��

	shuzi[7] = c % 10;									//��λ����

	c = c / 10;
	shuzi[6] = c % 10;									//ǧλ����

	c = c / 10;
	shuzi[5] = c % 10;									//��λ����

	c = c / 10;
	shuzi[4] = c % 10;									//ʮ��λ����

	c = c / 10;
	shuzi[3] = c % 10;									//����λ����

	c = c / 10;
	shuzi[2] = c % 10;									//ǧ��λ����

	c = c / 10;
	shuzi[1] = c % 10;									//��λ����

	c = c / 10;
	shuzi[0] = c % 10;									//ʮ��λ����

	shuzi[8] = (int)(d * 10);                            //ʮλ����
	shuzi[9] = (int)((d - shuzi[8] * 0.1) / 0.01);              //Բλ����
	shuzi[10] = (int)((d - 0.1 * shuzi[8] - 0.01 * shuzi[9]) / 0.001);									//��λ����
	shuzi[11] = (int)((d - 0.1 * shuzi[8] - 0.01 * shuzi[9] - 0.001 * shuzi[10]) / 0.0001);									//��λ����

	printf("��д�����:\n");
	result_function(shuzi);
    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
   
   
    return 0;
}
