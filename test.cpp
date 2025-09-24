#include "address_gen.h"
#include "sad_routine.h"
#include "scan_pattern.h"

int main() {
    int sizes[] = {4, 4, 2, 2};
    int window[4] = {1, 2, 3, 4};
    /*  1 2
        3 4
    */
    
    int frame[16] = {0, 0, 1, 2, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0}; 
    /*
        0 0 1 2
        0 0 3 4
        0 0 0 0
        0 0 0 0
    */
    int v0, v1, result = 0;

    int frameRows = sizes[0];
    int frameCols = sizes[1];
    int winRows = sizes[2];
    int winCols = sizes[3];
    
    scanning(winRows, winCols, frameRows, frameCols,
             window, frame, &result, &v0, &v1);

    std::cout << "min sad: " << result << "at: " << v0 << ", " << v1;
}
