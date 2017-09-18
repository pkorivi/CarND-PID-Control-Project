#include "PID.h"
#include <iostream>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

void PID::UpdateError(double cte) {
  /*if(this->prev_cte == 0xffff){
    this->prev_cte = cte;
  }*/
  this->p_error = cte;
  this->i_error += cte;
  this->d_error =  cte - this->prev_cte;
  this->prev_cte = cte;
  //cout<<"update error"<<this->p_error<<" "<<this->i_error<<this->d_error<<endl;
}

double PID::TotalError() {
  //cout<<"total_Error"<<this->Kp<<" "<<this->p_error<<" "<<this->Ki<<" "<<this->i_error<<" "<<this->Kd<<" "<<this->d_error<<endl;
  return (this->Kp*this->p_error) + (this->Ki*this->i_error) \
   + (this->Kd*this->d_error);//p_error + i_error + d_error; //
}
