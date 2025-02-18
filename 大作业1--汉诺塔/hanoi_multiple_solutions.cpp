/* �ƿ� 2353761 ��𪾧 */
#include"cmd_console_tools.h"
#include"hanoi.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
using namespace std;

/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

int bushu = 1;
int a[10], b[10], c[10];  //�洢�̺�
int d, e, f;            //�洢a��b��c��������
static int sudushijian;//�ƶ���ʱ��ʱ��

void chushihua(char src, int n) 
{
	bushu = 1;
	d = 0;
	e = 0;
	f = 0;
	sudushijian = 0;
	for (int g = 0; g < 10; ++g) {
		a[g] = 0;
		b[g] = 0;
		c[g] = 0;
	}
	if (src == 'A') {
		d = n;
		for (int i = 0; i < n; ++i) {
			a[i] = n - i;
		}
	}
	else if (src == 'B') {
		e = n;
		for (int i = 0; i < n; ++i) {
			b[i] = n - i;
		}
	}
	else {
		f = n;
		for (int i = 0; i < n; ++i) {
			c[i] = n - i;
		}
	}
	return;
}
void chushihua2(int gongnenghao)
{
	if (gongnenghao == 4 ||gongnenghao==9||gongnenghao==8) {
		cct_gotoxy(11, 36);
		cout << "��ʼ�� ";
		cout << "A:";
		for (int m = 0; m < 10; ++m) {
			if (a[m] > 0) {
				cout << setw(2) << a[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "B:";
		for (int m = 0; m < 10; ++m) {
			if (b[m] > 0) {
				cout << setw(2) << b[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "C:";
		for (int m = 0; m < 10; ++m) {
			if (c[m] > 0) {
				cout << setw(2) << c[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";
		cout << endl;
		print_shu();
		if (gongnenghao != 9) {
			if (sudushijian) {
				Sleep(sudushijian);
			}
			else {
				int huiche;
				while (1) {
					huiche = _getch();
					if (huiche == 13) {
						break;
					}
				}
			}
		}
		else {
			cct_gotoxy(9, 33);
			cout << "=========================" << endl;
			cct_gotoxy(9, 34);
			cout << "  A         B         C" << endl;
		}
	}
	return;
}
void mark_number(int n,char src, char dst)
{
	int i, j;
	if (src == 'A') {
		i = d;
		a[i - 1] = 0;
		--d;
	}
	else if (src == 'B') {
		i = e;
		b[i - 1] = 0;
		--e;
	}
	else {
		i = f;
		c[i - 1] = 0;
		--f;
	}

	if (dst == 'A') {
		j = d;
		a[j] = n;
		++d;
	}
	else if (dst == 'B') {
		j = e;
		b[j] = n;
		++e;
	}
	else {
		j = f;
		c[j] = n;
		++f;
	}
	return;
}

void print_column(int n, char src, char dst,int gongnenghao)
{
	mark_number(n, src, dst);
	if (gongnenghao == 2) {
		cout << endl;
	}
	else {
		cout << "A:";
		for (int m = 0; m < 10; ++m) {
			if (a[m] > 0) {
				cout << setw(2) << a[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "B:";
		for (int m = 0; m < 10; ++m) {
			if (b[m] > 0) {
				cout << setw(2) << b[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";

		cout << "C:";
		for (int m = 0; m < 10; ++m) {
			if (c[m] > 0) {
				cout << setw(2) << c[m];
			}
			else {
				cout << "  ";
			}
		}
		cout << " ";
		cout << endl;
		if (gongnenghao != 3) {
			print_shu();
		}
	}
	return;
}

void print_shu()//�����������
{
	int x = 11, y = 32;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (a[m] > 0) {
			cout << a[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	x = x + 10;
	y = 32;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (b[m] > 0) {
			cout << b[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	x = x + 10;
	y = 32;
	for (int m = 0; m < 10; ++m) {
		cct_gotoxy(x, y);
		if (c[m] > 0) {
			cout << c[m];
			--y;
		}
		else {
			cout << " ";
		}
	}
	return;
}

void print(int x, int y)
{
	cct_gotoxy(x, y);
	cout << "���س�������";

	while (_getch() != '\r')
		;
	cct_cls();

	return;
}

void print_title(int gongnenghao,char src,char dst,int n)
{
	cct_cls();
	switch (gongnenghao) {
		case 6:
		case 7:
		case 9:
			cct_gotoxy(0, 0);
			cout << "�� " << src << " �ƶ��� " << dst << " ,�� " << n << " ��";
			break;
		case 8:
		case 4:
			cout << "�� " << src << " �ƶ��� " << dst << " ,�� " << n << " �㣬��ʱ����Ϊ ";
			break;
		default:
			break;
	}
	return;
}
void draw_column(char src,char dst,int gongnenghao,int n)
{
	if (gongnenghao == 5 || gongnenghao == 6 || gongnenghao == 7 || gongnenghao == 8 || gongnenghao == 9) {
		if (gongnenghao != 8) {
			print_title(gongnenghao, src, dst, n);
		}
		int x;
		int y;
		cct_setcursor(CURSOR_INVISIBLE);
		/*�Ȼ���������*/
		x = 1;
		y = 20;
		/* ������(1,20)λ�ô���ӡ��һ������ */
		cct_showch(x, y, ch, bg_color, fg_color, LENGTH);
		x = 1 + LENGTH + SPACE;                                                 //A������ʼx��1-24 
		cct_showch(x, y, ch, bg_color, fg_color, LENGTH);
		x = 1 + (LENGTH + SPACE) * 2;                                            //B����ʼ x��33-56 
		cct_showch(x, y, ch, bg_color, fg_color, LENGTH);                 //C����ʼ x: 65-88  
		/*��ʼ��ӡ����*/
		for (y = 19; y >= 5; --y) {
			x = 1 + (LENGTH - 1) / 2;
			cct_showch(x, y, ch, bg_color, fg_color, 1);
			Sleep(30);
			x = 1 + LENGTH + SPACE + (LENGTH - 1) / 2;
			cct_showch(x, y, ch, bg_color, fg_color, 1);
			Sleep(30);
			x = 1 + (LENGTH + SPACE) * 2 + (LENGTH - 1) / 2;
			cct_showch(x, y, ch, bg_color, fg_color, 1);
			Sleep(30);
		}
		//���賣��A���м�ֵx1=1+(LENGTH-1)/2��B���м�ֵx2=1+LENGTH+SPACE+(LENGTH-1)/2;C���м�ֵx3=1+(LENGTH+SPACE)*2+(LENGTH-1)/2
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}
	return;
}

void draw_original(char src,int n,int gongnenghao) 
{
	if (gongnenghao == 6 || gongnenghao == 7 || gongnenghao == 8 || gongnenghao == 9) {
		cct_setcursor(CURSOR_INVISIBLE);

		int x, y = 19;
		if (src == 'A') {
			x = 1 + (LENGTH - 1) / 2;
		}
		else if (src == 'B') {
			x = 1 + LENGTH + SPACE + (LENGTH - 1) / 2;
		}
		else {
			x = 1 + (LENGTH + SPACE) * 2 + (LENGTH - 1) / 2;
		}
		for (int h = n; h >= 1; --h) {
			cct_showch(x - h, y, ' ', h, fg_color, 2 * h + 1);
			--y;
			Sleep(30);
		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
	}
	return;
}

void yanshipanduan(int gongnenghao, char src, char dst, int n)
{
	if (gongnenghao == 4 || gongnenghao == 8) {
		if (gongnenghao == 8) {
			movement(src, dst, n);
		}
		if (sudushijian) {
			Sleep(sudushijian);
		}
		else {
			int huiche;
			while (1) {
				huiche = _getch();
				if (huiche == 13) {
					break;
				}
			}
		}
	}
	return;
}

void panduan_function(int gongnenghao, int n, char src, char dst)
{
	if (gongnenghao == 1) {
		cout << n << '#' << ' ' << src << '-' << '-' << '>' << dst << endl;
	}
	else {
		if (gongnenghao != 2&&gongnenghao!=3) {
			cct_gotoxy(11, 36);
		}
		cout << "��" << setw(4) << bushu << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")  ";
		print_column(n, src, dst, gongnenghao);
		yanshipanduan(gongnenghao, src, dst, n);
	}
	return;
}

void hanoi(int n, char src, char tmp, char dst, int gongnenghao)  //n���̺� ���ϵ���Ϊ1��2��3...���빦�ܺ�
{
	if (gongnenghao != 5 && gongnenghao != 6 && gongnenghao != 7 && gongnenghao != 9) {
		if (n == 1) {
			panduan_function(gongnenghao, n, src, dst);
			++bushu;
			return;
		}
		hanoi(n - 1, src, dst, tmp, gongnenghao);
		panduan_function(gongnenghao, n, src, dst);
		++bushu;
		hanoi(n - 1, tmp, src, dst, gongnenghao);
	}
	return;
}


void shuru(char *src1,char *tmp1,char *dst1,int*n,int gongnenghao)//��������ĺ���                                                       
{
	int layers;
	char src, dst;//layers�ǲ㣬src����ʼ��,dst��Ŀ����
	if (gongnenghao != 5) {
		while (1) {
			cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
			cin >> layers;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
			}
			else {
				cin.ignore(65536, '\n');//������ȷҲҪ���Ժ�����ַ�
				if (layers >= 1 && layers <= 16) {
					*n = layers;
					while (1) {
						cout << "��������ʼ��(A-C)" << endl;
						cin >> src;
						if (cin.good() == 0) {
							cin.clear();
							cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�//�Ӹ�continue������������ٳ����� ����65536����ɺ���� 
						}
						else {
							cin.ignore(65536, '\n');//������ȷҲҪ���Ժ�����ַ�
							if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c')) {
								if (src >= 'a' && src <= 'c') {
									src = src - 32;
								}
								*src1 = src;
								while (1) {
									cout << "������Ŀ����(A-C)" << endl;
									cin >> dst;
									if (cin.good() == 0) {
										cin.clear();
										cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
									}
									else {
										cin.ignore(65536, '\n');
										if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c')) {
											if (dst >= 'a' && dst <= 'c') {
												dst = dst - 32;
											}
											*dst1 = dst;
											if (src == dst) {
												cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
											}
											else {
												break;
											}
										}
									}
								}
								break;
							}
						}
					}
					break;
				}
			}
		}                //���벿�ִ������;�Ѿ�ת�˴�Сд
		*tmp1 = 'A' + 'B' + 'C' - src - dst;
	}
	return;
}

void set_sudu(char src,char dst,int layers,int gongnenghao)
{
	int sudu;
	if (gongnenghao == 4 || gongnenghao == 8) {
		while (1) {
			cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-5��ʱ��ӦΪ100ms/80ms/50ms/20ms/10ms)" << endl;
			cin >> sudu;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n'); // �������뻺�����е��ַ���ֱ�����з�
			}
			else {
				if (sudu >= 0 && sudu <= 5)
					break;
			}
		}
		//��ʱ����sudu��
		if (sudu == 1) {
			sudushijian = 100;
		}
		else if (sudu == 2) {
			sudushijian = 80;
		}
		else if (sudu == 3) {
			sudushijian = 50;
		}
		else if (sudu == 4) {
			sudushijian = 20;
		}
		else if (sudu == 5) {
			sudushijian = 10;
		}
		else {//0-��������
			sudushijian = 0;
		}
		print_title(4, src, dst, layers);
		cout << sudu;
		cct_gotoxy(9, 33);
		cout << "=========================" << endl;
		cct_gotoxy(9, 34);
		cout << "  A         B         C" << endl;
		cct_gotoxy(20, 36);
	}
	return;
}

void movement(char src, char dst, int n)
{
	cct_setcursor(CURSOR_INVISIBLE);
	int srcc, dstt, x1, x2;
	if (src == 'A') {
		srcc = d;
		x1 = 1 + (LENGTH - 1) / 2;
	}
	else if (src == 'B') {
		srcc = e;
		x1 = 1 + LENGTH + SPACE + (LENGTH - 1) / 2;
	}
	else {
		srcc = f;
		x1 = 1 + (LENGTH + SPACE) * 2 + (LENGTH - 1) / 2;
	}

	if (dst == 'A') {
		dstt = d;
		x2 = 1 + (LENGTH - 1) / 2;
	}
	else if (dst == 'B') {
		dstt = e;
		x2 = 1 + LENGTH + SPACE + (LENGTH - 1) / 2;
	}
	else {
		dstt = f;
		x2 = 1 + (LENGTH + SPACE) * 2 + (LENGTH - 1) / 2;
	}
    //����
	for (int y = 19 - srcc; y >= Y; y--) {
		cct_showstr(x1-n, y, " ", n, fg_color, 2 * n+1 );          
		Sleep(sudushijian+20);
		if (y >= Y+1) {
			cct_showch(x1-n, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n+1);
		}
		if (y >= 5) {
			cct_showch(x1, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		}
	}
	if (x1 < x2) {  //����(x1<x2)
		for (int x = x1; x <= x2; x++) {
			cct_showch(x-n, Y, ' ', n, fg_color, 2 * n+1);
			Sleep(sudushijian+20);
			if (x <= x2 - 1) {
				cct_showch(x-n, Y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
			}
		}
	}
	else {     //���� x1>x2
		for (int x = x1; x >= x2; x--) {
			cct_showch(x-n, Y, ' ', n, fg_color, 2 * n + 1);
			Sleep(sudushijian+20);
			if (x >= x2 - 1) {
				cct_showch(x-n, Y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
			}
		}
	}
	//���� 
	for (int y = Y; y <= 19-dstt+1; y++) {
		cct_showstr(x2-n, y, " ", n, fg_color, 2*n + 1);
		Sleep(sudushijian+20);
		if (y <= 19-dstt) {
			cct_showch(x2-n, y, ' ', COLOR_BLACK, COLOR_WHITE, 2 * n + 1);
		}
		if (y >= 5&&y<=19-dstt) {
			cct_showch(x2, y, ' ', COLOR_HYELLOW, COLOR_WHITE, 1);
		}
	}
	cct_setcolor(COLOR_BLACK,COLOR_WHITE); //�ָ�ȱʡ��ɫ--�ڵװ���
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	return;
}

int game_9_shuru()
{
	char srcc1, dstt1;
	while (1) {
		cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
		int x1, y1;
		cct_getxy(x1, y1);
		cct_showch(x1, y1, ' ', COLOR_BLACK, COLOR_WHITE, 2);//����
		cct_gotoxy(x1, y1);
		while (1) {
			srcc1 = _getche();
			if ((srcc1 >= 'a' && srcc1 <= 'c') || (srcc1 >= 'A' && srcc1 <= 'C')||srcc1=='Q'||srcc1=='q') {
				if (srcc1 == 'q' || srcc1 == 'Q') {
					return 0;
				}
				if (srcc1 >= 'a' && srcc1 <= 'c') {
					srcc1 = srcc1 - 32;
				}
				while (1) {
					dstt1 = _getche();
					if ((dstt1 >= 'a' && dstt1 <= 'c') || (dstt1 >= 'A' && dstt1 <= 'C')) {
						if (dstt1 >= 'a' && dstt1 <= 'c') {
							dstt1 = dstt1 - 32;
						}
						if (dstt1 != srcc1) {
							while (_getch() != '\r')
								;
							break;
						}

					}
					cct_showch(x1+1, y1, ' ', COLOR_BLACK, COLOR_WHITE, 1);//����
					cct_gotoxy(x1+1, y1);
				}
			}
			else {
				cct_showch(x1, y1, ' ', COLOR_BLACK, COLOR_WHITE, 1);//����
				cct_gotoxy(x1, y1);
				continue;
			}
			break;
		}//�������
		int m, n;
		if (srcc1 == 'A') {
			m =d==0?0: a[d - 1];
		}
		else if (srcc1 == 'B') {
			m =e==0?0: b[e - 1];
		}
		else {
			m = f==0?0:c[f - 1];
		}
		if (dstt1 == 'A') {
			n = d == 0 ? 0 : a[d - 1];
		}
		else if (dstt1 == 'B') {
			n = e == 0 ? 0 : b[e - 1];
		}
		else {
			n = f == 0 ? 0 : c[f - 1];;
		}
		if (m == 0) {
			cout << endl;
			cout << "��Ҫ�ƶ��յ�����";
			Sleep(1000);
			cct_showch(0, 38, ' ', COLOR_BLACK, COLOR_WHITE, 40);//����
			cct_showch(0, 39, ' ', COLOR_BLACK, COLOR_WHITE, 40);//����
			cct_gotoxy(0, 38);
		}
		else if (m >= n && n != 0) {
			cout << endl;
			cout << "NoNo,��Ҫ����ѹС��Ŷ";
			Sleep(1000);
			cct_showch(0, 38, ' ', COLOR_BLACK, COLOR_WHITE, 40);//����
			cct_showch(0, 39, ' ', COLOR_BLACK, COLOR_WHITE, 40);//����
			cct_gotoxy(0, 38);
		}
		else {
			game_9_yidong(srcc1,dstt1,m);
			break;
		}
	}
	return 1;
}

void game_9_yidong(char srcc1, char dstt1,int m)
{
	cct_gotoxy(9, 33);
	cout << "=========================" << endl;
	cct_gotoxy(9, 34);
	cout << "  A         B         C" << endl;
	cct_gotoxy(11, 36);
	cout << "��" << setw(4) << bushu << " ��(" << setw(2) << m << "#: " << srcc1 << "-->" << dstt1 << ")  ";
	++bushu;
	print_column(m, srcc1, dstt1, 9);
	movement(srcc1, dstt1, m);
}

void game_9_control(char dst,int layers)
{
	int i=1;
	if (dst == 'A') {
		while (d != layers&&i==1) {
			cct_gotoxy(0, 38);
			i=game_9_shuru();
		}
	}
	else if (dst == 'B') {
		while (e!= layers && i == 1) {
			cct_gotoxy(0, 38);
			i=game_9_shuru();
		}
	}
	else {
		while (f != layers && i == 1) {
			cct_gotoxy(0, 38);
			i=game_9_shuru();
		}
	}
	if (i == 0) {
		cct_gotoxy(0, 39);
		cout << "����һ�֣�";
		return;
	}
	cct_gotoxy(0, 39);
	cout << "��Ϸ������̫��������";
	return;
	
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
