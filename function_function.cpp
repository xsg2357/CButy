//
// Created by xiang on 2019/9/21.
//
#include <iostream>
#include "headerfile/functionfiloe.h"
using namespace std;

/**
 *  函数：将一段代码封装起来 减少重复代码
 *  一个较大的程序 一般封装为若干块  每个模块实现特定的功能
 *  函数定义一般分为5个模块：
 *   返回值类型 函数名 函数表列 函数体语句  return表达式
 *
 *   返回值类型 函数名 (函数表列){
 *      函数体语句
 *      return表达式
 *   }
 *
 *   num1 num2 形式参数 简称形参
 * @return
 */
int add(int num1, int num2) {

    return num1 + num2;
}


int main70() { //函数的调用

    int a = 10;
    int b = 20;

    //调用函数是，实参会把值传递给形参
    int c = add(a, b);
    cout << "加法：c = " << c << endl;

    cout << "加法：" << add(1, 2) << endl;

    a = 500;
    b = 100;
    c = add(a, b);//a和b都是实际参数 简称实参
    cout << "加法：c = " << c << endl;

    return 0;
}

/**
 * 值传递 调用函数时，实参会把值传递给形参
 * 形参发生改变时，实际的值并不会改变
 * eg:两个值进行交换
 *
 * 不需要 返回值时，用void可以不用return
 */
void swap(int num1, int num2) {

    cout << "交换前数字：num1 =" << num1 << ",num2=" << num2 << endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "交换后数字：num1 =" << num1 << ",num2=" << num2 << endl;

}

int main71() {
    int a = 10;
    int b = 20;

    swap(a, b);

}

void test01() {
    cout << "这是无参无反函数" << endl;
}

void test02(int a) {
    cout << "这是有参无反函数，值是" << a << endl;
}

int test03() {
    cout << "这是无参有反函数" << endl;
    return 1;
}

int test04(int a, int b) {
    cout << "这是有参有反函数" << endl;
    return a - b;
}

/**
 * 函数常见样式：
 *   无参无反 无参有反 有参有反 有参无反
 */
int main72() {
    test01();
    test02(20);

    int a = test03();
    cout << "这是无参有反函数的值：" << a << endl;

    int b = test04(3, 4);
    cout << "这是有参有反函数的值：" << b << endl;
    return 0;
}

/**
 * 函数声明 eg: 比较两个值得函数
 * 提前告知编译器函数的存在，可以利用函数的声明
 * 声明可以写多次，但是智能定义一次
 */
int max(int a, int b);
int max(int a, int b);

/*int max(int a, int b) {

    return a > b ? a : b;
}*/

int main73() {

    int a = 10;
    int b = 20;

    cout << "最大值：" << max(a,b) << endl;

}

int max(int a, int b) {

    return a > b ? a : b;
}


/**
 * 函数的分文件编写--让代码结构更清晰
 * 1.创建后缀名为.h的头文件
 * 2.创建后缀名为.cpp的源文件
 * 3.在头文件中编写函数的声明
 * 4.在源文件中编写函数的定义
 */
int main74(){

    int a = function_file(30,40);
    cout << "最大值：A = " << a << endl;
    return 0;
}
