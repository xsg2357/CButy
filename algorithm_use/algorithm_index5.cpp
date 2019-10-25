//
// Created by Administrator on 2019/10/25.
//
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

class myPrintVectorAlogrithm
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

/**
 * set_intersection
    功能描述：
        求两个容器的交集
    函数原型：
        set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
        // 求两个集合的交集
        // 注意:两个集合必须是有序序列
        // beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 // dest 目标容器开始迭代器
 */
int main189(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

    vector<int> vTar;
    //取两个里面较小的值给目标容器开辟空间
    //大容器包含小容器 开辟空间 取最小容器的size即可
    vTar.resize(min(v1.size(),v2.size()));
    // 交集
    vector<int>::iterator itEnd = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin());
//    求交集的两个集合必须的有序序列
//    目标容器开辟空间需要从两个容器中取小值
//    set_intersection返回值既是交集中最后一个元素的位置
    for_each(vTar.begin(),itEnd,myPrintVectorAlogrithm());
//    5 6 7 8 9
    return  0;
}

/**
 * et_union
    功能描述：
        求两个集合的并集
    函数原型：
        set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
        // 求两个集合的并集
        // 注意:两个集合必须是有序序列
        // beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 // dest 目标容器开始迭代器
 */
int main190(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }

//    求并集的两个集合必须的有序序列
//    目标容器开辟空间需要两个容器size相加
//    set_union返回值既是并集中最后一个元素的位置
    vector<int> vTar;
    vTar.resize(v1.size()+v2.size());
    vector<int>::iterator itEnd = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin());
    for_each(vTar.begin(),itEnd,myPrintVectorAlogrithm());
//    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    return  0;
}

/**
 * set_difference
    功能描述：
        求两个集合的差集
    函数原型：
        set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
        // 求两个集合的差集
        // 注意:两个集合必须是有序序列
        // beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 // dest 目标容器开始迭代器
 */
int main(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+5);
    }
    //    求差集的两个集合必须的有序序列
//    目标容器开辟空间需要从两个容器size取较大值
//    set_difference返回值既是差集中最后一个元素的位置
    vector<int> vTarget;
    //取两个里面较大的值给目标容器开辟空间
    vTarget.resize(max(v1.size(),v2.size()));

    cout << " v1 & v2 set_difference:" << endl;
    for_each(vTarget.begin(),set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin()),myPrintVectorAlogrithm());
    cout << endl;
    cout << " v2 & v1 set_difference:" << endl;
    for_each(vTarget.begin(),set_difference(v2.begin(),v2.end(),v1.begin(),v1.end(),vTarget.begin()),myPrintVectorAlogrithm());
//    v1 & v2 set_difference:
//    0 1 2 3 4
//    v2 & v1 set_difference:
//    10 11 12 13 14

    return  0;
}
