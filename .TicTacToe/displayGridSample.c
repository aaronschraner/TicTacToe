
//
// CST 126 - Assignment 1
//
// Author: Michael Hoffman
//
// File: displayGridSample.cpp
//
// Sample program to illustrate how to display a tic-tac-toe game grid using
// the consoleGraphics.h graphical character set provided for assignment #1.
//
// A grid such as this can be displayed using the code below:
//
//       |   |      <--- blank row ... see displayBlankRow()
//     ? | ? | ?    <--- data row ... see displayDataRow()
//       |   |
//    ---+---+---   <--- border row ... see displayBorderRow()
//       |   |
//     ? | ? | ?
//       |   |
//    ---+---+---
//       |   |
//     ? | ? | ?
//       |   |
//
// You are welcome to copy the code in this file and modify it for use in
// your assignment #1 solution.
//


#include  <iostream>
#include  "consoleGraphics.h"


using  namespace  std;


//
// Local functions
//


//
// Display a solid-line grid row.
//
// For example, if numCols is 3, it will look something like this:
//
//     ---+---+---
//
static void  displayBorderRow( int  numCols )
{
  //
  // Loop once for each column
  //
  for( int  col = 0;  col < numCols;  ++col )
  {
    cout  <<  CG_LINE_HOR
          <<  CG_LINE_HOR
          <<  CG_LINE_HOR;

    //
    // Put in a separator between each column, unless it's the last column
    //
    if  (col != numCols-1)
      cout  <<  CG_CROSS;
  }

  cout  <<  endl;
}


//
// Display a hollow-line grid row
//
// For example, if numCols is 3, it will look something like this:
//
//     bbb|bbb|bbb
//
//   Note: the b's above are blank spaces
//
static void  displayBlankRow( int  numCols )
{
  //
  // Loop once for each column
  //
  for( int  col = 0;  col < numCols;  ++col )
  {
    cout  <<  "   ";

    //
    // Put in a separator between each column, unless it's the last column
    //
    if  (col != numCols-1)
      cout  <<  CG_LINE_VERT;
  }

  cout  <<  endl;
}


//
// Display a hollow-line grid row that has a ? where a data value (X or O)
// should go.
//
// For example, if numCols is 3, it will look something like this:
//
//     b?b|b?b|b?b
//
//   Note: the b's above are blank spaces
//
static void  displayDataRow( int  rowNum, int  numCols )
{
  //
  // Loop once for each column
  //
  for( int  col = 0;  col < numCols;  ++col )
  {
    cout  <<  " ? ";

    //
    // Put in a separator between each column, unless it's the last column
    //
    if  (col != numCols-1)
      cout  <<  CG_LINE_VERT;
  }

  cout  <<  endl;
}


//
// Global functions
//


//
// Display the game board
//
void  displayBoard( int  numRows, int  numCols )
{
  cout  <<  endl;

  //
  // Loop once for each row
  //
  for( int  row = 0;  row < numRows;  ++row )
  {
    displayBlankRow( numCols );
    displayDataRow( row, numCols );
    displayBlankRow( numCols );

    //
    // Put in a separator line between rows, unless it's the last row
    //
    if  (row == numRows-1)
      cout  <<  endl;
    else
      displayBorderRow( numCols );
  }

  cout  <<  endl;
}


//
// main()
//
// Prompt the user for a number of rows and columns and then display
// a game grid that corresponds.
//
int  main()
{
  int  numRows;
  int  numCols;

  cout  <<  "   Enter number of rows: ";
  cin  >>  numRows;

  cout  <<  "Enter number of columns: ";
  cin  >>  numCols;

  displayBoard( numRows, numCols );

  return  0;
}
