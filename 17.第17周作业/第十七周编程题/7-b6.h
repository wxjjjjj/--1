/* 2353761 ��𪾧 �ƿ� */
#pragma once

/* --- �������Ҫ��ͷ�ļ�������ռ䣬д�ڴ˴� --- */

/* --- �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� --- */

/* --- ���������ȫ�ֺ�����Ҫ������д�ڴ˴� --- */

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* ������������ݳ�Ա */

public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
	Date(int y , int m , int d);
	Date();
	Date(int days);
	void set(int y, int m, int d);
	void set(int y, int m);
	void set(int y);
	void get(int &y, int& m, int& d);
	void show();
};
