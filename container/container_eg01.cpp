//
// Created by Administrator on 2019/10/18.
//

# include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

/**
 * 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
 *
 */
class Container01Person {
public:

    Container01Person(const string &name, int score) : _name(name), _score(score) {}

    string _name;
    int _score;
};


//          创建五名选手，放到vector中
//        遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//        sort算法对deque容器中分数排序，去除最高和最低分
//        deque容器遍历一遍，累加总分
//        获取平均分
void createPersonContainer(vector<Container01Person> &v) {
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++){

        string name ="chooser_";
        name += nameSeed[i];
        int score = 0;

        Container01Person person(name,score);
        //将创建的person对象 放入到容器中
        v.push_back(person);
    }

}
void setScore(vector<Container01Person> &v) {
    for (vector<Container01Person>::iterator it = v.begin(); it != v.end(); it++) {

        deque<int> d;
        for (int i = 0; i <10 ; ++i) {

            int score = rand() % 41 +60;
            d.push_back(score);

        }
        //排序
        sort(d.begin(), d.end());

        //去除最高和最低分
        d.pop_back();
        d.pop_front();

        //取平均分
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit; //累加每个评委的分数
        }

        int avg = sum / d.size();

        //将平均分 赋值给选手身上
        it->_score = avg;
    }

}

void showScore(vector<Container01Person>&v)
{
    for (vector<Container01Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "name: " << it->_name << " , score: " << it->_score << endl;
    }
}

int main(){
    //随机数种子
    srand((unsigned int)time(NULL));

    //1、创建5名选手
    vector<Container01Person>v;  //存放选手容器
    createPersonContainer(v);

    //测试
    //for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    //{
    //	cout << "姓名： " << (*it).m_Name << " 分数： " << (*it).m_Score << endl;
    //}

    //2、给5名选手打分
    setScore(v);

    //3、显示最后得分
    showScore(v);

    system("pause");

//    name: chooser_A , score: 77
//    name: chooser_B , score: 78
//    name: chooser_C , score: 79
//    name: chooser_D , score: 85
//    name: chooser_E , score: 78
    return  0;
}