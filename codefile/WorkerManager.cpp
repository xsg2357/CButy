//
// Created by Administrator on 2019/10/8.
//

#include "../headerfile/WorkerManager.h"

WorkerManager::WorkerManager() {
    ifstream its;
    its.open(FILENAME, ios::in);
    //�ļ�������
    if (!its.is_open()) {
        cout << "�ļ�������" << endl;
        this->_empNum = 0;
        this->workerArray = NULL;
        this->_fileIsExist = true;
        its.close();
        return;
    }
    //�ļ����ڵ��ǿ�
    char ch;
    its >> ch;
    if (its.eof()) {
        cout << "�ļ�Ϊ��" << endl;
        this->_empNum = 0;
        this->workerArray = NULL;
        this->_fileIsExist = true;
        its.close();
        return;
    }
    //�ļ�������
    this->_empNum = this->getEmpNum();
    cout << "Ա������:" << this->_empNum << endl;

    //���ٿռ� �浽������
    this->workerArray = new Worker *[this->_empNum];
    this->initEmp();

}

string WorkerManager::UTF8ToGB(const char *str) {
    string result;
    WCHAR *strSrc;
    LPSTR szRes;

    //�����ʱ�����Ĵ�С
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //�����ʱ�����Ĵ�С
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}

void WorkerManager::showMenu() {

    cout << "*********************************" << endl;
    cout << "****** ��ӭʹ��ְ������ϵͳ ********" << endl;
    cout << "****** 0.�˳�ϵͳ         ********" << endl;
    cout << "****** 1.����Ա��         ********" << endl;
    cout << "****** 2.��ʾԱ��         ********" << endl;
    cout << "****** 3.ɾ����ְԱ��      ********" << endl;
    cout << "****** 4.�޸�ְ��         ********" << endl;
    cout << "****** 5.����ְ��         ********" << endl;
    cout << "****** 6.�������         ********" << endl;
    cout << "****** 7.���ϵͳ         ********" << endl;
    cout << "*********************************" << endl;


}

