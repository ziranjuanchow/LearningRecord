
#include <iostream>

using namespace std;

/****************************************

                 C++ ����
       1. Overload,������Ҫ������ͬһ��������
       2. ����д��ͬ������ֻҪ�󷽷���һ�£������Ĳ����ͷ���ֵ���Բ�ͬ

*****************************************/


class Fruit{
    public:
        double add_tare_and_core(double tareWeight, double coreWeight){
            cout << "double" << endl;
            return tareWeight + coreWeight;
        }
        int add_tare_and_core(int tareWeight, int coreWeight){  // ��������ĺ���
            cout << "int" << endl;
            return tareWeight + coreWeight;
        }
};



int main()
{
    Fruit fru;

    cout << "���ػ���ݲ����������������Զ����ö�Ӧ����" << endl;
    cout << fru.add_tare_and_core(5.33, 2.81) << endl;
    cout << fru.add_tare_and_core(5, 3) << endl;

    return 0;
}


