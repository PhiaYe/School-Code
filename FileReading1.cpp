//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <fstream>

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

int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects);

int parseline(char line[], int& value, int& valueg, const int minAcceptableID, const int maxAcceptableID){
    int in = 0;
 
    enum STATES {START, WS1, WS2, WS3, WS4, STUDENTID, COMMA, GRADE};
    STATES state = START; 
    
    while(line[in] != 0){
        if(line[in] != '\n'){      
            switch(state){
                
                case START:
                    if((line[in] == ' ') || (line[in] == '\t')){
                        state = WS1; 
                    }
                    else if((line[in] >='0') && (line[in] <= '9')){
                        value = line[in]-'0';
                        state = STUDENTID;
                    }
                    else{
                        return -1;
                    }
                    break;
                
                case WS1:
                    if(line[in] >= '0' && line[in] <= '9'){
                        value = line[in] - '0';
                        state = STUDENTID; 
                    }
                    else if(line[in] == ' ' || line[in] == '\t'){
                        state = WS1;
                    }
                    else
                        return -1;
                    break;
                
                case WS2:
                    if(line[in] == ' ' || line[in] == '\t'){
                        state = WS2;
                    }
                    else if(line[in] == ','){
                        state = COMMA;
                    }
                    else
                        return -1;
                    break;
                
                case WS3:
                    if(line[in] >= '0' && line[in] <= '9'){
                        valueg = line[in] - '0';
                        state = GRADE;
                    }
                    else if(line[in] == ' ' || line[in] == '\t'){
                        state = WS3;
                    }
                    else if(line[in] == '-')
                        return 0;
                    else
                        return -1;
                    break;
                
                case WS4:
                    if(line[in] == ' '|| line[in]=='\t')
                        state = WS4;
                    else if(line[in] == 0){
                       
                    }
                    else 
                        return -1;
                    break;
                
                case STUDENTID:
                    if((line[in] >= '0') && (line[in] <= '9')){
                        value = value * 10 + line[in] - '0';
                        state = STUDENTID;
                    }
                    else if(line[in] == ' ' || line[in] == '\t'){
                        state = WS2;
                    }
                    else if(line[in] == ','){
                        state = COMMA;
                    }
                    else 
                        return -1;
                    break;
                
                case COMMA:
                    if(line[in] >= '0'&& line[in] <= '9'){
                        valueg = line[in] - '0';
                        state = GRADE;
                    }
                    else if(line[in] == ' '||line[in]== '\t'){
                        state = WS3;
                    }
                    else if(line[in] == '-')
                        return 0;
                    else
                        return -1;
                    break;
                
                case GRADE: 
                    if(line[in] >= '0' && line[in] <= '9'){
                        valueg = valueg*10+line[in]-'0';
                        state = GRADE;
                    }
                    else if (line[in]==' '|| line[in]=='\t'){
                        state = WS4;
                    }
                    else if(line[in] == 0){
                        
                    }
                    else if(line[in] == '-')
                        return 0;
                    else
                        return -1;
                    break;
                }
                in++;
        }
    }
    if(value < minAcceptableID || value > maxAcceptableID){
        return 0;
    }
    else if(valueg < 0 || valueg > 100){
        return 0;
    }
    else
        return 1;
}
              
void HistogramStuff(int valueg, int histogram[10]){
    if(valueg == 100)
        histogram[9]++;
    else
        histogram[valueg/10]++;
}
 
 
//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return -1 if you cannot compute the histogram for any
// reason;
// Return 0 if the histogram is correct and there are no
// rejections;
// Return the number of rejects if there are rejected
// records from the file
//

int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects) {
    
    if(minAcceptableID > maxAcceptableID){
        return -1;
    }
    if(!histogram){
        return -1;
    }
    const int maxLineLength = 100;
    char line[maxLineLength];
    int value;
    int valueg; 
    
    std::ifstream infile;
    infile.open(filename);
    
    if(!infile.is_open())
        return -1;
    
    bool done = false;  
    int fileLineNumber = 0;
    int numRejects = 0;
    int maxNumErrors = 10;
    rejects = new int[maxNumErrors];
    
    for(int i = 0; i<10;i++){
        histogram[i] = 0;
    }
    
    while(!done){
        ++fileLineNumber;
        if(!infile.getline(line, maxLineLength)){
            if(infile.eof()){
                done = true;
            }
            else
                return -1;
        }
        if(!done){
            value = 0;
            valueg = 0;
                      
            if(parseline(line, value, valueg, minAcceptableID, maxAcceptableID)==1){ 
                HistogramStuff(valueg, histogram);
            }
            else if (parseline(line, value, valueg, minAcceptableID, maxAcceptableID)==0){
                rejects[numRejects] = fileLineNumber;
                numRejects++;
            }
            else
                return -1;
        }        
    
    }
    return numRejects;
  
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
  if (argc < 2) {

  }
  const int numBuckets = 10;
  const int bucketRange = 100/numBuckets;
  int  buckets[numBuckets];
  int* rejectedRecords;
  int retCode = histogram(argv[1], buckets, 22200000, 22299999, rejectedRecords);
  if (retCode < 0) {
      cout << "Unable to compute histogram." << endl;
  }
  else {
    for (int i = 0; i < numBuckets; ++i)
      if (i != numBuckets-1)
	cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)-1) << "]: " << buckets[i] << endl;
      else
	cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)) << "]: " << buckets[i] << endl;
    if (retCode > 0) {
      cout << "Number of rejected records: " << retCode << endl;
      cout << "Rejected records are:";
      for (int i = 0; i < retCode; ++i)
	cout << " " << rejectedRecords[i];
      cout << endl;
      delete[] rejectedRecords;
    }
  }

  return 0;
}

#endif
