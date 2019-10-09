//
// Created by Administrator on 2019/10/9.
//

#ifndef CBUTY_TEMPLATEPERSON2_H
#define CBUTY_TEMPLATEPERSON2_H

#pragma once //防止头文件重复包含

# include <iostream>
#include <string>

using  namespace std;
template<class NameType, class AgeType >
class TemplatePerson2 {
public:

    TemplatePerson2(NameType name, AgeType age) ;

    NameType _name;
    AgeType _age;


    void showInfo();

};


#endif //CBUTY_TEMPLATEPERSON2_H
