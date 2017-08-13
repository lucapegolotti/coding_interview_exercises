#include "printlog.hpp"

void printlog(Color outColor, std::string text)
{
  std::cout << "\033[;" << outColor+30 << "m";
  std::cout << text;
  std::cout << "\033[0m\n";
}
