#include "test.hpp"

Test::Test(std::string testName) :
  M_subTests(),
  M_testName(testName),
  M_successes(0)
{

}

void Test::addSubTest(void (*subTest)(Test&))
{
  M_subTests.push_back(subTest);
}

void Test::assert(bool statement)
{
  M_successes = statement? M_successes + 1 : M_successes;
}


void Test::run()
{
  // std::cout << std::endl;
  // std::cout << "\033[1;31mRunning test" << M_testName << "\033[0m "<< std::endl;
  // std::cout << "-------------------------" << std::endl;

  std::string msg = "\nRunning test " + M_testName;
  printlog(MAGENTA, msg);
  printlog(WHITE, "-----------------------");

  unsigned int n_tests = M_subTests.size();
  for (int i = 0; i < n_tests; i++)
  {
    msg = "\tTest " + std::to_string(i+1) + " ... ";
    printlog(BLUE, msg);
    (*M_subTests[i])(*this);
  }

  msg = "Successful tests: " + std::to_string(M_successes) + "/" + std::to_string(n_tests);

  if (M_successes == n_tests)
  {
    printlog(GREEN, msg);
  }
  else
  {
    printlog(RED, msg);
  }
}
