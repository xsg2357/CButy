//
// Created by Administrator on 2019/10/8.
//

#include <iostream>
#include "headerfile/WorkerManager.h"
#include "headerfile/Manager.h"
#include "headerfile/Employee.h"
#include "headerfile/Boss.h"

using namespace std;

int main139() {
    WorkerManager wm;
    while (true) {
        wm.showMenu();
        int choice = 0;
        cout << "****** 请输入您的选择...   ********" << endl;
        cin >> choice;
        switch (choice) {
            case 0://退出系统
                wm.exitSystem();
                break;
            case 1://添加
                wm.addEmp();
                break;
            case 2://显示所有的
                wm.showEmp();
                break;
            case 3://删除
                wm.delEmp();
                break;
            case 4://修改
                wm.ModEmp();
                break;
            case 5://序号或者名字查找
                wm.findEmp();
                break;
            case 6://升降排序
                wm.sortEmp();
                break;
            case 7://清空
                wm.cleanEmp();
                break;
            default:
                cout << "您的输入有误,退出系统！" << endl;
                wm.exitSystem();
                break;
        }
    }
    return 0;
}
