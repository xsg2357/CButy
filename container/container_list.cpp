//
// Created by Administrator on 2019/10/18.
//
# include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;


void printListValue(const list<int> &listValue){
    for (list<int>::const_iterator it =listValue.begin();it !=listValue.end();it++) {
        cout << *it << " ";
    }
    cout << endl;
}

/**
 * list构造函数
 * STL中List和vector是两个最常被使用的容器，各有优缺点
    功能描述：
        创建list容器
    函数原型：
        list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
        list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
        list(n,elem); //构造函数将n个elem拷贝给本身。
        list(const list &lst); //拷贝构造函数。
 */
void listTest001(){

    list<int> lt1;
    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);

    printListValue(lt1);


    list<int> lt2(lt1.begin(),lt1.end());
    printListValue(lt2);

    list<int> lt3(lt2);
    printListValue(lt3);

    list<int> lt4(10,1000);
    printListValue(lt4);
//
//    10 20 30 40
//    10 20 30 40
//    10 20 30 40
//    1000 1000 1000 1000 1000 1000 1000 1000 1000 1000
}

/**
 * ist 赋值和交换
    功能描述：
        给list容器进行赋值，以及交换list容器
    函数原型：
        assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
        assign(n, elem); //将n个elem拷贝赋值给本身。
        list& operator=(const list &lst); //重载等号操作符
        swap(lst); //将lst与本身的元素互换。
 */
void listTest002(){
    list<int> lt1;
    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);

    printListValue(lt1);

    list<int> lt2;
    lt2 = lt1;
    printListValue(lt2);

    list<int> lt3;
    lt3.assign(lt2.begin(),lt2.end());
    printListValue(lt3);

    list<int> lt4;
    lt4.assign(10,1000);
    printListValue(lt4);

    //交换
    lt1.swap(lt4);
    printListValue(lt1);
    printListValue(lt4);

//    10 20 30 40
//    10 20 30 40
//    10 20 30 40
//    1000 1000 1000 1000 1000 1000 1000 1000 1000 1000

//    1000 1000 1000 1000 1000 1000 1000 1000 1000 1000
//    10 20 30 40


}

/**
 * list 大小操作
    功能描述：
        对list容器的大小进行操作
    函数原型：
        size(); //返回容器中元素的个数
        empty(); //判断容器是否为空
        resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
        ​ //如果容器变短，则末尾超出容器长度的元素被删除。
        resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
        //如果容器变短，则末尾超出容器长度的元素被删除。
 */
void listTest003(){
    list<int> lt1;
    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);

    printListValue(lt1);

    if(lt1.empty()){
        cout  << " lt1 is null" << endl;
    }else{
        cout  << " lt1 is not null" << endl;
        cout  << " lt1 size is "<< lt1.size() << endl;
    }

    //重新指定大小
    lt1.resize(10);
//    lt1.resize(10,1000);
    printListValue(lt1);


    lt1.resize(2);
    printListValue(lt1);

//    判断是否为空 --- empty
//    返回元素个数 --- size
//    重新指定个数 --- resize


//    10 20 30 40
//    lt1 is not null
//    lt1 size is 4
//    10 20 30 40 0 0 0 0 0 0
//    10 20
}

/**
 * list 插入和删除
    功能描述：
        对list容器进行数据的插入和删除
    函数原型：
        push_back(elem);//在容器尾部加入一个元素
        pop_back();//删除容器中最后一个元素
        push_front(elem);//在容器开头插入一个元素
        pop_front();//从容器开头移除第一个元素
        insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
        insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
        insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
        clear();//移除容器的所有数据
        erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
        erase(pos);//删除pos位置的数据，返回下一个数据的位置。
        remove(elem);//删除容器中所有与elem值匹配的元素。
 */
void listTest004(){

//    尾插 --- push_back
//    尾删 --- pop_back
//    头插 --- push_front
//    头删 --- pop_front
//    插入 --- insert
//    删除 --- erase
//    移除 --- remove
//    清空 --- clear


    list<int> lt1;
    //尾插
    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    //头插
    lt1.push_front(1100);
    lt1.push_front(1200);
    lt1.push_front(1300);
    lt1.push_front(1400);

    printListValue(lt1);

    //尾删法
    lt1.pop_back();
    //头删
    lt1.pop_front();
    printListValue(lt1);

    //插入
    lt1.insert(lt1.begin(),1000);
    printListValue(lt1);
    list<int>::iterator it = lt1.begin();
    lt1.insert(it++,2000);
    printListValue(lt1);

    //删除
    it = lt1.begin();
    lt1.erase(++it);
    printListValue(lt1);

    //移除
    lt1.push_back(1000);
    lt1.push_back(1000);
    printListValue(lt1);
    lt1.remove(1000);
    printListValue(lt1);

    lt1.clear();
    printListValue(lt1);

//    1400 1300 1200 1100 10 20 30 40
//    1300 1200 1100 10 20 30
//    1000 1300 1200 1100 10 20 30
//    2000 1000 1300 1200 1100 10 20 30
//    2000 1300 1200 1100 10 20 30
//    2000 1300 1200 1100 10 20 30 1000 1000
//    2000 1300 1200 1100 10 20 30

}


