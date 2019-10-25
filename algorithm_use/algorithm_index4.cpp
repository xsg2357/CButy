//
// Created by Administrator on 2019/10/25.
//
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * accumulate(iterator beg, iterator end, value);
        // 计算容器元素累计总和
        // beg 开始迭代器
        // end 结束迭代器
        // value 起始值
 */
int main187(){

    vector<int> v;
    for (int i = 0; i <100 ; ++i) {
        v.push_back(i);
    }

    // 加入header #include <numeric> accumulate使用时头文件注意是 numeric
    int total = accumulate(v.begin(),v.end(),5);
    cout << total << endl;
//    4955
    return  0;
}

class myPrintNumeric
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};


/**
 *  fill
    功能描述：
         向容器中填充指定的元素
    函数原型：
        fill(iterator beg, iterator end, value);
        // 向容器中填充元素
        // beg 开始迭代器
        // end 结束迭代器
        // value 填充的值
 */
int main188(){

    vector<int> v;
    v.resize(10);

    // 加入header #include <numeric>
    // 利用fill可以将容器区间内元素填充为 指定的值
    fill(v.begin(),v.end(),100);
    for_each(v.begin(),v.end(),myPrintNumeric());
//    100 100 100 100 100 100 100 100 100 100
    return  0;
}
