#include <iostream>

#include <cmath>

#include <cassert>

using namespace std;

int findMaxK(int n) {
int power = 2;
double max = 0.0;
int maxK = 0;
while (n > 0) {
n -= 2;
double t = (double)n/power;
double r = pow(t, (double)power);
  if (r > max) {
      maxK = power;
      max = r;
  }
power++;
}
return maxK;
}

unsigned int f(int n) {
      if (n <= 7) return n;    
      int k = findMaxK(n);      
      int sum = n - 2*(k-1);    
      unsigned int mul = 1;     
      while (k > 0) {
             int avg = sum/k;
             mul *= avg;
             k--;
             sum -= avg;
       }

     assert(sum == 0);

     return mul;
}

int main(){
	cout<<f(16)<<endl;
	return 0;
}
