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
 * �����ϵ��-����ָ���ַ���ݿ��Ըı��β�
 */
void addPerson(address_books *pBooks);

/**
 * ��ʾ��ϵ��-����ָ���ַ���ݿ��Ըı��β�
 */
void showPerson(address_books *pBooks);

/**
 * ������ϵ��-����ָ���ַ���ݿ��Ըı��β�
 */
void findPerson(address_books *pBooks);

/**
 * �޸���ϵ��-����ָ���ַ���ݿ��Ըı��β�
 */
void modifyPerson(address_books *pBooks);

/**
 * �����ϵ��-����ָ���ַ���ݿ��Ըı��β�
 */
void cleanPerson(address_books *pBooks);

/**
 * ��ʾͨѶ¼�˵�
 */
void showMenu() {

    cout << "**********************" << endl;
    cout << "***** 1.�����ϵ�� ****" << endl;
    cout << "***** 2.��ʾ��ϵ�� ****" << endl;
    cout << "***** 3.ɾ����ϵ�� ****" << endl;
    cout << "***** 4.������ϵ�� ****" << endl;
    cout << "***** 5.�޸���ϵ�� ****" << endl;
    cout << "***** 6.�����ϵ�� ****" << endl;
    cout << "***** 0.�˳�ͨѶ¼ ****" << endl;

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
        pBooks->personArray[i] = pBooks->personArray[i + 1];//����Ǩ��
        /*   if (pBooks->personArray[i].name == name){
               return  i;
           }*/
    }
    pBooks->size--;

}


/**
 * ͨѶ¼
 */
int main101() {

    int select = 0;//�����û�ѡ���������

    address_books abs;
    abs.size = 0;

    while (true) {
        showMenu();

        cin >> select;

        switch (select) {
            case 1://1.�����ϵ��
                addPerson(&abs);
                break;
            case 2://2.��ʾ��ϵ��
                showPerson(&abs);
                break;
            case 3://3.ɾ����ϵ��
                {
                    string name;
                    cout << "������ɾ����ϵ������" << endl;
                    cin >> name;
                    int res = isExist(&abs, name);
                    if (res == -1) {
                        cout << "���޴���" << endl;
                    } else {
                        deletePerson(&abs, res);
                    }
                    system("pause");//�����������
                    system("cls");//����
                }
                break;
            case 4://4.������ϵ��
                findPerson(&abs);
                break;
            case 5://5.�޸���ϵ��
                modifyPerson(&abs);
                break;
            case 6:// 6.�����ϵ��
                cleanPerson(&abs);
                break;
            case 0://0.�˳�ͨѶ¼
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                return 0;
                break;
            default:
                cout << "������󣡣���" << endl;
                break;

        }


    }

//    system("pause");
//
//    return  0;
}

void cleanPerson(address_books *pBooks) {
    pBooks->size = 0; //�߼���գ�ֻ�轫ͨѶ¼��ϵ�˸�����Ϊ0
    cout << "ͨѶ¼�����" << endl;
    system("pause");//�����������
    system("cls");//����
}

void modifyPerson(address_books *pBooks) {
    string name1;
    cout << "�������޸���ϵ������" << endl;
    cin >> name1;

    int res = isExist(pBooks, name1);
    if (res == -1) {
        cout << "���޴���" << endl;
    } else {

        string name;
        cout << "����������" << endl;
        cin >> name;
        pBooks->personArray[res].name = name;

        cout << "�������Ա�" << endl;
        cout << "1����������" << endl;
        cout << "2��������Ů" << endl;
        int sex = 0;

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                pBooks->personArray[res].sex = sex;
                break;
            }
            cout << "����������������" << endl;
        }


        int age;
        cout << "����������" << endl;
        cin >> age;
        pBooks->personArray[res].age = age;

        string phone;
        cout << "������绰" << endl;
        cin >> phone;
        pBooks->personArray[res].phone = phone;

        string address;
        cout << "��������ϵ��ַ" << endl;
        cin >> address;
        pBooks->personArray[res].addr = address;

    }
    system("pause");//�����������
    system("cls");//����
}

void findPerson(address_books *pBooks) {
    string name;
    cout << "�����������ϵ������" << endl;
    cin >> name;

    int res = isExist(pBooks, name);
    if (res == -1) {
        cout << "���޴���" << endl;
    } else {
        person person = pBooks->personArray[res];
        cout << "������" <<person.name << "\t";
        cout << "�Ա�" <<(person.sex == 1 ? "��" : "Ů") << "\t";
        cout << "���䣺" <<person.age << "\t";
        cout << "�绰��" <<person.phone << "\t";
        cout << "��ַ��" << person.addr << endl;
    }
    system("pause");//�����������
    system("cls");//����
}

void showPerson(address_books *pBooks) {
    if (pBooks->size == 0) {
        cout << "ͨѶ¼Ϊ��" << endl;
    } else {
        for (int i = 0; i < pBooks->size; ++i) {
            cout << "������" << pBooks->personArray[i].name << "\t";
            cout << "�Ա�" << (pBooks->personArray[i].sex == 1 ? "��" : "Ů") << "\t";
            cout << "���䣺" << pBooks->personArray[i].age << "\t";
            cout << "�绰��" << pBooks->personArray[i].phone << "\t";
            cout << "��ַ��" << pBooks->personArray[i].addr << endl;
        }
    }

    system("pause");//�����������
    system("cls");//����
}

void addPerson(address_books *pBooks) {

    if (pBooks->size == 1000) {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    } else {
        string name;
        cout << "����������" << endl;
        cin >> name;
        pBooks->personArray[pBooks->size].name = name;

        cout << "�������Ա�" << endl;
        cout << "1����������" << endl;
        cout << "2��������Ů" << endl;
        int sex = 0;

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                pBooks->personArray[pBooks->size].sex = sex;
                break;
            }
            cout << "����������������" << endl;
        }


        int age;
        cout << "����������" << endl;
        cin >> age;
        pBooks->personArray[pBooks->size].age = age;

        string phone;
        cout << "������绰" << endl;
        cin >> phone;
        pBooks->personArray[pBooks->size].phone = phone;

        string address;
        cout << "��������ϵ��ַ" << endl;
        cin >> address;
        pBooks->personArray[pBooks->size].addr = address;

        pBooks->size++;

        cout << "��ӳɹ�" << endl;

        system("pause");//�����������
        system("cls");//����
    }

}

