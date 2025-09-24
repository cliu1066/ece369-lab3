#ifndef ADDRESS_GEN_H
#define ADDRESS_GEN_H

#include <vector>
#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;

int copy_block_from_frame(
    const int* frame,
    int frame_h, int frame_w,
    int r0, int c0,
    int wh, int ww,
    int* out_block);


#endif
