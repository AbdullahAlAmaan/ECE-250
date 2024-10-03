#include <iostream>
using namespace std;
void Reverse(int arr[], int size, int index){
  if(index==0){
    return;
  } 
  cout<<arr[size]<< " ";
  Reverse(arr,size,index-1);
}
int main(){

  int arr[5] = {1, 2, 3, 4, 5};
  int size=sizeof(arr)/sizeof(arr[0]);
  int index=size-1;
  Reverse(arr,size,index);
}