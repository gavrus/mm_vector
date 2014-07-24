#include <sys/types.h>
#include <sys/stat.h>
#include<sys/mman.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdexcept>
#include "mm_file.hpp"

namespace
{
  size_t get_file_size(std::string filename)
  {
    struct stat stat_buf;
    int rc = stat(filename.c_str(), &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
  }
}

namespace mm_container
{
  mm_file::mm_file() noexcept: 
  _mapped_area(nullptr), _fid(-1), _fsize(0) { }
  
  mm_file::mm_file(const std::string& filename): 
   _mapped_area(nullptr), _fid(-1), _fsize(0)
  {
    if ((_fid = open(filename.c_str(), O_RDONLY)) < 0) 
      throw std::runtime_error("File not exist");
    
    _fsize = get_file_size(filename);
    _mapped_area = mmap(0, _fsize, PROT_READ, MAP_SHARED, _fid, 0);
  }
  
  mm_file::~mm_file()
  {
    if(_fid > -1) close(_fid);
    _mapped_area = nullptr;
  }
  
  size_t mm_file::size() const noexcept
  {
    return _fsize;
  }

  void* mm_file::data() const noexcept
  {
    return _mapped_area;
  } 
}
