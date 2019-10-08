//
// Created by Administrator on 2019/10/8.
//

#pragma once //防止头文件重复包含
#ifndef CBUTY_WORKER_H
#define CBUTY_WORKER_H

# include <iostream>
#include <string>
using  namespace std;

class Worker {

public:

    virtual  void showInfo() = 0;

    virtual  string getDeptName() = 0;

    int _id;
    string _name;
    int _deptId;

};


#endif //CBUTY_WORKER_H
