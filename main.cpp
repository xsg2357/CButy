#include <iostream>
#include <string>

# define Day 7 //常量定义1

using  namespace std;

int main0() {
    std::cout << "Hello, World!" << std::endl;

    //变量用于管理内存空间,在给常量、变量起名的时候不得使用关键字
    //标志符：字母 数字 下划线
    //第一个字母必须是字母和下划线
    //标志符中字母区分大小写
    int a = 10;
    std::cout << "a = " << a << std::endl;
    /**
     * 定义常量 常量是不可修改的
     * 1.# define 宏常量 表达方式： # define 常量名 常量值
     * 2.const 修饰的变量 表达方式： const 变量类型 变量名 = 变量值
     */
    std::cout << "一周有" << Day << "天" << std::endl; //输出常量 define

    const  int  month = 30; //常量定义2
    std::cout << "一月有" << month << "天" << std::endl;

    system("pause"); // 请按任意键继续. . .

    return 0;
}

int main1(){


    //1.短整型 -32768 ~ 32767 2字节
    short num1 = 10;
    //2.整型  4 字节
    int num2 = 10;
    //3.长整型 4字节 Linux 8字节
    long num3 = 10;
    //4.长长整型 8字节
    long long num4 = 10;

    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    std::cout << "num3 = " << num3 << std::endl;
    std::cout << "num4 = " << num4 << std::endl;

    system("pause"); // 请按任意键继续

    /**
     * sizeof 关键字可以统计数据类型所占内存大小
     * 语法：sizeof(数据类型/变量)
     *      short sizeof = 2
            int sizeof = 4
            long sizeof = 4
            long  long sizeof = 8
            总结： short < int <= long <= long long
     */
    std::cout << "short sizeof = " << sizeof(short) << std::endl;
    std::cout << "int sizeof = " << sizeof(int) << std::endl;
    std::cout << "long sizeof = " << sizeof(long) << std::endl;
    std::cout << "long  long sizeof = " << sizeof(long long) << std::endl;

    return  0;
}

int main2(){
    //实型（浮点型） 单精度float和双精度double 默认显示6位有效数字
    //float 4 字节 7位有效数字 ；double 8 字节 15~16位有效数字
    float f1 = 3.1415926f;
    std::cout << "f1 = " << f1 << std::endl;

    double  d1 = 3.1415926;
    std::cout << "d1 = " << d1 << std::endl;

    //统计内存空间
    std::cout << "float sizeof = " << sizeof(float) << std::endl;
    std::cout << "double sizeof = " << sizeof(double) << std::endl;

    //科学计数法
    float f2 = 3e2; //3 * 10~2
    std::cout << "f2 = " << f2 << std::endl; //300
    float f3 = 3e-2; //3 * 0.1 ~ 2
    std::cout << "f3 = " << f3 << std::endl; // 0.03

    return  0;
}

int main3(){
    //字符型用于单个字符 char c = 'c'
    //显示字符变量时，用单引号括起来，不能用双引号 ； 单引号只能用一个字符，不能是多个字符
    //c和C++中站1个字节，不能放到内存中存储，而是把对应的ASCII编码放到内存中

    char c = 'a';
    std::cout << "c = " << c << std::endl;
    std::cout << "char sizeof = " << sizeof(char) << std::endl;
    std::cout << "char sizeof = " << int(c) << std::endl; //97 A--> 65

    return  0;
}

int main4(){
    //转义字符：\a 警报 \b 退格 \f 换页  \n 换行 \r 回车  \t水平制表
    //\v 垂直制表  \\代表一个反斜杠“\” \' 代表一个单引号  等
    std::cout << "ccc\acccccc" << std::endl;
    std::cout << "ccc\bcccccc" << std::endl;
    std::cout << "ccc\fcccccc" << std::endl;
    std::cout << "ccc\ncccccc" << std::endl;
    std::cout << "ccc\rcccccc" << std::endl;
    std::cout << "ccc\tcccccc" << std::endl;
    std::cout << "ccc\vcccccc" << std::endl;
    std::cout << "ccc\\cccccc" << std::endl;
    std::cout << "ccc\'cccccc" << std::endl;
    std::cout << "ccc\"cccccc" << std::endl;
    std::cout << "ccc\?cccccc" << std::endl;

    return 0;
}

int main5(){
    //字符串：用于表示一串字符
    //1.C风格 不能用单引号 要用双引号
    char str1[] = "abcde";
    std::cout << "str1 ==" << str1 << std::endl;

    //2.C++风格 需要加入头文件#include <string>
    string str2 = "Hello World";
    std::cout << "str2 ==" << str2 << std::endl;
    return 0;
}

int main6(){
    //布尔类型 创建bool数据
    bool  flag = false;
    bool  flag1 = true;
    std::cout << "flag ==" << flag << std::endl; //0
    std::cout << "flag1 ==" << flag1 << std::endl;//1

    //查看布尔类型内存空间
    std::cout << "sizeof bool ==" << sizeof(bool) << std::endl; //1字节

    return 0;
}

int main7(){

    //    1.整型
    int a = 0;
    std::cout << "请给整型变量a赋值：" << std::endl;
    cin >> a;
    std::cout << "a ==" << a << std::endl;

    //    浮点型
    int f = 0;
    std::cout << "请给浮点型变量f赋值：" << std::endl;
    cin >> f;
    std::cout << "f ==" << f << std::endl;

    //    字符型
    char c = 'a';
    std::cout << "请给字符型变量f赋值：" << std::endl;
    cin >> c;
    std::cout << "c ==" << c << std::endl;

    //   字符串
    string str = "hello";
    std::cout << "请给字符串变量str赋值：" << std::endl;
    cin >> str;
    std::cout << "str ==" << str << std::endl;

    //   布尔值
    bool flag = false;
    std::cout << "请给布尔值变量flag赋值：" << std::endl;
    cin >> flag;
    std::cout << "flag ==" << flag << std::endl;


    return 0;
}