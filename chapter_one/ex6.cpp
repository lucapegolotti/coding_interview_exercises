#include <iostream>
#include <string>
#include <math.h>

#include <test.hpp>
#include <printlog.hpp>

class Matrix
{
public:
  Matrix()
  {

  }

  Matrix(const unsigned int& nRows, const unsigned int& nCols) :
    M_nRows(nRows),
    M_nCols(nCols),
    M_referenceCounting()
  {
    allocate();
    putZero();
    M_referenceCounting = new unsigned int;
    *M_referenceCounting = 0;
    increaseReferenceCounting();
  }

  Matrix(const Matrix& other)
  {
    M_matrix = other.M_matrix;
    M_nRows = other.M_nRows;
    M_nCols = other.M_nCols;
    M_referenceCounting = other.M_referenceCounting;
    M_referenceCounting++;
  }

  ~Matrix()
  {
    decreaseReferenceCounting();
    if (M_referenceCounting == 0)
      deallocate();
  }

  void allocate()
  {
    M_matrix = new int*[M_nRows];

    for (int i = 0; i < M_nRows; i++)
    {
      M_matrix[i] = new int[M_nCols];
    }
  }

  void putZero()
  {
    for (int i = 0; i < M_nRows; i++)
    {
      for (int j = 0; j < M_nCols; j++)
      {
        M_matrix[i][j] = 0;
      }
    }
  }

  void deallocate()
  {
    for (int i = 0; i < M_nRows; i++)
    {
      delete M_matrix[i];
    }

    delete M_matrix;
    delete M_referenceCounting;
  }

  void fill(const int& seed = 1)
  {
    for (int i = 0; i < M_nRows; i++)
    {
      for (int j = 0; j < M_nCols; j++)
      {
        M_matrix[i][j] = i * seed + j;
      }
    }
  }

  void print()
  {
    for (int i = 0; i < M_nRows; i++)
    {
      for (int j = 0; j < M_nCols; j++)
      {
        printlog(CYAN,M_matrix[i][j]);
        printlog(WHITE,"\t");
      }
      printlog(WHITE,"\n");
    }
  }

  int& operator()(const unsigned int& row, const unsigned int& col)
  {
    return M_matrix[row][col];
  }

  bool operator==(const Matrix& other)
  {
    if (M_nRows != other.getRows() || M_nCols != other.getCols())
    {
      return false;
    }

    for (int i = 0; i < M_nRows; i++)
    {
      for (int j = 0; j < M_nCols; j++)
      {
        if (M_matrix[i][j] != other.M_matrix[i][j])
          return false;
      }
    }


    return true;
  }

  // index of element is 0 for the top left corner, then increases in clockwise
  // orientation
  int& getElementInLayer(const unsigned int& layer, const unsigned int& index)
  {
    unsigned int widthLayer = M_nRows - 2*layer;
    unsigned int heightLayer = M_nCols - 2*layer;

    if (layer > std::min(M_nRows,M_nCols)/2)
    {
      printlog(RED, "ERROR in getElementInLayer: layer out of bounds\n");
      exit(1);
    }

    // top part
    if (index <= widthLayer - 1)
    {
      return M_matrix[layer][layer + index];
    }
    // right part
    else if (index < widthLayer + heightLayer - 2)
    {
      return M_matrix[layer + index - (widthLayer-1)][M_nCols - layer-1];
    }
    // bottom part
    else if (index < 2*widthLayer + heightLayer - 3)
    {
      return M_matrix[M_nRows - layer - 1][M_nCols - layer - index + (widthLayer + heightLayer - 2) - 1];
    }
    else if (index < 2*widthLayer + 2*heightLayer - 4)
    {
      return M_matrix[M_nRows - layer - index + (2*widthLayer + heightLayer - 3) - 1][layer];
    } else
    {
      printlog(RED, "ERROR in getElementInLayer: index out of bounds\n");
      exit(1);
    }
  }

  unsigned int getRows() const
  {
    return M_nRows;
  }

  unsigned int getCols() const
  {
    return M_nCols;
  }

  void increaseReferenceCounting()
  {
    *M_referenceCounting++;
  }

  void decreaseReferenceCounting()
  {
    *M_referenceCounting--;
  }

private:
  unsigned int M_nRows;
  unsigned int M_nCols;

  int** M_matrix;

  unsigned int* M_referenceCounting;
};

// this is not done in place, hence nRows != nCols possibly
Matrix rotateMatrixClockwise(Matrix& input)
{
  unsigned int nRows = input.getRows();
  unsigned int nCols = input.getCols();
  Matrix output(nCols,nRows);

  unsigned int maxLayer = ceil(static_cast<double>(std::min(nRows,nCols))/2.0);

  for (int i = 0; i < maxLayer; i++)
  {
    unsigned int widthLayer = nRows - 2*i;
    unsigned int heightLayer = nCols - 2*i;
    if (widthLayer == 1 && heightLayer == 1)
    {
      output.getElementInLayer(i,0) = input.getElementInLayer(i,0);
    }
    else
    {
      unsigned int sizeLayer = 2*(widthLayer + heightLayer - 2);

      for (int j = 0; j < sizeLayer; j++)
      {
        output.getElementInLayer(i,(j+widthLayer-1)%sizeLayer) = input.getElementInLayer(i,j);
      }
    }

  }


  return output;
}

void subTest1(Test& test)
{
  Matrix matrix(3,3);

  Matrix expectedResult(3,3);
  expectedResult(0,0) = 2;
  expectedResult(0,1) = 1;
  expectedResult(0,2) = 0;
  expectedResult(1,0) = 3;
  expectedResult(1,1) = 2;
  expectedResult(1,2) = 1;
  expectedResult(2,0) = 4;
  expectedResult(2,1) = 3;
  expectedResult(2,2) = 2;

  matrix.fill();
  Matrix output = rotateMatrixClockwise(matrix);

  test.assert(output == expectedResult);
}

int main()
{
  Test test("Ex6");

  test.addSubTest(*subTest1);

  test.run();

  return 0;
}
