#include <iostream>

using namespace std;

/****************************************

        C++ ���캯������������:

        1. ���캯�����ഴ������ʱ�Զ�����
        2. �������������������ʱ�Զ�����

*****************************************/

class Fruit{
    public:
        Fruit(){ //���캯������������ʱ�Զ�����
            cout << "���ǹ��캯�������������ʱ���Զ�����,�ҵ����ֱ����������ͬ��" <<
                "�Ҳ����з���ֵ����ʹ��voidҲ�����У������ҿ�����һ�����߶������!" << endl;
        }
        ~Fruit(){ //ǰ���~�������ֺ�����һ������������������
            cout << "�����������������������ʱ���Զ�����,�ҵ����ֱ����������ͬ��" <<
                "�Ҳ����з���ֵ����ʹ��voidҲ�����У���Ҳ�������κεĲ���!" << endl;
        }
        string getName();//��������ʵ��
        void setName(string n);//��������ʵ��
    private:
        string name;  //����
        double weight;//����
        string color; //��ɫ
        int number;   //����
};//ע��ֺ�

string Fruit::getName(){  //::���� ���������Fruit::getName ������Fruit���е�getName����
    return name;
}

void Fruit::setName(string n){
    name = n;
}

int main()
{
    string name;

    Fruit fru; //���������fru,��ʱ���Զ����ù��캯��

    fru.setName("banana");  //�����fru���ú���
    name = fru.getName();
    cout << "name = " << name << endl;

    return 0;
} //�������������,fru��������ٵ�����ʱ���Զ����ù��캯��

