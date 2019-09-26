//
// Created by Administrator on 2019/9/26.
//
#include <iostream>

using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;
const  int c_g_b = 10;

/**
 * 内存分区模型
 * 代码区：存放函数体的 二进制代码 由曹作雄进行管理
 * 全局区： 存放全局变量和静态变量、以及常量
 * 栈区：由编译器自动编译释放、存放函数的局部变量、参数值等
 * 堆区：由程序员分配和释放、若程序员不释放，则由程序结束时系统自动回收
 * 存在的意义：不同区域存放的数据、赋予不同的生命周期、给我们最大 的灵活度
 */
int main201(){
    //代码区——程序运行前 程序编译后 生成了exe可执行程序
    //存放cpu执行的机器指令
    //代码区是共享的 共享的目的是对于频繁执行的程序 只需要在内存中存取一分代码即可
    //代码区是只读的 使其制度的原因是防止以外程序修改了他的指令


    //全局区 全局变量和静态变量，在运行前
    //全局区还包含常量区，字符串常量 和 整型常量
    //局部变量
    int a = 10;
    int b = 10;

    //不在全局区：局部变量 const修饰的局部变量（局部常量）
    //在全局区：全局变量和静态变量（static关键字）、常量（字符串常量和const修饰的全局变量）和全局变量

    cout <<  " a size address is "  << &a << endl; //0x67febc
    cout <<  " g_a all size address is "  << &g_a << endl; //0x40a008

    cout <<  " b size address is "  << &b << endl; //0x67feb8
    cout <<  " g_b all size address is "  << &g_b << endl; //0x40a00c

    //静态变量 在普通变量前面加上static
    static  int s_a = 20;
    static  int s_b = 20;
    cout <<  " s_a size address is "  << &s_a << endl; //0x40a010
    cout <<  " s_b size address is "  << &s_b << endl; //0x40a014
    cout <<  " string size address is "  << &"annnn" << endl; //0x40bcb6

    //const 修饰的局部变量和全局变量
    const  int c_g_a = 30;
    cout <<  " c_g_a size address is "  << &c_g_a << endl; //0x67feb4
    cout <<  " c_g_b size address is "  << &c_g_b << endl; //0x40bc18

    return  0;
}

//int * func(int c){//形参数据也会放在栈区
int  func(int c){//形参数据也会放在栈区

    int a = 10;

//    return  &a; //address of stack memory associated with local var returned
    return  a;
}


/**
 *  程序运行后：栈区
 *  由编译器自动分配释放、存放函数额参数值、局部变量等
 *  注意事项：栈区 不返回局部变量 的地址
 */
int main202(){

//    int  *p = func(1);
    int  p = func(1);

//    cout <<  " *p =  "  << *p  << endl; // 10第一次可以打印正确的数字 ，是因为编译器做了保留
//    cout <<  " *p =  "  << *p  << endl; //第二次数据就不会保留

    return  0;
}


int * func1(){

     //指针本质也是局部变量 放在栈上 指针保存的数据放在栈区
     int *a =  new int(10);

    return a;
}


/**
 * 在堆区开放内存，用new 关键字，程序运行后
 */
int main203(){

    int  *p = func1();

    cout <<  " *p =  "  << *p  << endl;//10
    cout <<  " *p =  "  << *p  << endl;//10
    cout <<  " *p =  "  << *p  << endl;//10

    return  0;
}

/**
 * new 的基本语法
 * new 数据类型 返回的是一个指针
 */
int * func2(){

    int *p = new int(10);

    return  p;

}

void test001(){

    int *p = func2();
    cout <<  " *p =  "  << *p  << endl;//10
    cout <<  " *p =  "  << *p  << endl;//10
    cout <<  " *p =  "  << *p  << endl;//10
    //    * 堆区：由程序员分配和释放、若程序员不释放，则由程序结束时系统自动回收
    // 如果手动释放堆区的数据，则使用关键字delete
    delete  p;
//    cout <<  " *p =  "  << *p  << endl;// 内存已被释放，再次访问会报错，非法操作
}

void test002(){

    //再堆区创建10整型的数组
    int * arr = new int[10];// 10代表数组有10个元素
    for (int i = 0; i < 10 ; ++i) {
        arr[i] = i+100;
    }

    for (int j = 0; j <10 ; ++j) {
        cout <<  " *arr =  "  << arr[j]  << endl;//10
    }

    delete []arr; //释放数组需要加上【】


}


int main204(){

//   test001();
   test002();

    return  0;
}