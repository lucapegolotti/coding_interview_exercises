#ifndef PRINTLOG_HPP
#define PRINTLOG_HPP

#include <iostream>
#include <string>

enum Color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

extern void printlog(Color outColor, std::string text);
extern void printlog(Color outColor, int num);

#endif  // PRINTLOG_HPP
