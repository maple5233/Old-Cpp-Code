/*��Ŀ����

�����Ϊһ�ֶ���Ҳ������������������������԰���
������ơ�
����(�ֱ���O��T��B��ʾԭ�桢���ð滹�Ǳ���)��
��Ч��������(��CDate���Ӷ����ʾ)��
�洢����(�ֱ���D��H��U��ʾ���̡����̺�U��)�ȡ�

���������ͨ���������캯����ʵ�֣���ʱ�ڿ������캯����������͸ĳɡ�B��, �洢���ʸ�Ϊ"H"���������䡣

����ɸ���Ŀ������졢����ʹ�ӡ(������2015��4��7��������Ч�ڻ��ж����죬�Ƿ����)��Ա������ʵ�֡�

�����������Ч��ֹ������0��0��0�գ���ʾ���������ƣ�Ϊunlimited��
������������2015��4��7��֮ǰ�����ǹ��ڣ���ʾΪexpired��
�������������2015��4��7��֮������ʾ֮���ʣ�����������������Ϣ�����������


��CDate���ʵ�֣�

 class CDate
{
private:
    int year, month, day;
public:
    CDate(int y, int m, int d) { year = y; month = m; day = d; }
    bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear()         //�������ڴӵ���1��1�����������
    {
    int i, sum=day; 
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

        if (isLeapYear())
            for(i=0;i<month;i++)   sum +=b[i];
        else
            for(i=0;i<month;i++)   sum +=a[i];

         return sum;
    }
};

����

�������ݵ����� t

��һ���������

��һ���������  ��һ�������������  ��һ�������Ч���� �� ��

�ڶ����������

�ڶ���������� �ڶ�������������� �ڶ��������Ч���� �� ��

......

���

name: ��һ���������

type: ��һ���������

media: ��һ�������������

��һ�����2015-4-7�����Ч����

name: ��һ���������

type: backup

media: hard disk

��һ�����2015-4-7�����Ч����

......

��������

3
Photoshop_CS5
O D 0 0 0
Audition_3.0
B U 2015 2 3
Visual_Studio_2010
T H 2015 5 5
�������

name:Photoshop_CS5
type:original
media:optical disk
this software has unlimited use

name:Photoshop_CS5
type:backup
media:hard disk
this software has unlimited use

name:Audition_3.0
type:backup
media:USB disk
this software has expired

name:Audition_3.0
type:backup
media:hard disk
this software has expired

name:Visual_Studio_2010
type:trial
media:hard disk
this software is going to be expired in 28 days

name:Visual_Studio_2010
type:backup
media:hard disk
this software is going to be expired in 28 days
��ʾ

*/