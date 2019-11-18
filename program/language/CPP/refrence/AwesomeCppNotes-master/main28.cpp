#include <iostream>
#include <sstream>
#include <boost/format.hpp>

using namespace std;

int main()
{
    /******************   <sstream> stringstream     ******************/
    //把int转换成字符串，把int和字符串连接起来
	stringstream s0;
	char s1[] = "789";
	string s2("56.5");
	string s2_("h q");
	s0 << "hello" << 123 << s1 << s2_; //把所有内容读进s0，可以有空格
	s0 << s2;

    string s3 = s0.str();
	cout << s3 << endl;
    //把string或char*类型的字符串转换成int
	double y;
    stringstream s7;
    s7 << s2;
    //s7 << s1;
    s7 >> y;
    cout << y << endl;

	string s4;
	while(s0 >> s4)   //把s0的所有内容读进s4，读进的过程中自动会在空白符处断开
        cout << s4 << endl;

    /******************   <boost/format.hpp> boost::format     ******************/
    //把int和字符串连接起来
	string s5 = (boost::format("%1% --  %2%  test") % "ad" % 2).str();
    cout << s5 << endl;

    //字符串转int
    string s6("1243");
    int x = std::atoi(s6.c_str());  // atol(long), atof(float), atod(double) 等
    cout << x << endl;


	return 0;
}
