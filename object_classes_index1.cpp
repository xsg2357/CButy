//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
#include <string>

using namespace std;

const double PI = 3.14;

/**
 * class 代表设计一个类，类后面紧跟着后面是类的名称
 */
class Circle {

    //访问权限
    //公共权限
public:

    int m_r; //属性-半径

    double caculateZc() { //行为-计算圆的周长

        return 2 * PI * m_r;
    }

};

int main501() {
    Circle c1;//创建圆的对象 实例化：通过一个类创建一个对象的过程

    c1.m_r = 10;//给圆的属性赋值

    //通过圆的行为计算圆的周长
    cout << "circle all chang is " << c1.caculateZc() << endl; // 62.8

    return  0;
}

/**
 * 对象封装——案例：设计一个学生类
 */
class StudentObject {

public:

    /**
     * 类中的属性和行为 称之为成员
     * 属性 成员属性 成员变量
     * 行为 成员行为 成员函数
     */
    string name;
    int id;

    void showStudentInfo() {
        cout << "student name =  " << name << ", id =  " << id << endl;
    }

    void setName(string _name) {
        name = _name;
    }

    void setId(int _id) {
        id = _id;
    }

};

int main502() {

    StudentObject studentObject;
    studentObject.id = 10021;
    studentObject.name = "zhangsan";
    studentObject.showStudentInfo();

    StudentObject studentObject1;
    studentObject1.id = 10022;
    studentObject1.setName("lisi");
    studentObject1.showStudentInfo();

    StudentObject studentObject2;
    studentObject2.setId(10023)  ;
    studentObject2.setName("wangwu");
    studentObject2.showStudentInfo();

    /*student name =  zhangsan, id =  10021
    student name =  lisi, id =  10022
    student name =  wangwu, id =  10023*/
    return 0;
}
