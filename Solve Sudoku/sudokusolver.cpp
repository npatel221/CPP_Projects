#include <iostream>

#define ROW 9
#define COL 9

using namespace std;

/* Rules of Sudoku:
a number can only appear once along any row
a number can only appear once along any col
a number can only appear once in the mini 3x3 grid 
*/
// check whether a given num can be placed on (row,col) on the Sudoku puzzle
bool checkMove(unsigned short row, unsigned short col, unsigned short num, unsigned short (&myPuzzle) [ROW][COL])
{
    // check along row and col
    for (int index = 0; index < ROW; index++)
    {
        // number found along the row
        if (myPuzzle[row][index] == num) {return false;}

        // number found along the col
        if (myPuzzle[index][col] == num) {return false;}
    }

    // check within the mini 3x3 grid
    unsigned short int x0 = (row/3)*3;
    unsigned short int y0 = (col/3)*3;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (myPuzzle[x0+i][y0+j] == num) {return false;}
        }
    }
    return true; // number can be placed on row,col
}

// this function will use backtracking technique to solve the sudoku puzzle
bool getSolution(unsigned short (&myPuzzle) [ROW][COL])
{
    for (int row = 0; row < ROW; row++) // go through rows
    {
        for (int col = 0; col < COL; col++) // go through cols
        {
            if (myPuzzle[row][col] == 0) // find empty spot
            {
                for (int numtry = 1; numtry <= 9; numtry++) // try numbers from 1 to 9
                {
                    if (checkMove(row,col,numtry,myPuzzle) == true) // check if move is possible
                    {
                        myPuzzle[row][col] = numtry; // move possible give it a try
                        if (getSolution(myPuzzle)) // now try to solve the rest of the puzzle
                        {
                            return true; // got a solution
                        }
                        else 
                        {
                            myPuzzle[row][col] = 0; // undo the move
                        }
                    }
                }
                return false; // can't find a number to place
            }
        }
    }
}

// this function will print nicely a 9x9 sudoku board aka 2d array
void printPuzzle(const unsigned short (&myPuzzle) [ROW][COL])
{
    char toPrint[ROW][COL]; // char array to print
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            // swap 0's with * for fancy visualization
            if (myPuzzle[row][col] == 0)
            {
                toPrint[row][col] = '*';
            }
            else
            {
                toPrint[row][col] = '0' + myPuzzle[row][col]; // convert int to char
            }
        }
        // print an entire row
        printf("%c %c %c | %c %c %c | %c %c %c\n",toPrint[row][0],toPrint[row][1],toPrint[row][2],
            toPrint[row][3],toPrint[row][4],toPrint[row][5],
            toPrint[row][6],toPrint[row][7],toPrint[row][8]);

        // print horizontal line after 3rd and 6th row
        if (row == 2 || row == 5)
        {
            cout << "---------------------" << endl;
        }
    }
    return;
}

int main()
{
    cout << "Welcome to Sudoku Solver!\n";
    // create a puzzle
    unsigned short puzzle [ROW][COL] = 
    {{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}};
    
    cout << "\nPuzzle" << endl;
    printPuzzle(puzzle); // print puzzle first

    // print solution if attempt to solve is a success
    if (getSolution(puzzle))
    {
        cout << "\nSolution" << endl;
        printPuzzle(puzzle);
    }
    else
    {
        cout << "\nUnable to find a solution to the given puzzle" << endl;
    }
    
    return 0;
}