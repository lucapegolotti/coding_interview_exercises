#include "printlog.hpp"

void printlog(Color outColor, std::string text)
{
  std::cout << "\033[;" << outColor+30 << "m";
  std::cout << text;
  std::cout << "\033[0m";
}


void printlog(Color outColor, int num)
{
  printlog(outColor, std::to_string(num));
}

template < typename T >
std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
