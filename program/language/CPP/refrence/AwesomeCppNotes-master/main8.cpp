
#include <iostream>

using namespace std;

/****************************************

                 C++ ģ��
       C++ģ���ܰ���������ͬ������Բ�ͬ��������ʱ������
       1. ����ģ��
       2. ��ģ��
       3. ģ���ض���

*****************************************/


///////////    ����ģ�� /////////////////

template <class T>   //ģ�壬 T�����Լ��滻��������

T addOperator(T x1, T x2){
    return x1 + x2;
}

template <class FIRST, class SECOND>  //����������ģ��

FIRST smaller(FIRST a, SECOND b){
    return (a < b ? a : b);
}

int main()
{
    int a = 3, b = 4;
    double c = 3.2, d = 4.7;

    //���㶨��ĺ���������int���ͣ������ݵ�ʵ����doubleʱ���϶��ǲ��еġ��෴����ˡ�
    //��ʱģ����Խ�������⡣˼��һ�£�ģ����ʱ�ܽ���������ص�һ����Ӧ��
    cout << "a + b = " << addOperator(a, b) << endl;
    cout << "c + d = " << addOperator(c, d) << endl;

    cout << "the smaller number is " << smaller(a, c) << endl;
    cout << "the smaller number is " << smaller(c, b) << endl;
    return 0;
}

