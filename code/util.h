#ifndef _FILE_H_
#define _FILE_H_

#include <sstream>
#include <iostream>
#include <string>

class File {
public:
    static std::string readText(const char* path);
};

class String {
public:
    template<typename T, typename... Targs>
    static std::string format(const char* format, T value, Targs... args) {
        std::ostringstream ostr;
        formatHelper(ostr, format, value, args...);
        return ostr.str();
    }

private:
    static void formatHelper(std::ostringstream& ostr, const char* format) {
        ostr << format;
    }

    template<typename T, typename... Targs>
    static void formatHelper(std::ostringstream& ostr, const char* format, T value, Targs... args) {
        for ( ; *format != '\0'; format++ ) {
            if ( *format == '%' ) {
               ostr << value;
               formatHelper(ostr, format+1, args...); // recursive call
               return;
            }
            ostr << *format;
        }
    }
};

class Log {
public:
    static void log(const char* format) {
        std::cout << format;
    }
    
    template<typename T, typename... Targs>
    static void log(const char* format, T value, Targs... args) {
        for ( ; *format != '\0'; format++ ) {
            if ( *format == '%' ) {
               std::cout << value;
               log(format+1, args...); // recursive call
               return;
            }
            std::cout << *format;
        }
    }
};
#endif