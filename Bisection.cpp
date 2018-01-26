//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return 3.2*x*x -2.1*x -23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize,
		      int counter);
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize,
		      int counter){

  //just for testing
  //cout << left <<  "  LEFT   ";
  //cout << right << "  RIGHT   ";
  //cout << f(left) << " F(LEFT)   ";
  //cout << f(right) << "   F(RIGHT)   " << endl;

  //error for invalid parameters
  /*
  if left > right
  if f(left)*f(right) >= 0
  */

  //terminating condition with counter if does not fulfill condition for minIntervalSize or precision
  //cout << counter << "  counter";
  if (counter == 1000 || f(left)!= f(left) || f(right) != f(right))
    return std::numeric_limits<float>::quiet_NaN();

  if (left > right || f(left)*f(right) >= 0)
  {
    //cout <<"... " << endl
    return std::numeric_limits<float>::quiet_NaN();
  }

  float l = left;
  float r = right;
  float p = precision;
  float interval = minIntervalSize;

  float midpoint = (l + r)/2; //determine midpoint;

  if (fabs(f(midpoint)) <= p)
    return midpoint;

  if (fabs(r - l) < interval)
    return midpoint;

  float slope = (f(r)-f(l))/(r-l);
  //cout << slope << "   slope   ";
  //cout << midpoint << "   midpoint   ";
  //cout << f(midpoint) << "  f(midpoint)  ";

  //calculating root
  if (slope > 0){
    if (f(midpoint) > 0){
      //r = midpoint;
      return bisectionHelper(l, midpoint, p, interval, counter+1);
    }
    else{
      //l = midpoint;
      return bisectionHelper(midpoint, r, p, interval, counter+1);
    }
  }

  //slope < 0
  else{
    if (f(midpoint) > 0){
      //r = midpoint;
      return bisectionHelper(midpoint, r, p, interval, counter+1);
    }
    else{
      //l = midpoint;
      return bisectionHelper(l, midpoint, p, interval, counter+1);
    }
  }

  /*if ((f(midpoint) is precise enough) OR (interval is less than minIntervalSize))
    return midpoint;
  if(midpoint replaces left)
    bisection(midpoint, right, precision, minIntervalSize, counter+1);
  else
    bisection(left, midpoint, precision, minIntervalSize, counter+1);
  */
}

float bisection(const float left, const float right,
		const float precision, const float minIntervalSize) {

    if ((precision <= 0) || (minIntervalSize <= 0) || (left > right) ){
      return std::numeric_limits<float>::quiet_NaN();
    }
    //invoke bisectionHelper with extra parameters
    return bisectionHelper(left, right, precision, minIntervalSize, 0);
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
float left = -10;
float right = 0;
float precision = 0.01;
float minIntervalSize = 0.01;

  cout << bisection(left, right, precision, minIntervalSize);

  return 0;
}

#endif
