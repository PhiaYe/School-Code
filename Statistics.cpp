#include<iostream>
#include<stdlib.h>
using namespace std;

int main(const int argc, const char* const argv[]){

if (argc < 2){
cerr << "Error: Unable to compute statistics over data set due to insufficient arguments." << endl;
}

int counter = 1;
float num;
float total = 0;
float max = atof(argv[1]);
float min = atof(argv[1]);

while (counter < argc){

num = atof(argv[counter]);
total += num;

if (num < min){
min = num;
}

if (num > max){
max = num;
}

counter++;
}

cout << "Number of floating-point numbers: " << argc - 1 << endl;
cout << "Minimum floating-point number: " << min << endl;
cout << "Average floating-point number: " << total/(argc-1) << endl;
cout << "Maximum floating-point number: " << max << endl;

return 0;
}
