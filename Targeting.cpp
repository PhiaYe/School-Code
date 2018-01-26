//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
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

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b,
							 const float w, float& theta);

bool hitTargetGivenAngle (const float h, const float m, const float theta,
							const float d, const float t, const float b,
							const float w, float& v);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b,
							 const float w, float& theta) {

	if ( h < 0 || v <= 0 || m <= 0 || d < 0 || b < 0 || w < 0)
		return false;

	float g = 9.8;
	//quadratic will give 2 different values
	float x1; //addition
	float x2; //substraction

		x1 = (-d + sqrt(d*d + (2*g*d*d/(v*v))*(-g*d*d/(2*v*v) + h - t) ))/(-g*d*d/(v*v));
		x2 = (-d + sqrt(d*d - (2*g*d*d/(v*v))*(-g*d*d/(2*v*v) + h - t) ))/(-g*d*d/(v*v));

	float theta1;
	float theta2;

	theta1 = atan(x1) * 180/3.14159;
	//cout << "theta1: " << theta1 << endl;
	theta2 = atan(x2) * 180/3.14159;
	//cout << "theta2: " << theta2 << endl;

	if (theta1 < 270 && theta1 > -90)
		theta = theta1;
	else
		theta = theta2;

	if (theta == 90)
		return false;

	//cout << "theta:" << theta << endl;

	return true;
}

bool hitTargetGivenAngle (const float h, const float m, const float theta,
							const float d, const float t, const float b,
							const float w, float& v) {

	if( h < 0 || m <= 0 || theta > 270 || theta < -90 || d < 0 || b < 0 || w < 0)
		return false;

	float g = 9.8;
	float thetaReal = theta * 3.14159 / 180;

	if (t > 0)
		v = sqrt((g*d*d)/((2*cos(thetaReal)*cos(thetaReal))*(d*tan(thetaReal) + h - t)));

	else
		v = sqrt((g*d*d)/((2*cos(thetaReal)*cos(thetaReal))*(d*tan(thetaReal) + h + t)));

	return true;
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

  float theta = 45; // Angle in degrees;
  float v = 25;

  cout << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity\n\n";
  }

  cout << "Given initial velocity: " << v << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenVelocity (h, v, m, d, t, b, w, theta)) {
    cout << "required angle: " << theta << endl << endl;
  }
  else {
    cout << "cannot calculate the angle\n\n";
  }

  return 0;
}
#endif
