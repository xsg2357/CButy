//
// Created by Administrator on 2019/9/20.
//

#include <iostream>

using namespace std;
/**
 * 数组 就是一个集合，里面放了相同类型的元素
 * 数组是由连续的内存位置存放的
 * 一维数组：1.数据类型 数组名 数组长度
 *         2.数据类型 数组名 数组长度 ={元素1，。。。元素n}
 *         3.数据类型 数组名 【】 ={元素1，。。。元素n}
 * 可以通过数组下标访问数组中的元素
 */
int main61(){

    int arr[5];//数组命名规范和变量名规范一至，不能和变量名重名
    //数组中的元素赋值，下标从0开始索引
    arr[0] =0;
    arr[1] =1;
    arr[2] =2;
    arr[3] =3;
    arr[4] =4;

    cout << arr[0]  << endl;
    cout << arr[1]  << endl;
    cout << arr[2]  << endl;
    cout << arr[3]  << endl;
    cout << arr[4]  << endl;

    int arr2[5] = { 0,1,2,3,4};
   /* cout << arr2[0]  << endl;
    cout << arr2[1]  << endl;
    cout << arr2[2]  << endl;
    cout << arr2[3]  << endl;
    cout << arr2[4]  << endl;*/

    //数组遍历循环，输出数组值
    for (int i = 0; i < 5; ++i) {
        cout << arr2[i]  << endl;
    }

    int arr3[5] = { 0,1,2};//如果数组没有填充完，会用0来填充


    //数组遍历循环，输出数组值
    for (int i = 0; i < 5; ++i) {
        cout << arr3[i]  << endl;
    }

    int  arr4[] ={10,20,30,40,50,60,70,80};//定义此数组的时候。必须有初始值
    for (int i = 0; i < 8; ++i) {
        cout << arr3[i]  << endl;
    }

    return  0;
}

/**
 *数组用途：
 *      1.统计数组在内存中的长度 sizeof
 *      2.统计数组在内存中的首地址
 */
int main62(){

    int arr[8] ={10,20,30,40,50,60,70,80}; //数组名是常量，不可以在重新赋值
    cout << "size of arr is" << sizeof(arr) << endl; //32
    cout << "size of arr single is" << sizeof(arr[0]) << endl; //4
    cout << "size of arr length is" << sizeof(arr) /sizeof(arr[0]) << endl; //元素个数：8
//    cout << "size of arr the first  address is" << (int)arr << endl; //6553248 x32
    cout << "size of arr the first  address is" << (long long)arr << endl; //6553248 x64
//    cout << "size of arr the first single address is" << (int)&arr[0] << endl; //6553248 x32
    cout << "size of arr the first single address is" << (long long)&arr[0] << endl; //6553248 x64
//    cout << "size of arr the second  address is" << (int)&arr[1] << endl; //6553252 x32
    cout << "size of arr the second  address is" << (long long)&arr[1] << endl; //6553252 x64

    return  0;
}

/**
 * 案例：筛选最大值
 */
int main63(){
    int arr[] ={102,250,360,320,450};
    int  max =0 ;
    for (int i = 0; i < sizeof(arr) /sizeof(arr[0]); ++i) {
        if (arr[i] > max){
            max = arr[i];
        }
    }
    cout << "max value is " << max << endl;
    return  0;
}

/**
 * 案例：元素逆置
 */
int main64(){
    int arr[] ={102,250,360,320,450};
    int length = sizeof(arr) /sizeof(arr[0]);
    cout   << " before: " << endl;
    for (int i = 0; i <length ; ++i) {
        cout << arr[i]  << " ";
    }
    /**
     * 记录起始、结束位置 下标
     * 起始位置、起始位置 互换元素
     * 起++，end--
     * 起始位置 >= 结束位置
     */
    int start = 0;
    int end = length-1;
    while (start < end){
        int  temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start ++;
        end --;

    }
    cout   << " after: " << endl;
    for (int i = 0; i <length ; ++i) {
        cout << arr[i]  << " ";
    }
    //    before:
    //    102 250 360 320 450
    //    after:
    //    450 320 360 250 102
    return 0;
}

/**
 * 冒泡排序；最常用排序，对数组内元素进行排序
 * 1.想领两个元素，第一个比第二个大，就交换他们
 * 2.对每一组相邻元素做同样的工作，执行完毕后，找出最大值
 * 3.重复上面的操作，每次比较次数减1，知道不需要比较
 */
