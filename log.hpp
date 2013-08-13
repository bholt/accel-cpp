#pragma once

#include <iostream>

#define LOG(to_print) \
    std::cerr << __FILE__ << ":" << __LINE__ << "] " << to_print << std::endl

#if defined(DEBUG) || defined(_DEBUG)
#define DLOG(to_print) LOG(to_print)
#else
#define DLOG(to_print) do {} while (0)
#endif

#define LLOG(to_print) LOG("@" << id << ": " << to_print)
#define LDLOG(to_print) DLOG("@" << id << ": " << to_print)

#define CHECK(bool_expr) if (!(bool_expr)) { LOG( "Check failed: "#bool_expr ); }
#define CHECK_LT(a, b) if (!((a) < (b))) { LOG( "Check failed: " << (a) << " < " << (b) ); }
#define CHECK_EQ(a, b) if (!((a) == (b))) { LOG( "Check failed: " << (a) << " == " << (b) ); }
