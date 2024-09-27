#include <iostream>
using namespace std;
int main()
{
  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int sum[3][3]; // initialising the new array that we will obtain after addition 

  for (int i = 0; i < 3; i++)
  {

    for (int j = 0; j < 3; j++) // only one traversal is used for both the arrays to loop over it
    {

      sum[i][j] = arr[i][j] + arr1[i][j];
      cout << sum[i][j] << " ";
    }
    cout << endl;
  }
}