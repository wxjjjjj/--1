#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int a[100],i,j,k=0;

	for (i = 0; i < 100; ++i) {
		a[i] = 0;                  //��ʼ��100յ��ȫ��
	}

	for (i = 1; i < 101; ++i) {   //i,j�Ǳ��
		for (j = 1; j < 101; ++j) {
			if (j % i == 0) {
				a[j-1] = a[j-1] + 1;
			}
		}
	}
	
	for (i = 0; i < 100; ++i) {
		if (a[i] % 2 == 1) {                //�����������Ϊ���Ƶı��
			++k;                            //k�������
		}
	}

	for (i = 0; i < 100; ++i) {
		if (a[i] % 2 == 1&&k>1) {                //�����������Ϊ���Ƶı��
			cout << i + 1 << ' ';
			k--;
		}
		else if (a[i] % 2 == 1 && k == 1) {
			cout << i + 1;
		}
	}

	
	cout << endl;

	return 0;
}