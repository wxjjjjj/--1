/* 2353761 �ƿ� ��𪾧*/
#include <iostream>
#include <conio.h>
using namespace std;

#include "cmd_console_tools.h"
#include "7-b2.h"

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��ʾ��Ϣ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
static void to_be_continued(const char* prompt = NULL, const int X = 0, const int Y = 28)
{
	cct_setcolor(); //�ָ�ȱʡ��ɫ
	cct_gotoxy(X, Y);

	if (prompt)
		cout << prompt << "�����س�������...";
	else
		cout << "���س�������...";

	/* ���Գ��س�������������루ע�⣺_getch�Ļس���\r����getchar��\n��*/
	while (_getch() != '\r')
		;

	return;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	const char menu_hanoi[][MAX_ITEM_LEN] = {
		" 1.�ڲ����飬���ɳ�ʼ״̬��Ѱ���Ƿ��г�ʼ��������",
		" 2.�ڲ����飬������ʼ����������0�����䲢��0���",
		" 3.�ڲ����飬������ʼ������������������ʾ",
		" 4.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬",
		" 5.n*n�Ŀ��(�зָ���)����ʾ��ʼ״̬",
		" 6.n*n�Ŀ��(�޷ָ���)����ʾ��ʼ״̬����ʼ��������",
		" 7.n*n�Ŀ��(�зָ���)��������ʼ�����������ʾ������ʾ",
		" 8.cmdͼ�ν���������(�зָ��ߣ�����ƶ�ʱ��ʾ���꣬�Ҽ��˳�)",
		" 9.cmdͼ�ν���������",
		" 0.�˳�",
		NULL
	};

	const char menu_colorlinez[][MAX_ITEM_LEN] = {
		"A.�ڲ����飬������ɳ�ʼ5����",
		"B.�ڲ����飬�������60%����Ѱ���ƶ�·��",
		"C.�ڲ����飬������",
		"D.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����",
		"E.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����",
		"F.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�",
		"G.cmdͼ�ν���������",
		"Q.�˳�",
		NULL
	};

	const char menu_test[][MAX_ITEM_LEN] = {
		" 1.�������ҳ��ɺϳ����ʶ���ǵݹ飩",
		" 2.�������ҳ��ɺϳ����ʶ���ݹ飩",
		"3.���������һ�κϳɣ��ֲ�����ʾ��",
		"4.�����������棨�ֲ�����ʾ��",
		" 5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�",
		" 6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�",
		"7.αͼ�ν������ü�ͷ��/���ѡ��ǰɫ��",
		"8.αͼ�ν������һ�κϳɣ��ֲ��裩",
		" 9.αͼ�ν���������(֧�����)",
		" A.�����н��棨�����Զ���-�����棩",
		"B.αͼ�ν��棨�����Զ���-�����棩",
		"C.�����н��棨�����Զ���-�����棩",
		" 0.�˳�",
		""
	};

	if (1) {
		cct_setconsoleborder(120, 35);
		cct_cls();
		cout << "����1���ڴ�����������ʾ������㹻������Ĳ˵���߶��㹻�������еĲ˵���" << endl;

		struct PopMenu parameter;
		parameter.title = "��ŵ��"; //�����ǵ����ַ�
		parameter.start_x = 30;
		parameter.start_y = 10;
		parameter.width = 80;	//�����˵������ҿ���
		parameter.high = 10;	//�����˵������¿��ߣ���������˲˵���ʵ������������Ϊʵ������
		parameter.bg_color = COLOR_BLACK;	//����ɫ
		parameter.fg_color = COLOR_HWHITE; //ǰ��ɫ

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_hanoi, &parameter);

		cct_gotoxy(0, 20);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {
		cct_setconsoleborder(120, 35);
		cct_cls();
		cout << "����2���ڴ�����������ʾ������㹻������Ĳ˵���߶��㹻�������еĲ˵���������������ַ�" << endl;

		struct PopMenu parameter;
		parameter.title = "H��ŵ"; //�����ǵ����ַ��Һ�����
		parameter.start_x = 30;
		parameter.start_y = 10;
		parameter.width = 80;	//�����˵������ҿ���
		parameter.high = 15;	//�����˵������¿��ߣ���������˲˵���ʵ������������Ϊʵ������
		parameter.bg_color = COLOR_HBLUE;	//����ɫ
		parameter.fg_color = COLOR_HYELLOW; //ǰ��ɫ

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_hanoi, &parameter);

		cct_gotoxy(0, 20);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {
		cct_setconsoleborder(120, 35);
		cct_cls();
		cout << "����3���ڴ�����������ʾ������㹻������Ĳ˵�����߶Ȳ����������еĲ˵���" << endl;
		cout << "       �˵�����Ҫ���¹���" << endl;

		struct PopMenu parameter;
		parameter.title = "test3 "; //�����Ǵ�Ӣ�ĵ���
		parameter.start_x = 20;
		parameter.start_y = 5;
		parameter.width = 59;	//�����˵������ҿ��ߣ��˴��͸���60��������ʾӦ��һ��
		parameter.high = 5;	//�����˵������¿��ߣ���������˲˵���ʵ������������Ҫ����
		parameter.bg_color = COLOR_RED;	//����ɫ
		parameter.fg_color = COLOR_HYELLOW; //ǰ��ɫ

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_test, &parameter);

		cct_gotoxy(0, 20);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {
		cct_setconsoleborder(120, 35);
		cct_cls();
		cout << "����4���ڴ�����������ʾ����Ȳ�����������Ĳ˵���߶��㹻�������еĲ˵���" << endl;
		cout << "       ������ȵĲ˵�����Ҫ�ض�" << endl;
		cout << "       �ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�����Ҫ��ӡһ������ʱ�������ú��֣��ÿո����" << endl;

		struct PopMenu parameter;
		parameter.title = "����˵�"; //������˫���ַ�
		parameter.start_x = 10;
		parameter.start_y = 8;
		parameter.width = 40;	//�����˵������ҿ���
		parameter.high = 20;	//�����˵������¿��ߣ���������˲˵���ʵ������������Ҫ����
		parameter.bg_color = COLOR_HWHITE;	//����ɫ
		parameter.fg_color = COLOR_BLACK; //ǰ��ɫ

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_colorlinez, &parameter);

		cct_gotoxy(0, 23);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {
		cct_setconsoleborder(120, 35);
		cct_cls();
		cout << "����5���ڴ�����������ʾ����Ȳ���������title�ĳ��ȣ��߶��㹻�������еĲ˵���" << endl;
		cout << "       ��С���Ϊ������ʾtitle����Ŀ�ȣ�������ȵĲ˵�����Ҫ�ض�" << endl;
		cout << "       �ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�����Ҫ��ӡһ������ʱ�������ú��֣��ÿո����" << endl;

		struct PopMenu parameter;
		parameter.title = "����˵�5-�ӳ���"; //������˫���ַ�
		parameter.start_x = 10;
		parameter.start_y = 8;
		parameter.width = 6;	//�����˵������ҿ��ߣ�С��title�ĳ��ȣ�
		parameter.high = 20;	//�����˵������¿��ߣ���������˲˵���ʵ������������Ҫ����
		parameter.bg_color = COLOR_HWHITE;	//����ɫ
		parameter.fg_color = COLOR_BLACK; //ǰ��ɫ

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_colorlinez, &parameter);

		cct_gotoxy(0, 23);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {
		cct_setconsoleborder(120, 35);
		cct_cls();
		cout << "����6���ڴ�����������ʾ����Ȳ���������title�ĳ��ȣ��߶��㹻�������еĲ˵���" << endl;
		cout << "       ��С���Ϊ������ʾtitle����Ŀ�ȣ�������ȵĲ˵�����Ҫ�ض�" << endl;
		cout << "       �ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�����Ҫ��ӡһ������ʱ�������ú��֣��ÿո����" << endl;

		struct PopMenu parameter;
		parameter.title = "����˵�6-�ӳ���2"; //�����ǵ����ַ�
		parameter.start_x = 10;
		parameter.start_y = 8;
		parameter.width = 6;	//�����˵������ҿ��ߣ�С��title�ĳ��ȣ�
		parameter.high = 20;	//�����˵������¿��ߣ���������˲˵���ʵ������������Ҫ����
		parameter.bg_color = COLOR_HCYAN;	//����ɫ
		parameter.fg_color = COLOR_BLACK; //ǰ��ɫ

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_colorlinez, &parameter);

		cct_gotoxy(0, 23);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {
		cct_setconsoleborder(120, 35);
		cct_cls();
		cct_gotoxy(0, 15);
		cout << "����7���ڴ�����������ʾ����Ȳ�����������Ĳ˵���߶Ȳ������������еĲ˵���" << endl;
		cout << "       ������ȵĲ˵�����Ҫ�ضϣ��˵�����Ҫ���¹���" << endl;
		cout << "       �ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�����Ҫ��ӡһ������ʱ�������ú��֣��ÿո����" << endl;

		struct PopMenu parameter;
		parameter.title = "���Բ˵�7"; //�����ǵ����ַ�
		parameter.start_x = 0;
		parameter.start_y = 0;
		parameter.width = 30;		//�����˵�������������ע�⣬��Ȳ�������ʱҪ���ְ�����ֲ��ң�
		parameter.high = 5;		//�����˵�����������
		parameter.bg_color = COLOR_YELLOW;
		parameter.fg_color = COLOR_HBLUE;

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_test, &parameter);

		cct_gotoxy(0, 20);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {	//�߶ȴ�����������ȴ��ڴ��������Խ��
		cct_cls();
		cct_setconsoleborder(80, 30);
		cct_gotoxy(0, 15);
		cout << "����8���˵�����ʾ��ȳ����˴��ڿ�ȣ���Ҫ�۷�����һ�е���ʼλ�ã�����title��" << endl;
		cout << "       �˵�����Ҫ���¹�������ʾ����" << endl;
		cout << "       Ϊ�˼���������������Կ�Ȳ��������" << endl;

		struct PopMenu parameter;
		parameter.title = "����˵�8"; //�����ǵ����ַ�
		parameter.start_x = 44;//�����˵�������������ע�⣬�������������ʵλ��Ϊ�����������
		parameter.start_y = 2;
		parameter.width = 70;	//�����˵�������������ע�⣬����������Կ�Ȳ����������
		parameter.high = 7;		//�����˵�����������
		parameter.bg_color = COLOR_HBLUE;
		parameter.fg_color = COLOR_YELLOW;

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_hanoi, &parameter);

		cct_gotoxy(0, 20);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {	//�߶ȴ�����������ȴ��ڴ��������Խ�絫�ɹ���
		cct_cls();
		cct_setconsoleborder(80, 30, 200, 50); //ע�⣺�ĸ�����
		cct_gotoxy(0, 15);
		cout << "����9���˵�����ʾ��ȳ����˴��ڿ�ȣ�����δ�����������Ŀ��" << endl;
		cout << "       ����Ҫ�۷���ӡ�����Ǻ����������Ҫ�ƶ�cmd�����·���ˮƽ�����˲��ܿ���" << endl;
		cout << "       ������ȵĲ˵�����Ҫ�ضϣ��˵�����Ҫ���¹���" << endl;
		cout << "       �ض�ʱ��Ҫ���ǰ���������⣬��������ֻʣ��һ���ַ�λ�ã�����Ҫ��ӡһ������ʱ�������ú��֣��ÿո����" << endl;

		struct PopMenu parameter;
		parameter.title = "���Բ˵�9";
		parameter.start_x = 70;
		parameter.start_y = 0;
		parameter.width = 30;	//�����˵�������������ע�⣬��Ȳ�������ʱҪ���ְ�����ֲ��ң�
		parameter.high = 8;		//�����˵�����������
		parameter.bg_color = COLOR_BLUE;
		parameter.fg_color = COLOR_HYELLOW;

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_test, &parameter);

		cct_gotoxy(0, 20);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	if (1) {	//�߶ȴ�����������ȴ��ڴ��������Խ�絫�ɹ���
		cct_cls();
		cct_setconsoleborder(80, 30);
		cct_gotoxy(0, 15);
		cout << "����10���ղ˵�����" << endl;

		const char menu_special[][MAX_ITEM_LEN] = {
			NULL
		};

		struct PopMenu parameter;
		parameter.title = "special";
		parameter.start_x = 0;
		parameter.start_y = 0;
		parameter.width = 30;	//�����˵�������������ע�⣬��Ȳ�������ʱҪ���ְ�����ֲ��ң�
		parameter.high = 8;		//�����˵�����������
		parameter.bg_color = COLOR_BLUE;
		parameter.fg_color = COLOR_HYELLOW;

		/* ����pop_menu����������ѡ��Ĳ˵���������1��ʼ������*/
		int ret = pop_menu(menu_special, &parameter);

		cct_gotoxy(0, 20);
		cct_setcolor(); //�ָ�ȱʡ��ɫ
		if (ret > 0)
			cout << "����ѡ��Ϊ�˵��ĵ�" << ret << "��." << endl;
		else
			cout << "����δѡ��˵�." << endl;
		to_be_continued();
	}

	return 0;
}
