//
// Created by Administrator on 2019/9/19.
//
#include <iostream>
#include <ctime>

using namespace std;

/**
 * while ѭ�� �﷨��while(����){ ִ���﷨}
 * ֻҪѭ���Ľ��Ϊ�棬�ͻ�ִ��ѭ��
 */
int main41() {
    //��� 0 - 9
    int num = 0;
    while (num < 10) {
        cout << " num = " << num << endl;
        num++;
        //ע�⣺��Ҫд��ѭ��
    }
    return 0;
}

int main42() {
    //������������ ����ʱ�� ��ֹÿ�ζ�һ��
    srand((unsigned int) time(NULL));


    //��������� 1 - 100
    int num = rand() % 100 + 1;

    //����������ݣ����в²�
    int val = 0;
    while (1) {
        cout << " ��ҿ�ʼ�²� " << endl;
        cin >> val;
        if (val > num) {
            cout << " �²���� " << endl;
        } else if (val < num) {
            cout << " �²��С " << endl;
        } else {
            cout << " �¶��� " << endl;
            //�˳���Ϸ
            break;//�ùؼ��ֿ����˳�ѭ��
        }
    }

    return 0;
}

/**
 * do...whileѭ����� �䷨��do{...to do..}while(����);
 * ������while����������do_while�����ִ��һ��ѭ����� ���ж�ѭ������
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
    } while (num);//������ѭ��

//    while (num) {//����Ĵ��벻��ִ��
//        cout << " num = " << num << endl;
//        num++;
//    }

    return 0;
}

/**
 * ˮ�ɻ���  eg��1^3 +5^3 +3^3  = 153
 */
int main44(){

    //�ȴ�ӡ��λ����
    int num = 100;
    do{

        //�������������ҵ���λˮ�ɻ���
        int a = 0;//��λ
        int b = 0;//ʮλ
        int c = 0;//��λ

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
 * forѭ�� �﷨��for���������� ���������� < ���ȣ�����++����{ִ�����}
 * ���� �ṹ��ϴ
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
 * ������ 7�ı�������λ��7����λ��7�� ʮλ��7
 */
int main46(){

    for (int i = 1; i <= 100 ; i++) {

        if( i % 7 == 0 || i % 10 == 7 || i / 10 == 7){
            cout << " ������ = " << i << endl;
        }

    }

    return  0;
}

/**
 * Ƕ��ѭ�� ��ӡ��ͼ
 */
int main47(){

    for (int j = 0; j <10 ; ++j) {//��ѭ���������

        for (int i = 0; i < 10; ++i) {//��ѭ���������
            cout << "* ";//��ѭ�����
        }

        cout << endl;//��ѭ�����
    }

    return  0;
}

/**
 * Ƕ��ѭ�� ��ӡ�˷���
 */
int main48(){

    for (int i = 1; i <= 9 ; ++i) {

        for (int j = 1; j <= i ; ++j) {

            cout << j << " * " << i << " = " << ( j * i) << " ";//��ѭ�����

        }
        cout << endl;//��ѭ�����
    }
    
    return  0;
}