void WorkerManager::addEmp() {

    int addNum = 0;
    cout << "�����Ա������" << endl;
    cin >> addNum;
    if (addNum > 0) {
        int newSize = this->_empNum + addNum;//�仯��Ա������

        //�����¿ռ�
        Worker **pWorker = new Worker *[newSize];

        if (this->workerArray != NULL) {
            for (int i = 0; i < newSize; ++i) {
                pWorker[i] = this->workerArray[i];
            }
        }

        for (int j = 0; j < addNum; ++j) {

            int id;
            string name;
            int dChoice;
            cout << "����ӵ�" << (j + 1) << "��Ա���ı��" << endl;
            cin >> id;
            cout << "����ӵ�" << (j + 1) << "��Ա��������" << endl;
            cin >> name;
            cout << "����ӵ�" << (j + 1) << "��Ա���Ĳ���" << endl;
            cout << "1.Ա��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> dChoice;
            Worker *worker = NULL;
            switch (dChoice) {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    cout << "��������" << endl;
                    break;
            }
            pWorker[this->_empNum + j] = worker;
        }

        //�ͷ�ԭ�пռ�
        delete[] this->workerArray;
        //���¿ռ�ָ��
        this->workerArray = pWorker;
        //����Ա������
        this->_empNum = newSize;
        this->_fileIsExist = false;//�ļ���Ϊ��
        cout << "���" << addNum << "��Ա���ɹ���" << endl;
        this->saveEmp();
    } else {
        cout << "��������" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::saveEmp() {

    ofstream ost;
    ost.open(FILENAME, ios::out);
    for (int i = 0; i < this->_empNum; ++i) {

        ost << this->workerArray[i]->_id << "\t"
            << this->workerArray[i]->_name << "\t"
            << this->workerArray[i]->_deptId << "\t" << endl;

    }
    ost.close();

}

void WorkerManager::exitSystem() {
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

int WorkerManager::getEmpNum() {
    ifstream its;
    its.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while (its >> id && its >> name && its >> dId) {
        num++;
    }
    its.close();
    return num;
}

int WorkerManager::isExistEmp(int id) {
    int idIndex = -1;

    for (int i = 0; i < this->_empNum; ++i) {
        if (this->workerArray[i]->_id == id) {
            idIndex = i;
            break;
        }
    }

    return idIndex;
}

void WorkerManager::showEmp() {
    if (this->_fileIsExist) {
        cout << "�ļ������ڻ���Ϊ��" << endl;
        return;
    }
    for (int i = 0; i < this->_empNum; ++i) {
        this->workerArray[i]->showInfo();
    }
    system("pause");
    system("cls");
//    exit(0);
}

void WorkerManager::delEmp() {
    if (this->_fileIsExist) {
        cout << "�ļ������ڻ���Ϊ��" << endl;
        return;
    }
    int id = 0;
    cout << "������Ա��id:" << endl;
    cin >> id;
    int relId = this->isExistEmp(id);
    if (relId != -1) {
        for (int i = relId; i < this->_empNum - 1; ++i) {
            this->workerArray[i] = this->workerArray[i + 1];
        }
        //ɾ��������ļ����ݺ�Ա������
        this->_empNum--;
        saveEmp();
        cout << "ɾ���ɹ�" << endl;
    } else {
        cout << "Ա��������" << endl;
    }
    system("pause");
//    exit(0);
}

void WorkerManager::sortEmp() {
    if (this->_fileIsExist) {
        cout << "�ļ������ڻ���Ϊ��" << endl;
        return;
    }
    cout << "����������+��ʽ" << endl;
    cout << "1.Ա���Ž���" << endl;
    cout << "2.Ա��������" << endl;
    int select = 0;
    cin >> select;
    for (int i = 0; i < this->_empNum; ++i) {
        int minOrMax = i;
        if (select == 1 || select == 2) {
            for (int j = 0; j < this->_empNum; ++j) {//����
                if (select == 1) {
                    if (this->workerArray[minOrMax]->_id > this->workerArray[j]->_id) {
                        minOrMax = j;
                    }
                } else {//����
                    if (this->workerArray[minOrMax]->_id < this->workerArray[j]->_id) {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax) {
                Worker *temp = this->workerArray[i];
                this->workerArray[i] = this->workerArray[i + 1];
                this->workerArray[i + 1] = temp;
            }
        } else {
            cout << "��������" << endl;
            break;
        }
    }
    cout << "����ɹ�" << endl;
    this->saveEmp();
}

void WorkerManager::findEmp() {
    if (this->_fileIsExist) {
        cout << "�ļ������ڻ���Ϊ��" << endl;
        return;
    }

    cout << "��������ҷ�ʽ" << endl;
    cout << "1.����Ų�" << endl;
    cout << "2.���ؼ��֣����֣�����" << endl;
    int select = 0;
    cin >> select;
    if (select == 1) {
        int id = 0;
        cout << "������Ա��id:" << endl;
        cin >> id;
        int relId = this->isExistEmp(id);
        if (relId != -1) {
            this->workerArray[relId]->showInfo();
            cout << "ɾ���ɹ�" << endl;
        } else {
            cout << "Ա��������" << endl;
        }
    } else if (select == 2) {
        string name = "";
        cout << "������Ա��id:" << endl;
        cin >> name;
        bool flag = false;
        for (int i = 0; i < this->_empNum; ++i) {
            if (this->workerArray[i]->_name == name) {
                flag = true;
                this->workerArray[i]->showInfo();
            }
        }
        if (!flag) {
            cout << "����ʧ��" << endl;
        }
    } else {
        cout << "��������" << endl;
    }


    system("pause");
//    exit(0);
}

void WorkerManager::ModEmp() {
    if (this->_fileIsExist) {
        cout << "�ļ������ڻ���Ϊ��" << endl;
        return;
    }
    int id = 0;
    cout << "������Ա��id:" << endl;
    cin >> id;
    int relId = this->isExistEmp(id);
    if (relId != -1) {
        delete this->workerArray[relId];
        int idNew = 0;
        string name;
        int dChoice;
        cin >> idNew;
        cout << "���޸�Ա��������" << endl;
        cin >> name;
        cout << "���޸�Ա���Ĳ���" << endl;
        cout << "1.Ա��" << endl;
        cout << "2.����" << endl;
        cout << "3.�ϰ�" << endl;
        cin >> dChoice;
        Worker *worker = NULL;
        switch (dChoice) {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                cout << "��������" << endl;
                break;
        }
        //ɾ��������ļ����ݺ�Ա������
        this->workerArray[relId] = worker;
        cout << "�޸ĳɹ�" << endl;
        saveEmp();
    } else {
        cout << "Ա��������" << endl;
    }
    system("pause");
//    exit(0);
}

void WorkerManager::cleanEmp() {
    if (this->_fileIsExist) {
        cout << "�ļ������ڻ���Ϊ��" << endl;
        return;
    }
    cout << "�����������ʽ" << endl;
    cout << "1.����" << endl;
    cout << "2.ȷ��" << endl;
    int select = 0;
    cin >> select;
    if (select == 1) {
        system("pause");
    } else if (select == 2) {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->workerArray != NULL) {
            for (int i = 0; i <this->_empNum; ++i) {
                delete this->workerArray[i];
                this->workerArray[i] =NULL;
            }
            delete [] this->workerArray;
            this->workerArray = NULL;
            this->_fileIsExist = true;
            this->_empNum = 0;
        }
        cout << "��ճɹ�" << endl;
    } else {
        cout << "��������" << endl;
        system("pause");
    }
}

void WorkerManager::initEmp() {
    ifstream its;
    its.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while (its >> id && its >> name && its >> dId) {
        Worker *worker = NULL;
//        char chrs[name.length()];
//        strcpy_s(chrs, sizeof(name), name.c_str());//ע�⣬stringת��Ϊchar[]��ʱ��Ĭ�ϵ��ַ���������'\0'��־��
//        name = UTF8ToGB(chrs);
        switch (dId) {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
        }
        this->workerArray[num] = worker;
        num++;
    }
    its.close();
}


WorkerManager::~WorkerManager() {
    if (this->workerArray != NULL) {
        delete[]this->workerArray;
        workerArray = NULL;
    }
}