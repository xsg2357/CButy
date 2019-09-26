//
// Created by Administrator on 2019/9/26.
//
#include <iostream>

using  namespace std;
/**
 * 函数默认参数
 * 函数的形参列表中的形参是可以有默认值的
 * 语法：返回值类型 函数名（参数 = 默认值）{}
 */
int funa(int a = 10,int b = 20,int c = 30){

    return  a+b+c;
}
int funaa(int a ,int b = 20,int c = 30){

    return  a+b+c;
}

int funa2(int a = 10,int b = 20,int c = 30);

int funa2(int a,int b,int c){

    return  a+b+c;
}

int  main401(){

    /**
     * 注意事项：
     * 如果某个位置已经有了默认参数 那么从这个位置从左网友都必须有默认参数值
     * 如果函数声明有默认参数，函数实现就不能有默认参数,声明和实现只能有一个有默认参数
     *
     */
    cout << funa(10,20,30) << endl;
    cout << funa(10,30) << endl;
    cout << funa(10,20,30) << endl;
    cout << funa(10,20) << endl;
    cout << funa(10) << endl;
   ;

    /*60
    70
    60
    60
    60
    60*/
    cout << funa2() << endl; //60

    return 0;
}

//占位参数还可以有默认值
void funb(int a = 10,int = 10){

    cout << "funa(10,20,30)" << endl;
}


/**
 * 函数占位参数
 * C++ 形参列表里可以有占位参数，用来占位，调用函数时必须填补该位置
 * 语法： 返回值类型 函数名（数据类型）{}
 *
 */
int main402(){

    funb(10,5);
    funb();

    return  0;
}

void fund(){
    cout << "fund" << endl;
}

void fund(int a){
    cout << "fund a = " << a << endl;
    fund();
}
void fund(double b){
    cout << "fund b = " << b << endl;
    fund();
}
void fund(int a, double b){
    cout << "fund a = " << a << ",fund b = " << b<< endl;
    fund();
}

void fund( double b,int a){
    cout << "fund b = " << b <<"fund a = " << a << endl;
    fund();
}

/*int fund( double b,int a){
    cout << "fund b = " << b <<"fund a = " << a << endl;
    fund();
    // 函数的返回值不可以作为条件
    return  a+b;
}*/
/**
 * 函数重载
 * 函数名可以相同，提高复用性
 * 满足条件：
 *      1.同一个作用域下
 *      2.函数名相同
 *      2.函数的参数类型不同、个数不同、或者顺序不同
 *  函数的返回值不可以作为条件

 *  引用作为函数的条件
 *  函数重载遇到默认参数
 */
int main403(){

    fund();
    fund(10);
    fund(3.14);
    fund(10,3.14);
    fund(3.14,10);

    return  0;
}

// 引用作为函数的条件
void fune(int &a){ //int &a = 10; 不合法

    cout << "void fune(int &a)" << endl;

}


void fune(const int &a){//const int &a = 10; 合法，指向临时空间

    cout << "void fune(const int &a)" << endl;

}

//函数重载遇到默认参数
void fune2(int a,int b = 10){//碰到默认参数，会产生歧义
    cout << "void fune2( int a)" << endl;
}

void fune2(int a){
    cout << "void fune2( int a)" << endl;
}

int main404(){
    int a = 20;

    fune(a);
    fune(10);
    //    void fune(int &a)
    //    void fune(const int &a)

//    fune2(10); // error：fune2(int a,int b = 10) 和fune2(int a)都能调用

    return  0;

}



