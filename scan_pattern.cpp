/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include "scan_pattern.h"
#include "sad_routine.h"
#include "address_gen.h"

void scanning(int winRows, int winCols, int frameRows, int frameCols,
             int* window, int* frame, int* result, int* v0, int* v1)
{
    int row = 0, col = 0;
    int minSad = windowSad(winCols, winRows, frameCols, frameRows, 
                           row, col, window, frame);
    int currSad = 0;

    col += 1;
    
    bool moveDown = true;

    //initialize the min SAD location for the window as the start point
    int minSadAdd[2] = {row, col};
    while ((row != frameRows - winRows) && (col != frameCols - winCols)) {
        currSad = windowSad(winCols, winRows, frameCols, frameRows, 
                           row, col, window, frame);
        if (currSad <= minSad) {
            minSad = currSad;
            *result = currSad;
            *v0 = row;
            *v1 = col;
        }
        
        if (moveDown) {
            //reach bound to start moving up when last row is reached
            if (row == frameRows - winRows) {
                col += 1;
                moveDown = false;
            }
            
            //bound to move up when first column is reached, but last row
            //has not
            else if (col == 0) {
                row += 1;
                moveDown = false;
            }
            
            else {
                row += 1;
                col -= 1;
            }
        }
        
        else {
            //reach bound to start moving down
            //when rightmost column is reached
            if (col == frameCols - winCols) {
                row += 1;
                moveDown = true;
            }
            
            //bound to move down when first row is reached, and last column
            //is not
            else if(row == 0) {
                col += 1;
                moveDown = true;
            }
            
            else {
                row -= 1;
                col += 1;
            }
        }
        
    }
    
    if (currSad <= minSad) {
            minSad = currSad;
            *result = currSad;
            *v0 = row;
            *v1 = col;
    }
}
