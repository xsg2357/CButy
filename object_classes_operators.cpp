//
// Created by Administrator on 2019/9/28.
//

#include <iostream>
#include <string>

using namespace std;

class PersonAdd {
public:

    friend  ostream & operator<< (ostream &cout1,PersonAdd &p1);//友元访问私有属性

    PersonAdd(){

    }


    PersonAdd(int a,int b){
        _A = a;
        _B = b;
    }

    /**
     * 成员函数 加号运算符重载
     */
     /*PersonAdd operator+(PersonAdd &p){
         PersonAdd temp;
         temp._A =this->_A +p._A;
         temp._B =this->_B +p._B;

         return  temp;

     }
*/
    /**
     * 一般不会利用成员函数来实现左移运算符重载
     */
     /*void operator<< (cout){

     }*/

    int _A;
    int _B;
private:
    int _C;
};

/**
     * 全局函数 加号运算符重载
     */
PersonAdd operator+(PersonAdd &p1, PersonAdd &p2) {
    PersonAdd temp;
    temp._A = p1._A + p2._A;
    temp._B = p1._B + p2._B;

    return temp;
}

PersonAdd operator+(PersonAdd &p1, int num) {
    PersonAdd temp;
    temp._A = p1._A + num;
    temp._B = p1._B + num;

    return temp;
}

// 需要用&cout 引用的方式来传递，不要新创建一个来传递
// 简化operator<<（cout1，p1） ===> cout << p1
//利用全局函数来实现左移运算符重载
ostream & operator<< (ostream &cout1,PersonAdd &p1){

    p1._C = 10;

    cout1 << " A = " << p1._A  << ", B = " << p1._B << p1._C << endl;
    return  cout1;
}

void test_01() {

    PersonAdd p1;
    p1._A = 10;
    p1._B = 10;

    PersonAdd p2;
    p2._A = 10;
    p2._B = 10;

    PersonAdd p3 = p1 + p2;
    PersonAdd p4 = p1 + 10; //Person + int
    //    PersonAdd p4 = operator+(p1,10); //全局函数 本质调用
    //    PersonAdd p3 = operator+(p1,p2); //全局函数 本质调用
    //    PersonAdd p3 = p1.operator+(p2); //成员函数 本质调用

    cout << " A = " << p3._A << endl;
    cout << " B = " << p3._B << endl;
    //    A = 20
    //    B = 20
}

void test_002() {
    PersonAdd p1;
    p1._A = 10;
    p1._B = 10;


//    cout << " A = " << p1._A << endl;
//    cout << " B = " << p1._B << endl;
    cout << p1 << "hello " ;

//    A = 10, B = 1010
//    hello

}

/**
 * 运算符重载：对已有的运算符重新定义 赋予其另一种功能 以适应其不同 的数据类型
 * 加号运算符重载：实现两个不同数据类型的相加
 * 对于内置数据的表达式的运算符是不可能改变的
 * 不要滥用运算符重载
 */
int main124() {
    test_01();
    return 0;
}


int main125(){

    test_002();

    return  0;
}

class MyInteger{

    friend ostream & operator<<(ostream &cout2,MyInteger integer);


public:

    MyInteger(){
        _num = 0;
    }

    //重置++ 前置递增
    //    MyInteger& 发挥引用是为了一直对一个数据进行操作
    MyInteger& operator++(){
        _num ++; //1.先运算

        return  *this; // 后返回自身
    }

    //重置++ 后置递增
    //void operator++(int) int是占位参数，可以区分前置和后置递增
    MyInteger operator++(int){

        //先返回 记录结果
        MyInteger temp = *this;
        //其次  递增
        _num ++;
        // 最后将记录结果返回
        return temp;

    }

private:
    int _num;

};


ostream & operator<<(ostream &cout2,MyInteger integer){

    cout2 << integer._num;

    return  cout2;
}

/**
 * 递增运算符重载 自定义整型
 */
int main126(){

    MyInteger myInteger; // 0

    cout << ++myInteger << endl; //1

    cout << myInteger++ << endl; //1

    cout << myInteger << endl; //2

    return  0;

}

class  OperationPerson{

public:

    OperationPerson(int age){

        _age = new int(age);
    }

    ~OperationPerson(){
        if (_age != NULL){//NULL 可以替换成nullptr
            delete  _age;
            _age = NULL;
        }
    }

    OperationPerson&  operator=(OperationPerson &person){

        //编译器提供浅拷贝
//        _age = person._age;

        if (_age != NULL){ //NULL 可以替换成nullptr
            delete  _age;
            _age = NULL;
        }

        //深拷贝操作
        _age = new int(*person._age);

        // 反回自身
        return  *this;

    }
    int  *_age;

};

/**
 * 赋值运算符重载
 * c++一般至少给对象添加4个函数
 * 默认构造函数 （无参，函数体为空）
 * 默认析构函数 （无参，函数体为空）
 * 默认拷贝构造函数，对属性值进行拷贝
 * 默认赋值运算符operator=，对其属性进行赋值
 * 如果累中有属性指向堆区，做赋值深浅拷贝操作也会出现问题
 */
int main127(){

    OperationPerson operationPerson(18);
    cout << *operationPerson._age << endl; // 18

    OperationPerson operationPerson2(20);
    cout << *operationPerson2._age << endl; // 20

    OperationPerson operationPerson3(20);
    cout << *operationPerson3._age << endl; // 20

    operationPerson3 = operationPerson2 = operationPerson;
    cout << *operationPerson._age << endl; // 18
    cout << *operationPerson2._age << endl;// 18
    cout << *operationPerson3._age << endl; // 18

    return  0;
}

class OperationPerson1{

public:
    OperationPerson1( string _name, int age) : name(_name), age(age) {}

    string name;
    int age;

    bool  operator==(OperationPerson1 &operationPerson1){

        return  operationPerson1.age == this->age &&  operationPerson1.name == this->name;
    }

    bool  operator!=(OperationPerson1 &operationPerson1){
        return  operationPerson1.age != this->age ||  operationPerson1.name != this->name;
    }

};


/**
 * 关系运算符重载
 * == !=
 */
int main128(){

    OperationPerson1 operationPerson1("li si",18);
    OperationPerson1 operationPerson2("zhang san",18);

    cout << (operationPerson1 == operationPerson2) << endl; // 0--false
    cout << (operationPerson1 != operationPerson2) << endl; // 1--true

    return  0;

}

class  MyPrint{

public:

   /* MyPrint(){

    }*/


    void operator()(string test){
        cout << test << endl;

    }

};

void  print01(string test){

    MyPrint myPrint;
    myPrint(test);

}


/**
 * 函数调用运算符重载
 * 函数调用运算符（）也可以重载
 * 由于重载后的方式非常像函数的调用 也称仿函数
 * 仿函数没有固定写法 很灵活
 */
int main129(){

    MyPrint myPrint;
    myPrint("hello");


    print01("wold");

    //匿名函数对象打印
    MyPrint()("wold wold") ;

    /*hello
    wold
    wold wold*/
    return  0;
}