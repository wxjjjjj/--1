/* 2353761 ��𪾧 �ƿ� */
#include <iostream>
#include <cstdio>
#include <conio.h>   //_getch()��_kbhit()��ͷ�ļ� _kbhit() �������ڼ�鵱ǰ�Ƿ��м������롣����а��������£����᷵��һ������ֵ��ͨ����1�������򷵻�0��
#include <time.h>
#include <windows.h>  //���ܺ�numʲô���������������ĳ���һ����
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
            int X       ��ָ��λ�õ�x����
            int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
            int X       ��ָ��λ�õ�x����
            int Y       ��ָ��λ�õ�y����
            char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
int menu() 
{
	cout << "1.��I��J��K��L�������������ң���Сд���ɣ������ͷ��겻�������ƣ��߽�ֹͣ��" << endl;
	cout << "2.��I��J��K��L�������������ң���Сд���ɣ������ͷ��겻�������ƣ��߽���ƣ�" << endl;
	cout << "3.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽�ֹͣ��" << endl;
	cout << "4.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽���ƣ�" << endl;
	cout << "0.�˳�" << endl;
	cout << "��ѡ��[0-4] ";
	char shuru;
	shuru = _getch();
	if (shuru== '0') {
		return 0;
	}
	else if (shuru == '1' ) {
		return 1;
	}
	else if (shuru == '2') {
		return 2;
	}
	else if (shuru == '3' ) {
		return 3;
	}
	else if (shuru == '4') {
		return 4;
	}
	else {       //�������µĴ������룬������Ӧ���Ǽ�����������˵�ҳ��
		return 5;
	}
}

