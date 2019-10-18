//
// Created by Administrator on 2019/10/18.
//

# include <iostream>
#include <string>
#include <queue>

using namespace std;

class  QueuePerson{
public:

    QueuePerson(const string &name, int age) : _name(name), _age(age) {}

    string _name;
    int _age;
};


/**
 * queue 常用接口
    功能描述：栈容器常用的对外接口
    构造函数：
        queue<T> que; //queue采用模板类实现，queue对象的默认构造形式
        queue(const queue &que); //拷贝构造函数
    赋值操作：
        queue& operator=(const queue &que); //重载等号操作符
    数据存取：
        push(elem); //往队尾添加元素
        pop(); //从队头移除第一个元素
        back(); //返回最后一个元素
        front(); //返回第一个元素
    大小操作：
        empty(); //判断堆栈是否为空
        size(); //返回栈的大小
 */
int main155(){
//    入队 --- push
//    出队 --- pop
//    返回队头元素 --- front
//    返回队尾元素 --- back
//    判断队是否为空 --- empty
//    返回队列大小 --- size
    queue<QueuePerson> que;

    //准备数据
    QueuePerson p1("ts", 30);
    QueuePerson p2("swk", 1000);
    QueuePerson p3("zbj", 900);
    QueuePerson p4("ss", 800);

    //入队列 不支持随机访问
    que.push(p1);
    que.push(p2);
    que.push(p3);
    que.push(p4);

    //队列不提供迭代器
    while (!que.empty()){

        cout << "first == >" << que.front()._name <<  "==> name,age <==" << que.front()._age  << endl;
        cout << "end == >" << que.back()._name <<  "==> name,age <==" << que.back()._age  << endl;

        cout << endl;

        que.pop();

    }

    cout << "size is " << que.size() << endl;

//    first == >ts==> name,age <==30
//    end == >ss==> name,age <==800
//
//    first == >swk==> name,age <==1000
//    end == >ss==> name,age <==800
//
//    first == >zbj==> name,age <==900
//    end == >ss==> name,age <==800
//
//    first == >ss==> name,age <==800
//    end == >ss==> name,age <==800
//
//    size is 0


    return  0;
}