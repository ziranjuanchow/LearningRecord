#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1("HI I am a pretty boy!");

    cout << "s1.substr(10, 6) = " << s1.substr(10, 6) << endl;  //��ȡ���ַ������ӵ�10���ַ���ʼ��ȡ����Ϊ6�����ַ���

    string s2("I am a s and am a b");
    cout << "s2.find(am) = " << s2.find("am") << endl;   //Ѱ�����ַ�����λ��
    cout << "s2.rfind(am) = " << s2.rfind("am") << endl; //���ַ���ĩβ��ʼѰ��

    string s3("interesting");
    cout << "s3 = " << s3 << endl;
    cout << "s3.erase(3, 5) = " << s3.erase(3, 5) << endl; //ɾ�����ַ������ӵ�3���ַ���ʼɾ������Ϊ5�����ַ���������֮���ֱ�Ӹı�ԭ�ַ���

    string s4("amazing");
    cout << "s4 = " << s4 << endl;
    cout << "s4.replace(3, 2) = " << s4.replace(3, 2, "HHHHH") << endl; //�滻���ַ������ӵ�3���ַ���ʼ�滻����Ϊ2�����ַ���������֮���ֱ�Ӹı�ԭ�ַ���

    string s5("comeon");
    cout << "s5 = " << s5 << endl;
    cout << "s5.insert(3, \"lucky\") = " << s5.insert(3, "lucky") << endl; //�������ַ������ӵ�3���ַ���ʼ�������ַ���������֮���ֱ�Ӹı�ԭ�ַ���

    string one("apple"), two("banana");
    cout << "swap֮ǰ : one = " << one << "\t two = " << two << endl; //�����ַ���������֮��ֱ�Ӹı�ԭ�ַ���
    one.swap(two);
    cout << "swap֮�� : one = " << one << "\t two = " << two << endl;


    return 0;
}
