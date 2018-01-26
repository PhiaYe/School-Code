#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;

int main(const int argc, const char* const argv[]){

if(argc < 2){
cerr << "Error: insufficient arguments." << endl;
}

int counter = 1;
float num;
float total = 0;

float max = atof(argv[1]);
float min = atof(argv[1]);

cout << setw(10) << "Sample" << setw(10) << "Value" << setw(10) << "Minimum" << setw(10) << "Average" << setw(10) << "Maximum" << endl;

while (counter < argc){

num = atof(argv[counter]);
total += num;

if (num < min){
min = num;
}

if (num > max){
max = num;
}

cout << setw(10) << counter << setw(10) << num << setw(10) << min << setw(10) << (total/counter) << setw(10) << max << endl;

counter++;

}

}
