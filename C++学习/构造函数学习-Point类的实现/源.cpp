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
	Point(const Point& ano);
	~Point();
	double getX() const;
	double getY() const;
	void setX(double x_value);
	void setY(double y_value);
	double getDisTo(const Point &p);
};
Point::Point()
{
	x = 0;
	y = 0;
	cout << "Constructor." << endl;
}
Point::Point(double x_value, double y_value)
{
	x = x_value;
	y = y_value;
	cout << "Constructor." << endl;
}
Point::Point(const Point& ano)
{
	x = ano.x;
	y = ano.y;
	cout << "Constructor." << endl;
}
Point::~Point()
{
	cout << "Distructor." << endl;
}
double Point::getX()const
{
	return x;
}
double Point::getY()const
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
double Point::getDisTo(const Point &p)
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
		int num,i,m;
		cin >> num;
		double dis=0,maxd=0;
		int c, d;
		Point *a = new Point[num];
		for (i = 0; i < num; i++)
		{
			int j = 0, k = 0;
			cin >> j>> k;
			(a + i)->setX(j);
			(a + i)->setY(k);
		}
		for (i = 0; i < num; i++)
		{
			for (m = 0; m < num; m++)
			{
				dis = (a + i)->getDisTo(*(a + m));
				if (dis > maxd)
				{
					maxd = dis;
					c = i;
					d = m;
				}
			}
		}
		cout << "The longeset distance is ";
		cout << setiosflags(ios::fixed);
		cout << setprecision(2) << maxd << ',';
		cout << "between p[" << c << "] and p[" << d << "]." << endl;
		delete[]a;
	}
	return 0;
}
