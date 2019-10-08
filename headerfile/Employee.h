//
// Created by Administrator on 2019/10/8.
//
#pragma once //防止头文件重复包含
#ifndef CBUTY_EMPLOYEE_H
#define CBUTY_EMPLOYEE_H
# include <iostream>
#include <string>
#include "Worker.h"

using  namespace std;

class Employee : public Worker{

public:


    Employee(int id,string name,int dId);

    Employee();

    void showInfo() override;

    string getDeptName() override;

};


#endif //CBUTY_EMPLOYEE_H
