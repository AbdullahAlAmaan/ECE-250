#include <iostream>
using namespace std;
void Decrease(int n){
  if(n==0){
    return;
}
cout<<n<< " ";
Decrease(n-1);
}

int main() {
  Decrease(5);
  return 0;
}