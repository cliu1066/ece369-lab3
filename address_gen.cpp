/*
Created by Barack M. on 9/15/2025.
Program description: Implementation of the address generation for reading the corresponding frame
elements based on the current position in the frame.
*/

#include "address_gen.h"

// Linear index in a row-major 1D frame
inline size_t lin_idx(int row, int col, int frame_w) {
    return static_cast<size_t>(row) * static_cast<size_t>(frame_w)
         + static_cast<size_t>(col);
}

// Task 2: copy the wh×ww block at top-left (r0,c0) from frame into out_block
void copy_block_from_frame(const int* frame,
                           int frame_h, int frame_w,
                           int r0, int c0,
                           int wh, int ww,
                           vector<int>& out_block)
{   //Some exceptions to get the correct window - (Task 3 should adhere to this)
    if (r0 < 0 || c0 < 0 || wh <= 0 || ww <= 0) throw invalid_argument("bad dims");
    if (r0 + wh > frame_h || c0 + ww > frame_w) throw out_of_range("window exceeds frame");

    out_block.resize(static_cast<size_t>(wh) * static_cast<size_t>(ww));

    // For loops for copying
    for (int i = 0; i < wh; ++i) {
        const size_t base = lin_idx(r0 + i, c0, frame_w);  // frame row start
        const size_t dst_row = static_cast<size_t>(i) * ww;     // out row start
        for (int j = 0; j < ww; ++j) {
            out_block[dst_row + j] = frame[base + j];
        }
    }
}


