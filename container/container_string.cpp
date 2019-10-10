//
// Created by Administrator on 2019/10/10.
//
# include <iostream>
#include <string>

using namespace std;

/**
 * 字符串构造
 */
void testString01() {
    string s1;// 创建一个空字符串 string()

    cout << " s = " << s1 << endl;

    const char *str = "hello world"; //使用字符串初始化 使用字符串类初始化s

    string s2(str); //string(const _CharT* __s)
    cout << " s = " << s2 << endl;

    string s3(s2); //使用string初始化拧一个string string(const basic_string& __str)
    cout << " s = " << s3 << endl;

    string s4(10, 'a'); // n个字符串初识c string(size_type __n, _CharT __c）
    cout << " s = " << s4 << endl;

//    s =
//    s = hello world
//    s = hello world
//        s = aaaaaaaaaa

}

/**
 * 字符串赋值
 * string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
    string& operator=(const string &s); //把字符串s赋给当前的字符串
    string& operator=(char c); //字符赋值给当前的字符串
    string& assign(const char *s); //把字符串s赋给当前的字符串
    string& assign(const char *s, int n); //把字符串s的前n个字符赋给当前的字符串
    string& assign(const string &s); //把字符串s赋给当前字符串
    string& assign(int n, char c); //用n个字符c赋给当前字符串
 */

void testString02() {

    string string1;
    string1 = "hello world";
    cout << " s = " << string1 << endl;

    string string2;
    string2 = string1;
    cout << " s = " << string2 << endl;

    string string3;
    string3 = '2';
    cout << " s = " << string3 << endl;

    string string4;
    string4.assign("hell0 c++");
    cout << " s = " << string4 << endl;

    string string5;
    string5.assign("hell0 c++", 5);
    cout << " s = " << string5 << endl;

    string string6;
    string6.assign(string5);
    cout << " s = " << string6 << endl;

    string string7;
    string7.assign(10, 'w');
    cout << " s = " << string7 << endl;
//    s = hello world
//    s = hello world
//            s = 2
//    s = hell0 c++
//    s = hell0
//    s = hell0
//    s = wwwwwwwwww
}

/**
 * 字符串拼接
 * string& operator+=(const char* str); //重载+=操作符
    string& operator+=(const char c); //重载+=操作符
    string& operator+=(const string& str); //重载+=操作符
    string& append(const char *s); //把字符串s连接到当前字符串结尾
    string& append(const char *s, int n); //把字符串s的前n个字符连接到当前字符串结尾
    string& append(const string &s); //同operator+=(const string& str)
    string& append(const string &s, int pos, int n);//字符串s中从pos开始的n个字符连接到字符串结尾
 */
