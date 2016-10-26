/************************************************************************/
/*                             C++��ҵ(1.26-2.4)		                    */
/*                   �����������ʽʵ�ֶ���ʽ����������			            */
/*                             ģ������                                   */
/*                     ����ģ���д �����ʵ���ӳ�Ա����						*/
/************************************************************************/

#include<iostream>
using namespace std;

/**����(�ڵ�)��**/
class Term
{
public:
	int expn; //ָ��
	float coef;//ϵ��
	Term* next;//��һ��;
	Term();//���캯�� ��ָ����ϵ����ֵΪ0 ��һ�ֵΪNULL;
};
/**�������� �����**/
class LinkList
{
private:
	Term* head;//ͷ�ڵ�;
	int length;//��;
public:
	void create(int m);//������Ϊm������ ���麯��;
	void insert(Term e);//����ڵ�;
	void del(int x);//ɾ����x�� ��x��1��ʼ;
	void display();//��ʾ������ д�ɴ��麯��;
};
/**����ʽ�� �̳е�������**/
class Polynomial
{
private:
	double vaule;//����ʽ��ֵ ��ʼ��Ϊ0;
	double x;//����ʽ��x�ĵ�ǰֵ ��ʼ��Ϊ0;
public:
	Polynomial();//���캯�� ��ʼ��;
	void create(int m);//��д ����m�����ʽ ���麯��;
	void sort();//������ʽ����������;
	void calculate(double x);//��������x�����������ʽ��ֵ����value;
	void display();//��д display()����;
	/**
	*   ��display()������Ҫ������:
	*   1.����ʽ�ӵʹ���ߴ����������;
	*	2.��һ���������������ʽΪ����;
	*	Ȼ����ѧ��ʽ�������ʽ �� -x^(-1) +1 -x +x^3 ������ (-1)x^(-1) +1 +(-1)x +x^3;
	*   3.�ڶ������ ��xֵΪxʱ������ʽ��ֵΪvaule;
	**/
};
/**ȫ�ֺ�����**/
Polynomial addPolyn(Polynomial a, Polynomial b);//����ʽ���;
Polynomial mulPolyn(Polynomial a, Polynomial b);//����ʽ���;
/**������**/
int main()
{
	/**�Զ���ʽ�Ĺ��ܽ��в���**/
	return 0;
}
