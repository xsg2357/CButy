//
// Created by Administrator on 2019/10/8.
//

#include <iostream>
#include "headerfile/WorkerManager.h"
#include "headerfile/Manager.h"
#include "headerfile/Employee.h"
#include "headerfile/Boss.h"

using  namespace std;

int main(){
    WorkerManager wm;
    while (true){
        wm.showMenu();
        int choice = 0;
        cout << "****** ����������ѡ��...   ********" << endl;
        cin >> choice;
        switch (choice){
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.addEmp();
                break;
            case 2:
                wm.showEmp();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                cout << "������������" << endl;
                break;
        }

    }

    return  0;
}
