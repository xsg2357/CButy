//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
using namespace std;
class  Pigger{
public:

    Pigger(){ //栈区--构造函数
        cout << " Pigger 普通=无参 start() "  << endl;
    }

    Pigger(int a){
        cout << " Pigger 普通=有参 start() a =  "<<  a  << endl;
    }

    Pigger(const Pigger &p){ //拷贝构造函数
        cout << " Pigger =拷贝构造函数 start()   "  << endl;
        age = p.age;//将别人的身上的属性拷贝到自己身上
    }

    ~Pigger(){// 栈区--析构函数
        cout << " Pigger = end() "  << endl;
    }

private:
    int age;
};

void pigger_test01(){//构造函数和析构函数 都是必须有的，
    // 如果自己不提供，则编译器则会自动提供空实现的构造函数和析构函数
    Pigger pigger;//默认构造函数的调用，不要加（）
    // Pigger pigger();//默认是函数的声明


    //    1）使用一个已经创建的对象来初始化一个对象
    Pigger pigger2(10); //有参构造-括号法
    Pigger pigger3(pigger2); //有参构造-括号法 拷贝

    /**
     * 显示法
     */
    Pigger pigger11;
    Pigger pigger12 = Pigger(10);
    Pigger pigger13 = Pigger(pigger12);

    Pigger(10);//匿名对象：当程序运行结束后 系统会立即回收掉
    //    Pigger(pigger12);//不用拷贝构造函数 匿名对象初始化
    //    重定向（编译器）Pigger pigger13 = Pigger(pigger12); 认为是对象初始化


    /**
     * 隐士转换法
     */
    Pigger p4 = 10;
    Pigger p5 = p4;

   /* Pigger 普通=无参 start()
    Pigger 普通=有参 start() a =  10
    Pigger =拷贝构造函数 start()
    Pigger 普通=无参 start()
    Pigger 普通=有参 start() a =  10
    Pigger =拷贝构造函数 start()
    Pigger 普通=有参 start() a =  10
    Pigger = end()
    Pigger 普通=有参 start() a =  10
    Pigger =拷贝构造函数 start()
    Pigger = end()
    Pigger = end()
    Pigger = end()
    Pigger = end()
    Pigger = end()
    Pigger = end()
    Pigger = end()
    Pigger = end()*/

}

/**
 * 2）值传递的方式给函数传值
 */
void doWork(Pigger p){
    cout << " doWork(Pigger p) "  << endl;
}

//3）以值方式返回局部对象
Pigger doWork2(){
    cout << " doWork(Pigger p) "  << endl;
    Pigger p;

    return  p;
}

void pigger_test02(){

    Pigger p;
    doWork(p);

}

void pigger_test03(){

    Pigger p =  doWork2();

    //p和doWork2()不是同一个对象，他们的内存空间不同
}


int main111(){
    pigger_test01();
    pigger_test02();
    pigger_test03();
    return  0;
}

class  Pigger1{


    Pigger1(int a){

    }

    //result：调用无参构造和拷贝构造会报错

};
class  Pigger2{

    //result：调用无参构造和拷贝构造不会报错,提供无参构造，默认提供拷贝构造

};
class  Pigger3{

    Pigger3(){

    }
    //result：调用无参构造和拷贝构造不会报错
    Pigger3(const Pigger &p){

    }
};
class  Pigger4{

    //result：如果用户定义有拷贝构造函数，C++不在默认提供其他构造函数
    Pigger4(const Pigger &p){

    }
};