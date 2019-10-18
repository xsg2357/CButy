//
// Created by Administrator on 2019/10/18.
//

# include <iostream>
#include <string>
#include <set>
using namespace std;

void  printSetValue(set<int> &value){
    for(set<int>::const_iterator it = value.begin();it != value.end();it++ ){
        cout<< *it << " ";
    }
    cout << endl;
}


/**
 * set构造和赋值
    功能描述：创建set容器以及赋值
    构造：
        set<T> st; //默认构造函数：
        set(const set &st); //拷贝构造函数
 */
void  testSet001(){

    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);
    printSetValue(s1);

    //所有元素都会在插入时自动被排序
    set<int> s2(s1);
    printSetValue(s2);

    //     set不允许容器中有重复的元素
    set<int> s3;
    s3 = s2;
    printSetValue(s3);
//    10 20 30 40 50
//    10 20 30 40 50
//    10 20 30 40 50

}

/**
 * set大小和交换
    功能描述：
        统计set容器大小以及交换set容器
    函数原型：
        size(); //返回容器中元素的数目
        empty(); //判断容器是否为空
        swap(st); //交换两个集合容器
 */
void  testSet002(){

//    统计大小 --- size
//    判断是否为空 --- empty
//    交换容器 --- swap

    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);

    if(s1.empty()){
        cout  << " s1 is null" << endl;
    } else{
        cout  << " s1 is not null" << endl;
        cout  << " s1 size is "<< s1.size() << endl;
        printSetValue(s1);

    }


    set<int> s2;
    s2.insert(100);
    s2.insert(400);
    s2.insert(200);
    s2.insert(300);
    s2.insert(500);
    printSetValue(s2);
    cout  << " after:" << endl;
    s1.swap(s2);
    printSetValue(s1);
    printSetValue(s2);

//    s1 is not null
//    s1 size is 5
//    10 20 30 40 50
//    100 200 300 400 500
//    after:
//    100 200 300 400 500
//    10 20 30 40 50
}


/**
 * set插入和删除
    功能描述：
          set容器进行插入数据和删除数据
    函数原型：
        insert(elem); //在容器中插入元素。
        clear(); //清除所有元素
        erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
        erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
        erase(elem); //删除容器中值为elem的元素。
 */
void  testSet003(){
//    插入 --- insert
//    删除 --- erase
//    清空 --- clear
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);
    printSetValue(s1);

    //删除
    s1.erase(s1.begin());
    printSetValue(s1);
    s1.erase(30);
    printSetValue(s1);

    //清空
//    s1.erase(s1.begin(),s1.end());
    s1.clear();
    printSetValue(s1);

//    10 20 30 40 50
//    20 30 40 50
//    20 40 50

}

/**
 * set查找和统计
    功能描述：
        对set容器进行查找数据以及统计数据
    函数原型：
        find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
        count(key); //统计key的元素个数
 */
void  testSet004(){
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30);
    s1.insert(50);

    set<int>::iterator pos = s1.find(30);
    if (pos != s1.end()){
        cout  << " s1 is find" << endl;
    }else{
        cout  << " s1 is not find" << endl;

    }

    //统计的结果要么是0 要么是1
    int num = s1.count(30);
    cout  << " num = " << num << endl;
//    查找 --- find （返回的是迭代器）
//    统计 --- count （对于set，结果为0或者1）
//    num = 1


//    s1 is find
}

/**
 * set和multiset区别
    学习目标：
        掌握set和multiset的区别
    区别：
        set不可以插入重复数据，而multiset可以
        set插入数据的同时会返回插入结果，表示插入是否成功
        multiset不会检测数据，因此可以插入重复数据
 *
 */
void  testSet005(){
//    如果不允许插入重复数据可以利用set
//            如果需要插入重复数据利用multise
    set<int> s1;
    pair<set<int>::iterator,bool > ret = s1.insert(10);
    if(ret.second){
        cout  << " s1 first is insert" << endl;
    }else{
        cout  << " s1 first is not insert" << endl;

    }

    ret = s1.insert(10);
    if(ret.second){
        cout  << " s1 first is insert" << endl;
    }else{
        cout  << " s1 first is not insert" << endl;
    }

    multiset<int> mst;
    mst.insert(10);
    mst.insert(10);
    mst.insert(10);
    for(multiset<int>::const_iterator it = mst.begin();it != mst.end();it++ ){
        cout << *it << " ";
    }
    cout << endl;
//    s1 first is insert
//    s1 first is not insert
//    10 10 10
}

/**
 * pair对组创建
    功能描述：
        成对出现的数据，利用对组可以返回两个数据
    两种创建方式：
        pair<type, type> p ( value1, value2 );
        pair<type, type> p = make_pair( value1, value2 );
 */
void  testSet006(){
    pair<string,int> par1(string("zhang san"),10);
    cout << " name = " << par1.first << " ,age = " << par1.second << endl;
    pair<string,int> par2 = make_pair("zhang san",20);
    cout << " name = " << par2.first << " ,age = " << par2.second << endl;
//    name = zhang san ,age = 10
//    name = zhang san ,age = 20
}

class  MySetSortCompare{
public:
    //仿函数
    bool  operator()(int v1, int v2){

        return  v1 > v2;
    }
};

/**
 * et容器排序
    学习目标：
        set容器默认排序规则为从小到大，掌握如何改变排序规则
    主要技术点：
        利用仿函数，可以改变排序规则
        示例一 set存放内置数据类型
 */
void  testSet007(){
    set<int> s1;
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(50);

    //默认从小到大
    printSetValue(s1);

    //指定排序规则为从大到小
    set<int,MySetSortCompare> s2;
    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(50);
    for(set<int,MySetSortCompare>::const_iterator it = s2.begin();it != s2.end();it++ ){
        cout<< *it << " ";
    }
    cout << endl;
//    10 20 30 40 50
//    50 40 30 20 10
}


class  SetSortPerson{
public:

    SetSortPerson(const string &name, int age) : _name(name), _age(age) {}

    string _name;
    int _age;
};


class  CompareSetSortPerson{
public:
    bool operator()(const SetSortPerson &setSortPerson1,const SetSortPerson &setSortPerson2){

        return  setSortPerson1._age > setSortPerson2._age;
    }

};

/**
 *         示例二 set存放自定义数据类型
 */
void  testSet008(){
    SetSortPerson p1("liu bei",30);
    SetSortPerson p2("liu bei1",40);
    SetSortPerson p3("liu bei2",20);
    SetSortPerson p4("liu bei3",50);
    set<SetSortPerson, CompareSetSortPerson> s;
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    for(set<SetSortPerson,CompareSetSortPerson>::const_iterator it = s.begin();it != s.end();it++ ){
        cout << " name = " << it->_name << " ,age = " <<  it->_age << endl;
    }
//    name = liu bei3 ,age = 50
//    name = liu bei1 ,age = 40
//    name = liu bei ,age = 30
//    name = liu bei2 ,age = 20
 }


int main158(){
//    testSet001();
//    testSet002();
//    testSet003();
//    testSet004();
//    testSet005();
//    testSet006();
//    testSet007();
    testSet008();
    return 0;
}
