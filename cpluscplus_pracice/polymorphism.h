#pragma once


class Point
{
public:
	Point(float x = 0, float y = 0);//���캯��
	void setPoint(float a, float b);//��������ֵ
	float getX()const//��ȡx����
	{
		return _x;
	}
	float getY()const//��ȡy����
	{
		return _y;
	}
	friend ostream& operator<<(ostream& _cout, const Point& p);
protected:
	float _x;
	float _y;
};


class Circle :public Point
{
public :
	Circle(float x = 0, float y = 0, float r = 0);//���캯��
	void setRadius(float r);//���ð뾶ֵ
	float getRadius()const;//��ȡ�뾶ֵ
	float area()const;
	friend ostream& operator<<(ostream& _cout, const Circle& c);
protected :
	float radius;
};


class Cylinder :public Circle
{
public :
	Cylinder(float x = 0, float y = 0, float r = 0, float h = 0);
	void setHeight(float h);
	float getHeight()const;
	float area()const;
	float volume()const;
	friend ostream& operator<<(ostream& _cout, const Cylinder& c);
protected :
	float height;
};