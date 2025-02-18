#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int runnian(int year) {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
		return 1;
	}
	return 0;
}

int day(int year, int runnian, int month, int days) {   //������ѡ������Ǿ��ö�ά���飡����
	int i, sum = 0;
	//ÿ�µ������洢��������
	int a[2][12] = { {31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31} };//a[0]����Ƿ����� a[1]���������
	//���������
	if (month <= 0 || month >= 13) {
		printf("�������-�·ݲ���ȷ\n");
		return 0;
	}
	if (a[runnian][month - 1] < days || days <= 0) {
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
		return 0;
	}
	//��������
	for (i = 0; i < month - 1; ++i) {
		sum = a[runnian][i] + sum;
	}
	sum = sum + days;
	return sum;

}

int main()
{
	printf("�������꣬�£���\n");
	int a, b, c, d, sum;
	scanf("%d %d %d", &a, &b, &c);          //a���꣬b���£�c���� 
	d = runnian(a);     //dΪ1���������ꣻ0Ϊ������
	sum = day(a, d, b, c);
	if (sum == 0) {
		return 0;
	}
	printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, sum);
	return 0;
}