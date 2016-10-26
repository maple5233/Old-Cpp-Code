/************************************************************************/
/*                             C++作业(1.26-2.4)		                    */
/*                   以面向对象形式实现多项式相加相乘运算			            */
/*                             模板如下                                   */
/*                     请照模板编写 可以适当添加成员函数						*/
/************************************************************************/

#include<iostream>
using namespace std;

/**数项(节点)类**/
class Term
{
public:
	int expn; //指数
	float coef;//系数
	Term* next;//下一项;
	Term();//构造函数 将指数和系数赋值为0 下一项赋值为NULL;
};
/**单链表类 虚基类**/
class LinkList
{
private:
	Term* head;//头节点;
	int length;//表长;
public:
	void create(int m);//创建表长为m的链表 纯虚函数;
	void insert(Term e);//插入节点;
	void del(int x);//删除第x项 且x从1开始;
	void display();//显示单链表 写成纯虚函数;
};
/**多项式类 继承单链表类**/
class Polynomial
{
private:
	double vaule;//多项式的值 初始化为0;
	double x;//多项式的x的当前值 初始化为0;
public:
	Polynomial();//构造函数 初始化;
	void create(int m);//重写 创建m项多项式 纯虚函数;
	void sort();//将多项式按次数排序;
	void calculate(double x);//代入数据x　计算出多项式的值赋给value;
	void display();//重写 display()方法;
	/**
	*   对display()方法的要求如下:
	*   1.多项式从低次向高次排序后才输出;
	*	2.第一行先输出：“多项式为：”;
	*	然后按数学格式输出多项式 如 -x^(-1) +1 -x +x^3 而不是 (-1)x^(-1) +1 +(-1)x +x^3;
	*   3.第二行输出 当x值为x时，多项式的值为vaule;
	**/
};
/**全局函数区**/
Polynomial addPolyn(Polynomial a, Polynomial b);//多项式相加;
Polynomial mulPolyn(Polynomial a, Polynomial b);//多项式相乘;
/**主函数**/
int main()
{
	/**对多项式的功能进行测试**/
	return 0;
}