int main65(){

    int arr[] = {2,4,0,5,7,1,3,8,9};
    int length = sizeof(arr) /sizeof(arr[0]);
    cout   << " before: " << endl;
    for (int i = 0; i <length ; ++i) {
        cout << arr[i]  << " ";
    }
    cout  << endl;
    for (int i = 0; i <length -1; ++i) {//总共排序的次数等于元素个数-1

        for (int j = 0; j <length - i -1 ; ++j) {//能蹭循环次数等于元素个数-i（排序轮数）-1

            if(  arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }

    }
    cout   << " after: " << endl;
    for (int i = 0; i <length ; ++i) {
        cout << arr[i]  << " ";
    }
    /*before:
    2 4 0 5 7 1 3 8 9
    after:
    0 1 2 3 4 5 7 8 9*/
    return  0;
}

/**
 * 二维数组 在一维数组上面再加一维
 * 定义方式：
 * 数据类型 数组名[行数][列数] ；
 * 数据类型 数组名[行数][列数] = {{数据1，数据2}，{数据3，数据4}}；==>数据直观 更有可读性
 * 数据类型 数组名[行数][列数] =  {数据1，数据2，数据3，数据4}；
 * 数据类型 数组名[][列数] =  {数据1，数据2，数据3，数据4}；
 */
int main66(){

    //1
    int arr[2][3];
    arr[0][1] =1;
    arr[0][2] =1;
    arr[0][0] =1;
    arr[1][1] =1;
    arr[1][2] =1;
    arr[1][0] =1;


    cout << arr[0][1]  << " ";
    cout << arr[0][2]  << " ";
    cout << arr[0][0]  << " ";
    cout   << endl;
    cout << arr[1][1]  << " ";
    cout << arr[1][2]  << " ";
    cout << arr[1][0]  << " ";

    cout    << endl;
    cout    << endl;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <3 ; ++j) {

            cout << arr[i][j]  << " ";
        }
        cout    << endl;
    }
    cout    << endl;

    //2
    int arr2[2][3] = {
            {1,2,4},
            {2,4,6}
    };
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <3 ; ++j) {

            cout << arr2[i][j]  << " ";
        }
        cout    << endl;
    }
    cout    << endl;

    //3 省去值里面的大括号
    int arr3[2][3] ={1,2,3,4,5,6};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <3 ; ++j) {

            cout << arr3[i][j]  << " ";
        }
        cout    << endl;
    }

    cout    << endl;
    //4 省去行数的行的长度
    int arr4[][3] ={1,2,3,4,5,6};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <3 ; ++j) {

            cout << arr4[i][j]  << " ";
        }
        cout    << endl;
    }
    return  0;
}

/**
 * 内存空间、首元素空间
 */
int main67(){

    int arr2[2][3] = {
            {1,2,4},
            {2,4,6}
    };

    cout << sizeof(arr2) << "==> is size of arr , ";
    cout << sizeof(arr2[0]) << "==> is size of arr first, ";
    cout << sizeof(arr2[0][0]) << "==> is size of arr first, ";
    cout << sizeof(arr2)/sizeof(arr2[0]) << "==> is size of arr first line, ";//行数
    cout << sizeof(arr2[0])/sizeof(arr2[0][0]) << "==> is size of arr first column. " << endl;//列数

    //第一行和第二行数据的内存地址相差12
//    cout << "size of arr the first  address is" << (int)arr2 << endl; //6553256 x32
    cout << "size of arr the first  address is" << (long long)arr2 << endl; //6553256 x64
//    cout << "size of arr the first single address is" << (int)&arr2[0] << endl; //6553256 x32
    cout << "size of arr the first single address is" << (long long)&arr2[0] << endl; //6553256 x64
//    cout << "size of arr the first  address is" << (int)&arr2[0][0] << endl; //6553256 x32
    cout << "size of arr the first  address is" << (long long)&arr2[0][0] << endl; //6553256 x64
//    cout << "size of arr the second  address is" << (int)&arr2[0][1] << endl; //6553260 x32
    cout << "size of arr the second  address is" << (long long)&arr2[0][1] << endl; //6553260 x64
//    cout << "size of arr the second  address is" << (int)&arr2[1][0] << endl; //6553268 x32
    cout << "size of arr the second  address is" << (long long)&arr2[1][0] << endl; //6553268 x64

    return 0;
}

/**
 * 二维数组的案例 eg：统计行的总数据
 */
int main68(){

    int score[3][3] = {
            {100,100,100},
            {100,70,80},
            {80,80,90}

    };

    int lineLength = sizeof(score) / sizeof(score[0]);
    int colLength = sizeof(score[0]) / sizeof(score[0][1]);

    string name[] ={"张三","张-","张二"};
    int nameLength = sizeof(name) / sizeof(name[0]);

    //统计
    for (int i = 0; i <  lineLength; ++i) {
        int sum = 0;//统计分总数
        for (int j = 0; j <colLength ; ++j) {
            sum += score[i][j];
        }
        if(nameLength == lineLength){
            cout << name[i] << "的总分为："<<sum << endl;
        } else{
            cout << "第" << (i + 1) << "个人的总分为："<<sum << endl;
        }
    }

    return  0;
}