int move_by_ijkl(const HANDLE hout,int huirao) { //a�����������Ƿ���Ƶ�

	init_border(hout);
	gotoxy(hout, 35, 9);	//����ƻ����м�
	int x = 35, y = 9;
	int diuqijiantou;
	char ch;
	if (huirao == 1) {//�߽�ֹͣ
		while (1) {
			if (_kbhit()) {//�����а������� ��_kbhit����ֵΪ1

				ch = _getch();
				if (int(ch) <0) { //�ڸó��������ͷ�ķ���ֵ�Ǹ���-32��Ϊʲô��
					diuqijiantou = _getch();
				}
				switch (ch) {
					case 'i':
					case'I':
						if (y == 1) {
							gotoxy(hout, x, y);
							break;
						}
						else {
							y--;
							gotoxy(hout, x, y);
							break; // ��
						}
					case'K':
					case 'k':
						if (y == 17) {
							gotoxy(hout, x, y);
							break;
						}
						else {
							y++;
							gotoxy(hout, x, y);
							break; // ��
						}

					case'J':
					case 'j':
						if (x == 1) {
							gotoxy(hout, x, y);
							break;
						}
						else {
							x--;
							gotoxy(hout, x, y);
							break; // ��  
						}

					case 'l':
					case'L':
						if (x == 69) {
							gotoxy(hout, x, y);
							break;
						}
						else {
							x++;
							gotoxy(hout, x, y);
							break; // �� 
						}

					case'Q':
					case'q':
						gotoxy(hout, 0, 24);
						return 0;
					default:
						break;
				}  //����ƶ�����

				
				if (ch == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
			}
		}	
	}

	else {//�߽����
		while (1) {
			if (_kbhit()) {//�����а������� ��_kbhit����ֵΪ1

				ch = _getch();
				if (int(ch) < 0) { //�ڸó��������ͷ�ķ���ֵ�Ǹ���-32��Ϊʲô��
					diuqijiantou = _getch();//��ȡ���ڶ����ȴ���ȡ�ļ�ֵ
				}
				switch (ch) {
					case 'i':
					case'I':
						if (y == 1) {
							y = 17;
							gotoxy(hout, x, y);
							break;
						}
						else {
							y--;
							gotoxy(hout, x, y);
							break; // ��
						}
					case'K':
					case 'k':
						if (y == 17) {
							y = 1;
							gotoxy(hout, x, y);
							break;
						}
						else {
							y++;
							gotoxy(hout, x, y);
							break; // ��
						}

					case'J':
					case 'j':
						if (x == 1) {
							x = 69;
							gotoxy(hout, x, y);
							break;
						}
						else {
							x--;
							gotoxy(hout, x, y);
							break; // ��  
						}

					case 'l':
					case'L':
						if (x == 69) {
							x = 1;
							gotoxy(hout, x, y);
							break;
						}
						else {
							x++;
							gotoxy(hout, x, y);
							break; // �� 
						}

					case'Q':
					case'q':
						gotoxy(hout, 0, 24);
						return 0;
					default:
						break;
				}  //����ƶ�����
				if (ch == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
			}
		}

	}
	return 1;
}

int move_by_arrow(const HANDLE hout, int huirao2) { //a�����������Ƿ���Ƶ�
	init_border(hout);
	gotoxy(hout, 35, 9);	//����ƻ����м�
	int x = 35, y = 9;
	char ch;
	if (huirao2 == 3) {//�߽�ֹͣ
		while (1) {
			if (_kbhit()) {//�����а������� ��_kbhit����ֵΪ1

				ch = _getch();
				if (int(ch) < 0) { //�ڸó��������ͷ�ķ���ֵ�Ǹ���-32��Ϊʲô��
					ch = _getch();
					switch (int(ch)) {
						case 72:
							if (y == 1) {
								gotoxy(hout, x, y);
								break;
							}
							else {
								y--;
								gotoxy(hout, x, y);
								break; // ��
							}
						case 80:
							if (y == 17) {
								gotoxy(hout, x, y);
								break;
							}
							else {
								y++;
								gotoxy(hout, x, y);
								break; // ��
							}

						case 75:
							if (x == 1) {
								gotoxy(hout, x, y);
								break;
							}
							else {
								x--;
								gotoxy(hout, x, y);
								break; // ��  
							}

						case 77:
							if (x == 69) {
								gotoxy(hout, x, y);
								break;
							}
							else {
								x++;
								gotoxy(hout, x, y);
								break; // �� 
							}
						default:
							break;
					}  //����ƶ�����
				}
				if (ch == 'q' || ch == 'Q') {

						gotoxy(hout, 0, 24);
						return 0;
				}
				
				if (ch == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
			}
		}
	}

	else {//�߽����
		while (1) {
			if (_kbhit()) {//�����а������� ��_kbhit����ֵΪ1

				ch = _getch();
				if (int(ch) < 0) { //�ڸó��������ͷ�ķ���ֵ�Ǹ���-32��Ϊʲô��
					ch = _getch();
					switch (int(ch)) {
						case 72:
							if (y == 1) {
								y = 17;
								gotoxy(hout, x, y);
								break;
							}
							else {
								y--;
								gotoxy(hout, x, y);
								break; // ��
							}
						case 80:
							if (y == 17) {
								y = 1;
								gotoxy(hout, x, y);
								break;
							}
							else {
								y++;
								gotoxy(hout, x, y);
								break; // ��
							}

						case 75:
							if (x == 1) {
								x = 69;
								gotoxy(hout, x, y);
								break;
							}
							else {
								x--;
								gotoxy(hout, x, y);
								break; // ��  
							}

						case 77:
							if (x == 69) {
								x = 1;
								gotoxy(hout, x, y);
								break;
							}
							else {
								x++;
								gotoxy(hout, x, y);
								break; // �� 
							}
						default:
							break;
					}  //����ƶ�����
				}
				if (ch == 'q' || ch == 'Q') {

					gotoxy(hout, 0, 24);
					return 0;
				}

				if (ch == ' ') {
					showch(hout, x, y, ' ');
					gotoxy(hout, x, y);
				}
			}
		}
	}
	return 1;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ�� HANDLE��һ������int���������Ͷ��壬��������hout

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));


	while (1) {
		int a,b=1;
		a = menu();
		if (a == 0) {
			cout << 0;
			return 0;
		}
		else if (a == 1) {//����1
			cls(hout);
			b=move_by_ijkl(hout,a);
		}
		else if (a == 2) {//����2
			cls(hout);
			b=move_by_ijkl(hout,a);
		}
		else if (a == 3) {//����3
			cls(hout);
			b = move_by_arrow(hout, a);
		
		}
		else if (a == 4) {//����4
			cls(hout);
			b = move_by_arrow(hout, a);
		}

		if (b==0) {
			cout << "��Ϸ���������س������ز˵�.";
			int huiche;
			
			while (1) {
				huiche = _getch();
				if (huiche == 13) {
					break;
				}
			}
		}
		/* �˾�������ǵ���ϵͳ��cls�������� */
		cls(hout);
			
	}

	return 0;
}
