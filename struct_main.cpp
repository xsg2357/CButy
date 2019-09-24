//
// Created by xiang on 2019/9/22.
//
#include <iostream>
#include <ctime>

using namespace std;

/**
 * �ṹ�������û��Զ�����������ͣ������û��洢��ͬ����������
 * �﷨��struct �ṹ���� { �ṹ���Ա�б�}
 * struct �ṹ���� ������
 * struct �ṹ���� ������ = {��Աֵ,��Աֵ,��Աֵ....}
 * ����ṹ���ʱ��˳�㴴������
 * struct�����Ա�ʡ��
 */
struct Student { //����ѧ����������
    //��Ա�б�
    string name;
    int age;
    int score;

} s3;

int main91() {

    struct Student s1;
    s1.name = "����";
    s1.age = 187;
    s1.score = 99;
    cout << "name == " << s1.name << ",age == " << s1.age << ",score == " << s1.score << endl;

    struct Student s2 = {"����", 10, 30};
    cout << "name == " << s2.name << ",age == " << s2.age << ",score == " << s2.score << endl;

    s3.name = "wang";
    s3.score = 30;
    s3.age = 25;
    cout << "name == " << s3.name << ",age == " << s3.age << ",score == " << s3.score << endl;

    /*name == ����,age == 187,score == 99
    name == ����,age == 10,score == 30
    name == wang,age == 25,score == 30*/

    return 0;
}

/**
 * ���Զ���Ľṹ�ŵ������з���ά��
 * struct �ṹ���� ������[Ԫ�ظ���] = { {}��{}...{}}
 */
int main92() {

    struct Student structStudentArray[3] = {
            {"����", 10, 30},
            {"����", 10, 30},
            {"����", 10, 30}
    };

    //���ṹ���е�Ԫ�ظ�ְ
    structStudentArray[2].age = 80;
    structStudentArray[2].score = 90;

    //�����ṹ������
    for (int i = 0; i < 3; ++i) {
        cout << "name == " << structStudentArray[i].name << ",age == "
             << structStudentArray[i].age << ",score == " << structStudentArray[i].score << endl;
    }

    return 0;
}

/**
 * �ṹ��ָ��
 * struct����ʡ��
 * ͨ���ṹ��ָ����ʽṹ�������÷��š�->��
 */
int main93() {

    struct Student s1 = {"����", 10, 30};

    //ͨ��ָ��ָ��ṹ�����
    struct Student *p = &s1;

    //ͨ��ָ����ʽṹ������
    cout << "name == " << (p->name) << ",age == "
         << (p->age) << ",score == " << (p->score) << endl;

    //    name == ����,age == 10,score == 30

    return 0;
}

/**
 * �ṹ���п���Ƕ�׽ṹ��
 * �ṹ���еĳ�Ա���������ǽṹ��
 */
struct Teacher {

    int id;
    string name;
    int age;
    Student student;
};

void printStudent(Student student);

void printStudent1(Student *pStudent);


int main94() {

    Teacher t;
    t.age = 20;
    t.id = 1001;
    t.name = "����ʦ";
    t.student.name = "С��";
    t.student.score = 30;
    t.student.age = 20;

    cout << "teacher name == " << t.name << ",age == " << t.age << ",id == " << t.id << endl;
    cout << "student name == " << t.student.name << ",age == " << t.student.age << ",score == " << t.student.score
         << endl;

    /*teacher name == ����ʦ,age == 20,id == 1001
    student name == С��,age == 20,score == 30*/

    return 0;
}

/**
 * ���ṹ����Ϊ�������ݸ�����
 * 1.ֵ����
 * 2.��ַ����
 */
void printStudent1(Student *pStudent) {

    pStudent->age = 200;

    cout << "printStudent1 name == " << pStudent->name << ",age == " << pStudent->age << ",score == " << pStudent->score
         << endl;
    //��������޸��������е�ֵ����ʹ��ֵ���ݣ���֮��ʹ�õ�ַ����
    /* main name == ����,age == 10,score == 85
     printStudent name == ����,age == 100,score == 85
     printStudent1 name == ����,age == 200,score == 85

     printStudent1 name == ����,age == 200,score == 85
     main name == ����,age == 200,score == 85

     */

}


int main95() {

    struct Student student = {"����", 10, 85};


    printStudent(student);
    printStudent1(&student);

    cout << "main name == " << student.name << ",age == " << student.age << ",score == " << student.score << endl;

    /*main name == ����,age == 10,score == 85
    printStudent name == ����,age == 10,score == 85
    printStudent1 name == ����,age == 10,score == 85*/

    return 0;
}

