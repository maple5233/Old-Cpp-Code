#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
class str
{
private:
	int len;
	char* s;
public:
	str(){ s = new char[100]; len = 0; }
	str(const char* a)
	{
		int i;
		len = strlen(a);
		s = new char[len + 1];
		for (i = 0; i<len; i++)
		{
			*(s + i) = *(a + i);
		}
		*(s + len) = 0;
	}
	str(const str& a)
	{
		int i;
		len = a.len;
		s = new char[len + 1];
		for (i = 0; i<len; i++)
		{
			*(s + i) = *(a.s + i);
		}
		*(s + len) = 0;
	}
	~str()
	{
		delete[] s;
	}
	friend str operator +(const str& a, const str& b);
	friend str operator -(const str& a, const str& b);
	void operator =(const str& b)
	{
		len = b.len;
		int i = 0;
		for (i = 0; i<len; i++)
		{
			*(s + i) = *(b.s + i);
		}
		*(s + len) = 0;
	}
	void show()
	{
		cout << "length=" << len << ' ';
		int i;
		for (i = 0; i<len; i++)
			cout << *(s + i);
		cout << endl;
	}
};

str operator +(const str& a, const str& b)
{
	str c;
	int i = 0;
	c.len = a.len + b.len;
	c.s = new char[c.len + 1];
	for (i = 0; i<a.len; i++)
	{
		*(c.s + i) = *(a.s + i);
	}
	for (i = a.len; i<c.len; i++)
	{
		*(c.s + i) = *(b.s + i - a.len);
	}
	*(c.s + c.len) = 0;
	return c;
}
str operator -(const str& a, const str& b)
{
	char* p = strstr(a.s, b.s);

	if (p != NULL)//写成if (p != 0)或者if (p)也可
	{
		str c;
		int i = 0;
		c = a;
		c.len = a.len - b.len;
		c.s = new char[c.len + 1];
		int xia = p - a.s;
		for (i = xia; i<c.len; i++)
		{
			*(c.s + xia) = *(c.s + xia + b.len);
		}
		*(c.s + c.len) = 0;
		return c;
	}
	else return a;
}

int main()
{
	char a[100];
	char b[100];
	gets(a);
	gets(b);
	str s1(a);
	str s2(b);
	str s3;
	s3 = s1 + s2;
	str s4;
	s4 = s1 - s2;
	s3.show();
	s4.show();
	return 0;
}
