/*2353761 ��𪾧 �ƿ�*/
#include <iostream>
#include<iomanip>
using namespace std;


int zeller(int y, int m, int d) //�Ѿ�������y��m��d�����ڲ����ٶ���
{
	int c, w, q;
	q = y;    //��ݴ���q�ڲ���
	c = y / 100;
	y = y - c * 100;
	if (m == 1) {
		q = q - 1;
		c = q / 100;
		y = q - c * 100;
		m = 13;
	}
	else if (m == 2) {
		q = q - 1;
		c = q / 100;
		y = q - c * 100;
		m = 14;
	}
	else {
		m = m;
	}
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w = w + 7;
	}
	w = w % 7;
	return w;    //wΪ���������ն�Ӧ������0��������
}

void print_title(int month)//��ӡ�������
{
	cout << setiosflags(ios::right)<<setw(3*4+1) << month - 2 << "��";
	cout << setiosflags(ios::right)<< setw(7*4+2) << month - 1 << "��";
	cout << setiosflags(ios::right)<< setw(7 * 4 + 2) << month << "��" << endl;
	cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
	return;
}
 
void print_days(int year, int month3, int array[])   //���д�ӡ���� array��ÿ���µ���������
{
	int k = 0,w = 0,tmp=0,max_line=0,line=0;
	int a[6] = { 0 };//�������������ǣ�a[0]-a[1]��month3-2�µ�k-������w-���µ�һ�����������0Ϊ���գ��������Դ�����
	for (int i = month3 - 2; i <= month3; ++i) {
		w=zeller(year, i, 1);
		a[tmp+1] = w;
		
		for (int k = 1; k <= 6; ++k) {
			if (7 * k - w >= array[i-1]) {
				a[tmp] = k;
				break;
			}
		}
		tmp = tmp + 2;
	}
	if (a[0] > a[2]) {
		max_line = a[0];
	}
	else {
		max_line = a[2];
	}
	if (max_line > a[4]) {
		max_line = max_line;
	}
	else {
		max_line = a[4];
	}
	
	
	cout << resetiosflags(ios::right);                                         //!!�����Ҫright�������left���룬��Ҫ������֮�����һ���������

	for (int c = 1; c <= 5; c = c + 2) { //��һ�д�ӡ���
		
		switch (a[c]) {
			case 0:
				cout <<  setiosflags(ios::left)<<setw(4)  << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			case 1:
				cout << setw(4 * 1) << setfill(' ') << ' ';
				cout << setiosflags(ios::left) << setw(4)  << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setiosflags(ios::left) << setw(4) << i;
				}
				break;
			case 2:
				cout << setw(4 * 2) << setfill(' ') << ' ';
				cout << setw(4) << setiosflags(ios::left) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			case 3:
				cout << setw(4 * 3) << setfill(' ') << ' ';
				cout <<setiosflags(ios::left) <<setw(4) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setiosflags(ios::left) << setw(4) << i;
				}
				break;
			case 4:
				cout << setw(4 * 4) << setfill(' ') << ' ';
				cout << setw(4) << setiosflags(ios::left) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			case 5:
				cout << setw(4 * 5) << setfill(' ') << ' ';
				cout << setw(4) << setiosflags(ios::left) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			case 6:
				cout << setw(4 * 6) << setfill(' ') << ' ';
				cout << setw(4) << setiosflags(ios::left) << 1;
				for (int i = 2; i <= 7 - a[c]; ++i) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				break;
			default:
				break;
		}
		cout << setw(4) << setfill(' ')<<' ';
	}
	cout << endl;
	for (line = 2; line <= max_line; ++line) {//֮��ļ���
		for (int c = 1; c <= 5; c = c + 2) {//ÿһ����
			for (int i = 7 * (line - 1) - a[c]+1; i <= 7 * line - a[c];++i) {
				if (i <= array[month3 - 3 + (c / 2)]) {
					cout << setw(4) << setiosflags(ios::left) << i;
				}
				else {
					cout << setw(4) << setfill(' ') << ' ';
				}
				if (i == 7 * line - a[c]) {
					break;
				}
			}
			cout << setw(4) << setfill(' ') << ' ';
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main()
{
	int meigeyue[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//ÿ���µ�����
	int year = 0, month = 0, day = 0;

	cout << "���������[1900-2100]" << endl;
	cin >> year;
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {//����-2����29��
		++meigeyue[1];
	}
	cout << year << "�������:" << endl;
	cout << endl;
	print_title(3);
	print_days(year, 3, meigeyue);
	print_title(6);
	print_days(year, 6, meigeyue);
	print_title(9);
	print_days(year, 9, meigeyue);
	print_title(12);
	print_days(year, 12, meigeyue);
	
	cout<<endl; 
	
	return 0;
}
