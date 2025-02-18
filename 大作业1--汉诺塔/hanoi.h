/* �ƿ� 2353761 ��𪾧 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ------------------------------------------------------------------------------------------------------ */

const char ch = ' ';
const int bg_color = COLOR_HYELLOW;	//����Ϊ����ɫ
const int fg_color = COLOR_HBLUE;		//ǰ��Ϊ����ɫ
const int LENGTH = 23;
const int SPACE = 9;
const int Y = 2;


int  hanoi_menu (void); //����������������void�����򱨴�
void shuru(char* src, char* tmp, char* dst,int*n,int gongnenghao);
void hanoi(int n, char src, char tmp, char dst, int gongnenghao);
void print(int x, int y);
void draw_column(char src,char dst,int gongnenghao,int n);
void draw_original(char src,int n,int gongnenghao);
void print_column(int n, char src, char dst, int gongnenghao);
void chushihua(char src, int n);
void movement(char src, char dst, int n);
void set_sudu(char src, char dst, int layers,int gongnenghao);
void mark_number(int n, char src, char dst);
int game_9_shuru (void);
void game_9_control (char dst,int layers);
void print_title(int gongnenghao, char src, char dst, int n);
void print_shu();
void yanshipanduan(int gongnenghao, char src, char dst, int n);
void panduan_function(int gongnenghao, int n, char src, char dst);
void chushihua2 (int gongnenghao);
void game_9_yidong(char srcc1, char dstt1, int m);
