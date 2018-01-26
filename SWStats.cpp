#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

int main(const int argc, const char* const argv[]){

if(argc < 3){
cerr << "Error: insufficient arguments." << endl;
return -1;
}

if (atof(argv[1]) <= 0){
cerr << "Error: Window size cannot be non-positive." << endl;
return -1;
}

if (atof(argv[1]) == 1){
cerr << "Warning: Window size cannot be 1." << endl;
return -1;
}

if (atof(argv[1]) > (argc - 2) ){
cerr << "Warning: Window cannot be larger than the number of inputs." << endl;
}

int counter = 1;
float num;
float total = 0;

float max = atof(argv[2]);
float min = atof(argv[2]);
//float alpha = atof(argv[1]);

float oldAvg = atof(argv[2]);
float newAvg = 0;

//int age = atoi(argv[2]);
//int j = 0;

//int i = 0;

cout << "Window Size: " << argv[1] << endl;
cout << setw(10) << "Sample" << setw(10) << "Value" << setw(10) << "SWMinimum" << setw(10) << "SWAverage" << setw(10) << "SWMaximum" << endl;

while ((counter + 1) < argc){

num = atof(argv[counter+1]);
total += num;

if (num < min){
min = num;
//j = 0;
}

if (num > max){
max = num;
//i = 0;
}

//newAvg = (alpha * num) + ((1 - alpha) * oldAvg);
newAvg = (total)/counter;
oldAvg = newAvg;


//if (i == age){
//max = num;
//i = 1;
//}

//if (j == age){
//min = num;
//j = 1;
//}

//i++;
//j++;

cout << setw(10) << counter << setw(10) << num << setw(10) << min << setw(10) << newAvg << setw(10) << max << endl;

counter++;

}

return 0;

}
