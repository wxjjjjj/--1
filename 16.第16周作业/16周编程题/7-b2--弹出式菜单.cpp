/* 2353761 �ƿ� ��𪾧*/
#include"7-b2.h"
#include <iostream>
#include <conio.h>
#include"cmd_console_tools.h"
using namespace std;
/* 1���������ͷ�ļ�
   2����������ȫ�ֱ�����������̬ȫ�֣���������const��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */
/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */
//struct xxx {
  //  ...
//};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
***************************************************************************/
static void word_cut(const char menu[][MAX_ITEM_LEN],int end_line,int x1)
{
	int x, y;
	for (int j = 0; j < MAX_ITEM_LEN; ++j) {
		cct_getxy(x, y);
		if (int(menu[end_line - 1][j]) <= -2 && int(menu[end_line - 1][j]) >= -95) {//����
			if (x1 - 1 - x >= 2) {
				cout << menu[end_line - 1][j] << menu[end_line - 1][j + 1];
				j++;
			}
			else {
				break;
			}
		}
		else {
			if (x < x1) {
				cout << menu[end_line - 1][j];
			}
		}
	}
	return;
}
static void word_cut_pro(const struct PopMenu* original_para,const char menu[][MAX_ITEM_LEN], int end_line, int x1,int x2,int bg_color,int fg_color)
{
	int x, y,j;
	for ( j = 0; j < MAX_ITEM_LEN; ++j) {
		cct_getxy(x, y);
		if (int(menu[end_line - 1][j]) <= -2 && int(menu[end_line - 1][j]) >= -95) {//����
			if (x1 - 1 - x >= 2) {
				cout << menu[end_line - 1][j] << menu[end_line - 1][j + 1];
				j++;
			}
			else {
				cout << ' ';
				break;
			}

		}
		else {
			if (x < x1) {
				cout << menu[end_line - 1][j];
			}
		}
	}
	while (x < x1) {
		cct_showch(x, y, ' ', bg_color, fg_color, 1);
		++x;
	}
	cct_gotoxy(0, y + 1);
	cct_getxy(x, y);
	for (int k = j; k < MAX_ITEM_LEN; ++k) {
		if (menu[end_line - 1][k] != 0) {
			cout << menu[end_line - 1][k];
			cct_getxy(x, y);
		}
	}
	
	while (x < x2 ) {
		cct_showch(x, y, ' ',bg_color,fg_color, 1);
		++x;
	}
	
	return;
}
static void menu_roll(int line, const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para,int menu_real_high,int x1,int X,int Y,int key,int judge, int clos)
{
	int x, y;
	cct_setcolor(original_para->bg_color, original_para->fg_color);
	cct_gotoxy(original_para->start_x + 2, original_para->start_y + 1);
	if (key == KB_ARROW_DOWN) {
		for (int i = line - menu_real_high + 1; i <= line; ++i) {
			if (judge == 1) {
				word_cut(menu, i + 1, x1);
				cct_getxy(x, y);
				while (x < x1 - 1) {
					cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
					++x;
				}
				cct_gotoxy(original_para->start_x + 2, y + 1);
			}
			else {
				word_cut_pro(original_para, menu, i+1, clos + 1, x1-2, original_para->bg_color, original_para->fg_color);
				cct_getxy(x, y);
				cct_gotoxy(original_para->start_x + 2, y );
			}
			
		}
		cct_gotoxy(X, Y);
	}
	else {
		for (int i = line; i <= line - 1 + menu_real_high; ++i) {
			if (judge == 1) {
				word_cut(menu, i-1 , x1);
				cct_getxy(x, y);
				while (x < x1 - 1) {
					cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
					++x;
				}
				cct_gotoxy(original_para->start_x + 2, y +1);
			}
			else {
				word_cut_pro(original_para, menu, i -1, clos + 1, x1 - 2, original_para->bg_color, original_para->fg_color);
				cct_getxy(x, y);
				cct_gotoxy(original_para->start_x + 2, y);
			}
		}
		cct_gotoxy(X, Y);
	}
	
	return;
}
static void set_word_color(const struct PopMenu* original_para,int fg_color,int bg_color, int line, const char menu[][MAX_ITEM_LEN],int end_line,int x1)
{
	cct_setcolor(fg_color, bg_color);
	int x, y;
	cct_getxy(x, y);
	word_cut(menu, line, x1);
	cct_getxy(x, y);
	while (x < original_para->start_x + original_para->width) {
		cct_showch(x, y, ' ',fg_color, bg_color, 1);
		++x;
	}
	cct_gotoxy(original_para->start_x + 2, original_para->start_y + line);
	cct_setcursor(CURSOR_INVISIBLE);
	return;
}
static void set_word_color_pro(const struct PopMenu* original_para, int fg_color, int bg_color, int line, const char menu[][MAX_ITEM_LEN], int end_line, int x1,int clos)
{
	cct_setcolor(fg_color, bg_color);
	int x, y;
	cct_getxy(x, y);
	word_cut_pro(original_para, menu, line, clos+1,x1-2, fg_color, bg_color);
	cct_gotoxy(original_para->start_x + 2, original_para->start_y + line);
	cct_setcursor(CURSOR_INVISIBLE);
	return;
}
static int move_by_arrow(const struct PopMenu* original_para,int end_line, const char menu[][MAX_ITEM_LEN],int x1,int judge,int clos)
{
	char ch;
	int x= original_para->start_x + 2, y= original_para->start_y + 1,line=1,menu_real_high;
	if (original_para->high > end_line - 1) {
		menu_real_high = end_line - 1;
	}
	else {
		menu_real_high = original_para->high;
	}
	if (end_line == 1) {//�ղ˵��Ĵ���
		return 0;
	}
	cct_gotoxy(original_para->start_x+2, original_para->start_y+line);//��һ�����ڵ���
	if (judge == 1) {
		set_word_color(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1);
	}
	else {
		set_word_color_pro(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1, clos);
	}
	//ִ���귵��original_para->start_x + 2
	while (1) {
		if (_kbhit()) {//�����а������� ��_kbhit����ֵΪ1
			ch = _getch();
			if (int(ch) < 0) { 
				ch = _getch();
				cct_getxy(x, y);
				switch (int(ch)) {
					case KB_ARROW_UP:
						if (y == original_para->start_y + 1 && line == 1) {
							cct_gotoxy(x, y);
							break;
						}
						else if (y == original_para->start_y + 1 && line != 1) {
							cct_getxy(x, y);
							menu_roll(line, menu, original_para, menu_real_high, x1, x, y, KB_ARROW_UP,judge,clos);
							line--;
							if (judge == 1) {
								set_word_color(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1);
							}
							else {
								set_word_color_pro(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1, clos);
							}
							cct_gotoxy(x, y);
							break;
						}
						else {
							if (judge == 1) {
								set_word_color(original_para, original_para->bg_color, original_para->fg_color, line, menu, end_line, x1);
							}
							else {
								set_word_color_pro(original_para, original_para->bg_color, original_para->fg_color, line, menu, end_line, x1, clos);
							}							
							y--;
							line--;
							cct_gotoxy(x, y);
							if (judge == 1) {
								set_word_color(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1);
							}
							else {
								set_word_color_pro(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1, clos);
							}
							cct_gotoxy(x, y);
							break; // ��
						}
					case KB_ARROW_DOWN:
						if (y == original_para->start_y + menu_real_high && line == end_line - 1) {//(y == original_para->start_y + end_line-1)//original_para->high���ܻᳬ���˵���ʵ���������ʲ˵�ʵ�ʴ�ӡ�ĸ߶�Ϊ
							cct_gotoxy(x, y);
							break;
						}
						else if (y == original_para->start_y + menu_real_high && line != end_line - 1) {
							cct_getxy(x, y);
							menu_roll(line, menu, original_para, menu_real_high, x1, x, y, KB_ARROW_DOWN,judge, clos);
							line++;
							if (judge == 1) {
								set_word_color(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1);
							}
							else {
								set_word_color_pro(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1, clos);
							}
							cct_gotoxy(x, y);
							break;
						}
						else {
							if (judge == 1) {
								set_word_color(original_para, original_para->bg_color, original_para->fg_color, line, menu, end_line, x1);
							}
							else {
								set_word_color_pro(original_para, original_para->bg_color, original_para->fg_color, line, menu, end_line, x1, clos);
							}							
							y++;
							line++;
							cct_gotoxy(x, y);
							if (judge == 1) {
								set_word_color(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1);
							}
							else {
								set_word_color_pro(original_para, original_para->fg_color, original_para->bg_color, line, menu, end_line, x1, clos);
							}
							cct_gotoxy(x, y);
							break; // ��
						}
					default:
						break;
				}  //����ƶ�����
			}
			else if (int(ch) == 13) {//�س�
				cct_getxy(x, y);
				break;
			}
		}
	}
	return line;
}
static int cut_print(const struct PopMenu* original_para, const char menu[][MAX_ITEM_LEN],int x1)
{
	int cols, lines, buffer_cols, buffer_lines,end_line;
	cct_getconsoleborder(cols,  lines,buffer_cols,buffer_lines);//ֻ�õ�����cols
	cct_gotoxy(original_para->start_x + 2, original_para->start_y + 1);
	for (end_line = 1; menu[end_line - 1] != NULL && menu[end_line - 1][0] != '\0'; ++end_line) { ///������ע�������ֹ����������--endline�ǲ˵�ѡ�����+1
		if (end_line <= original_para->high) {
			cct_gotoxy(original_para->start_x, original_para->start_y + end_line);
			cout << "�U ";
			cct_gotoxy(original_para->start_x + 2, original_para->start_y + end_line);
			word_cut_pro(original_para, menu, end_line, cols + 1, x1, original_para->bg_color, original_para->fg_color);
			int x, y;
			cct_getxy(x, y);
			cct_gotoxy(x - 1, y);
			cout << "�U";
			cct_gotoxy(x , y);
			cout << ' ';
		}
	}
	int x, y;
	cct_getxy(x, y);
	cct_gotoxy(original_para->start_x, y);
	cout << "�^";
	cct_getxy(x, y);
	cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
	cct_gotoxy(x + 1, y);
	for (; x < cols; ++x) {
		cout << "�T";
		cct_getxy(x, y);
		cct_gotoxy(x + 1, y);
		cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
	}
	cct_gotoxy(0, y + 1);
	x = 0;
	while (x < x1-2) {
		cout << "�T";
		cct_getxy(x, y);
		cct_gotoxy(x + 1, y);
		cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
	}
	cout << "�a";
	cct_getxy(x, y);
	cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
	return end_line;
}
static int print_border(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para,int* x1) //��û����ɣ��ضϵĹ��ܻ�û���,�߶ȡ���Ƚض϶�û�п���
{
	int a, b, n, x, y,y1,end_line;
	cct_showch(original_para->start_x, original_para->start_y, ' ', original_para->bg_color, original_para->fg_color, 1);
	a = strlen(original_para->title);
	if (original_para->width % 2 == 1) {
		if (a % 2 == 1) {
			b = (original_para->width+1) / 2 - (a + 1) / 2;//��ӡtitleʱ����һ���ո�
		}
		else {
			b = (original_para->width+1) / 2 - a / 2;
		}
	}
	else {
		if (a % 2 == 1) {
			b = (original_para->width) / 2 - (a + 1) / 2;//��ӡtitleʱ����һ���ո�
		}
		else {
			b = (original_para->width) / 2 - a / 2;
		}
	}
	n = b / 2;
	cct_gotoxy(original_para->start_x, original_para->start_y);
	cout << "�X";
	for (int i = 0; i < n; ++i) {
		cct_getxy(x, y);
		cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
		cct_gotoxy(x + 1, y);
		cout << "�T";
	}
	cct_getxy(x, y);
	cct_gotoxy(x + 1, y);
	cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
	cout << original_para->title;
	if (a % 2 == 1) {
		cout << ' ';
	}
	for (int i = 0; i < n; ++i) {
		cout << "�T";
		cct_getxy(x, y);
		cct_gotoxy(x + 1, y);
		cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
	}
	cct_getxy(x, y);
	cct_gotoxy(x, y);
	cout << "�[";
	cct_getxy(*x1, y1);
	cct_showch(*x1, y1, ' ', original_para->bg_color, original_para->fg_color, 1);
	if (y1 != original_para->start_y) {                                                       //���ڽضϵĴ���
		end_line=cut_print(original_para,menu,*x1);
		return end_line;
	}
	else {
		for (end_line = 1; menu[end_line - 1] != NULL && menu[end_line - 1][0] != '\0'; ++end_line) { ///������ע�������ֹ����������--endline�ǲ˵�ѡ�����+1
			if (end_line <= original_para->high) {
				cct_gotoxy(original_para->start_x, original_para->start_y + end_line);
				cout << "�U ";
				cct_getxy(x, y);
				word_cut(menu, end_line, *x1);                                                   //!!!
				cct_getxy(x, y);
				while (x < *x1) {
					cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
					++x;
				}
				cct_gotoxy(*x1 - 1, original_para->start_y + end_line);
				cout << "�U";
				cct_getxy(x, y);
				cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
			}
		}
		cct_getxy(x, y);
		cct_gotoxy(original_para->start_x, y + 1);
		cout << "�^";
		cct_getxy(x, y);
		cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
		cct_gotoxy(x + 1, y);
		for (; x < *x1 - 1; ++x) {
			cout << "�T";
			cct_getxy(x, y);
			cct_gotoxy(x + 1, y);
			cct_showch(x, y, ' ', original_para->bg_color, original_para->fg_color, 1);
		}
		cout << "�a";
		cct_getxy(*x1, y1);
		cct_showch(*x1, y1, ' ', original_para->bg_color, original_para->fg_color, 1);
		return end_line;
	}
}
static int judge_(const struct PopMenu* original_para,int * cols)
{
	int lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(*cols, lines, buffer_cols, buffer_lines);
	if (*cols < original_para->start_x + original_para->width&& buffer_cols < original_para->start_x + original_para->width) {
		return 0;
	}
	else {
		return 1;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	int end_line,choice,x1,judge,clos;
	end_line=print_border(menu, original_para,&x1);
	judge=judge_(original_para,&clos);
	choice=move_by_arrow(original_para, end_line, menu,x1,judge,clos);
	return choice; //���践��
	
}
