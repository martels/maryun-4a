#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>

using namespace std;

typedef int ValueType; // The type of the value in a cell
const int Blank = -1;  // Indicates that a cell is blank
 
const int SquareSize = 3;  //  The number of cells in a small square
                           //  (usually 3).  The board has
                           //  SquareSize^2 rows and SquareSize^2
                           //  columns.

const int BoardSize = SquareSize * SquareSize;

const int MinValue = 1;
const int MaxValue = 9;

int numSolutions = 0;

class board
// Stores the entire Sudoku board
{
   public:
      board(int);
      void clear();
      void initialize(ifstream &fin);
      void print();
      bool isBlank(int, int);
      ValueType getCell(int, int);

      void conflicts();
      bool isSolved();
      void clearUpdate(int, int, int);
      void addUpdate(int, int, int);
      void updateConflicts();
      void printConflicts();
      void setCell(int, int, int);
      
   private:
 
      // The following matrices go from 1 to BoardSize in each
      // dimension, i.e., they are each (BoardSize+1) * (BoardSize+1)
      bool flag;
      matrix<ValueType> rows[9][9], squares[9][9], columns[9][9];
      matrix<ValueType> value;
      matrix<ValueType> OriginalBoard;
};

#endif