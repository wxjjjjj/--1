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


/*���ļ���
�� cmd ͼ�ν��淽ʽʵ�ֵĸ�����  ����DEFG*/

//�ν�--���س���ͼ����ʾ
void draw_border_pause()
{
	int x, y;
	cct_getxy(x, y);
	cct_gotoxy(x, y + 1);
	cout << "���س�����ʾͼ��...";

	while (_getch() != '\r')
		;
	cct_cls();
}
//���߿��޷ָ��ߣ�
void draw_border(int array[][9], int hang, int lie)
{//��Ϊ�����ˣ����Ի������Բο������ǣ�0��0��
	cct_cls();
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "�X", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�[", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int j = 0; j < hang; ++j) {
		cct_getxy(x, y);
		cct_gotoxy(0, y + 1);
		cct_getxy(x, y);
		cct_showstr(0, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < lie; ++i) {
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "  ";
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(0, y+1, "�^", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�a", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	//����
	cct_gotoxy(2, 1);
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; ++j) {
			cct_getxy(x, y);
			if (array[y - 1][x/2 - 1] != 0) {
				cct_showstr(x, y, "��", array[y - 1][x/2 - 1], COLOR_HWHITE, 1, -1);
			}
			else {
				cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
				cout << "  ";
			}
		}
		cct_gotoxy(2, y+1);
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	return;
}
//���߿��зָ��ߣ�
void draw_border_pro(int array[][9], int hang, int lie)
{
	cct_cls();
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "�X", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie - 1; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�j", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(x, y, "�[", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int j = 0; j < hang-1; ++j) {
		cct_getxy(x, y);
		cct_gotoxy(0, y + 1);
		cct_getxy(x, y);
		cct_showstr(0, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < lie; ++i) {
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "  ";
			cct_getxy(x, y);
			cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		}
		cct_getxy(x, y);
		cct_gotoxy(0, y + 1);
		cct_getxy(x, y);
		cct_showstr(0, y, "�d", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < lie - 1; ++i) {
			cct_getxy(x, y);
			cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
			cct_getxy(x, y);
			cct_showstr(x, y, "�p", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�g", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_gotoxy(0, y + 1);
	cct_getxy(x, y);
	cct_showstr(0, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie; ++i) {
		cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
		cout << "  ";
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(0, y + 1, "�^", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie-1; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�m", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(x, y, "�a", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	//����
	cct_gotoxy(2, 1);
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; ++j) {
			cct_getxy(x, y);
			if (array[(y - 1)/2][(x-2)/4] != 0) {
				cct_showstr(x, y, "��", array[(y - 1) / 2][(x - 2) / 4], COLOR_HWHITE, 1, -1);
				cct_getxy(x, y);
				cct_gotoxy(x + 2, y);
			}
			else {
				cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
				cout << "  ";
				cct_getxy(x, y);
				cct_gotoxy(x + 2, y);
			}
		}
		cct_gotoxy(2, y + 2);
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	return;
}
//�÷ֿ�
void draw_score()
{
	int x, y, X, Y, x1, y1;
	cct_gotoxy(45, 0);
	cct_getxy(x, y);
	cct_showstr(x, y, "�X", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 5; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_getxy(X, Y);
	cct_showstr(x, y, "�[", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(45, y + 1, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(x, y, "�÷֣�", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x1, y1);
	cct_showstr(x1, y1, "0", COLOR_HWHITE, COLOR_BLACK, 1, -1);             //���µ÷ֵ�����(53,1)
	cct_getxy(x, y);
	while (x < X) {
		cct_showstr(x, y, " ", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
	}
	cct_showstr(X, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(45, y + 1, "�^", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 5; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�a", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	return;
}
//���������и�����ɫ�������
int cal_number(int array[][9], int hang,int lie,int color)
{
	int count = 0;
	for (int i = 0; i < hang; ++i) {
		for (int j = 0; j < lie; j++) {
			if (array[i][j] == color) {
				count++;
			}
		}
	}
	return count;
}
//ͳ�ƿ�
void draw_sort(int array[][9],int hang,int lie)
{
	int x, y;
	cct_showstr(45, 8, "�X", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 12; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�[", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int j = 0; j < 8; ++j) {
		cct_getxy(x, y);
		cct_gotoxy(45, y + 1);
		cct_getxy(x, y);
		cct_showstr(45, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < 12; ++i) {
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "  ";
		}
		cct_getxy(x, y);
		cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(45, y + 1, "�^", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 12; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�a", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_showstr(47, 9, "��", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << ':' << setw(2) << hang * lie-5<<"/("<< fixed << setprecision(2) << double(hang*lie-5)/hang/lie*100<<"%)" << "  ����-0";
	for (int i = 1; i < 8; ++i) {
		cct_showstr(47, 9+i, "��", i, COLOR_HWHITE, 1, -1);
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cct_getxy(x, y);
		cct_gotoxy(x, y);
		cout << ':' << setw(2) << cal_number(array,hang,lie,i) << "/(" << fixed << setprecision(2)<< double(cal_number(array, hang, lie, i)) / hang / lie * 100 << "%)" << "  ����-0";
	}
	return;
}
//����ܳ�ʼ
void draw_real_time(int ball[],int array[][9],int hang,int lie) //ʵʱ����
{
	draw_score();//�÷ֿ�
	int x, y;
	cct_showstr(45, 4, "�X", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 2; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�j", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(x, y, "�[", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int j = 0; j <1; ++j) {
		cct_getxy(x, y);
		cct_gotoxy(45, y + 1);
		cct_getxy(x, y);
		cct_showstr(45, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		for (int i = 0; i < 3; ++i) {
			cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
			cout << "  ";
			cct_getxy(x, y);
			cct_showstr(x, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		}
	}
	cct_getxy(x, y);
	cct_showstr(45, y + 1, "�^", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < 2; ++i) {
		cct_getxy(x, y);
		cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
		cct_getxy(x, y);
		cct_showstr(x, y, "�m", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	}
	cct_getxy(x, y);
	cct_showstr(x, y, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	cct_getxy(x, y);
	cct_showstr(x, y, "�a", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	//����
	for (int i = 0; i < 3; ++i) {
		cct_showstr(47 + 4 * i,5 , "��", ball[i], COLOR_HWHITE, 1, -1);
	}
	draw_sort(array,hang,lie);
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	
	return;
}
//������
void move_by_mouse(int hang,int lie,int array[][9],int gongnenghao)
{
	cct_setcursor(CURSOR_INVISIBLE);
	int x, y, flag_y = 0, flag_x = 0, flag_first = 0, flag_second = 0, array_src_x = 0, array_src_y = 0, array_dst_x = 0, array_dst_y = 0,sum_score=0;
	cct_getxy(x, y);
	cct_gotoxy(0, y);
	cout << "����ƶ����������ѡ���Ҽ������˳�" << endl;
	cct_enable_mouse();
	cout << "[��ǰ���] ";
	cct_getxy(x, y);
	int MX, MY, MAction, keycode1, keycode2,state_= CCT_MOUSE_EVENT,ball[3] = { 0 };
	if (gongnenghao == 2) {//���÷ֿ�ͳ�ƿ򡢺�Ԥ����� //cct_gotoxy(45, 0);//cct_gotoxy(0, 22);
		for (int i = 0; i < 3; ++i) {
			ball[i] = rand() % 7 + 1;
		}
		draw_real_time(ball, array, hang, lie);
	}
	while (1) {
		cct_gotoxy(x, y);
		state_ = cct_read_keyboard_and_mouse(MX, MY, MAction, keycode1, keycode2);
		for (int i = 1; i <= hang; ++i) {
			if (MY == 2 * i - 1) {
				flag_y = i;
			}
		}
		for (int i = 1; i <= lie; ++i) {
			if (MX == 4 * i - 2|| MX == 4 * i - 1) {
				flag_x = i;
			}
		}
		if (flag_y == 0 || flag_x == 0) {
			cout << "λ�÷Ƿ�";
		}
		else {
			cout << char('A' + flag_y-1) << " ��"<< flag_x << " ��";
			if (MAction == MOUSE_LEFT_BUTTON_CLICK&& array[flag_y - 1][flag_x - 1]!=0&&flag_first==0) {
				cct_showstr(4 * flag_x-2, 2*flag_y-1, "��", array[flag_y - 1][flag_x - 1], COLOR_HWHITE, 1, -1);    //ѡ���˾Ͳ�����ѡ�����ģ�����
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				flag_first = 1;
				array_src_x = flag_y - 1;
				array_src_y = flag_x - 1;
			}
			else if (MAction == MOUSE_LEFT_BUTTON_CLICK && array[flag_y - 1][flag_x - 1] == 0 && flag_second == 0) {
				flag_second = 1;
				array_dst_x = flag_y - 1;
				array_dst_y = flag_x - 1;
			}
		}
		if (MAction == MOUSE_RIGHT_BUTTON_CLICK) {
			break;
		}
		flag_x = 0;
		flag_y = 0;
		if (flag_first == 1 && flag_second == 1) {
			int visited[9][9] = { 0 },result = 0;
			search_for_path(array, array_src_x, array_src_y, array_dst_x, array_dst_y, hang, lie, visited, &result, 4, array_src_x, array_src_y);
			if (result == 1) {
				int visited_1[9][9] = { 0 }, result_1 = 0;
				search_for_path(array, array_src_x, array_src_y, array_dst_x, array_dst_y, hang, lie, visited_1, &result_1, 9, array_src_x, array_src_y);//��ʼarray[str[0] - 'A'][str[1] - '0' - 1]
				if (gongnenghao == 2) {
					update_array(array, flag_y, flag_x, flag_first, flag_second, array_src_x, array_src_y, array_dst_x, array_dst_y, hang, lie,ball,&sum_score);
					if (judge_full(array, hang, lie)) {
						cct_gotoxy(0, 21);
						break;
					}
				}
			}
			else {
				if (gongnenghao == 2) {
					break;
				}
			}
			if (gongnenghao == 1) {
				break;
			}
		}
	}
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_disable_mouse();
}
//���±�����ֵ�����µ÷֡���ɫ����������ͳ��
void update_array(int array[][9], int& flag_y, int& flag_x, int& flag_first, int& flag_second, int& array_src_x, int& array_src_y, int& array_dst_x, int& array_dst_y,int hang,int lie,int ball[],int *sum_score)
{
	int tmp, count = 0;
	tmp = array[array_src_x][array_src_y];
	array[array_src_x][array_src_y] = 0;
	array[array_dst_x][array_dst_y] = tmp;
	get_score(array, sum_score, hang, lie, ball,8);//��дһ���ۼƵ÷ֵĺ���
	for (int i = 0; i < 3; ++i) {
		ball[i] = rand() % 7 + 1;
	}
	for (int i = 0; i < 3; ++i) {
		cct_showstr(47 + 4 * i, 5, "��", ball[i], COLOR_HWHITE, 1, -1);
	}
	flag_y = 0;
	flag_x = 0;
	flag_first = 0;
	flag_second = 0;
	array_src_x = 0;
	array_src_y = 0;
	array_dst_x = 0;
	array_dst_y = 0;
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cct_gotoxy(53, 1);
	cout << *sum_score;
	cct_showstr(47, 9, "��", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << ':' << setw(2) << cal_number(array, hang, lie, 0) << "/(" << fixed << setprecision(2) << double(cal_number(array, hang, lie, 0)) / hang / lie * 100 << "%)";
	for (int i = 1; i < 8; ++i) {
		cct_showstr(47, 9 + i, "��", i, COLOR_HWHITE, 1, -1);
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		int x, y;
		cct_getxy(x, y);
		cct_gotoxy(x, y);
		cout << ':' << setw(2) << cal_number(array, hang, lie, i) << "/(" << fixed << setprecision(2) << double(cal_number(array, hang, lie, i)) / hang / lie * 100 << "%)";
	}
	cct_setcolor(COLOR_BLACK,COLOR_WHITE);
	return;
}
//�����ƶ�
void movement_ball(int array[][9], int src_x, int src_y, int dst_x, int dst_y, int result, int gongnenghao,int _x,int _y)
{
	if (result==0&&(gongnenghao==9|| gongnenghao == 10|| gongnenghao == 11|| gongnenghao == 12)) {//�ƶ�
		//����
		if (gongnenghao == 10) {
			for (int y = 2 * src_x + 1; y >= 2 * dst_x + 1; y--) {
				int x = 4 * src_y + 2;
				if (y % 2 == 1) {
					cct_showstr(x, y + 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
				}
				else {
					cct_showstr(x, y + 1, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
				}
				cct_showstr(x, y, "��", array[_x][_y], COLOR_HWHITE, 1, -1);
				Sleep(100);
			}
		}
		else if (gongnenghao == 11) {
			for (int x = 4 * src_y + 2; x <= 4 * dst_y + 2; x++) {//����
				int y = 2 * src_x + 1;
				if (x % 2 == 0) {
					if (x % 4 == 0) {
						cct_showstr(x - 2, y, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
					}
					else {
						cct_showstr(x - 2, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
					}
				}
				else {
					cct_showstr(x - 2, y, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
				}
				cct_showstr(x, y, "��", array[_x][_y], COLOR_HWHITE, 1, -1);
				Sleep(100);
			}
		}
		else if (gongnenghao == 12) {
			for (int x = 4 * src_y + 2; x >= 4 * dst_y + 2; x--) {//����
				int y = 2 * src_x + 1;
				if (x % 2 == 0) {
					if (x % 4 == 0) {
						cct_showstr(x + 2, y, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
					}
					else {
						cct_showstr(x + 2, y, "�U", COLOR_HWHITE, COLOR_BLACK, 1, -1);
					}
				}
				else {
					cct_showstr(x + 2, y, " ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
				}
				cct_showstr(x, y, "��", array[_x][_y], COLOR_HWHITE, 1, -1);
				Sleep(100);
			}
		}
		else if (gongnenghao == 9) {
			//���� 
			for (int y = 2 * src_x + 1; y <= 2 * dst_x + 1; y++) {
				int x = 4 * src_y + 2;
				if (y % 2 == 1) {
					cct_showstr(x, y - 1, "�T", COLOR_HWHITE, COLOR_BLACK, 1, -1);
				}
				else {
					cct_showstr(x, y - 1, "  ", COLOR_HWHITE, COLOR_HWHITE, 1, -1);
				}
				cct_showstr(x, y, "��", array[_x][_y], COLOR_HWHITE, 1, -1);
				Sleep(100);
			}
		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_gotoxy(0, 20);
	}
	return;
}
