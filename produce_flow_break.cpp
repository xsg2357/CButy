//
// Created by Administrator on 2019/9/19.
//

#include <iostream>

using namespace std;


/**
 * 跳转语句——break语句
 * 使用时机：
 *        1.出现在switch语句中，终止case跳出switch
 *        2.出现在循环语句中，跳出当前循环语句
 *        3.出现在嵌套循环中，跳出内层循环语句
 *
 */
int main51(){


    //    .出现在switch语句中，终止case跳出switch
    cout << " 请选择难度 "  << endl;
    cout << " 1、困难 "  << endl;
    cout << " 2、一般 "  << endl;
    cout << " 3、简单 "  << endl;
    int sel = 0;
    cin >> sel;
    switch (sel){
        case 1:
            cout << " 1、困难 "  << endl;
            break;
        case 2:
            cout << " 2、一般 "  << endl;
            break;
        case 3:
            cout << " 3、简单 "  << endl;
            break;
        default:
            cout << " 选择错误 "  << endl;
            break;
    }

    //    .出现在循环语句中，跳出当前循环语句
    for (int i = 0; i < 10; ++i) {
        if ( i > 5){
            break;
        }
        cout << " i = "<< i  << endl;
    }

    //   3.出现在嵌套循环中，跳出内层循环语句
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10; ++i) {
            if( j ==5){
                break;
            }
            cout << "* ";//内循环语句
        }
        cout << endl;//外循环语句
    }
    
    return 0;
}

/**
 * 跳转语句——Continue语句
 * 执行到某一句，遇到continue判断 就会跳过当前循环，不执行下面的语句，继续执行下一次循环
 * break 会退出循环，continue不会退出循环
 */
int main52(){

    for (int i = 0; i <100 ; ++i) {

        if ( i % 2 == 0){//输出奇数，不输出偶数
            continue;//在此，不会执行下面的语句，继续执行下一次循环
        }
        cout << " i = "<< i  ;
    }

       /* i = 1 i = 3 i = 5 i = 7 i = 9 i = 11 i = 13 i = 15 i = 17 i = 19 i = 21 i = 23 i = 25 i = 27 i = 29 i = 31 i = 33 i = 3
        5 i = 37 i = 39 i = 41 i = 43 i = 45 i = 47 i = 49 i = 51 i = 53 i = 55 i = 57 i = 59 i = 61 i = 63 i = 65 i = 67 i = 69
        i = 71 i = 73 i = 75 i = 77 i = 79 i = 81 i = 83 i = 85 i = 87 i = 89 i = 91 i = 93 i = 95 i = 97 i = 99*/

    return  0;
}

/**
 * 跳转语句——goto语句
 *
 * FLAG在哪里，执行到goto时，就会跳转到FLAG，中间的语句就会被省略掉
 * 缺点：破坏代码结构，不推荐使用
 */
int main53(){

    cout << " 1。 = "<< endl  ;
    cout << " 2。 = "<< endl  ;
    cout << " 3。 = "<< endl  ;
    goto FLAG;
    cout << " 4。 = "<< endl  ;
    cout << " 5。 = "<< endl  ;
    cout << " 6。 = "<< endl  ;
    FLAG:
    cout << " 7。 = "<< endl  ;
    cout << " 8。 = "<< endl  ;

   /* 1。 =
    2。 =
    3。 =
    7。 =
    8。 =*/

    return 0;
}