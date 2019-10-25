//
// Created by Administrator on 2019/10/25.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class  MyCopyAndReplace001{

public:
    void operator()(int val){
        cout << val << " ";
    }
};


/**
 * copy
    功能描述：
        容器内指定范围的元素拷贝到另一容器中
    函数原型：
        copy(iterator beg, iterator end, iterator dest);
        // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
        // beg 开始迭代器
        // end 结束迭代器
        // dest 目标起始迭代器
 */
int main183(){
    vector<int> v;
    for (int i = 0; i <10 ; ++i) {
        v.push_back(i+1);
    }
    vector<int> v1;
    //利用copy算法在拷贝时，目标容器记得提前开辟空间
    v1.resize(v.size());
    copy(v.begin(),v.end(),v1.begin());

    for_each(v1.begin(),v1.end(),MyCopyAndReplace001());
//    1 2 3 4 5 6 7 8 9 10
    return  0;
}

/**
 * replace
    功能描述：
        将容器内指定范围的旧元素修改为新元素
    函数原型：
    replace(iterator beg, iterator end, oldvalue, newvalue);
        // 将区间内旧元素 替换成 新元素
        // beg 开始迭代器
        // end 结束迭代器
        // oldvalue 旧元素
        // newvalue 新元素
 */
int main184(){
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "before:" << endl;
    for_each(v.begin(), v.end(), MyCopyAndReplace001());
    cout << endl;

//    replace会替换区间内满足条件的元素
    replace(v.begin(),v.end(),20,2000);

    cout << "after:" << endl;
    for_each(v.begin(), v.end(), MyCopyAndReplace001());
    cout << endl;
//    20 30 20 40 50 10 20
//    after:
//    2000 30 2000 40 50 10 2000
    return  0;
}

class ReplaceGreater30
{
public:
    bool operator()(int val)
    {
        return val >= 30;
    }

};

/**
 * replace_if
    功能描述:
        将区间内满足条件的元素，替换成指定元素
    函数原型：
    replace_if(iterator beg, iterator end, _pred, newvalue);
        // 按条件替换元素，满足条件的替换成指定元素
        // beg 开始迭代器
        // end 结束迭代器
        // _pred 谓词
        // newvalue 替换的新元素
 */
int main185(){
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);

    cout << "before:" << endl;
    for_each(v.begin(), v.end(), MyCopyAndReplace001());
    cout << endl;

//    replace_if按条件查找，可以利用仿函数灵活筛选满足的条件
    replace_if(v.begin(), v.end(),ReplaceGreater30(),2000);

    cout << "after:" << endl;
    for_each(v.begin(), v.end(), MyCopyAndReplace001());
    cout << endl;

//    before:
//    20 30 20 40 50 10 20
//    after:
//    20 2000 20 2000 2000 10 20

    return  0;
}

/**
 * swap
    功能描述：
        互换两个容器的元素
    函数原型：
        swap(container c1, container c2);
        // 互换两个容器的元素
        // c1容器1
        // c2容器2
 */
int main186(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
        v2.push_back(i+100);
    }
    cout << "before:" << endl;
    for_each(v1.begin(), v1.end(), MyCopyAndReplace001());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyCopyAndReplace001());
    cout << endl;

//    swap交换容器时，注意交换的容器要同种类型
    cout << "after:" << endl;
    swap(v1,v2);

    for_each(v1.begin(), v1.end(), MyCopyAndReplace001());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyCopyAndReplace001());
    cout << endl;

//    before:
//    0 1 2 3 4 5 6 7 8 9
//    100 101 102 103 104 105 106 107 108 109
//    after:
//    100 101 102 103 104 105 106 107 108 109
//    0 1 2 3 4 5 6 7 8 9
    return  0;
}