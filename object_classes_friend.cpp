//
// Created by Administrator on 2019/9/28.
//

#include <iostream>
#include <string>

using namespace std;

/**
 * 全局函数做友元
 * 语法：friend 方法类型 方法名（参数。。。）；
 */
class Building {

    friend void goodGuy(Building *building);

public:
    Building() {
        _settingRoom = "ke ting";
        _bedRoom = "wo shi";
    }

public:
    string _settingRoom;
private:
    string _bedRoom;
};

void goodGuy(Building *building) {

    cout << "hava e friend  resolve " << building->_settingRoom << endl; //hava e friend  resolve ke ting
    cout << "hava e friend  resolve " << building->_bedRoom << endl; //hava e friend  resolve wo shi

}

int main121() {
    Building building;
    goodGuy(&building);
    return 0;
}

/**
 * 类做友元
 * 语法：friend class 类名；
 * 可以访问本类中的私有属性
 */
class Building1 {

    friend class GoodGuy;

public:
    Building1();

public:
    string _settingRoom;
private:
    string _bedRoom;
};

Building1::Building1() {
    _settingRoom = "ke ting";
    _bedRoom = "wo shi";
}

class GoodGuy {
public:

    GoodGuy();


    void visit();

    Building1 *building;
};

GoodGuy::GoodGuy() {
    building = new Building1;
}

void GoodGuy::visit() {
    cout << "have a friend  resolve " << building->_settingRoom << endl; //have a friend  resolve ke ting
    cout << "have a friend  resolve " << building->_bedRoom << endl; //have a friend  resolve wo shi
}

int main122() {

    GoodGuy goodGuy1;
    goodGuy1.visit();

    return 0;
}

/**
 * 成员函数做友元
 * 语法：friend  方法类型  类名::方法名();
 */
class Building2; //定义Building2 告诉编译器Building2 会去实现


class GoodGuy1 {
public:
    GoodGuy1();

    void visit(); //visit 可以访问Building2中私有成员
    void visit2();//visit2 不可以访问Building2中私有成员

    Building2 *building;
};

class Building2 {

    friend void GoodGuy1::visit();

public:
    Building2();

public:
    string _settingRoom;
private:
    string _bedRoom;

};

Building2::Building2() {
    _settingRoom = "ke ting";
    _bedRoom = "wo shi";
}

GoodGuy1::GoodGuy1() {
    building = new Building2;
}

void GoodGuy1::visit() {
    cout << "visit have a friend  resolve " << building->_settingRoom << endl;
    cout << "visit have a friend  resolve " << building->_bedRoom << endl;
    //    visit have a friend  resolve ke ting
    //    visit have a friend  resolve wo shi
}

void GoodGuy1::visit2() {
    cout << "visit have a friend  resolve " << building->_settingRoom << endl;
//    cout << "visit have a friend  resolve " << building->_bedRoom << endl;

    //    visit have a friend  resolve ke ting

}

int main123() {

    GoodGuy1 goodGuy1;
    goodGuy1.visit();
    goodGuy1.visit2();

    return 0;
}

