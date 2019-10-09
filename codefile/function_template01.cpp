//
// Created by Administrator on 2019/10/9.
//

#include <iostream>
#include <string>

using namespace std;

template<class T>

void mySwap02(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
//模板必须确定出T的数据类型，才可以使用
void myTestTemplate01() {
    cout << " c = " << "myTestTemplate01" << endl;
}

/**
 * 泛型排序
 */
template<class T>
void mySort01(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        if (max != i) {
            mySwap02(arr[max], arr[i]);
        }
    }
}

/**
 * 泛型打印
 */
template<class T>
void mySortPrint01(T arr[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void myTestSwap02() {
    int a = 10;
    int b = 20;
    string e = "10";
    mySwap02(a, b);//自动类型推导
//    mySwap02(a,e);//自动类型推导  必须推导出一致的数据类型T，才可以使用 error
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;

    string c = "10";
    double d = 20;
//    mySwap02<double>(c,d);//显示类型推导 必须推导出一致的数据类型T，才可以使用 error
    cout << " c = " << c << endl;
    cout << " d = " << d << endl;
}

void myTestSwap03() {
    char charArr[] = "abdcfe";
    mySort01(charArr, sizeof(charArr) / sizeof(char));
    mySortPrint01(charArr, sizeof(charArr) / sizeof(char));
}

void myTestSwap04() {
    int charArr[] = {1, 3, 5, 7, 4, 2, 6};
    mySort01(charArr, sizeof(charArr) / sizeof(int));
    mySortPrint01(charArr, sizeof(charArr) / sizeof(int));
}


int main141() {
    myTestSwap02();
//    myTestTemplate01(); error
    myTestTemplate01<int>(); //myTestTemplate01
    return 0;
}


/**
 * 函数模板eg：数组排序
 */
int main142() {
    myTestSwap03();
    myTestSwap04();
//    f e d c b a
//    7 6 5 4 3 2 1
    return 0;
}

int myAdd01(int a, int b) {

    return a + b;
}

template<class T>
int myAdd02(T a, T b) {

    return a + b;
}

int main143() {

    int a = 10;
    int b = 20;
    char c = 'c'; // char a->97 c->99

    cout << myAdd01(a, b) << endl;// 30
    cout << myAdd01(a, c) << endl;// 109
    cout << myAdd02(a, b) << endl;// 30
//    cout << myAdd02(a,c) << endl;//  error 函数模板调用时，如果利用自动类型推导，不会发生隐士类型转换

    cout << myAdd02<int>(a, c) << endl;// 109 如果利用显示指定类型的方式，可以发生隐士类型转换
    return 0;
}

void myPrint01(int a, int b) {
    cout << " c = " << "myPrint01" << endl;
}

template<class T>
void myPrint01(T a, T b) {
    cout << " c = " << "myPrint01 template" << endl;
}

void myPrint02(int a, int b);

//void myPrint02(int a, int b){
//    cout << " c = " << "myPrint01" << endl;
//}
template<class T>
void myPrint02(T a, T b) {
    cout << " c = " << "myPrint02 template" << endl;
}

template<class T>
void myPrint02(T a, T b, T c) {
    cout << " c = " << "myPrint02 template abc" << endl;
}

/**
 * 普通函数和函数模板的调用规则：
            1.如果函数模板和普通函数都可以实现，优先调用普通函数
            2.可以通过空模板参数列表来强制调用函数模板
            3.函数模板也可以发生重载
            4.如果函数模板可以产生更好的匹配，优先调用模板函数
 */
int main144() {
    int a = 10;
    int b = 20;
    myPrint01(a, b);
    myPrint02<>(a, b);
    myPrint02<>(a, b, 30);

    char c = 'a';
    char d = 'b';
    myPrint01(c, d);

//    c = myPrint01
//    c = myPrint02 template
//    c = myPrint02 template abc
//    c = myPrint01 template
    return 0;
}




class ComparePerson{
public:

    ComparePerson(const string &name, int age) : _name(name), _age(age) {}

    string _name;
    int _age;
};

template<class T>
bool myCompareData01(T &a, T &b) {
    return a == b;
}

/**
 * 利用具体化的模板，可以解决自定义数据类型的通用化
 */
template<>  bool myCompareData01(ComparePerson &a, ComparePerson &b) {

    return  a._name == b._name && a._age == b._age;
}


void testMyCompareData01(){
    int a = 10;
    int b = 20;
    cout << " a = b ==> " << myCompareData01(a,b) << endl;

    ComparePerson p1("zhangsan",10);
    ComparePerson p2("zhangsan",10);
    cout << " a = b ==> " << myCompareData01(p1,p2) << endl;

//    a = b ==> 0
//    a = b ==> 1


}

/**
 * 学习模板并不是为了写模板，而是在STL能工运用系统提供的模板
 */
int main145(){
    testMyCompareData01();
    return  0;
}