#include <iostream>
#include "mm_vector.hpp"

int main() 
{
  mm_container::mm_vector<float> v("/home/alexxx/test.tst");
  for(auto x : v) std::cout<<x<<" ";
  
  mm_container::mm_vector<float> v1(v.begin(), v.end());
  
  std::cout<<"\n";
  std::cout<< v1[0];
}
