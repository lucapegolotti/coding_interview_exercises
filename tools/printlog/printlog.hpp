#ifndef PRINTLOG_HPP
#define PRINTLOG_HPP

#include <iostream>
#include <string>
#include <sstream>

enum Color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

extern void printlog(Color outColor, std::string text);

template < typename T >
extern std::string to_string( const T& n );

extern void printlog(Color outColor, int num);

#endif  // PRINTLOG_HPP
