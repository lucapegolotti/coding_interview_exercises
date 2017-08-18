#include <iostream>
#include <string>
#include <set>
#include <math.h>

#include <test.hpp>
#include <printlog.hpp>

template <int nCols>
void setRowAndColsToZero(int matrix[][nCols], int nRows)
{
  std::set<int> rowsWithZeros;
  std::set<int> colsWithZeros;

  for (int i = 0; i < nRows; i++)
  {
    for (int j = 0; j < nCols; j++)
    {
      if (matrix[i][j] == 0)
      {
        rowsWithZeros.insert(i);
        colsWithZeros.insert(j);
      }
    }
  }

  for (std::set<int>::iterator it = rowsWithZeros.begin(); it != rowsWithZeros.end(); it++)
  {
    for (int j = 0; j < nCols; j++)
    {
      matrix[*it][j] = 0;
    }
  }

  for (std::set<int>::iterator it = colsWithZeros.begin(); it != colsWithZeros.end(); it++)
  {
    for (int i = 0; i < nRows; i++)
    {
      matrix[i][*it] = 0;
    }
  }
}

void subTest1(Test& test)
{
  int matrix[3][4];

  matrix[0][0] = 1;
  matrix[0][1] = -1;
  matrix[0][2] = 0;
  matrix[0][3] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 10;
  matrix[1][2] = 2;
  matrix[1][3] = 1;
  matrix[2][0] = 3;
  matrix[2][1] = -2;
  matrix[2][2] = 0;
  matrix[2][3] = 0;

  int expectedResult[3][4];

  expectedResult[0][0] = 0;
  expectedResult[0][1] = 0;
  expectedResult[0][2] = 0;
  expectedResult[0][3] = 0;
  expectedResult[1][0] = 4;
  expectedResult[1][1] = 10;
  expectedResult[1][2] = 0;
  expectedResult[1][3] = 0;
  expectedResult[2][0] = 0;
  expectedResult[2][1] = 0;
  expectedResult[2][2] = 0;
  expectedResult[2][3] = 0;

  setRowAndColsToZero<4>(matrix, 3);

  bool check = true;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (matrix[i][j] != expectedResult[i][j])
      {
        check = false;
        i = 3;
        j = 4;
      }
    }
  }

  test.assert(check);

}

void subTest2(Test& test)
{
  int matrix[3][3];

  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 5;
  matrix[1][2] = 6;
  matrix[2][0] = 7;
  matrix[2][1] = 8;
  matrix[2][2] = 9;

  int expectedResult[3][3];

  expectedResult[0][0] = 1;
  expectedResult[0][1] = 2;
  expectedResult[0][2] = 3;
  expectedResult[1][0] = 4;
  expectedResult[1][1] = 5;
  expectedResult[1][2] = 6;
  expectedResult[2][0] = 7;
  expectedResult[2][1] = 8;
  expectedResult[2][2] = 9;

  setRowAndColsToZero<3>(matrix, 3);

  bool check = true;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (matrix[i][j] != expectedResult[i][j])
      {
        check = false;
        i = 3;
        j = 4;
      }
    }
  }

  test.assert(check);

}

void subTest3(Test& test)
{
  int matrix[3][3];

  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 0;
  matrix[1][1] = 5;
  matrix[1][2] = 6;
  matrix[2][0] = 7;
  matrix[2][1] = 8;
  matrix[2][2] = 9;

  int expectedResult[3][3];

  expectedResult[0][0] = 0;
  expectedResult[0][1] = 2;
  expectedResult[0][2] = 3;
  expectedResult[1][0] = 0;
  expectedResult[1][1] = 0;
  expectedResult[1][2] = 0;
  expectedResult[2][0] = 0;
  expectedResult[2][1] = 8;
  expectedResult[2][2] = 9;

  setRowAndColsToZero<3>(matrix, 3);

  bool check = true;

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (matrix[i][j] != expectedResult[i][j])
      {
        check = false;
        i = 3;
        j = 4;
      }
    }
  }

  test.assert(check);

}

int main()
{
  Test test("Ex7");

  test.addSubTest(*subTest1);
  test.addSubTest(*subTest2);
  test.addSubTest(*subTest3);


  test.run();

  return 0;
}
