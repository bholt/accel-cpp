# Accel C++
Simple library of headers for making common tasks in C++ easier. The goal from the start is to avoid taking dependences on other libraries and try to stick to vanilla C++ standard libraries.

## Categories of accelerations (so far):
### Logging
Super simplified version of what Google Glog does, letting you dump things with file/line number easily.

### Flags
Simple declarative flag parser.

### Time
`walltime()` for fine-grained timing (performance measurement) on multiple platforms

## To use:
Clone the entire repo.

Or, download a single file:

```bash
# Linux:
wget https://raw.github.com/bholt/accel-cpp/master/flags.hpp
# Mac:
curl -O https://raw.github.com/bholt/accel-cpp/master/flags.hpp
```
