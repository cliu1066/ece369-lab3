#include "sad_routine.h"

int windowSad(int winWidth, int winHeight, int frameWidth, int frameHeight, 
              int frameRow, int frameCol, int window[], int frame[]) {
    int w = 0;
    int h = 0;
    int sad = 0;
    
    while (h < winHeight) {
        w = 0;
        while (w < winWidth) {
            //int winPos = getArrayPos(h, w, winWidth);
            int t1 = h * winWidth;
            int winPos = t1 + w;
            int currWin = window[winPos];

            int currFrameRow = frameRow + h;
            int currFrameCol = frameCol + w;
            //int framePos = getArrayPos(currFrameRow, currFrameCol, frameWidth);
            t1 = currFrameRow * frameWidth;
            int framePos = t1 + currFrameCol;
            int currFrame = frame[framePos];

            int diff = currWin - currFrame;

            if (diff < 0) {
                diff = diff * -1;
            }

            sad = sad + diff;
            w = w + 1;
        }
        h = h + 1;
    }

    return sad;
}

/*int getArrayPos(int row, int col, int width) {
    int mult = row * width;
    int add = mult + col;
    return add;
}*/