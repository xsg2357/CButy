//
// Created by Administrator on 2019/9/27.
//

#ifndef CBUTY_CIRCLEOBJECT_H
#define CBUTY_CIRCLEOBJECT_H


#include "PointObject.h"

class CircleObject {

private:
    int m_r;
    PointObject m_point;//圆心 一个类可以作为另一个类的成员变量
public:
    int getMR() const;

    void setMR(int mR);

    const PointObject &getMPoint() const;

    void setMPoint(const PointObject &mPoint);

};


#endif //CBUTY_CIRCLEOBJECT_H
