/*��𪾧 2353761 �ƿ�*/
/*2352647 �Ϲ�˼�� 2351323 ��꿭Z 2350284 �ſ��� 2350338 ͯ��ҵ 2350987 ������ */
#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>

#define maxrow 10
#define maxcolumn 26

void number_of_lei(char array[][maxcolumn])
{
	int number = 0;
	for (int k = 1; k < maxrow - 1; ++k) {

		for (int j = 1; j < maxcolumn - 1; ++j) {

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
	return;

}

int main()
{
	char array[maxrow][maxcolumn],array1[maxrow][maxcolumn];
	int number = 0,j=0;
	char c;
	for (int i = 0; i <maxrow ; ++i) {
		while (1) {
			c = getchar();
			if (c == '*' || (c >= '0' && c <= '9')) {
				array[i][j] = c;
				++j;
			}
			if(j==maxcolumn){
				j = 0;
				break;
			}
		}
	}//����
	

	//�жϴ���1--��*��
	for (int i = 0; i < maxrow; ++i) {
		for (int j = 0; j < maxcolumn; ++j) {
			if (array[i][j] == '*') {
				++number;
			}

		}
	}
	if (number != 50) {
		printf("����1\n");
		return 0;
	}

	//�жϴ���2
	for (int i = 0; i < maxrow; ++i) {
		for (int j = 0; j < maxcolumn; ++j) {
			if (array[i][j] == '*') {
				array1[i][j] = array[i][j];
			}

		}
	}
	number_of_lei(array1);
	for (int i = 0; i < maxrow; ++i) {
		for (int j = 0; j < maxcolumn; ++j) {
			if (array[i][j] !=array1[i][j]) {
				printf("����2\n");
				return 0;
			}

		}
	}

	//��ȫ�³�~
	printf("��ȷ\n");
	return 0;
}
