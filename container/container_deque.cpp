//
// Created by Administrator on 2019/10/18.
//
# include <iostream>
# include <algorithm> //本文件引用algorithm头文件，主要是为了sort排序方法
#include <string>
#include <deque>

using namespace std;

void dequePrintInfo(const deque<int> &deq) {

    for (deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++) {

        cout << *it << " ";

    }

    cout << endl;

}

/**
 * deque容器构造
 * deque<T> deqT; //默认构造形式
    deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
    deque(n, elem); //构造函数将n个elem拷贝给本身。
    deque(const deque &deq); //拷贝构造函数
 */
void testDeque01() {

    deque<int> deq1;
    for (int i = 0; i < 10; ++i) {
        deq1.push_back(i);
    }
    dequePrintInfo(deq1);

    deque<int> deq2(deq1.begin(), deq1.end());
    dequePrintInfo(deq2);

    deque<int> deq3(10, 100);
    dequePrintInfo(deq3);

    deque<int> deq4 = deq3;
    dequePrintInfo(deq3);

    //    0 1 2 3 4 5 6 7 8 9
//    0 1 2 3 4 5 6 7 8 9
//    100 100 100 100 100 100 100 100 100 100
//    100 100 100 100 100 100 100 100 100 100
}

/**
 * 给deque容器进行赋值
 * deque& operator=(const deque &deq); //重载等号操作符
    assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
    assign(n, elem); //将n个elem拷贝赋值给本身。
 */
void testDeque02() {
    deque<int> deq1;
    for (int i = 0; i < 10; ++i) {
        deq1.push_back(i);
    }
    dequePrintInfo(deq1);
    // =
    deque<int> deq2 = deq1;
    dequePrintInfo(deq2);

    //assign
    deque<int> deq3;
    deq3.assign(deq2.begin(),deq2.end());
    dequePrintInfo(deq3);

    deque<int> deq4;
    deq4.assign(10,100);
    dequePrintInfo(deq4);

//    0 1 2 3 4 5 6 7 8 9
//    0 1 2 3 4 5 6 7 8 9
//    0 1 2 3 4 5 6 7 8 9
//    100 100 100 100 100 100 100 100 100 100
}


/**
 * 对deque容器的大小进行操作,deque容器没有容量限制，可以无限制扩大
 * deque.empty(); //判断容器是否为空
    deque.size(); //返回容器中元素的个数
    deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。
    ​ //如果容器变短，则末尾超出容器长度的元素被删除。
    deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。
    ​ //如果容器变短，则末尾超出容器长度的元素被删除。
 */
void testDeque03() {

//    deque没有容量的概念
//    判断是否为空 --- empty
//    返回元素个数 --- size
//    重新指定个数 --- resize

    deque<int> deq1;
    for (int i = 0; i < 10; ++i) {
        deq1.push_back(i);
    }
    dequePrintInfo(deq1);

    if(deq1.empty()){
        cout  << " deq1 is null" << endl;
    }else{
        cout  << " deq1 is not null" << endl;
        cout  << " deq1 size is "<< deq1.size() << endl;
    }

    deq1.resize(15,1);
    dequePrintInfo(deq1);

    deq1.resize(5);
    dequePrintInfo(deq1);
//
//    0 1 2 3 4 5 6 7 8 9
//    deq1 is not null
//    deq1 size is 10
//    0 1 2 3 4 5 6 7 8 9 1 1 1 1 1
//    0 1 2 3 4


}

/**
 * 向deque容器中插入和删除数据
 * 两端插入操作：
    push_back(elem); //在容器尾部添加一个数据
    push_front(elem); //在容器头部插入一个数据
    pop_back(); //删除容器最后一个数据
    pop_front(); //删除容器第一个数据
 * 指定位置操作：
    insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
    insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。
    insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。
    clear(); //清空容器的所有数据
    erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
    erase(pos); //删除pos位置的数据，返回下一个数据的位置。
 */
void testDeque04() {


//    插入和删除提供的位置是迭代器！
//    尾插 --- push_back
//    尾删 --- pop_back
//    头插 --- push_front
//    头删 --- pop_front

    deque<int> deq1;
    //尾插
    deq1.push_back(10);
    deq1.push_back(20);
    //头插
    deq1.push_front(100);
    deq1.push_front(200);

    dequePrintInfo(deq1);

    //尾删法
    deq1.pop_back();
    //头删法
    deq1.pop_front();
    dequePrintInfo(deq1);


    deque<int> deq2;
    //尾插
    deq2.push_back(10);
    deq2.push_back(20);
    //头插
    deq2.push_front(100);
    deq2.push_front(200);
    dequePrintInfo(deq2);

    //insert插入
    deq2.insert(deq2.begin(),1000);
    deq2.insert(deq2.begin(),2,10000);
    dequePrintInfo(deq2);

    deque<int>deq3;
    deq3.push_back(1);
    deq3.push_back(2);
    deq3.push_back(3);

    deq2.insert(deq2.begin(),deq3.begin(),deq3.end());
    dequePrintInfo(deq2);


    //删除
    deque<int> deq4;
    deq4.push_back(10);
    deq4.push_back(20);
    deq4.push_front(100);
    deq4.push_front(200);
    dequePrintInfo(deq4);

    deque<int>::const_iterator it = deq4.begin();
    it++;
    deq4.erase(it);
    dequePrintInfo(deq4);

//    deq4.erase(deq4.begin(), deq4.end());
    deq4.clear();
    dequePrintInfo(deq4);
//    200 100 10 20
//    100 10
//    200 100 10 20
//    10000 10000 1000 200 100 10 20
//    1 2 3 10000 10000 1000 200 100 10 20
//    200 100 10 20
//    200 10 20
//

}

/**
 * 对deque 中的数据的存取操作
 * at(int idx); //返回索引idx所指的数据
    operator[]; //返回索引idx所指的数据
    front(); //返回容器中第一个数据元素
    back(); //返回容器中最后一个数据元素
 */
void testDeque05() {

//    除了用迭代器获取deque容器中元素，[ ]和at也可以
//    front返回容器第一个元素
//    back返回容器最后一个元素

    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    //[] 访问
    for (int i = 0; i <d.size() ; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
    // at 访问
    for (int i = 0; i <d.size() ; ++i) {
        cout << d.at(i) << " ";
    }
    cout << endl;

    cout << d.front() << "===> first " << endl;
    cout << d.back() << "===> end " << endl;

//    300 200 100 10 20 30
//    300 200 100 10 20 30
//    300===> first
//    30===> end


}

/**
 * 利用算法实现对deque容器进行排序
 * sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
 */
void testDeque06() {

    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(100);
    d.push_front(200);
    dequePrintInfo(d);

//    sort算法非常实用，使用时包含头文件 algorithm即可
//      默认排序规则： 从小到大
//   vector 也可用sort函数进行排序
    sort(d.begin(),d.end());
    dequePrintInfo(d);
//    200 100 10 20
//    10 20 100 200


}


int main153() {

//    testDeque01();
//    testDeque02();
//    testDeque03();
//    testDeque04();
//    testDeque05();
    testDeque06();


    return 0;
}

