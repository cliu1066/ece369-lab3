#ifndef SCAN_PATTERN_H
#define SCAN_PATTERN_H

#include <iostream>
#include <vector>
#include "sad_routine.h"
#include "address_gen.h"

void scanning(int winRows, int winCols, int frameRows, int frameCols,
             int* window, int* frame, int* result, int* v0, int* v1);

#endif
