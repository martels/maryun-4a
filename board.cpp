

#include "board.h"

using namespace std;


board::board(int sqSize)
   : value(BoardSize+1,BoardSize+1)
// Board constructor
{
   clear();
}

void board::clear()
// Mark all possible values as legal for each board entry
{
   for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++)
      {
         value[i][j] = Blank;
      }
}

void board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
   char ch;

   clear();
   
   for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++)
	    {
	       fin >> ch;

          // If the read char is not Blank
	      if (ch != '.')
             setCell(i,j,ch-'0');   // Convert char to int
        }
}

int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
{
   // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
   // coordinates of the square that i,j is in.  

   return SquareSize * ((i-1)/SquareSize) + (j-1)/SquareSize + 1;
}

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
   for (int i = 0; i < v.size(); i++)
      ostr << v[i] << " ";
   cout << endl;
}

ValueType board::getCell(int i, int j)
// Returns the value stored in a cell.  Throws an exception
// if bad values are passed.
{
   if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize)
      return value[i][j];
   else
      throw rangeError("bad value in getCell");
}

bool board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{
   if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
      throw rangeError("bad value in setCell");

   return (getCell(i,j) == Blank);
}

void board::print()
// Prints the current board.
{
   for (int i = 1; i <= BoardSize; i++)
   {
      if ((i-1) % SquareSize == 0)
      {
         cout << " -";
	 for (int j = 1; j <= BoardSize; j++)
	    cout << "---";
         cout << "-";
	 cout << endl;
      }
      for (int j = 1; j <= BoardSize; j++)
      {
	 if ((j-1) % SquareSize == 0)
	    cout << "|";
	 if (!isBlank(i,j))
	    cout << " " << getCell(i,j) << " ";
	 else
	    cout << "   ";
      }
      cout << "|";
      cout << endl;
   }

   cout << " -";
   for (int j = 1; j <= BoardSize; j++)
      cout << "---";
   cout << "-";
   cout << endl;
}

bool isSolved()
{
      matrix rows[9][9], squares[9][9], columns[9][9];
      int arows, asquares, acolumns;
      int temp = 0;

      //set matrices to 0
      for(int i = 0, i < 9, i++)
      {
            for(int j = 0, j < 9, j++)
            {
                  rows[i][j] = 0;
                  squares[i][j] = 0;
                  columns[i][j] = 0;
            }
      }

      //count the number of times a number apears in a row
      for(int i = 0, i < 9, i++)
      {
            for(int j = 0, j < 9, j++)
            {
                  temp = value[i][j];
                  rows[i][temp-1] = rows[i][temp-1] + 1;
            }
      }

      //count the number of times a number appears in a square
      for(int i = 0; i < 9; i = i + 3)
      {
            for(int j = i, j < (i + 2); j++)
            {
                  for(int k = i, k < (i + 2); k++)
                  {
                        temp = value[j][k];
                        squares[i][temp - 1] = squares[i][temp - 1] + 1;
                  }
            }
      }

      for(int i = 0, i < 9, i++)
      {
            for(int j = 0, j < 9, j++)
            {
                  temp = value[j][i];
                  columns[i][temp-1] = columns[i][temp-1] + 1;
            }
      }

void clearUpdate(int, int, int)
{

}

void addUpdate(int, int, int)
{

}

void updateConflicts()
{

}

void printConflicts()
{

}

void board::setCell(int i, int j, int num)
{
      if(num < 10 && num >= -1)
      {
            value[i][j] = num;
            return;
      }
}










int main()
{
   ifstream fin;
   
   // Read the sample grid from the file.
   string fileName = "sudoku1.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
      board b1(SquareSize);

      while (fin && fin.peek() != 'Z')
      {
	 b1.initialize(fin);
	 b1.print();
//	 b1.printConflicts();
      }
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }
}