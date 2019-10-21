//
// Created by Administrator on 2019/10/21.
//
# include <iostream>
#include <string>
#include <map>

using namespace std;


void printMapValue(map<int, int> &m) {

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << "key = " << it->first << ", value= " << it->second << endl;
    }
    cout << endl;
}


/**
 * map构造和赋值
    功能描述：
        对map容器进行构造和赋值操作
函数原型：
    构造：
        map<T1, T2> mp; //map默认构造函数:
        map(const map &mp); //拷贝构造函数
    赋值：
        map& operator=(const map &mp); //重载等号操作符
 */
void testMap001() {
//    map中所有元素都是成对出现，插入数据时候要使用对组
    map<int, int> ma;
//    error: invalid type argument of unary '*' (have 'int')
    ma.insert(pair<int, int>(1, 20));
    ma.insert(pair<int, int>(3, 30));
    ma.insert(pair<int, int>(4, 40));
    ma.insert(pair<int, int>(2, 10));

    printMapValue(ma);

    map<int, int> ma2(ma);
    printMapValue(ma2);

    map<int, int> ma3 = ma2;
    printMapValue(ma3);

//    key = 1, value= 20
//    key = 2, value= 10
//    key = 3, value= 30
//    key = 4, value= 40
//
//    key = 1, value= 20
//    key = 2, value= 10
//    key = 3, value= 30
//    key = 4, value= 40
//
//    key = 1, value= 20
//    key = 2, value= 10
//    key = 3, value= 30
//    key = 4, value= 40


}

/**
 * map大小和交换
        功能描述：
            统计map容器大小以及交换map容器
        函数原型：
            size(); //返回容器中元素的数目
            empty(); //判断容器是否为空
            swap(st); //交换两个集合容器
 */
void testMap002() {

//    统计大小 --- size
//    判断是否为空 --- empty
//    交换容器 --- swap


    map<int, int> ma;
//    error: invalid type argument of unary '*' (have 'int')
    ma.insert(pair<int, int>(1, 20));
    ma.insert(pair<int, int>(3, 30));
    ma.insert(pair<int, int>(4, 40));
    ma.insert(pair<int, int>(2, 10));
    if (ma.empty()) {
        cout << " map is null" << endl;
    } else {
        cout << " map is not null" << endl;
        cout << " map size is " << ma.size() << endl;

    }

    map<int, int> ma2;
//    error: invalid type argument of unary '*' (have 'int')
    ma2.insert(pair<int, int>(4, 200));
    ma2.insert(pair<int, int>(5, 300));
    ma2.insert(pair<int, int>(6, 400));
    ma2.insert(pair<int, int>(7, 100));

    cout << " before: " << endl;
    printMapValue(ma);
    printMapValue(ma2);

    cout << " after: " << endl;
    ma.swap(ma2);
    printMapValue(ma);
    printMapValue(ma2);
//    map is not null
//    map size is 4
//    before:
//    key = 1, value= 20
//    key = 2, value= 10
//    key = 3, value= 30
//    key = 4, value= 40
//
//    key = 4, value= 200
//    key = 5, value= 300
//    key = 6, value= 400
//    key = 7, value= 100
//
//    after:
//    key = 4, value= 200
//    key = 5, value= 300
//    key = 6, value= 400
//    key = 7, value= 100
//
//    key = 1, value= 20
//    key = 2, value= 10
//    key = 3, value= 30
//    key = 4, value= 40

}


/**
 * map插入和删除
    功能描述：
        map容器进行插入数据和删除数据
    函数原型：
        insert(elem); //在容器中插入元素。
        clear(); //清除所有元素
        erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
        erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
        erase(key); //删除容器中值为key的元素。
 */
void testMap003() {
//    map插入方式很多，记住其一即可
//    插入 --- insert
//    删除 --- erase
//    清空 --- clear

    map<int, int> ma;
//    error: invalid type argument of unary '*' (have 'int')
    //插入方式
    ma.insert(pair<int, int>(1, 20));
    ma.insert(make_pair(2, 30));
    ma.insert(map<int, int>::value_type(20, 30));
    ma[4] = 40;//不推荐使用[] 用途：但是可以用来访问key的值
    printMapValue(ma);

    //删除方式
    ma.erase(ma.begin());
    ma.erase(4);//按照key删除
    printMapValue(ma);
    //    ma.erase(ma.begin(),ma.end());//相当于清空

    ma.clear();//清空
    printMapValue(ma);

//    key = 1, value= 20
//    key = 2, value= 30
//    key = 4, value= 40
//    key = 20, value= 30
//
//    key = 2, value= 30
//    key = 20, value= 30
//

}

/**
 * map查找和统计
    功能描述：
        对map容器进行查找数据以及统计数据
    函数原型：
        find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
        count(key); //统计key的元素个数
 */
void testMap004() {
//    查找 --- find （返回的是迭代器）
//    统计 --- count （对于map，结果为0或者1）
    map<int, int> ma;
//    multimap<int,int> ma; //multimap的用法和map一样
//    error: invalid type argument of unary '*' (have 'int')
    ma.insert(pair<int, int>(1, 20));
    ma.insert(pair<int, int>(3, 30));
    ma.insert(pair<int, int>(4, 40));
    ma.insert(pair<int, int>(2, 10));
    ma.insert(pair<int, int>(3, 30));

    map<int, int>::iterator pos = ma.find(3);
    if (pos != ma.end()) {
        cout << " map is  find " << (*pos).first << "value = " << (*pos).second << endl;
    } else {
        cout << " map is not find" << endl;
    }

    /**
     * 统计
     * map不允许插入重复key count统计而言 结果要么是0 要么是1
     * multimap 的cout统计结果可能大于1
     */
    int num = ma.count(3);
    cout << " num = " << num << endl;

//    map is  find 3value = 30
//    num = 1

}


class MyMapCompareSort {
public:
    bool operator()(int v1, int v2) {

        return v1 > v2;
    }
};

/**
 * map容器排序
    学习目标：
        map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
    主要技术点:
        利用仿函数，可以改变排序规则
 */
void testMap005() {
//    利用仿函数可以指定map容器的排序规则
//    对于自定义数据类型，map必须要指定排序规则,同set容器
    map<int, int> ma;
//    error: invalid type argument of unary '*' (have 'int')
    ma.insert(pair<int, int>(1, 20));
    ma.insert(pair<int, int>(3, 30));
    ma.insert(pair<int, int>(4, 40));
    ma.insert(pair<int, int>(2, 10));

    cout << " before: " << endl;
    printMapValue(ma);

    map<int, int,MyMapCompareSort> ma1;
//    error: invalid type argument of unary '*' (have 'int')
    ma1.insert(pair<int, int>(1, 20));
    ma1.insert(pair<int, int>(3, 30));
    ma1.insert(pair<int, int>(4, 40));
    ma1.insert(pair<int, int>(2, 10));
    cout << " after: " << endl;
    for (map<int, int,MyMapCompareSort>::iterator it = ma1.begin(); it != ma1.end(); it++) {
        cout << "key = " << it->first << ", value= " << it->second << endl;
    }
    cout << endl;

//    before:
//    key = 1, value= 20
//    key = 2, value= 10
//    key = 3, value= 30
//    key = 4, value= 40
//
//    after:
//    key = 4, value= 40
//    key = 3, value= 30
//    key = 2, value= 10
//    key = 1, value= 20
}


int main159() {
//    testMap001();
//    testMap002();
//    testMap003();
//    testMap004();
    testMap005();

    return 0;
}

