// loop version of Binary Search
#include <iostream>
using namespace std;
 int Bin_Search(int arr[],int size, int target){
  int start=0;
  int end=size-1;
  while(start<=end){
    int middle=start-start/2+end/2;
    if(arr[middle]==target){
      return middle;
    }
    
   else if(middle<target){
      start=middle+1;
    }
    else { //(middle>target)
      end=middle-1;    }
  }
  return -1;
}

int main(){

  int arr[5] = {1, 2, 3, 4, 5};
  int target = 7;
  int index=Bin_Search(arr, 5, target);
  cout << index;
}