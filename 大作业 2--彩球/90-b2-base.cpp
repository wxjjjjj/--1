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
���ڲ����鷽ʽʵ�ֵĸ����� ����ABC*/


//�����ڲ�������
void array_A(int hang, int lie, int array[][9], int number_ball)
{
	int x, y, count = 0, color;
	//����ֲ�5�������ɫ�������־ʹ��������ɫ1-7��7����ɫ
	while (1) {
		color = rand() % 7 + 1;
		x = rand() % hang;
		y = rand() % lie;
		if (array[x][y] == 0) {
			array[x][y] = color;
			count++;
		}
		if (count == number_ball) {
			break;
		}
	}
	return;
}
//��ӡ����
void print_array(int hang, int lie, int array[][9], int visited[][9], int gongnenghao)
{
	//�ȴ�ӡ��һ��
	cout << "  |  ";
	for (int i = 1; i <= lie; ++i) {
		cout << i << "  ";
	}
	cout << endl;
	cout << "--+-";
	for (int i = 1; i <= lie; ++i) {
		cout << "---";
	}
	cout << endl;
	for (int i = 0; i < hang; ++i) {
		cout << char('A' + i) << " |  ";
		for (int j = 0; j < lie; j++) {
			if (array[i][j] != 0 && gongnenghao != 3 || visited[i][j] != 0 && gongnenghao == 3) {//���ܺ�3��Ϊ�ƶ�·��0��ɫ�õ�/���ܺ�1&2�ȼ۹�
				int x, y;
				cct_getxy(x, y);
				cct_showch(x, y, char('0' + array[i][j]), COLOR_HYELLOW, array[i][j]);
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cout << "  ";
			}
			else {
				cout << array[i][j] << "  ";
			}
		}
		cout << endl;
	}
	return;
}
//�������������������
void generation_of_3_ball(int ball[])
{
	//cout << endl;
	//cout << "������3���������ɫ�ֱ���: ";
	for (int i = 0; i < 3; ++i) {
		ball[i]=rand() % 7 + 1;
		cout << ball[i] << ' ';
	}
	cout << endl;
	return;
}
//�ƶ�������ĸ��¡��޸�
void change_array_and_print(int src_x, int src_y, int dst_x, int dst_y,int array[][9],int hang,int lie,int ball[],int*sum_score)
{
	int tmp,count=0, tmp_score;
	tmp=array[src_x][src_y];
	array[src_x][src_y] = 0;
	array[dst_x][dst_y] = tmp;
	tmp_score=get_score(array, sum_score, hang, lie,ball,1);//��дһ���ۼƵ÷ֵĺ���
	print_array(hang, lie, array, array, 1);
	cout << "���ε÷֣�" << tmp_score << "  �ܵ÷֣�" << *sum_score << endl;
	
	return;
}
//�����ƶ�ָ��
void input_move_instruction(int src, int dst, int array[][9], int hang, int lie, int gongnenghao, int* sum_score)
{
	int x, y, ball[3] = { 0 };
	char str1[3] = { 0 }, str2[3] = { 0 };
	cout << endl;
	cout << "������3���������ɫ�ֱ���: ";
	generation_of_3_ball(ball);
	while (1) {
		cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
		cct_getxy(x, y);
		judge_input(str1, hang, lie, x, y);
		if (array[str1[0] - 'A'][str1[1] - '0' - 1] == 0) {
			cout << "��ʼλ��Ϊ�գ�����������. " << endl;
		}
		else {
			cout << "����Ϊ" << str1[0] << "��" << str1[1] << "�� " << endl;
			break;
		}
	}
	while (1) {
		cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
		cct_getxy(x, y);
		judge_input(str2, hang, lie, x, y);
		if (array[str2[0] - 'A'][str2[1] - '0' - 1] != 0) {
			cout << "Ŀ��λ�÷ǿգ�����������. " << endl;
		}
		else {
			cout << "����Ϊ" << str2[0] << "��" << str2[1] << "�� " << endl;
			break;
		}
	}
	//Ѱ��·������
	int visited[9][9] = { 0 };
	int result = 0;
	search_for_path(array, int(str1[0] - 'A'), int(str1[1] - '0' - 1), int(str2[0] - 'A'), int(str2[1] - '0' - 1), hang, lie, visited, &result, gongnenghao, int(str1[0] - 'A'), int(str1[1] - '0' - 1));
	if (gongnenghao != 2 && result != 0) {
		change_array_and_print(int(str1[0] - 'A'), int(str1[1] - '0' - 1), int(str2[0] - 'A'), int(str2[1] - '0' - 1), array, hang, lie, ball, sum_score);
	}
	result = 0;
	return;
}
//�ж��ƶ�����ָ��
void judge_input(char str[], int hang, int lie, int x, int y)
{
	while (1) {
		cin.getline(str, 3);
		if ((str[0] - 'A' >= 0 && str[0] - 'A' < hang) || (str[0] - 'a' >= 0 && str[0] - 'a' < hang)) {
			if (str[0] >= 'a' && str[0] <= 'z') {
				str[0] = str[0] - 32;
			}//ת��д�洢
			if (str[1] - '0' >= 1 && str[1] - '0' <= lie) {
				break;
			}
		}
		cct_gotoxy(0, y + 1);
		cout << "�����������������";
		cin.clear();
		cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 8); // ����
		cct_gotoxy(x, y);
	}
	return;
}
