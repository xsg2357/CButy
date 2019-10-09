//
// Created by Administrator on 2019/10/9.
//
#include <iostream>
#include <string>
//#include "../headerfile/TemplatePerson2.h"
#include "../codefile/TemplatePerson2.cpp"
#include "../codefile/TemplatePerson3.hpp"
#include "../codefile/MyArrayTemplate.hpp"

using namespace std;

template<class NameType, class AgeType = int> //默认的模板参数列表
class TemplatePerson {
public:

    TemplatePerson(NameType name, AgeType age) : _name(name), _age(age) {}

    NameType _name;
    AgeType _age;

    void showInfo() {
        cout << "name=" << this->_name << ",age=" << this->_age << endl;
    }
};

void personTest01() {
    TemplatePerson<string, int> person("zhangsan", 18);
//    TemplatePerson person("zhangsan",18); error 没有自动类型的推导方式
    person.showInfo();

    TemplatePerson<string> person2("zhangsan", 18);
    person2.showInfo();

//    name=zhangsan,age=18
//    name=zhangsan,age=18

}

class CommonPerson1 {

public:


    void showInfo1() {
        cout << "CommonPerson1 show" << endl;
    }
};

class CommonPerson2 {

public:

    void showInfo2() {
        cout << "CommonPerson2 show" << endl;
    }
};

template<class T>
class MyPersonClass {

public:
    T obj;

    //类模板中的成员函数
    void func1() {
        obj.showInfo1();
    }

    void func2() {
        obj.showInfo2();
    }
};

//    1.指定传入的类型--直接显示对象的数据类型
void printTemplatePerson01(TemplatePerson<string, int> &person) {
    person.showInfo(); //name=zhangsan,age=18
}

//    2.参数模块化--将对象中的参数变为模板进行传递
template<class T1, class T2>
void printTemplatePerson02(TemplatePerson<T1, T2> &person) {
    person.showInfo(); //name=zhangsan,age=18
    cout << "type T1 == " << typeid(T1).name() << endl;
    cout << "type T2 == " << typeid(T2).name() << endl;
//    type T1 == NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
//    type T2 == i
}

// 3.整个类模板化--将这个对象类型模板化进行传递
template<class T>
void printTemplatePerson03(T &person) {
    person.showInfo(); //name=zhangsan,age=18
    cout << "type T == " << typeid(person).name() << endl;
//    type T == 14TemplatePersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
}

void personTest02() {
    TemplatePerson<string, int> person("zhangsan", 18);
//    printTemplatePerson01(person);
//    printTemplatePerson02(person);
    printTemplatePerson03(person);
}


int main146() {
//    personTest01();
//
//    MyPersonClass<CommonPerson1> myPersonClass;
//    myPersonClass.func1();
//
//    MyPersonClass<CommonPerson2> myPersonClass1;
//    myPersonClass1.func2();

//    CommonPerson1 show
//    CommonPerson2 show

    personTest02();


    return 0;
}

template<class T>
class BaseTemplate {
public:
    T a;
};

/*class Son:public  BaseTemplate{ error 要制定出父类中T的类型

};*/

class SonTemplate : public BaseTemplate<int> {

};

/**
 * 如果想灵活指定出父类中T的类型，子类也需要为类模板
 */
template<class T1, class T2>
class SonTemplate1 : public BaseTemplate<T2> {
public:

    SonTemplate1() {
        cout << "type T1 == " << typeid(T1).name() << endl;
        cout << "type T2 == " << typeid(T2).name() << endl;
//        type T1 == i
//        type T2 == c
    }

    T1 obj2;

};

template<class NameType, class AgeType> //默认的模板参数列表
class TemplatePerson1 {
public:

//    TemplatePerson(NameType name, AgeType age) : _name(name), _age(age) {}
    TemplatePerson1(NameType name, AgeType age);

    NameType _name;
    AgeType _age;


    void showInfo();

//    void showInfo() {
//        cout << "name=" << this->_name << ",age=" << this->_age << endl;
//    }
};

//构造函数的内外实现
template<class NameType, class AgeType>
TemplatePerson1<NameType, AgeType>::TemplatePerson1(NameType name, AgeType age) {
    this->_name = name;
    this->_age = age;
}

template<class NameType, class AgeType>
void TemplatePerson1<NameType, AgeType>::showInfo() {
    cout << "name=" << this->_name << ",age=" << this->_age << endl;
}


