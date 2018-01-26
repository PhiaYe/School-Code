//GCD Greatest Common Divisor: largest positive "g" s.t. << a mod g = 0 && b mod g = 0
//LCM Least Common Multiple: smallest integer dividable by both a and b
//LCM (a,b) = (a*b)/GCD(a,b)

#include<iostream>
#include<stdlib.h>

using namespace std;

int main (const int argc, const char* const argv[]){

if (argc < 3){
cerr << "Error: Unable to compute GCD and/or LCM because there are insufficient arguments." << endl;
return -1;
}

if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0){
cerr << "Error: Unable to compute GCD and/or LCM because one or more arguments are invalid." << endl;
return -1;
}

if (argc > 3){
cerr << "Warning: Too many arguments." << endl;
}

int a = atoi(argv[1]);
int b = atoi(argv[2]);
int gcd = 1;
int maybe = atoi(argv[1]);
int lcm = 1;

while (maybe > 0){
if ((a % maybe == 0) && (b % maybe == 0)){
gcd = maybe;
break;
}
maybe--;
}

lcm = (a/gcd)*b;

cout << "GCD(" << a << ", " << b << ") = " << gcd << endl;
cout << "LCM(" << a << ", " << b << ") = " << lcm << endl;

return 0;

}