//ֵ����
void printStudent(struct Student student) {
    student.age = 100;
    cout << "printStudent name == " << student.name << ",age == " << student.age << ",score == " << student.score
         << endl;
}


/**
 * ʹ��const����ֹ�����,��ֵ��ʱ��Ͳ��ᱨ��
 * ���βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��ḳֵ�µİ汾����
 */
void printStudentConst(const struct Student *pStudent) {
    //pStudent->name = "С��";
    //    cout << "printStudentConst name == " << student.name << ",age == " << student.age << ",score == " << student.score
    //         << endl;

    //    pStudent->name = "С��"; �������޸�
    cout << "printStudent1 name == " << pStudent->name << ",age == " << pStudent->age << ",score == " << pStudent->score
         << endl;
}


int main96() {

    struct Student student = {"����", 10, 85};

    printStudentConst(&student);

    return 0;
}

struct Teacher1 {
    string name;
    struct Student studentArray[5];
};

void printInfo(Teacher1 pTeacher1[3], int len);



void createTeacherSpace(struct Teacher1 tArray[], int len) {
    string name = "abcde";//����ʦ��ֵ
    string nameSeed = "abcde";//����ʦ��ֵ
    for (int i = 0; i < len; ++i) {
        tArray[i].name = "Teacher_";
        tArray[i].name += name[i];

        for (int j = 0; j < 5; ++j) {
            tArray[i].studentArray[j].name = "Student_";
            tArray[i].studentArray[j].name += nameSeed[j];

            int random = rand() % 61 + 40; //�����

            tArray[i].studentArray[j].score = random;
        }
    }

}

/**
 * �ṹ�尸��1: һ����ʦ��5��ѧ�� * 3
 */
int main97() {

    srand((unsigned int) time(NULL));//���������

    struct Teacher1 tArray[3];
    int len = sizeof(tArray) / sizeof(tArray[0]);
    createTeacherSpace(tArray, len);
    printInfo(tArray, len);

    /* name == Teacher_a
     name == Student_a score == 46
     name == Student_b score == 98
     name == Student_c score == 43
     name == Student_d score == 50
     name == Student_e score == 97
     name == Teacher_b
     name == Student_a score == 54
     name == Student_b score == 87
     name == Student_c score == 100
     name == Student_d score == 44
     name == Student_e score == 56
     name == Teacher_c
     name == Student_a score == 53
     name == Student_b score == 93
     name == Student_c score == 53
     name == Student_d score == 64
     name == Student_e score == 52*/

    return 0;
}

void printInfo(Teacher1 pTeacher1[], int len) {
    for (int i = 0; i < len; ++i) {

        cout << "teacher name == " << pTeacher1[i].name << endl;

        for (int j = 0; j < 5; ++j) {
            cout << "student name == " << pTeacher1[i].studentArray[j].name
                 << " score == " << pTeacher1[i].studentArray[j].score << endl;
        }

    }
};

struct Hero {
    string name;
    int age;
    string gender;
};

void bubboHeroSort(Hero pHero[5], int len);

/**
 * �ṹ�尸��2: Ӣ�۰�������������
 */
int main98() {

    struct Hero hero[5] = {{"�ŷ�",  36, "��"},
                           {"�ŷ�1", 48, "��"},
                           {"�ŷ�2", 26, "��"},
                           {"�ŷ�3", 53, "��"},
                           {"�ŷ�4", 36, "Ů"}};

    int len = sizeof(hero) / sizeof(hero[0]);

    bubboHeroSort(hero,len);

    for (int i = 0; i <len ; ++i) {
        cout << "student name == " << hero[i].name << "student age == " << hero[i].age
             << " gender == " << hero[i].gender << endl;
    }

   /* student name == �ŷ�2student age == 26 gender == ��
    student name == �ŷ�2student age == 26 gender == ��
    student name == �ŷ�2student age == 26 gender == ��
    student name == �ŷ�4student age == 36 gender == Ů
    student name == �ŷ�4student age == 36 gender == Ů*/

    return 0;
}

void bubboHeroSort(Hero pHero[], int len) {
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len -i -1 ; ++j) {
            if (pHero[j].age > pHero[j+1].age){
                struct  Hero  temp =  pHero[j+1];
                pHero[j] = pHero[j+1];
                pHero[j+1] = temp;
            }
        }
    }
}
