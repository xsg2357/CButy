//
// Created by Administrator on 2019/10/21.
//

# include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/**
 * 仿函数
 */
//函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class FunctionObjectAdd{
public:
    int operator()(int v1,int v2){

        return v1+v2;
    }
};


//        函数对象超出普通函数的概念，函数对象可以有自己的状态
class FunctionObjectPrint{
public:

    FunctionObjectPrint(){
        this->_count = 0;
    }

    void  operator()(string test){
        cout << test << endl;
        this->_count ++;
    }

    int _count;
};

void  myTestFunctionObject001(){
    FunctionObjectAdd functionObjectAdd;
    cout << functionObjectAdd(10,20) << endl; //30

}
void  myTestFunctionObject002(){
    FunctionObjectPrint functionObjectPrint;
    functionObjectPrint("hello");
    functionObjectPrint("hello");
    functionObjectPrint("count");
    cout <<     functionObjectPrint._count << endl;
//    hello
//            hello
//    count
//    3

}

//仿函数写法非常灵活，可以作为参数进行传递。
void deFunctionObjectPrint(FunctionObjectPrint &functionObjectPrint,string test){
    functionObjectPrint(test);
}

void  myTestFunctionObject003(){
    FunctionObjectPrint functionObjectPrint;
    deFunctionObjectPrint(functionObjectPrint,"nihao");
    deFunctionObjectPrint(functionObjectPrint,"nihao1");
//          nihao
//            nihao1
}

int main160(){
    myTestFunctionObject001();
    myTestFunctionObject002();
    myTestFunctionObject003();
    return 0;
}

//参数只有一个的谓词，称为一元谓词
struct  GreatOneElement{
    bool  operator()(int val){

        return  val >5;
    }
};


void test_one_element(){
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int> :: iterator it = find_if(v.begin(),v.end(),GreatOneElement());
    if (it == v.end()){

        cout << " find_if is not" << endl;
    }else{
        cout << " find_if is " << * it << endl;

    }

//    find_if is 6
}


//参数只有两个的谓词，称为二元谓词
class  MyTestTwoElement{
public:
    bool  operator()(int v1,int v2){

        return  v1 > v2;
    }
};


void test_two_element(){

    vector<int> v;
    v.push_back(10);
    v.push_back(40);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);

    sort(v.begin(),v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "----------------------------" << endl;
    //使用函数对象改变算法策略，排序从大到小
    sort(v.begin(),v.end(),MyTestTwoElement());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
//    10 20 30 40 50
//    ----------------------------
//    50 40 30 20 10
}

int  main161(){
    test_one_element();
    test_two_element();
    return  0;
}