//
// Created by Administrator on 2019/10/8.
//
#include <iostream>
#include <fstream> //引入文件操作的头文件
#include <string>

using namespace std;
/**
 * 写文件
 */
void fs01(){
    ofstream ofs;//创建流对象ofstream或者fstream
    ofs.open("test.txt",ios::out);//打开指定方式
    // 利用 ofs << 泻热如内容
    ofs << "姓名：张三" << endl;
    ofs << "姓名：李四" << endl;
    ofs << "姓名：找网页" << endl;
    ofs << "姓名：刘勇" << endl;
    //关闭文件 操作完毕，关闭文件
    ofs.close();

    /*姓名：张三
    姓名：李四
    姓名：找网页
    姓名：刘勇*/

}

/**
 * 读文件1
 */
void fs02(){

    ifstream ifs;
    ifs.open("test.txt",ios::in);
    bool  is_open = ifs.is_open();//判断文件是否存在
    if(!is_open){
        cout << " file open failed " << endl;
        return;
    }
    //读文件操作
    char  buf[1024] = {0};
    while (ifs >> buf){
        cout << buf << endl;
    }
    ifs.close();
}
/**
 * 读文件2
 */
void fs03(){

    ifstream ifs;
    ifs.open("test.txt",ios::in);
    bool  is_open = ifs.is_open();//判断文件是否存在
    if(!is_open){
        cout << " file open failed " << endl;
        return;
    }
    //读文件操作
    char  buf[1024] = {0};
    while (ifs.getline(buf, sizeof(buf))  ){
        cout << buf << endl;
    }
    ifs.close();
}
/**
 * 读文件3
 */
void fs04() {

    ifstream ifs;
    ifs.open("test.txt", ios::in);
    bool is_open = ifs.is_open();//判断文件是否存在
    if (!is_open) {
        cout << " file open failed " << endl;
        return;
    }
    //读文件操作
    string buf;
    while (getline(ifs, buf)) {
        cout << buf << endl;
    }
    ifs.close();
}
/**
 * 读文件4
 */
void fs05() {

    ifstream ifs;
    ifs.open("test.txt",ios::in);
    bool  is_open = ifs.is_open();//判断文件是否存在
    if(!is_open){
        cout << " file open failed " << endl;
        return;
    }
    //读文件操作
    char c;
    while ( (c = ifs.get())  != EOF ){ //EOF 表示文件的结尾 end of file
        cout << c ;
    }
    ifs.close();
}

class  writePerson{
public:
    char _name[64];
    int _age;
};

/**
 * 二进制写文件
 */
void fs06() {

    ofstream ofs("person.txt",ios::out | ios::binary);
//    ofs.open("person.txt",ios::out | ios::binary);
    //读文件操作

    writePerson p ={"张三",24};
    ofs.write((const char *) &p, sizeof(p));

    ofs.close();
}
/**
 * 二进制读文件
 */
void fs07() {

    ifstream ifs("person.txt",ios::out | ios::binary);

    bool  is_open = ifs.is_open();//判断文件是否存在
    if(!is_open){
        cout << " file open failed " << endl;
        return;
    }

    writePerson p;
    ifs.read(( char *) &p, sizeof(p));

    cout << "name: "<<p._name<< ",age: "<< p._age << endl;


    ifs.close();
}

int main138(){

//    fs01();
//    fs02();
//    fs03();
//    fs04();
//    fs05();
//    fs06();
//    fs06();
    fs07();

    return  0;
}
