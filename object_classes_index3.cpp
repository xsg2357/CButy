//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
using namespace std;
class  Pigger{
public:

    Pigger(){ //ջ��--���캯��
        cout << " Pigger ��ͨ=�޲� start() "  << endl;
    }

    Pigger(int a){
        cout << " Pigger ��ͨ=�в� start() a =  "<<  a  << endl;
    }

    Pigger(const Pigger &p){ //�������캯��
        cout << " Pigger =�������캯�� start()   "  << endl;
        age = p.age;//�����˵����ϵ����Կ������Լ�����
    }

    ~Pigger(){// ջ��--��������
        cout << " Pigger = end() "  << endl;
    }

private:
    int age;
};

void pigger_test01(){//���캯������������ ���Ǳ����еģ�
    // ����Լ����ṩ�������������Զ��ṩ��ʵ�ֵĹ��캯������������
    Pigger pigger;//Ĭ�Ϲ��캯���ĵ��ã���Ҫ�ӣ���
    // Pigger pigger();//Ĭ���Ǻ���������


    //    1��ʹ��һ���Ѿ������Ķ�������ʼ��һ������
    Pigger pigger2(10); //�вι���-���ŷ�
    Pigger pigger3(pigger2); //�вι���-���ŷ� ����

    /**
     * ��ʾ��
     */
    Pigger pigger11;
    Pigger pigger12 = Pigger(10);
    Pigger pigger13 = Pigger(pigger12);

    Pigger(10);//�������󣺵��������н����� ϵͳ���������յ�
    //    Pigger(pigger12);//���ÿ������캯�� ���������ʼ��
    //    �ض��򣨱�������Pigger pigger13 = Pigger(pigger12); ��Ϊ�Ƕ����ʼ��


    /**
     * ��ʿת����
     */
    Pigger p4 = 10;
    Pigger p5 = p4;

   /* Pigger ��ͨ=�޲� start()
    Pigger ��ͨ=�в� start() a =  10
    Pigger =�������캯�� start()
    Pigger ��ͨ=�޲� start()
    Pigger ��ͨ=�в� start() a =  10
    Pigger =�������캯�� start()
    Pigger ��ͨ=�в� start() a =  10
    Pigger = end()
    Pigger ��ͨ=�в� start() a =  10
    Pigger =�������캯�� start()
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
 * 2��ֵ���ݵķ�ʽ��������ֵ
 */
void doWork(Pigger p){
    cout << " doWork(Pigger p) "  << endl;
}

//3����ֵ��ʽ���ؾֲ�����
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

    //p��doWork2()����ͬһ���������ǵ��ڴ�ռ䲻ͬ
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

    //result�������޲ι���Ϳ�������ᱨ��

};
class  Pigger2{

    //result�������޲ι���Ϳ������첻�ᱨ��,�ṩ�޲ι��죬Ĭ���ṩ��������

};
class  Pigger3{

    Pigger3(){

    }
    //result�������޲ι���Ϳ������첻�ᱨ��
    Pigger3(const Pigger &p){

    }
};
class  Pigger4{

    //result������û������п������캯����C++����Ĭ���ṩ�������캯��
    Pigger4(const Pigger &p){

    }
};