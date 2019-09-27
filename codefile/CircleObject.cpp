//
// Created by Administrator on 2019/9/27.
//

#include "../headerfile/CircleObject.h"
//类:: 方法名 表示某个类的作用域下
int CircleObject::getMR() const {
    return m_r;
}

void CircleObject::setMR(int mR) {
    m_r = mR;
}

const PointObject & CircleObject::getMPoint() const {
    return m_point;
}

void CircleObject::setMPoint(const PointObject &mPoint) {
    m_point = mPoint;
}