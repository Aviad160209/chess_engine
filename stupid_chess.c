#include <stdio.h>

/*TO DO:
add comments
add knight movement
add bishop, king and queen movement
*/
int main()
{
    char chessBord[8][8];
    char move[10];
    int row = 0;
    int col = 0;
    int amountOfMoves = 0;

    // board setting
    for (row = 0; row < 8; row++)
    {
        for (col = 0; col < 8; col++)
        {
            if ((row == 0 && col == 0) || (row == 0 && col == 7))
            {
                chessBord[row][col] = 'r';
            }
            else if ((row == 0 && col == 1) || (row == 0 && col == 6))
            {
                chessBord[row][col] = 'n';
            }
            else if ((row == 0 && col == 2) || (row == 0 && col == 5))
            {
                chessBord[row][col] = 'b';
            }
            else if (row == 0 && col == 3)
            {
                chessBord[row][col] = 'k';
            }
            else if (row == 0 && col == 4)
            {
                chessBord[row][col] = 'q';
            }
            else if (row == 1)
            {
                chessBord[row][col] = 'p';
            }
            else if (row == 6)
            {
                chessBord[row][col] = 'P';
            }
            else if ((row == 7 && col == 0) || (row == 7 && col == 7))
            {
                chessBord[row][col] = 'R';
            }
            else if ((row == 7 && col == 1) || (row == 7 && col == 6))
            {
                chessBord[row][col] = 'N';
            }
            else if ((row == 7 && col == 2) || (row == 7 && col == 5))
            {
                chessBord[row][col] = 'B';
            }
            else if (row == 7 && col == 3)
            {
                chessBord[row][col] = 'K';
            }
            else if (row == 7 && col == 4)
            {
                chessBord[row][col] = 'Q';
            }
            else
            {
                chessBord[row][col] = '.';
            }
        }
    }

    while (amountOfMoves == 0)
    {
        printf("white move: ");

        if (fgets(move, sizeof(move), stdin) == NULL) {
            printf("\nInput interrupted. Exiting...\n");
            break;
        }

        if (move[0] == 'r') 
        {
            int targetRow = move[2] - '1';
            int targetCol = 0;

            if (move[1] >= 'A' && move[1] <= 'H')
            {
                targetCol = move[1] - 'A';
            }
            else if (move[1] >= 'a' && move[1] <= 'h')
            {
                targetCol = move[1] - 'a';
            }
            else 
            {
                printf("Invalid column\n");
                continue;
            }

            int found = 0;

            for (row = 0; row < 8 && !found; row++) 
            {
                for (col = 0; col < 8; col++)
                {
                    if (chessBord[row][col] == 'r') 
                    {
                        if (col == targetCol) // same column
                        {
                            int step = (targetRow > row) ? 1 : -1;
                            int clear = 1;
                            for (int i = row + step; i != targetRow; i += step) 
                            {
                                if (chessBord[i][col] != '.') 
                                {
                                    clear = 0;
                                    break;
                                }
                            }
                            if (clear) 
                            {
                                if (chessBord[targetRow][col] != '.' &&
                                    chessBord[targetRow][col] >= 'b' &&
                                    chessBord[targetRow][col] <= 'p')
                                    {
                                        break; 
                                    }
                                chessBord[targetRow][col] = 'r';
                                chessBord[row][col] = '.';
                                found = 1;
                                amountOfMoves++;
                                break;
                            }
                        }
                        else if (row == targetRow) // same line
                        {
                            int step = (targetCol > col) ? 1 : -1;
                            int clear = 1;
                            for (int i = col + step; i != targetCol; i += step) 
                            {
                                if (chessBord[row][i] != '.') 
                                {
                                    clear = 0;
                                    break;
                                }
                            }
                            if (clear) 
                            {
                                if (chessBord[row][targetCol] != '.' &&
                                    chessBord[row][targetCol] >= 'b' &&
                                    chessBord[row][targetCol] <= 'p')
                                    {
                                        break;
                                    }

                                chessBord[row][targetCol] = 'r';
                                chessBord[row][col] = '.';
                                found = 1;
                                amountOfMoves++;
                                break;
                            }
                        }
                    }
                }
            }

            if (!found)
            {
                printf("Invalid move!\n");
            }
        }

        if (move[0] == 'p')
        {
            int targetRow = move[2] - '1';
            int targetCol = 0;
            int currntRow = 0;

            if (move[1] >= 'A' && move[1] <= 'H')
            {
                targetCol = move[1] - 'A';
            }
            else if (move[1] >= 'a' && move[1] <= 'h')
            {
                targetCol = move[1] - 'a';
            }
            for (int i = 0; i < 8; i++)
            {
                if (chessBord[i][targetCol] == 'p')
                {
                    currntRow = i;
                    break;
                }
            }

            if (targetRow <= currntRow + 2 && targetRow > currntRow)
            {
                chessBord[targetRow][targetCol] = 'p';
                chessBord[currntRow][targetCol] = '.';
                amountOfMoves++;
            }
            else
            {
                printf("illegal move\n");
            }
        }
        if (move[0] == 'n')
        {
            int targetRow = move[2] - '1';
            int targetCol = 0;
            int currntRow = 0;
        
            if (move[1] >= 'A' && move[1] <= 'H')
            {
                targetCol = move[1] - 'A';
            }
            else if (move[1] >= 'a' && move[1] <= 'h')
            {
                targetCol = move[1] - 'a';
            }
            if (chessBord[targetRow-2][targetCol-1] == 'n')
            {
                chessBord[targetRow-2][targetCol-1] = '.';
                chessBord[targetRow][targetCol] = 'n';
                amountOfMoves++;
            }
            else if (chessBord[targetRow-2][targetCol+1] == 'n')
            {
                chessBord[targetRow-2][targetCol+1] = '.';
                chessBord[targetRow][targetCol] = 'n';
                amountOfMoves++;
            }
            /**/
            
        }
        // printing of the board
        for (row = 0; row < 8; row++)
        {
            for (col = 0; col < 8; col++)
            {
                printf("%c ", chessBord[row][col]);
            }
            printf("\n");
        }
    }

    return 0;
}
