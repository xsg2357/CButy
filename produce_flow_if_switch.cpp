//
// Created by Administrator on 2019/9/19.
//
#include <iostream>

using namespace std;

int main31() {
    /**
     * ������ƽṹ��
     *   1.˳��ṹ ����˳��ִ�� ��������ת
     *   2.���������Ƿ����� ��ѡ���ִ����Ӧ����
     *   3.���������Ƿ����� ѭ�����ִ��ĳ�δ���
     */

    /**
     * if ��䡪���������������
     */
    //����if �﷨��if(����){ .... to do ...}

    int score = 0;
    cout << "�����������" << endl;
    cin >> score;

    //����if �����ж� if���治��д�ֺ�
    if (score > 600) {
        cout << "��ϲ�㿼����һ����ѧ" << endl;
    }

    //����if �﷨��if(����){ .... to do ...}else{ ... to do ...}
    if (score > 700) {
        cout << "��ϲ��ÿ������ص��ѧ" << endl;
    } else {
        cout << "��ϲ�㿼����һ����ѧ" << endl;
    }


    //������if �﷨��if(����1){ .... to do ...} else if(����2){ .... to do ...}....else{ ... to do ...}
    if (score > 750) {
        cout << "��ϲ��ÿ������ص��ѧ" << endl;
        //Ƕ�� if��� �﷨��if(����1){ ..if(����1){..to do .. }.. to do ...} else if(����2){ .... to do ...}....else{ ... to do ...}
        if (score == 768) {
            cout << "��ϲ��ÿ������ص�___�ص��ѧ" << endl;
        }
    }
    if (score > 800) {
        cout << "��ϲ��ÿ��Ϲ���Ĵ�ѧ" << endl;
    } else {
        cout << "��ϲ�㿼����һ����ѧ" << endl;
    }


    return 0;

}

int main32() {
    //��ֻС�������

    //1.������ֻС�������
    int a = 0;
    int b = 0;
    int c = 0;

    cout << "������a�����أ�" << endl;
    cin >> a;
    cout << "a�����أ�" << a << endl;

    cout << "������b�����أ�" << endl;
    cin >> b;
    cout << "b�����أ�" << b << endl;

    cout << "������c�����أ�" << endl;
    cin >> c;
    cout << "c�����أ�" << c << endl;

    if (a > b) {

        if (a > c) {
            cout << "a�����ش�" << endl;
        } else {
            cout << "c�����ش�" << endl;
        }
    } else {
        if (b > c) {
            cout << "b�����ش�" << endl;
        } else {
            cout << "c�����ش�" << endl;
        }
    }


    return 0;
}

int main33() {
    //��Ŀ����� �﷨�����ʽ1 �� ���ʽ2�����ʽ3
    //���ʽ1Ϊ��ִ�б��ʽ2��Ϊ��ִ�б��ʽ3

    int a = 10;
    int b = 20;
    int c = 0;

    c = a > b ? a : b;//20
    cout << "c ��" << c << endl;

    //���ص��Ǳ��������Լ�����ֵ

    a > b ? a : b = 100;
    cout << "a ��" << a << endl;//10
    cout << "b ��" << b << endl;//100

    return 0;
}

/**
 * switch ��� �ṹ���� ִ��Ч�ʸߣ� ֻ�������ͺ��ַ��ͣ� �����������ж�
 * �﷨��
 *   switch(���ʽ){
 *      case ���1��
 *         ִ�����; break;
 *      case ���2��
 *         ִ�����; break;
 *      case ���2��
 *         ִ�����; break;
 *      ......
 *      default:
 *           ִ�����;break;
 *   }
 */
int main34(){

    int score = 0;
    cout << "�������Ӱ���֣�" << endl;
    cin >> score;
    switch (score){

        case 60:
        case 65:
            cout << "����" << endl;
            break;
        case 70:
        case 75:
            cout << "һ�㣺" << endl;
            break;
        case 80:
        case 85:
            cout << "�ܺã�" << endl;
            break;
        case 90:
        case 95:
            cout << "̫���ˣ�" << endl;
            break;
        default:
            cout << "��ˣ�" << endl;
            break;
    }

    return  0;
}