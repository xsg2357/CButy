//
// Created by Administrator on 2019/10/9.
//

#include "../headerfile/TemplatePerson2.h"
template<class NameType, class AgeType >
TemplatePerson2<NameType,AgeType>::TemplatePerson2(NameType name, AgeType age){
    this->_name = name;
    this->_age = age;
}

template<class NameType, class AgeType >
void TemplatePerson2<NameType,AgeType>::showInfo() {
    cout << "name=" << this->_name << ",age=" << this->_age << endl;
}