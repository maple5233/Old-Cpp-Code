#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point
{
	double x, y;
public:
	Point();
	Point(double x_value, double y_value);
	double getX();
	double getY();
	void setX(double x_value);
	void setY(double y_value);
	double distanceToAnotherPoint(Point p);
};
Point::Point()
{
	x = 0;
	y = 0;
}
Point::Point(double x_value, double y_value)
{
	x = x_value;
	y = y_value;
}
double Point::getX()
{
	return x;
}
double Point::getY()
{
	return y;
}
void Point::setX(double x_value)
{
	x = x_value;
}
void Point::setY(double y_value)
{
	y = y_value;
}
double Point::distanceToAnotherPoint(Point p)
{
	double d;
	d = (p.getX() - x)*(p.getX() - x) + (p.getY() - y)*(p.getY() - y);
	d = sqrt(d);
	return d;
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		double a, b, c, d, distance;
		cin >> a >> b >> c >> d;
		Point m;
		Point n;
		m.setX(a);
		m.setY(b);
		n.setX(c);
		n.setY(d);
		distance = m.distanceToAnotherPoint(n);
		cout << setiosflags(ios::fixed);
		cout << "Distance of Point(" << setprecision(2) << m.getX() << ",";
		cout << setprecision(2) << m.getY() << ") to Point(";
		cout << setprecision(2) << n.getX() << "," << setprecision(2) << n.getY() << ") is ";
		cout << setprecision(2) << distance << endl;
	}
	return 0;
}
