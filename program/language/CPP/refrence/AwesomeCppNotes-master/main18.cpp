#include <iostream>
using namespace std;

/*******************************************
                    C++ Ԥ����

Ԥ��������һЩָ�ָʾ��������ʵ�ʱ���֮ǰ������ɵ�Ԥ����
���е�Ԥ������ָ����Ծ��ţ�#����ͷ��ֻ�пո��ַ����Գ�����Ԥ����ָ��֮ǰ��Ԥ����ָ��� C++ ��䣬�������ǲ����Էֺţ�;����β��
֮ǰ���е�ʵ���ж��� #include ָ���������ڰ�ͷ�ļ�������Դ�ļ��У�
C++ ��֧�ֺܶ�Ԥ����ָ����� #include��#define��#if��#else��#line �ȣ�

**********************************************/


#define PI 3.14  //������

#define MIN(a, b) (a < b ? a : b)  //������

#define TEST



int main()
{
    double r  = 2.5;
    int a = 20, b = 34;

    cout << "area of circle is " << PI * r * r << endl;
    cout << "the smaller number is " << MIN(a, b) << endl;

#ifdef TEST  //ǰ���Ѿ��궨����TEST
    cout << "this is test code ! " << endl;
#endif // TEST

#ifdef 0  //�����0�Ļ����Ͳ��ᱻ���
    cout << "these codes won't not print" << endl;
#endif // 0
    return 0;
}
