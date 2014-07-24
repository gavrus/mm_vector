#ifndef MM_FILE_HPP
#define MM_FILE_HPP

namespace mm_container
{
  class mm_file 
  {
  public:
    mm_file()noexcept;
    mm_file(const std::string& filename);
    ~mm_file();
    size_t size() const noexcept;
    void* data() const noexcept;
    
  private:
    void* _mapped_area;
    int _fid;//posix file id
    size_t _fsize;
  };
}


#endif	/* MM_FILE_HPP */