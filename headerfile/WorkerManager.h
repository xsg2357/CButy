//
// Created by Administrator on 2019/10/8.
//
#pragma once //防止头文件重复包含
# include <iostream>
# include <fstream>
#include "Worker.h"
#include "Manager.h"
#include "Employee.h"
#include "Boss.h"
#include <Windows.h>
#include <cstdlib>

#ifndef CBUTY_WORKERMANAGER_H
#define CBUTY_WORKERMANAGER_H
#define FILENAME "empFile.txt"

using  namespace std;//标准命名空间


class WorkerManager {

public:

    WorkerManager();

    void showMenu();


    void exitSystem();

    void addEmp();

    /**
     * 保存员工
     */
    void saveEmp();
    void showEmp();
    void initEmp();
    string UTF8ToGB(const char* str);
    int getEmpNum();


    Worker ** workerArray;

    int _empNum;
    bool _fileIsExist = false;


    ~WorkerManager();

};


#endif //CBUTY_WORKERMANAGER_H
