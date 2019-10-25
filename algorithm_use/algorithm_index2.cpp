//
// Created by Administrator on 2019/10/25.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

void mySortPrint001(int val)
{
    cout << val << " ";
}



/**
 * sort
    功能描述：
        对容器内元素进行排序
    函数原型：
        sort(iterator beg, iterator end, _Pred);
        // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
        // beg 开始迭代器
        // end 结束迭代器
        // _Pred 谓词
 */
int main178(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    //从小到大排序 sort属于开发中最常用的算法之一
    sort(v.begin(),v.end());
    for_each(v.begin(),v.end(),mySortPrint001);
    cout << endl;

    //降序排列
    sort(v.begin(),v.end(),greater<int>());
    for_each(v.begin(),v.end(),mySortPrint001);
    cout << endl;
//    10 20 30 40 50
//    50 40 30 20 10
    return  0;
}

class my_random_shufflePrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};

/**
 * random_shuffle
    功能描述：
        洗牌 指定范围内的元素随机调整次序
    函数原型：
        random_shuffle(iterator beg, iterator end);
        // 指定范围内的元素随机调整次序
        // beg 开始迭代器
        // end 结束迭代器
 */
int main179(){
    srand((unsigned int ) time(NULL));//随机数种子
    vector<int> v;
    for(int i = 0 ; i < 10;i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), my_random_shufflePrint());
    cout << endl;

    //打乱顺序 random_shuffle洗牌算法比较实用，使用时记得加随机数种子
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(), v.end(), my_random_shufflePrint());
    cout << endl;
//    0 1 2 3 4 5 6 7 8 9
//    7 3 4 2 5 0 1 8 6 9
    return  0;
}

/**
 * merge
    功能描述：
        两个容器元素合并，并存储到另一容器中
    函数原型：
        merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
        // 容器元素合并，并存储到另一容器中
        // 注意: 两个容器必须是有序的
        // beg1 容器1开始迭代器 // end1 容器1结束迭代器 // beg2 容器2开始迭代器 // end2 容器2结束迭代器 // dest 目标容器开始迭代器
 */
int main180(){
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10 ; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
    }

    vector<int> vTar;
    //目标容器需要提前开辟空间
    vTar.resize(v1.size()+v2.size());
    //合并两个有序容器到vtar merge合并的两个容器必须的有序序列
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTar.begin());
    for_each(vTar.begin(), vTar.end(), my_random_shufflePrint());
    cout << endl;
//    0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
    return  0;
}

/**
 * reverse
    功能描述：
        将容器内元素进行反转
    函数原型：
        reverse(iterator beg, iterator end);
        // 反转指定范围的元素
        // beg 开始迭代器
        // end 结束迭代器
 */
int main181(){


    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(50);
    v.push_back(20);
    v.push_back(40);

    cout << "before: " << endl;
    for_each(v.begin(), v.end(), my_random_shufflePrint());
    cout << endl;

    cout << "after: " << endl;
//    reverse反转区间内元素，面试题可能涉及到
    reverse(v.begin(),v.end());
    for_each(v.begin(), v.end(), my_random_shufflePrint());

//    before:
//    10 30 50 20 40
//    after:
//    40 20 50 30 10

    return  0;
}