void testString03() {
    string string1 = "me";
    string1 += "play game";
    cout << " s = " << string1 << endl;

    string1 += ':';
    cout << " s = " << string1 << endl;

    string string2 = "LoL; DNF";
    string1 += string2;
    cout << " s = " << string1 << endl;

    string string3 = "i";
    string3.append(" love");
    cout << " s = " << string3 << endl;

    string3.append("game abcde ", 4);
    cout << " s = " << string3 << endl;

    string3.append(string2);
    cout << " s = " << string3 << endl;

    string3.append(string2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
    cout << " s = " << string3 << endl;

//    s = meplay game
//    s = meplay game:
//    s = meplay game:LoL; DNF
//    s = i love
//    s = i lovegame
//    s = i lovegameLoL; DNF
//    s = i lovegameLoL; DNF DN

}


/**
 * string查找和替换
    功能描述：
        查找：查找指定字符串是否存在
        替换：在指定的位置替换字符串
    函数原型：
        int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
        int find(const char* s, int pos = 0) const; //查找s第一次出现位置,从pos开始查找
        int find(const char* s, int pos, int n) const; //从pos位置查找s的前n个字符第一次位置
        int find(const char c, int pos = 0) const; //查找字符c第一次出现位置
        int rfind(const string& str, int pos = npos) const; //查找str最后一次位置,从pos开始查找
        int rfind(const char* s, int pos = npos) const; //查找s最后一次出现位置,从pos开始查找
        int rfind(const char* s, int pos, int n) const; //从pos查找s的前n个字符最后一次位置
        int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
        string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
        string& replace(int pos, int n,const char* s); //替换从pos开始的n个字符为字符串s
 */
void testString04() {

    string str1 = "abcdefgde";
    int pos = str1.find("de");

    //find找到字符串后返回查找的第一个字符位置，找不到返回-1
    if (pos == -1) {
        cout << " pos = no find " << endl;
    } else {
        cout << " pos = " << pos << endl;
    }

    pos = str1.rfind("de"); //rfind从右往左查找 find 从左往右查找
    cout << " pos = " << pos << endl;

    //replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
    str1.replace(1, 3, "1111");
    cout << " s = " << str1 << endl;
//    pos = 3
//    pos = 7
//    s = a1111efgde
}

/**
 * 字符串之间的比较
 * 字符串比较是按字符的ASCII码进行对比
 *  = 返回 0
    > 返回 1
    < 返回 -1
 *      int compare(const string &s) const; //与字符串s比较
        int compare(const char *s) const; //与字符串s比较
 */
void testString05() {
    string str1 = "hello";
    string str2 = "bello";

    //字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大
    if (str1.compare(str2) == 0) {

        cout << "str1 == str2" << endl;
    } else if (str1.compare(str2) > 0) {  //1
        cout << "str1 > str2" << endl;
    } else {// -1
        cout << "str1 <>> str2" << endl;
    }

//    str1 > str2
}

/**
 * 字符串的存取
 *string中单个字符存取方式有两种
        char& operator[](int n); //通过[]方式取字符
        char& at(int n); //通过at方法获取字符
 */
void testString06() {
    string str = "hello world";
    //通过[]方式取字符
    for (int i = 0; i <str.size() ; ++i) {
        cout << str[i] << " ";
    }
    cout << endl;
    //通过at方法获取字符
    for (int i = 0; i <str.size() ; ++i) {
        cout << str.at(i) << " ";
    }
    cout << endl;

    //修改单个字符
    str[0] = 'x';
    cout << " s = " << str << endl;
    str.at(1) = 'x';
    cout << " s = " << str << endl;

//    h e l l o   w o r l d
//    h e l l o   w o r l d
//    s = xello world
//    s = xxllo world

}


/**
 * string插入和删除
 * 功能描述：
    对string字符串进行插入和删除字符操作
    函数原型：
        string& insert(int pos, const char* s); //插入字符串
        string& insert(int pos, const string& str); //插入字符串
        string& insert(int pos, int n, char c); //在指定位置插入n个字符c
        string& erase(int pos, int n = npos); //删除从Pos开始的n个字符
 */
void testString07() {
    string str = "hello";
    str.insert(1,"111");
    cout << " s = " << str << endl;

    // 插入和删除的起始下标都是从0开始
    str.erase(1,3);
    cout << " s = " << str << endl;
//    s = h111ello
//    s = hello
}

/**
 * string 子串获取
 * string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串
 */
void testString08() {
    string str = "abcdefg";
    string subStr = str.substr(1,3);
    cout << " s = " << subStr << endl;

    string email = "hello@sina.com";
    int pos = email.find("@");
    string name = email.substr(0,pos);
    // 灵活的运用求子串功能，可以在实际开发中获取有效的信息
    cout << " s = " << name << endl;
//    s = bcd
//    s = hello
}


/**
 * string 是C++风格的字符串 本质是一个类
 * char* 是一个指针
 * string是一个类 内部封装了char* 管理这个字符串 是char*的容器
 * string管理char*分配的内存 不用担心复制越界和取值越界等 由类内部进行负责
 *
 */
int main151() {
//    testString01();
//    testString02();
//    testString03();
//    testString04();
//    testString05();
//    testString06();
//    testString07();
    testString08();

    return 0;
};
