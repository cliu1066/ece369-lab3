/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

int main()
{
    int row = 0, col = 0;
    /*cout << "input the row of first element for the window\n";
    cin >> row;
    
    cout << "input the column of first element for the window\n";
    cin >> col;
    */
    
    cout << "input the window row size:\n";
    cin >> winrRows;
    
    cout << "input the window column size:\n";
    cin >> winCols;
    
    cout << "input the frame row size:\n";
    cin >> frameRows;
    
    cout << "input the frame column size:\n";
    cin >> frameCols;
    
    //FIXME
    //compare first SAD value then move to the right
    col += 1;
    
    bool moveDown = true;
    //initialize the min SAD location for the window as the start point
    int minSadAdd[2] = {row, col};
    while ((row != frameRows - winRows) && (col != frameCols - winCols)) {
        //FIXME
        //compare SAD at location to minSad, if less, set current
        //SAD to the minimum and save address to minSadAdd
        
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
    
    //FIXME    
    //compare SAD at final location to minSad, if less, set current
    //SAD to the minimum and save address to minSadAdd
    

    return 0;
}