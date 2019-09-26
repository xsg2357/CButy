//
// Created by Administrator on 2019/9/26.
//

#include <iostream>

using namespace std;

/**
 * 引用：
 * 给变量起别名
 * 语法：数据类型 &别名 = 原名
 */
int main301() {

    int a = 10;
    int &b = a;//别名

    cout << " a = " << a << endl; // 10
    cout << " b = " << b << endl;// 10


    b = 20;
    cout << " a = " << a << endl;// 20
    cout << " b = " << b << endl;// 20

    return 0;
}

/**
 * 引用必须初始化，初始化之后不可改变
 */
int main302() {


    int a = 10;
    int &b = a;//别名
//    int &b ;//别名 error

    int c = 20;
    b = c;//这是赋值操作

    cout << " a = " << a << endl;// 20
    cout << " b = " << b << endl;// 20
    cout << " c = " << c << endl;// 20

    return 0;
}

/**
 * 利用值传递。不能让形参修饰实参
 */
void mySwap001(int a, int b) {

    int temp = a;
    a = b;
    b = temp;

    // a =20 ，b = 10

}

/**
 * 利用指针。让形参修饰实参
 */
void mySwap002(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;

    // a =20 ，b = 10


}

/**
 * 可以利用引用。让形参修饰实参
 */
void mySwap003(int &a, int &b) {

    int temp = a;
    a = b;
    b = temp;

    // a =20 ，b = 20

}

/**
 * 可以利用引用。让形参修饰实参
 * 简化指针的用法
 */
int main303() {

    int a = 10;
    int b = 20;

    mySwap001(a, b);
    cout << " a = " << a << endl;// 10
    cout << " b = " << b << endl;// 20

    mySwap002(&a, &b);

    cout << " a = " << a << endl;// 20
    cout << " b = " << b << endl;// 10

    mySwap003(a, b);
    cout << " a = " << a << endl;// 20
    cout << " b = " << b << endl;// 20

    return 0;
}

/*int& test_01(){

    int a= 10;

    return  a; //error 不要返回局部变量的引用

}*/


int& test_02(){

    static int a= 10; //静态变量存在全局区 //全局区的数据在程序结束后释放

    return a;

}

/**
 *  引用做返回值
 *  不要返回局部变量的引用
 *  函数的调用可以作为左值
 */
int main304(){

    /*int &ref = test_01();
    cout << " ref = " << ref << endl;// 10 第一次编译器做了保留
    cout << " ref = " << ref << endl;// error*/


   int &ref = test_02();
    cout << " ref = " << ref << endl;// 10
    cout << " ref = " << ref << endl;// 10
    cout << " ref = " << ref << endl;// 10

    //函数的返回是引用，函数的调用可以作为左值
    test_02() = 1000; // test_02() 返回一个变量  a ->  test_02 -> ref
    cout << " ref = " << ref << endl;// 1000
    cout << " ref = " << ref << endl;// 1000
    cout << " ref = " << ref << endl;// 1000

    return  0;
}


//发现是引用，转换为int * const ref =  &a;
void funcc(int& a){
     a = 100; //ref 是引用 转换为*ref = 100；
}


/**
 * 引用的本身在C++内部中是一个指针
 * C++推荐使用引用，语法方便，引用的本质就是指针
 */
int main305(){

    int a = 10;

    //自动转换为转换为int * const ref =  &a;指针常量指指针方向不可更改 也说明为什引用不可更改
    int& ref = a;

    ref = 20;//内部发现ref 是引用 转换为*ref = 20；
    cout << " a = " << a << endl;// 1
    cout << " ref = " << ref << endl;// 1

    funcc(a);

    return  0;
}

void showValue(const  int &a){

//    a = 1000;

    cout << " val a= " << a << endl;
}


/**
 * 常量使用 来修饰形参，防止误操作
 */
int main(){

    int a = 10;

//    int& ref = 10;  // error
    // 加上const之后 编译器将代码修改优化 int temp = 10;const int& ref = temp;
    const int& ref = a; //引用必须应用一块合法的内存空间

//    ref = 20; 加上const之后，变为只读，不可更改
    int b = 10;
    showValue(b);

    return 0;
}