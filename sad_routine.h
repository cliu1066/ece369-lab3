#ifndef SAD_ROUTINE_H
#define SAD_ROUTINE_H

#include <iostream>

int windowSad(int winWidth, int winHeight, int frameWidth, int frameHeight, 
              int frameRow, int frameCol, int window[], int frame[]);
              
int getArrayPos(int row, int col, int width);

#endif