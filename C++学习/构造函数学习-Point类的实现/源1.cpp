/*在主函数中根据用户输入的数目建立Point数组，求出数组内距离最大的两个点之间的距离值。

输入

测试数据的组数 t

第一组点的个数

第一个点的 x 坐标   y坐标

第二个点的 x坐标  y坐标

............

输出

输出第一组距离最大的两个点以及其距离

...........

在C++中，输出指定精度的参考代码如下：

#include <iostream>

#include <iomanip> //必须包含这个头文件

using namespace std;

void main( )

{ double a =3.141596;

  cout<<fixed<<setprecision(3)<<a<<endl;  //输出小数点后3位

样例输入

2
4
0 0
5 0
5 5
2 10
3
-1 -8
0 9
5 0
样例输出

Constructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 10.44,between p[1] and p[3].
Distructor.
Distructor.
Distructor.
Distructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 17.03,between p[0] and p[1].
Distructor.
Distructor.
Distructor.
*/

/*
问题 B: Point_Array(类与对象)
一、要求Point类，未满足，则扣3分：
1. 私有属性:
double x;
double y;
2. 方法包含（每个函数只能有一个！且按照给定函数定义来实现，不得修改参数和返回类型）：
①无参构造函数：x，y分别赋值为0
②有参构造函数：给x，y分别赋值
③拷贝构造函数：通过现有对象构造新对象
④析构函数：
⑤get方法：
⑥set方法：
⑦getDisTo方法：求两个点之间的距离
二、对每个函数的要求：
1．无参构造函数：无参数，x、y分别赋值为0，否则扣1分；
2．有参构造函数：参数为横坐标和纵坐标，否则扣1分；
3．拷贝构造函数：参数只能是一个对象，可为const Point&或Point &，，否则，扣2分；
4．析构函数：做相关输出
5．get方法：按照给出的函数定义实现
6．set方法：按照给出的函数定义实现
7．getDisTo方法：要求参数为const Point& p，且return两个点的距离，不能在此函数中求多个点之间的距离。否则扣2分。
三、main函数：
要求：
Constructor. 和Distructor. 两条语句是在构造函数和析构函数中做输出，不得在main函数中输出，否则扣2分。
建立一个动态分配的Point数组*p（new的过程即调用无参构造函数），通过set函数修改x，y的值，在main函数中进行对这个点数组两两求距离，进而求出最大距离。否则，扣2分。
无delete Point数组，扣2分！
*/