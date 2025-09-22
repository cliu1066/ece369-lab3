#ifndef SCAN_PATTERN_H
#define SCAN_PATTERN_H

#include <iostream>
#include <vector>
#include "sad_routine.h"

void scanning(int winRows, int winCols, int frameRows, int frameCols,
             int window[2][2], int frame[4][4], int* result, int* v0, int* v1);

#endif