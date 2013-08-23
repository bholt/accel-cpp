/////////////////////////////////////////////////////
// Author: Brandon Holt
// Source: github.com/bholt/accel-cpp
/////////////////////////////////////////////////////
#pragma once

#include <iostream>

#define LOG(to_print) \
    std::cerr << __FILE__ << ":" << __LINE__ << "] " << to_print << std::endl

#if defined(DEBUG) || defined(_DEBUG)
#define DLOG(to_print) LOG(to_print)
#else
#define DLOG(to_print) do {} while (0)
#endif


# if defined(DEBUG) || defined(_DEBUG)
#   define CHECK(bool_expr) if (!(bool_expr)) { LOG( "Check failed: "#bool_expr ); throw false; }
#   define CHECK_LT(a, b) if (!((a) < (b))) { LOG( "Check failed: " << (a) << " < " << (b) ); throw false; }
#   define CHECK_EQ(a, b) if (!((a) == (b))) { LOG( "Check failed: " << (a) << " == " << (b) ); throw false; }
# else
#   define CHECK(bool_expr) do {} while (0)
#   define CHECK_LT(a, b) do {} while (0)
#   define CHECK_EQ(a, b) do {} while (0)
# endif
