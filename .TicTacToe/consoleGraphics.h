
//
// CST 126 - Assignment 1
//
// Author: Michael Hoffman
//
// File: consoleGraphics.h
//
// This file contains character definitions for some basic
// console graphics.
//


#ifndef  consoleGraphics_H
#define  consoleGraphics_H


#ifdef  WIN32

  //
  // These definitions are used when compiling for the Microsoft platform
  //
#  define  CG_LINE_VERT  char(179)   // vertical
#  define  CG_LINE_HOR   char(196)   // horizontal
#  define  CG_CROSS  char(197)  // cross

#else

  //
  // These definitions are used when compiling for the Microsoft platform
  //
#  define  CG_LINE_VERT  '|'    // vertical line
#  define  CG_LINE_HOR   '-'    // horizontal line
#  define  CG_CROSS      '+'    // cross

#endif


#endif
