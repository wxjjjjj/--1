#include <iostream>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void cct_showstr(const int X, const int Y, const char* str, const int bg_color, const int fg_color, int rpt, int maxlen);
void cct_getxy(int& x, int& y);
void cct_setfontsize(const char* fontname, const int high, const int width);
int main()
{
	/* �������͵Ŀ�ܣ�ÿ��11��Ԫ�أ�ÿ��Ԫ�ؾ�Ϊһ�������ַ���2�ֽڣ� 
		˫�߿�ܣ�"�X", "�^", "�[", "�a", "�T", "�U", "�j", "�m", "�d", "�g", "�p"
	 	���߿�ܣ�"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��"
		��˫����: "�V", "�\", "�Y", "�_", "�T", "��", "�h", "�k", "�b", "�e", "�n"
		�ᵥ��˫��"�W", "�]", "�Z", "�`", "��", "�U", "�i", "�l", "�c", "�f", "�o"
    */

	/* ˫�߿��ʹ���������������滻Ϊ�������ͣ� 
	   �X�T�j�T�[
	   �U  �U  �U
	   �d�T�p�T�g
	   �U  �U  �U
	   �^�T�m�T�a      */
	cct_setfontsize("������",24,0);
	cout << "�X�T�j�T�[" << endl;
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "�X�T�j�T�[", 1, 4, 1, -1);
	cout << "�U  �� �U �� �U" << endl;
	cout << "�d�T�p�T�g" << endl;
	cout << "�U  �U  �U" << endl;
	cout << "�^�T�m�T�a" << endl;

	return 0;
}
/*
void draw_border_pro(int array[][9], int hang, int lie)
{
	int x, y;
	cct_getxy(x, y);
	cct_showstr(x, y, "�X", COLOR_HWHITE, COLOR_BLACK, 1, -1);
	for (int i = 0; i < lie - 1; ++i) {                                  //1
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
}*/