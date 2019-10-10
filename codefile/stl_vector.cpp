//
// Created by Administrator on 2019/10/10.
//
# include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class VectorPerson{

public:

    VectorPerson(string mName, int mAge) : _mName(mName), _mAge(mAge) {}

    string _mName;
    int _mAge;

};

/**
 * 容器嵌套自定义数据类型
 */
void testVectorPerson01(){

    vector<VectorPerson> v ;

    for (int i = 0; i < 5; ++i) {
        string name = &"name_"[i];
        VectorPerson p(name,i*10);
        v.push_back(p);
    }
    for (vector<VectorPerson>::iterator it = v.begin() ;it!= v.end(); it++) {
        cout << "name:" <<  (*it)._mName << ",age:" <<  (*it)._mAge << endl;
    }

    /*name:name_,age:0
    name:ame_,age:10
    name:me_,age:20
    name:e_,age:30
    name:_,age:40*/
}

/**
 * 容器嵌套自定义数据类型指针
 */
void testVectorPerson02(){

    vector<VectorPerson*> v ;

    string namea[5] = {"aaa","aaa1","aaa2","aaa3","aaa4"};

    for (int i = 0; i < 5; i++) {
        string  name = namea[i];
        VectorPerson p(name,(i+1)*10);
        v.push_back(&p);
    }
    cout << "name:" << v.size()  << endl;

    for (vector<VectorPerson*>::iterator it = v.begin(); it != v.end(); it++) {
        VectorPerson * p = (*it);
        cout << "Name:" << p->_mName << " Age:" << (*it)->_mAge << endl;
    }

    /*Name:aaa4 Age:50
    Name:aaa4 Age:50
    Name:aaa4 Age:50
    Name:aaa4 Age:50
    Name:aaa4 Age:50*/
}


void MyPrintVector(int val)
{
    cout << val << " ";
}


void testVector01(){

    //创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型,头文件vector
    vector<int> vector1;

    //向容器中存放数据
    vector1.push_back(10);
    vector1.push_back(20);
    vector1.push_back(40);
    vector1.push_back(30);
    vector1.push_back(50);

    //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
    //v.begin()返回迭代器，这个迭代器指向容器中第一个数据
    //v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
    //vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
    vector<int>::iterator start = vector1.begin();
    vector<int>::iterator end = vector1.end();

    //第一种遍历方式：
    while (start != end) {
        cout << *start << " ";
        start++;
    }

    cout <<  endl;

    //第2种遍历方式：
    for (vector<int>::iterator it = vector1.begin() ;it!= vector1.end(); it++) {
        cout << *it << "  ";
    }
    cout <<  endl;

    //第3种遍历方式：
    //使用STL提供标准遍历算法  头文件 algorithm
    for_each(vector1.begin(),vector1.end(),MyPrintVector);

    /*10 20 40 30 50
    10  20  40  30  50
    10 20 40 30 50*/

}


/**
 * 容器嵌套容器
 */
void testVector02(){
    vector< vector<int> >  v;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }

    //将小容器元素插入到大容器vector v中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);


    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {

        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
            cout << *vit << " ";
        }
        cout << endl;
    }
//    1 2 3 4
//    2 3 4 5
//    3 4 5 6
//    4 5 6 7

}


int main(){

    testVector02();
//    testVectorPerson02();
//    testVectorPerson01();
//    testVector01();

    return  0;
}