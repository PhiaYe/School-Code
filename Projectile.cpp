//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {

  //all variables are given except destX and destY
  //given d and t, but we don't know where projectile actually lands
  //depends on velocity and angle theta
  //find the destination where it lands even if it doesn't land on target
  //find vertical displacement, use that to find horizontal displacement with time being a common variable
  //if displacement matches with given target then return true

  if (w < 0 || h < 0 || theta < -90 ||  theta > 270 || m <= 0 || v < 0 || t < 0 || b < 0)
    return false;

  //assume there is no target
  float g = 9.8;
  float newTheta = theta*3.14159/180; //change from degrees to radians

  if (theta == 90 || v == 0){
    destX = 0;
    destY = h;
  }

  else{
    //using vertical displacement
    float time1 = (-v*sin(newTheta) + sqrt(v*v*sin(newTheta)*sin(newTheta) + 2*g*h))/(-g); //quadratic rule for positive
    float time2 = (-v*sin(newTheta) - sqrt(v*v*sin(newTheta)*sin(newTheta) + 2*g*h))/(-g); //quadratic rule for negative
    float timeReal;

    if (time1 > 0 )
      timeReal = time1;
    else
      timeReal = time2;

    destX = v*cos(newTheta)*timeReal;
    destY = v*sin(newTheta)*timeReal - g*timeReal*timeReal/2;

    //check different conditions for whether hits target
    //condition for whether hits wall of target

    if (destX < b)
      destY = 0;

    if (destX >= b){
      float timeWall = b/(v*cos(newTheta));
      float timeOver = (b+w)/(v*cos(newTheta));
      float hWall = (h + v*sin(newTheta)*timeWall + (-g/2) * (timeWall*timeWall));
      float hPass = (h + v*sin(newTheta)*timeOver + (-g/2) * (timeWall*timeOver));

      if (hWall <= t){
        destX = b;
        destY = hWall;
      }

      if (hWall > t && hPass < t){
        float timeTarget1 = (-v*sin(newTheta) + sqrt(v*v*sin(newTheta)*sin(newTheta) + 2*g*(h-t)))/(-g);
        float timeTarget2 = (-v*sin(newTheta) - sqrt(v*v*sin(newTheta)*sin(newTheta) + 2*g*(h-t)))/(-g);
        float timeTarget;

        if (timeTarget1 > 0)
          timeTarget = timeTarget1;
        else
          timeTarget = timeTarget2;

        destY = t;
        destX = v*cos(newTheta)*timeTarget;
      }

      if (hWall > t && hPass > t){
        destY = 0;
      }

    }

  }

  return true;
}

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....

  float h = 10;
  float v = 10;
  float m = 10;
  float theta = 45;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 5;
  float b = 97;
  float w = 5;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
