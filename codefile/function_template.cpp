//
// Created by Administrator on 2019/10/9.
//
#include <iostream>
#include <string>

using namespace std;
//
template<typename T>//声明一个模板，高速编译器后面代码中的紧更着的T不要报错，T是一个通用数据类型
void mySwap01(T &a,T &b){
    T temp  = a;
    a = b;
    b = temp;
}

void myTestSwap01(){
    int a= 10;
    int b= 20;
    mySwap01(a,b);//自动类型推导
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;

    double c= 10;
    double d= 20;
    mySwap01<double>(c,d);//显示类型推导
    cout << " c = " << c << endl;
    cout << " d = " << d << endl;
}


int main140() {
    myTestSwap01();
    return 0;
}

