#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>


/*
��һ�ַ�����
����Ԫ�ص�ֵ����һ��������±�--����Խ��ķ���*/

void count(int array[],int n) {
	//��������ߵĳɼ��ڵ�a[0]��
	int i, j, k, t,geshu=0;
	for (i = 0; i < n - 1; ++i) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (array[j] > array[k]) {
				k = j;
			}
		}
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}
	for (i = 0; i < n; ++i) {
		if (array[i] >= 0) {
			for (j = i+1; j < n; j++) {
				if (array[j] == array[i]) {
					array[j] = -1;
					++geshu;
				}
			}
			if (geshu >= 0) {
				++geshu;
				printf("%d ", array[i]);
				printf("%d\n", geshu);
			}
			geshu = 0;
		}
			
	}
}

int main() {
	printf("������ɼ������1000������������������\n");
	int a[1000], i;           //�Զ���������δ��ʼ������ֵ��ȷ����ֻ��ȫ�ֱ�������ʼ��ʱĬ��Ϊ0

	for (i = 0; i < 1000; ++i) {  //��ʼ��
		a[i] = -1;
	}

	for (i = 0; i < 1000; ++i) {  //i�м�¼��Ч�������������ݸ��������ã���ȷ������i+1��
		scanf("%d", &a[i]);    
		if (a[i] < 0) {
			break;
		}
	}
	if (a[0] < 0) {
		printf("����Ч����\n");
		return 0;
	}
	printf("���������Ϊ:\n");
	for (i = 0; i < 1000; ++i) {
		if (a[i] >= 0) {
			printf("%d ", a[i]);
			if (i % 10 == 9) {
				printf("\n");
			}
		}
	}
	printf("\n");
	printf("�����������Ķ�Ӧ��ϵΪ:\n");

	count(a,1000);

	return 0;
}
