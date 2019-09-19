//
// Created by Administrator on 2019/9/19.
//
#include <iostream>

using namespace std;

int main31() {
    /**
     * 程序控制结构：
     *   1.顺序结构 程序按顺序执行 不发生跳转
     *   2.根据条件是否满足 有选择的执行相应功能
     *   3.根据条件是否满足 循环多次执行某段代码
     */

    /**
     * if 语句——满足条件的语句
     */
    //单行if 语法：if(条件){ .... to do ...}

    int score = 0;
    cout << "请输入分数：" << endl;
    cin >> score;

    //单行if 条件判断 if后面不能写分号
    if (score > 600) {
        cout << "恭喜你考上了一本大学" << endl;
    }

    //多行if 语法：if(条件){ .... to do ...}else{ ... to do ...}
    if (score > 700) {
        cout << "恭喜你好考上了重点大学" << endl;
    } else {
        cout << "恭喜你考上了一本大学" << endl;
    }


    //多条件if 语法：if(条件1){ .... to do ...} else if(条件2){ .... to do ...}....else{ ... to do ...}
    if (score > 750) {
        cout << "恭喜你好考上了重点大学" << endl;
        //嵌套 if语句 语法：if(条件1){ ..if(条件1){..to do .. }.. to do ...} else if(条件2){ .... to do ...}....else{ ... to do ...}
        if (score == 768) {
            cout << "恭喜你好考上了重点___重点大学" << endl;
        }
    }
    if (score > 800) {
        cout << "恭喜你好考上国外的大学" << endl;
    } else {
        cout << "恭喜你考上了一本大学" << endl;
    }


    return 0;

}

int main32() {
    //三只小猪称体重

    //1.定义三只小猪的体重
    int a = 0;
    int b = 0;
    int c = 0;

    cout << "请输入a的体重：" << endl;
    cin >> a;
    cout << "a的体重：" << a << endl;

    cout << "请输入b的体重：" << endl;
    cin >> b;
    cout << "b的体重：" << b << endl;

    cout << "请输入c的体重：" << endl;
    cin >> c;
    cout << "c的体重：" << c << endl;

    if (a > b) {

        if (a > c) {
            cout << "a的体重大" << endl;
        } else {
            cout << "c的体重大" << endl;
        }
    } else {
        if (b > c) {
            cout << "b的体重大" << endl;
        } else {
            cout << "c的体重大" << endl;
        }
    }


    return 0;
}

int main33() {
    //三目运算符 语法：表达式1 ？ 表达式2：表达式3
    //表达式1为真执行表达式2，为假执行表达式3

    int a = 10;
    int b = 20;
    int c = 0;

    c = a > b ? a : b;//20
    cout << "c ：" << c << endl;

    //返回的是变量，可以继续赋值

    a > b ? a : b = 100;
    cout << "a ：" << a << endl;//10
    cout << "b ：" << b << endl;//100

    return 0;
}

/**
 * switch 语句 结构清晰 执行效率高； 只能是整型和字符型； 不可以区间判断
 * 语法：
 *   switch(表达式){
 *      case 结果1：
 *         执行语句; break;
 *      case 结果2：
 *         执行语句; break;
 *      case 结果2：
 *         执行语句; break;
 *      ......
 *      default:
 *           执行语句;break;
 *   }
 */
int main34(){

    int score = 0;
    cout << "请输入电影评分：" << endl;
    cin >> score;
    switch (score){

        case 60:
        case 65:
            cout << "及格：" << endl;
            break;
        case 70:
        case 75:
            cout << "一般：" << endl;
            break;
        case 80:
        case 85:
            cout << "很好：" << endl;
            break;
        case 90:
        case 95:
            cout << "太好了：" << endl;
            break;
        default:
            cout << "差极了：" << endl;
            break;
    }

    return  0;
}