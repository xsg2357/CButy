//
// Created by Administrator on 2019/9/28.
//
#include <iostream>
#include <string>

using namespace std;

class BasePage {
public:
    void top() {
        cout << " this is common page top" << endl;
    }

    void bottom() {
        cout << " this is common page bottom" << endl;
    }

    void left() {
        cout << " this is common page left" << endl;
    }
};

class APage : public BasePage {

public:

    void content() {
        cout << " this is common page APage content" << endl;
    }

};

class BPage : public BasePage {

public:

    void content() {
        cout << " this is common page BPage content" << endl;
    }

};

class CPage : public BasePage {

public:

    void content() {
        cout << " this is common page CPage content" << endl;
    }

};

/**
 * 继承的好处：减少重复代码
 * 语法：class 子类:继承方式 父类{}
 * 子类也称派生类
 * 父类也称为基类
 * 派生类的成员包括两大部分：
 *      1.一类是从基类继承过来，另外就是自己增加的成员
 * 从基类继承过来的表现其共性 新增加的成员表现其个性
 * 继承方式分为三种： 1.公共继承 2.保护继承 3.私有继承
 */
int main130() {

    APage apage;
    BPage bpage;
    CPage cpage;

    apage.bottom();
    apage.top();
    apage.left();
    apage.content();

    bpage.bottom();
    bpage.top();
    bpage.left();
    bpage.content();

    cpage.bottom();
    cpage.top();
    cpage.left();
    cpage.content();

    return 0;
}

/**
 * 父类中的所有成员都会被子类继承下去
 * 父类中的私有成员是被编译器隐藏了 因此访问不到 但是确实被继承下去了
 * 子类继承父类后 当创建子类对象时 也会调用父类的构造函数和析构函数
 * 继承同名成员处理方式
 *      访问子类同名成员 直接访问即可
 *      访问父类同名成员 需要加作用域
 */
class Base1 {
public:

    Base1() {
        cout << " parent Base1()" << endl;
        _a = 100;
    }

    ~Base1() {
        cout << " parent ~Base1()" << endl;
    }

    void func() {
        cout << " parent func" << endl;
    }
    void func(int a) {
        cout << " parent func(int a)" << endl;
    }

    int _a;
protected:
    int _b;
private:
    int _c;
};

/**
 * 公共继承
 */
class Son1 : public Base1 {

public:

    Son1() {
        cout << " child Son1()" << endl;
        _a = 200;
    }

    ~Son1() {
        cout << " child ~Son1()" << endl;
    }

    void func() {
        _a = 10;//父类中的公共成员。到了子类依旧是公共成员
        _b = 10;//父类中的保护成员。到了子类依旧是保护成员
        cout << " son func" << endl;
    }

    int _a;

};

/**
 * 保护继承
 */
class Son2 : protected Base1 {

public:
    void func() {
        _a = 10;//父类中的公共成员。到了子类变成了是保护成员
        _b = 10;//父类中的保护成员。到了子类依旧是保护成员
    }

};

/**
 * 私有继承
 */
class Son3 : private Base1 {

public:
    void func() {
        _a = 10;//父类中的公共成员。到了子类变成了是私有成员
        _b = 10;//父类中的保护成员。到了子类变成了私有成员
    }

};


class Grand3 : public Son3 {

    void func() {

        //到了子类中，父类中是私有权限或者变成了私有权有 ，都是不可以访问的

        /*_a = 10;//父类中的公共成员。到了子类变成了是私有成员
        _b= 10;//父类中的保护成员。到了子类变成了私有成员*/
    }
};

void test_base01() {
    Son1 son1;
    son1._a = 10;
//    son1._b = 10; //此权限是保护权限 类外访问不到
//    son1._c = 10; //此权限在父类中是私有权限 类外访问不到
}

void test_base02() {
    Son2 son1;
//    son1._a = 10;//此权限 到了子类中是私有权限 类外访问不到
//    son1._b = 10; //此权限是保护权限 到了子类中是私有权限  类外访问不到
}

/**
 * 打印对象模型
 * 命令查看对象模型： cl  /d1 reportSingleClassLayout类名 文件名
 */
void test_size_04() {

    cout << " size of son" << sizeof(Son1) << endl;
    cout << " size of son" << sizeof(Base1) << endl;
    //    size of son12
    //    size of son12
}

/**
 * 继承中析构和构造顺序：
 *    先构造父类，在构造子类，先析构子类，在析构父类
 */
void test_size_05() {
    Son1 son1;
    /* parent Base1()
     child Son1()
     child ~Son1()
     parent ~Base1()*/
}

/**
 * 同名属性的处理，父类需要加作用域，子类直接访问
 * 访问父类的同名变量：子类变量.父类名称::父类同名变量
 */
void test_size_06() {

    Son1 s;

    cout << " _a of son is " << s._a << endl; //200
    cout << " _a of Base is " << s.Base1::_a << endl; //100

}

/**
 * 同名函数的处理 子类：直接调用访问 父类需要加作用域
 * 访问父类的同名函数：子类变量.父类名称::父类同名函数
 * 如果子类中出现了和父类的同名函数，子类则把父类中的所有同名函数（重载）全部隐藏掉 调用方法为:加上父类的作用域
 */
void test_size_07() {
    Son1 s;
    s.func(); // son func
    s.Base1::func();
//    s.func(100); // error
    s.Base1::func(100);
}


int main() {

    test_size_07();
//    test_size_06();
//    test_size_05();

//    test_size_04();
    return 0;
}

