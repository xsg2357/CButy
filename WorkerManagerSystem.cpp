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
        cout << "****** ����������ѡ��...   ********" << endl;
        cin >> choice;
        switch (choice) {
            case 0://�˳�ϵͳ
                wm.exitSystem();
                break;
            case 1://���
                wm.addEmp();
                break;
            case 2://��ʾ���е�
                wm.showEmp();
                break;
            case 3://ɾ��
                wm.delEmp();
                break;
            case 4://�޸�
                wm.ModEmp();
                break;
            case 5://��Ż������ֲ���
                wm.findEmp();
                break;
            case 6://��������
                wm.sortEmp();
                break;
            case 7://���
                wm.cleanEmp();
                break;
            default:
                cout << "������������,�˳�ϵͳ��" << endl;
                wm.exitSystem();
                break;
        }
    }
    return 0;
}
