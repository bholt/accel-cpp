#include "all.hpp"

DEFINE_FLAG(int, foo, 0, "number of foos");

FLAGS_IMPL();

int main(int argc, const char* argv[]) {
  flags::parse(argc, argv);
  
  LOG( "foo: " << flags::foo );
  
  return 0;
}
