/*�ƿ� ��𪾧 2353761*/
#include<iostream>
#include <ctime> //��������� 

using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";

void generate_password(int changdu, int daxie, int xiaoxie, int number, int others, char password[17])
{
	
	int i,count=0;
	while (count<changdu) {
		i = rand() % 75 + 48; //����i��48-122֮��,�Ǵ�д��Сд�����ֵķ�Χ
		
		if (i >= 48 && i <= 57&&number>0) {
			number--;
			password[count] = char(i);
			++count;
		}
		else if (i >= 65 && i <= 90 && daxie > 0) {
			daxie--;
			password[count] = char(i);
			count++;
		}
		else if (i >= 97 && i <= 122&&xiaoxie>0) {
			xiaoxie--;
			password[count] = char(i);
			count++;
		}
		else {
			if (others > 0) {
				others--;
				password[count] = other[i % 15];//��ֹԽ��
				count++;
			}
			else if(number==0&&daxie==0&&others==0&&xiaoxie==0) {//������С���������
				if (i >= 48 && i <= 57) {
					password[count] = char(i);
					++count;
				}
				else if (i >= 65 && i <= 90) {
					password[count] = char(i);
					count++;
				}
				else if (i >= 97 && i <= 122) {
					password[count] = char(i);
					count++;
				}
				else {
					password[count] = other[i % 15];//��ֹԽ��
					count++;
				}
			}
		}//������ÿ�����ͷ��ŵ���С��������

	}

	return;
}


int main()
{
	char password[10][17] = { 0 };//char 0��β�㣬��0��������0��'/0'��β��,���һ�д�β0
	/* srand������������α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ���
	������main������ִ�й������ں����ﲻ��*/
	srand((unsigned int)(time(0)));

	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	int changdu, daxie, xiaoxie, number, others;
	cin >> changdu;
	if (cin.good() == 0) {
		cout << "����Ƿ�" << endl;
		return 0;
	}
	else {
		if (changdu >= 12 && changdu <= 16) {
			cin >> daxie;
			if (cin.good() == 0) {
				cout << "����Ƿ�" << endl;
				return 0;
			}
			else {
				if (daxie >= 2) {
					cin >> xiaoxie;
					if (cin.good() == 0) {
						cout << "����Ƿ�" << endl;
					}
					else {
						if (xiaoxie >= 2) {
							cin >> number;
							if (cin.good() == 0) {
								cout << "����Ƿ�" << endl;
							}
							else {
								if (number >= 2) {
									cin >> others;
									if (cin.good() == 0) {
										cout << "����Ƿ�" << endl;
									}
									else {
										if (others >= 2) {
											if (others + number + daxie + xiaoxie > changdu) {
												cout << "�����ַ�����֮��[" << daxie << '+' << xiaoxie << '+' << number << '+' <<others << "]���������볤��[" << changdu << "]" << endl;
											}
											else {//���봦����ɣ���ʼ�������ʮ������
												for (int i = 0; i < 10; ++i) {
													generate_password(changdu,daxie, xiaoxie,number,others,password[i]);
												}
												cout << changdu << ' ' << daxie << ' ' << xiaoxie << ' ' << number << ' ' << others << endl;
												for (int i = 0; i < 10; ++i) {
													cout << password[i] << endl;
												}
												return 0;
											}
										}
										else {
											cout << "�������Ÿ���[" << others << "]����ȷ" << endl;
										}
									}
								}
								else {
									cout << "���ָ���[" << number << "]����ȷ" << endl;
								}
							}
						}
						else {
							cout<< "Сд��ĸ����[" << xiaoxie << "]����ȷ" << endl;
						}
					}
				}
				else {
					cout << "��д��ĸ����[" << daxie << "]����ȷ" << endl;
				}
			}
		}
		else {
			cout << "���볤��[" << changdu << "]����ȷ" << endl;
		}
		
	}
	return 0;
}
