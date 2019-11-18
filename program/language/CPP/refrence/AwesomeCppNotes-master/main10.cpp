

#include <iostream>

using namespace std;

/****************************************

                 C++ ģ��
       C++ģ���ܰ���������ͬ������Բ�ͬ��������ʱ������
       1. ����ģ��
       2. ��ģ��
       3. ģ���ض��� template specialization

*****************************************/


///////////    ģ���ػ� /////////////////

template <class T>   //ģ�壬 T�����Լ��滻��������

class Compare{
    public:
        void foo(T x){
            cout << x << " is not a string" << endl;
        }
};

template <>

class Compare<string>{
    public:
        void foo(string x){
            cout << x << " is a string" << endl;
        }
};

int main()
{
    Compare<double> comp1;
    Compare<string> comp2;

    comp1.foo(2.35);
    comp2.foo("hi");

    return 0;
}












