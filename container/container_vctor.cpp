//
// Created by Administrator on 2019/10/10.
//

# include <iostream>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int>& v) {

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}


/**
 * 创建vector容器-构造函数
   函数原型：
        vector<T> v; //采用模板实现类实现，默认构造函数
        vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
        vector(n, elem); //构造函数将n个elem拷贝给本身。
        vector(const vector &vec); //拷贝构造函数。
 */
 void testVector001(){
     vector<int> v1;

    for (int i = 0; i <10 ; ++i) {
        v1.push_back(i);
    }

    printVector(v1);

    vector<int>  v2(v1.begin(),v1.end());
    printVector(v2);

    vector<int>  v3(10,100);
    printVector(v3);

    vector<int>  v4(v1);
    printVector(v4);
//    0 1 2 3 4 5 6 7 8 9
//    0 1 2 3 4 5 6 7 8 9
//    100 100 100 100 100 100 100 100 100 100
//    0 1 2 3 4 5 6 7 8 9

 }

/**
 * vector 赋值操作
 * 给vector容器进行赋值
    函数原型：
        vector& operator=(const vector &vec);//重载等号操作符
        assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
        assign(n, elem); //将n个elem拷贝赋值给本身。
 */
 void testVector002(){
    vector<int> v1;
    for (int i = 0; i <10 ; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int>  v2;
    v2 = v1;
    printVector(v2);

    vector<int>  v3;
    v3.assign(v1.begin(),v1.end());
    printVector(v3);

    vector<int>  v4;
    v4.assign(10,100);
    printVector(v4);
//    0 1 2 3 4 5 6 7 8 9
//    0 1 2 3 4 5 6 7 8 9
//    0 1 2 3 4 5 6 7 8 9
//    100 100 100 100 100 100 100 100 100 100

}

/**
 * vector容器的容量和大小
 * 对vector容器的容量和大小操作
    函数原型：
        empty(); //判断容器是否为空
        capacity(); //容器的容量
        size(); //返回容器中元素的个数
        resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
        ​ //如果容器变短，则末尾超出容器长度的元素被删除。
        resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
        ​ //如果容器变短，则末尾超出容器长度的元素被删除
 */
void testVector003(){
    vector<int> v1;
    for (int i = 0; i <10 ; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    if (v1.empty()){
        cout << " v1 is empty" << endl;
    }else{
        cout << " v1 is not empty" << endl;
        cout << " v1  capacity :" << v1.capacity() << endl;
        cout << " v1 size :" << v1.size() << endl;

    }


    //resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    v1.resize(15,100);
    printVector(v1);

    //resize 重新指定大小 ，若指定的更小，超出部分元素被删除
    v1.resize(5);
    //判断是否为空 --- empty
    //返回元素个数 --- size
    //返回容器容量 --- capacity
    //重新指定大小 --- resize
    printVector(v1);

//    0 1 2 3 4 5 6 7 8 9
//    v1 is not empty
//    v1  capacity :16
//    v1 size :10
//    0 1 2 3 4 5 6 7 8 9 100 100 100 100 100
//    0 1 2 3 4

 }

/**
 * vector插入和删除
 * 对vector容器进行插入、删除操作
    函数原型：
        push_back(ele); //尾部插入元素ele
        pop_back(); //删除最后一个元素
        insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
        insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
        erase(const_iterator pos); //删除迭代器指向的元素
        erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
        clear(); //删除容器中所有元素
 */
 void testVector004(){
    vector<int> v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);
    //尾删法
    v1.pop_back();
    printVector(v1);

    //插入 第一个参数是迭代器
    v1.insert(v1.begin(),100);
    printVector(v1);

    v1.insert(v1.begin(),2,300);
    printVector(v1);

    v1.erase(v1.begin());
    printVector(v1);

//    v1.erase(v1.begin(),v1.end());
    v1.clear();
   /* 尾插 --- push_back
    尾删 --- pop_back
    插入 --- insert (位置迭代器)
    删除 --- erase （位置迭代器）
    清空 --- clear*/
    printVector(v1);

//    10 20 30 40 50
//    10 20 30 40
//    100 10 20 30 40
//    300 300 100 10 20 30 40
//    300 100 10 20 30 40


}

/**
 * vector数据的存取
 * 对vector中的数据的存取操作
    函数原型：
        at(int idx); //返回索引idx所指的数据
        operator[]; //返回索引idx所指的数据
        front(); //返回容器中第一个数据元素
        back(); //返回容器中最后一个数据元素
 */
void testVector005(){
    vector<int> v1;

    for (int i = 0; i <10 ; ++i) {
        v1.push_back(i);
    }

    for (int j = 0; j <v1.size() ; ++j) {
        cout << v1[j] << " ";
    }
    cout << endl;
    for (int j = 0; j <v1.size() ; ++j) {
        cout << v1.at(j)<< " ";
    }
    cout << endl;

    cout << v1.front()<< " ";
    cout << v1.back()<< " ";
//    0 1 2 3 4 5 6 7 8 9
//    0 1 2 3 4 5 6 7 8 9
//    0 9


 }

/**
 * vector  互换容器
 * 实现两个容器内元素进行互换
    函数原型：
        swap(vec); // 将vec与本身的元素互换
 */
 void testVector006(){
    vector<int> v1;
    for (int i = 0; i <10 ; ++i) {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int j = 10; j > 0; --j) {
        v2.push_back(j);
    }
    printVector(v2);

    v1.swap(v2);
    printVector(v1);
    printVector(v2);

//    0 1 2 3 4 5 6 7 8 9
//    10 9 8 7 6 5 4 3 2 1
//    10 9 8 7 6 5 4 3 2 1
//    0 1 2 3 4 5 6 7 8 9

    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }

    cout << " v  capacity :" << v.capacity() << endl;
    cout << " v size :" << v.size() << endl;

    v.resize(3);//重新指定大小
    cout << " v  capacity :" << v.capacity() << endl;
    cout << " v size :" << v.size() << endl;

    //利用swap收缩内存空间 vector<int>(v) 匿名对象拷贝v， 匿名对象->v ，容器的交换
    //swap可以使两个容器互换，可以达到实用的收缩内存效果
    vector<int>(v).swap(v);
    cout << " v  capacity :" << v.capacity() << endl;
    cout << " v size :" << v.size() << endl;
//    v  capacity :131072
//    v size :100000
//    v  capacity :131072
//    v size :3
//    v  capacity :3
//    v size :3


 }


/**
 *  vector预留空间
    功能描述：
        减少vector在动态扩展容量时的扩展次数
    函数原型：
        reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
 */
 void testVector007(){
    vector<int> v;



    //预留空间 前： num = 18
    v.reserve(100000);
    //预留空间 后： num = 1

    int num = 0;
    int* p = NULL;  //指向首个元素的地址
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
        //&v[0] 代表首地址 首个元素的地址
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    cout << "num:" << num << endl;
 }


 /**
 * vector数据结构和数组非常相似，也称为单端数组
 * 不同之处在于数组是静态空间，而vector可以动态扩展
 * 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
 * vector容器的迭代器是支持随机访问的迭代器
 */
int main152(){
//    testVector001();
//     testVector002();
//     testVector003();
//     testVector004();
//     testVector005();
//     testVector006();
     testVector007();
    return  0;
}