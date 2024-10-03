#include <iostream>
using namespace std;

void Increase(int start, int n)
{
  if (start == n + 1) 
  {
    return; // BASE CASE
  }
  cout << start << " "; // TASK
  Increase(start + 1, n);
} // RECURSION FUNCTION

int main()
{
  int start = 1;
  Increase(start, 7);
  return 0;
}