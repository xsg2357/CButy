//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
using namespace std;
class  Piger{
public:

    Piger(){ //栈区--构造函数
        cout << " Piger 普通=无参 start() "  << endl;
    }

    Piger(int a,int height){
        cout << " Piger 普通=有参 start() a =  "<<  a  << endl;
        age = a;
        _height = new int (height); //重新申请内存空间
    }


    Piger(const Piger &p){ //自己实现拷贝构造函数，解决浅拷贝带来的问题
        cout << " Piger =拷贝构造函数 start()   "  << endl;
        age = p.age;//将别人的身上的属性拷贝到自己身上

    //        _height = p._height; 编译器默认实现这句代码
    //深拷贝操作 重新申请内存空间
        _height = new int(*p._height);
    }

    ~Piger(){// 栈区--析构函数
        //析构代码，将堆区开辟数据做释放的操作
        //浅拷贝带来的问题就是重复释放
        if(_height != NULL){
            delete _height;
            _height = NULL;
        }
        cout << " Piger = end() "  << endl;
    }

public:
    int age;
    int * _height;
};

void Piger_test01(){

    Piger p(18,160);
    cout << " Piger1 =   " << p.age << "height=="<< *p._height << endl;
    Piger p2(p);
    cout << " Piger2 =   "  << p2.age << "height==" <<  *p2._height<< endl;

    //    Piger 普通=有参 start() a =  18
    //    Piger1 =   18height==160
    //    Piger =拷贝构造函数 start()
    //    Piger2 =   18height==160
    //    Piger = end()
    //    Piger = end()

}

/**
 * 如果有属性在堆区开辟的，一定要自己实现拷贝函数，防止浅拷贝带来的问题
 */
int main112(){

    Piger_test01();

    return 0;
}

/**
 * C++提供了初始化列表语法
 * 语法：构造函数（）：属性1（值1）,属性2（值2）,。。。{}
 */
class  Pig{


public:

    /*Pig(int a,int b,int c){ //传统初始化操作
        _a = a;
        _b = b;
        _c = c;
    }*/

    //初始胡列表操作
    Pig(int a,int b,int c):_a(a),_b(b),_c(c){

    }

    int _a;
    int _b;
    int _c;


};

void Pig_test01(){

    Pig pig(30,20,10);
    cout << " Pig.a  " << pig._a << endl;
    cout << " Pig.b  " << pig._b << endl;
    cout << " Pig.c  " << pig._c << endl;

    /*Pig.a  30
    Pig.b  20
    Pig.c  10*/

}

int main113(){
    Pig_test01();
    return  0;
}
