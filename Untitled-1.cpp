#include <iostream>
using namespace std;
#include <cstring>
#include "circle.h"
#include"point.h"

#include"point.cpp"
#include"circle.cpp"

/* class point 
{
  public:
  void setx(int x){
    m_x=x;
  }
  int getx(){
    return m_x;
  }
  void sety(int y){
    m_y=y;
  }
  int gety(){
    return m_y;
  }
  private:
  int m_x;
  int m_y;
};

class circle{
public:
void setr(int r){
  m_r=r;
}
int getr(){
  return m_r;
}
void setcenter(point center){
  m_center=center;
}
point getcenter(){
return m_center;
}
private:
int m_r;
point m_center;
};
 */
void isincircle(circle &c,point &p){
  int distance=((c.getcenter().getx()-p.getx())*(c.getcenter().getx()-p.getx())+
  (c.getcenter().gety()-p.gety())*(c.getcenter().gety()-p.gety()));
  int rdistance =c.getr()*c.getr();

  if(distance == rdistance){
    cout<<"on"<<endl;
  }else if(distance<rdistance){
    cout<<"in"<<endl;
  }else if(distance>rdistance)
    cout<<"out"<<endl;
}
int main(){

  circle c;
  c.setr(10);
  point center;
  center.setx(10);
  center.sety(0);

  c.setcenter(center);

  point p;
  p.setx(10);
  p.sety(10);

  isincircle(c,p);
  return 0;
}