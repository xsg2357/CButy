//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
#include <string>
#include "headerfile/CircleObject.h"
#include "headerfile/PointObject.h"

using namespace std;
const double PI1 = 3.14;
/**
 * private 成员 类内可以访问，类外可以访问
 * protected 成员 类内可以访问，类外不可以访问 儿子可以访问父亲的保护的内容
 * public 成员 类内可以访问，类外不可以访问 儿子不可以访问父亲的私有的内容
 */

class PersonObject{

public:
    string _name;
protected:
    string _car;

private:
    string _car_pwd;
public:
    void func(){
        _name = "zhang  san";
        _car = "tuo la ji";
        _car_pwd = "123456987";
    }

private:
    void func1(){
        _name = "zhang  san";
        _car = "tuo la ji";
        _car_pwd = "123456987";
    }

};

int main601(){

    PersonObject personObject;
    personObject._name ="li si";
    //    personObject._car ="li si"; 保护权限 类外访问不到
    //    personObject._car_pwd ="li si"; 私有权限 类外访问不到

    personObject.func();
    //    personObject.func1();私有权限 类外访问不到

    return  0;
}

/**
 *  class 和 struct在内部都可以访问
 */
class  C1{
    string name;

    void setName(string _name) {
        name = _name;
    }
};

struct  C2{
    string name;

    void setName(string _name) {
        name = _name;
    }
};

int main602(){

    C1 c1;

    //    c1.name = "zhang san";
//    c1.setName("zhang san"); //class的默认权限是私有private的


    C2 c2;
    c2.name  = "zhang san";
    c2.setName("zhang san"); //struct的默认权限是公共public的

    return  0;

}

//成员属性设置为私有化
//1.可以控制读写权限
//2.可以检测数据的有效性

class Person2Object{
private:
    string _name;
    int _age = 0;
    string _lover;

public:
    const string &getName() const {
        return _name;
    }

    void setName(const string &name) {
        _name = name;
    }

    int getAge() const {
        return _age;
    }

    void setAge(int age) {
        if(age > 100){
            age = 80; //2.可以检测数据的有效性
        }
        _age = age;
    }

    const string &getLover() const {
        return _lover;
    }

    void setLover(const string &lover) {
        _lover = lover;
    }
};

int main603(){

    Person2Object person2Object;
    person2Object.setName("li su");
    person2Object.setLover("li si si");
    cout << " name = " << person2Object.getName() << endl;
    cout << " age = " << person2Object.getAge() << endl;
    cout << " lover = " << person2Object.getLover() << endl;

    /*name = li su
     age = 0
    lover = li si si*/

    return  0;
}

/**
 * 封装权限案例：创建立方体的类
 */
class  Cube{


private:
    int m_w;
    int m_h;
    int m_L;

public:
    int getMW() const {
        return m_w;
    }

    void setMW(int mW) {
        m_w = mW;
    }

    int getMH() const {
        return m_h;
    }

    void setMH(int mH) {
        m_h = mH;
    }

    int getML() const {
        return m_L;
    }

    void setML(int mL) {
        m_L = mL;
    }

    int calculateS(){

        return  2 * m_L * m_h +2 * m_L * m_w +2 * m_w * m_h ;
    }
    int calculateV(){

        return   m_L * m_h * m_w ;
    }

    bool isSameByClass(Cube &c){

        return m_h == c.getMH() && m_L == c.getML() && m_w == c.getMW();
    }

};

bool isSame(Cube &c1,Cube &c2){

    return c1.getMH() == c2.getMH() && c1.getML() == c2.getML() && c1.getMW() == c2.getMW();

}

int main604(){

    Cube cl;
    cl.setMH(10);
    cl.setML(10);
    cl.setMW(10);

    cout << " size = " << cl.calculateS() << endl; // 600
    cout << " volume = " << cl.calculateV() << endl; // 1000

    Cube c2;
    c2.setMH(10);
    c2.setML(10);
    c2.setMW(10);

    bool  isSame1 = isSame(cl,c2);
    cout << " c1 = c2 " << isSame1 << endl; //  1 全局函数判断

    bool  isSame3 = cl.isSameByClass(c2);
    cout << " c1 = c2 " << isSame3 << endl; //  1 成员函数判断

    return 0;
}


/**
 * 设计一个点类 已移动到codefile和headerfile中
 */
/*class PointObject{
private:
    int m_X;
    int m_Y;

public:
    int getMX() const {
        return m_X;
    }

    void setMX(int mX) {
        m_X = mX;
    }

    int getMY() const {
        return m_Y;
    }

    void setMY(int mY) {
        m_Y = mY;
    }
};*/


/**
 * 设计一个圆类 已移动到codefile和headerfile中
 */
/*class  CircleObject{
private:
    int m_r;
    PointObject m_point;//圆心 一个类可以作为另一个类的成员变量
public:
    int getMR() const {
        return m_r;
    }

    void setMR(int mR) {
        m_r = mR;
    }

    const PointObject &getMPoint() const {
        return m_point;
    }

    void setMPoint(const PointObject &mPoint) {
        m_point = mPoint;
    }
};*/

void isInCircle(CircleObject &c,PointObject &p){

    int cX= c.getMPoint().getMX() - p.getMX();
    int cY= c.getMPoint().getMY() - p.getMY();

    int  dis = cX * cX + cY * cY;

    int rDis = c.getMR() * c.getMR();

    if (dis == rDis){
        cout << " point in circle center "  << endl;
    }else if (dis > rDis){
        cout << " point not in circle  "  << endl;
    }else{
        cout << " point in circle  "  << endl;
    }

}

/**
 * 封装权限案例：点和园的关系
 */
int main605(){

    CircleObject circle;
    circle.setMR(10);

    PointObject pintCenter;
    pintCenter.setMX(10);
    pintCenter.setMX(0);
    circle.setMPoint(pintCenter);

    PointObject pint;
    pint.setMX(10);
    pint.setMX(10);

    isInCircle(circle,pint); // point not in circle

    return  0;
}
