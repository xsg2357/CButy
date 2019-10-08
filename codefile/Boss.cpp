//
// Created by Administrator on 2019/10/8.
//

#include "../headerfile/Boss.h"

Boss::Boss(int id,string name,int dId) {
    this->_id = id;
    this->_name = name;
    this->_deptId = dId;
}


void Boss::showInfo() {
    cout << "编号：" << this->_id << endl;
    cout << "姓名：" << this->_name << endl;
    cout << "岗位：" << this->getDeptName() << endl;
    cout << "岗位职责：管理公司所有事物"  << endl;
}

string Boss::getDeptName() {
    return "老板";
}