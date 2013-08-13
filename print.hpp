#pragma once

#include <cstddef>
#include <cstdarg>
#include <string>

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
