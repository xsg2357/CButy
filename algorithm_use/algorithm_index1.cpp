//
// Created by Administrator on 2019/10/25.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printforeach001(int val) {
    cout << val << " ";
}

class printforeach002 {

public:
    void operator()(int val) {
        cout << val << " ";
    }

};

/**
 * for_each
    功能描述：
        实现遍历容器
    函数原型：
        for_each(iterator beg, iterator end, _func);
        // 遍历算法 遍历容器元素
        // beg 开始迭代器
        // end 结束迭代器
        // _func 函数或者函数对象
 */
int main170() {

    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }

//    for_each在实际开发中是最常用遍历算法，需要熟练掌握
    for_each(v.begin(), v.end(), printforeach001);
    cout << endl;
    for_each(v.begin(), v.end(), printforeach002());
//    0 1 2 3 4 5 6 7 8 9
//    0 1 2 3 4 5 6 7 8 9
    return 0;
}

int printtransform001(int val) {
    return val;
}

class printtransform002 {

public:
    void operator()(int val) {
        cout << val << " ";
    }
};


/**
 * ransform
    功能描述：
        搬运容器到另一个容器中
    函数原型：
        transform(iterator beg1, iterator end1, iterator beg2, _func);
        //beg1 源容器开始迭代器
        //end1 源容器结束迭代器
        //beg2 目标容器开始迭代器
        //_func 函数或者函数对象
 */
int main171() {

    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
//    搬运的目标容器必须要提前开辟空间，否则无法正常搬运
    vector<int> vTarget; //目标容器
    vTarget.resize(v.size());//开辟空间
    transform(v.begin(), v.end(), vTarget.begin(), printtransform001);//搬运
    for_each(vTarget.begin(), vTarget.end(), printtransform002());
//    0 1 2 3 4 5 6 7 8 9
    return 0;
}

class FindPerson {
public:
    FindPerson(string name, int age) {
        this->_Name = name;
        this->_Age = age;
    }

    //重载== 底层判断 p==
    bool operator==(const FindPerson &p) {
        return this->_Name == p._Name && this->_Age == p._Age;
    }

public:
    string _Name;
    int _Age;
};

/**
 * find
    功能描述：
        查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
    函数原型：
        find(iterator beg, iterator end, value);
        // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
        // beg 开始迭代器
        // end 结束迭代器
        // value 查找的元素
 */
int main172() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

//    利用find可以在容器中找指定的元素，返回值是迭代器
    if (find(v.begin(), v.end(), 5) == v.end()) {
        cout << "not find" << endl;
    } else {
        cout << "find" << endl;
    }
//    find

    vector<FindPerson> vp;

    FindPerson p1("12", 12);
    FindPerson p2("13", 13);
    FindPerson p3("14", 14);
    FindPerson p4("15", 15);
    FindPerson p5("16", 16);
    FindPerson p6("17", 17);

    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);
    vp.push_back(p5);
    vp.push_back(p6);

//    利用find可以在容器中找指定的元素，返回值是迭代器
    vector<FindPerson>::iterator it = find(vp.begin(), vp.end(), p2);

    if (it == vp.end()) {
        cout << "not find" << endl;
    } else {
        cout << "find ==> name:" << it->_Name << " age:" << it->_Age << endl;
    }
//    find ==> name:13 age:13
    return 0;
}

class GreaterFindIfFive {
public:
    bool operator()(int val) {
        return val > 5;
    }
};

class GreaterFindIf20 {
public:
    bool operator()(FindPerson &val) {
        return val._Age > 10;
    }
};

/**
 * find_if
    功能描述：
        按条件查找元素
    函数原型：
        find_if(iterator beg, iterator end, _Pred);
        // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
        // beg 开始迭代器
        // end 结束迭代器
        // _Pred 函数或者谓词（返回bool类型的仿函数）
 */
int main173() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i + 1);
    }

//    find_if按条件查找使查找更加灵活，提供的仿函数可以改变不同的策略
    if (find_if(v.begin(), v.end(), GreaterFindIfFive()) == v.end()) {
        cout << "not find if" << endl;
    } else {
        cout << "find if" << endl;
    }
