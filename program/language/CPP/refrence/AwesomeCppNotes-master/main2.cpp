#include <iostream>
#include <cstdlib>

using namespace std;

/****************************************
    1. ���顢new��malloc���ڴ�������
    2. new��malloc������
*****************************************/

int main()
{
    int32_t array1[10] = {0};
    int32_t *array2 = new int32_t [10];
    int32_t *array3 = (int32_t *)malloc(sizeof(int32_t) * 10);
    int32_t array4[5][3] = {0};

    /****************    1    **************/

    cout << "���顢new��malloc���ǴӶ��Ϸ����ڴ�" << endl;

    //array1��array1[0]�ĵ�ַ
    cout << "array1��ֵ = " << array1 << ", &array1[0] = " << &array1[0] << endl;

    //�鿴array1�����Ԫ�صĵ�ַ�����Կ���������������
    cout << endl << "�鿴array1��Ԫ�صĵ�ַ�����������������4���ֽڣ���Ϊint32_tռ��4���ֽ�" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << array1 + i <<endl;
    }

    //�鿴array2�����Ԫ�صĵ�ַ�����Կ���������������
    cout << endl << "�鿴array2��Ԫ�صĵ�ַ�����������������4���ֽڣ���Ϊint32_tռ��4���ֽ�" << endl;
    cout << "new������ַ���߼��������������Ͽ�������Ҳ���ܲ�����" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << array2 + i <<endl;
    }

    //�鿴array3�����Ԫ�صĵ�ַ�����Կ���������������
    cout << endl << "�鿴array3��Ԫ�صĵ�ַ�����������������4���ֽڣ���Ϊint32_tռ��4���ֽ�" << endl;
    cout << "malloc������ַ���߼��������������Ͽ�������Ҳ���ܲ�����" << endl ;
    for(int i = 0; i < 10; i++)
    {
        cout << array3 + i <<endl;
    }
    cout << endl;

    //�鿴��ά�����ڴ����
    cout << "array4��array4[0]�ĵ�ַ : " << "array4 = " << array4 << ", &array4[0] = " << &array4[0] << endl;
    cout << "array4[0]��array4[0][0]�ĵ�ַ : " << "array4[0] = " << array4[0] << ", &array4[0][0] = " << &array4[0][0] << endl;
    cout << endl << "��ά������һά�������ʽ��ţ���ַ֮���3*4B = 12B:" << endl;
    cout << "array4[0] = " << array4[0] << endl;
    cout << "array4[1] = " << array4[1] << endl;
    cout << "array4[2] = " << array4[2] << endl;
    cout << "array4[3] = " << array4[3] << endl;

    cout << "����Ԫ��֮����һά������ʽ��ţ���ַ���4B" << endl;
    cout << "&array4[2][0] = " << &array4[2][0] << endl;
    cout << "&array4[2][1] = " << &array4[2][1] << endl;


    /****************    2    **************/
    cout << endl << "      new��malloc������       " << endl;
    cout << "1. new����Ҫָ���ڴ����ͣ����Ͱ�ȫ����malloc���ص��ڴ�Ϊvoid*����Ҫǿ��ת��;" << endl;
    cout << "2. new�Զ�ȷ���ڴ��С����malloc��Ҫ�ֶ�ָ��;" << endl;
    cout << "3. new���Զ����ù��캯��������delete�ͷ��ڴ��������������malloc��free�ͷ��ڴ�;" << endl;
    cout << "4. new/delete��C++�����������malloc/free��C++�Ŀ⺯��," <<
         "���ڱ���������Ȩ��֮�ڣ����ܹ���ִ�й��캯������������������ǿ�ӡ�" << endl;
}
