/*�ƿ� ��𪾧 2353761*/
#include<iostream>

using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";

int examine_function(char password[17],int changdu,int daxie,int xiaoxie,int number,int others)
{
	int count=0,daxie1=0,xiaoxie1=0,number1=0,others1=0,k=0;
	for (int i = 0; i < 17; ++i) {
		if (password[i] != 0) {
			count++;
		}
		if (password[i] >= '0' && password[i] <= '9') {
			number1++;
		}
		else if (password[i] >= 'a' && password[i] <= 'z') {
			xiaoxie1++;
		}
		else if (password[i] >= 'A' && password[i] <= 'Z') {
			daxie1++;
		}
		else {
			for (int j = 0; j < 15; ++j) {
				if (password[i] == other[j]) {
					others1++;
					break;
				}
			}
		}
	}
	if (count != changdu|| number1 < number || daxie1 < daxie || xiaoxie1 < xiaoxie || others1 < others||number1+daxie1+xiaoxie1+others1!=changdu) {
		cout << "����" << endl;
		k = 0;
	}
	else {//��ȷ�Ȳ����
		k = 1;
	}
	return k;
}

int main()
{
	int m = -1;
	char password[10][17] = { 0 };//���һ�д�β0����Ȼ���ҵ�
	int changdu, daxie, xiaoxie, number, others;
	cin.ignore(65536, '\n');//���Ե�һ��
	cin >> changdu;
	cin >> daxie;
	cin >> xiaoxie;
	cin >> number;
	cin >> others;
	cin.ignore(65536, '\n');//���Ե�һ��
	for (int i = 0; i < 10; ++i) {
		cin.getline(password[i], 17);
	}//��ȡ���

	for (int i = 0; i < 10; ++i) {
		
		m = examine_function(password[i],changdu,daxie,xiaoxie,number,others);
		if (m == 0) {
			return 0;
		}
	}
	cout << "��ȷ" << endl;
	return 0;
}