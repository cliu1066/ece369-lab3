#include <iostream>

/* Objective: Compute sum of absolute difference for given window size 
 * @param: width, height of window, start x, start y
 * @return: SAD of window
 */
int windowSad(int width, int height, int x, int y, int window[4][8], int frame[16][16]) {
    int w = 0;
    int h = 0;
    int sad = 0;
    
    // loop1
    while (h < height) {
        // loop2
        w = 0;
        while (w < width) {
            int* winRow = window[y + h];
            int winVal = winRow[x + w];
            int* frameRow = frame[y + h];
            int frameVal = frameRow[x + w];
            int diff = winVal - frameVal;

            // Check if negative -> multiply by -1
            if (diff < 0) {
                diff *= -1;
            }

            // postcheck
            sad += diff;
            w++;
        }
        //postloop
        h++;
    }
    //finish
    return sad;
}

int main()
{
    int window[4][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    int frame[16][16] = {
        {7, 5, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,},
        {7, 5, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,},
        {7, 5, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,},
        {7, 5, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,},
        {0, 4, 2, 3, 4, 5, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60},
        {0, 5, 3, 4, 5, 6, 30, 35, 40, 45, 0, 0, 0, 0, 70,  75,},
        {0, 6, 12, 18, 24, 30, 36, 42, 48, 54, 0, 0, 0, 0, 84, 90,},
        {0, 4, 8, 8, 8, 8, 42, 49, 56, 63, 0, 0, 0, 0, 98, 105, },
        {0, 1, 8, 8, 8, 8, 48, 56, 64, 72, 0, 0, 0, 0, 112, 120, },
        {0, 1, 8, 8, 8, 8, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135},
        {0, 10, 8, 8, 8, 8, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150,},
        {0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165,},
        {9, 9, 9, 9, 48, 60, 72, 84, 96, 108, 120, 132, 0, 1, 2, 3, },
        {9, 9, 9, 9, 52, 65, 78, 91, 104, 114, 130, 143, 1, 2, 3, 4, },
        {9, 9, 9, 9, 56, 70, 84, 98, 112, 126, 140, 154, 2, 3, 4, 5, },
        {9, 9, 9, 9, 60, 75, 90, 105, 120, 135, 150, 165, 3, 4, 5, 6 },
    };

    int sad = windowSad(2, 2, 0, 0, window, frame);

    std::cout << sad;
}