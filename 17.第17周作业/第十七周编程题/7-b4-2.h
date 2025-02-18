/* 2353761 ��𪾧 �ƿ� */
#pragma once

/* ���������Ҫ��ͷ�ļ�������ռ� */
#include<cmath>
class triangle;  //�����ǰ������˼��һ�£����������Ŀ����Ϊʲô

/* point��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class point {
private:
	int x;
	int y;
public:
	/* �������ڴ����һ����Ա����������1����,Ҫ������ʵ�� */
	void set(int m, int n)
	{
		x = m;
		y = n;
		return;
	}
	/* ������������Ǹ���Ա�����⣬������������κε����ݳ�Ա�ͳ�Ա�����������Ը�����Ҫ����������� */
	friend class triangle;      //��Ԫ�����˽�г�Ա
};

/* triangle��Ķ��弰ʵ�֣��Ѹ����������ݣ���Ҫ�󲹳���� */
class triangle {
private:
	point p1;
	point p2;
	point p3;
	//�����������private���ݳ�Ա�⣬������������κ����͵����ݳ�Ա
public:
	/* ���캯������ʵ�֣���׼���� */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* ��p1/p2/p3������ֱ�x,y����ֵ */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}

	/* ������Ҫ������Ӧ���������area����(�β�Ϊ�գ���׼��)��
           Ҫ����������ܹ��������Σ��򷵻���������򷵻� -1 */
	double area()
	{
		double a, b, c;
		a = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
		b = sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
		c = sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y- p3.y));
		if ((a + b > c) && (a + c > b) && (b + c > a) && (fabs(a - b) < c) && (fabs(a - c) < b) && (fabs(b - c) < a)) {
			return double(abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y))) / 2;
		}
		else {
			return -1;
		}
	}
	/* ���Զ�����Ҫ�ĳ�Ա�������������ޣ��������ڷ�ʽʵ�֣�������������ݳ�Ա */

};
