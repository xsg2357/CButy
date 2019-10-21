//
// Created by Administrator on 2019/10/21.
//
# include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

#define CEHUA  0
#define MEISHU 1
#define YANFA  2

using namespace std;

class EgWorker
{
public:
    string _Name;
    int _Salary;
};

void setEgGroup(vector<EgWorker> &vector, multimap<int, EgWorker> &multimap);

void showEgWorkerByGourp(multimap<int, EgWorker> &multimap);

void  createEg2Worker(vector<EgWorker> &v){
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; ++i) {
        EgWorker egWorker;
        egWorker._Name = "employee";
        egWorker._Name += nameSeed[i];

        egWorker._Salary = rand() % 10000 + 10000;// 10000 ~ 19999
        v.push_back(egWorker);
    }
}


/**
 * 案例-员工分组
    3.10.1 案例描述
        公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
        员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
        随机给10名员工分配部门和工资
        通过multimap进行信息的插入 key(部门编号) value(员工)
        分部门显示员工信息
    3.10.2 实现步骤
        创建10名员工，放到vector中
        遍历vector容器，取出每个员工，进行随机分组
        分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
        分部门显示员工信息
 */
int main(){
    srand((unsigned int)time(NULL));

    //1、创建员工
    vector<EgWorker>vWorker;
    createEg2Worker(vWorker);

    //2、员工分组
    multimap<int,EgWorker> mWorker;
    setEgGroup(vWorker,mWorker);

    //3、分组显示员工
    showEgWorkerByGourp(mWorker);

    return  0;
}

void showEgWorkerByGourp(multimap<int, EgWorker> &m) {
    cout << "ce hua:" << endl;

    multimap<int,EgWorker>::iterator pos = m.find(CEHUA);
    int count = m.count(CEHUA); // 统计具体人数
    int index = 0;
    for (; pos != m.end() && index < count; pos++ , index++)
    {
        cout << "_Name =  " << pos->second._Name << " , _Salary " << pos->second._Salary << endl;
    }

    cout << "----------------------" << endl;
    cout << "mei shu : " << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU); // 统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "_Name =  " << pos->second._Name << " , _Salary " << pos->second._Salary << endl;
    }

    cout << "----------------------" << endl;
    cout << "yan fa: " << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA); // 统计具体人数
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "_Name =  " << pos->second._Name << " , _Salary " << pos->second._Salary << endl;
    }

//    ce hua:
//    _Name =  employeeD , _Salary 16500
//    _Name =  employeeI , _Salary 16962
//    _Name =  employeeJ , _Salary 14464
//            ----------------------
//    mei shu :
//    _Name =  employeeC , _Salary 16334
//    _Name =  employeeE , _Salary 19169
//    _Name =  employeeG , _Salary 11478
//            ----------------------
//    yan fa:
//    _Name =  employeeA , _Salary 10041
//    _Name =  employeeB , _Salary 18467
//    _Name =  employeeF , _Salary 15724
//    _Name =  employeeH , _Salary 19358
}

void setEgGroup(vector<EgWorker> &vec, multimap<int, EgWorker> &mul) {
    for (vector<EgWorker>::iterator it = vec.begin();it!=vec.end();it++){
        //产生随机部门编号
        int deptId = rand() % 3; // 0 1 2
        //分组显示
        mul.insert(make_pair(deptId,*it));
    }
}
