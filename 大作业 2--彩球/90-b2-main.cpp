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
���main�����Ͳ˵�����*/

int color_linez_menu()
{
	cout << "---------------------------------" << endl;
	cout << "A.�ڲ����飬������ɳ�ʼ5����" << endl;
	cout << "B.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
	cout << "C.�ڲ����飬������" << endl;
	cout << "D.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
	cout << "E.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
	cout << "F.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�" << endl;
	cout << "G.cmdͼ�ν���������" << endl;
	cout << "Q.�˳�" << endl;
	cout << "---------------------------------" << endl;
	cout << "[��ѡ��:]";
	return int(_getche()); //ע�� 1���ص�intֵ��49
}

int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	int i,hang=0,lie=0,sum_score=0;
	int array[9][9] = { 0 };
	/* srand������������α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ���*/
	cct_setfontsize("������", 24, 0);
	srand((unsigned int)(time(0)));

	while (1) {
		cct_cls();
		i = color_linez_menu();
		if (i >= int('a') && i <= int('g') || i >= int('A') && i <= int('G') || i == int('Q') || i == int('q')) {
			Sleep(150);
			if (i == int('Q') || i == int('q')) {
				return 0;
			}
			Input(&hang, &lie);
			if (i == int('A') || i == int('a') || i == int('D') || i == int('E') || i == int('d') || i == int('e')) {
				array_A(hang, lie, array, 5);
				cout << "��ʼ����:" << endl;
				print_array(hang, lie, array, array, 1);
				if (i == int('D') || i == int('E') || i == int('d') || i == int('e')) {
					draw_border_pause();
					if (i == int('E') || i == int('e')) {
						draw_border_pro(array, hang, lie);
					}
					else {
						draw_border(array, hang, lie);
					}
				}
			}
			if (i == int('B') || i == int('b')) {
				array_A(hang, lie, array, int(hang * lie * 0.6));
				cout << "��ǰ����:" << endl;
				print_array(hang, lie, array, array, 1);
				input_move_instruction(0, 0, array, hang, lie, 2, &sum_score);
			}
			if (i == int('C') || i == int('c')) {
				array_A(hang, lie, array, 5);
				while (1) {
					cout << "��ǰ����:" << endl;
					print_array(hang, lie, array, array, 1);
					input_move_instruction(0, 0, array, hang, lie, 3, &sum_score);
					if (judge_full(array, hang, lie)) {//���������
						break;
					}
				}
				sum_score = 0;
			}
			if (i == int('F') || i == int('f')) {
				array_A(hang, lie, array, int(hang * lie * 0.6));
				draw_border_pro(array, hang, lie);
				move_by_mouse(hang, lie, array, 1);
			}
			if (i == int('G') || i == int('g')) {
				array_A(hang, lie, array, 5);
				draw_border_pro(array, hang, lie);
				move_by_mouse(hang, lie, array, 2);
			}
			chushihua_array(array, hang, lie);
			print();
		}
		else {
			continue;
		}
	}
	return 0;
}