#pragma once
#include <iostream>
using namespace std;
#include"point.h"

class circle{
    public:
    void setr(int r);
    
    int getr();
    
    void setcenter(point center);
    point getcenter();
    private:
    int m_r;
    point m_center;
    };