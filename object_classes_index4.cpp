//
// Created by Administrator on 2019/9/27.
//

#include <iostream>
using namespace std;
class  Piger{
public:

    Piger(){ //ջ��--���캯��
        cout << " Piger ��ͨ=�޲� start() "  << endl;
    }

    Piger(int a,int height){
        cout << " Piger ��ͨ=�в� start() a =  "<<  a  << endl;
        age = a;
        _height = new int (height); //���������ڴ�ռ�
    }


    Piger(const Piger &p){ //�Լ�ʵ�ֿ������캯�������ǳ��������������
        cout << " Piger =�������캯�� start()   "  << endl;
        age = p.age;//�����˵����ϵ����Կ������Լ�����

    //        _height = p._height; ������Ĭ��ʵ��������
    //������� ���������ڴ�ռ�
        _height = new int(*p._height);
    }

    ~Piger(){// ջ��--��������
        //�������룬�����������������ͷŵĲ���
        //ǳ������������������ظ��ͷ�
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

    //    Piger ��ͨ=�в� start() a =  18
    //    Piger1 =   18height==160
    //    Piger =�������캯�� start()
    //    Piger2 =   18height==160
    //    Piger = end()
    //    Piger = end()

}

/**
 * ����������ڶ������ٵģ�һ��Ҫ�Լ�ʵ�ֿ�����������ֹǳ��������������
 */
int main112(){

    Piger_test01();

    return 0;
}

/**
 * C++�ṩ�˳�ʼ���б��﷨
 * �﷨�����캯������������1��ֵ1��,����2��ֵ2��,������{}
 */
class  Pig{


public:

    /*Pig(int a,int b,int c){ //��ͳ��ʼ������
        _a = a;
        _b = b;
        _c = c;
    }*/

    //��ʼ���б����
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
