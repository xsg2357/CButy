#include <iostream>
#include <string>

# define Day 7 //��������1

using  namespace std;

int main0() {
    std::cout << "Hello, World!" << std::endl;

    //�������ڹ����ڴ�ռ�,�ڸ�����������������ʱ�򲻵�ʹ�ùؼ���
    //��־������ĸ ���� �»���
    //��һ����ĸ��������ĸ���»���
    //��־������ĸ���ִ�Сд
    int a = 10;
    std::cout << "a = " << a << std::endl;
    /**
     * ���峣�� �����ǲ����޸ĵ�
     * 1.# define �곣�� ��﷽ʽ�� # define ������ ����ֵ
     * 2.const ���εı��� ��﷽ʽ�� const �������� ������ = ����ֵ
     */
    std::cout << "һ����" << Day << "��" << std::endl; //������� define

    const  int  month = 30; //��������2
    std::cout << "һ����" << month << "��" << std::endl;

    system("pause"); // �밴���������. . .

    return 0;
}

int main1(){


    //1.������ -32768 ~ 32767 2�ֽ�
    short num1 = 10;
    //2.����  4 �ֽ�
    int num2 = 10;
    //3.������ 4�ֽ� Linux 8�ֽ�
    long num3 = 10;
    //4.�������� 8�ֽ�
    long long num4 = 10;

    std::cout << "num1 = " << num1 << std::endl;
    std::cout << "num2 = " << num2 << std::endl;
    std::cout << "num3 = " << num3 << std::endl;
    std::cout << "num4 = " << num4 << std::endl;

    system("pause"); // �밴���������

    /**
     * sizeof �ؼ��ֿ���ͳ������������ռ�ڴ��С
     * �﷨��sizeof(��������/����)
     *      short sizeof = 2
            int sizeof = 4
            long sizeof = 4
            long  long sizeof = 8

            �ܽ᣺ short < int <= long <= long long
     */
    std::cout << "short sizeof = " << sizeof(short) << std::endl;
    std::cout << "int sizeof = " << sizeof(int) << std::endl;
    std::cout << "long sizeof = " << sizeof(long) << std::endl;
    std::cout << "long  long sizeof = " << sizeof(long long) << std::endl;

    return  0;
}

int main2(){
    //ʵ�ͣ������ͣ� ������float��˫����double Ĭ����ʾ6λ��Ч����
    //float 4 �ֽ� 7λ��Ч���� ��double 8 �ֽ� 15~16λ��Ч����
    float f1 = 3.1415926f;
    std::cout << "f1 = " << f1 << std::endl;

    double  d1 = 3.1415926;
    std::cout << "d1 = " << d1 << std::endl;

    //ͳ���ڴ�ռ�
    std::cout << "float sizeof = " << sizeof(float) << std::endl;
    std::cout << "double sizeof = " << sizeof(double) << std::endl;

    //��ѧ������
    float f2 = 3e2; //3 * 10~2
    std::cout << "f2 = " << f2 << std::endl; //300
    float f3 = 3e-2; //3 * 0.1 ~ 2
    std::cout << "f3 = " << f3 << std::endl; // 0.03

    return  0;
}

int main3(){
    //�ַ������ڵ����ַ� char c = 'c'
    //��ʾ�ַ�����ʱ���õ�������������������˫���� �� ������ֻ����һ���ַ��������Ƕ���ַ�
    //c��C++��վ1���ֽڣ����ܷŵ��ڴ��д洢�����ǰѶ�Ӧ��ASCII����ŵ��ڴ���

    char c = 'a';
    std::cout << "c = " << c << std::endl;
    std::cout << "char sizeof = " << sizeof(char) << std::endl;
    std::cout << "char sizeof = " << int(c) << std::endl; //97 A--> 65

    return  0;
}

int main4(){
    //ת���ַ���\a ���� \b �˸� \f ��ҳ  \n ���� \r �س�  \tˮƽ�Ʊ�
    //\v ��ֱ�Ʊ�  \\����һ����б�ܡ�\�� \' ����һ��������  ��
    std::cout << "ccc\acccccc" << std::endl;
    std::cout << "ccc\bcccccc" << std::endl;
    std::cout << "ccc\fcccccc" << std::endl;
    std::cout << "ccc\ncccccc" << std::endl;
    std::cout << "ccc\rcccccc" << std::endl;
    std::cout << "ccc\tcccccc" << std::endl;
    std::cout << "ccc\vcccccc" << std::endl;
    std::cout << "ccc\\cccccc" << std::endl;
    std::cout << "ccc\'cccccc" << std::endl;
    std::cout << "ccc\"cccccc" << std::endl;
    std::cout << "ccc\?cccccc" << std::endl;

    return 0;
}

int main5(){
    //�ַ��������ڱ�ʾһ���ַ�
    //1.C��� �����õ����� Ҫ��˫����
    char str1[] = "abcde";
    std::cout << "str1 ==" << str1 << std::endl;

    //2.C++��� ��Ҫ����ͷ�ļ�#include <string>
    string str2 = "Hello World";
    std::cout << "str2 ==" << str2 << std::endl;
    return 0;
}

int main6(){
    //�������� ����bool����
    bool  flag = false;
    bool  flag1 = true;
    std::cout << "flag ==" << flag << std::endl; //0
    std::cout << "flag1 ==" << flag1 << std::endl;//1

    //�鿴���������ڴ�ռ�
    std::cout << "sizeof bool ==" << sizeof(bool) << std::endl; //1�ֽ�

    return 0;
}

int main7(){

    //    1.����
    int a = 0;
    std::cout << "������ͱ���a��ֵ��" << std::endl;
    cin >> a;
    std::cout << "a ==" << a << std::endl;

    //    ������
    int f = 0;
    std::cout << "��������ͱ���f��ֵ��" << std::endl;
    cin >> f;
    std::cout << "f ==" << f << std::endl;

    //    �ַ���
    char c = 'a';
    std::cout << "����ַ��ͱ���f��ֵ��" << std::endl;
    cin >> c;
    std::cout << "c ==" << c << std::endl;

    //   �ַ���
    string str = "hello";
    std::cout << "����ַ�������str��ֵ��" << std::endl;
    cin >> str;
    std::cout << "str ==" << str << std::endl;

    //   ����ֵ
    bool flag = false;
    std::cout << "�������ֵ����flag��ֵ��" << std::endl;
    cin >> flag;
    std::cout << "flag ==" << flag << std::endl;


    return 0;
}