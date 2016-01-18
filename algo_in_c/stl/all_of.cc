#include <iostream>
#include <algorithm>
#include <array>

// Up to linear in the distance between first and last:
// Calls pred for each element until a mismatch is found.
int main () {
  std::array<int,8> foo = {3,5,7,11,13,17,19,23};

  if ( std::all_of(foo.begin(), foo.end(), [](int i){return i%2;}) )
    std::cout << "All the elements are odd numbers.\n";

  return 0;
}