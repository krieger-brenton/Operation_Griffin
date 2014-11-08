#ifndef CPOINT_H
#define CPOINT_H

class CPoint
{
public:
	CPoint() : x(0), y(0) {}
	CPoint(int pX, int pY) { setX(pX); setY(pY); }
	void setX(int pX) { x = pX; }
	void setY(int pY) { y = pY; }
	int getX() { return x; }
	int getY() { return y; }
	//int difference(CPoint p);
private:
	int x;
	int y;
};

#endif /* CPOINT_H */