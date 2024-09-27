//2D Array means it is an array that stores arrays as its elements [[1,2],[2,3]]
//Visualise it as an matrix
#include <iostream>
using namespace std;
int main(){
int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}}; //2 rows and 3 columns
for (int i=0;i<3;i++){ 
  for (int j=0;j<3;j++){ // traversing through every row but this, outer loop is for selecting the row and inner loop is for going through every column of that row
    cout<<arr[i][j]<<" ";
  }
  cout<<endl;

}
}