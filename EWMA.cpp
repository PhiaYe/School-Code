#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

int main(const int argc, const char* const argv[]){

if(argc < 4){
cerr << "Error: insufficient arguments." << endl;
}

int counter = 3;
float num;
float total = 0;

float max = atof(argv[3]);
float min = atof(argv[3]);
float alpha = atof(argv[1]);

float oldAvg = atof(argv[3]);
float newAvg = 0;

int age = atoi(argv[2]);
int j = 0;

int i = 0;

cout << setw(10) << "Sample" << setw(10) << "Value" << setw(10) << "Minimum" << setw(10) << "EWMA" << setw(10) << "Maximum" << endl;

while (counter < argc){

num = atof(argv[counter]);
total += num;

if (num < min){
min = num;
j = 0;
}

if (num > max){
max = num;
i = 0;
}

newAvg = (alpha * num) + ((1 - alpha) * oldAvg);
oldAvg = newAvg;


if (i == age){
max = num;
i = 1;
}

if (j == age){
min = num;
j = 1;
}

i++;
j++;

cout << setw(10) << counter << setw(10) << num << setw(10) << min << setw(10) << newAvg << setw(10) << max << endl;

counter++;

}

return 0;

}
