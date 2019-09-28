//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
#include <string>

using namespace std;

class PPp {

    int _a; //非静态成员变量

    static  int _b;

    void func(){//非静态成员函数

    }

};

/**
 * 只有非静态成员变量才属于类的对象上
 */
int main117() {

    //    PPp p; 空对象分配内存空间是为了区分每个对象都有独一无二的内存空间
    //   每个对象包括空对象都占内存的位置
    //    cout << "size of Ppp is " << sizeof(p) << endl; //null object 1 byte

    //    PPp p; 非静态成员变量
    //    cout << "size of Ppp is " << sizeof(p) << endl; // object 4 byte

    //        PPp p; static  int _b
    //        cout << "size of Ppp is " << sizeof(p) << endl; // object 4 byte

    //        PPp p; func
    //        cout << "size of Ppp is " << sizeof(p) << endl; // object 4 byte

    return 0;
}

class  cat{

public:

    cat(int age){
        this->age = age;
    }

    cat& catAdd(cat &cat1){//返回本身，用引用返回，才能不断叠加本身
        //cat catAdd() 则每次叠加都是一个新的对象
        this->age += cat1.age;

        return *this;
    }


    int age;
};


int main118(){

    cat cat1(10);

    cout << "age " << cat1.age << endl; //10

    cat cat2(20);
    cat2.catAdd(cat1);
    cout << "age " << cat2.age << endl; //30

    // 链式编程思想
    cat2.catAdd(cat1).catAdd(cat1).catAdd(cat1);
    cout << "age " << cat2.age << endl; //60
    return  0;
}

class Cat{
public:

    void showClassName(){
        cout << "Cat "  << endl; //10
    }

    void showClassAge(){//"<< _age" 默认是 " << this -> _age "
        if (this == NULL){
            return;
        }
        cout << "Cat " << _age << endl; //10
    }

    int _age;
};

int main119(){

    Cat *cat22 = NULL;


    cat22->showClassAge();
    cat22->showClassName();

    return 0;
};

class  Cat1{
public:

    Cat1(){

    }


    //this指针的本质 是指针常量 指针的方向是不可以修改的
    //Person * const this; //值可以修改
    //const Person * const this; //值不可以修改
    //在成员函数后面加const 修饰的this指向，让this指针指向的值也不可以修改
    void showCat() const {

        _b = 10;
        //     _a = 10; error
        //   this = NULL error;this指针的本质 是指针常量 指针的方向是不可以修改的
    }

    void func(){

    }


   int  _a;
   mutable  int  _b; //成员属性声明时加关键字mutable后，在场函数中依然可以修改
};

int main120(){

    const  Cat1 cat12;
    //    cat12.func();
    cat12.showCat(); //常对象只能调用常函数和常变量

    //    cat12._a = 10;
    cat12._b = 100;
    return  0;
}