#include<iostream>
#include<cmath>

using namespace std;

void paixu(int array[], int n) {
	int i,j,k,t;
	for (i = 0; i < n-1; ++i) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (array[j] < array[k]) {
				k = j;
			}
		}
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}
	for (i = 0; i < n; ++i) {
		if (array[i] > 0)
			cout << array[i] << ' ';
	}
}

int main() {
	cout << "��������������������������20������0������������" << endl;
	int a[21], i, b;           //�Զ���������δ��ʼ������ֵ��ȷ����ֻ��ȫ�ֱ�������ʼ��ʱĬ��Ϊ0

	for (i = 0; i < 20; ++i) {  //��ʼ��
		a[i] = 0;
	}

	for (i = 0; i < 20; ++i) {  //i�м�¼��Ч�������������ݸ��������ã���ȷ������i+1��
		cin >> a[i];
		if (a[i] <= 0) {
			break;              
		}
	}
	if (a[0] <= 0) {
		cout << "����Ч����" << endl;
		return 0;
	}
	cout << "ԭ����Ϊ��" << endl;
	for (i = 0; i <20; ++i) {
		if(a[i]>0)
			cout << a[i] << ' ';
	}
	cout << endl;
	cout << "������Ҫ�����������" << endl;

	cin.ignore(65536, '\n');        //���������ǰ����հɣ����cin��coutֱ��ignore���������cout��ʲô��û��

	cin >> a[20];
	cout << "����������Ϊ��" << endl;
	paixu(a, 21);
	cout << endl;
	return 0;
}