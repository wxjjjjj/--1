/* �ƿ� 2353761 ��𪾧 */
#include <iostream>
#include <iomanip>
#include"cmd_console_tools.h"
#include"hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	int i,layers,x,y=0;
	char src,tmp,dst;
	while (1) {
		cct_cls();
		i = hanoi_menu();
		if (i == 48) {//0--ֱ�ӽ���
			return 0;
		}
		cct_getxy(x, y);
		cct_gotoxy(0, y + 3);

		shuru(&src, &tmp, &dst, &layers,i-48);                                                //�ӹ��ܺ� ֻ��5����
		chushihua(src, layers);
		set_sudu(src, dst, layers,i-48);                                                      //�ӹ��ܺ� ֻ��4&8��
		
		draw_column(src, dst, i - 48, layers);                                                 //���ж�������ֻ��5/6/7/8/9��
		draw_original(src, layers,i-48);                                                       //���ж������͹��ܺţ�ֻ��6/7/8/9��
		chushihua2(i - 48);                                                                   //�ж�������д��ֻ��4/8/9
		hanoi(layers, src, tmp, dst, i - 48);                                                  //���ж�������ֻ��5/6/7/9����
		switch (i) {
			case 55://7
				mark_number(1, src, layers % 2 == 1 ? dst : tmp);
				movement(src, layers % 2 == 1 ? dst : tmp, 1);
				break;
			case 57://9
				game_9_control(dst, layers);
				break;
		}
		if (i - 48 == 1 || i - 48 == 2 || i - 48 == 3) {
			cct_getxy(x, y);
		}
		else {
			y = 39;
		}
		print(0, y + 1);
	}
	return 0;
}
