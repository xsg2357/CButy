//
// Created by xiang on 2019/9/21.
//
#include <iostream>
#include "headerfile/functionfiloe.h"
using namespace std;

/**
 *  ��������һ�δ����װ���� �����ظ�����
 *  һ���ϴ�ĳ��� һ���װΪ���ɿ�  ÿ��ģ��ʵ���ض��Ĺ���
 *  ��������һ���Ϊ5��ģ�飺
 *   ����ֵ���� ������ �������� ���������  return���ʽ
 *
 *   ����ֵ���� ������ (��������){
 *      ���������
 *      return���ʽ
 *   }
 *
 *   num1 num2 ��ʽ���� ����β�
 * @return
 */
int add(int num1, int num2) {

    return num1 + num2;
}


int main70() { //�����ĵ���

    int a = 10;
    int b = 20;

    //���ú����ǣ�ʵ�λ��ֵ���ݸ��β�
    int c = add(a, b);
    cout << "�ӷ���c = " << c << endl;

    cout << "�ӷ���" << add(1, 2) << endl;

    a = 500;
    b = 100;
    c = add(a, b);//a��b����ʵ�ʲ��� ���ʵ��
    cout << "�ӷ���c = " << c << endl;

    return 0;
}

/**
 * ֵ���� ���ú���ʱ��ʵ�λ��ֵ���ݸ��β�
 * �βη����ı�ʱ��ʵ�ʵ�ֵ������ı�
 * eg:����ֵ���н���
 *
 * ����Ҫ ����ֵʱ����void���Բ���return
 */
void swap(int num1, int num2) {

    cout << "����ǰ���֣�num1 =" << num1 << ",num2=" << num2 << endl;
    int temp = num1;
    num1 = num2;
    num2 = temp;

    cout << "���������֣�num1 =" << num1 << ",num2=" << num2 << endl;

}

int main71() {
    int a = 10;
    int b = 20;

    swap(a, b);

}

void test01() {
    cout << "�����޲��޷�����" << endl;
}

void test02(int a) {
    cout << "�����в��޷�������ֵ��" << a << endl;
}

int test03() {
    cout << "�����޲��з�����" << endl;
    return 1;
}

int test04(int a, int b) {
    cout << "�����в��з�����" << endl;
    return a - b;
}

/**
 * ����������ʽ��
 *   �޲��޷� �޲��з� �в��з� �в��޷�
 */
int main72() {
    test01();
    test02(20);

    int a = test03();
    cout << "�����޲��з�������ֵ��" << a << endl;

    int b = test04(3, 4);
    cout << "�����в��з�������ֵ��" << b << endl;
    return 0;
}

/**
 * �������� eg: �Ƚ�����ֵ�ú���
 * ��ǰ��֪�����������Ĵ��ڣ��������ú���������
 * ��������д��Σ��������ܶ���һ��
 */
int max(int a, int b);
int max(int a, int b);

/*int max(int a, int b) {

    return a > b ? a : b;
}*/

int main73() {

    int a = 10;
    int b = 20;

    cout << "���ֵ��" << max(a,b) << endl;

}

int max(int a, int b) {

    return a > b ? a : b;
}


/**
 * �����ķ��ļ���д--�ô���ṹ������
 * 1.������׺��Ϊ.h��ͷ�ļ�
 * 2.������׺��Ϊ.cpp��Դ�ļ�
 * 3.��ͷ�ļ��б�д����������
 * 4.��Դ�ļ��б�д�����Ķ���
 */
int main74(){

    int a = function_file(30,40);
    cout << "���ֵ��A = " << a << endl;
    return 0;
}