/**
 * list 数据存取
    功能描述：
        对list容器中数据进行存取
    函数原型：
        front(); //返回第一个元素。
        back(); //返回最后一个元素。
 */
void listTest005(){
//    list容器中不可以通过[]或者at方式访问数据
//    返回第一个元素 --- front
//    返回最后一个元素 --- back
    list<int> lt1;
    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);

    printListValue(lt1);

    //cout << L1.at(0) << endl;//错误 不支持at访问数据
    //cout << L1[0] << endl; //错误  不支持[]方式访问数据
    //list 本质链表 不适用本质连续空间存储数据，迭代器也不支持随机性访问
    cout << "first: " << lt1.front() << endl;
    cout << "end: " << lt1.back() << endl;

    list<int>::iterator it = lt1.begin();
    //it = it + 1;//错误，不可以跳跃访问，即使是+1
    ////list容器的迭代器是双向迭代器
    it++;
    it --;
//    first: 10
//    end: 40

}

bool myListCompare(int v1,int v2){

    return  v1 > v2;
}


/**
 *  list 反转和排序
    功能描述：
        将容器中的元素反转，以及将容器中的数据进行排序
    函数原型：
        reverse(); //反转链表
        sort(); //链表排序
 */
void listTest006(){
//    反转 --- reverse
//    排序 --- sort （成员函数）
    list<int> lt1;
    lt1.push_back(20);
    lt1.push_back(10);
    lt1.push_back(50);
    lt1.push_back(30);
    lt1.push_back(40);

    printListValue(lt1);

    lt1.reverse();//反转
    cout << "reverse after:" ;
    printListValue(lt1);

    //所有不支持的随即访问的迭代器，不可以用标准算法
//    sort(lt1.begin(),lt1.end());
    lt1.sort();//默认排序规则：从小到大 升序
    cout << "sort after:" ;
    printListValue(lt1);

    lt1.sort(myListCompare);//自定义降序排列
    cout << "sort after:" ;
    printListValue(lt1);
//    20 10 50 30 40
//    reverse after:40 30 50 10 20
//    sort after:10 20 30 40 50
//    sort after:50 40 30 20 10
}

/**
 * 案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
    排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
 */
class  ListPerson{

public:

    ListPerson(const string &name, int age, int height) : _name(name), _age(age), _height(height) {}

    string _name;
    int _age;
    int _height;

};

bool myListPersonCompare(ListPerson &v1,ListPerson &v2){

    if (v1._age  == v2._age){

        return  v1._height > v2._height;
    }else{

        return  v1._age < v2._age;
    }

}


/**
 * 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
    高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
 */
void listTest007(){

    list<ListPerson> lp1;

    ListPerson p1("zhang san",100,20);
    ListPerson p2("zhang san1",30,40);
    ListPerson p3("zhang san2",50,20);
    ListPerson p4("zhang san3",20,30);
    ListPerson p5("zhang san4",40,20);
    ListPerson p6("zhang san5",10,10);

    lp1.push_back(p1);
    lp1.push_back(p2);
    lp1.push_back(p3);
    lp1.push_back(p4);
    lp1.push_back(p5);
    lp1.push_back(p6);

//    for (list<ListPerson>::iterator it = lp1.begin(); it != lp1.end(); it++) {
    for (auto it = lp1.begin(); it != lp1.end(); it++) {
        cout << "name: " << it->_name << " age: " << it->_age
             << "height:"
                " " << it->_height << endl;
    }

    cout << "---------------------------------" << endl;
    lp1.sort(myListPersonCompare);
    for (auto & it : lp1) {
        cout << "name: " << it._name << " age: " << it._age
             << "height:"
                " " << it._height << endl;
    }

//    name: zhang san age: 100height: 20
//    name: zhang san1 age: 30height: 40
//    name: zhang san2 age: 50height: 20
//    name: zhang san3 age: 20height: 30
//    name: zhang san4 age: 40height: 20
//    name: zhang san5 age: 10height: 10
//    ---------------------------------
//    name: zhang san5 age: 10height: 10
//    name: zhang san3 age: 20height: 30
//    name: zhang san1 age: 30height: 40
//    name: zhang san4 age: 40height: 20
//    name: zhang san2 age: 50height: 20
//    name: zhang san age: 100height: 20

}

int main157(){
//    listTest001();
//    listTest002();
//    listTest003();
//    listTest004();
//    listTest005();
//    listTest006();
    listTest007();
    return  0;
}
