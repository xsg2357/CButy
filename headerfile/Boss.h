//
// Created by Administrator on 2019/10/8.
//

#ifndef CBUTY_BOSS_H
#define CBUTY_BOSS_H
#pragma once //防止头文件重复包含
# include <iostream>
#include <string>
#include "Worker.h"

using  namespace std;

class Boss : public Worker{

public:

    Boss(int id,string name,int dId);


    void showInfo() override;

    string getDeptName() override;

};



#endif //CBUTY_BOSS_H
