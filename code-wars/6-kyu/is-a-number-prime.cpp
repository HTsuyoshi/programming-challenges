#include <cmath>

bool isPrime(int num) {
  if (num < 2) return false;
  num = abs(num);
  for (int i=2; i<=sqrt(num); i++)
    if (num % i == 0)
      return false;
  return true;
}
