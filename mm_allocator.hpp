#ifndef MM_ALLOCATOR_HPP
#define MM_ALLOCATOR_HPP

#include <memory>
#include "mm_file.hpp"

namespace
{
  enum class alloc_mode
  {
    CLASSIC,
    MMAP
  };
}

namespace mm_container
{  
  template <typename T>
  class mm_allocator: public std::allocator<T>
  {
  public:

    template<typename U>
    struct rebind
    {
      typedef mm_allocator<U> other;
    };

    mm_allocator() noexcept:
    std::allocator<T>(),
    _mf(),
    _alloc_mode(alloc_mode::CLASSIC),
    _numelems(0) { }
    
    mm_allocator(const std::allocator<T> &a) noexcept:
    std::allocator<T>(a),
    _mf(),
    _alloc_mode(alloc_mode::CLASSIC),
    _numelems(0) { }
    
    mm_allocator(const std::string& filename):
    std::allocator<T>(),
    _mf(filename),
    _alloc_mode(alloc_mode::MMAP),
    _numelems(_mf.size() / sizeof(T)) { }
    
    T* allocate(size_t n)
    {
      if (_alloc_mode == alloc_mode::CLASSIC) 
	return std::allocator<T>::allocate(n); 
      else 
	return static_cast<T*>(_mf.data());
    }
    
    void deallocate(T* p, size_t n)
    {
      if (_alloc_mode == alloc_mode::CLASSIC) 
	std::allocator<T>::deallocate(p, n); 
    }
    size_t get_numelems()
    {
      return _numelems; 
    }
    
  private:
    mm_file _mf;
    alloc_mode _alloc_mode;
    size_t _numelems;
  };
}


#endif	/* MM_ALLOCATOR_HPP */