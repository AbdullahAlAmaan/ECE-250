//without creation of a new array
#include <iostream>
using namespace std;
int main(){
  int start=0;
  int end=4;
  int arr[5]={1,2,3,4,5};
 while(start<end){
   int temp=arr[start]; // this is like swap function (a,b) so temp=a, a=b (so a has value of b now) and then b=temp( temp had a value so swapped)
   arr[start]=arr[end];
   arr[end]=temp;
   start++;
   end--;
 }
  for(int i=0;i<5;i++){
    cout<<arr[i] << " ";
  }
  }