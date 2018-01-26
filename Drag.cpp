//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

#define NaN std::numeric_limits<float>::quiet_NaN()
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove

bool hitTargetGivenAngle (const float h, const float m, const float theta,
              const float d, const float step, const float k,
              const float t, const float b, const float w, float& v);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

bool hitTargetGivenAngle (const float h, const float m, const float theta,
							const float d, const float step, const float k,
              const float t, const float b, const float w, float& v) {

								if( h < 0 || m <= 0 || theta > 270 || theta < -90 || d < 0 || b < 0 || w < 0)
									return false;

								float g = 9.8;
								float thetaReal = theta * 3.14159 / 180;

								if (t > 0)
									v = sqrt((g*d*d)/((2*cos(thetaReal)*cos(thetaReal))*(d*tan(thetaReal) + h - t)));

								else
									v = sqrt((g*d*d)/((2*cos(thetaReal)*cos(thetaReal))*(d*tan(thetaReal) + h + t)));

								return true;



  //Using bisection to find the velocity at which it will hit the target given a certain Angle
  //float left = 0;
  //float right = 1000;
  thetaRad = theta * 3.14159 / 180;
  deltaX = 0; 
  newDeltaX = 0;
  deltaT = 0;
  while (newDeltaX != -h+t){
    //discrete-time simulation
    newDeltaX = deltaX + v*deltaT;

  }


}


#ifndef MARMOSET_TESTING
int main() {

  // Some test driver code here ....
  float h = 50;
  float d = 60;
  float b = 40;
  float t = 30;
  float w = 30;
  float m = 1;
  float step = 0.01;
  float k = 0.5;
  float theta = 45; // Angle in degrees;
  float v = 25;

  cout << endl << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, step, k, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity" << endl << endl;
  }

  return 0;
}
#endif
