//
// Created by Administrator on 2019/9/19.
//

#include <iostream>

using namespace std;


/**
 * ��ת��䡪��break���
 * ʹ��ʱ����
 *        1.������switch����У���ֹcase����switch
 *        2.������ѭ������У�������ǰѭ�����
 *        3.������Ƕ��ѭ���У������ڲ�ѭ�����
 *
 */
int main51(){


    //    .������switch����У���ֹcase����switch
    cout << " ��ѡ���Ѷ� "  << endl;
    cout << " 1������ "  << endl;
    cout << " 2��һ�� "  << endl;
    cout << " 3���� "  << endl;
    int sel = 0;
    cin >> sel;
    switch (sel){
        case 1:
            cout << " 1������ "  << endl;
            break;
        case 2:
            cout << " 2��һ�� "  << endl;
            break;
        case 3:
            cout << " 3���� "  << endl;
            break;
        default:
            cout << " ѡ����� "  << endl;
            break;
    }

    //    .������ѭ������У�������ǰѭ�����
    for (int i = 0; i < 10; ++i) {
        if ( i > 5){
            break;
        }
        cout << " i = "<< i  << endl;
    }

    //   3.������Ƕ��ѭ���У������ڲ�ѭ�����
    for (int j = 0; j < 10; ++j) {
        for (int i = 0; i < 10; ++i) {
            if( j ==5){
                break;
            }
            cout << "* ";//��ѭ�����
        }
        cout << endl;//��ѭ�����
    }
    
    return 0;
}

/**
 * ��ת��䡪��Continue���
 * ִ�е�ĳһ�䣬����continue�ж� �ͻ�������ǰѭ������ִ���������䣬����ִ����һ��ѭ��
 * break ���˳�ѭ����continue�����˳�ѭ��
 */
int main52(){

    for (int i = 0; i <100 ; ++i) {

        if ( i % 2 == 0){//��������������ż��
            continue;//�ڴˣ�����ִ���������䣬����ִ����һ��ѭ��
        }
        cout << " i = "<< i  ;
    }

       /* i = 1 i = 3 i = 5 i = 7 i = 9 i = 11 i = 13 i = 15 i = 17 i = 19 i = 21 i = 23 i = 25 i = 27 i = 29 i = 31 i = 33 i = 3
        5 i = 37 i = 39 i = 41 i = 43 i = 45 i = 47 i = 49 i = 51 i = 53 i = 55 i = 57 i = 59 i = 61 i = 63 i = 65 i = 67 i = 69
        i = 71 i = 73 i = 75 i = 77 i = 79 i = 81 i = 83 i = 85 i = 87 i = 89 i = 91 i = 93 i = 95 i = 97 i = 99*/

    return  0;
}

/**
 * ��ת��䡪��goto���
 *
 * FLAG�����ִ�е�gotoʱ���ͻ���ת��FLAG���м�����ͻᱻʡ�Ե�
 * ȱ�㣺�ƻ�����ṹ�����Ƽ�ʹ��
 */
int main53(){

    cout << " 1�� = "<< endl  ;
    cout << " 2�� = "<< endl  ;
    cout << " 3�� = "<< endl  ;
    goto FLAG;
    cout << " 4�� = "<< endl  ;
    cout << " 5�� = "<< endl  ;
    cout << " 6�� = "<< endl  ;
    FLAG:
    cout << " 7�� = "<< endl  ;
    cout << " 8�� = "<< endl  ;

   /* 1�� =
    2�� =
    3�� =
    7�� =
    8�� =*/

    return 0;
}