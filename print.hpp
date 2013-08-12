#pragma once

template< size_t Size >
inline void sprintf_s(char (&buf)[Size], const char * fmt, ...) {
  // va_list argptr;
  // va_start(argptr, fmt);
  // sprintf(buf, )
  //
}

std::string str_fmt(const char* fmt, ...) {
  char dest[1024 * 16];
  va_list argptr;
  va_start(argptr, fmt);
  vsprintf(dest, fmt, argptr);
  va_end(argptr);
  return std::string(dest);
}

