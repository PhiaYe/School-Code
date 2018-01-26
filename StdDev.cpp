#include<iostream>
#include<stdlib.h>
#include<math.h>
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
float avg;

//variables for newAvg
int thirdCounter = 1;
float input;
float newAvg;
float realTot;

//new
float temp;
float popDev;
float sampleDev;
float epsilon;

while(thirdCounter < argc){
input = atof(argv[thirdCounter]);
realTot += input;
thirdCounter++;
}
newAvg = realTot/(argc-1);

while (counter < argc){
temp = counter;
num = atof(argv[counter]);
total += num;

if (num < min){
min = num;
}

if (num > max){
max = num;
}

avg = total/(argc-1);

counter++;
}

counter = 1;

while (counter < argc){
temp = counter;
epsilon += pow((num - newAvg),2);
cout << epsilon;

popDev = sqrt((1/temp) * epsilon);
cout << "pop Dev: " << popDev << endl;

sampleDev = sqrt((1 / (temp - 1)) * epsilon);
cout << "sampleDev: "<< sampleDev << endl;

counter++;
}

cout << "Number of floating-point numbers: " << argc - 1 << endl;
cout << "Minimum floating-point number: " << min << endl;
cout << "Average floating-point number: " << avg << endl;
cout << "Maximum floating-point number: " << max << endl;
cout << "Population standard deviation: " << popDev << endl;
cout << "Sample standard deviation: " << sampleDev << endl;

return 0;
}