//    find if


    vector<FindPerson> vp;

    FindPerson p1("12", 12);
    FindPerson p2("13", 13);
    FindPerson p3("14", 14);
    FindPerson p4("15", 15);
    FindPerson p5("16", 16);
    FindPerson p6("17", 17);

    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);
    vp.push_back(p5);
    vp.push_back(p6);

    vector<FindPerson>::iterator it = find_if(vp.begin(), vp.end(), GreaterFindIf20());

    if (it == vp.end()) {
        cout << "not find if" << endl;
    } else {
        cout << "find if ==> name:" << it->_Name << " age:" << it->_Age << endl;
    }
//    find if==> name:12 age:12


    return 0;
}

/**
 * adjacent_find
    功能描述：
        查找相邻重复元素
    函数原型：
        adjacent_find(iterator beg, iterator end);
        // 查找相邻重复元素,返回相邻元素的第一个位置的迭代器
        // beg 开始迭代器
        // end 结束迭代器
 */
int main174() {

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);
    v.push_back(4);
    v.push_back(3);

//    如果出现查找相邻重复元素，记得用STL中的adjacent_find算法
    vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    if (it == v.end()) {
        cout << "not adjacent_find" << endl;
    } else {
        cout << " adjacent_find " << endl;
    }
//    adjacent_find
    return 0;
}


/**
 * binary_search
    功能描述：
        查找指定元素是否存在
    函数原型：
        bool binary_search(iterator beg, iterator end, value);
        // 查找指定的元素，查到 返回true 否则false
        // 注意: 在无序序列中不可用
        // beg 开始迭代器
        // end 结束迭代器
        // value 查找的元素
 */
int main175() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
//    二分查找法查找效率很高，值得注意的是查找的容器中元素必须的有序序列
//    注意: 在无序序列中不可用
    if (binary_search(v.begin(), v.end(), 2)) {
        cout << "binary_search" << endl;
    } else {
        cout << "not binary_search" << endl;
    }
//     binary_search
    return 0;
}

/**
 * count
    功能描述：
        统计元素个数
    函数原型：
        count(iterator beg, iterator end, value);
        // 统计元素出现次数
        // beg 开始迭代器
        // end 结束迭代器
        // value 统计的元素
 */
int main176() {

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

    int num = count(v.begin(), v.end(), 4);
    cout << " num = " << num << endl;

//    统计自定义数据类型时候，需要配合重载 operator==
    vector<FindPerson> vp;

    FindPerson p1("12", 12);
    FindPerson p2("13", 13);
    FindPerson p3("12", 12);
    FindPerson p4("15", 15);
    FindPerson p5("16", 16);
    FindPerson p6("12", 12);

    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);
    vp.push_back(p5);
    vp.push_back(p6);

    FindPerson p("12",12);

    int personNum = count(vp.begin(), vp.end(),p);
    cout << " personNum = " << personNum << endl;
//    num = 3
//    personNum = 3
    return 0;
}

class GreaterCountIf002
{
public:
    bool operator()(const FindPerson &fp)
    {
        return fp._Age >= 12;
    }
};

class GreaterCountIf001
{
public:
    bool operator()(int val)
    {
        return val >= 4;
    }
};


/**
 *  count_if
    功能描述：
        按条件统计元素个数
    函数原型：
        count_if(iterator beg, iterator end, _Pred);
        // 按条件统计元素出现次数
        // beg 开始迭代器
        // end 结束迭代器
        // _Pred 谓词
 */
int main177(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);

//    按值统计用count，按条件统计用count_if
    int num = count_if(v.begin(),v.end(),GreaterCountIf001());
    cout << " num = " << num << endl;

    FindPerson p1("12", 12);
    FindPerson p2("13", 13);
    FindPerson p3("12", 12);
    FindPerson p4("15", 15);
    FindPerson p5("16", 16);
    FindPerson p6("12", 12);

    vector<FindPerson> vp;
    vp.push_back(p1);
    vp.push_back(p2);
    vp.push_back(p3);
    vp.push_back(p4);
    vp.push_back(p5);
    vp.push_back(p6);

    int personNum = count_if(vp.begin(),vp.end(),GreaterCountIf002());
    cout << " personNum = " << personNum << endl;
//    num = 4
//    personNum = 6
    return  0;
}
