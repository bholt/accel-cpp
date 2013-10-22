/////////////////////////////////////////////////////
// Author: Brandon Holt
// Source: github.com/bholt/accel-cpp
/////////////////////////////////////////////////////
#pragma once

#include <iostream>

#ifdef _DEBUG
#define DEBUG 1
#endif

#define LOG(to_print) \
    std::cerr << __FILE__ << ":" << __LINE__ << "] " << to_print << std::endl

#ifdef DEBUG
#define DLOG(to_print) LOG(to_print)
#else
#define DLOG(to_print) do {} while (0)
#endif

#define CHECK(bool_expr) if (!(bool_expr)) { LOG( "Check failed: "#bool_expr ); throw "Check failed."; }
#define CHECK_LT(a, b) if (!((a) < (b))) { LOG( "Check failed: " << (a) << " < " << (b) ); throw "Check failed."; }
#define CHECK_EQ(a, b) if (!((a) == (b))) { LOG( "Check failed: " << (a) << " == " << (b) ); throw "Check failed."; }

#ifdef DEBUG
#  define DCHECK(bool_expr) CHECK(bool_expr)
#  define DCHECK_LT(a, b)   CHECK_LT(a, b)
#  define DCHECK_EQ(a, b)   CHECK_EQ(a, b)
#else
#  define DCHECK(bool_expr) do {} while (0)
#  define DCHECK_LT(a, b) do {} while (0)
#  define DCHECK_EQ(a, b) do {} while (0)
#endif
