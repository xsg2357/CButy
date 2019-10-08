//
// Created by Administrator on 2019/10/8.
//

#include "../headerfile/Manager.h"

Manager::Manager(int id,string name,int dId) {
    this->_id = id;
    this->_name = name;
    this->_deptId = dId;
}


void Manager::showInfo() {
    cout << "编号：" << this->_id << endl;
    cout << "姓名：" << this->_name << endl;
    cout << "岗位：" << this->getDeptName() << endl;
    cout << "岗位职责：完成老板交给的任务，并且给普通员工下发任务"  << endl;
}

string Manager::getDeptName() {
    return "经理";
}
