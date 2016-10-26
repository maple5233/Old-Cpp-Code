/*题目描述

完成如下所示的CDate类中构造函数和其它成员函数的定义，并编写程序实现按下列格式打印某个日期的功能：mm / dd / yyyy, 星期。

(提示：计算某个日期(day, month, year)为星期几的公式如下：
week = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7 + 1;
其中，如果month实际为1或2, 则计算时公式里month的值取13或14, 且year的值取其实际值减1的值）。

class CDate
{
public:
	void print();
	void getWeekofDay();
private:
	int month;
	int day;
	int year;
	int week;
};

输入

日期个数

第一个日期

第二个日期

.......

输出

日期1月 / 日期1日 / 日期1年, 日期1星期

日期2月 / 日期2日 / 日期2年, 日期2星期

......

样例输入

3
1949 10 1
2015 1 1
2011 11 11
样例输出

10 / 1 / 1949, Saturday
1 / 1 / 2015, Thursday
11 / 11 / 2011, Friday
提示*/