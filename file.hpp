#include <fstream>

namespace accel {
  class file_stream : public std::fstream {
    bool in_binary_mode;
  public:
    file_stream(const char* filename, ios_base::openmode mode = ios_base::in | ios_base::out)
      : fstream(filename, mode), in_binary_mode(mode & ios_base::binary)
    { }
    
    /// Implicitly use type information to read binary data in multiples of the object size.
    template< typename T >
    file_stream& read(T* p, streamsize n = 1) {
      std::fstream::read((char*)p, n * sizeof(T));
      return *this;
    }

    /// Allow using '>>' to load binary values (when opened in binary mode)
    template< typename T >
    file_stream& operator>>(T& o) {
      if (in_binary_mode) {
        read(&o);
      } else {
        fstream::operator>>(o);
      }
      return *this;
    }
  };
  
}