/* �ƿ� 2353761 ��𪾧 */
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void danwei_function(int n)
{
	switch (n) {
		case 0:
			result=result+"ʰ";
			break;
		case 1:
			result=result+"��";
			break;
		case 2:
			result=result+"Ǫ";
			break;
		case 3:
			result=result+"��";
			break;
		case 4:
			result=result+"ʰ";
			break;
		case 5:
			result=result+"��";
			break;
		case 6:
			result=result+"Ǫ";
			break;
		case 7:
			result=result+"��";
			break;
		case 8:
			result=result+"ʰ";
			break;
		case 9:
			result=result+"Բ";
			break;
		case 10:
			result=result+"��";
			break;
		case 11:
			result=result+"��";
			break;
		case 12:
			result=result+"��";
			break;
	}
	return;
}
void result_function(int array[])
{
	int tmp = 0;
	for (int i = 0; i < 10; ++i) {
		//�ȴ�������
		if (array[i] != 0) {
			result=result+chnstr[2 * array[i]]+ chnstr[2 * array[i]+1];
		}
		else {
			if (i != 0 && i != 1 && i != 5) {
				for (int j = 0; j < i; ++j) {
					tmp = tmp + array[j];
				}
				if (tmp > 0 && array[i + 1] > 0 && i != 9) {
					result = result + chnstr[2 * array[i]] + chnstr[2 * array[i] + 1];
				}
				else if (tmp + array[10] + array[11] == 0 && i == 9) {
					result = result + chnstr[2 * array[i]] + chnstr[2 * array[i] + 1];
				}
				tmp = 0;
			}
		}
		//����λ
		if (i != 1 && i != 5 && i != 9) {
			if (array[i] != 0) {
				danwei_function(i);
			}
		}
		else {
			if (i == 1) {
				if (array[0] + array[1]) {
					danwei_function(i);
				}
			}
			else if (i == 5) {
				if (array[2] + array[3] + array[4] + array[5]) {
					danwei_function(i);
				}
			}
			else {
				for (int j = 0; j <= i; ++j) {
					tmp = array[j] + tmp;
				}
				if (tmp == 0 && (array[10] != 0 || array[11] != 0)) {
					;
				}
				else {
					danwei_function(i);
				}

			}
		}
	}
	//�ǡ��ֵ�������
	if (array[10] == 0 && array[11] == 0) {
		danwei_function(12);
	}
	else if (array[10] != 0 && array[11] == 0) {
		if (array[10] != 0) {
			result = result + chnstr[2 * array[10]] + chnstr[2 * array[10] + 1];
		}
		danwei_function(10);
		danwei_function(12);
	}
	else if (array[10] == 0 && array[11] != 0) {
		for (int j = 0; j < 10; ++j) {
			tmp = tmp + array[j];
		}
		if (tmp > 0) {
			result = result + chnstr[2 * array[10]] + chnstr[2 * array[10] + 1];
		}
		if (array[11]) {
			result = result + chnstr[2 * array[11]] + chnstr[2 * array[11] + 1];
		}
		danwei_function(11);
	}
	else {
		if (array[10] != 0) {
			result = result + chnstr[2 * array[10]] + chnstr[2 * array[10] + 1];
		}
		if (array[10] != 0) {
			danwei_function(10);
		}
		if (array[11] != 0) {
			result = result + chnstr[2 * array[11]] + chnstr[2 * array[11] + 1];
		}
		if (array[11] != 0) {
			danwei_function(11);
		}
	}
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
    /* --���������Ҫ������ --*/
	cout << "������[0-100��)֮�������:" << endl;;
	double a, d, x;
	int shuzi[12] = { 0 };
	cin >> a;
	a = a + 0.005;                              //�ֲ�ʵ�����������λС����Ҫ��С-0.0005���Դ�����
	long c;                                     //��Ϊlong long��dev�б��벻ͨ����������long��
	x = a / 100;								    //��������������ݱ�ò���������11��9λ����������� ����ʱ��λС������λС����
	c = (long)x;									//�����������������ִ���c��
	d = x - c;								    //��С�����ִ���d��

	shuzi[7] = c % 10;									//��λ����

	c = c / 10;
	shuzi[6] = c % 10;									//ǧλ����

	c = c / 10;
	shuzi[5] = c % 10;									//��λ����

	c = c / 10;
	shuzi[4] = c % 10;									//ʮ��λ����

	c = c / 10;
	shuzi[3] = c % 10;									//����λ����

	c = c / 10;
	shuzi[2] = c % 10;									//ǧ��λ����

	c = c / 10;
	shuzi[1] = c % 10;									//��λ����

	c = c / 10;
	shuzi[0] = c % 10;									//ʮ��λ����

	shuzi[8] = (int)(d * 10);                            //ʮλ����
	shuzi[9] = (int)((d - shuzi[8] * 0.1) / 0.01);              //Բλ����
	shuzi[10] = (int)((d - 0.1 * shuzi[8] - 0.01 * shuzi[9]) / 0.001);									//��λ����
	shuzi[11] = (int)((d - 0.1 * shuzi[8] - 0.01 * shuzi[9] - 0.001 * shuzi[10]) / 0.0001);									//��λ����

	cout << "��д�����:" << endl;
	result_function(shuzi);

    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
