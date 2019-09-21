//
// Created by xiang on 2019/9/21.
//
#include <iostream>

using namespace std;

/**
 * ָ������ã�����ͨ��ָ��ֱ�ӷ����ڴ�
 * �ڴ����Ǵ�0��ʼ�� һ����ʮ�����Ʊ�ʾ
 * ��������ָ�������¼��ַ
 */
int main81(){

    //����ָ��
    int a = 10;
    //ָ����﷨�� �������� * ָ���������
    int *p;

    //��ָ���¼����a�ĵ�ַ
    p = &a;
    cout << "a�ĵ�ַΪ�� " << &a << endl;
    cout << "ָ�룺p = " << p << endl;

    /*a�ĵ�ַΪ�� 0x64fe14
    ָ�룺p = 0x64fe14*/

    //ʹ��ָ�룺����ͨ�������õķ�ʽ���ҵ�ָ��ָ�����ڴ�
    //ָ��ǰ�� * ��������� �ҵ�ָ����ָ�����ڴ������

    *p = 1000;
    cout << "a��ֵΪΪ��a = " << a << endl;
    cout << "ָ�룺*p = " << *p << endl;

   /* a��ֵΪΪ��a = 1000
    ָ�룺*p = 1000*/

    return  0;
}

/**
 * ָ����ռ���ڴ�ռ�
 * 32λϵͳ��4���ֽ�
 * 64λϵͳ��8���ֽ�
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
 * ��ָ��;ָ�����ָ���ڴ�λ0 �ı��
 * ��;����ʼ��ָ�����
 * ��ָ��ָ����ڴ��ǲ��ܷ��ʵ�
 */
int main83(){

    int *p = NULL;

    cout << " p ==  " << p << endl;

    //    *p = 100;  //��ָ��ָ����ڴ��ǲ��ܷ��ʵ� 0~255 ��ϵͳ�ڴ�ռ�õ� �������û�����

    return  0;
}

/**
 * Ұָ�룺ָ�����ָ��Ƿ����ڴ�ռ�
 * �ڳ�����Ӧ����Ұָ��
 * ��ָ���Ұָ�벻���û�����Ŀռ� ����ʹ��
 */
int main84(){

    int  *p = (int *) 0x110;

//    cout << " p ==  " << *p << endl; // �ᱨ��
    return  0;
}

/**
 * const����ָ�룺
 * 1.const����ָ�� ����ָ�� ��ָ��ǰ�����const�޶�
 *    ָ���ָ������޸ģ�����ָ���ֵ�������޸�
 *    eg: const int *p = &a ��*p = &b
 * 2.const���γ���  ָ�볣��
 *   ��ָ�����* �������const�޶���ָ���ָ�򲻿��Ըģ�����ֵ�����޸�
 *   eg: int * const p = &a; *p = 20
 * 3.const����ָ��ͳ��� �� ��������ǰ���*�������const
 *   ָ���ָ���ָ���ֵ���������޸�
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
 * ָ�������
 * ����ָ����������Ԫ��
 */
int main(){

    return 0;
}