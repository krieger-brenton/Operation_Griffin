#pragma once
#include <iostream>
#include <math.h>

class CPoint
{
public:
	CPoint() : x(0), y(0) {}
	CPoint(int pX, int pY) { setX(pX); setY(pY); }
	void setX(int pX) { x = pX; }
	void setY(int pY) { y = pY; }
	int getX() { return x; }
	int getY() { return y; }
	void setPoint(int pX, int pY) { x = pX; y = pY; }
	int difference(CPoint p) { return std::sqrt(std::pow(x + p.getX(), 2) + std::pow(y + p.getY(), 2)); }
private:
	int x;
	int y;
};

inline std::ostream& operator<<(std::ostream& out, CPoint & point){
	return out << "(" << point.getX() << ',' << point.getY() << ")";
}