//
// Created by Administrator on 2019/9/20.
//

#include <iostream>

using namespace std;
/**
 * ���� ����һ�����ϣ����������ͬ���͵�Ԫ��
 * ���������������ڴ�λ�ô�ŵ�
 * һά���飺1.�������� ������ ���鳤��
 *         2.�������� ������ ���鳤�� ={Ԫ��1��������Ԫ��n}
 *         3.�������� ������ ���� ={Ԫ��1��������Ԫ��n}
 * ����ͨ�������±���������е�Ԫ��
 */
int main61(){

    int arr[5];//���������淶�ͱ������淶һ�������ܺͱ���������
    //�����е�Ԫ�ظ�ֵ���±��0��ʼ����
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

    //�������ѭ�����������ֵ
    for (int i = 0; i < 5; ++i) {
        cout << arr2[i]  << endl;
    }

    int arr3[5] = { 0,1,2};//�������û������꣬����0�����


    //�������ѭ�����������ֵ
    for (int i = 0; i < 5; ++i) {
        cout << arr3[i]  << endl;
    }

    int  arr4[] ={10,20,30,40,50,60,70,80};//����������ʱ�򡣱����г�ʼֵ
    for (int i = 0; i < 8; ++i) {
        cout << arr3[i]  << endl;
    }

    return  0;
}

/**
 *������;��
 *      1.ͳ���������ڴ��еĳ��� sizeof
 *      2.ͳ���������ڴ��е��׵�ַ
 */
int main62(){

    int arr[8] ={10,20,30,40,50,60,70,80}; //�������ǳ����������������¸�ֵ
    cout << "size of arr is" << sizeof(arr) << endl; //32
    cout << "size of arr single is" << sizeof(arr[0]) << endl; //4
    cout << "size of arr length is" << sizeof(arr) /sizeof(arr[0]) << endl; //Ԫ�ظ�����8
//    cout << "size of arr the first  address is" << (int)arr << endl; //6553248 x32
    cout << "size of arr the first  address is" << (long long)arr << endl; //6553248 x64
//    cout << "size of arr the first single address is" << (int)&arr[0] << endl; //6553248 x32
    cout << "size of arr the first single address is" << (long long)&arr[0] << endl; //6553248 x64
//    cout << "size of arr the second  address is" << (int)&arr[1] << endl; //6553252 x32
    cout << "size of arr the second  address is" << (long long)&arr[1] << endl; //6553252 x64

    return  0;
}

/**
 * ������ɸѡ���ֵ
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
 * ������Ԫ������
 */
int main64(){
    int arr[] ={102,250,360,320,450};
    int length = sizeof(arr) /sizeof(arr[0]);
    cout   << " before: " << endl;
    for (int i = 0; i <length ; ++i) {
        cout << arr[i]  << " ";
    }
    /**
     * ��¼��ʼ������λ�� �±�
     * ��ʼλ�á���ʼλ�� ����Ԫ��
     * ��++��end--
     * ��ʼλ�� >= ����λ��
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
 * ð������������򣬶�������Ԫ�ؽ�������
 * 1.��������Ԫ�أ���һ���ȵڶ����󣬾ͽ�������
 * 2.��ÿһ������Ԫ����ͬ���Ĺ�����ִ����Ϻ��ҳ����ֵ
 * 3.�ظ�����Ĳ�����ÿ�αȽϴ�����1��֪������Ҫ�Ƚ�
 */
int main65(){

    int arr[] = {2,4,0,5,7,1,3,8,9};
    int length = sizeof(arr) /sizeof(arr[0]);
    cout   << " before: " << endl;
    for (int i = 0; i <length ; ++i) {
        cout << arr[i]  << " ";
    }
    cout  << endl;
    for (int i = 0; i <length -1; ++i) {//�ܹ�����Ĵ�������Ԫ�ظ���-1

        for (int j = 0; j <length - i -1 ; ++j) {//�ܲ�ѭ����������Ԫ�ظ���-i������������-1

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
 * ��ά���� ��һά���������ټ�һά
 * ���巽ʽ��
 * �������� ������[����][����] ��
 * �������� ������[����][����] = {{����1������2}��{����3������4}}��==>����ֱ�� ���пɶ���
 * �������� ������[����][����] =  {����1������2������3������4}��
 * �������� ������[][����] =  {����1������2������3������4}��
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

    //3 ʡȥֵ����Ĵ�����
    int arr3[2][3] ={1,2,3,4,5,6};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j <3 ; ++j) {

            cout << arr3[i][j]  << " ";
        }
        cout    << endl;
    }

    cout    << endl;
    //4 ʡȥ�������еĳ���
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
 * �ڴ�ռ䡢��Ԫ�ؿռ�
 */
int main67(){

    int arr2[2][3] = {
            {1,2,4},
            {2,4,6}
    };

    cout << sizeof(arr2) << "==> is size of arr , ";
    cout << sizeof(arr2[0]) << "==> is size of arr first, ";
    cout << sizeof(arr2[0][0]) << "==> is size of arr first, ";
    cout << sizeof(arr2)/sizeof(arr2[0]) << "==> is size of arr first line, ";//����
    cout << sizeof(arr2[0])/sizeof(arr2[0][0]) << "==> is size of arr first column. " << endl;//����

    //��һ�к͵ڶ������ݵ��ڴ��ַ���12
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
 * ��ά����İ��� eg��ͳ���е�������
 */
int main68(){

    int score[3][3] = {
            {100,100,100},
            {100,70,80},
            {80,80,90}

    };

    int lineLength = sizeof(score) / sizeof(score[0]);
    int colLength = sizeof(score[0]) / sizeof(score[0][1]);

    string name[] ={"����","��-","�Ŷ�"};
    int nameLength = sizeof(name) / sizeof(name[0]);

    //ͳ��
    for (int i = 0; i <  lineLength; ++i) {
        int sum = 0;//ͳ�Ʒ�����
        for (int j = 0; j <colLength ; ++j) {
            sum += score[i][j];
        }
        if(nameLength == lineLength){
            cout << name[i] << "���ܷ�Ϊ��"<<sum << endl;
        } else{
            cout << "��" << (i + 1) << "���˵��ܷ�Ϊ��"<<sum << endl;
        }
    }

    return  0;
}