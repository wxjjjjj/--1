/*2353761 ��𪾧 �ƿ�*/
#include<iostream>
#include<cstdio>
#include<stdio.h>

using namespace std;

int judge_huiwen(char* str1, char* str2)
{
	char* p,*q,*n;
	p = str1;
	q = str1;
	n = str2;
	while (*p != '\n') {
		++p;
	}//pָ��/n�س�

	if (p - q <= 1) {
		return 1;
	}//�մ���һ���ַ��Ĵ�
	else {
		while (p - q != 0) {
			--p;
			*n = *p;
			n++;
		}//���������
	}
	n = str2;
	while (*p != '\n') {
		if (*p != *n) {
			return 0;
		}
		n++;
		p++;
	}
	return 1;
	
}
int main()
{
	char str1[81],str2[81];
	bool is_huiwen;
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str1, 81, stdin);

	is_huiwen = judge_huiwen(str1, str2);
	
	if (is_huiwen) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

	return 0;
}