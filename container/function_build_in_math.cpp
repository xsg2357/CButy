//
// Created by Administrator on 2019/10/21.
//
# include <iostream>
# include <functional> //算术仿函数
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 内建函数对象
 */
int main163() {

    negate<int> n; //取反
    cout << n(10) << endl;
    plus<int> p;//加法
    cout << p(10, 20) << endl;
    minus<int> min;//减法
    cout << min(10, 20) << endl;
    multiplies<int> mul;//乘法
    cout << mul(10, 20) << endl;
    divides<int> div;//除法
    cout << div(10, 20) << endl;
    modulus<int> mod;//取模
    cout << mod(10, 20) << endl;
//    -10
//    30
//    -10
//    200
//    0
//    10
    return 0;
}

class MyFunctionalCompare {
public:
    bool operator()(int v1, int v2) {
        return v1 > v2;
    }
};


int main164() {

    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(40);
    v.push_back(20);

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //自己实现仿函数
    //sort(v.begin(), v.end(), MyFunctionalCompare());
    //STL内建仿函数  大于仿函数
    sort(v.begin(), v.end(), greater<int>());//大于
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), equal_to<int>());//等于
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), not_equal_to<int>());//不等于
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), greater_equal<int>());//大于等于
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), less<int>());//小于
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), less_equal<int>());//小于等于
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
//    10 30 50 40 20
//    50 40 30 20 10
//    50 40 30 20 10
//    10 20 30 40 50
//    50 40 30 20 10
//    10 20 30 40 50
//    10 20 30 40 50
    return 0;
}

int main165() {
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(false);

    for (vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    //逻辑非  将v容器搬运到v2中，并执行逻辑非运算
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
//    1 0 1 0
//    0 1 0 1

//    vector<bool> v3;
//    v3.resize(v.size());
//    transform(v.begin(), v.end(), v3.begin(), logical_or<bool>());////逻辑或
//    for (vector<bool>::iterator it = v3.begin(); it != v3.end(); it++) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    vector<bool> v4;
//    v4.resize(v.size());
//    transform(v.begin(), v.end(), v4.begin(), logical_and<bool>());//逻辑与
//    for (vector<bool>::iterator it = v4.begin(); it != v4.end(); it++) {
//        cout << *it << " ";
//    }
//    cout << endl;
    return 0;

}
