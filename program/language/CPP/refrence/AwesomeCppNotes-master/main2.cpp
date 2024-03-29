#include <iostream>
#include <cstdlib>

using namespace std;

/****************************************
    1. 数组、new、malloc的内存分配情况
    2. new和malloc的区别
*****************************************/

int main()
{
    int32_t array1[10] = {0};
    int32_t *array2 = new int32_t [10];
    int32_t *array3 = (int32_t *)malloc(sizeof(int32_t) * 10);
    int32_t array4[5][3] = {0};

    /****************    1    **************/

    cout << "数组、new和malloc都是从堆上分配内存" << endl;

    //array1是array1[0]的地址
    cout << "array1的值 = " << array1 << ", &array1[0] = " << &array1[0] << endl;

    //查看array1里面各元素的地址，可以看到其是连续分配
    cout << endl << "查看array1各元素的地址，其连续分配且相差4个字节，因为int32_t占用4个字节" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << array1 + i <<endl;
    }

    //查看array2里面各元素的地址，可以看到其是连续分配
    cout << endl << "查看array2各元素的地址，其连续分配且相差4个字节，因为int32_t占用4个字节" << endl;
    cout << "new出来地址是逻辑上连续，物理上可能连续也可能不连续" << endl;
    for(int i = 0; i < 10; i++)
    {
        cout << array2 + i <<endl;
    }

    //查看array3里面各元素的地址，可以看到其是连续分配
    cout << endl << "查看array3各元素的地址，其连续分配且相差4个字节，因为int32_t占用4个字节" << endl;
    cout << "malloc出来地址是逻辑上连续，物理上可能连续也可能不连续" << endl ;
    for(int i = 0; i < 10; i++)
    {
        cout << array3 + i <<endl;
    }
    cout << endl;

    //查看二维数组内存分配
    cout << "array4是array4[0]的地址 : " << "array4 = " << array4 << ", &array4[0] = " << &array4[0] << endl;
    cout << "array4[0]是array4[0][0]的地址 : " << "array4[0] = " << array4[0] << ", &array4[0][0] = " << &array4[0][0] << endl;
    cout << endl << "二维数组以一维数组的形式存放，地址之间差3*4B = 12B:" << endl;
    cout << "array4[0] = " << array4[0] << endl;
    cout << "array4[1] = " << array4[1] << endl;
    cout << "array4[2] = " << array4[2] << endl;
    cout << "array4[3] = " << array4[3] << endl;

    cout << "相邻元素之间以一维数组形式存放，地址相差4B" << endl;
    cout << "&array4[2][0] = " << &array4[2][0] << endl;
    cout << "&array4[2][1] = " << &array4[2][1] << endl;


    /****************    2    **************/
    cout << endl << "      new和malloc的区别       " << endl;
    cout << "1. new不需要指定内存类型，类型安全，而malloc返回的内存为void*，需要强制转换;" << endl;
    cout << "2. new自动确定内存大小，而malloc需要手动指定;" << endl;
    cout << "3. new会自动调用构造函数，并由delete释放内存调用析构函数，malloc由free释放内存;" << endl;
    cout << "4. new/delete是C++的运算符，而malloc/free是C++的库函数," <<
         "不在编译器控制权限之内，不能够把执行构造函数和析构函数的任务强加。" << endl;
}
