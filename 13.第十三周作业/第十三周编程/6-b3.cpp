/*2353761 ��𪾧 �ƿ�*/
#include<iostream>

using namespace std;

int main()
{
	char str[33] = { 0 };
	char* p;
	unsigned int count = 0, sum=0,tmp=1,a;

	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin.getline(str, 33);//��ȡ�� n-1 ���ַ�Ϊֹ��Ϊ�������ռ�洢�ַ����Ľ�β�� \0������ȡ���ı������������з����ᱻ�洢���ַ����� str �С�

	p = str;
	while (*p != 0) {
		++p;
		++count;
	}//pָ��β0
	a = count;
	while (count != 0) {
		--p;
		for (int i = 1; i <=a-count; ++i) {
			tmp = tmp*2;
		}//2��n�η�
		sum = sum+int(*p-'0') * tmp;
		--count;
		tmp = 1;
	}

	cout << sum << endl;
	return 0;

}