//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
// You are allowed float.h
#include <math.h>
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

bool stringToFloat(const char input[], float& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...

bool stringToFloat(const char input[], float& value) {
  int i = 0;
  int signExponent = 0; //index storing i if exponent is negative
  float value1 = 0;
  float value2 = 0;
  float value3 = 0;

  if (input[0] == '+' || input[0] == '-'){
    i = 1;
  }

  //    VALUE 1
  while (input[i] != '.' || input[i] != 'e' || input[i] != 'E' || input[i] != 0){

    if (input[i] >= '0' || input[i] <= '9'){
      value1 *= 10;
      value1 += input[i] - '0';
      i++;
      cout << "value1  " << value1 << endl;
    }

    if ((input[i] < '0' || input[i] > '9') && (input[i] != 'e' || input[i] != 'E') && (input[i] != '.') && (input != 0)){
      cout << "false" << endl;
      return false;
    }

  }//end of while loop1

//    VALUE 2
  if (input[i] == '.'){
    i++;
    int indexDec = -1;

    while (input[i] != 'e' || input[i] != 'E' || input[i] != 0){

      if (input[i] >= '0' || input[i] <= '9'){
          value2 += (input[i] - '0')/(pow(10,indexDec));
          indexDec--;
          i++;
      }

      if ((input[i] < '0' || input[i] > '9') && (input[i] != 'e' || input[i] != 'E') && (input != 0)){
        return false;
      }
    }//end of while != 'e'
  }//end of if '.'

  cout << "value2  " << value2 << endl;

//    VALUE 3
  if (input[i] == 'e' || input[i] == 'E'){
    i++;

    if (input[i] == '+' || input[i] == '-')
      int signExponent = i;
      i++;

    while (input[i] != 0){
      if(input[i] >= '0' || input[i] <= '9'){
        value3 *= 10;
        value3 += input[i] - '0';
        i++;
      }

      if((input[i] < '0' || input[i] > '9') && (input != 0))
        return false;

    }//end while != 0

  }//end if 'e'

  cout << "value3  " << value3 << endl;

  if (input[0] == '-'){
    value1 = -value1;
  }

  if (input[signExponent] == '-'){
    value3 = -value3;
  }

  value = (value1 + value2) * pow(10,value3);
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
int main(const int argc, const char* const argv[]) {

  // Some test driver code here ....
  float argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <float>" << endl;
    return -1;
  }

  if (stringToFloat(argv[1],argv1))
    cout << "argv[1] is a float with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not a float. argv[1]: " <<argv[1] << endl;
  return 0;
}

#endif
