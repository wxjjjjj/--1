/* �ƿ� 2353761 ��𪾧*/
#include"cmd_console_tools.h"
#include"90-b2.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
using namespace std;

/*���ļ����ܣ�
��һЩ�ڲ�����/ͼ�η�ʽ���õĺ��������жϽ�����
���ù��ú���--
1.���е�����
2.С���жϽ����ȴ�����end
3.ÿ������ִ����һ�κ���Ҫ��array�ָ�0
4.·����������
5.�ж������Ƿ���
6.����÷�*/


//����÷�
int get_score(int array[][9], int* sum_score, int hang, int lie, int ball[], int gongnenghao)
{
	/*�÷ֹ���ֻ�к��ţ����ų�������ſ������÷�,���������ü��ֹ�*/
	int number1[8] = { 0 };
	for (int i = 0; i < 8; ++i) {
		number1[i] = cal_number(array, hang, lie, i);
	}
	int k = 0, m = 0, x = 0, y = 0, tmp = 0;;
	int tmp_score = 0, count = 0;
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; j++) {
			if (array[i][j] != 0) {
				//�����ҿ���������
				for (k = j; k >= 0; --k) {
					if (array[i][k] != array[i][j]) {
						k++;
						break;
					}
					++count;
				}
				for (m = j + 1; m < lie; ++m) {
					if (array[i][m] != array[i][j]) {
						m--;
						break;
					}
					++count;
				}
				if (count >= 5) {//��������������k��¼����߽磬m��¼�ұ߽�
					tmp_score = tmp_score + count;
					for (int q = k; q <= m; ++q) {
						array[i][q] = 0;
						if (gongnenghao == 8) {
							cct_showstr(4 * q + 2, 2 * i + 1, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
						}
					}
					count = 0;
				}
				else {
					count = 0;
					//�����ҿ���������
					for (k = i; k >= 0; --k) {
						if (array[k][j] != array[i][j]) {
							k++;
							break;
						}
						++count;
					}
					for (m = i + 1; m < hang; ++m) {
						if (array[m][j] != array[i][j]) {
							m--;
							break;
						}
						++count;
					}
					if (count >= 5) {
						tmp_score = tmp_score + count;
						for (int q = k; q <= m; ++q) {
							array[q][j] = 0;
							if (gongnenghao == 8) {
								cct_showstr(4 * j + 2, 2 * q + 1, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
							}
						}
						count = 0;
					}
					else {
						count = 0;
					}
				}
			}
		}
	}
	*sum_score = *sum_score + tmp_score;
	if (gongnenghao == 8 && tmp_score != 0) {
		cct_showstr(47, 9, "��", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << ':' << setw(2) << cal_number(array, hang, lie, 0) << "/(" << fixed << setprecision(2) << double(cal_number(array, hang, lie, 0)) / hang / lie * 100 << "%)" << "  ����-0";
		for (int i = 1; i < 8; ++i) {
			cct_showstr(47, 9 + i, "��", i, COLOR_HWHITE, 1, -1);
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			int x, y;
			cct_getxy(x, y);
			cct_gotoxy(x, y);
			cout << ':' << setw(2) << cal_number(array, hang, lie, i) << "/(" << fixed << setprecision(2) << double(cal_number(array, hang, lie, i)) / hang / lie * 100 << "%)" << "  ����-" << setw(2) << number1[i] - cal_number(array, hang, lie, i) << "  ";
		}
	}
	if (tmp_score == 0) {
		while (tmp < 3 && !judge_full(array, hang, lie)) {
			x = int(fabs(rand() % hang));
			y = int(fabs(rand() % lie));
			if (array[x][y] == 0) {
				array[x][y] = ball[tmp];
				if (gongnenghao == 8) {
					cct_showstr(4 * y + 2, 2 * x + 1, "��", array[x][y], COLOR_HWHITE, 1, -1);
				}
				++tmp;
			}
		}
	}
	return tmp_score;
}
//�ж�array����
bool judge_full(int array[][9], int hang, int lie)
{
	int flag = 0;
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < lie; j++) {
			if (array[i][j] == 0) {
				flag++;
			}
		}
	}
	if (flag == 0) {//˵��ȫ�Ƿ��㣬����
		return 1;
	}
	else {
		return 0;
	}
}
//�����С���
void Input(int* hang, int* lie)
{
	cct_cls();
	while (1) {
		cout << "����������(7-9)��" << endl;
		cin >> *hang;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
		}
		else {
			cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
			if (*hang >= 7 && *hang <= 9) {
				while (1) {
					cout << "����������(7-9)��" << endl;
					cin >> *lie;
					if (cin.good() == 0) {
						cin.clear();
						cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
					}
					else {
						cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
						if (*lie >= 7 && *lie <= 9) {
							break;
						}
					}
				}
				break;
			}
		}
	}
	return;
}
//�ν�--����end������һС��
void print()
{
	int x, y;
	cct_getxy(x, y);
	cct_gotoxy(0, y + 1);
	cout << "��С�������������End����...";
	char str[4] = { 0 };
	cct_getxy(x, y);
	while (1) {
		cin.getline(str, 4);
		if (str[0] == 'e' || str[0] == 'E') {
			if (str[1] == 'n' || str[1] == 'N') {
				if (str[2] == 'd' || str[2] == 'D') {
					break;
				}
			}
		}
		cct_gotoxy(0, y+1);
		cout << "�����������������";
		cin.clear();
		cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 4); // ����
		cct_gotoxy(x, y);
	}
	return;
}
//��ʼ���������飬ȫ��Ϊ0
void chushihua_array(int array[][9],int hang,int lie)//��ʼ��
{
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; ++j) {
			array[i][j] = 0;
		}
	}
	return;
}
//·������
void search_for_path(int array[][9], int src_x, int src_y, int dst_x, int dst_y, int hang, int lie, int visited[][9], int* result, int gongnenghao, int x, int y)//��ʼarray[str[0] - 'A'][str[1] - '0' - 1]
{
	visited[src_x][src_y] = int('*' - '0');//��ʾ�Ѿ����ʹ�
	if (src_x == dst_x && src_y == dst_y) {
		*result = 1;
		if (gongnenghao == 2) {
			cout << "���ҽ�����飺" << endl;//cout << "�ҵ���";
			print_array(hang, lie, visited, visited, 2);
			cout << "�ƶ�·��(��ͬɫ��ʶ)��" << endl;
			print_array(hang, lie, array, visited, 3);
		}
		else if(gongnenghao==3){
			cout << "�ƶ��������(��ͬɫ��ʶ)��" << endl;
		}
		return;
	}
	if (array[src_x + 1][src_y] == 0 && src_x + 1 < hang && visited[src_x + 1][src_y] == 0) {//��������g=9
		movement_ball(array, src_x, src_y, src_x+1, src_y,*result,gongnenghao,x,y);                 //!!
		search_for_path(array, src_x + 1, src_y, dst_x, dst_y, hang, lie, visited, result, gongnenghao, x, y);
		movement_ball(array, src_x+1, src_y, src_x, src_y, *result, gongnenghao+1,x,y);// ���ܵĻ���
	}
	if (array[src_x - 1][src_y] == 0 && src_x - 1 >= 0 && visited[src_x - 1][src_y] == 0) {//��������g=10
		movement_ball(array, src_x, src_y, src_x - 1, src_y, *result, gongnenghao+1,x,y);
		search_for_path(array, src_x - 1, src_y, dst_x, dst_y, hang, lie, visited, result, gongnenghao, x, y);
		movement_ball(array, src_x-1, src_y, src_x, src_y, *result, gongnenghao,x,y);
	}
	if (array[src_x][src_y + 1] == 0 && src_y + 1 < lie && visited[src_x][src_y + 1] == 0) {//��������g=11
		movement_ball(array, src_x, src_y, src_x , src_y+1, *result, gongnenghao+2,x,y);
		search_for_path(array, src_x, src_y + 1, dst_x, dst_y, hang, lie, visited, result, gongnenghao, x, y);
		movement_ball(array, src_x, src_y+1, src_x, src_y, *result, gongnenghao+3,x,y);
	}
	if (array[src_x][src_y - 1] == 0 && src_y - 1 >= 0 && visited[src_x][src_y - 1] == 0) {//��������g=12
		movement_ball(array, src_x, src_y, src_x, src_y - 1, *result, gongnenghao+3,x,y);
		search_for_path(array, src_x, src_y - 1, dst_x, dst_y, hang, lie, visited, result, gongnenghao, x, y);
		movement_ball(array, src_x, src_y-1, src_x, src_y, *result, gongnenghao+2,x,y);
	}
	//ÿ�λ��ݾͻᵽ����
	if (src_x == x && src_y == y && *result == 0) {
		int tmpx,tmpy;
		cct_getxy(tmpx, tmpy);
		cct_gotoxy(0, tmpy + 1);
		cout << "�Ҳ������·��" << endl;
	}
	return;
}