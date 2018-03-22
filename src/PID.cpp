#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  Kp_coeff=Kp;
  Ki_coeff=Ki;
  Kd_coeff=Kd;
  d_error = 0;
  p_error = 0;
  i_error = 0;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::Get_Update() {
  return - d_error * Kd_coeff - p_error * Kp_coeff - i_error * Ki_coeff;
}

double PID::TotalError() {
}

