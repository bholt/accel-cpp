/////////////////////////////////////////////////////
// Author: Brandon Holt
// Source: github.com/bholt/accel-cpp
/////////////////////////////////////////////////////
#pragma once

#include <cstddef>
#include <cstdarg>
#include <string>
#include <sstream>
#include <vector>

template< size_t Size >
inline void vsprintf_s(char (&buf)[Size], const char * fmt, va_list va) {
  vsnprintf(buf, Size, fmt, va);
}

template< size_t Size >
inline void sprintf_s(char (&buf)[Size], const char * fmt, ...) {
  va_list argptr;
  va_start(argptr, fmt);
  vsprintf_s(buf, fmt, argptr);
  va_end(argptr);
}

template< size_t Size >
inline void strcpy_s(char (&buf)[Size], const char * fmt, ...) {
  va_list argptr;
  va_start(argptr, fmt);
  vsprintf_s(buf, fmt, argptr);
  va_end(argptr);
}

std::string str_fmt(const char* fmt, ...) {
  char dest[1<<16];
  va_list argptr;
  va_start(argptr, fmt);
  vsprintf_s(dest, fmt, argptr);
  va_end(argptr);
  return std::string(dest);
}

template< int width = 10, typename ArrayT = std::nullptr_t >
inline std::string array_str(const char * name, const ArrayT& array) {
  bool multiline = array.size() > width;
  std::stringstream ss;
  if (name) {
    ss << name << ": ";
  }
  ss << "[";
  long i=0;
  for (auto e : array) {
    if (i % width == 0 && multiline) ss << "\n  ";
    ss << " " << e;
    i++;
  }
  ss << (multiline ? "\n" : " ") << "]";
  return ss.str();
}

template< int width = 10, typename ArrayT = std::nullptr_t >
inline std::string array_str(const ArrayT& array) {
  return array_str(nullptr, array);
}

template< typename T >
std::ostream& operator<<(std::ostream& o, std::vector<T> v) {
  o << array_str(v);
  return o;
}
