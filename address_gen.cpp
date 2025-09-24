/*
Task 2: Copy a wh×ww block starting at top-left (r0, c0) from a row-major 1D frame
        into a caller-provided 1D output buffer.

- Row-major 1D layout means: element at (row, col) in a frame of width W
  lives at flat index row*W + col.

- No static, no casting, no vectors, no C++ features.
- Returns 0 on success, non-zero on invalid inputs.
*/

#include <stddef.h>  // for size_t (not strictly necessary if you prefer plain int)
#include <limits.h>  // optional, only if you want to check for negatives robustly

/* 
 * Parameters:
    frame     : pointer to the first element of the frame (size = frame_h * frame_w)
    frame_h   : number of rows in the frame
    frame_w   : number of columns in the frame
    r0, c0    : top-left coordinate of the block to copy
    wh, ww    : block height and width
   out_block : pointer to the first element of the destination buffer
                (caller must ensure it has space for wh * ww ints)
 
* Returns:
 *   0  -> success
 *  -1  -> bad dimensions (negative or zero)
 *  -2  -> window exceeds the frame bounds
 *  -3  -> null pointer(s)
 */
int copy_block_from_frame(
    const int* frame,
    int frame_h, int frame_w,
    int r0, int c0,
    int wh, int ww,
    int* out_block)
{
    /* -------------------- basic validation -------------------- */
    if (frame == 0 || out_block == 0) {
        return -3; /* null pointers */
    }

    /* dimensions must be positive; start coordinates must be non-negative */
    if (frame_h <= 0 || frame_w <= 0 || wh <= 0 || ww <= 0 || r0 < 0 || c0 < 0) {
        return -1; /* bad dims */
    }

    /* ensure requested block fits entirely inside the frame */
    if (r0 + wh > frame_h || c0 + ww > frame_w) {
        return -2; /* window exceeds frame */
    }


    /*
       We iterate over each row of the block (i = 0..wh-1)
       and each column of the block (j = 0..ww-1).

       Source index into the big frame (row-major 1D):
           src = (r0 + i) * frame_w + (c0 + j)

       Destination index into the compact out_block (also row-major):
           dst = i * ww + j
    */
    int i, j;
    for (i = 0; i < wh; i++) {
        // compute the starting flat index of the current source row once
        int src_row_start = (r0 + i) * frame_w + c0;

        //compute the starting flat index of the current destination row
        int dst_row_start = i * ww;

        // copy one row of ww element
        for (j = 0; j < ww; j++) {
            out_block[dst_row_start + j] = frame[src_row_start + j];
        }
    }

    return 0; 
}
