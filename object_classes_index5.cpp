//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
#include <string>
using namespace std;

class Phone{

public:

    Phone(string name){

        _p_name = name;
        cout  <<"Phone  ======> "  <<endl;
    }

    ~Phone(){
        cout  <<"Phone destory ======> "  <<endl;
    }

    string _p_name;

};

class Pa{

public:

    Pa(string name,string phone):_name(name),_phone(phone){
        cout  <<"Pa ======> "  <<endl;
    }

    ~Pa(){
        cout  <<"Pa destory ======> "  <<endl;
    }

    string _name;
    Phone  _phone;
    //当其他对象作为本类成员，构造时先构造类对象，其次是类本身
    // Phone  ======>
    // Pa ======>
    //析构的书序与构造相反
    // Pa destory ======>
    //Phone destory ======>
};

/**
 * C++类中的成员可以是另一个类的对象，称之为对象成员
 * 对象成员和类的构造和析构顺序
 */
int  main115(){

    Pa pa("zhang san","iphone xs");

    cout << pa._name <<" ======> "  << pa._phone._p_name <<endl;


    return  0;
}

/*class B; //这里我们使用前置声明，完全不知道B是什么样子
class A {
public:
    static B bb;//声明了一个类型为B的静态成员，在这里编译器并未给bb分配内存。
//因为仅仅是声明bb,所以编译器并不需要知道B是什么样子以及要给其对应的对象分配多大的空间。
//所以使用前置声明"class B"就可以保证编译通过。
};*/

class  Ppa{

public:

    static  int a ;//静态成员变量 类内申明，类外初始化
    int b;

    static  void  func(){

        a = 200;

        //        b = 100; error:静态成员函数只能访问静态成员变量
        //费静态成员变量，无法区分是哪个对象的

        cout <<" ppa static ======> "   <<endl;
    }

    void  funb(){

        a = 300;//非静态成员函数可以访问静态成员变量
        cout <<" ppa funb ======> "   <<endl; //1 byte
    }

private:


    void  fund(){

        a = 300;//非静态成员函数可以访问静态成员变量
        cout <<" ppa funb ======> "   <<endl;
    }

};

 int Ppa::a = 10;
int main116(){

    Ppa ppa;
    ppa.a = 10; // 编译以上代码会出现“对‘A::a’未定义的引用”错误。这是因为静态成员变量a未定义，也就是还没有分配内存，显然是不可以访问的
    ppa.func();

    Ppa::a = 10;
    Ppa::func(); // 编译以上代码会出现“对‘A::a’未定义的引用”错误。这是因为静态成员变量a未定义，也就是还没有分配内存，显然是不可以访问的
    //    Ppa::fund(); 类外访问不到非静态私有函数

    return  0;
}