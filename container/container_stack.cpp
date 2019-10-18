//
// Created by Administrator on 2019/10/18.
//
# include <iostream>
#include <string>
#include <stack>

using namespace std;


/**
 * stack 常用接口
    功能描述：栈容器常用的对外接口
        构造函数：
        stack<T> stk; //stack采用模板类实现， stack对象的默认构造形式
        stack(const stack &stk); //拷贝构造函数
    赋值操作：
        stack& operator=(const stack &stk); //重载等号操作符
    数据存取：
        push(elem); //向栈顶添加元素
        pop(); //从栈顶移除第一个元素
        top(); //返回栈顶元素
    大小操作：
        empty(); //判断堆栈是否为空
        size(); //返回栈的大小
 */
int main154(){

//    入栈 --- push
//    出栈 --- pop
//    返回栈顶 --- top
//    判断栈是否为空 --- empty
//    返回栈大小 --- size

    stack<int> s;

    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "size " << s.size() << endl;

    //只要栈不为空 就查看栈顶
    while (!s.empty()){

        //查看栈顶元素
        cout << "top " << s.top() << endl;

        //出栈
        s.pop();
    }

    cout << "size " << s.size() << endl;

//    size 4
//    top 40
//    top 30
//    top 20
//    top 10
//    size 0

    return  0;
}
