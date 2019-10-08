//
// Created by Administrator on 2019/10/8.
//

#include "../headerfile/Employee.h"

Employee::Employee(int id,string name,int dId) {
    this->_id = id;
    this->_name = name;
    this->_deptId = dId;
}

void Employee::showInfo() {
    cout << "编号：" << this->_id << endl;
    cout << "姓名：" << this->_name << endl;
    cout << "岗位：" << this->getDeptName() << endl;
    cout << "岗位职责：完成经理交给的任务"  << endl;
}

string Employee::getDeptName() {
    return "员工";
}
