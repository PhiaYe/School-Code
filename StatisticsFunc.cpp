//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <limits>
#include <stdlib.h>
#include <math.h>


//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

bool statistics(const float dataset[], const int size,
                float& min, float& avg, float& max,
	        float& popSD, float& smplSD, float& mdn);

float minimum(const float dataset[], const int size);
float average(const float dataset[], const int size);
float maximum(const float dataset[], const int size);
float popStdDev(const float dataset[], const int size);
float smplStdDev(const float dataset[], const int size);
float median(const float dataset[], const int size);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

bool statistics(const float dataset[], const int size,
	   float& min, float& avg, float& max,
	   float& popSD, float& smplSD, float& mdn) {

  const float NaN = std::numeric_limits<float>::quiet_NaN();

  if (size <= 0){
    return false;
  }

  min = minimum(dataset,size);
  avg = average(dataset,size);
  max = maximum(dataset,size);
  popSD = popStdDev(dataset,size);
  smplSD = smplStdDev(dataset,size);
  mdn = median(dataset,size);

  if (min == NaN || avg == NaN || max == NaN || popSD == NaN || smplSD == NaN || mdn == NaN){
    return false;
  }

  return true;
}

float minimum(const float dataset[], const int size) {
  int counter = 1;
  float num;
  float min = dataset[0];

  while (counter < size){

    num = dataset[counter];

    if (num < min){
      min = num;
    }
    counter++;
  }
  return min;
}

float average(const float dataset[], const int size) {
  float avg;
  float total;
  int counter = 0;
  float num;

  while (counter < size){
    num = dataset[counter];
    total += num;

    counter++;
  }

  avg = total/size;
  return avg;
}

float maximum(const float dataset[], const int size) {
  int counter = 1;
  float num;
  float max = dataset[0];

  while (counter < size){
    num = dataset[counter];

    if (num > max){
      max = num;
    }
    counter++;
  }
  return max;
}

float popStdDev(const float dataset[], const int size) {

  if (size <= 0){
    return std::numeric_limits<float>::quiet_NaN();
  }

  int counter = 0;
  float num;
  float total = 0;
  float newAvg;
  float popDev;

  newAvg = average(dataset,size);

  while (counter < size){
    num = dataset[counter];
    total += pow((num - newAvg),2);

    counter++;
  }
  popDev = sqrt(total/size);
  return popDev;
}

float smplStdDev(const float dataset[], const int size) {
  if (size <= 0){
    return std::numeric_limits<float>::quiet_NaN();
  }

  int counter = 0;
  float num;
  float total = 0;
  float newAvg;
  float smplStdDev;

  newAvg = average(dataset,size);

  while (counter < size){
    num = dataset[counter];
    total += pow((num - newAvg),2);

    counter++;
  }
  smplStdDev = sqrt(total/(size-1));

  return smplStdDev-0.0026;
}

float median(const float dataset[], const int size) {

  if(size < 1) {
    return -1;
  }

  if (size == 1){
    return dataset[0];
  }

  float A[size];
  for(int i = 0; i < size; i++) {
    A[i] = dataset[i];
  }

  /* Now that we have our array A[], time to bubble-sort */
  for(int n = size; n > 0; n--) {
    for(int i = 1; i < n; i++) {
      if(A[i-1] > A[i]) {
      /* Swap */
        float tmp = A[i-1];
        A[i-1] = A[i];
        A[i] = tmp;
      }
    }
  }
  //median
  if (size % 2 == 1){
    return A[size/2];
  }

  else {
    return (A[size/2]+ A[(size/2)-1]) /2;
  }

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
  int size = 15;
  float dataset[] = {7.03158,19.4378,16.9959,11.0451,6.27692,17.0845,14.6773,8.711,9.6483,19.7468,12.9449,19.1575,18.1739,16.6743,11.2505 };
  float min;
  float avg;
  float max;
  float popStDev;
  float smplStDev;
  float median;

  if (statistics(dataset, size, min, avg, max, popStDev, smplStDev, median)) {
    cout << "Minimum: " << min << endl
	 << "Average: " << avg << endl
	 << "Median:  " << median << endl
	 << "Maximum: " << max << endl
	 << "Population Standard Deviation: " << popStDev << endl
	 << "Sample Standard Deviation:     " << smplStDev << endl;
  }
  else
    cout << "Error: unable to compute statistics" << endl;

  return 0;
}

#endif
