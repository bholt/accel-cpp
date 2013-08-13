#pragma once

#include <vector>
#include <sstream>
#include <cstring>
#include <string>
#include "print.hpp"

// forward declaration
namespace flags { template<typename T> class Flag; }

template< typename T >
std::ostream& operator<<(std::ostream& o, const flags::Flag<T>& f) {
  return o << f.val;
}

namespace flags {
  class FlagBase;
  template<typename T> class Flag;

  namespace impl {
    std::vector<FlagBase*>& registered_flags();
  }
  
  class FlagBase {
    std::string name;
  public:
    FlagBase(const char * name): name(name) {
      impl::registered_flags().push_back(this);
    }
    virtual const char * flag() const { return name.c_str(); }
    virtual void parse(const char * arg) = 0;
  };
  
  template< class T >
  class Flag : public FlagBase {
  protected:
    T val;
    T default_val;
  public:
    Flag(const char * name, T default_val):
      FlagBase(name),
      val(default_val),
      default_val(default_val)
    { }
    void parse(const char * a) {
      std::istringstream(a) >> val;
    }    
    operator T() { return val; }
    const T& operator=(const T& o) { val = o; }
    
    template< typename TT >
    friend std::ostream& ::operator<<(std::ostream& o, const Flag<TT>& f);
  };
    
  inline void parse(int& argc, const char ** argv) {
    for (int i=1; i<argc; i++) {
      if (strncmp("--", argv[i], 2) != 0) continue;
      
      std::string flag_str(argv[i]+2);
      std::string arg_str;
      size_t p = flag_str.find("=");
      if (p != std::string::npos) {
        arg_str = flag_str.substr(p+1);
        flag_str = flag_str.substr(0, p);
      } else {
        arg_str = std::string(argv[i+1]);
        i++;
      }
      for (FlagBase * f : impl::registered_flags()) {
        if (flag_str.compare(f->flag()) == 0) {
          LOG( flag_str << " : " << arg_str );
          f->parse(arg_str.c_str());
          break;
        }
      }
    }
  }
}


#define FLAGS_IMPL()                               \
  namespace flags {                                \
    namespace impl {                               \
      std::vector<FlagBase*>& registered_flags() { \
        static std::vector<FlagBase*> flags;       \
        return flags;                              \
      }                                            \
    }                                              \
  }


#define DECLARE_FLAG(type, name) \
  namespace flags { extern Flag<type> name; }
#define DEFINE_FLAG(type, name, default_val, description) \
  namespace flags { Flag<type> name(#name, default_val); }
