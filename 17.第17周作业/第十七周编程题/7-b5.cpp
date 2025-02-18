/* 2353761 ��𪾧 �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#include <cstring>
#include <iostream>
#include<iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	bool state_1,state_2;  //ѡ��״̬0-δѡ��1-ѡ��/state_1--��һ��ѡ�Σ�state_2--�ڶ���ѡ��
	//��Ԫ����
	friend class stu_list; 
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */
	void paixu();//����һ\����ѡ�ε�����������,Ȼ�󸳸�list_merge[MAX_STU_NUM]
	void fenxi();//��������ѡ������
};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::paixu()//�������У��������+�����ظ�
{
	int k=0;
	student tmp;
	for (int i = 0; i < MAX_STU_NUM-1; ++i) {
		k = i;
		for (int j = i+1; j < MAX_STU_NUM; ++j) {
			if (list_round_1[k].no < list_round_1[j].no) {
				k = j;
			}
		}
		tmp = list_round_1[k];
		list_round_1[k] = list_round_1[i];
		list_round_1[i] = tmp;
	}
	
	//����ָ�봦���ظ�
	student* slow= &list_round_1[1];
	for (int i = 1; list_round_1[i].no != 0; ++i) {
		if (list_round_1[i].no != list_round_1[i - 1].no) {
			*slow = list_round_1[i];
			++slow;
		}
	}
	while ((*slow).no != 0) {
		(*slow).no = 0;
		++slow;
	}
	
	for (int i = 0; i < MAX_STU_NUM - 1; ++i) {
		k = i;
		for (int j = i + 1; j < MAX_STU_NUM; ++j) {
			if (list_round_2[k].no < list_round_2[j].no) {
				k = j;
			}
		}
		tmp = list_round_2[k];
		list_round_2[k] = list_round_2[i];
		list_round_2[i] = tmp;
	}
	slow = &list_round_2[1];
	for (int i = 1; list_round_2[i].no != 0; ++i) {
		if (list_round_2[i].no != list_round_2[i - 1].no) {
			*slow= list_round_2[i];
			++slow;
		}
	}
	while ((*slow).no != 0) {
		(*slow).no = 0;
		++slow;
	}
	return;
}
void stu_list::fenxi()
{
	student* p = &list_round_1[0],*q= &list_round_2[0];
	while (p->no != 0) {
		++p;
	}
	--p;
	while (q->no != 0) {
		++q;
	}
	--q;
	for (int i = 0; i < MAX_STU_NUM; ++i) {
		if ((p->no) == (q->no)) {
			list_merge[i].stu_no = p->no;
			strcpy(list_merge[i].stu_name, p->name);
			--p;
			--q;
		}
		else if ((p->no )> (q->no)) {
			list_merge[i].stu_no = q->no;
			strcpy(list_merge[i].stu_name, q->name);
			--q;
		}
		else {
			list_merge[i].stu_no = p->no;
			strcpy(list_merge[i].stu_name, p->name);
			--p;
		}
		
	}//�������������������״̬
	
	for (int i = 0; list_merge[i].stu_no!=0; ++i) {
		list_merge[i].state_1 = 0;
		list_merge[i].state_2 = 0;
		for (int j = 0; j < MAX_STU_NUM; ++j) {
			if (list_round_1[j].no == list_merge[i].stu_no) {
				list_merge[i].state_1 = 1;
			}
		}
		for (int j = 0; j < MAX_STU_NUM; ++j) {
			if (list_round_2[j].no == list_merge[i].stu_no) {
				list_merge[i].state_2 = 1;
			}
		}
		
	}
	return;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
	for (int i = 0; i < MAX_STU_NUM; ++i) {
		list_round_1[i].no = 0;
		list_round_2[i].no = 0;
		list_merge[i].stu_no = 0;
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸� 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	cout << prompt << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                             ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	int i = 0;
	while (list_merge[i].stu_no >0) {
		cout << setw(5) << left << i + 1;
		cout << setw(9) << left << list_merge[i].stu_no;
		cout << setw(33) << left << list_merge[i].stu_name;
		if (list_merge[i].state_1 == 1) {
			cout << "Y      ";
		}
		else {
			cout << "/      ";
		}
		if (list_merge[i].state_2 == 1&& list_merge[i].state_1 == 1) {
			cout << "Y" << endl;
		}
		else if (list_merge[i].state_1 == 0 && list_merge[i].state_2 == 1) {
			cout << "��ѡ" << endl;
		}
		else if (list_merge[i].state_1 == 1 && list_merge[i].state_2 == 0) {
			cout << "�˿�" << endl;
		}
		i++;
	}
	cout<< "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */
	list.paixu();
	list.fenxi();


	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

