#include<iostream>
#include<cmath>

using namespace std;

//printf("%d-%d-%d��%d��ĵ�%d��\n", a, b, c, a, sum);

void mingci(int array[], int n) {
	//��������ߵĳɼ��ڵ�a[0]��
	int i, j, k, t, mingci = 0;
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

	//����
	cout << array[0] << ' '<<1<<endl;
	for (i = 1; i < n; ++i) {
		if (array[i] >= 0) {
			for (j = i-1; j >=0; j--) {
				if (array[j] == array[i]) {
					mingci = j + 1;
				}
			}
			if (mingci == 0) {
				mingci = i + 1;
			}
			cout << array[i] << ' ' << mingci << endl;;
			mingci = 0;
		}
	}
}

int main() {
	cout << "������ɼ������1000������������������" << endl;;
	int a[1000], i;           //�Զ���������δ��ʼ������ֵ��ȷ����ֻ��ȫ�ֱ�������ʼ��ʱĬ��Ϊ0

	for (i = 0; i < 1000; ++i) {  //��ʼ��
		a[i] = -1;
	}

	for (i = 0; i < 1000; ++i) {  //i�м�¼��Ч�������������ݸ��������ã���ȷ������i+1��
		cin >> a[i];
		if (a[i] < 0) {
			break;
		}
	}
	if (a[0] < 0) {
		cout << "����Ч����" << endl;
		return 0;
	}
	cout << "���������Ϊ:" << endl;
	for (i = 0; i < 1000; ++i) {
		if (a[i] >= 0) {
			cout << a[i] << ' ';
			if (i % 10 == 9) {
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << "���������εĶ�Ӧ��ϵΪ:" << endl;

	mingci(a, 1000);

	return 0;
}