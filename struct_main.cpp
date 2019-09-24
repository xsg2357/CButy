//
// Created by xiang on 2019/9/22.
//
#include <iostream>
#include <ctime>

using namespace std;

/**
 * 结构体属于用户自定义的数据类型；允许用户存储不同的数据类型
 * 语法：struct 结构体名 { 结构体成员列表}
 * struct 结构体名 变量名
 * struct 结构体名 变量名 = {成员值,成员值,成员值....}
 * 定义结构体的时候顺便创建变量
 * struct不可以被省略
 */
struct Student { //创建学生数据类型
    //成员列表
    string name;
    int age;
    int score;

} s3;

int main91() {

    struct Student s1;
    s1.name = "张三";
    s1.age = 187;
    s1.score = 99;
    cout << "name == " << s1.name << ",age == " << s1.age << ",score == " << s1.score << endl;

    struct Student s2 = {"李四", 10, 30};
    cout << "name == " << s2.name << ",age == " << s2.age << ",score == " << s2.score << endl;

    s3.name = "wang";
    s3.score = 30;
    s3.age = 25;
    cout << "name == " << s3.name << ",age == " << s3.age << ",score == " << s3.score << endl;

    /*name == 张三,age == 187,score == 99
    name == 李四,age == 10,score == 30
    name == wang,age == 25,score == 30*/

    return 0;
}

/**
 * 将自定义的结构放到数组中方便维护
 * struct 结构体名 数组名[元素个数] = { {}，{}...{}}
 */
int main92() {

    struct Student structStudentArray[3] = {
            {"张三", 10, 30},
            {"李四", 10, 30},
            {"王五", 10, 30}
    };

    //给结构体中的元素副职
    structStudentArray[2].age = 80;
    structStudentArray[2].score = 90;

    //遍历结构体数组
    for (int i = 0; i < 3; ++i) {
        cout << "name == " << structStudentArray[i].name << ",age == "
             << structStudentArray[i].age << ",score == " << structStudentArray[i].score << endl;
    }

    return 0;
}

/**
 * 结构体指针
 * struct可以省略
 * 通过结构体指针访问结构体数据用符号“->”
 */
int main93() {

    struct Student s1 = {"张三", 10, 30};

    //通过指针指向结构体变量
    struct Student *p = &s1;

    //通过指针访问结构体数据
    cout << "name == " << (p->name) << ",age == "
         << (p->age) << ",score == " << (p->score) << endl;

    //    name == 张三,age == 10,score == 30

    return 0;
}

/**
 * 结构体中可以嵌套结构体
 * 结构体中的成员变量可以是结构体
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
    t.name = "坏老师";
    t.student.name = "小四";
    t.student.score = 30;
    t.student.age = 20;

    cout << "teacher name == " << t.name << ",age == " << t.age << ",id == " << t.id << endl;
    cout << "student name == " << t.student.name << ",age == " << t.student.age << ",score == " << t.student.score
         << endl;

    /*teacher name == 坏老师,age == 20,id == 1001
    student name == 小四,age == 20,score == 30*/

    return 0;
}

/**
 * 将结构体作为参数传递给函数
 * 1.值传递
 * 2.地址传递
 */
void printStudent1(Student *pStudent) {

    pStudent->age = 200;

    cout << "printStudent1 name == " << pStudent->name << ",age == " << pStudent->age << ",score == " << pStudent->score
         << endl;
    //如果不想修改主函数中的值，则使用值传递，反之，使用地址传递
    /* main name == 张三,age == 10,score == 85
     printStudent name == 张三,age == 100,score == 85
     printStudent1 name == 张三,age == 200,score == 85

     printStudent1 name == 张三,age == 200,score == 85
     main name == 张三,age == 200,score == 85

     */

}


int main95() {

    struct Student student = {"张三", 10, 85};


    printStudent(student);
    printStudent1(&student);

    cout << "main name == " << student.name << ",age == " << student.age << ",score == " << student.score << endl;

    /*main name == 张三,age == 10,score == 85
    printStudent name == 张三,age == 10,score == 85
    printStudent1 name == 张三,age == 10,score == 85*/

    return 0;
}

//值传递
void printStudent(struct Student student) {
    student.age = 100;
    cout << "printStudent name == " << student.name << ",age == " << student.age << ",score == " << student.score
         << endl;
}


/**
 * 使用const来防止误操作,改值的时候就不会报错
 * 将形参改为指针，可以减少内存空间，而且不会赋值新的版本出来
 */
void printStudentConst(const struct Student *pStudent) {
    //pStudent->name = "小王";
    //    cout << "printStudentConst name == " << student.name << ",age == " << student.age << ",score == " << student.score
    //         << endl;

    //    pStudent->name = "小王"; 不可以修改
    cout << "printStudent1 name == " << pStudent->name << ",age == " << pStudent->age << ",score == " << pStudent->score
         << endl;
}


int main96() {

    struct Student student = {"张三", 10, 85};

    printStudentConst(&student);

    return 0;
}

struct Teacher1 {
    string name;
    struct Student studentArray[5];
};

void printInfo(Teacher1 pTeacher1[3], int len);



void createTeacherSpace(struct Teacher1 tArray[], int len) {
    string name = "abcde";//给老师赋值
    string nameSeed = "abcde";//给老师赋值
    for (int i = 0; i < len; ++i) {
        tArray[i].name = "Teacher_";
        tArray[i].name += name[i];

        for (int j = 0; j < 5; ++j) {
            tArray[i].studentArray[j].name = "Student_";
            tArray[i].studentArray[j].name += nameSeed[j];

            int random = rand() % 61 + 40; //随机数

            tArray[i].studentArray[j].score = random;
        }
    }

}

/**
 * 结构体案例1: 一个老师带5个学生 * 3
 */
int main97() {

    srand((unsigned int) time(NULL));//随机数中子

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
 * 结构体案例2: 英雄按年龄升序排序
 */
int main98() {

    struct Hero hero[5] = {{"张飞",  36, "男"},
                           {"张飞1", 48, "男"},
                           {"张飞2", 26, "男"},
                           {"张飞3", 53, "男"},
                           {"张飞4", 36, "女"}};

    int len = sizeof(hero) / sizeof(hero[0]);

    bubboHeroSort(hero,len);

    for (int i = 0; i <len ; ++i) {
        cout << "student name == " << hero[i].name << "student age == " << hero[i].age
             << " gender == " << hero[i].gender << endl;
    }

   /* student name == 张飞2student age == 26 gender == 男
    student name == 张飞2student age == 26 gender == 男
    student name == 张飞2student age == 26 gender == 男
    student name == 张飞4student age == 36 gender == 女
    student name == 张飞4student age == 36 gender == 女*/

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
