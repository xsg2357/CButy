//
// Created by Administrator on 2019/9/19.
//
#include <iostream>
#include <ctime>

using namespace std;

/**
 * while 循环 语法：while(条件){ 执行语法}
 * 只要循环的结果为真，就会执行循环
 */
int main41() {
    //输出 0 - 9
    int num = 0;
    while (num < 10) {
        cout << " num = " << num << endl;
        num++;
        //注意：不要写死循环
    }
    return 0;
}

int main42() {
    //添加随机数种子 利用时间 防止每次都一样
    srand((unsigned int) time(NULL));


    //生成随机数 1 - 100
    int num = rand() % 100 + 1;

    //玩家输入数据，进行猜测
    int val = 0;
    while (1) {
        cout << " 玩家开始猜测 " << endl;
        cin >> val;
        if (val > num) {
            cout << " 猜测过大 " << endl;
        } else if (val < num) {
            cout << " 猜测过小 " << endl;
        } else {
            cout << " 猜对了 " << endl;
            //退出游戏
            break;//该关键字可以退出循环
        }
    }

    return 0;
}

/**
 * do...while循环语句 句法：do{...to do..}while(条件);
 * 区别：与while的区别在于do_while语句先执行一次循环语句 在判断循环条件
 */
int main43() {

    int num = 0;
//
//    do{
//        cout << " num = " << num << endl;
//        num++;
//    }while (num < 10);
    do {
        cout << " num = " << num << endl;
        num++;
    } while (num);//会是死循环

//    while (num) {//里面的代码不会执行
//        cout << " num = " << num << endl;
//        num++;
//    }

    return 0;
}

/**
 * 水仙花数  eg：1^3 +5^3 +3^3  = 153
 */
int main44(){

    //先打印三位数字
    int num = 100;
    do{

        //从所有数字中找到三位水仙花数
        int a = 0;//各位
        int b = 0;//十位
        int c = 0;//百位

        a = num % 10;
        b = num /10  % 10;
        c = num / 100;

        if (a * a *a +b * b *b +c * c *c == num){
            cout << " num = " << num << endl;
            /*num = 153
            num = 370
            num = 371
            num = 407*/
        }

        num ++;
    }while (num < 1000);


    return  0;
}

/**
 * for循环 语法：for（数据类型 变量：变量 < 长度；变量++；）{执行语句}
 * 常用 结构清洗
 */
int main45(){

//    int i = 0;
//    for (;;){
//        if ( i >10){
//            break;
//        }
//        cout << " i = " << i << endl;
//        i++;
//    }


    for (int i = 0; i < 10; i++) {
        cout << " i = " << i << endl;
    }

    return 0;
}

/**
 * 敲桌子 7的倍数；个位是7；百位是7； 十位是7
 */
int main46(){

    for (int i = 1; i <= 100 ; i++) {

        if( i % 7 == 0 || i % 10 == 7 || i / 10 == 7){
            cout << " 敲桌子 = " << i << endl;
        }

    }

    return  0;
}

/**
 * 嵌套循环 打印星图
 */
int main47(){

    for (int j = 0; j <10 ; ++j) {//外循环控制语句

        for (int i = 0; i < 10; ++i) {//内循环控制语句
            cout << "* ";//内循环语句
        }

        cout << endl;//外循环语句
    }

    return  0;
}

/**
 * 嵌套循环 打印乘法表
 */
int main48(){

    for (int i = 1; i <= 9 ; ++i) {

        for (int j = 1; j <= i ; ++j) {

            cout << j << " * " << i << " = " << ( j * i) << " ";//外循环语句

        }
        cout << endl;//外循环语句
    }
    
    return  0;
}