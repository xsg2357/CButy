//
// Created by xiang on 2019/9/21.
//
#include <iostream>

using namespace std;

/**
 * 指针的作用：可以通过指针直接访问内存
 * 内存编号是从0开始的 一般用十六进制表示
 * 可以利用指针变量记录地址
 */
int main81(){

    //定义指针
    int a = 10;
    //指针的语法： 数据类型 * 指针变量名；
    int *p;

    //让指针记录变量a的地址
    p = &a;
    cout << "a的地址为： " << &a << endl;
    cout << "指针：p = " << p << endl;

    /*a的地址为： 0x64fe14
    指针：p = 0x64fe14*/

    //使用指针：可以通过解引用的方式来找到指针指引的内存
    //指针前加 * 代表解引用 找到指针所指引的内存的数据

    *p = 1000;
    cout << "a的值为为：a = " << a << endl;
    cout << "指针：*p = " << *p << endl;

   /* a的值为为：a = 1000
    指针：*p = 1000*/

    return  0;
}

/**
 * 指针所占的内存空间
 * 32位系统：4个字节
 * 64位系统：8个字节
 */
int main82(){

    int a = 10;
    int  *p = &a;

    cout << " size of int * " << sizeof(p) << endl; //8 64
    cout << " size of float * " << sizeof(float *) << endl; //8 64
    cout << " size of double * " << sizeof(double *) << endl; //8 64
    cout << " size of char * " << sizeof(char *) << endl; //8 64

    return  0;
}

/**
 * 空指针;指针变量指向内存位0 的编号
 * 用途：初始化指针变量
 * 空指针指向的内存是不能访问的
 */
int main83(){

    int *p = NULL;

    cout << " p ==  " << p << endl;

    //    *p = 100;  //空指针指向的内存是不能访问的 0~255 是系统内存占用的 不允许用户访问

    return  0;
}

/**
 * 野指针：指针变量指向非法的内存空间
 * 在程序中应避免野指针
 * 空指针和野指针不是用户申请的空间 不能使用
 */
int main84(){

    int  *p = (int *) 0x110;

//    cout << " p ==  " << *p << endl; // 会报错
    return  0;
}

/**
 * const修饰指针：
 * 1.const修饰指针 常量指针 在指针前面加上const限定
 *    指针的指向可以修改，但是指针的值不可以修改
 *    eg: const int *p = &a ；*p = &b
 * 2.const修饰常量  指针常量
 *   在指针符号* 后面加上const限定，指针的指向不可以改，但是值可以修改
 *   eg: int * const p = &a; *p = 20
 * 3.const修饰指针和常量 在 数据类型前面和*后面加上const
 *   指针的指向的指针的值都不可以修改
 *   eg: const int * const p = &a
 */
int main85(){

    int  a= 10;
    int b = 20;

    //1
    const  int *p = &a;
    p = &b;
//    *p = 200;

    //2
    int * const p1 = &a;
//    p1 = &b;
    *p1 = 300;

    //3
    const  int * const p2 = &a;
//    p3 = &b;
//      *p3 = 200;

    return  0;
}

/**
 * 指针和数组
 * 利用指针访问数组的元素
 */
int main86(){

    int arr[] = {1,3,2,4,5,6,7,8,9,110};

    cout << "this first ploit is" << arr[0] << endl;
    int *p = arr; //arr就是数组首地址

    cout << "*p this first ploit is " << *p << endl;

    p ++; //让指针向后偏移4个字节
    cout << "*p this second ploit is " << *p << endl;

    int *p2 = arr;
    //利用指针来遍历数组
    for (int i = 0; i < sizeof(arr)/ sizeof(arr[0]); ++i) {
        cout  << * p2 << " ";
        p2 ++;
    }
    //    1 3 2 4 5 6 7 8 9 110
    return 0;
}

/**
 * 值传递
 */
void swap01(int a,int b){
    int  temp = a;
    a = b;
    b= temp;

    cout << " after: a = "<< a ;
    cout << " after: b = "<< b ;

}

/**
 * 地址传递
 */
void swap02(int *p,int *p2){
    int  temp = *p;
    *p = *p2;
    *p2= temp;

    cout << "swap02 after: *p = "<< *p ;
    cout << "swap02 after: *p2 = "<< *p2 ;

}


/**
 *  指针和函数
 */
int main87(){

    int a= 10;
    int b = 20;
    swap01(a,b);
    cout << " a = "<< a ;
    cout << " b = "<< b ;
    //    after: a = 20 after: b = 10 ,a = 10 b = 20
    cout << endl;

    // 地址传递
    swap02(&a,&b);
    cout << " a = "<< a ;
    cout << " b = "<< b ;
    //    after: a = 20 after: b = 10  ,a = 10 b = 20

    return  0;
}

/**
 * 冒泡排序
 */
void bubbleSort(int *arr,int len){
    for (int i = 0; i <len-1 ; ++i) {
        for (int j = 0; j < len -i -1 ; ++j) {
            if (arr[j] >arr[j+1]){
                int  temp = arr[j];
                arr[j]  = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void  printArr(int *arr,int len){
    for (int i = 0; i < len; ++i) {
        cout << " "<< arr[i] ;
    }
}

int main88(){

    //创建一个数组
    int arr[] = {1,3,2,4,5,6,7,8,9,110};
    int len = sizeof(arr) / sizeof(arr[0]);

    //利用函数进行排序
    bubbleSort(arr,len);

    //打印排序后的数组
    printArr(arr,len);
    //    1 2 3 4 5 6 7 8 9 110
    return  0;
}

