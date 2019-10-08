//
// Created by Administrator on 2019/10/8.
//

#include "../headerfile/WorkerManager.h"

WorkerManager::WorkerManager() {
    ifstream its;
    its.open(FILENAME,ios::in);
    //文件不存在
    if(!its.is_open()){
        cout << "文件不存在" << endl;
        this->_empNum = 0;
        this->workerArray = NULL;
        this->_fileIsExist = true;
        its.close();
        return ;
    }
    //文件存在但是空
    char ch;
    its >> ch;
    if(its.eof()){
        cout << "文件为空" << endl;
        this->_empNum = 0;
        this->workerArray = NULL;
        this->_fileIsExist = true;
        its.close();
        return ;
    }
    //文件有数据
    this->_empNum = this->getEmpNum();
    cout << "员工数量:" << this->_empNum<< endl;

    //开辟空间 存到数组中
    this->workerArray = new Worker *[this->_empNum];
    this->initEmp();

}

string WorkerManager::UTF8ToGB(const char* str)
{
    string result;
    WCHAR *strSrc;
    LPSTR szRes;

    //获得临时变量的大小
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i+1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //获得临时变量的大小
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i+1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete []strSrc;
    delete []szRes;

    return result;
}

void WorkerManager::showMenu() {

    cout << "*********************************" << endl;
    cout << "****** 欢迎使用职工管理系统 ********" << endl;
    cout << "****** 0.退出系统         ********" << endl;
    cout << "****** 1.增加员工         ********" << endl;
    cout << "****** 2.显示员工         ********" << endl;
    cout << "****** 3.删除离职员工      ********" << endl;
    cout << "****** 4.修改职工         ********" << endl;
    cout << "****** 5.查找职工         ********" << endl;
    cout << "****** 6.编号排序         ********" << endl;
    cout << "****** 7.清空系统         ********" << endl;
    cout << "*********************************" << endl;


}

void WorkerManager::addEmp() {

    int addNum = 0;
    cout << "请添加员工数量" << endl;
    cin >> addNum;
    if (addNum > 0) {
        int newSize = this->_empNum + addNum;//变化新员工数量

        //开启新空间
        Worker ** pWorker = new Worker *[newSize];

        if (this->workerArray != NULL) {
            for (int i = 0; i < newSize; ++i) {
                pWorker[i] = this->workerArray[i];
            }
        }

        for (int j = 0; j < addNum; ++j) {

            int id;
            string name;
            int dChoice;
            cout << "请添加第" << (j + 1) << "新员工的编号" << endl;
            cin >> id;
            cout << "请添加第" << (j + 1) << "新员工的姓名" << endl;
            cin >> name;
            cout << "请添加第" << (j + 1) << "新员工的部门" << endl;
            cout << "1.员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dChoice;
            Worker *worker;
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
                    cout << "输入有误！" << endl;
                    break;
            }
            pWorker[this->_empNum + j] = worker;
        }

        //释放原有空间
        delete[] this->workerArray;
        //更新空间指向
        this->workerArray =pWorker;
        //更新员工数量
        this->_empNum = newSize;
        this->_fileIsExist = false;//文件不为空
        cout << "添加"<< addNum <<"名员工成功！" << endl;
        this->saveEmp();
    } else {
        cout << "输入有误！" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::saveEmp()  {

    ofstream ost;
    ost.open(FILENAME,ios::out);
    for (int i = 0; i < this->_empNum; ++i) {

        ost << this->workerArray[i]->_id << "\t"
                << this->workerArray[i]->_name << "\t"
                << this->workerArray[i]->_deptId << "\t" <<endl;

    }
    ost.close();

}

void WorkerManager::exitSystem() {
    cout << "欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}
int WorkerManager::getEmpNum() {
    ifstream its;
    its.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while(its >> id &&its >> name &&its >> dId){
        num ++;
    }
    its.close();
    return  num;
}
void WorkerManager::showEmp()  {
    if(this->_fileIsExist){
        cout << "文件不存在或者为空" << endl;
        return;
    }
    for (int i = 0; i < this->_empNum; ++i) {
        this->workerArray[i]->showInfo();
    }
    system("pause");
    system("cls");
//    exit(0);
}
void WorkerManager::initEmp() {
    ifstream its;
    its.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num = 0;
    while(its >> id &&its >> name &&its >> dId){
        Worker *worker = NULL;
        char chrs[name.length()];
        strcpy_s(chrs, sizeof(name), name.c_str());//注意，string转化为char[]的时候，默认的字符串背后有'\0'标志；
        name = UTF8ToGB(chrs);
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
        num ++;
    }
    its.close();
}


WorkerManager::~WorkerManager() {
    if(this->workerArray !=NULL){
        delete []this->workerArray;
        workerArray = NULL;
    }
}