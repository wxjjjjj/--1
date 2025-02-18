/* 2353761 ��𪾧 �ƿ� */
#include <iostream>
using namespace std;

/* 1�����������κ����͵�ȫ�ֱ������������������궨���
   2������������κ���ʽ��ȫ�ֺ���
*/

/* --- ����Ķ��岹������ --- */
class Days {
private:
	int year;
	int month;
	int day;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա

	/* ������Բ�����Ҫ�����Ա�����Ķ��壨���ṩ����磬���������������Ա�������ã��������Ϊ˽�У��������ޣ��������壩 */

public:
	Days(int year, int month,int day);
	int calc_days();     //�����ǵ���ĵڼ���

	/* ������Բ���������Ҫ�����Ա�����Ķ���(����ʵ��)���������ޣ��������� */

};

/* --- �˴��������Ա����������ʵ�� --- */
int Days::calc_days()
{
	int d=0;
	switch (month) {
		case 1:
			if (day>= 0 && day <= 31) {
				d = day;
			}
			else {
				d = -1;
			}
			break;
		case 2:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 29 && day >= 0) {
					d = 31 + day;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 28 && day >= 0) {
					d = 31 + day;
				}
				else {
					d = -1;
				}
				break;
			}
		case 3:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28;
				}
				else {
					d = -1;
				}
				break;
			}
		case 4:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 30 && day >= 0) {
					d = 31 + day + 29 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 30 && day >= 0) {
					d = 31 + day + 28 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
		case 5:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		case 6:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 30 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 30 && day >= 0) {
					d = 31 + 31 + day + 28 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		case 7:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		case 8:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
		case 9:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 30 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 30 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
		case 10:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		case 11:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 30 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 30 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
				}
				else {
					d = -1;
				}
				break;
			}
		case 12:
			if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {   //�棬��Ϊ����,������29��
				if (day <= 31 && day >= 0) {
					d = 31 + day + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
			else {
				if (day <= 31 && day >= 0) {
					d = 31 + day + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
				}
				else {
					d = -1;
				}
				break;
			}
		default:
			cout << "�������-�·ݲ���ȷ" << endl;
			break;
	}
	return d;
}
Days::Days(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
 ***************************************************************************/
int main()
{
	if (1) {
		Days d1(2024, 3, 18);//���ݳ�Ա��˽�У����Բ���ֱ���������ķ�����ʼ��
		cout << "Ӧ�����78�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 3, 18);
		cout << "Ӧ�����77�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 12, 31);
		cout << "Ӧ�����366��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 12, 31);
		cout << "Ӧ�����365��ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2024, 2, 29);
		cout << "Ӧ�����60�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	if (1) {
		Days d1(2023, 2, 29);
		cout << "Ӧ�����-1�� ʵ���ǣ�" << d1.calc_days() << endl;
	}

	return 0;
}
