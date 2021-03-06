/*定义一个身份证类PID，包含私有属性：身份证类型、身份证号码、出生日期；另外包含方法：构造、打印、升级。

身份证类型表示一代身份证或者二代身份证，分别用1和2表示

身份证号码是一个字符串，长度为15或者18

出生日期是一个类，包含私有属性年、月、日，以及构造函数和获取属性的get方法

构造函数的作用就是接受外来参数，并设置各个属性值，注意这里因为有复合类，所以要考虑复合类成员的构造

打印函数的作用就是把身份证的所有属性都输出，输出格式看示例

升级函数的作用是如果身份证号码是15位的就升级为18位，包括把身份证类型改为2，然后把号码扩展，规则如下：

1. 原15位身份证的第7位到12位表示出生年月日，每个两位；把年份的2位扩展为四位。

2. 把扩展后的17个数字求和，取总和的末尾数字，如果末尾数字是0，则将0改为X，然后把这个数字作为第18位

例如身份证123456910203000，表示91年2月3日出生，然后根据类属性出生日期知道是1991年，不是2091年。因此扩展为12345619910203000

接着把17个数字相加得到46，取末尾6，最终扩展为123456199102030006

输入

第一行输入t表示t个示例

第二行输入一个身份证的5个属性，顺序为：类型、号码、出生年、月、日

依次输入t行

输出

对每个身份证对象调用升级方法，对身份证进行升级

然后调用每个对象的打印方法进行输出

样例输入

3
1 123456910203000 1991 2 3
2 654321200001018889 2000 1 1
1 234567001217000 2000 12 17
样例输出

type=2 birth=1991.02.03
ID=123456199102030006
type=2 birth=2000.01.01
ID=654321200001018889
type=2 birth=2000.12.17
ID=23456720001217000X


题 C: 身份证设定（复合类）
一、要求Date类，未满足，则扣3分：
1. 私有属性：年、月、日
2. 方法包含：
①有参构造函数：三个参数，对年、月、日进行赋值，否则扣2分
②get方法：三个get方法，分别获取年、月、日，缺一不可，否则扣2分
二、要求PID类，未满足，则扣3分：
1. 私有属性：身份证类型（int）、身份证号码（字符串类型，要求用动态数组char* 或者 string）、出生日期（Date类型、复合类）
2. 方法包含（每个函数只能有一个！）：
①有参构造函数：对每个属性进行赋值
②打印函数：输出身份证类型、生日、身份证号码
③升级函数：对身份证类型进行升级，同时对身份证号码进行修改
三、对PID类每个函数的要求：
1．有参构造函数：必须使用初始化列表对复合类进行初始化（见ppt），即参数为身份证类型、身份证号码、年、月、日（不能为Date对象），否则扣4分；
2．打印函数：按照输出要求输出身份证类型、生日、身份证号码，否则扣2分；
3．升级函数：将type类型进行更改，同时对身份证号码进行升级，升级内容见题目描述。若用char *类型表示身份证号码，当重新进行new数组时，必须delete原来的数组，否则扣2分！
三、main函数：
要求：
不得在main函数中输出，只能通过调用PID类的print函数，否则扣2分。
PID类对象必须调用构造函数进行初始化，不能通过其他方法，否则扣3分。


*/