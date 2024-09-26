#include <iostream>
using namespace std;
int main()
{
  int arr[5] = {1, 2, 3, 4, 5};
  int value = 5;
  int count = 0;
  for (int i = 0; i < 5; i++) // Compare the first with rest and check and after each repetition checking the next with the rest of the array
  {
    for (int j = i + 1; j < 5; j++)
    {
      if (arr[i] + arr[j] == value)
      {
        count += 1;
      }
    }
  }
  cout << count;
}