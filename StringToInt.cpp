//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

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

bool stringToInt(const char input[], int& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool stringToInt(const char input[], int& value) {
  // acts as atoi operator
  // ascii table: numbers from 48 to 57
  // return result of converting input into int as value
  // valid inputs: no whitespace, no letters, only digits, leading sign (+ or -), has to fit within valid range of an int
  // if conversion is successful - return true - else return false - don't need to set value to a number

  int i = 0;

  if (input[0] == '+' || input[0] == '-') // input[i] is a sign "+" or "-"
    i = 1;

  while (input[i] != 0){

    if (input[i] < '0' || input[i] > '9'){
        return false;
    }
    value *= 10;
    value += input[i] - '0'; // '0' pulls the ASCII value for 0 so 48
    i++;
  }

  if (value < 0)
    return false;

  if (input[0] == '-')
    value = -value;

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
  int argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <int>" << endl;
    return -1;
  }

  if (stringToInt(argv[1],argv1))
    cout << "argv[1] is an int with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not an int." << endl;
  return 0;
}

#endif
