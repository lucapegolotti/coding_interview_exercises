#include "test.hpp"

Test::Test(std::string testName) :
  M_subTests(),
  M_testName(testName),
  M_nTests(0),
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
  M_nTests++;
}


void Test::run()
{

  std::string msg = "\nRunning test " + M_testName + "\n";
  printlog(MAGENTA, msg);
  printlog(WHITE, "-----------------------\n");

  int count = 0;
  for (std::vector<void (*)(Test&)>::iterator it = M_subTests.begin();
       it < M_subTests.end(); it++)
  {
    count++;
    msg = "\tTest " + std::to_string(count) + " ... \n";
    printlog(BLUE, msg);
    (*(*it))(*this);
  }

  msg = "Successful asserts: " + std::to_string(M_successes) + "/" +
         std::to_string(M_nTests) + "\n";

  if (M_successes == M_nTests)
  {
    printlog(GREEN, msg);
  }
  else
  {
    printlog(RED, msg);
  }
}
