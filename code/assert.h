#ifndef NDEBUG
#include <iostream>
#include <stdexcept>
#include <ncurses.h>
#   define ASSERT(condition) ASSERT_MESSAGE((condition), "") 
#   define ASSERT_MESSAGE(condition, message) \
    do { \
        if (! (condition)) { \
            endwin(); \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ \
                      << " line " << __LINE__ << ": " << message << std::endl; \
            throw std::runtime_error(""); \
        } \
    } while (false)
#else
#   define ASSERT(condition, message) do { } while (false)
#endif