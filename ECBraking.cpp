//Error Check Braking
//Check 5 conditions
// 1) v==0          no crash
// 2) v>0 && x>0
// 3) v>0 && x<0    no crash
// 4) v<0 && x>0    no crash
// 5) v<0 && x<0    same as (2)
// 6) a==0

#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(const int argc, const char* const argv[]){

if (argc < 4){
cerr << "Error: Insufficient arguments; expecting three arguments" << endl;
return -1;
}

else if (atof(argv[3]) < 0){
cerr << "Error: Maximum acceptable rate of deceleration should be positive. " << endl;
return -1;
}

else if (argc > 4){
cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
}

float v = atof(argv[1]);
float x = atof(argv[2]);
float a = atof(argv[3]);
// where 'a' is the maximum acceptable rate of deceleration

float aMin = fabs(-(v * v) / (2 * x));
// where minAcc is the minimum acceleration to avoid a collision
float tMax = fabs(2 * x / v);
// where tMax is the maximum stopping time to avoid a collision
float tCrash;
float vCrash;

//no crash
if (v == 0){
cout << "There is no possibility of collision because the car is not in motion." << endl;
}

else if ((v>0 && x>0) || ( v<0 && x<0 )){

//no crash
if (aMin < a){
cout << "Initial car velocity: " << v << "m/s" << endl;
cout << "Distance to obstacle: " << x << "m" << endl;
cout << "Minimum deceleration: " << aMin << "m/s/s" << endl;
cout << "Maximum stopping time: " << tMax << "s" << endl;
}

//crash
if (aMin > a){

if (v < 0){
vCrash = sqrt(pow(v,2) + (2*a*x));
}
else{
vCrash = sqrt(pow(v,2) - (2*a*x));
}

tCrash = fabs(((vCrash - fabs(v))/ a));

cout << "Crash will occur in " << tCrash << " seconds at velocity " << vCrash << " m/s; deploying airbags." << endl;

}
}
//no crash
else if ((v>0 && x<0) || (v<0 && x>0)){
cout << "There is no possibility of collision because the car is driving away from the truck." << endl;
}

return 0;
}
