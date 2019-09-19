//
// Created by Administrator on 2019/9/19.
//
#include <iostream>
using  namespace std;
int main11(){
    //加减乘除
    int a1 = 10;
    int b1 = 3;

    cout << a1 + b1 << endl;
    cout << a1 - b1 << endl;
    cout << a1 * b1 << endl;
    cout << a1 / b1 << endl; //两个整数相除 结果依然是整数 将小数部分去除

    int a2 = 10;
    int b2 = 20;

    cout << a2 / b2 << endl;

    int a3 = 10;
    int b3 = 0;

//    cout << a3 / b3 << endl; // error: 除数不可以为0

    //两个小数可以相除 运算的结果也可以是小数
    double d1 = 0.5;
    double d2 = 0.25;
    cout << d1 / d2 << endl;
    return  0;
}

int main12(){
    //取模运算本质 就是求余数
    int a1 = 10;
    int b1 = 3;

    cout << a1 % b1 << endl;

    int a2 = 10;
    int b2 = 20;
    cout << a2 % b2 << endl;

    int a3 = 10;
    int b3 = 0;

//    cout << a3 % b3 << endl; // error: 除数不可以为0


    double  d1 = 3.14;
    double  d2 = 1.1;
    //两个小数是不可以做取模运算的

//    cout << d1 % d2 << endl;
    return  0;
}

int main13(){

    //1.前置递增
    int a = 10;
    ++a;
    cout << "a = " << a <<endl;
    //2.后置递增
    int b = 10;
    b++;
    cout << "b = " << b <<endl;
    //3.前置和后置的区别 前置：先让变量+1，然后进行表达式运算
     int a2 = 10;
     int b2 = ++a2 * 10;
    cout << "a2 = " << a2 <<endl;//11
    cout << "b2 = " << b2 <<endl;//110
    // 后置：先进行表达式运算，后让变量加1
    int a3 = 10;
    int b3 = a3++ * 10;
    cout << "a3 = " << a3 <<endl;//11
    cout << "b3 = " << b3 <<endl;//100

    int a11 = 10;
    --a11;
    cout << "a11 = " << a11 <<endl;//9
    //2.后置递增
    int b11 = 10;
    b11--;
    cout << "b11 = " << b11 <<endl; //9
    //3.前置和后置的区别 前置：先让变量-1，然后进行表达式运算
     int a21 = 10;
     int b21 = --a21 * 10;
    cout << "a21 = " << a21 <<endl;//9
    cout << "b21 = " << b21 <<endl;//90
    // 后置：先进行表达式运算，后让变量减1
    int a31 = 10;
    int b31 = a3-- * 10;
    cout << "a31 = " << a31 <<endl;//10
    cout << "b31 = " << b31 <<endl;//110
    return  0;
}

int main14(){
    // 赋值运算符
    int a = 10;

    // =
    a= 100;
    cout << "a = " << a <<endl; //100
    // += a = a+100
    a += 100;
    cout << "a = " << a <<endl;//200
    // = a= a- 100
    a -= 100;
    cout << "a = " << a <<endl;//100
    // = a= a/100
    a /= 100;
    cout << "a = " << a <<endl;//1
    //% = a= a % 100;
    a %= 100;
    cout << "a = " << a <<endl;//1
    // *= a= a *100;
    a *= 100;
    cout << "a = " << a <<endl;//100
    return  0;
}

int main15(){
    //比较运算符 返回一个真值或者一个假植
    int a = 10;
    int b =9;
    // ==
    cout << (a == b) <<endl;//0
    // >=
    cout << (a >= b) <<endl;//1
    // <=
    cout << (a <= b) <<endl;//0
    // !=
    cout << (a != b) <<endl;//1
    // >
    cout << (a > b) <<endl;//1
    // <
    cout << (a < b) <<endl;//0


    return  0;
}

int  main16(){
    //逻辑运算符：用于根据表达式的值是否为真或者假
    //1. ! 非 !a 如果a为假，!a则为真；如果a为镇，!a则为假
    int a = 10;
    cout << !a <<endl;//0 除了0都为真
    cout << !!a <<endl;// 1
    //2. && 与 a&&b 如果a和b都为假，结果则为假，否则为镇
    int b = 10;
    cout << (a&&b) << endl;//1

    a= 0;
    b = 10;
    cout << (a&&b) << endl;//0

    a= 0;
    b = 0;
    cout << (a&&b) << endl;//0 总结：同真为真，其余为假

    //3. || 或 a||b 如果a和b有一个值为真，结果则为真，两个值为假，则结果为假

    a= 10;
    b = 10;
    cout << (a||b) << endl;//1

    a= 0;
    b = 10;
    cout << (a||b) << endl;//1

    a= 0;
    b = 0;
    cout << (a||b) << endl;//0 总结：同假为假，其余为真

    return 0;
}