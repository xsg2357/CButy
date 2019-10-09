#pragma once //防止头文件重复包含

# include <iostream>
#include <string>

using namespace std;

template <class  T>
class  MyArrayTemplate{
public:
    MyArrayTemplate(int capacity){
        cout << "constructor"  << endl;
        this->_capacity = capacity;
        this->_size = 0;
        this->pAddress =new T[this->_capacity];
    }

    MyArrayTemplate(const MyArrayTemplate &myArrayTemplate){//拷贝构造
        cout << "copy constructor"  << endl;
        this->_capacity = myArrayTemplate._capacity;
        this->_size = myArrayTemplate._size;
//        this->pAddress = myArrayTemplate.pAddress;

        this->pAddress = new T[myArrayTemplate._capacity];
        for (int i = 0; i <this->_size ; ++i) {
            this->pAddress[i] = myArrayTemplate.pAddress[i];
        }
    }

    void pushBack(const T &val){
        if (this->_capacity == this->_size){
            return;
        }
        this->pAddress[this->_size] = val; //数组末尾插入数据
        this->_size ++;//更新数组大小
    }

    void popBack(){//让用户访问不到最后一个数据，尾删法
        if(this->_size == 0){
            return;
        }
        this->_size -- ;
    }

    //通过数组下标访问
    T operator[](int index){

        return  this->pAddress[index];
    }


    int  getCapacity(){
        return  this->_capacity;
    }

    int getSize(){
        return  this->_size;
    }


    MyArrayTemplate &operator=(const MyArrayTemplate&myArrayTemplate){//有数据 先释放 在深度拷贝
        if (this->pAddress != NULL){
            cout << "operator constructor"  << endl;
            delete[] this->pAddress;
            this->pAddress == NULL;
            this->_size = 0;
            this->_capacity = 0;
        }

        this->_capacity = myArrayTemplate._capacity;
        this->_size = myArrayTemplate._size;
        this->pAddress = new T[myArrayTemplate._capacity];
        for (int i = 0; i <this->_size ; ++i) {
            this->pAddress[i] = myArrayTemplate.pAddress[i];
        }

        return  *this;//返回自身
    }


    ~MyArrayTemplate(){
        cout << "~ constructor"  << endl;
        if (this->pAddress != NULL){
            delete[] this->pAddress;
            this->pAddress == NULL;
        }
    }

private:
    T *pAddress;
    int _capacity;
    int _size;
};