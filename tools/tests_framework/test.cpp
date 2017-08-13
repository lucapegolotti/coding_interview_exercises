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
  std::cout << std::endl;
  std::cout << "\033[1;31mRunning test\033[0m " << M_testName << std::endl;
  std::cout << "-------------------------" << std::endl;

  unsigned int n_tests = M_subTests.size();
  for (int i = 0; i < n_tests; i++)
  {
    std::cout << "Test " << i+1 << " ... " << std::endl;
    (*M_subTests[i])(*this);
  }

  std::cout << "Successful tests: " << M_successes << "/" << n_tests << std::endl;
}
