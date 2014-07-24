mm_vector
=========

STL compatiable container (vector) for stroring virual memory segment of the memory mapped file. 

A memory-mapped file is a segment of virtual memory which has been assigned a direct byte-for-byte correlation with some portion of a file or file-like resource. This approach suitable for interaction with huge amount of data, including machine learning tasks on Big Data.

Examples:


#include "mm_vector.hpp"

int main() 
{
  //Map file, which contains several single precision numbers and print
  mm_container::mm_vector<float> v("testfile.test");
  for(auto x : v) std::cout<<x<<" ";
  
  //Use mm_vector as standart STL vector
   mm_container::mm_vector<float> v{0.1, 0.2, 0.3};
}