int main147() {

//    SonTemplate sonTemplate;
//    SonTemplate1<int, char> sonTemplate1;

//    TemplatePerson1<string, int> templatePerson1("zhangsan",18);
//    templatePerson1.showInfo(); //name=zhangsan,age=18
    TemplatePerson2<string, int> templatePerson2("zhangsan", 18);
    templatePerson2.showInfo(); //name=zhangsan,age=18
    //    报错解决方式1：#include "../codefile/TemplatePerson2.cpp" 直接引入cpp文件
    //报错解决方式3：#include "../codefile/TemplatePerson3.hpp" cpp文件:把.cpp和.h写在一个文件中
    TemplatePerson3<string, int> templatePerson3("zhangsan", 18); //name=zhangsan,age=18
    templatePerson3.showInfo();

    return 0;
}

//1.声明此类的存在
template<class NameType, class AgeType >
class  TemplatePerson4;

//2.全局函数类外实现--需要提前让编译器知道全局函数的存在
template<class NameType, class AgeType >
void printPerson2(TemplatePerson4<NameType, AgeType> person){
    cout << "name=" << person._name << ",age=" << person._age << endl;
}


//3.
template<class NameType, class AgeType = int> //默认的模板参数列表
class TemplatePerson4 {

    //全局函数类内实现--直接在类内声明友元即可
    friend void printPerson(TemplatePerson4<NameType, AgeType> person) {
        cout << "name=" << person._name << ",age=" << person._age << endl;
    }

    //4.
    //全局函数类外实现--需要提前让编译器知道全局函数的存在,需要加空模板
    friend void printPerson2<>(TemplatePerson4<NameType, AgeType> person);

public:

    TemplatePerson4(NameType name, AgeType age) : _name(name), _age(age) {}


    void showInfo() {
        cout << "name=" << this->_name << ",age=" << this->_age << endl;
    }

private:
    NameType _name;
    AgeType _age;
};





int main148(){

    TemplatePerson4<string, int> templatePerson4("zhangsan", 18); //name=zhangsan,age=18
//    templatePerson3.showInfo();
     printPerson(templatePerson4); //name=zhangsan,age=18
    TemplatePerson4<string, int> templatePerson5("zhangsan", 18);
//  error:  E:\CWork\CButy\codefile\class_template.cpp:212:71: note: (if this is not what you intended,
//  make sure the function template has already been declared and add <> after the function name here)

    printPerson2(templatePerson5); //name=zhangsan,age=18

    return  0;
}

/**
 * 类模板案例：
 * 创建一个通用的数组类
 *     可以对内置数据类型以及自定义数据类型的数据进行存储
 *     将数组中的数据存贮到堆区
 *     构造函数中可以传入数组的容量
 *     提供对应的拷贝构造函数以及operator == 防止浅拷贝问题
 *     提供尾插法和尾删法对数组中的数据进行增加和删除
 *     可以通过下标的方式访问数组中的元素
 *     可以获取数组中当前元素个数和数组的容量
 */
int main149(){

    MyArrayTemplate<int> myArrayTemplate(5);

//    MyArrayTemplate<int> myArrayTemplate3(100);
//    myArrayTemplate3 = myArrayTemplate2;
//    constructor
//    copy constructor
//    constructor
//            operator constructor
//    ~ constructor
//    ~ constructor
//    ~ constructor
    for (int i = 0; i < 5; ++i) {
        myArrayTemplate.pushBack(i) ;
    }
    cout << "print:"  << endl;
    for (int i = 0; i < myArrayTemplate.getCapacity(); ++i) {
        cout << myArrayTemplate[i] << " ";
    }
    cout  << endl;
    cout  << "Capacity == "<<myArrayTemplate.getCapacity() << endl;
    cout  << "size == "<<myArrayTemplate.getSize() << endl;
    cout << "print:"  << endl;
    MyArrayTemplate<int> myArrayTemplate2(myArrayTemplate);
    for (int i = 0; i < myArrayTemplate2.getCapacity(); ++i) {
        cout << myArrayTemplate2[i] << " ";
    }
    myArrayTemplate2.popBack();
    cout   << endl;
    cout  << "Capacity == "<<myArrayTemplate2.getCapacity() << endl;
    cout  << "size == "<<myArrayTemplate2.getSize() << endl;
   /* constructor
    print:
    0 1 2 3 4
    Capacity == 5
    size == 5
    print:
    copy constructor
    0 1 2 3 4
    Capacity == 5
    size == 4
    ~ constructor
    ~ constructor*/
    return  0;
}
