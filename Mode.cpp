//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//


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

int range(const int dataset[], const int size);
int mode(const int dataset[], const int size, int mode[]);
bool sort(int dataset[], const int size);
void selection(int arr[], int n);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  Return -1 if there there are any problems with the dataset.
// Range  and mode should never be negative, so return -1
//

int range(const int dataset[], const int size){
//return the difference between maximum and minimum value of dataset
  if (size < 1)
    return -1;

  int minn = dataset[0];
  int maxx = dataset[0];
  int counter = 0;

  while (counter < size){
    if (dataset[counter] < minn)
      minn = dataset[counter];
    if (dataset[counter] > maxx)
      maxx = dataset[counter];
    counter++;
  }
  return maxx - minn;
}

bool selection(int dataset[], int size, int counter){
//locMin = location of mininum
  int locMin;
  int temp;

  if (counter >= size)
    return true;

  locMin = counter;//set locMin to the current index of array

	for (int j=counter+1; j < size; j++){

	    if (dataset[j] < dataset[locMin])
        locMin = j;
	//locMin will keep track of the index that min is in, this is needed when a swap happens
	}

	 //if locMin no longer equals i than a smaller value must have been found, so a swap must occur
  if (locMin != counter){
    temp = dataset[counter];
    dataset[counter] = dataset[locMin];
    dataset[locMin] = temp;
  }

  return selection(dataset, size, counter + 1);
}


int mode(const int dataset[], const int size, int mode[]){
//size is the number of items in the dataset
//The mode is the most common number in dataset
//return the number of modes that you find
//array mode is filled with the actual mode values (in order of increasing size)
  if (size == 1)
    return 1;

  int s = size;
  int array[s-1];

  for (int a=0; a < s; a++){
    array[a] = dataset[a];
  }

  selection(array, s, 0);

  int index = 0; //index for mode array storing values of modes
  int temp = 1; //stores highest number of repetitions
  int j = 1; //counter for number of repetitions of a value in dataset

  for (int i=0; i<s; i++){

    if (array[i] != array[i+1]){
      j = 1;
    }

    else{
      j++;

      if (j == temp){
        index++;
        mode[index] = array[i];
      }
      else if (j > temp){
        temp = j;
        index = 0;
        mode[index] = array[i];
      }
    }
  }
return index + 1;
}

bool sort(int dataset[], const int size){
  return selection(dataset, size, 0);
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
  int data[] = {1,1,2,3,4,5};
  int size = 6;

  /*
  selection(data, size, 0);

  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }*/


  //change this to however many modes you expect to find
  int modeArray[100]={0};
  int rng = range(data, size);
  int modes = mode(data, size, modeArray);
  cout << "range: " << rng << " number of Modes: " << modes << " Modes are this: ";
  for(int i = 0; i<modes;i++){
  	cout<< modeArray[i];
  	if(i<modes-1){
  		cout << ", ";
  	}
  }
  cout<<endl;
  return 0;
}

#endif
