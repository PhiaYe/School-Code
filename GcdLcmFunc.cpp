//Your #includes here; make sure you are allowed them ..
#include <iostream>
#include <stdlib.h>

//#includes and function declarations; do not remove

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int greatestCommonDenominator(const int, const int);
int leastCommonMultiple(const int, const int);
#endif

//
// Your code here ...
//

int greatestCommonDenominator(const int a, const int b) {

  if (a<=0){
    return -1;
  }

  if (b<=0){
    return -1;
  }

  int _a = a;
  int _b = b;
  int _gcd = 1;
  int maybe = a;


  while (maybe > 0){
    if ((_a % maybe == 0) && (_b % maybe == 0)){
      _gcd = maybe;
      break;
    }
    maybe--;
  }

  return _gcd;
}

int leastCommonMultiple (const int a, const int b) {

  if (a<=0){
    return -1;
  }

  if (b<=0){
    return -1;
  }

  int _a = a;
  int _b = b;
  int _gcd = 1;
  int maybe = a;
  int _lcm = 1;

  while (maybe > 0){
    if ((_a % maybe == 0) && (_b % maybe == 0)){
      _gcd = maybe;
      break;
    }
    maybe--;
  }

  _lcm = (_a/_gcd)*_b;

  return _lcm;

}

//
//Test Driver
//

//Do not remove the #ifndef and its associated #endif

// This is required so that when you submit your code,

// this test driver will be ignored by Marmoset

//

#ifndef MARMOSET_TESTING


int main(const int argc, const char* const argv[]) {

  if (argc < 3) {
  cerr << "Error: Usage: " << argv[0] << "<num1> <num2>; exiting" << endl;
  return -1;
  }

int gcd = greatestCommonDenominator(atoi(argv[1]),atoi(argv[2]));

if (gcd < 0){
cerr << "Unable to compute GCD(" << argv[1] << "," << argv[2] << ")" << endl;
}

else{
cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;
}

int lcm = leastCommonMultiple(atoi(argv[1]),atoi(argv[2]));


if (lcm < 0)
{
  cerr << "Unable to compute LCM(" << argv[1] << "," << argv[2] << ")" << endl;
  }

else
{
cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;
}

return 0;

}

#endif
