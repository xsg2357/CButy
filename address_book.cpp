//
// Created by Administrator on 2019/9/26.
//
#include <iostream>
#include <string>

using namespace std;

# define MAX  1000

struct person {

    string name;
    int sex;
    int age;
    string phone;
    string addr;

};

struct address_books {

    struct person personArray[MAX];
    int size;
};


/**
 * 添加联系人-利用指针地址传递可以改变形参
 */
void addPerson(address_books *pBooks);

/**
 * 显示联系人-利用指针地址传递可以改变形参
 */
void showPerson(address_books *pBooks);

/**
 * 查找联系人-利用指针地址传递可以改变形参
 */
void findPerson(address_books *pBooks);

/**
 * 修改联系人-利用指针地址传递可以改变形参
 */
void modifyPerson(address_books *pBooks);

/**
 * 清空联系人-利用指针地址传递可以改变形参
 */
void cleanPerson(address_books *pBooks);

/**
 * 显示通讯录菜单
 */
void showMenu() {

    cout << "**********************" << endl;
    cout << "***** 1.添加联系人 ****" << endl;
    cout << "***** 2.显示联系人 ****" << endl;
    cout << "***** 3.删除联系人 ****" << endl;
    cout << "***** 4.查找联系人 ****" << endl;
    cout << "***** 5.修改联系人 ****" << endl;
    cout << "***** 6.清空联系人 ****" << endl;
    cout << "***** 0.退出通讯录 ****" << endl;

}

int isExist(address_books *pBooks, string name) {
    for (int i = 0; i < pBooks->size; ++i) {
        if (pBooks->personArray[i].name == name) {
            return i;
        }
    }

    return -1;

}

void deletePerson(address_books *pBooks, int ret) {
    for (int i = ret; i < pBooks->size; ++i) {
        pBooks->personArray[i] = pBooks->personArray[i + 1];//数据迁移
        /*   if (pBooks->personArray[i].name == name){
               return  i;
           }*/
    }
    pBooks->size--;

}


/**
 * 通讯录
 */
int main101() {

    int select = 0;//创建用户选择输入变量

    address_books abs;
    abs.size = 0;

    while (true) {
        showMenu();

        cin >> select;

        switch (select) {
            case 1://1.添加联系人
                addPerson(&abs);
                break;
            case 2://2.显示联系人
                showPerson(&abs);
                break;
            case 3://3.删除联系人
                {
                    string name;
                    cout << "请输入删除联系人姓名" << endl;
                    cin >> name;
                    int res = isExist(&abs, name);
                    if (res == -1) {
                        cout << "查无此人" << endl;
                    } else {
                        deletePerson(&abs, res);
                    }
                    system("pause");//按任意键继续
                    system("cls");//清屏
                }
                break;
            case 4://4.查找联系人
                findPerson(&abs);
                break;
            case 5://5.修改联系人
                modifyPerson(&abs);
                break;
            case 6:// 6.清空联系人
                cleanPerson(&abs);
                break;
            case 0://0.退出通讯录
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break;
            default:
                cout << "输入错误！！！" << endl;
                break;

        }


    }

//    system("pause");
//
//    return  0;
}

void cleanPerson(address_books *pBooks) {
    pBooks->size = 0; //逻辑清空，只需将通讯录联系人个数置为0
    cout << "通讯录已清空" << endl;
    system("pause");//按任意键继续
    system("cls");//清屏
}

void modifyPerson(address_books *pBooks) {
    string name1;
    cout << "请输入修改联系人姓名" << endl;
    cin >> name1;

    int res = isExist(pBooks, name1);
    if (res == -1) {
        cout << "查无此人" << endl;
    } else {

        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        pBooks->personArray[res].name = name;

        cout << "请输入性别" << endl;
        cout << "1————男" << endl;
        cout << "2————女" << endl;
        int sex = 0;

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                pBooks->personArray[res].sex = sex;
                break;
            }
            cout << "输入有误，重新输入" << endl;
        }


        int age;
        cout << "请输入年龄" << endl;
        cin >> age;
        pBooks->personArray[res].age = age;

        string phone;
        cout << "请输入电话" << endl;
        cin >> phone;
        pBooks->personArray[res].phone = phone;

        string address;
        cout << "请输入联系地址" << endl;
        cin >> address;
        pBooks->personArray[res].addr = address;

    }
    system("pause");//按任意键继续
    system("cls");//清屏
}

void findPerson(address_books *pBooks) {
    string name;
    cout << "请输入查找联系人姓名" << endl;
    cin >> name;

    int res = isExist(pBooks, name);
    if (res == -1) {
        cout << "查无此人" << endl;
    } else {
        person person = pBooks->personArray[res];
        cout << "姓名：" <<person.name << "\t";
        cout << "性别：" <<(person.sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" <<person.age << "\t";
        cout << "电话：" <<person.phone << "\t";
        cout << "地址：" << person.addr << endl;
    }
    system("pause");//按任意键继续
    system("cls");//清屏
}

void showPerson(address_books *pBooks) {
    if (pBooks->size == 0) {
        cout << "通讯录为空" << endl;
    } else {
        for (int i = 0; i < pBooks->size; ++i) {
            cout << "姓名：" << pBooks->personArray[i].name << "\t";
            cout << "性别：" << (pBooks->personArray[i].sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << pBooks->personArray[i].age << "\t";
            cout << "电话：" << pBooks->personArray[i].phone << "\t";
            cout << "地址：" << pBooks->personArray[i].addr << endl;
        }
    }

    system("pause");//按任意键继续
    system("cls");//清屏
}

void addPerson(address_books *pBooks) {

    if (pBooks->size == 1000) {
        cout << "通讯录已满，无法添加" << endl;
        return;
    } else {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        pBooks->personArray[pBooks->size].name = name;

        cout << "请输入性别" << endl;
        cout << "1————男" << endl;
        cout << "2————女" << endl;
        int sex = 0;

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                pBooks->personArray[pBooks->size].sex = sex;
                break;
            }
            cout << "输入有误，重新输入" << endl;
        }


        int age;
        cout << "请输入年龄" << endl;
        cin >> age;
        pBooks->personArray[pBooks->size].age = age;

        string phone;
        cout << "请输入电话" << endl;
        cin >> phone;
        pBooks->personArray[pBooks->size].phone = phone;

        string address;
        cout << "请输入联系地址" << endl;
        cin >> address;
        pBooks->personArray[pBooks->size].addr = address;

        pBooks->size++;

        cout << "添加成功" << endl;

        system("pause");//按任意键继续
        system("cls");//清屏
    }

}

