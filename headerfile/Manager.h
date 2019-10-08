//
// Created by Administrator on 2019/10/8.
//
#pragma once //防止头文件重复包含

# include <iostream>
#include <string>
#include "Worker.h"

#ifndef CBUTY_MANAGER_H
#define CBUTY_MANAGER_H


class Manager : public Worker {

public:

    Manager(int id,string name,int dId);


    void showInfo() override;

    string getDeptName() override;

};


#endif //CBUTY_MANAGER_H
