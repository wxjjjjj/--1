/*2353761 ��𪾧 �ƿ�*/
#include<iostream>
#include<string>

using namespace std;

void shuru(string xuehao[], string name[], int score[10])
{
	for (int i = 0; i < 10; ++i) {
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> xuehao[i];
		cin >> name[i];
		cin >> score[i];
	}
	return;
}
void select(string xuehao[], string name[], int score[10])
{
	int k,m;
	string s1, s2;
	for (int i = 0; i < 9; ++i) {
		k = i;
		for (int j = i + 1; j < 10; ++j) {
			if (score[j] < score[k]) {
				k = j;
			}
		}//�ҳ���Сֵ���±�
		m = score[i];
		s1 = xuehao[i];
		s2 = name[i];
		score[i] = score[k];
		xuehao[i] = xuehao[k];
		name[i] = name[k];
		score[k] = m;
		xuehao[k] = s1;
		name[k] = s2;
	}
	return;
}
void print(string xuehao[], string name[], int score[10])
{
	cout << endl;
	cout << "����������(�ɼ�����):" << endl;
	for (int i = 0; i < 10; ++i) {
		if (score[i] < 60) {
			cout << name[i] << ' ' << xuehao[i] << ' ' << score[i] << endl;
		}
	}
	return;
}
int main()
{
	string xuehao[10], name[10];
	int score[10];
	shuru(xuehao,name,score);
	select(xuehao, name, score);
	print(xuehao, name, score);
	return 0;
}