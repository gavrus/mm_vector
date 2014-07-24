#ifndef MM_VECTOR_HPP
#define MM_VECTOR_HPP

#include <vector>
#include "mm_allocator.hpp"
#include <initializer_list>

namespace mm_container
{  
  template <typename T>
  class mm_vector: public std::vector<T, mm_allocator<T> > 
  {
  public:
    typedef mm_allocator<T> alloc_type;
    typedef std::vector<T, mm_allocator<T> > b_vector;
    
    mm_vector(): b_vector(){ }
    mm_vector(const b_vector& other): b_vector(other) { }
    explicit mm_vector(size_t n): b_vector(n) { }
    explicit mm_vector(alloc_type a): b_vector(a) { }
    template <class Iter> mm_vector(Iter b, Iter e): b_vector(b, e) { }
    mm_vector(int n, T val, alloc_type a); 
    mm_vector (mm_vector&& x): b_vector(x) { }
    mm_vector (mm_vector&& x, const alloc_type& a): b_vector(x, a) { }
    mm_vector(std::initializer_list<T> il): b_vector(il) { }
    explicit mm_vector(const std::string& filename): 
    b_vector( alloc_type(filename) )
    {
      size_t nel = this->get_allocator().get_numelems();
      this->reserve(nel);
      this->_M_impl._M_finish = this->_M_impl._M_start + nel;
    }
  };
}




#endif	/* MM_VECTOR_HPP */