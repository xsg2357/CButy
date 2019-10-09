#pragma once //防止头文件重复包含

# include <iostream>
#include <string>

using namespace std;

template<class NameType, class AgeType>
class TemplatePerson3 {
public:

    TemplatePerson3(NameType name, AgeType age);

    NameType _name;
    AgeType _age;

    void showInfo();

};

template<class NameType, class AgeType>
TemplatePerson3<NameType, AgeType>::TemplatePerson3(NameType name, AgeType age) {
    this->_name = name;
    this->_age = age;
}

template<class NameType, class AgeType>
void TemplatePerson3<NameType, AgeType>::showInfo() {
    cout << "name=" << this->_name << ",age=" << this->_age << endl;
}