//
// Created by Administrator on 2019/9/19.
//
#include <iostream>
#include <time.h>

using  namespace std;
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

int main42(){
    //添加随机数种子 利用时间 防止每次都一样

    srand((unsigned int) time(NULL));


    //生成随机数 1 - 100
    int num = rand() % 100 +1;

    //玩家输入数据，进行猜测
    int val = 0;
    while(1){
        cout << " 玩家开始猜测 " << endl;
        cin >> val;
        if(val > num){
            cout << " 猜测过大 " << endl;
        }else if (val < num){
            cout << " 猜测过小 " << endl;
        }else{
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
int main(){

    return  0;
}