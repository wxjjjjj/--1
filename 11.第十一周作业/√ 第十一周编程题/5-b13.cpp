/*�ƿ� ��𪾧 2353761*/
#include<iostream>
#include <time.h> //��������� 
#include <cstdio>
#include <conio.h> 
#include <windows.h> //����GetStdHandle����
using namespace std;
#define maxrow 10
#define maxcolumn 26

void number_of_lei(char array[][maxcolumn])
{
	int number = 0;
	for (int k = 1; k < maxrow-1; ++k) {
		
		for (int j = 1; j < maxcolumn-1; ++j) {
			
			if (array[k][j] != '*') {
				for (int q = k - 1; q <= k + 1; ++q) {
					
					for (int p = j - 1; p <= j + 1; ++p) {
						if (array[q][p] == '*') {
							++number;
						}
					}
				}
				array[k][j] = '0' + number;
				number = 0;
			}
			
		}
	}
	
	//��������߽��ĸ���
	if (array[0][0] != '*') {
		if (array[0][1] == '*') {
			++number;
		}
		if (array[1][1] == '*') {
			++number;
		}
		if (array[1][0] == '*') {
			++number;
		}
		array[0][0] = '0' + number;
		number = 0;
	}
	if (array[0][25] != '*') {
		if (array[0][24] == '*') {
			++number;
		}
		if (array[1][24] == '*') {
			++number;
		}
		if (array[1][25] == '*') {
			++number;
		}
		array[0][25] = '0' + number;
		number = 0;
	}
	if (array[9][25] != '*') {
		if (array[9][24] == '*') {
			++number;
		}
		if (array[8][24] == '*') {
			++number;
		}
		if (array[8][25] == '*') {
			++number;
		}
		array[9][25] = '0' + number;
		number = 0;
	}
	if (array[9][0] != '*') {
		if (array[8][0] == '*') {
			++number;
		}
		if (array[8][1] == '*') {
			++number;
		}
		if (array[9][1] == '*') {
			++number;
		}
		array[9][0] = '0' + number;
		number = 0;
	}
	
	//����ʣ��߽��
	for (int v = 1; v < maxcolumn - 1; ++v) {
		if (array[0][v] != '*') {
			for (int g = 0; g <= 1; ++g) {
				for (int h = v - 1; h <= v + 1; ++h) {
					if (array[g][h] == '*') {
						++number;
					}
				}
			}
			array[0][v] = '0' + number;
			number = 0;
		}
	}
	for (int v = 1; v < maxcolumn - 1; ++v) {
		if (array[9][v] != '*') {
			for (int g = 8; g <= 9; ++g) {
				for (int h = v - 1; h <= v + 1; ++h) {
					if (array[g][h] == '*') {
						++number;
					}
				}
			}
			array[9][v] = '0' + number;
			number = 0;
		}
	}
	for (int v = 1; v < maxrow - 1; ++v) {
		if (array[v][0] != '*') {
			for (int g = 0; g <= 1; ++g) {
				for (int h = v - 1; h <= v + 1; ++h) {
					if (array[h][g] == '*') {
						++number;
					}
				}
			}
			array[v][0] = '0' + number;
			number = 0;
		}
	}
	for (int v = 1; v < maxrow - 1; ++v) {
		if (array[v][25] != '*') {
			for (int g = 24; g <= 25; ++g) {
				for (int h = v - 1; h <= v + 1; ++h) {
					if (array[h][g] == '*') {
						++number;
					}
				}
			}
			array[v][25] = '0' + number;
			number = 0;
		}
	}
	
	for (int v = 0; v < maxrow; ++v) {
		for (int g = 0; g < maxcolumn; ++g) {
			cout << array[v][g] << ' ';
		}
		cout << endl;
	}

	return;
}

int main()
{
	char array[maxrow][maxcolumn];
	/* srand������������α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ���
	*/
	srand((unsigned int)(time(0)));
	//�ַ������ʼ��
	for (int k = 0; k < maxrow; ++k) {
		for (int j = 0; j < maxcolumn; ++j) {
			array[k][j] = { '0' };
		}
	}
	/* �������50����*/
	int count=0;
	while (1) {
		int y = rand() % maxrow -1;
		int x = rand() % maxcolumn - 1;
		if (x % 2 != 0) {
			x = x - 1; //x������ż��
		}
		if (x >= 0 && x < 26 && y >= 0 && y < 10) {
			if (array[y][x] != '*') {
				array[y][x] = '*';
				++count;
			}
		}
		if (count == 50) {
			break;
		}
	}//���Ѿ����ɺ�
	
	number_of_lei(array);
	cout << endl;
	return 0;
}
